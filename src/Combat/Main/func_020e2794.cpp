#include <globaldefs.h>

struct Container0205a3d0;
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteContext_DrawEntries(void* p);
extern "C" void func_020e1780(void* p);

struct Struct_020e2794 {
    unsigned char pad[0x3f];
    unsigned char unknown_3f_0_ : 1;
};

struct Struct_020e2794_2 {
    unsigned char pad0[0xc];
    struct Struct_020e2794* c;
    void* unknown_10_;
    unsigned char pad1[4];
    short field_18;
    short field_1a;
    unsigned short field_1c;
    unsigned char pad2[2];
    struct Container0205a3d0* field_20;
};

// USA: func_020e2794
extern "C" ARM void func_020e2794(struct Struct_020e2794_2* self, void* b) {
    if (!self->c->unknown_3f_0_) return;
    if (self->field_20 != NULL) {
        SpriteEntryList_SetPosition(self->field_20, self->field_1c, self->field_18, self->field_1a);
        if (b != NULL) SpriteContext_DrawEntries(b);
    }
    func_020e1780(self->unknown_10_);
}
