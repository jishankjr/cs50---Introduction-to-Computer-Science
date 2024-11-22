#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s card.raw\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // Initialize variables
    BYTE buffer[BLOCK_SIZE];
    FILE *outptr = NULL;
    char filename[8];
    int jpeg_count = 0;
    int found_jpeg = 0;

    // Read until end of card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // Check if it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if one is open
            if (found_jpeg)
            {
                fclose(outptr);
            }
            else
            {
                found_jpeg = 1;
            }

            // Create new JPEG file
            sprintf(filename, "%03d.jpg", jpeg_count);
            outptr = fopen(filename, "wb");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }

            // Write current block to JPEG file
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
            jpeg_count++;
        }
        else
        {
            // Continue writing to current JPEG file
            if (found_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
            }
        }
    }

    // Close files
    fclose(inptr);
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    return 0;
}