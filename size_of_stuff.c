#include <stdio.h>
#include <stdint.h>

struct test {
    int a;
    int b;
};

struct large {
    void* data;
    char buffer[64];
};

struct not_padded {
    int a;
    int b;
    int* c;
    int* d;
};

struct padded {
    int a;
    int* b;
    int c;
    int* d;
};

int main() {
    // machine dependent code
    printf("Size of %s : %ld\n", "char", sizeof(char));
    printf("Size of %s : %ld\n", "short", sizeof(short));
    printf("Size of %s : %ld\n", "int", sizeof(int));
    printf("Size of %s : %ld\n", "float", sizeof(float));
    printf("Size of %s : %ld\n", "double", sizeof(double));
    printf("Size of %s : %ld\n", "pointer", sizeof(void*));

    // garanteed size
    printf("\nSize of more stuff:\n");
    printf("Size of %s : %ld\n", "short", sizeof(int8_t));
    printf("Size of %s : %ld\n", "half-word", sizeof(int16_t));
    printf("Size of %s : %ld\n", "word", sizeof(int32_t));
    printf("Size of %s : %ld\n", "long word", sizeof(int64_t));

    // size of structs
    printf("\nSize of structs:\n");
    printf("Size of 'test' struct : %ld\n", sizeof(struct test));
    printf("Size of 'large' struct : %ld\n", sizeof(struct large));
    printf("Size of 'not_padded' struct : %ld\n", sizeof(struct not_padded));
    printf("Size of 'padded' struct : %ld\n", sizeof(struct padded));
}
