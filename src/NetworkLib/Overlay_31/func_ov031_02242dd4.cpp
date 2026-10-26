#include <globaldefs.h>

struct Struct_ov031_0224954c {
    unsigned int values[9];
};

extern Struct_ov031_0224954c data_ov031_0224954c;

// USA: func_ov031_02242dd4
extern "C" ARM int func_ov031_02242dd4(char* output, unsigned int value) {
    Struct_ov031_0224954c var0 = data_ov031_0224954c;
    unsigned int* var1 = var0.values;
    int index;
    int count = 0;
    index = 0;
    bool started = false;
    do {
        unsigned int var5 = var1[index];
        if (value >= var5) {
            unsigned int digit = value / var5;
            unsigned int var7 = digit * var5;
            started = true;
            if (output != 0) {
                output[count] = digit + '0';
            }
            value -= var7;
            count++;
        } else if (started != 0) {
            if (output != 0) {
                output[count] = '0';
            }
            count++;
        }
        index++;
    } while (index < 9);
    if (output != 0) {
        output[count] = value + '0';
    }
    return count + 1;
}
