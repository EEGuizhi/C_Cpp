#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	char act;
    system("chcp 850");
	/*LPCWSTR text = L"Hello World";
	LPCWSTR title = L"Hi";
	
	MessageBoxW(NULL,text,title,0x0);*/
	
    for(int i=0;i<255;i++){
        printf("%d : %c\n",i,i);
    }
    
    act = getch();
    return 0;
}
