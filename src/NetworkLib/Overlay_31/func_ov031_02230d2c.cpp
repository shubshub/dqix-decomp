#include <globaldefs.h>

struct Struct_ov031_02230d2c { unsigned char pad[4]; unsigned char unknown_4_[4]; };
struct Struct_ov031_02290ca0_24 { unsigned char selected; unsigned char pad[7]; Struct_ov031_02230d2c* work; };
extern Struct_ov031_02290ca0_24 data_ov031_02290ca0;
struct Struct_ov031_02248f5c { unsigned char entries[4]; };
extern Struct_ov031_02248f5c data_ov031_02248f5c;

// USA: func_ov031_02230d2c
extern "C" ARM void func_ov031_02230d2c() {
    Struct_ov031_02248f5c entries = data_ov031_02248f5c;
    unsigned char selected = data_ov031_02290ca0.selected;
    int index = 0;
    unsigned char* entry = entries.entries;
    do {
        if (selected == *entry) {
            data_ov031_02290ca0.work->unknown_4_[index] = 20;
            if (index & 1) {
                data_ov031_02290ca0.work->unknown_4_[index - 1] = 0;
                return;
            } else {
                data_ov031_02290ca0.work->unknown_4_[index + 1] = 0;
                return;
            }
        }
        index++;
        entry++;
    } while (index < 4);
}
