#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct EntryManager020e2490;
void InitEntryManager020e2490(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);
struct List0204af64;
void Background_Init(struct List0204af64* obj);
extern "C" void func_0204c684(void*);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198*);

struct Struct_ov003_021544ec {
    char unknown_0_[4];
    void* unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
    char unknown_10_[0x59 - 0x10];
    signed char unknown_59_;
};
extern "C" void func_ov003_0215376c(struct Struct_ov003_021544ec* arg0);
extern "C" void func_ov003_021536e0(struct Struct_ov003_021544ec* arg0, SafeAllocator* arg1);

struct Struct_ov003_0217f320 {
    unsigned int unknown_0_[8];
};
extern Struct_ov003_0217f320 data_ov003_0217f320;

struct Struct_ov003_021544ec_2 {
    SafeAllocator* unknown_0_;
    struct Struct_ov003_021544ec* unknown_4_;
    char unknown_8_[4];
    void* unknown_c_;
    struct Struct_02020cb8* unknown_10_;
    char* unknown_14_;
    Struct_0207f7f0* unknown_18_;
    struct Struct_020e2490* unknown_1c_;
    int* unknown_20_;
    struct Struct_02043368_2* unknown_24_;
    void* unknown_28_;
    char unknown_2c_[0x90 - 0x2c];
    char unknown_90_[0xfc - 0x90];
    char unknown_fc_[0x114 - 0xfc];
    char unknown_114_[1];
};

#if defined(jpn)
enum { Enum_ov003_021544ec_128 = 0x68, Enum_ov003_021544ec_4 = 3 };
#else
enum { Enum_ov003_021544ec_128 = 0x80, Enum_ov003_021544ec_4 = 4 };
#endif

// USA: func_ov003_021544ec
extern "C" ARM void func_ov003_021544ec(struct Struct_ov003_021544ec_2* arg0, SafeAllocator* arg1) {
    if (arg1 != 0) {
        arg0->unknown_0_ = (SafeAllocator*)arg1->Allocate(0xa0);
        arg0->unknown_4_ = (struct Struct_ov003_021544ec*)arg1->Allocate(0x60);
        arg0->unknown_c_ = arg1->Allocate(0x4c00);
        arg0->unknown_10_ = (struct Struct_02020cb8*)arg1->Allocate(0x40);
        arg0->unknown_14_ = (char*)arg1->Allocate(0x2a0);
        arg0->unknown_18_ = static_cast<Struct_0207f7f0*>(arg1->Allocate(Enum_ov003_021544ec_128));
        arg0->unknown_20_ = (int*)arg1->Allocate(0x30);
        arg0->unknown_24_ = (struct Struct_02043368_2*)arg1->Allocate(0x190);
        arg0->unknown_28_ = arg1->Allocate(8);
        arg0->unknown_1c_ = (struct Struct_020e2490*)arg1->Allocate(0x24);
        func_020e2490(arg0->unknown_1c_, 0, 1, arg0->unknown_28_, arg1, Enum_ov003_021544ec_4, 0x40);

        Struct_ov003_0217f320 var0 = data_ov003_0217f320;
        for (unsigned char var1 = 0; var1 < 8; var1++) {
            SafeAllocator* var2 = arg0->unknown_0_;
            unsigned int var3 = var0.unknown_0_[var1];
            var2[var1].ResetAllocatorPointer();
            var2[var1].CreateTypeA(arg1->Allocate(var3), var3);
            var2[var1].Reset();
        }
        for (unsigned char i = 0; i < 2; i++) {
            Background_Init((struct List0204af64*)((char*)obj->lists + i * 0x20));
        }
        for (unsigned char var5 = 0; var5 < 3; var5++) {
            func_0204c684(arg0->unknown_14_ + var5 * 0xe0);
        }
        func_0207f84c(arg0->unknown_18_);
        for (unsigned char var6 = 0; var6 < 12; var6++) {
            arg0->unknown_20_[var6] = 0;
        }
        for (unsigned char i = 0; i < 10; i++) {
            Sprite_Init((struct Struct0205a198*)((char*)obj->buf24 + i * 0x28));
        }
        GameState::GetInstance();
        struct Struct_ov003_021544ec* var8 = arg0->unknown_4_;
        func_ov003_0215376c(var8);
        func_ov003_021536e0(var8, arg1);
        var8->unknown_8_ = arg0->unknown_90_;
        var8->unknown_4_ = arg0->unknown_fc_;
        var8->unknown_c_ = arg0->unknown_114_;
        var8->unknown_59_ = -1;
    }
}
