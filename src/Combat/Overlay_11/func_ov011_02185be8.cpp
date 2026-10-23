#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov011_02184c30 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Struct_ov011_02185be8_2 {
    Struct_ov011_02184c30 unknown_0_;
    Struct_ov011_02184c30 unknown_8_;
    int unknown_10_;
    int unknown_14_;
    Struct_ov011_02184c30 unknown_18_;
};

extern "C" int func_ov011_02184c30(struct Struct_ov011_02184c30* arg0);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* arg0, int arg1);
extern "C" ARM void* func_ov011_021849c8(void* arg0);
extern "C" ARM void* func_ov011_02185ce0(void* arg0);
extern "C" ARM void func_0205a494(void* arg0);
#if defined(jpn)
// JPN: InitObjWithVTable_02185ce0 is inlined, the object is 0x84 bytes and func_ov023_021fa760 takes 6 arguments.
void SpriteContext_Init(char* obj);
extern int data_ov023_021fddfc;
extern "C" ARM int func_ov023_021fa760(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5);
#else
extern "C" ARM int func_ov023_021fa760(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#endif

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* arg0, struct Struct_ov004_0215c30c_2* arg1);

#if defined(jpn)
struct Struct_ov011_02185be8 {
    void* unknown_0_;
    char unknown_4_[0x20 - 4];
    char unknown_24_[0x84 - 0x20];
};
#else
struct Struct_ov011_02185be8 {
    void* unknown_0_;
    char unknown_4_[0x24 - 4];
    char unknown_24_[0x88 - 0x24];
};
#endif

// USA: func_ov011_02185be8
extern "C" ARM int func_ov011_02185be8(struct Struct_ov011_02185be8_2* arg0) {
    int var0 = func_ov011_02184c30(&arg0->unknown_0_);
    int var1 = func_ov011_02184c30(&arg0->unknown_8_);

    int var2;
    if (arg0->unknown_10_ == 2) var2 = arg0->unknown_14_;
    else var2 = 0;
    if (var2 == 0) return 0;

    int var3 = func_ov011_02184c30(&arg0->unknown_18_);

    void* var4 = func_ov017_021b2164();
    void* var5 = func_ov011_021845f8(var4, var1);
    if (var5 == 0) return 0;

    ((SafeAllocator*)((char*)var5 + 4))->GetSizeWithLargestBlockRemoved();
    void* var6 = ((SafeAllocator*)((char*)var5 + 4))->Allocate(sizeof(Struct_ov011_02185be8));
    if (var6 == 0) return 0;

    struct Struct_ov011_02185be8 var7;
#if defined(jpn)
    local.vtable = &data_ov023_021fddfc;
    SpriteContext_Init(local.sub);
#else
    func_ov011_02185ce0(&var7);
#endif
    memcpy(var6, &var7, sizeof(Struct_ov011_02185be8));

#if defined(jpn)
    if (func_ov023_021fa760(var6, var4, var0, var1, var2, var3) == 0) {
#else
    if (func_ov023_021fa760(var6, var4, var0, var1, 0, var2, var3) == 0) {
#endif
        func_0205a494(var7.unknown_24_);
        return 0;
    }

    void* var8 = func_ov011_021849c8(var4);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)var8, (struct Struct_ov004_0215c30c_2*)var6);
    func_0205a494(var7.unknown_24_);
    return 1;
}
