#include <stdio.h>

int main()
{
  float x[100], y[100], sum = 0, prodfunc;
  int n;
  printf("How many values do you have????\n");
  scanf("%d", &n);
  printf("Enter your values in x axis\n");
  for (int i = 1; i <= n; i++)
  {
    printf("Enter x%d\n", i);
    scanf("%f", &x[i]);
  }
  printf("Enter your values in y axis\n");
  for (int i = 1; i <= n; i++)
  {
    printf("Enter y%d\n", i);
    scanf("%f", &y[i]);
  }
  float xp, p, q;
  printf("Enter the Interpolated value!!!\n");
  scanf("%f", &xp);
  for (int i = 1; i <= n; i++)
  {
    prodfunc = 1;
    for (int j = 1; j <= n; j++)
    {
      if (j != i)
      {
        prodfunc = prodfunc * ((xp - x[j]) / (x[i] - x[j]));
      }
    }
    sum = sum + y[i] * prodfunc;
  }
  printf("---------\n");
  printf("The interpolated result is approximately equal to %f\n", sum);
}
