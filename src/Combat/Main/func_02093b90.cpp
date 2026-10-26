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

struct FlagWord02046708;
struct AllocatorUnion;
struct SePlayer;
struct Struct_02093b90 {
    char text[ENTRY_TEXT_02093b90];
    short code;
    signed char index;
    unsigned char started;
};
struct Struct_02093b90_2 {
    Struct_02093b90 entries[16];
    int handle;
    float phase;
    unsigned char text[TEXT_LEN_02093b90];
    unsigned char state:7, display:1;
    unsigned char enabled:1, reserved:7;
    unsigned char elapsed;
    signed char count;
    unsigned char unknown, flags;
};
struct Struct_02093b90_3 {
    unsigned int offset;
    unsigned short x, y, width, height;
};
struct S_b20c { void* buffer; Struct_02093b90_3* tiles; unsigned char count; };
extern AllocatorUnion g_mainAllocator;
extern SePlayer g_sePlayer;
extern "C" char* OamManager_GetInstance();
extern "C" unsigned char func_020938cc();
extern "C" void OamManager_SetUploadEnabled(char*, int, int);
extern "C" FlagWord02046708* GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(FlagWord02046708*, unsigned int);
extern "C" void func_020941b0(Struct_02093b90_2*);
extern "C" int func_020941f8(Struct_02093b90_2*);
extern "C" int func_020943dc(Struct_02093b90_2*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" int func_0209378c(int);
extern "C" int func_020937f0(int);
extern "C" void GlyphDestination_Clear(S_b20c*);
extern "C" void GlyphDestination_SetPixels(void*, int);
extern "C" void GlyphDestination_SetRects(void*, int, unsigned char);
extern "C" void GlyphDestination_DrawText(void*, int, int, void*, int, int);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjVRAM(const void*, unsigned int, unsigned int);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_020945ac(Struct_02093b90_2*);

static inline unsigned char* inline_02093b90(Struct_02093b90_2* obj) { return obj->text; }

// USA: func_02093b90
extern "C" ARM void func_02093b90(Struct_02093b90_2* self, int ticks) {
    char* context = OamManager_GetInstance();
    OamManager_SetUploadEnabled(context, func_020938cc(), 1);
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    if (FlagWord_TestBits(flags, 0x20)) {
        func_020941b0(self);
        return;
    }
    if (!self->enabled) return;
    unsigned char var2 = func_020938cc();
    if (self->display != var2) {
        func_020941b0(self);
        self->display = var2;
        return;
    }
    if (IsScreenFullyFaded(GetGameResources(), true)) {
        func_020941b0(self);
        return;
    }
    if (func_020941f8(self)) return;
    self->phase += 0.2f;
    if (6.28f <= self->phase) self->phase -= 6.28f;
    if (self->count <= 0) return;
    if (func_020943dc(self)) return;
    if (FlagWord_TestBits(flags, 0x8000)) return;
    if (self->text[0]) {
        void* pixels = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800);
        if (!pixels) return;
        int display = self->display;
        if (pixels) {
          unsigned char* text = inline_02093b90(self);
          if (text) {
            func_0209378c(display);
            int destination = func_020937f0(display);
            if (destination) {
                memset(pixels, 0x11111111, 0x800);
                Struct_02093b90_3 tiles[8];
                unsigned char index;
                unsigned char x;
                unsigned int offset;
                offset=0;
                x=0;
                index=0;
                for (;index<8; ++index) {
                    int tileIndex = index;
                    Struct_02093b90_3* tile = &tiles[tileIndex];
                    tiles[index].offset=0;

                    tile->x=0;
                    tile->y=0;
                    tile->width=0;
                    tile->height=0;
                    tiles[index].offset=offset;
                    tile->x=x;
                    tile->y=0;
                    tile->width=32;
                    x+=32;
                    tile->height=16;
                    offset+=256;
                }
                S_b20c descriptor;
                GlyphDestination_Clear(&descriptor);
                GlyphDestination_SetPixels(&descriptor, (int)pixels);
                GlyphDestination_SetRects(&descriptor, (int)tiles, 8);
                GlyphDestination_DrawText(&descriptor, 16, 3, text, DRAW_ARGS_02093b90);
                CleanInvalidateCacheRange(pixels, 0x800);
                if (display==0) LoadToMainObjVRAM(pixels, destination-0x800, 0x800);
                else LoadToSubObjVRAM(pixels, destination-0x800, 0x800);
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
    self->elapsed += ticks;
    unsigned int limit;
    switch ((unsigned char)self->count) {
    case 0: case 1: limit=180; break;
    case 2: limit=120; break;
    default: limit=60; break;
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
    func_020945ac(self);
    self->elapsed=0;
}
