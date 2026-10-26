#include <globaldefs.h>

struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);

struct Struct_ov024_021fd104 { unsigned int v[3]; };
struct Struct_ov024_021fd104_2 {
    float value;
    unsigned char id;
    unsigned char pad5;
    unsigned char pad6;
    unsigned char unknown_7_;
    unsigned char code;
    unsigned char unknown_9_, pad10, unknown_b_;
};
union Struct_ov024_021fd104_3 {
    Struct_ov024_021fd104 raw;
    Struct_ov024_021fd104_2 f;
};

// USA: func_ov024_021fd104
extern "C" ARM void func_ov024_021fd104(char* self, unsigned char id) {
    union Struct_ov024_021fd104_3 e;
    e.raw = *(Struct_ov024_021fd104*)(self + 0x65c);
    short s = *(short*)(*(char**)(self + 0x64c) + 0x32);
    float v = (float)s;
    e.f.id = id;
    e.f.unknown_7_ = 0x64;
    e.f.code = 7;
    e.f.value = v;
    func_ov024_021f6a1c(*(struct Struct_ov024_021f6a1c**)(self + 0x658), &e);
}
