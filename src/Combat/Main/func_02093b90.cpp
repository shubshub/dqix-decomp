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
struct S_b20c { void* buffer; Tile02093b90* tiles; unsigned char count; };
extern AllocatorUnion g_mainAllocator;
extern SePlayer g_sePlayer;
extern "C" char* func_0203bd08();
unsigned char IsPowCnt1Bit15Clear020938cc();
void SetByteAt0xc0203be58(char*, int, int);
FlagWord02046708* GlobalFlags_GetInstance();
int TestFlags02046708(FlagWord02046708*, unsigned int);
void ReleaseHandleAndClearFlags(Obj020941b0*);
extern "C" int func_020941f8(Obj020941b0*);
extern "C" int func_020943dc(Obj020941b0*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
int GetDisplayModeCode0209378c(int);
extern "C" int func_020937f0(int);
extern "C" void func_0205b20c(Struct_020200c0_4*);
extern "C" void func_0205b220(void*, int);
extern "C" void func_0205b228(void*, int, unsigned char);
extern "C" void func_0205b234(void*, int, int, void*, int, int);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjVRAM(const void*, unsigned int, unsigned int);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_020945ac(Obj020941b0*);

static inline unsigned char* inline_02093b90(Struct_02093b90_2* arg0) { return arg0->unknown_348_; }

// USA: func_02093b90
extern "C" ARM void func_02093b90(Obj020941b0* self, int ticks) {
    char* context = func_0203bd08();
    SetByteAt0xc0203be58(context, IsPowCnt1Bit15Clear020938cc(), 1);
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    if (TestFlags02046708(flags, 0x20)) {
        ReleaseHandleAndClearFlags(self);
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
    if (func_020941f8(self)) return;
    self->phase += 0.2f;
    if (6.28f <= self->phase) self->phase -= 6.28f;
    if (self->count <= 0) return;
    if (func_020943dc(self)) return;
    if (TestFlags02046708(flags, 0x8000)) return;
    if (self->text[0]) {
        void* pixels = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800);
        if (!pixels) return;
        int display = self->display;
        if (pixels) {
          unsigned char* text = GetText02093b90(self);
          if (text) {
            GetDisplayModeCode0209378c(display);
            int destination = func_020937f0(display);
            if (destination) {
                memset(pixels, 0x11111111, 0x800);
                Tile02093b90 tiles[8];
                unsigned char index;
                unsigned char x;
                unsigned int offset;
                offset=0;
                x=0;
                index=0;
                for (;index<8; ++index) {
                    int tileIndex = index;
                    Tile02093b90* tile = &tiles[tileIndex];
                    tiles[index].offset=0;

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
        AllocatorUnion_Free(&g_mainAllocator,pixels);
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
    if (self->count>0 && self->entries[0].code==0x4e23) limit=150;
    if (limit>=self->elapsed) return;
    void* pixels = AllocatorUnion_AllocateRounded(&g_mainAllocator,0x800);
    if (pixels) {
        int display=self->display;
        if (pixels) {
            int destination=func_020937f0(display);
            if (destination) {
                memset(pixels,0x11111111,0x800);
                CleanInvalidateCacheRange(pixels,0x800);
                if (display==0) LoadToMainObjVRAM(pixels,destination-0x800,0x800);
                else LoadToSubObjVRAM(pixels,destination-0x800,0x800);
            }
        }
        AllocatorUnion_Free(&g_mainAllocator,pixels);
    }
    func_020945ac(arg0);
    arg0->unknown_3ca_=0;
}
