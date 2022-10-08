#include <stdio.h>

int main()
{
    struct date
    {
        int year;
        int month;
        int day;
    }holiday={2004, 4, 26},festival;

    printf("Input year: ");
    scanf("%d",&festival.year);
    printf("Input month: ");
    scanf("%d",&festival.month);
    printf("Input day: ");
    scanf("%d",&festival.day);

    printf("holiday=%02d/%02d/%04d \n",holiday.month,holiday.day,holiday.year);
    printf("festival=%02d/%02d/%04d \n",festival.month,festival.day,festival.year);

    return 0;
}
