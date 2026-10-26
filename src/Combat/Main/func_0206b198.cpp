#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_02041bbc(Struct_0204166c*);

// JPN: func_0206cb14
extern "C" ARM void func_0206cb14(void* context, int arg1, unsigned short index) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    if (index >= 0x80) return;
    if (func_02069430(self, index)) return;
    Struct_0204166c* slot = &self->glyphs[index];
    if (slot->unknown_8_ < 0) return;
    if (self->unknown_17b8_[index] == 0) return;
    if (arg1 != slot->unknown_1a_) return;
    int count = self->unknown_17b8_[index] - 1;
    self->unknown_17b8_[index] = count;
    if ((count & 0xff) != 0) return;
    func_02041bbc(slot);
    self->unknown_9b4_ = (self->unknown_9b4_ - 1) & 0x7f;
}
#else

struct Struct_0204166c;
extern "C" void func_020416c0(struct Struct_0204166c* s);

extern "C" ARM bool func_02044494(void* obj, void* src);

struct Struct_0206b198 {
    char pad0[8];
    int field8;
    char pad1[0x1c - 0xc];
};

struct Struct_0204500c_4 {
    char pad0[0x9b4];
    int field9b4;
    Struct_0206b198 unknown_9b8_[0x80];
    unsigned char unknown_17b8_[0x80];
};

// USA: func_0206b198
extern "C" ARM void func_0206b198(struct Struct_0204500c_4* obj, unsigned short idx) {
    if (idx >= 0x80) return;
    if (func_02044494(obj, &idx)) return;
    struct Struct_0206b198* e = &obj->unknown_9b8_[idx];
    if (e->field8 < 0) return;
    if (obj->unknown_17b8_[idx] == 0) return;
    int cnt = obj->unknown_17b8_[idx] - 1;
    obj->unknown_17b8_[idx] = cnt;
    if ((cnt & 0xff) != 0) return;
    func_020416c0((struct Struct_0204166c*)e);
    obj->field9b4 = (obj->field9b4 - 1) & 0x7f;
}

#endif
