#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44; // Size of .wav header

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    // Read scaling factor
    float factor = atof(argv[3]);

    // Buffer for header
    uint8_t header[HEADER_SIZE];

    // Read header from input file
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);

    // Write header to output file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Process audio samples (assuming 16-bit PCM format)
    int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        // Adjust sample based on factor
        sample = sample * factor;

        // Write adjusted sample to output file
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}