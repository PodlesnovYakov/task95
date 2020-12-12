#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
void gauss(double **a,int n, int m)
{
    double  sm;
    int k, imax;

    k = 0;
    while (k < n)
    {

        sm = fabs(a[k][k]);
        imax = k;
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(a[i][k]) > sm)
            {
                sm= fabs(a[i][k]);
                imax = i;
            }
        }

        if (sm < 0.00001)
        {

            printf("–ешений нет.");
            return;
        }

        double *t = (double*) malloc(sizeof(double) * m);
        t = a[imax];
        a[imax] = a[k];
        a[k] = t;


        for (int i = k; i < n; i++)
        {
            double t = a[i][k];
            if (fabs(t) < 0.00001) continue;
            for (int j = 0; j < m; j++)
                a[i][j] /= t;

            if (i == k)  continue;
            for (int j = 0; j < m; j++)
                a[i][j] = a[i][j] - a[k][j];
        }
        k++;

    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, n1;
    printf("¬ведите размер матрицы:\n");
    scanf("%d", &n);
    n1 = n + 1;
    double **m = (double **) malloc(sizeof(double *) * n);
    printf("¬ведите элементы матрицы,включа€ х и у.\n");
    for(int i = 0; i < n; ++i)
    {
        m[i] = (double *) malloc(sizeof(double) * (n + 1));
        for(int j = 0; j < n1; ++j)
        {
            scanf("%lf", &m[i][j]);
        }

    }
    gauss(m,n,n1);

    for(int i = n - 1; i >= 0; --i)
    {

        for(int k = i - 1; k >= 0 ; --k)
        {
            double h = m[k][i];
            for (int j = i; j < n + 1; ++j)
            {
                m[k][j] -= m[i][j] * h;

            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        printf("x%d = %lf \n",i + 1, m[i][n]);

    }

    return 0;
}


