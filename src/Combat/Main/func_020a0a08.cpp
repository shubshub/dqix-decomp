#include <globaldefs.h>

struct S_a0af4;
extern "C" short func_020a0af4(struct S_a0af4* p, int key);
struct Struct_020a0a08;
extern "C" void func_020a0a60(struct Struct_020a0a08* map, short i);

struct Struct_02061c04_23 { short* keys; signed char* unknown_4_; short count; };

// USA: func_020a0a08
extern "C" ARM int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount) {
    short* keys = map->keys;
    signed char* var1 = map->unknown_4_;
    short idx = func_020a0af4((struct S_a0af4*)map, key);
    int ret = 0;
    if (idx >= 0) {
        var1[idx] -= amount;
        if (var1[idx] <= 0) {
            keys[idx] = ret - 1;
            var1[idx] = ret;
            func_020a0a60((struct Struct_020a0a08*)map, idx);
        }
        ret = 1;
    }
    return ret;
}
