#if defined(jpn)
#define func_ov014_021885bc func_ov014_0218948c
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_02080bac(void* obj, int id);
extern "C" void func_0208065c(void* obj, int id);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" void func_020806b0(void* obj, int id);
extern "C" void func_02080b2c(void* obj, int id);
extern "C" void func_02081130(void* obj, int id, int flag);
extern "C" int func_020813ec(void* obj, int id);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
struct Struct_ov014_02186bc8_3;
extern "C" short func_ov014_021874f8(struct Struct_ov014_02186bc8_3* obj);
struct Struct_ov014_021872dc;
extern "C" short func_ov014_02187520(struct Struct_ov014_021872dc* s);

struct Struct_ov014_021885bc {
    struct Struct_ov014_021885bc* next;
    char pad4[4];
    int field8;
    char pad12[0x13 - 0xc];
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
};

// USA: func_ov014_021885bc
extern "C" ARM void func_ov014_021885bc(void* self) {
    void* list = *(void**)((char*)self + 0xc0);
    short val = *(short*)((char*)self + 0x176);
    *(short*)((char*)list + LOW_REGION(0x2a, 0x36)) = val;
    func_02080bac(list, 5);
    func_0208065c(list, 5);

    struct Struct_ov014_021885bc* node = *(struct Struct_ov014_021885bc**)((char*)self + 0xbc);
    short id = 0x1b;
    short count = 0;
    for (; count < 0x10; id++, count++) {
        if (node != NULL) {
            int v = KeyTable_Get((struct Container020e0310*)((char*)self + 0xe0), 0x15);
            func_02080f8c((struct Container02080f8c*)list, id, v);
            if (node->unknown_13_1_) {
                func_02080f8c((struct Container02080f8c*)*(void**)((char*)self + 0xc0), id, node->field8);
            }
            node = node->next;
        } else {
            func_020806b0(list, id);
            func_02080b2c(list, id);
        }
    }

    short var6 = func_ov014_021874f8((struct Struct_ov014_02186bc8_3*)self);
    short idx = (short)(func_ov014_02187520((struct Struct_ov014_021872dc*)self) + 1);
    func_02080fa8((struct Struct_02080fa8*)list, 0x2b, idx);
    short page = (short)((var6 + 0xf) / 0x10);
    func_02080fa8((struct Struct_02080fa8*)list, 0x2d, page);
    int var9 = (var6 > 0x10) ? 1 : 0;
    func_02081130(list, 5, var9);
    func_020813ec(list, 5);
}
