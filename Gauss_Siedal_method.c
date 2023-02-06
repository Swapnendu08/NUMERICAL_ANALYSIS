#include <stdio.h>
int arr[100][100], b[100];
void generate_general_terms(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == n)
            {
                printf("a%d%dx%d = b%d", i, j, j, i);
            }
            else
            {
                printf("a%d%dx%d + ", i, j, j);
            }
        }
        printf("\n");
    }
}
void generate(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == n)
            {
                printf("%dx%d = %d", arr[i][j], j, b[i]);
            }
            else
            {
                printf("%dx%d + ", arr[i][j], j);
            }
        }
        printf("\n");
    }
}
float mod(float x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return (-x);
    }
}
int main(int argc, char const *argv[])
{
    float x1 = 0, x2 = 0, x3 = 0;
    printf("Lets use Gauss_Siedal_method for 3 terms\n");
    printf("Your equations are in the form of :-\n");
    printf("____________________________________________________________________\n");
    generate_general_terms(3);
    printf("____________________________________________________________________\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            printf("Enter the value of a%d%d\n", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    for (int i = 1; i <= 3; i++)
    {
        printf("Enter the value of b%d\n", i);
        scanf("%d", &b[i]);
    }
    printf("____________________________________________________________________\n");
    generate(3);
    printf("x1=(b1-a12x2-a13x3)/a11\n\n");
    printf("x2=(b2-a23x3-a21x1)/a22\n\n");
    printf("x3=(b3-a31x1-a32x2)/a33\n\n");
    printf("Let our initial guess by x1=0;x2=0,x3=0\n");
    if ((mod(arr[1][1]) >= (mod(arr[1][2]) + mod(arr[1][3]))) && (mod(arr[2][2]) >= (mod(arr[2][1]) + mod(arr[2][3]))) && (mod(arr[3][3]) >= (mod(arr[3][1]) + mod(arr[3][2]))))
    {
        for (int i = 0; i < 20; i++)
        {
            x1 = (b[1] - (arr[1][2] * x2) - (arr[1][3] * x3)) / arr[1][1];
            x2 = (b[2] - (arr[2][3] * x3) - (arr[2][1] * x1)) / arr[2][2];
            x3 = (b[3] - (arr[3][1] * x1) - (arr[3][2] * x2)) / arr[3][3];
            printf("x1=%f,x2=%f,x3=%f\n\n", x1, x2, x3);
        }
    }
    else
    {
        printf("Gauss-Siedal Method cannot be used as the coeefients of x1/x2/x3 is not greater than the sum of the coeffients of x2/x3,x3/x1,x1/x2.\n");
    }

    return 0;
}