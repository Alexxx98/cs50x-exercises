#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    char *filename = argv[1];

    //Checks if forensic file exists and it is not empty
    if (filename == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }

    FILE *raw_file = fopen(filename, "r");
    FILE *img = NULL;

    BYTE buffer[512];

    char *img_name = malloc(8);

    int counter = 0;

    while (fread(buffer, 1, sizeof(buffer), raw_file) == sizeof(buffer))
    {

        // if jpg found (the formula symbolize jpg header)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // if not first jpg
            if (counter > 0)
            {
                fclose(img);
            }

            // Change file name respectively to counter value
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");

            counter++;
        }

        // if chunk of 512 bytes has already jpg content and does not begin with jpg header
        if (img != NULL)
        {
            fwrite(buffer, 1, sizeof(buffer), img);
        }

    }

    // free memory section
    free(img_name);
    fclose(img);
    fclose(raw_file);

    return 0;
}