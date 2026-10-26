#include <globaldefs.h>

// USA: func_ov031_0221e3d0
extern "C" THUMB void func_ov031_0221e3d0(int seed, signed char* destination, int length, const signed char* key, int arg4) {
    int count = length / 2;
    int var1 = seed % arg4;
    int index = 0;
    if (index < count) {
        do {
            destination[index] = index;
            destination[index] ^= key[var1++];
            if (var1 >= arg4) var1 = 0;
            ++index;
        } while (index < count);
    }
}
