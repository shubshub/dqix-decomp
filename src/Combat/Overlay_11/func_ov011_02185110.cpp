#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0204719c;
extern "C" void func_02048080(Struct_0204719c* table);
extern "C" void SprSprite_Init(void* obj);

extern int data_ov023_021fe3e4;

struct Struct_ov011_02185020_3 {
    void* unknown_0_;
    char pad[0x34 - 4];
};

// USA: func_ov011_02185110
extern "C" ARM Struct_ov011_02185020_3* func_ov011_02185110(Struct_ov011_02185020_3* obj) {
    obj->unknown_0_ = &data_ov023_021fe3e4;
    func_02048080((Struct_0204719c*)((char*)obj + 0x34));
    SprSprite_Init((char*)obj + 0x20);
    return obj;
}
