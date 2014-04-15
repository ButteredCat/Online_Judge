#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Record
{
    char id[7];
    char name[9];
    int grade;
} Rec;

static int
id_cmp (const void *a, const void *b)
{
    Rec *pa = (Rec *) a;

    Rec *pb = (Rec *) b;

    return strcmp (pa->id, pb->id);
}

static int
name_cmp (const void *a, const void *b)
{
    Rec *pa = (Rec *) a;

    Rec *pb = (Rec *) b;

    return strcmp (pa->name, pb->name) == 0 ?
           strcmp (pa->id, pb->id) : strcmp (pa->name, pb->name);
}

static int
grade_cmp (const void *a, const void *b)
{
    Rec *pa = (Rec *) a;

    Rec *pb = (Rec *) b;

    return pa->grade == pb->grade ?
           strcmp (pa->id, pb->id) : pa->grade - pb->grade;
}

int
main ()
{
    int n, c, i;

    int (*cmp[]) (const void *, const void *) =
    {
        id_cmp, name_cmp, grade_cmp
    };
    Rec *p = NULL;

    while (scanf ("%d %d", &n, &c) != EOF)
    {
        if ((p = (Rec *) malloc (n * sizeof (Rec))) == NULL)
            exit (-1);
        for (i = 0; i < n; ++i)
            scanf ("%s %s %d", p[i].id, p[i].name, &p[i].grade);
        qsort (p, n, sizeof (Rec), cmp[c - 1]);
        for (i = 0; i < n; ++i)
            printf ("%s %s %d\n", p[i].id, p[i].name, p[i].grade);
        free (p);
    }
    return 0;
}
