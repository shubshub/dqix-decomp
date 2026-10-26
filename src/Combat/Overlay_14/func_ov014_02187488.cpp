#include <globaldefs.h>

struct Struct_02097418;
struct Struct_02097420;
extern "C" void* func_02097418(struct Struct_02097418* obj);
extern "C" int func_02097420(struct Struct_02097420* obj);

struct Struct_ov014_02187450;
struct Struct_ov014_02187450_2;
extern "C" int* func_ov014_02187450(struct Struct_ov014_02187450* obj, struct Struct_ov014_02187450_2* key);

struct Struct_ov014_02187488 {
    unsigned int unknown_0_0_ : 10;
};

// USA: func_ov014_02187488
extern "C" ARM void func_ov014_02187488(struct Struct_ov014_02187450* obj) {
    unsigned char* base = (unsigned char*)func_02097418((struct Struct_02097418*)((char*)obj + 0xa4));
    unsigned short count = (unsigned short)func_02097420((struct Struct_02097420*)((char*)obj + 0xa4));
    unsigned short i = 0;
    while (i < count) {
        unsigned char* entry = base + i * 0x20;
        int* v = func_ov014_02187450(obj, (struct Struct_ov014_02187450_2*)entry);
        if (v != 0) {
            if (((struct Struct_ov014_02187488*)v)->unknown_0_0_) {
                entry[0x13] |= 2;
            }
        }
        i++;
    }
}
