#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int, int);
void initial();
void border();
void display();
void generate();
int movable(char);
void move(char);
int losedetect();
void endgame();

int block[4][4];

int main()
{
    //program
    int endprogram=0;
    while(endprogram!=13)
    {
        //Initial interface
        initial();

        //Before playing
        char playing = 0;
        while(playing!=32)
        {
            gotoxy(52,17);
            playing=getch();
        }

        //Game start
        border();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                block[i][j]=0;
            }
        }

        //playing
        int lose=0;
        char act;
        while(lose!=1)
        {
            generate();
            display();
            if(losedetect())
                break;

            act=0;
            while(act=getch())
            {
                if(movable(act))
                    break;
            }

            if(act=='i'||act=='I')
                lose=1;
            move(act);
        }

        endgame();
        endprogram=getch();
    }

    printf("\n");
    return 0;
}

//Functions -------------------------------------------------------------------------------
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void initial()
{
    gotoxy(0,0);
    printf("==================================================================\n");
    printf("                                                                  \n");
    printf("                      Welcome to 2048 GAME!!                      \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("             > Press W/A/S/D to move, Press I to interrupt        \n");
    printf("                                                                  \n");
    printf("             > If any block has value of 2048, you win            \n");
    printf("                                                                  \n");
    printf("             > You can continue your playing after you win        \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                   Press space to start the Game...               \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("==================================================================\n");
}
void border()
{
    gotoxy(0,2);
    printf("        2048 GAME          Highest value:             Score:      \n");
    //6x4+2=26 3x4+2=14
    gotoxy(0,4);
    printf("                    שÝשששששששששששששששששששששששששששששששששששששששששששששששששß                    \n");
    for(int i=0;i<12;i++)
    {
        printf("                    שר                        שר                    \n");
    }
    printf("                    שדשששששששששששששששששששששששששששששששששששששששששששששששששו                    ");
}
void display()
{
    //score
    int highest=0,sum=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            sum=sum+block[i][j];
            if(block[i][j]>highest)
                highest=block[i][j];
        }
    }
    if(highest==2048)
    {
        gotoxy(5,10);
        printf("** YOU WIN **");
        gotoxy(49,10);
        printf("** YOU WIN **");
    }
    gotoxy(41,2);
    printf("%d",highest);
    gotoxy(60,2);
    printf("%d",sum);
    //blocks
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==0)
            {
                gotoxy(6*j+21,3*i+5);
                printf("      ");
                gotoxy(6*j+21,3*i+6);
                printf("      ");
                gotoxy(6*j+21,3*i+7);
                printf("      ");
            }
            else
            {
                gotoxy(6*j+21,3*i+5);
                printf("¢z¢w¢w¢w¢w¢{");
                gotoxy(6*j+21,3*i+6);
                if((block[i][j]/100000)>=1)
                    printf("%6d",block[i][j]);
                else if((block[i][j]/10000)>=1)
                    printf("¢x%5d",block[i][j]);
                else
                    printf("¢x%4d¢x",block[i][j]);
                gotoxy(6*j+21,3*i+7);
                printf("¢|¢w¢w¢w¢w¢}");
            }
        }
    }
    gotoxy(0,1);
}
void generate()
{
    //generate new block 2 or 4
    srand(time(NULL));
    int v,px,py,count=0;
    v=(rand()%2+1)*2;

    do{
        px=rand()%4;
        py=rand()%4;
    }while(block[py][px]!=0);

    block[py][px] = v;
}
int movable(char act)
{
    //check if any blocks can be moved
    switch(act)
    {
        case 'W':
        case 'w':
            for(int j=0;j<4;j++)
            {
                for(int i=3;i>0;i--)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i-1][j]==0)
                            return 1;
                        if(block[i][j]==block[i-1][j])
                            return 1;
                    }
                }
            }
            break;
        case 'A':
        case 'a':
            for(int i=0;i<4;i++)
            {
                for(int j=3;j>0;j--)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j-1]==0)
                            return 1;
                        if(block[i][j]==block[i][j-1])
                            return 1;
                    }
                }
            }
            break;
        case 'S':
        case 's':
            for(int j=0;j<4;j++)
            {
                for(int i=0;i<3;i++)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i+1][j]==0)
                            return 1;
                        if(block[i][j]==block[i+1][j])
                            return 1;
                    }
                }
            }
            break;
        case 'D':
        case 'd':
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j+1]==0)
                            return 1;
                        if(block[i][j]==block[i][j+1])
                            return 1;
                    }
                }
            }
            break;
        //interrupt the game
        case 'I':
        case 'i':
            return 1;
        default:
            break;
    }
    return 0;
}
void move(char act)
{
    //first step: switch to the "act" direction
    //second step: combine the blocks that should be merged
    //third step: move all blocks
    int tmp,x,y;
    printf("Act=%c",act);
    switch(act)
    {
        case 'W':
        case 'w':
            for(int j=0;j<4;j++)
            {
                //Plus the blocks on the [j] column
                tmp=0;
                for(int i=0;i<4;i++)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j]==tmp)
                        {
                            block[y][x]=tmp*2;
                            block[i][j]=0;
                        }
                        tmp=block[i][j];
                        y=i;
                        x=j;
                    }
                }
                //Move the blocks on the [j] column
                for(int i=0;i<4;i++)
                {
                    tmp=block[i][j];
                    if(tmp==0)
                    {
                        for(int k=1;k<4-i;k++)
                        {
                            if(block[i+k][j]!=0)
                            {
                                block[i][j]=block[i+k][j];
                                block[i+k][j]=0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 'A':
        case 'a':
            for(int i=0;i<4;i++)
            {
                //Plus the blocks on the [i] row
                tmp=0;
                for(int j=0;j<4;j++)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j]==tmp)
                        {
                            block[y][x]=tmp*2;
                            block[i][j]=0;
                        }
                        tmp=block[i][j];
                        y=i;
                        x=j;
                    }
                }
                //Move the blocks on the [i] row
                for(int j=0;j<4;j++)
                {
                    tmp=block[i][j];
                    if(tmp==0)
                    {
                        for(int k=1;k<4-j;k++)
                        {
                            if(block[i][j+k]!=0)
                            {
                                block[i][j]=block[i][j+k];
                                block[i][j+k]=0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 'S':
        case 's':
            for(int j=0;j<4;j++)
            {
                //Plus the blocks on the [j] column
                tmp=0;
                for(int i=3;i>=0;i--)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j]==tmp)
                        {
                            block[y][x]=tmp*2;
                            block[i][j]=0;
                        }
                        tmp=block[i][j];
                        y=i;
                        x=j;
                    }
                }
                //Move the blocks on the [j] column
                for(int i=3;i>=0;i--)
                {
                    tmp=block[i][j];
                    if(tmp==0)
                    {
                        for(int k=1;k<=i;k++)
                        {
                            if(block[i-k][j]!=0)
                            {
                                block[i][j]=block[i-k][j];
                                block[i-k][j]=0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 'D':
        case 'd':
            for(int i=0;i<4;i++)
            {
                //Plus the blocks on the [i] row
                tmp=0;
                for(int j=3;j>=0;j--)
                {
                    if(block[i][j]!=0)
                    {
                        if(block[i][j]==tmp)
                        {
                            block[y][x]=tmp*2;
                            block[i][j]=0;
                        }
                        tmp=block[i][j];
                        y=i;
                        x=j;
                    }
                }
                //Move the blocks on the [i] row
                for(int j=3;j>=0;j--)
                {
                    tmp=block[i][j];
                    if(tmp==0)
                    {
                        for(int k=1;k<=j;k++)
                        {
                            if(block[i][j-k]!=0)
                            {
                                block[i][j]=block[i][j-k];
                                block[i][j-k]=0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
    }
}
int losedetect()
{
    int rtn=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==0)
                rtn=0;
        }
    }
    if(rtn==1)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(j>0)
                {
                    if(block[i][j]==block[i][j-1])
                        rtn=0;
                }
                if(i>0)
                {
                    if(block[i][j]==block[i-1][j])
                        rtn=0;
                }
            }
        }
    }
    return rtn;
}
void endgame()
{
    gotoxy(5,18);
    printf("**GAME OVER**\n");
    //Exit program or restart
    gotoxy(5,19);
    printf("Press Enter/Other Keys to End/Restart the program ...");
}
