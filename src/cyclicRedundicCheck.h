#pragma once

#include <inttypes.h>

int CRC_CreateCRCTable(uint8_t polynomialWidth);

uint32_t CRC_CalculateCRC(uint8_t **data, uint8_t polynomialWidth);

int CRC_CheckCRC(uint8_t **data, uint32_t receivedCRC, uint8_t polynomialWidth);