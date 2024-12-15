#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "cyclicRedundicCheck.h"
#include "errorDevil.h"
#include "in-output.h"

#define ppm 50000
// 5% chance of flipping a bit in each byte

int main () {
    uint8_t** data = (uint8_t**)calloc(1, sizeof(uint8_t*));
    uint8_t crcLen = 32;

    char in;
    do {
        input(data, &crcLen);

        if (CRC_CreateCRCTable(crcLen) == -1) {
            fprintf(stderr, "Invalid Crc-Polynom");
            exit(-1);
        }
        uint32_t checksum = CRC_CalculateCRC(data, crcLen);

        printf("Checksum: 0x%08x\n", checksum);

        errorDevil(data, ppm);

        output(CRC_CheckCRC(data, checksum, crcLen));

        free(*data);

        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        printf("Input again (y/N) ?: ");
        scanf(" %c", &in);
    } while (in == 'Y' || in == 'y');
    free(data);
    return 0;
}