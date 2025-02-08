#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int input(uint8_t** data, uint8_t* crcLen) {
    // Prompt user to select the CRC polynomial (5, 16, or 32)
    printf("Which Polynom do you want to use (5, 16, 32) ?\n");
    int temp;
    scanf(" %u", &temp);
    
    // Validate and set the polynomial length (default to 32 if invalid input)
    if (temp != 5 && temp != 16 && temp != 32) {
        *crcLen = 32;
    } else {
        *crcLen = temp & 0xFF;  // Store the selected polynomial length
    }

    uint32_t lenData = 0;
    // Prompt user to input the number of characters they wish to enter (range 0-1500)
    printf("How many characters do you want to enter (0-1500) ?\n");
    scanf(" %u", &lenData);
    
    // Validate input range, default to 46 if invalid
    if (lenData > 1500 || lenData < 0) {
        lenData = 46;
    }

    // Allocate memory to store the entered data (+1 for null terminator)
    *data = (uint8_t*)calloc((lenData+1), sizeof(uint8_t));

    int ch = 0;
    // Clear the input buffer before reading the data
    while ((ch = getchar()) != '\n' && ch != EOF);

    // Prompt user to enter the data and read it into the allocated memory
    printf("Enter the Data (%u characters): ", lenData);
    if (fread(*data, sizeof(uint8_t), lenData, stdin)) {
        return 0;  // Successfully read the data
    } else {
        // Error occurred while reading input
        fprintf(stderr, "Error while reading from stdin\n");
        return -1;  // Return error code
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
