#include<iostream> 
#include<stdio.h>
#include<cstdlib>

int k(int);

int main()
{
	int input;
	int number;
	printf("\n 請輸入[二或一位數]: ");
	input = scanf("%d",&number);
	if(input != 1)
	{
		printf(">> Program Interrupt");
		exit(0);
	}
	if((number<0)||(number>=100))
	{
		printf("     -----Wrong-----");
		while((number<0)||(number>99))
		{
			printf("\n 重新輸入: ");
			scanf("%d",&number);
			if((number<0)||(number>=100))
			{
				printf("    -----Wrong-----");
			}
		}
	}
	k(number);
	printf("\n>> Program has ended\n");
	system("PAUSE") ;
	return 0;
}




















int k(int number)
{
	int i=-1,j=0,f,o;
	int g,n2_2,n2_1,l=-1,m;
	int N[5][41]={{1,1,1,1 ,0,1,0,0 ,1,1,1,1 ,1,1,1,1 ,1,0,0,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,0},
	              {1,0,0,1 ,0,1,0,0 ,0,0,0,1 ,0,0,0,1 ,1,0,0,1 ,1,0,0,0 ,1,0,0,0 ,0,0,0,1 ,1,0,0,1 ,1,0,0,1 ,0},
				  {1,0,0,1 ,0,1,0,0 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,0,0,1,0 ,1,1,1,1 ,1,1,1,1 ,0},
				  {1,0,0,1 ,0,1,0,0 ,1,0,0,0 ,0,0,0,1 ,0,0,0,1 ,0,0,0,1 ,1,0,0,1 ,0,1,0,0 ,1,0,0,1 ,0,0,0,1 ,0},
				  {1,1,1,1 ,0,1,0,0 ,1,1,1,1 ,1,1,1,1 ,0,0,0,1 ,1,1,1,1 ,1,1,1,1 ,0,1,0,0 ,1,1,1,1 ,1,1,1,1 ,0}};
    int N2[5][9];
	if(number==0)
	{
		j=4;//0	
	}
	else if(number==1)
	{
		j=8;//1
	}
	else if(number==2)
	{
		j=12;//2
	}
	else if(number==3)
	{
	    j=16;//3	
	}
	else if(number==4)
	{
		j=20;//4
	}
	else if(number==5)
	{
		j=24;//5
	}
	else if(number==6)
	{
		j=28;//6
	}
	else if(number==7)
	{
		j=32;//7
	}
	else if(number==8)
	{
		j=36;//8
	}
	else if(number==9)
	{
		j=40;//9
	}
	else if(number>9)//-----十位數HERE---------------------------------------------------------------------------------
	{
		n2_2=number/10;
		n2_1=number%10;
		if(n2_2==1)
		{
			m=8;
		}
		else if(n2_2==2)
		{
			m=12;
		}
		else if(n2_2==3)
		{
			m=16;
		}
		else if(n2_2==4)
		{
			m=20;
		}
		else if(n2_2==5)
		{
			m=24;
		}
		else if(n2_2==6)
		{
			m=28;
		}
		else if(n2_2==7)
		{
			m=32;
		}
		else if(n2_2==8)
		{
			m=36;
		}
		else if(n2_2==9)
		{
			m=40;
		}
		for(g=1;g<=20;g++)
	    {
		    if((m%4)==0)
		    {
		    	l=l+1;
		    	m=m-4;
		    }
		    if(N[l][m]==0)
		    {
		    	o=m%4;
		    	N2[l][o]=0;
		    }
		    else
		    {
			    if(N[l][m]==1)
			    {
			    	o=m%4;
			    	N2[l][o]=1;
				}
		    }
		    m++;
	    }
	    //---------
	    l=-1;// "l"歸位 
	    if(n2_1==0)
	    {
	    	m=4;
		}
		else if(n2_1==1)
		{
			m=8; 
		}
		else if(n2_1==2)
		{
			m=12; 
		}
		else if(n2_1==3)
		{
			m=16; 
		}
		else if(n2_1==4)
		{
			m=20; 
		}
		else if(n2_1==5)
		{
			m=24; 
		}
		else if(n2_1==6)
		{
			m=28; 
		}
		else if(n2_1==7)
		{
			m=32; 
		}
		else if(n2_1==8)
		{
			m=36; 
		}
		else if(n2_1==9)
		{
			m=40; 
		}
		for(g=1;g<=20;g++)
	    {
		    if((m%4)==0)
		    {
		    	l=l+1;
		    	m=m-4;
		    }
		
	    	if(N[l][m]==0)
		    {
		    	o=(m%4)+5;
		    	N2[l][o]=0;
		    }
		    else
		    {
			    if(N[l][m]==1)
			    {
			    	o=(m%4)+5;
			    	N2[l][o]=1;
				}
		    }
		    m++;
	    }
		 
	}
	//-----十位數HERE--------------------------------------------------------------------------------------------------------------------
	
	printf("--------------------------------\n");
	if((number>0)&&(number<=9))
	{
		for(f=1;f<=20;f++)
	    {
		    if((j%4)==0)
		    {
		    	i=i+1;
		    	j=j-4;
		    }
		
		    if(N[i][j]==0)
	    	{
		    	printf("  ");
		    }
		    else
		    {
			    if(N[i][j]==1)
			    printf("■");
		    }
		    j++;
		    if((f%4)==0)
		    {
		    	printf("\n");
		    }
	    }
	}
	else if((number>9)&&(number<100))
	{
		i=0;
		j=-1;
		for(f=1;f<=45;f++)
	    {
	    	j++;
		    if(N2[i][j]==0)
	    	{
		    	printf("  ");
		    }
		    else
		    {
			    if(N2[i][j]==1)
			    printf("■");
		    }
		    if(((j%8)==0)&&(j!=0))
		    {
		    	i=i+1;
		    	j=-1;
		    }
		    if(((f%9)==0)&&(f!=1))
		    {
		    	printf("\n");
		    }
	    }
	}
	return 1;
}
