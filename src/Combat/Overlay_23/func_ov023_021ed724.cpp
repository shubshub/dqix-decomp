#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" int func_020ac460(void* dst);
extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020ac3c8(unsigned int* dst, short* indices, int count);
extern "C" int func_020ac494(void* src);

struct Struct_020a03c4 {
    char pad[0x10];
    unsigned int val : 9;
    unsigned int hi : 23;
};
extern "C" void func_020a03c4(struct Struct_020a03c4* p, unsigned int amount);

// USA: func_ov023_021ed724
extern "C" ARM int func_ov023_021ed724(void* obj, short* src, int count) {
    if (obj == 0) return 0;
    if (src == 0) return 0;
    if (count == 0) return 0;

    short var0[50];
    char block[0xb0];
    unsigned int dst[15];

    int flag = 0;
    func_020ac460(dst);
    memset(var0, 0, 0x64);
    for (int i = 0; i < count; i++) {
        var0[i] = src[i];
    }
    func_020ac3c8(dst, var0, count);
    func_020ac4c0(block);
    if (((struct Struct_020a03c4*)block)->val == 0) {
        flag |= 1;
    }
    func_020a03c4((struct Struct_020a03c4*)block, count);
    func_020ac494(block);
    return flag;
}
