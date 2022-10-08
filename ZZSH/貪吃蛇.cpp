#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

HANDLE hOut;
int act,Pos[841][2],dir,len,food[2],mode=3;

void gotoxy(int x,int y)
{
    static COORD coord; 
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition (hOut, coord);
}

void draw(int x,int y)
{	
	gotoxy (x,y);
	cout << "■";
}

void HideCursor() 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); 
}

void gfood()
{
	int restart;
	do{
		restart=0;
		food[0]=(rand()%29)*2+2;
		food[1]=(rand()%29)+1;
		for(int i=0;i<len;i++)
		{
			if(Pos[i][0]==food[0]&&Pos[i][1]==food[1])
				restart=1;
		}
	}while(restart==1);
	
	gotoxy(food[0],food[1]);
	cout << "[]" ;
}

void setting()
{
	cout << "Choose Mode(0/1/2): ";
	while((mode!=0)&&(mode!=1)&&(mode!=2))
	{
		gotoxy(21,0);
		cout << "     ";
		gotoxy(21,0);
		cin >> mode;
		//mode=getch();
	}
	
	len=1; //設定初始長度 
	gotoxy(0,0);
	for(int i=0;i<=60;i++) //此行開始列印場地------------
	{
		cout << "═" ;
	}
	for(int i=1;i<=29;i++)
	{
		gotoxy(0,i);
		cout << "║" ; //字體寬2格 
		gotoxy(60,i);
		cout << "║" ;
	}
	gotoxy(0,30);
	for(int i=0;i<=60;i++)
	{
		cout << "═" ;
	}
	gotoxy(0,0);
	cout << "╔" ;
	gotoxy(60,0);
	cout << "╗" ;
	gotoxy(0,30);
	cout << "╚" ;
	gotoxy(60,30);
	cout << "╝" ;  //列印場地結束----------------------- 
	
	gotoxy(20,15);
	cout << "按下SPACE來開始遊戲..." ;
}

void start()
{
	gotoxy(37,31);
	cout << "按下SPACE可強制中斷遊戲" ;
	gotoxy(20,15);
	cout << "                      " ;
	gotoxy(30,15);
	cout << "■" ; //字體長度為2
	Pos[0][0]=30;  //前面那格表示蛇長的第幾個,後面那格[0]表示x座標,[1]表示y座標 
	Pos[0][1]=15;
	gfood();
}

void gameover()
{
	gotoxy(17,14);
	cout << "                         " ;
	gotoxy(17,15);
	cout << "     -- GAME OVER --     " ;
	gotoxy(17,16);
	cout << "                         " ;
	gotoxy(20,17);
	cout << "     Length: " << len <<"     ";
	gotoxy(20,18);
	cout << "                    ";
}


int main()
{	
	start:   //label for "goto"
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//setting 弄一個101x41的場地
	setting();
	
	//before start game
	while(kbhit()==0)
	{
		if(getch()==32)
		{
			start();
			act=0;
			break;
		}
	}
	
	//playing ------------------------------------------------------------------------------------------
	while(act!=32)
	{
		HideCursor(); //隱藏輸入光標 
		if(kbhit())   //是否按鍵盤,是則改變方向 
		{
			act=getch();
		}
		
		
		for(int i=0;i<len;i++)  //將行動軌跡傳承給下一個資料 
		{
			Pos[len-i][0]=Pos[len-i-1][0]; //先複製好等下要被修改(傳承)的資料 
			Pos[len-i][1]=Pos[len-i-1][1];
			
		}
		
		switch(act)  //移動&增長
		{
			case 119:
				Pos[0][1]=Pos[0][1]-1;
				if(Pos[0][0]==food[0]&&Pos[0][1]==food[1])
				{
					len=len+1;
					Pos[len][0]=62;
					gfood();
				}
				break;
			case 97:
				Pos[0][0]=Pos[0][0]-2;
				if(Pos[0][0]==food[0]&&Pos[0][1]==food[1])
				{
					len=len+1;
					Pos[len][0]=62;
					gfood();
				}
				break;
			case 115:
				Pos[0][1]=Pos[0][1]+1;
				if(Pos[0][0]==food[0]&&Pos[0][1]==food[1])
				{
					len=len+1;
					Pos[len][0]=62;
					gfood();
				}
				break;
			case 100:
				Pos[0][0]=Pos[0][0]+2;
				if(Pos[0][0]==food[0]&&Pos[0][1]==food[1])
				{
					len=len+1;
					Pos[len][0]=62;
					gfood();
				}
		}
		
		
		if(Pos[0][1]<=0||Pos[0][0]<=1||Pos[0][1]>=30||Pos[0][0]>=60)  //死亡偵測 1
		{
			gameover();
			gotoxy(0,31);
			break;
		}
		for(int k=1;k<len;k++)                                        //死亡偵測 2
		{
			if(Pos[0][0]==Pos[k][0]&&Pos[0][1]==Pos[k][1])
			{
				gameover();
				gotoxy(0,31);
				Pos[0][0]=-1; //借用Pos[0][0],等於-1時表示需要break出playing loop 
				break;
			}
		}
		if(Pos[0][0]==-1)
			break;
		
		draw(Pos[0][0],Pos[0][1]);  //畫出蛇
		
		gotoxy(Pos[len][0],Pos[len][1]); //消掉尾巴 
		if(act!=0)
			cout << "  "; 
		
		
		if(mode==0)
			Sleep(125);
		else if(mode==1)
			Sleep(100);
		else if(mode==2)
			Sleep(75);
	}
	//----------------------------------------------------------------------------------------------------
	
	gotoxy(1,31);
	cout << "按下SPACE結束程式" ;
	gotoxy(1,32);
	cout << "按下R重新遊戲" ;
	while(act!=32&&act!=114)
	{
		act=getch();
		if(act==114)
		{
			gotoxy(0,0);
			for(int i=0;i<=32;i++)
			{
				cout << "                                                             " << endl;
			}
			gotoxy(0,0);
			goto start;
		}
		else if(act==32)
		{
			break;
		}
	}
	
	return 0;
} 
