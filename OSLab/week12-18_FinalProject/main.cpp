#include "mbed.h"
#include "MQTTClientMbedOs.h"
#include <cstdio>
#include <cstring>
#include <iterator>
#define MAXIMUM_BUFFER_SIZE 32

PwmOut  mt_ccw_1(D10); // 左後方
DigitalOut  mt_cw_1(D11);
PwmOut  mt_ccw_2(D9); // 右後方
DigitalOut  mt_cw_2(D6);
PwmOut  mt_ccw_3(D5); // 右前方
DigitalOut  mt_cw_3(D4); //D0
PwmOut  mt_ccw_4(D3);    //D3
DigitalOut  mt_cw_4(D2); //A1

Mutex stdio_mutex;
static BufferedSerial serial_port(D1, D0);
char buf[MAXIMUM_BUFFER_SIZE] = {0};
//Define the maximum search capacity of wifiAP

static constexpr size_t MAX_NUMBER_OF_ACCESS_POINTS = 10; 
static constexpr size_t MAX_MESSAGE_RECEIVED_LENGTH = 100;
static constexpr size_t REMOTE_PORT = 1883;

const char *pub_topic = "OSLab/Group2";
const char *sub_topic = "OSLab/Group2";
const char* clientID = "Group 2-2";
InterruptIn button(BUTTON1);
EventFlags event_flag;

volatile int dirc = 0;
volatile bool ai_ON = false;

class Mqtt_App {
    public:
        Mqtt_App() : _net(NetworkInterface::get_default_instance()) {}
        ~Mqtt_App()
        {
            if(_net)
            {
                _net->disconnect();
            }
        }
        
        void run()
        {
            if(!_net)
            {
                printf("[Error] No network interface found.\r\n");
                return;
            }
            //Search available wifi.
            if(_net->wifiInterface())
            {
                wifi_scan();
            }
            // Connecting to Wifi (Depend on mbed_app.json)
            printf("\nConnecting to the network...\r\n");

            nsapi_size_or_error_t result = _net->connect();
            if (result != 0)
            {
                printf("[Error] Failed connect Network :  _net->connect() returned: %d\r\n", result);
                return;
            }

            SocketAddress addr;
            _net->get_ip_address(&addr);
            printf("[Success] connected to wifi , IP address : %s\r\n", addr.get_ip_address());
            
            // Setting broker address and Connect
            printf("\nConnecting to the socket ...\r\n");

            SocketAddress address;
            _net->gethostbyname(MBED_CONF_APP_HOSTNAME, &address);
            address.set_port(REMOTE_PORT);
            _socket.open(_net);
            nsapi_size_or_error_t socket_result =  _socket.connect(address);
            if(socket_result != 0)
            {
                printf("[Error] Failed connect Socket :  _socket.connect() returned: %d\r\n", socket_result);
                return;
            }
            printf("[Success] connected to Socket.\n");
            printf("\nConnecting to the MQTT Broker ...\r\n");
            //Trying to use Mqtt to connect to broker to send messages and receive messages
            MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
            data.clientID.cstring = (char *)clientID;
            data.username.cstring = (char *)MBED_CONF_MBED_MQTT_TESTS_USERNAME;
            data.password.cstring = (char *)MBED_CONF_MBED_MQTT_TESTS_PASSWORD;
            // Connect MQTT with data through the socket
            MQTTClient client(&_socket);
            nsapi_size_or_error_t mqtt_result =  client.connect(data);
            if(mqtt_result != 0)
            {
                printf("[Error] Failed MQTT Connection :  client.connect() returned: %d\r\n", mqtt_result);
                return;
            }
            printf("[Success] connected to MQTT Broker.\n");

            // Trying publish message to pub_topic 
            // const char* payload = "NCHU_OSLab_Group_0";
            // MQTT::Message message = 
            //         {
            //     .qos = MQTT::QoS::QOS2,
            //     .retained = false,
            //     .dup = false,
            //     .id = 0,
            //     .payload = (void*)payload,
            //     .payloadlen = strlen(payload)
            // };
            uint32_t flag_read = 0;

            client.subscribe(sub_topic, MQTT::QOS2, message_arrived);
            while(true)
            {
                ThisThread::sleep_for(50ms);
                client.yield(100);
            }
        }
    private:
        void wifi_scan()
        {
            WiFiInterface *wifi = _net->wifiInterface();
            WiFiAccessPoint ap[MAX_NUMBER_OF_ACCESS_POINTS];
            int result = wifi->scan(ap, MAX_NUMBER_OF_ACCESS_POINTS);
            if(result <= 0)
            {
                printf("WiFiInterface::scan() failed with return value : %d\r\n", result);
                return;
            }
            printf("%d networks available:\r\n",result);
            for(int i = 0; i < result; i++)
            {
                printf("Network: %s BSSID: %hhX:%hhX:%hhX:%hhx:%hhx:%hhx\r\n",
                ap[i].get_ssid(),
                ap[i].get_bssid()[0], ap[i].get_bssid()[1], ap[i].get_bssid()[2],
                ap[i].get_bssid()[3], ap[i].get_bssid()[4], ap[i].get_bssid()[5]);
            }
        }
        static void message_arrived(MQTT::MessageData &md)
        {
            // printf("\n--------------------Message arrived--------------------\n");
            // printf("\n[Subscribe] Topic : %.*s, Message : %.*s\n",
            // md.topicName.lenstring.len, md.topicName.lenstring.data,
            // static_cast<int>(md.message.payloadlen),
            // static_cast<char *>(md.message.payload));
            // printf("\n-------------------------------------------------------\n"); 
            char *message = static_cast<char *>(md.message.payload);
            if(strncmp(message,"shiftleft",md.message.payloadlen)==0)
            {
                dirc = 1;
            }   
            else if(strncmp(message,"forward",md.message.payloadlen)==0)
            {
                dirc = 2;
            }
            else if(strncmp(message,"shiftright",md.message.payloadlen)==0)
            {
                dirc = 3;
            }
            else if(strncmp(message,"turnleft",md.message.payloadlen)==0)
            {
                dirc = 4;
            }
            else if(strncmp(message,"backward",md.message.payloadlen)==0)
            {
                dirc = 5;
            }
            else if(strncmp(message,"turnright",md.message.payloadlen)==0)
            {
                dirc = 6;
            }
            else if(strncmp(message,"auto",md.message.payloadlen)==0)
            {
                dirc = 7;
                
                if(ai_ON){
                    event_flag.set(0x1);
                }
                ai_ON = !ai_ON;
            }
        }
    private:
        NetworkInterface *_net;
        TCPSocket _socket;
};


   

#define FORWARD 5
#define BACKWARD 2
#define SHIFT_LEFT 3
#define SHIFT_RIGHT 1
#define TURN_LEFT 6
#define TURN_RIGHT 4
#define AUTO_MODE 7


void notify(const char state)
{
    stdio_mutex.lock();
    printf("\r>> AI dir: %c   \r", state);
    stdio_mutex.unlock();
}


void dir_control() {
    int tmp = 0;
    while(true) {
       if(tmp != dirc) {
            switch (dirc) {
                case SHIFT_LEFT:  // shift left
                    mt_ccw_1 = 0.4; // 左後方
                    mt_ccw_2 = 0.5; // 右後方
                    mt_ccw_3 = 0.7; // 右前方
                    mt_ccw_4 = 0.3; // 左前方
                    mt_cw_1 = 0;
                    mt_cw_2 = 1;
                    mt_cw_3 = 0;
                    mt_cw_4 = 1;
                    break;
                case FORWARD:  // forward
                    mt_ccw_1 = 0.5; // 左後方
                    mt_ccw_2 = 0.5; // 右後方
                    mt_ccw_3 = 0.5; // 右前方
                    mt_ccw_4 = 0.5; // 左前方
                    mt_cw_1 = 1;
                    mt_cw_2 = 1;
                    mt_cw_3 = 1;
                    mt_cw_4 = 1;
                    break;
                case SHIFT_RIGHT:  // shift right
                    mt_ccw_1 = 0.6; // 左後方
                    mt_ccw_2 = 0.4; // 右後方
                    mt_ccw_3 = 0.3; // 右前方
                    mt_ccw_4 = 0.7; // 左前方
                    mt_cw_1 = 1;
                    mt_cw_2 = 0;
                    mt_cw_3 = 1;
                    mt_cw_4 = 0;
                    break;
                case TURN_LEFT:  // turn left
                    mt_ccw_1 = 0.5; // 左後方
                    mt_ccw_2 = 0.5; // 右後方
                    mt_ccw_3 = 0.5; // 右前方
                    mt_ccw_4 = 0.5; // 左前方
                    mt_cw_1 = 0;
                    mt_cw_2 = 1;
                    mt_cw_3 = 1;
                    mt_cw_4 = 0;
                    break;
                case BACKWARD:  // backward
                    mt_ccw_1 = 0.5; // 左後方
                    mt_ccw_2 = 0.5; // 右後方
                    mt_ccw_3 = 0.5; // 右前方
                    mt_ccw_4 = 0.5; // 左前方
                    mt_cw_1 = 0;
                    mt_cw_2 = 0;
                    mt_cw_3 = 0;
                    mt_cw_4 = 0;
                    break;
                case TURN_RIGHT:  // turn right
                    mt_ccw_1 = 0.5; // 左後方
                    mt_ccw_2 = 0.5; // 右後方
                    mt_ccw_3 = 0.5; // 右前方
                    mt_ccw_4 = 0.5; // 左前方
                    mt_cw_1 = 1;
                    mt_cw_2 = 0;
                    mt_cw_3 = 0;
                    mt_cw_4 = 1;
                    break;
                case AUTO_MODE:
                    if(uint32_t num = serial_port.read(buf, sizeof(buf))) {
                        notify(buf[0]);
                        switch (buf[0]) {
                            case 'F':
                                mt_ccw_1 = 0.4; // 左後方
                                mt_ccw_2 = 0.4; // 右後方
                                mt_ccw_3 = 0.4; // 右前方
                                mt_ccw_4 = 0.4; // 左前方
                                mt_cw_1 = 0;
                                mt_cw_2 = 0;
                                mt_cw_3 = 0;
                                mt_cw_4 = 0;
                                break;
                            case 'B':
                                mt_ccw_1 = 0.6; // 左後方
                                mt_ccw_2 = 0.6; // 右後方
                                mt_ccw_3 = 0.6; // 右前方
                                mt_ccw_4 = 0.6; // 左前方
                                mt_cw_1 = 1;
                                mt_cw_2 = 1;
                                mt_cw_3 = 1;
                                mt_cw_4 = 1;
                                break;
                            case 'S':
                                mt_ccw_1 = 0; // 左後方
                                mt_ccw_2 = 0; // 右後方
                                mt_ccw_3 = 0; // 右前方
                                mt_ccw_4 = 0; // 左前方
                                mt_cw_1 = 0;
                                mt_cw_2 = 0;
                                mt_cw_3 = 0;
                                mt_cw_4 = 0;
                                break;
                            case 'L':
                                mt_ccw_1 = 0.5; // 左後方
                                mt_ccw_2 = 0.5; // 右後方
                                mt_ccw_3 = 0.5; // 右前方
                                mt_ccw_4 = 0.5; // 左前方
                                mt_cw_1 = 1;
                                mt_cw_2 = 0;
                                mt_cw_3 = 0;
                                mt_cw_4 = 1;
                                break;
                            case 'R':
                                mt_ccw_1 = 0.5; // 左後方
                                mt_ccw_2 = 0.5; // 右後方
                                mt_ccw_3 = 0.5; // 右前方
                                mt_ccw_4 = 0.5; // 左前方
                                mt_cw_1 = 0;
                                mt_cw_2 = 1;
                                mt_cw_3 = 1;
                                mt_cw_4 = 0;
                                break;
                        }
                    }
                    break;
                default:
                    mt_ccw_1 = 0; // 左後方
                    mt_ccw_2 = 0; // 右後方
                    mt_ccw_3 = 0; // 右前方
                    mt_ccw_4 = 0; // 左前方
                    mt_cw_1 = 0;
                    mt_cw_2 = 0;
                    mt_cw_3 = 0;
                    mt_cw_4 = 0;
            }
            if(dirc != 7){
                tmp = dirc;
                dirc = 0;
                ThisThread::sleep_for(1500ms);
            }
            else{
                int flag = event_flag.wait_any_for(0x1,200ms);
                if(flag == 1) {
                    dirc = 0;
                    tmp = 7;
                }
            }
        }
    }
}




int main() {
   // dirc = AUTO_MODE;
    serial_port.set_baud(115200);
    serial_port.set_format(8, BufferedSerial::None, 1);  // bits, parity, stop bit
    Thread thread, thread2;
    // tmr.attach(&tag, 10s);
    Mqtt_App *app = new Mqtt_App();
    MBED_ASSERT(app);
    thread.start(callback(app, &Mqtt_App::run));
    thread2.start(dir_control);
    // button.fall(&isr);
    while(true) {

        ThisThread::sleep_for(50ms);
    }
    return 0;
}
