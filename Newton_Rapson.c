#include <stdio.h>
#include <math.h>
float f(float x)
{
    float y;
    y = (3 * x * x * x) - (2 * x * x) + (x) + 5;
    return y;
}
float df(float x)
{
    float y;
    y = (9 * x * x) - (4 * x) + 1;
    return y;
}

int main(int argc, char const *argv[])
{
    int maxits;
    float x0, epsilon, delta, h, x1, e1;
    printf("Lets have a function f(x)=3x2-2x+5\n");
    printf("We have to find the roots of the equation!!!\n");
    printf("Enter your initial guess!!\n");
    scanf("%f", &x0);
    printf("Enter the prescribed relative error!!\n");
    scanf("%f", &epsilon);
    printf("Enter prescribed lower bound for f'(x)!!\n");
    scanf("%f", &delta);
    printf("Enter the max number of iterations you want!!\n");
    scanf("%d", &maxits);
    for (int i = 1; i <= maxits; i++)
    {
        h = f(x0) / df(x0);
        if (fabs(df(x0) <= delta))
        {
            printf("SLOPE TOO SMALL!!\n");
            return 0;
        }
        else
        {
            x1 = x0 - h;
            e1 = fabs((x1 - x0) / x1);
            if (e1 < epsilon)
            {
                printf("After %d th iterations, root found at x=%f and f(x) is %f", i, x1, f(x1));
                return 0;
            }
            else
            {
                x0 = x1;
            }
        }
    }
    printf("The required solutions does not converge or iterations are done insuficiently!!\n");
    return 0;
}
