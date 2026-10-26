#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct Struct_020e1f1c {
    int f0;
    int value;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
};

struct Struct_020e1f1c_2 {
    Struct02020520* layouts;
    void* obj;
    Struct_020e1f1c* unknown_8_;
    char pad[0x30 - 0xc];
    int offset;
    int stride;
    char pad2[0x3c - 0x38];
    unsigned char count;
};

struct Struct_020e1f1c_3 {
    void* buffer;
    Struct_020e1f1c_2* panel;
};

void* AllocateVRAMStagingMemory(unsigned int value);
struct Struct_020e1288;
extern "C" int func_020e1288(Struct_020e1288*);
extern "C" void func_020e2018(void* owner);
extern "C" void GlyphDestinationRect_Clear(Struct02020520* s);
struct S_b20c;
extern "C" void GlyphDestination_Clear(S_b20c*);
extern "C" void GlyphDestination_SetPixels(void* obj, int value);
extern "C" void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);

// USA: func_020e1f1c
extern "C" ARM void* func_020e1f1c(Struct_020e1f1c_3* owner) {
    void* buffer = AllocateVRAMStagingMemory(0x4000);
    owner->buffer = buffer;
    if (buffer != 0) {
        Struct_020e1f1c_2* panel = owner->panel;
        int half = func_020e1288((Struct_020e1288*)panel);
        memset((char*)owner->buffer + panel->offset, 0, panel->stride + half);
        func_020e2018(owner);
        int count = owner->panel->count;
        for (int i = 0; i < count; i++) {
            Struct02020520* d = &owner->panel->layouts[i];
            Struct_020e1f1c* s = &owner->panel->unknown_8_[i];
            GlyphDestinationRect_Clear(d);
            d->a = s->value;
            d->b = s->x;
            d->c = s->y;
            d->d = s->w;
            d->e = s->h;
        }
        void* obj = owner->panel->obj;
        GlyphDestination_Clear((S_b20c*)obj);
        GlyphDestination_SetPixels(obj, (int)((unsigned int)owner->buffer + owner->panel->offset));
        GlyphDestination_SetRects(obj, (int)owner->panel->layouts, count);
    }
    return owner->buffer;
}
