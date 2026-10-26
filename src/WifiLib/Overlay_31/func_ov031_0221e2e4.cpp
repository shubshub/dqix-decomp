#include <globaldefs.h>

extern "C" void func_ov031_0221e31c(int, unsigned int*);

// USA: func_ov031_0221e2e4
extern "C" THUMB unsigned int func_ov031_0221e2e4(unsigned int arg0, const unsigned char* data, int length, int initialized, unsigned int* table) {
    if (initialized == 0) func_ov031_0221e31c(initialized, table);
    int index = 0;
    if (length > 0) do {
        arg0 = (arg0 >> 8) ^ table[(unsigned char)(data[index] ^ arg0)];
        index++;
    } while (index < length);
    return arg0;
}
