#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "equation.h"

void quadratic(struct equation *e) {
    long determinant = e->b * e->b - 4 * e->a * e->c;

    if (determinant < 0){
        e->is_solutions = 0;
    }
    else if (e->a == 0 && e->b == 0){
        if (e->c == 0){
            e->is_solutions = 1;
            e->infinity = 1;
        }
        else{
            e->is_solutions = 0;
        }
    }
    else{
        e->is_solutions = 1;

        if (e->a == 0){
            e->x1 = (-1 * e->c / e->b);
            e->x2 = e->x1;
        }
        else{
            e->x1 = (-1 * e->b + sqrt(determinant))/(2 * e->a);
            e->x2 = (-1 * e->b - sqrt(determinant))/(2 * e->a);
        }
    }
}
