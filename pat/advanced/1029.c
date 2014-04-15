#include<stdio.h>
#include<stdlib.h>

int
main ()
{
    int n1, n2, n, i, j, k;

    long int *p1, *p2, *p;

    while (scanf ("%d", &n1) != EOF)
    {
        p1 = p2 = p = NULL;

        if ((p1 = (long int *) malloc (n1 * sizeof (long int))) == NULL)
            exit (-1);
        for (i = 0; i < n1; ++i)
            scanf ("%ld", p1 + i);

        scanf ("%d", &n2);
        if ((p2 = (long int *) malloc (n2 * sizeof (long int))) == NULL)
            exit (-1);
        for (i = 0; i < n2; ++i)
            scanf ("%ld", p2 + i);

        n = n1 + n2;
        if ((p = (long int *) malloc (n * sizeof (long int))) == NULL)
            exit (-1);

        i = j = k = 0;
        while ((i < n1) && (j < n2))
        {
            if (p1[i] < p2[j])
                p[k++] = p1[i++];
            else
                p[k++] = p2[j++];
        }
        if (i == n1)
            while (j < n2)
                p[k++] = p2[j++];
        else
            while (i < n1)
                p[k++] = p1[i++];

        printf ("%ld\n", p[n / 2 - (n % 2 ? 0 : 1)]);

        free (p1);
        free (p2);
        free (p);
    }
    return 0;
}
