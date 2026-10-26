#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

extern "C" void SprSprite_Unload(struct Foo02048004* obj);
extern "C" void func_02048080(struct Struct_0204719c* table);

// USA: func_ov011_0218513c
extern "C" ARM void* func_ov011_0218513c(void* obj) {
    SprSprite_Unload((struct Foo02048004*)((char*)obj + 0x20));
    func_02048080((struct Struct_0204719c*)((char*)obj + 0x34));
    return obj;
}
