#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int input(uint8_t** data, uint8_t* crcLen) {
    printf("Which Polynom do you want tu use (5, 16, 32) ?\n");
    int temp;
    scanf(" %u", &temp);
    if (temp != 5 && temp != 16 && temp != 32) {
        *crcLen = 32;
    } else {
        *crcLen = temp & 0xFF;
    }
    uint32_t lenData = 0;
    printf("How many characters do you want to enter (0-1500) ?\n");
    scanf(" %u", &lenData);
    if (lenData > 1500 || lenData < 0) {
        lenData = 46;
    }
    *data = (uint8_t*)calloc((lenData+1), sizeof(uint8_t));
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("Enter the Data (%u characters): ", lenData);
    if (fread(*data, sizeof(uint8_t) , lenData, stdin)) {
        return 0;
    } else {
        fprintf(stderr, "Error while reading from stdin\n");
        return -1;
    }
}

int output(int returnValue) {
    if (returnValue) {
        printf("There where no errors during the transmission!\n");
    } else {
        printf("There where errors during the transmission!\n");
    }
    return 0;
}