#include<stdio.h>

using namespace std;

//題目:先輸入兩數表示陣列大小
//     接著輸入陣列(會空格 換行)(應該是不會有重複的數字) 
//     機器人將從數字最小之數起步
//     走向相鄰四格中最小之數
//     走過之格將不再走
//     注:數字將為不大於100000之非負整數 
//                                求:走到無路可走後 路途中之數字相加 
int main()
{
	int A,B;
	printf("先輸入兩數表示陣列大小 (要空格) ex:2 2\n\n接著輸入陣列 (要空格 換行)\n\n機器人將從數字最小之數起步\n\n走向相鄰四格中最小之數\n\n走過之格將不再走\n\n走至結尾並輸出總和\n\n請開始輸入:");
	while(scanf("%d %d",&A,&B)!=EOF)
	{
		int E[A][B];
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				scanf("%d",&E[i][j]);
			}
		}
		printf("\n陣列為:\n");
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				printf("%d ",E[i][j]);
				if(j==(B-1))
				{
					printf("\n");
				}
			}
		}
		//-------------------------------------------------陣列輸入結束 
		int M,N,m,n;
		m=0;
		n=0;
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				if(E[i][j]<E[m][n])
				{
					m=i;
					n=j;
				}
			}
		}
		printf("\n最小數字(起點)為:%d\n",E[m][n]);
		M=m;
		N=n;
		//--------------------------------------------------find min----end
		int Count=0,Sum=0;
		int D=0;
		D=E[m][n];
		Sum=D;
		E[m][n]=100001;
		while(Count!=4)
		{
			m=M;
			n=N;
			Count=0;
			//照    上 下 左 右     搜查 
			for(int i=1;i<=4;i++)
		    {
			    // 1
			    if(i==1)
			    {
				    if(((m-1)>=0)&&(E[m-1][n]<100001))
				    {
				    	M=m-1;
				    	N=n;
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 2
			    if(i==2)
			    {
				    if(((m+1)<A)&&(E[m+1][n]<100001))
				    {
				    	if(Count==1)
				    	{
				    		M=m+1;
							N=n;
						}
						else if(E[m+1][n]<E[M][N])
						{
							M=m+1;
							N=n;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 3
			    if(i==3)
			    {
				    if(((n-1)>=0)&&(E[m][n-1]<100001))
				    {
				    	if(Count==2)
				    	{
				    		M=m;
							N=n-1;
						}
						else if(E[m][n-1]<E[M][N])
						{
							M=m;
							N=n-1;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 4
			    if(i==4)
			    {
			    	if(((n+1)<B)&&(E[m][n+1]<100001))
				    {
				    	if(Count==3)
				    	{
				    		M=m;
							N=n+1;
						}
						else if(E[m][n+1]<E[M][N])
						{
							M=m;
							N=n+1;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
		    }
		    //----------------find
		    if(Count!=4)
		    {
		    	printf(">>%d",E[M][N]);
		    	Sum=Sum+E[M][N];
		    	D=E[M][N];
			}
		    else
		    {
		    	printf(">>END\n");
		    	printf("SUM=%d",Sum);
			}
			E[M][N]=100001;
		}
	}
	
	return 0;
}
