#include <stdio.h>

void bubbleSort(int *array, int size);
void swap(int *a, int *b);

int main()
{
    int a[] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    int size=sizeof(a)/sizeof(int);
    printf("Data items before sorting \n");
    for(int i=0;i<size;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");

    bubbleSort(a,size);
    printf("Data items after sorting \n");
    for(int i=0;i<size;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSort(int *array, int size)
{
    int done=0;
    for(int i=0;i<size;i++)
    {
        done=1;
        for(int j=0;j<(size-i-1);j++)
        {
            if(array[j]<array[j+1])
            {
                swap(&array[j],&array[j+1]);
                done=0;
            }
        }
        if(done==1)
            break;
    }
}

void swap(int *a, int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
