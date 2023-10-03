#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    char *input_name = argv[1];
    char *output_name = argv[2];

    if (input_name == NULL || output_name == NULL || argc != 3)
    {
        printf("Invalid usage.\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(input_name, "r");
    if (input == NULL)
    {
        printf("Could not open the file\n");
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(wh) != 0)
    {
        printf("Not a WAV format\n");
        return 3;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(output_name, "w");
    if (output == NULL)
    {
        printf("Could not open the file");
        return 4;
    }

    // Write header to file
    // TODO #6
    fwrite(&wh, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(wh);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];

    fseek(input, 0, SEEK_END);
    long infile_size = ftell(input);
    printf("file_size: %li\n", infile_size);

    for (long i = infile_size; i > sizeof(wh); i -= block_size)
    {
        fseek(input, i, SEEK_SET);
        fread(buffer, 1, block_size, input);
        fwrite(buffer, 1, block_size, output);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 87 && header.format[1] == 65 && header.format[2] == 86 && header.format[3] == 69)
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample * 8;
    return block_size;
}