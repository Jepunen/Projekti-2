/*
Sources:
https://www.geeksforgeeks.org/text-file-compression-and-decompression-using-huffman-coding/
https://www.codeproject.com/Questions/5320638/File-compression-and-decompression-and-C
https://stackoverflow.com/questions/58191611/compression-and-decompression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decompress( FILE *input ) {
    int count;
    char c;

    while ( fread(&count, sizeof(int), 1, input) == 1 ) {
        fread(&c, sizeof(char), 1, input);
        for ( int i = 0; i < count; i++ ) {
            printf("%c", c);
        }
    }
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

    decompress(input);
    fclose(input);

    return 0;
}