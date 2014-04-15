#include<stdio.h>

typedef struct NUMBER
{
    int galleon;
    int sickle;
    int knut;
} number;

int
main ()
{
    number a, b;

    int carry1, carry2;

    while (scanf
            ("%d.%d.%d %d.%d.%d", &a.galleon, &a.sickle, &a.knut,
             &b.galleon, &b.sickle, &b.knut) != EOF)
    {
        carry1 = carry2 = 0;
        if ((a.knut += b.knut) >= 29)
        {
            a.knut -= 29;
            carry1 = 1;
        }
        if ((a.sickle += b.sickle + carry1) >= 17)
        {
            a.sickle -= 17;
            carry2 = 1;
        }
        a.galleon += b.galleon + carry2;
        printf ("%d.%d.%d\n", a.galleon, a.sickle, a.knut);
    }
    return 0;
}
