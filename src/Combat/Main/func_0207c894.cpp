#include <globaldefs.h>

struct Struct_0207c484 {
    char pad0[0xbd0];
    short *unknown_bd0_[8];
    signed char *unknown_bf0_[8];
    short counts[8];
    unsigned char keys[8];
};
extern "C" int func_0207c484(Struct_0207c484 *, int, int, int);
extern const short data_020e8a04[8];

// USA: func_0207c894
extern "C" ARM int func_0207c894(void *map, int value, int key) {
    Struct_0207c484 *list = static_cast<Struct_0207c484 *>(map);
    if (value < 0) {
        return 0;
    }
    int var1 = -1;
    for (int i = 0; i < 8; i++) {
        if (key == list->keys[i]) {
            var1 = i;
            break;
        }
    }
    if (var1 < 0) {
        for (int i = 0; i < 8; i++) {
            int capacity  = data_020e8a04[i];
            short *values = list->unknown_bd0_[i];
            for (int j = 0; j < capacity; j++) {
                if (value == values[j]) {
                    signed char *counts = list->unknown_bf0_[i];
                    if (counts[j] != 0) {
                        counts[j]--;
                    }
                    if (counts[j] == 0) {
                        values[j] = -1;
                    }
                    return 1;
                }
            }
        }
    } else {
        return func_0207c484(list, value, 1, var1) != 0;
    }
    return 0;
}
