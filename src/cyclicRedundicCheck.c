#include <inttypes.h>

#include <stdio.h>

static uint32_t tableCRC[256];
static uint8_t polynomWidth = 0;

int CRC_CreateCRCTable(uint8_t polynomialWidth) {
    if (polynomWidth == polynomialWidth) {
        return 0;
    }
    polynomWidth = polynomialWidth;
    uint32_t polynomial = 0;
    switch (polynomialWidth) {
        //Theoreticly everything should work but some are better then others
        case (32):  
            polynomial = 0xedb88320;
            break;
        case (16):  
            polynomial = 0x1021;
            break;
        case (5):  
            polynomial = 0x05;
            break;
        default: {
            return -1;
        }
    }
     
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (uint32_t j = 8; j > 0; j--) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            } else {
                crc >>= 1;
            }
        }
        tableCRC[i] = crc;
    }
    return 0;
}

uint32_t CRC_CalculateCRC(uint8_t **data, uint8_t polynomialWidth) {
    uint32_t crc = (1<<polynomialWidth)-1; 
    //Intial crc value 0xF...F

    for (int i = 0; (*data)[i]; i++) {
        uint8_t byte = (uint8_t)((*data)[i]);
        uint32_t index = (crc ^ byte) & 0xff;
        crc = (crc >> 8) ^ tableCRC[index];
    }
    return crc ^ ((1<<polynomialWidth)-1); 
}

int CRC_CheckCRC(uint8_t **data, uint32_t receivedCRC, uint8_t polynomialWidth) {
    uint32_t calculatedCRC = CRC_CalculateCRC(data, polynomialWidth);
    return receivedCRC == calculatedCRC;
}