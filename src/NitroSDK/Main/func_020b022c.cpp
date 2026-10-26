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

extern "C" struct Struct_020afec4 *func_020b0288(struct Hdr02b0288 *h, unsigned int key);

struct Struct_020b022c { char pad[0x4]; unsigned int offset; };
extern "C" void func_020b0268(struct Struct_020b022c* p);

// USA: func_020b022c
extern "C" ARM int func_020b022c(struct Hdr02b0288* h, void** out) {
    struct Struct_020afec4* entry = func_020b0288(h, 0x50434d50);
    if (entry == NULL) {
        *out = NULL;
        return 0;
    }
    func_020b0268((struct Struct_020b022c*)((char*)entry + 8));
    *out = (char*)entry + 8;
    return 1;
}
