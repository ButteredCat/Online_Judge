#include<stdio.h>
#include<stdlib.h>

static int
cmp (const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
main ()
{
    int k, i, j, a;

    int *n = NULL;

    while (scanf ("%d", &k) != EOF)
    {
        if ((n = (int *) malloc (k * sizeof (int))) == NULL)
            exit (-1);
        for (i = 0; i < k; ++i)
            scanf ("%d ", n + i);
        for (i = 0; i < k; ++i)
            printf ("%d ", n[i]);
        printf ("\n");
        for (i = 0; i < k; ++i)
        {
            a = n[i];
            while ((a != 1) && (a != 0))
            {
                if (a % 2 == 0)
                    a /= 2;
                else
                    a = (3 * a + 1) / 2;
                for (j = 0; j < k; ++i)
                    if (a == n[j])
                        n[j] = 0;
            }
        }
        qsort (n, k, sizeof (int), cmp);
        for (i = 0; i < k; ++i)
            if (n[i] != 0)
                printf ("%d ", n[i]);
        printf ("\n");
        free (n);
    }
    return 0;
}
