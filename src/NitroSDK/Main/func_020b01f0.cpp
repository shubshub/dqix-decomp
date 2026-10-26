#include <globaldefs.h>

struct Struct_020afec4 {
    unsigned int id;
    unsigned int size;
};
struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short unknown_c_;
    unsigned short count;
};
struct Struct_020b01f0 { char pad[0xc]; unsigned int offset; };

extern "C" struct Struct_020afec4* func_020b0288(struct Hdr02b0288* h, unsigned int key);
extern "C" void func_020b0278(struct Struct_020b01f0* p);

// USA: func_020b01f0
extern "C" ARM int func_020b01f0(struct Hdr02b0288* h, void** out) {
    struct Struct_020afec4* e = func_020b0288(h, 0x504c5454);
    if (e == NULL) {
        *out = NULL;
        return 0;
    }
    func_020b0278((struct Struct_020b01f0*)((char*)e + 8));
    *out = (char*)e + 8;
    return 1;
}
