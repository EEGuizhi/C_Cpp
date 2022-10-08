#include <stdio.h>

int main()
{
    int n=0;
    char str[81];
    printf("Enter a line: ");
    gets(str);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a')
            n=n+1;
    }
    printf("There are %d 'a's in this line.\n",n);

    return 0;
}
