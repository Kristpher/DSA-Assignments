#include <stdio.h>
#define INF 10000000
int main()
{
    int a;
    scanf("%d", &a);
    int g[a][a];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == -1)
            {
                g[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < a; k++)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (g[i][k] + g[k][j] < g[i][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (g[i][j] != INF)
            {
                printf("%d ", g[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
