#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TESTEE
{
    char id[14];
    int locat;
    int score;
} Testee;

static int
cmp (const void *a, const void *b)
{
    Testee *pa = (Testee *) a;

    Testee *pb = (Testee *) b;

    if (pa->score != pb->score)
        return pb->score - pa->score;
    else
        return strcmp (pa->id, pb->id);
}

int
main ()
{
    int n, k, size, location, i, samerank, rank;

    Testee *p = NULL;

    while (scanf ("%d", &n) != EOF)
    {
        size = location = 0;
        while ((location < n) && scanf ("%d", &k))
        {
            size += k;
            ++location;
            if ((p =
                        (Testee *) realloc (p, size * sizeof (Testee))) == NULL)
                exit (-1);
            while (k)
            {
                scanf ("%s %d", p[size - k].id, &p[size - k].score);
                p[size - k].locat = location;
                --k;
            }
        }

        qsort (p, size, sizeof (Testee), cmp);

        printf ("%d\n", size);
        rank = samerank = 1;
        int *lrank = (int *) malloc (n * sizeof (int));

        int *samelrank = (int *) malloc (n * sizeof (int));

        if ((lrank == NULL) || (samelrank == NULL))
            exit (-1);
        for (i = 0; i < n; ++i)
            lrank[i] = samelrank[i] = 1;
        for (i = 0; i < size; ++i)
        {
            printf ("%s %d %d %d\n", p[i].id, rank, p[i].locat,
                    lrank[p[i].locat - 1]);
            if (p[i].score == p[i + 1].score)
                ++samerank;
            else
            {
                rank += samerank;
                samerank = 1;
            }
            if ((p[i].locat == p[i + 1].locat)
                    && (p[i].score == p[i + 1].score))
                ++samelrank[p[i].locat - 1];
            else
            {
                lrank[p[i].locat - 1] += samelrank[p[i].locat - 1];
                samelrank[p[i].locat - 1] = 1;
            }
        }
        free (p);
        free (lrank);
        free (samelrank);
    }
    return 0;
}
