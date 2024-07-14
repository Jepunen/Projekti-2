/*
Sources:
https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
https://www.tutorialspoint.com/cprogramming/index.htm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep_output(FILE *file, const char *search_term) {
    char *str = NULL;
    size_t size = 0;
    ssize_t len = 0;

    // Loop through lines and filter out non matching lines
    while ( (len = getline(&str, &size, file)) != -1 ) {
        if ( strstr(str, search_term) == NULL ) {
            continue;
        }
        printf("%s", str);
    }
    free(str);
}

int main(int argc, char *argv[]) {

    // Too few arguments
    if ( argc < 2 ) {
        printf("my-grep: searchterm [file...]\n");
        return 1;
    }

    const char *search_term = argv[1];

    // No file provided, read from terminal
    if ( argc == 2 ) {
        grep_output(stdin, search_term);

    // File(s) provided, read from them
    } else {
        for ( int i = 2; i < argc; i++ ) {
            FILE *file = fopen(argv[i], "r");
            if ( file == NULL ) {
                printf("my-grep: cannot open file\n");
                return 1;
            }
            grep_output(file, search_term);
    
            fclose(file);
        }
    }
    return 0;
}