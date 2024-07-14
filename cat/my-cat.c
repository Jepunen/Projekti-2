/*
Sources:
https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
https://stackoverflow.com/questions/42393117/c-print-lines-from-file-with-getline
https://stackoverflow.com/questions/19813949/how-to-read-a-line-from-a-file-in-c
*/

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