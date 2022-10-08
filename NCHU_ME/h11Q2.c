#include <stdio.h>
#include <time.h>
#include <windows.h>

int infect(int ,int );

int main()
{
    int a;
    for(int i=0;i<10;i++)
    {
        a=infect(100,2);
        printf("%d\n",a);
        Sleep(3);
    }
    /*struct time
    {
        int hour;
        int minutes;
        double second;
    }start={12, 32, 25.49},end={15, 12, 17.53},elapse;

    elapse.hour = end.hour - start.hour; //end time must bigger than start time

    if(end.minutes >= start.minutes)
    {
        elapse.minutes = end.minutes - start.minutes;
    }
    else
    {
        elapse.minutes = end.minutes + 60 - start.minutes;
        elapse.hour = elapse.hour - 1;
    }
    if(end.second >= start.second)
    {
        elapse.second = end.second - start.second;
    }
    else
    {
        elapse.second = end.second + 60 - start.second;
        elapse.minutes = elapse.minutes - 1;
    }

    printf("start=%02d:%02d:%04.2f \n",start.hour,start.minutes,start.second);
    printf("end=%02d:%02d:%04.2f \n",end.hour,end.minutes,end.second);
    printf("elapse=%02d:%02d:%04.2f \n",elapse.hour,elapse.minutes,elapse.second);*/

    return 0;
}

int infect(int total ,int infected)
{
    //total=活著的總人數  infected=活著但已遭感染的人  result=最後染疫的總人數
    int p[total],x,result=0;

    for(int i=0;i<infected;i++)
        p[i]=1;
    for(int i=infected;i<total;i++)
        p[i]=0;
    srand(time(NULL));
    for(int i=0;i<total;i++)
    {
        for(int j=i+1;j<total;j++)
        {

            if(i==j||(p[i]==p[j]))
                j=j+1;
            else
            {
                x=rand()%100;
                if(x<2)
                {
                    p[i]=1;
                    p[j]=1;
                }
            }
        }
    }
    for(int i=0;i<total;i++)
    {
        if(p[i]==1)
        {
            result=result+1;
        }
    }
    return result;
}
