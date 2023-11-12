#include <iostream>

using namespace std;

int hanoi_tower(int n, char t1, char t2, char t3){
	if(n==1){
		cout << "Move No." << n << " disk from Tower." << t1 << " to Tower." << t3 << endl;  // move
		return 1;
	}
	else{
		int count = 0;
		count += hanoi_tower(n-1, t1, t3, t2);
		
		cout << "Move No." << n << " disk from Tower." << t1 << " to Tower." << t3 << endl;  // move
		count += 1;

		count += hanoi_tower(n-1, t2, t1, t3);
		return count;
	}
}

int main(){
    int n;  // number of plates
    cout << "Please input the number of disks : ";
    cin >> n;

    cout << "Total steps count : " << hanoi_tower(n, 'A', 'B', 'C') << endl;  // showing result
    return 0;
}
