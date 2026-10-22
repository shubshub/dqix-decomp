#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define ENTRY_TEXT_02093b90 0xc
#define TEXT_LEN_02093b90 0x30
#define DRAW_ARGS_02093b90 10, 15
#else
#define ENTRY_TEXT_02093b90 0x30
#define TEXT_LEN_02093b90 128
#define DRAW_ARGS_02093b90 15, 0
#endif

struct Struct_02012de8;
struct AllocatorUnion;
struct SePlayer;
struct TextEntry02093b90 {
    char text[ENTRY_TEXT_02093b90];
    short code;
    signed char index;
    unsigned char started;
};
struct Struct_02093b90_2 {
    Struct_02093b90 unknown_0_[16];
    int unknown_340_;
    float unknown_344_;
    unsigned char unknown_348_[TEXT_LEN_02093b90];
    unsigned char unknown_3c8_0_:7, unknown_3c8_7_:1;
    unsigned char unknown_3c9_0_:1, unknown_3c9_1_:7;
    unsigned char unknown_3ca_;
    signed char unknown_3cb_;
    unsigned char unknown_3cc_, unknown_3cd_;
};
struct Struct_02093b90_3 {
    unsigned int unknown_0_;
    unsigned short unknown_4_, unknown_6_, unknown_8_, unknown_a_;
};
struct Struct_020200c0_4 { void* unknown_0_; Struct_02093b90_3* unknown_4_; unsigned char unknown_8_; };
extern AllocatorUnion data_02114e20;
extern SePlayer g_sePlayer;
extern "C" char* func_0203bd08();
extern "C" unsigned char func_020938cc();
extern "C" void func_0203be58(char*, int, int);
extern "C" Struct_02012de8* func_020d6c00();
extern "C" int func_02046708(Struct_02012de8*, unsigned int);
extern "C" void func_020941b0(Struct_02093b90_2*);
extern "C" int func_020941f8(Struct_02093b90_2*);
extern "C" int func_020943dc(Struct_02093b90_2*);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" int func_0209378c(int);
extern "C" int func_020937f0(int);
extern "C" void func_0205b20c(Struct_020200c0_4*);
extern "C" void func_0205b220(void*, int);
extern "C" void func_0205b228(void*, int, unsigned char);
extern "C" void func_0205b234(void*, int, int, void*, int, int);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjVRAM(const void*, unsigned int, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_020945ac(Obj020941b0*);

static inline unsigned char* inline_02093b90(Struct_02093b90_2* arg0) { return arg0->unknown_348_; }

// USA: func_02093b90
extern "C" ARM void func_02093b90(Struct_02093b90_2* arg0, int arg1) {
    char* var0 = func_0203bd08();
    func_0203be58(var0, func_020938cc(), 1);
    Struct_02012de8* var1 = func_020d6c00();
    if (func_02046708(var1, 0x20)) {
        func_020941b0(arg0);
        return;
    }
    if (!arg0->unknown_3c9_0_) return;
    unsigned char var2 = func_020938cc();
    if (arg0->unknown_3c8_7_ != var2) {
        func_020941b0(arg0);
        arg0->unknown_3c8_7_ = var2;
        return;
    }
    if (IsBrightnessOutsideValidRange(GetGameResources(), true)) {
        func_020941b0(arg0);
        return;
    }
    if (func_020941f8(arg0)) return;
    arg0->unknown_344_ += 0.2f;
    if (6.28f <= arg0->unknown_344_) arg0->unknown_344_ -= 6.28f;
    if (arg0->unknown_3cb_ <= 0) return;
    if (func_020943dc(arg0)) return;
    if (func_02046708(var1, 0x8000)) return;
    if (arg0->unknown_348_[0]) {
        void* var3 = func_02012d88(&data_02114e20, 0x800);
        if (!var3) return;
        int var4 = arg0->unknown_3c8_7_;
        if (var3) {
          unsigned char* var5 = inline_02093b90(arg0);
          if (var5) {
            func_0209378c(var4);
            int var6 = func_020937f0(var4);
            if (var6) {
                memset(var3, 0x11111111, 0x800);
                Struct_02093b90_3 var7[8];
                unsigned char var8;
                unsigned char var9;
                unsigned int var10;
                var10=0;
                var9=0;
                var8=0;
                for (;var8<8; ++var8) {
                    int var11 = var8;
                    Struct_02093b90_3* var12 = &var7[var11];
                    var7[var8].unknown_0_=0;

                    var12->unknown_4_=0;
                    var12->unknown_6_=0;
                    var12->unknown_8_=0;
                    var12->unknown_a_=0;
                    var7[var8].unknown_0_=var10;
                    var12->unknown_4_=var9;
                    var12->unknown_6_=0;
                    var12->unknown_8_=32;
                    var9+=32;
                    var12->unknown_a_=16;
                    var10+=256;
                }
                Struct_020200c0_4 var13;
                func_0205b20c(&var13);
                func_0205b220(&var13, (int)var3);
                func_0205b228(&var13, (int)var7, 8);
                func_0205b234(&var13, 16, 3, var5, DRAW_ARGS_02093b90);
                CleanInvalidateCacheRange(var3, 0x800);
                if (var4==0) LoadToMainObjVRAM(var3, var6-0x800, 0x800);
                else LoadToSubObjVRAM(var3, var6-0x800, 0x800);
            }
          }
        }
        TailForward02012da4(&data_02114e20,pixels);
        memset(self->text,0,TEXT_LEN_02093b90);
        self->flags |=4;
        if (!self->entries[0].started) {
            SePlayer_Play(&g_sePlayer,29,0);
            self->entries[0].started=1;
        }
        return;
    }
    arg0->unknown_3ca_ += arg1;
    unsigned int var14;
    switch ((unsigned char)arg0->unknown_3cb_) {
    case 0: case 1: var14=180; break;
    case 2: var14=120; break;
    default: var14=60; break;
    }
    if (arg0->unknown_3cb_>0 && arg0->unknown_0_[0].unknown_30_==0x4e23) var14=150;
    if (var14>=arg0->unknown_3ca_) return;
    void* var15 = func_02012d88(&data_02114e20,0x800);
    if (var15) {
        int var16=arg0->unknown_3c8_7_;
        if (var15) {
            int var17=func_020937f0(var16);
            if (var17) {
                memset(var15,0x11111111,0x800);
                CleanInvalidateCacheRange(var15,0x800);
                if (var16==0) LoadToMainObjVRAM(var15,var17-0x800,0x800);
                else LoadToSubObjVRAM(var15,var17-0x800,0x800);
            }
        }
        func_02012da4(&data_02114e20,var15);
    }
    func_020945ac(arg0);
    arg0->unknown_3ca_=0;
}
