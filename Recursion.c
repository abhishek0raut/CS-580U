// Program to count to zero from a given positive or negative number, implemnts recursive function

#include<stdio.h>

int countToZero(int num)
{
    if(num > 0)
    {
        printf("%d \n", num);
        num--;
        countToZero(num);
    }
    else if(num < 0)
    {
        printf("%d \n", num);
        num++;
        countToZero(num);

    }
    else
    {
        return 0;
    }

}

int main()
{
    int num;
    printf("Enter a positive or negative number to count to zero from:");
    scanf("%d",&num);
    printf("Counting given Number to zero: \n");
    num = countToZero(num);
    printf("%d",num);
    return 0;
}
