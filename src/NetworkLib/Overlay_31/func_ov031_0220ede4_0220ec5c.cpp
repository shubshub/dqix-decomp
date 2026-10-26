#include <globaldefs.h>


extern "C" int func_ov031_0220d60c(void);
struct Struct_ov031_0220ede4;
extern "C" ARM Struct_ov031_0220ede4* func_ov031_0220ede4(unsigned char* key);
extern "C" void* func_ov031_0220ece8(void);
extern "C" ARM int func_ov031_0220edb4(void);
extern "C" int func_020ca4b4(void*, void*, int);
extern "C" void func_ov031_0220eea0(void* node);

struct Struct_ov031_0220ec5c { unsigned char pad[0x3c]; unsigned short field3c; };

// USA: func_ov031_0220ec5c
extern "C" ARM void func_ov031_0220ec5c(Struct_ov031_0220ec5c* obj, int id) {
    int base = func_ov031_0220d60c();
    if (base == 0) return;
    if (*(unsigned char*)(base + 0x2000 + 0x26a) != 0 || obj->field3c != 0) return;
    void* node = func_ov031_0220ede4((unsigned char*)obj + 4);
    if (node == NULL) {
        node = func_ov031_0220ece8();
    }
    if (node == NULL) {
        if (*(int*)(base + 0x2000 + 0x278) == 1) {
            node = (void*)func_ov031_0220edb4();
        }
    }
    if (node == NULL) return;
    *(unsigned short*)((char*)node + 2) = (unsigned short)id;
    func_020ca4b4(obj, (char*)node + 0x10, 0xc0);
    func_ov031_0220eea0(node);
}
