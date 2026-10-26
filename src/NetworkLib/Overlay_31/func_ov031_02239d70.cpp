#include <globaldefs.h>

extern "C" void func_ov031_022393e4(int v);
extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239cd4(int);

struct Struct_ov031_02290d18_2 { void (*unk0)(int, void*, int, int); void* field4; };
extern Struct_ov031_02290d18_2 data_ov031_02290d18;

struct Struct_ov031_02239d70 { unsigned char pad[0x5e]; unsigned short unknown_5e_; unsigned short field60; };

struct Struct_ov031_02239d70_2 {
    unsigned char pad0[2];
    unsigned short field2;
    unsigned char pad1[4];
    unsigned short field8;
    unsigned short fielda;
};

extern int data_ov031_0224c44c;

// USA: func_ov031_02239d70
extern "C" ARM void func_ov031_02239d70(Struct_ov031_02239d70_2* s) {
    unsigned short field2 = s->field2;
    if (field2 != 0) {
        func_ov031_022393e4(field2);
        func_ov031_02239368(9);
        return;
    }
    if (data_ov031_02290d18.unk0 != 0) {
        data_ov031_02290d18.unk0(0x8000000, &data_ov031_0224c44c, s->field8, s->fielda);
    }
    unsigned short field8 = s->field8;
    unsigned short fielda = s->fielda;
    unsigned short cur = ((Struct_ov031_02239d70*)data_ov031_02290d18.field4)->unknown_5e_;
    if (cur > fielda) {
        ((Struct_ov031_02239d70*)data_ov031_02290d18.field4)->unknown_5e_ = fielda;
        unsigned short bit = 1 << (field8 - 1);
        ((Struct_ov031_02239d70*)data_ov031_02290d18.field4)->field60 = bit;
    } else if (cur == fielda) {
        ((Struct_ov031_02239d70*)data_ov031_02290d18.field4)->field60 = ((Struct_ov031_02239d70*)data_ov031_02290d18.field4)->field60 | (1 << (field8 - 1));
    }
    int tag = func_ov031_02239cd4((unsigned short)(field8 + 1));
    if (tag == 0x18) {
        func_ov031_02239368(7);
        return;
    }
    if (tag == 2) return;
    func_ov031_02239368(9);
}
