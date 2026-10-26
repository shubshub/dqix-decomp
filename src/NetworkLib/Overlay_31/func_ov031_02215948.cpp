#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02249ad4_2 {
    const signed char* field0;
    const signed char* first;
    const signed char* field8;
    const signed char* second;
};

extern Struct_ov031_02249ad4_2 data_ov031_02249ad4;
extern const unsigned char data_ov031_0224609c[13];
extern const unsigned char data_ov031_022460ac[16];

// USA: func_ov031_02215948
extern "C" ARM void func_ov031_02215948(const unsigned char* source, unsigned char* output) {
    {
        int index = 0;
        do {
            output[index] = source[index] ^ (source + index % 7)[13];
            index++;
        } while (index < 13);
    }
    {
        int index = 0;
        do {
            unsigned char* destination = output + index;
            const unsigned char* input = source + index;
            destination[3] = destination[3] ^ input[13];
            index++;
        } while (index < 7);
    }
    {
        int index = 0;
        do {
            output[index] ^= data_ov031_02249ad4.first[index];
            index++;
        } while (index < 13);
    }
    unsigned char buffer[13];
    VectorizedInvertedMemcpy(output, buffer, 13);
    {
        unsigned char* input = buffer;
        const unsigned char* var7 = data_ov031_0224609c;
        int index = 0;
        do {
            unsigned char value = *input;
            unsigned char position = *var7;
            output[position] = value;
            var7++;
            input++;
            index++;
        } while (index < 13);
    }
    {
        int index = 0;
        do {
            output[index] ^= data_ov031_02249ad4.second[index];
            index++;
        } while (index < 13);
    }
    {
        int index = 0;
        do {
            int high = (output[index] >> 4) & 15;
            int low = output[index] & 15;
            output[index] = (data_ov031_022460ac[high] << 4) | data_ov031_022460ac[low];
            index++;
        } while (index < 13);
    }
    {
        int index = 0;
        do {
            unsigned char* column = output + index;
            output[index] ^= column[6];
            column[3] ^= column[9];
            column[6] ^= column[3];
            column[9] ^= output[index];
            output[12] ^= output[index];
            index++;
        } while (index < 3);
    }
}
