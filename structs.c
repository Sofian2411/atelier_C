#include <stdio.h>
#include <stdlib.h>

typedef struct complex MyComplex;

struct complex {
    double r;
    double im;
};

MyComplex newComplex(double r, double im) {
    MyComplex var = { r, im };

    return var;
}

void printComplex(MyComplex complex) {
    printf("Complex(%.2lf, %.2lf)\n", complex.r , complex.im);
}

int main() {
    MyComplex var = newComplex(1, 1);

    printComplex(var);
}
