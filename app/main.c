#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "myfunc.h"
#include "quadratic.h"
#include "equation.h"

int main()
{
    int a;
    int b;
    int c;

    assert(scanf("%d %d %d", &a, &b, &c) > 0);

    struct equation e = {a,b,c,0,0,0,0};

    quadratic(&e);

    if (e.is_solutions){
        if (e.infinity)
            printf("Все числа");
        else
            printf("%lf %lf", e.x1, e.x2);
    }
    else
        printf("Решений нет");
}
