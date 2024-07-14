/*
Sources:
https://www.geeksforgeeks.org/text-file-compression-and-decompression-using-huffman-coding/
https://www.codeproject.com/Questions/5320638/File-compression-and-decompression-and-C
https://stackoverflow.com/questions/58191611/compression-and-decompression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress( FILE *input ) {
    int count;
    char curr, prev;

    if ( fread(&prev, sizeof(char), 1, input) != 1 ) {
        return; // Empty file
    }

    count = 1; // First char
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

    // Wrong amount of args
    if ( argc != 2 ) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    // rb for all kinds of files
    FILE *input = fopen(argv[1], "rb");

    if ( !input ) {
        perror("Failed to open input file");
        return 1;
    }

    compress(input);
    fclose(input);

    return 0;
}