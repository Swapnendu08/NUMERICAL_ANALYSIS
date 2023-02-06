#include <stdio.h>
float arr[100][100], m;
int n;

void generate_general_terms(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == n)
            {
                printf("a%d%dx%d = a%d%d", i, j, j, i, j + 1);
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
                printf("%0.2fx%d = %0.2f", arr[i][j], j, arr[i][j + 1]);
            }
            else
            {
                printf("%0.2fx%d + ", arr[i][j], j);
            }
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    float x1, x2, x3;
    n=3;
    printf("Lets first use for 3 terms\n");
    printf("Your equations are in the form of :-\n");
    printf("____________________________________________________________________\n");
    generate_general_terms(n);
    printf("____________________________________________________________________\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("Enter the value of a%d%d\n", i, j);
            scanf("%f", &arr[i][j]);
        }
    }
    printf("\n");
    printf("____________________________________________________________________\n");
    generate(n);
    for (int i = 2; i <= n; i++)
    {
        m = arr[i][1] / arr[1][1];
        for (int j = 1; j <= n + 1; j++)
        {
            arr[i][j] = arr[i][j] - (m * arr[1][j]);
        }
    }
    m = arr[3][2] / arr[2][2];

    for (int j = 2; j <= n + 1; j++)
    {
        arr[3][j] = arr[3][j] - (m * arr[2][j]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("%0.2f ", arr[i][j]);
        }
        printf("\n");
    }
    x3 = arr[3][4] / arr[3][3];
    x2 = (arr[2][4] - (arr[2][3] * x3)) / arr[2][2];
    x1 = (arr[1][4] - (arr[1][3] * x3) - (arr[1][2] * x2)) / arr[1][1];
    printf("The solutionn is x1=%f,x2=%f,x3=%f", x1, x2, x3);

    return 0;
}