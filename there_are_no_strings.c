#include <stdio.h>
#include <string.h>

int main() {
    char my_string[] = "Hello World!";

    for (int i = 0; my_string[i] != 0; i++) {
        printf("%c\n", my_string[i]);
    }

    char array_of_chars[] = {
        't',
        'e',
        's',
        't',
        '\0'
    };

    printf("%s\n", array_of_chars);

    // dangerous
    char string_with_no_end[5];
    string_with_no_end[0] = 'a';
    string_with_no_end[1] = 'b';
    string_with_no_end[2] = 'c';
    string_with_no_end[3] = 'd';
    string_with_no_end[4] = 'e';

    printf("%s\n", string_with_no_end);
    // no terminating null-byte

    return 0;
}
