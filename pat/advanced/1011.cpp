#include<cstdio>

using namespace std;

const char game[] = { 'W', 'T', 'L' };

int
main ()
{
    double x[3][3];

    int max[3] = { 0 };

    for (int i = 0; i < 9; ++i)
        scanf ("%lf", x[0] + i);
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j < 3; ++j)
            if (x[i][j] > x[i][max[i]])
                max[i] = j;
    double profit =
        (x[0][max[0]] * x[1][max[1]] * x[2][max[2]] * 0.65 - 1) * 2;
    printf ("%c %c %c %.2lf\n", game[max[0]], game[max[1]], game[max[2]],
            profit);

    return 0;
}
