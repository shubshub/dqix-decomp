#include <globaldefs.h>

struct KeyMap020a0b3c {
    short* keys;
    signed char* values;
    short count;
};

// USA: func_020a0b3c
extern "C" ARM signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key) {
    short* keys = map->keys;
    signed char* values = map->values;
    int count = map->count;
    short i;
    if (key < 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        if (key == keys[i]) {
            return values[i];
        }
    }
    return 0;
}
