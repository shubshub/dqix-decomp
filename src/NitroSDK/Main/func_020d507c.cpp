#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int, int);
struct Struct_020d507c;
extern "C" int func_020d5158(struct Struct_020d507c* o);
extern "C" void func_020d404c(int index, int value);
void CleanCacheRange(const void* addr, unsigned int size);

struct Struct_0202db64 {
    int field0;
    unsigned short field4;
    unsigned char pad1[0x14 - 0x6];
    unsigned short field14;
    unsigned char pad2[0x34 - 0x16];
    unsigned short field34;
    unsigned short unknown_36_;
};


// USA: func_020d507c
extern "C" ARM int func_020d507c(int a, struct Struct_0202db64* b) {
    int result = func_020d424c(1, 2);
    if (result != 0) {
        return result;
    }
    if (b == NULL) {
        return 6;
    }
    if (b->field4 != 0 && b->field0 == 0) {
        return 6;
    }

    int var1 = (b->field14 != 0) ? 0x2a : 0;
    if (b->field34 + var1 > 0x200 || b->unknown_36_ + ((b->field14 != 0) ? 6 : 0) > 0x200) {
        return 6;
    }

    func_020d5158((struct Struct_020d507c*)b);
    func_020d404c(7, a);
    CleanCacheRange(b, 0x40);
    if (b->field4 != 0) {
        CleanCacheRange((void*)b->field0, b->field4);
    }
    result = func_020d40bc(7, 1, (int)b);
    if (result == 0) {
        result = 2;
    }
    return result;
}
