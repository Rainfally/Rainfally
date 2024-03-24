#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
char getSignal()
{
    char signal[4] = { '+','-','*','/' };
    srand((unsigned)time(NULL));
    return signal[rand() % 4];
}
int random(double start, double end)
{
    return (int)(start + (end - start) * rand() / (RAND_MAX + 1.0));
}
int getResult(int num1, int num2, char signal)
{
    int res=0;
    switch (signal)
    {
    case '+':
        res = num1 + num2; break;
    case '-':
        res = num1 - num2; break;
    case '*':
        res = num1 * num2; break;
    case '/':
        res = num1 / num2; break;
    default:
        printf("ÔËËã·û´íÎó£¡\n");
    }
    return res;
}
int takeTest()
{
    int get;
    int num1, num2, a;
    char signal;
    srand((unsigned)time(NULL));
    signal = getSignal();
    num1 = random(0, 1000);
    num2 = random(1, 1000);
    if (signal == '-')
    {
        if (num1 < num2)
        {
            int temp;
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
    }
    if (signal == '/')
    {
        if (num2 == 0)
        {
            int temp;
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
    }
    printf("%d%c%d=", num1, signal, num2);
    scanf_s("%d", &get);
    fflush(stdin);   //Çå¿ÕÊäÈë»º³åÇø
    if (getResult(num1, num2, signal) == get)
    {
        printf("You're right!\n");
        a = 1;
    }
    else
    {
        printf("It's wrong!\n");
        printf("The right answer is: %d\n", getResult(num1, num2, signal));
        a = 0;
    }
    return a;
}
int main()
{
    FILE* fp1=NULL;
    int n, a, right = 0,wrong=0;
    double percent;
    printf("Please enter the number of the test:");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a = takeTest();
        right = right + a;
    }
    printf("Powerful!\n");
    printf("The number of right:%d\n", right);
    fp1 = fopen("D:\Grate.txt", "w");
    if (fp1)
    {
        fprintf(fp1,"Correct:%d\n",right);
    }
    fclose(fp1);
    wrong = n - right;
    fp1 = fopen("D:\Grate.txt", "a");
    if(fp1)
    {
        fprintf(fp1, "Wrong:%d\n", wrong);
    }
    percent = ((double)right * 100.00) / (double)n;
    printf("The percent of right:%0.2f %%\n", percent);
}