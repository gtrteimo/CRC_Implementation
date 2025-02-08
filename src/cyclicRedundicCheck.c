#include <inttypes.h>
#include <stdio.h>

static uint32_t tableCRC[256];
static uint8_t polynomWidth = 0;

int CRC_CreateCRCTable(uint8_t polynomialWidth) {
    if (polynomWidth == polynomialWidth) {
        return 0;  // If the polynomial width is unchanged, no need to regenerate the table
    }
    polynomWidth = polynomialWidth;
    uint32_t polynomial = 0;
    
    switch (polynomialWidth) {
        case (32):  
            polynomial = 0xedb88320;  // CRC-32 polynomial
            break;
        case (16):  
            polynomial = 0x1021;  // CRC-16 polynomial
            break;
        case (5):  
            polynomial = 0x05;  // CRC-5 polynomial
            break;
        default:
            return -1;  // Invalid polynomial width
    }

    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (uint32_t j = 8; j > 0; j--) {
            crc = (crc & 1) ? (crc >> 1) ^ polynomial : crc >> 1;  
            // Shift right, XOR with polynomial if LSB is 1 (simulating division)
        }
        tableCRC[i] = crc;
    }
    return 0;
}

uint32_t CRC_CalculateCRC(uint8_t **data, uint8_t polynomialWidth) {
    uint32_t crc = (1 << polynomialWidth) - 1;  // Initial CRC value (all bits set)

    for (int i = 0; (*data)[i]; i++) {
        uint8_t byte = (uint8_t)((*data)[i]);
        uint32_t index = (crc ^ byte) & 0xff;  
        // XOR current byte with CRC and use the lower 8 bits for the lookup table index
        crc = (crc >> 8) ^ tableCRC[index];  
        // Shift CRC right and XOR with the precomputed table value
    }
    return crc ^ ((1 << polynomialWidth) - 1);  
    // Final XOR step to invert the CRC bits, ensuring consistency with common CRC implementations
}

int CRC_CheckCRC(uint8_t **data, uint32_t receivedCRC, uint8_t polynomialWidth) {
    uint32_t calculatedCRC = CRC_CalculateCRC(data, polynomialWidth);
    return receivedCRC == calculatedCRC;  // Return true if the received CRC matches the calculated CRC
}
