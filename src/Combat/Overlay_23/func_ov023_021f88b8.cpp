#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* obj);

struct Struct_ov023_021f68b8 { void* first; };
extern "C" void* func_ov023_021f68b8(struct Struct_ov023_021f68b8* head, int n);

extern "C" unsigned int func_ov023_021f6f10(void* obj);

struct Struct_ov004_02153978 { char pad[6]; unsigned short field6; };
extern "C" unsigned int func_ov023_021f6f08(struct Struct_ov004_02153978* obj);

struct Struct_ov023_021f88b8 { char pad[0x45]; unsigned char bit0 : 1; };

extern "C" int func_ov023_021f6f18(void* obj);

extern "C" void func_ov023_021f809c(void* obj, void* param2);

// USA: func_ov023_021f88b8
extern "C" ARM void func_ov023_021f88b8(void* obj, void* param1, int id) {
    void* sub = func_ov011_021849c8(param1);
    void* node = func_ov023_021f68b8((struct Struct_ov023_021f68b8*)sub, 0);
    while (node != NULL) {
        unsigned int state = func_ov023_021f6f10(node);
        if (state == 8 && *(unsigned short*)((char*)node + 0x34) == *(unsigned short*)((char*)obj + 0x6)) {
            unsigned int var3 = func_ov023_021f6f08((struct Struct_ov004_02153978*)node);
            if ((unsigned int)id == var3) {
                ((struct Struct_ov023_021f88b8*)node)->bit0 = 1;
            } else {
                ((struct Struct_ov023_021f88b8*)node)->bit0 = 0;
            }
        }
        node = (void*)func_ov023_021f6f18(node);
    }
    func_ov023_021f809c(obj, param1);
}
