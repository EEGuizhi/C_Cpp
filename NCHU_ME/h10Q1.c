#include <stdio.h>
#include <ctype.h>

int getnum(char*);

int main()
{
    char a[21],b[21];
    int A,B;
    printf("Enter two weird numbers: ");
    scanf("%s %s",a,b);

    A=getnum(a);
    printf("The first weird number is %s and its value is %d.\n",a,A);
    B=getnum(b);
    printf("The second weird number is %s and its value is %d.\n",b,B);
    printf("The sum of %s and %s is %d.\n",a,b,A+B);

    return 0;
}

int getnum(char str[])
{
    int end,place=1,tmp,num=0;
    for(int i=0;i<21;i++)
    {
        if(str[i]=='\0')
        {
            end=i;
            break;
        }
    }
    for(int i=end;i>=0;i--)
    {
        if(isdigit(str[i]))
        {
            tmp=str[i]-48;
            for(int j=1;j<place;j++)
                tmp=tmp*10;
            num=num+tmp;
            place=place+1;
        }
    }

    return num;
}
