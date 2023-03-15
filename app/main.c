#include <stdio.h>
#include <assert.h>

#include "myfunc.h"
#include "quadratic.h"
#include "equation.h"

void rewrite(struct equation *e, int a, int b, int c){
    e->a = a;
    e->b = b;
    e->c = c;
    e->is_solutions = 0;
    e->x1 = 0;
    e->x2 = 0;
}

int main()
{
    struct equation e;

    int a;
    int b;
    int c;

    assert(scanf("%d %d %d", &a, &b, &c) > 0);

    rewrite(&e, a, b, c);

    quadratic(e);
    if (e.is_solutions)
        printf("%lf %lf", e.x1, e.x2);
    else
        printf("Решений нет");
}
