
#include <stdio.h>
#include <string.h>
#define maxsize 100
//长整数运算器
int num1[1000] = {0};
int num2[1000] = {0};
int num3[1000] = {0};
char str1[1000] = {0};
char str2[1000] = {0};
int length = 0;
int temp = 0;
int key = 1;

int max()
{
  if (strlen(str1) > strlen(str2))
  {
    return 1;
  }
  if (strlen(str2) > strlen(str1))
  {
    return -1;
  }
  for (int i = (999 - strlen(str1)); i <= 999; i++)
  {
    if (num1[i] > num2[i])
    {
      return 1;
    }
    if (num2[i] > num1[i])
    {
      return -1;
    }
  }
  return 1;
}

void add()
{

  for (int i = 999; i > (999 - length); i--)
  {
    num3[i] = num1[i] + num2[i] + temp;
   // printf("num3 %d\t", num3[i]);
    temp = 0;
    if (num3[i] > 9)
    {
      num3[i] = num3[i] - 10;
      temp = 1;
    }
  }
    printf("result:\t");
  if (temp == 1)
  {
    printf("%d", 1);
  }

  for (int i = 999 - length + 1; i <= 999; i++)
  {
    printf("%d", num3[i]);
  }
  printf("\n");
}

void sub()
{
  int k = 1;
  if (max() == 1)
  {
    k = 1;
  }
  else
  {
    k = -1;
  }

  for (int i = 999; i > (999 - length); i--)
  {
    num3[i] = num1[i] * k - num2[i] * k + temp;
    temp = 0;
    if (num3[i] < 0)
    {
      num3[i] = num3[i] + 10;
      temp = -1;
    }
  }
 // printf("\n");
 printf("result:\t");
  if (k == -1)
  {
    printf("%c", '-');
  }
  length = 1000;
  int n = 0;
  while (num3[n] == 0)
  {
    n++;
    length--;
  }

  for (int i = 999 - length + 1; i <= 999; i++)
  {
    printf("%d", num3[i]);
  }
  printf("\n");
}

int main()
{

  printf("please input num1:\n");
  gets(str1);
  printf("please input num2:\n");
  gets(str2);
  printf("please input (1:+ 2:-):");
  scanf("%d", &key);
  printf("OK\n");
  if (strlen(str1) >= strlen(str2))
  {
    length = strlen(str1);
  }
  else
  {
    length = strlen(str2);
  }

  for (int i = strlen(str1) - 1, j = 999; i >= 0; i--)
  {
    num1[j--] = str1[i] - '0';
  }

  for (int i = strlen(str2) - 1, j = 999; i >= 0; i--)
  {
    num2[j--] = str2[i] - '0';
  }

  if (key == 1)
  {
    add();
  }
  else if (key == 2)
  {
    sub();
  }
}

