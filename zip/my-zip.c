#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress( FILE *input ) {
    int count;
    char curr, prev;

    if ( fread(&prev, sizeof(char), 1, input) != 1 ) {
        return; // Empty file
    }

    count = 1;
    while ( fread(&curr, sizeof(char), 1, input) == 1 ) {
        if ( curr == prev ) {
            count++;
        } else {
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&prev, sizeof(char), 1, stdout);
            prev = curr;
            count = 1;
        }
    }
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&prev, sizeof(char), 1, stdout);

}

int main( int argc, char *argv[] ) {

    if ( argc != 2 ) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");

    if ( !input ) {
        perror("Failed to open input file");
        return 1;
    }

    compress(input);
    fclose(input);

    return 0;
}