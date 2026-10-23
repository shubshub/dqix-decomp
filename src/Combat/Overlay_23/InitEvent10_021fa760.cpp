#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj0RowEvent021fa760 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char pad_c[4];
    int field10;
    char pad14[0xc];
    int field20;
    char pad24[0x50];
    unsigned char field74;
    char pad75[3];
    char field78[0x10];
};

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void func_ov023_021faa60(void* obj, int p1);
void SpriteContext_Init(char* obj);

// USA: func_ov023_021fa760  (semantic: InitEvent10_021fa760)
#if defined(jpn)
struct Obj0RowEvent021f9b88 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char pad_c[4];
    int field10;
    char pad14[0xc];
    char pad20[0x50];
    unsigned char field70;
    char pad71[3];
    char field74[0x10];
};

extern "C" ARM int func_ov023_021fa760(struct Obj0RowEvent021f9b88* obj, int p1, int p2, int p3, int p4, int p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xa;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field10 = p4;
    SpriteContext_Init((char*)obj + 0x20);
    memset(obj->field74, 0, 0x10);
    obj->field70 = p5;
    func_ov023_021faa60(obj, p1);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fa760(struct Obj0RowEvent021fa760* obj, int p1, int p2, int p3, int p4, int p5, int p6) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xa;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field20 = p4;
    obj->field10 = p5;
    SpriteContext_Init((char*)obj + 0x24);
    memset(obj->field78, 0, 0x10);
    obj->field74 = p6;
    func_ov023_021faa60(obj, p1);
    return 1;
}
#endif
