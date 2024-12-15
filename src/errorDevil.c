#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int errorDevil (uint8_t** data, uint32_t ppm) {
    srand(time(NULL)+1);
    int ret = -1;

    for (uint8_t i = 0; (*data)[i]; i++) {
        ret=i&&!(rand()%(1000000/ppm))?(*data)[i]^=1<<(rand()%8):0;
        // ¯\_(ツ)_/¯ Why not?
        // How does it work? Witchcraft!

        /*   Comment THIS Line to activate the Code bellow
        //Better written like this:
        
        ret = i;
        //Flip the a bit with a ppm parts per millon chance
        if (rand()%(1000000/ppm)) {
            //Chose one of the bits randomly
            uint8_t randomSetBit = 1<<(rand()%8);
            //And the use XOR to flip just that bit
            (*data)[i]^=randomSetBit;
        }
        //*/
    }
    return ret;
}