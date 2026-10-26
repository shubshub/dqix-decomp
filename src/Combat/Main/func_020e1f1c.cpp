#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020200c0_3 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

struct Struct_020e1f1c {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
};

struct Struct_020e1f1c_2 {
    Struct_020200c0_3* unknown_0_;
    void* unknown_4_;
    Struct_020e1f1c* unknown_8_;
    char unknown_c_[0x30 - 0xc];
    int unknown_30_;
    int unknown_34_;
    char unknown_38_[0x3c - 0x38];
    unsigned char unknown_3c_;
};

struct Struct_020e1f1c_3 {
    void* unknown_0_;
    Struct_020e1f1c_2* unknown_4_;
};

void* AllocateVRAMStagingMemory(unsigned int value);
struct HasDims020e1288;
int GetHalfProductField8(HasDims020e1288*);
extern "C" void func_020e2018(void* owner);
void GlyphDestinationRect_Clear(Struct02020520* s);
struct S_b20c;
void GlyphDestination_Clear(S_b20c*);
void GlyphDestination_SetPixels(void* obj, int value);
void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);

// USA: func_020e1f1c
extern "C" ARM void* func_020e1f1c(Owner020e1f1c* owner) {
    void* buffer = AllocateVRAMStagingMemory(0x4000);
    owner->buffer = buffer;
    if (buffer != 0) {
        Panel020e1f1c* panel = owner->panel;
        int half = GetHalfProductField8((HasDims020e1288*)panel);
        memset((char*)owner->buffer + panel->offset, 0, panel->stride + half);
        func_020e2018(owner);
        int count = owner->panel->count;
        for (int i = 0; i < count; i++) {
            Struct02020520* d = &owner->panel->layouts[i];
            ClipRec020e1f1c* s = &owner->panel->clips[i];
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
    return arg0->unknown_0_;
}
