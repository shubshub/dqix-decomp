#include <globaldefs.h>

struct Struct_020db3a8;
extern "C" int func_020db3a8(Struct_020db3a8* s);
extern "C" int func_020de13c(unsigned char* obj);
extern "C" int func_020de148(unsigned char* obj);
extern "C" void func_020ddea0(void* elem, unsigned short arg1, unsigned char idx, void* p, unsigned char field3c, int val);

struct Struct_020db5ec {
    unsigned char pad1[0x3c];
    unsigned char field3c;
    unsigned char pad2[0x6e - 0x3c - 1];
    unsigned short unknown_6e_;
    unsigned char arr[3][0x28];
};

// USA: func_020db768
extern "C" ARM void func_020db768(Struct_020db5ec* s, void* other) {
    s->unknown_6e_ = (s->unknown_6e_ + 1) % 0xbe;
    for (int i = 0; i < 3; i++) {
        unsigned char* elem = s->arr[i];
        void* p = other;
        if (func_020de13c(elem)) {
            p = (char*)other + 4;
        } else if (func_020de148(elem)) {
            p = (char*)other + 8;
        }
        int val = 0xf;
        if (func_020db3a8((Struct_020db3a8*)s)) val = 0xe;
        func_020ddea0(elem, s->unknown_6e_, (unsigned char)(i * 4 + 4), p, s->field3c, val);
    }
}
