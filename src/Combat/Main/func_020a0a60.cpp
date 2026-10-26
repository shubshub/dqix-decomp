#include <globaldefs.h>

struct Struct_020a0a08 {
    short* keys;
    signed char* unknown_4_;
    short count;
};

// USA: func_020a0a60
extern "C" ARM void func_020a0a60(struct Struct_020a0a08* map, short i) {
    short* keys = map->keys;
    signed char* var1 = map->unknown_4_;
    int count = map->count;
    short j;
    for (; i < count - 1; i++) {
        if (var1[i] == 0) {
            for (j = i + 1; j < count; j++) {
                if (var1[j] != 0) {
                    keys[i] = keys[j];
                    var1[i] = var1[j];
                    keys[j] = -1;
                    var1[j] = 0;
                    break;
                }
            }
        }
    }
}
