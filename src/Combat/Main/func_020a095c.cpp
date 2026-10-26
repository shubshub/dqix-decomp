#include <globaldefs.h>

struct S_a0af4;
extern "C" short func_020a0af4(struct S_a0af4* p, int key);

struct KeyMap020a095c { short* keys; signed char* unknown_4_; short count; };

// USA: func_020a095c
extern "C" ARM int func_020a095c(struct KeyMap020a095c* map, int key, int amount) {
    short* keys = map->keys;
    signed char* var1 = map->unknown_4_;
    short count = map->count;
    short idx;
    int ret;
    if (key < 0) {
        return 0;
    }
    if (amount <= 0) {
        return 0;
    }
    ret = 0;
    idx = func_020a0af4((struct S_a0af4*)map, key);
    if (idx >= 0) {
        ret = 1;
        if (var1[idx] < 99) {
            signed char var5 = 99 - var1[idx];
            if (amount > var5) amount = var5;
            var1[idx] += amount;
        }
    } else {
        short i;
        for (i = 0; i < count; i++) {
            if (keys[i] < 0) {
                keys[i] = key;
                var1[i] = amount;
                ret = 1;
                break;
            }
        }
    }
    return ret;
}
