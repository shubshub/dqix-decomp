#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_0205d81c;
void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" int func_02050064(void* obj);
extern "C" void* __clear(void* dst, int count);
extern "C" int Font_EncodeText(void* src, void* dst, int flag);
int StringLength_020d2ff0(const char* s);
extern "C" void func_ov023_021e709c(void* ctx, void* arr, int index);
void* GetTableEntry0204a5e4(int a, int b);
void CleanInvalidateCacheRange(void const*, unsigned int);
void CleanCacheRange(void const*, unsigned int);

struct Struct_ov023_021ffa44 {
    int unknown_0_;
    void (*unknown_4_)(void*, void*, unsigned);
};
extern struct Struct_ov023_021ffa44 data_ov023_021ffa44;

struct Struct_ov023_021e8270 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

// USA: func_ov023_021e8270
extern "C" ARM void func_ov023_021e8270(char* arg0) {
    char* var0 = *(char**)(arg0 + 0x600);
    void* var1 = func_0205d81c((struct Struct_0205d81c*)(arg0 + 0x78), 0xd);
    if (var1 == 0) return;

    char* var2 = *(char**)((char*)var1 + 0x8);
    int var3 = *(int*)((char*)var1 + 0xa0);
    unsigned int var4 = *(unsigned int*)((char*)var1 + 0xa4);
    char* var5 = (char*)func_02050064(var1);
    void* var6 = *(void**)((char*)var1 + 0x4);
    memcpy(var2, var5 + var3, var4);

    char* var7 = (char*)GameState::GetInstance() + 0x29c + 0x5400;

    char var8[0x43a];
    __clear(var8, 0x3a);
    __clear(var8 + 0x3a, 0x400);

    int len;
    if (src != 0) {
        len = Font_EncodeText(src, buf, 1);
    } else {
        var9 = func_020d2ff0(var7 + 8);
        memcpy(var8, var7 + 8, var9);
    }

    func_ov023_021e709c(var1, var8, var9 - 1);
    func_ov023_021e709c(var1, var8, var9);
    func_ov023_021e709c(var1, var8, var9 + 1);

    if (!(data_ov023_021ffa44.unknown_0_ & 1)) {
        struct Struct_ov023_021e8270* var10 = (struct Struct_ov023_021e8270*)((char*)var6 + 0x1c);
        data_ov023_021ffa44.unknown_4_ = (void(*)(void*, void*, unsigned))func_0204a5e4(var10->unknown_0_0_, var10->unknown_0_4_);
        data_ov023_021ffa44.unknown_0_ |= 1;
    }
    CleanInvalidateCacheRange(var2, var4);
    data_ov023_021ffa44.unknown_4_(var2, (void*)var3, var4);
    CleanCacheRange(var2, var4);
}
