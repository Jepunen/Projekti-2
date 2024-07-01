#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep_output(FILE *file, const char *search_term) {
    char *str = NULL;
    size_t size = 0;
    ssize_t len = 0;

    while ( (len = getline(&str, &size, file)) != -1 ) {
        if ( strstr(str, search_term) == NULL ) {
            continue;
        }
        printf("%s", str);
    }
    free(str);
}

int main(int argc, char *argv[]) {

    if ( argc < 2 ) {
        printf("my-grep: searchterm [file...]\n");
        return 1;
    }

    const char *search_term = argv[1];

    if ( argc == 2 ) {
        grep_output(stdin, search_term);

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