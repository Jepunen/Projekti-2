#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if ( argc < 2 ) {
        return 0;
    }

    for ( int i = 1; i < argc; i++ ) {
        FILE *file = fopen(argv[i], "r");
        if ( file == NULL ) {
            printf("my-cat: cannot open file\n");
            return 1;
        }

        char *str = NULL;
        size_t size = 0;
        ssize_t len = 0;

        while ( (len = getline(&str, &size, file)) != -1 ) {
            printf("%s", str);
        }
        free(str);
        fclose(file);
    }
    return 0;
}