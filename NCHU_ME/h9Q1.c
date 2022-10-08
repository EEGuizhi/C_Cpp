#include <stdio.h>

int main()
{
    int arr1[]= { 1, 3 ,2, 5, 4};
    int arr2[]= {41,17,61,55,104,103,39,84,25,110,47,
                 101,34,99,121,122,43,11,30,24,42,90,89,30,46,82,
                 78,20,38,92,35,78,11,99,24,109,83,100,61,54,44,72,
                 19,111,40,32,68,108,51,99,39,116,38,29,32,11,88,97,
                 6,33,14,40,89,56,20,103,93,105,63,110,18,113,78,58,
                 54,6,88,115,11,71,109,14,86,41,12,10,91,72,89,51,41,
                 80,75,84,113,12,85,86,103,86,92,67,39,111,67
                };
    int arr3[]= {113,24,100,40,16,83,50,120,42,94,61,86,
                 76,16,17,66,23,87,16,98,0,105,39,104,72,77,99,28,
                 60,32,46,119,32,109,93,90,26,7,2,13,5,114,51,59,36,
                 59,83,37,68,43,45,74,61,63,14,106,107,120,67,18,75,
                 119,88,15,72,90,78,92,62,0,101,86,110,7,120,48,86,
                 75,54,30,1,6,59,63,92,44,39,76,95,121,44
                };
    int arr4[]= {90,76,67,109,111,56,49,21,82,110,78,51,
                 62,53,106,41,113,15,26,100,77,115,54,17,39,119,
                 66,56,67,86,72,119,23,87,43,105,35,119,82,86,26,
                 73,45,36,42,75,111,7,40,60,53,31,96,17,12,98,46,
                 98,38,10,48,97,95,84,42,98,58,43,41,113,116,108,
                 41,113,63,94,35,32,11,17,50,93,55,26,51,117,72,3,64
                 ,82,7,74,76,28,61,81,18,115,59,110,63,14,92
                };
    int mid,len,tmp,done;
    //array 1
    len=sizeof(arr1)/sizeof(int);
    mid=len/2;
    for(int i=0;i<len;i++)
    {
        done=1;
        for(int j=0;j<(len-i-2);j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                tmp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=tmp;
                done=0;
            }
        }
        if(done==1)
            break;
    }
    printf("The median of array arr1 is: %d \n",arr1[mid]);
    //array 2
    len=sizeof(arr2)/sizeof(int);
    mid=len/2;
    for(int i=0;i<len;i++)
    {
        done=1;
        for(int j=0;j<(len-i-2);j++)
        {
            if(arr2[j]>arr2[j+1])
            {
                tmp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=tmp;
                done=0;
            }
        }
        if(done==1)
            break;
    }
    printf("The median of array arr2 is: %d \n",arr2[mid]);
    //array 3
    len=sizeof(arr3)/sizeof(int);
    mid=len/2;
    for(int i=0;i<len;i++)
    {
        done=1;
        for(int j=0;j<(len-i-2);j++)
        {
            if(arr3[j]>arr3[j+1])
            {
                tmp=arr3[j];
                arr3[j]=arr3[j+1];
                arr3[j+1]=tmp;
                done=0;
            }
        }
        if(done==1)
            break;
    }
    printf("The median of array arr3 is: %d \n",arr3[mid]);
    //array 4
    len=sizeof(arr4)/sizeof(int);
    mid=len/2;
    for(int i=0;i<len;i++)
    {
        done=1;
        for(int j=0;j<(len-i-2);j++)
        {
            if(arr4[j]>arr4[j+1])
            {
                tmp=arr4[j];
                arr4[j]=arr4[j+1];
                arr4[j+1]=tmp;
                done=0;
            }
        }
        if(done==1)
            break;
    }
    printf("The median of array arr4 is: %d \n",arr4[mid]);

    return 0;
}
