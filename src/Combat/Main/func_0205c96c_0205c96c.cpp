#include <globaldefs.h>
#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205c570;
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_0205c570(struct Struct_0205c570* s);
extern "C" void func_02042b10(void* obj, void* value);
extern "C" void WindowFrame_Draw(void* obj, int a, int b);
extern "C" void func_02042b1c(unsigned char* base);
extern "C" int func_0205cde8(unsigned char* p);
#if defined(jpn)
extern "C" void func_02046c78(void* ctx, void* ptr, int x, int y, int color, int a, int b, int flag);
#else
extern "C" void func_02045f3c(void* ctx, void* ptr, int x, int y, int color, int a, int b, int flag, int c, int d);
#endif

struct Container0205a3d0;
struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    char pad8[0xd];
    unsigned char f15;
};
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" struct Entry0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteContext_DrawEntries(void* obj);

static inline int inline_0205c96c(unsigned char* obj) { return *(int*)(obj + 0x88); }
static inline int inline_0205c96c_2(unsigned char* obj) { return *(int*)(obj + 0x8c); }

// USA: func_0205c96c
extern "C" ARM void func_0205c96c(unsigned char* obj, int flag) {
    unsigned char* ctx;
    int cursor;
    int end;
    int sum;
    int color;
    int x;
    int y;
    int top;
    int i;
    int var9;
    int column;
    int row;
    void* list;
    struct Container0205a3d0* entries;
    unsigned short key;
    struct Entry0205a3d0* entry;

    if (obj[RG(0x233, 0x1c3)] == 0 || obj[RG(0x232, 0x1c2)] == 0) {
        return;
    }

    ctx = (unsigned char*)MessageSystem_GetInstance();
    cursor = *(int*)(obj + 0x50);
    sum = func_0205c570((struct Struct_0205c570*)(obj + 0x1c));
    color = 0x7fff;
    if (obj[RG(0x234, 0x1c4)] == 0) {
        color = 0x3def;
    }

    if (flag == 0) {
        *(short*)(obj + 0xcc) = color;
        func_02042b10(ctx, obj + 0xb4);
        WindowFrame_Draw(ctx + RG(0x19e0, 0x1804), 1, 1);
        func_02042b1c(ctx);
    }

    if (func_0205cde8(obj) == 0) {
        return;
    }

    ctx[RG(0x19b0, 0x17e0)] = 1;

    var9 = *(int*)(obj + 0x7c);
    i = var9 * *(int*)(obj + 0x84);
    x = *(short*)(obj + 0xb4) + 0xc;
    y = *(short*)(obj + 0xb6) + 8;
    end = i + var9;
    top = y;

    for (; i < end; i++) {
        int c = color;
        if (i == cursor && cursor == sum) {
            c = 0xf0a;
        }
#if defined(jpn)
        func_02046c78(ctx, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + 0x1b0 + i * 2), x, y, c, 0xc, 0x14, flag);
#else
        func_02045f3c(ctx, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + 0x220 + i * 2), x, y, c, 0xc, 0x14, flag, 1, 0x11);
#endif
        y += *(int*)(obj + 0xd8);
    }

    if ((obj[0xb0] | obj[0xb1]) == 0) {
        return;
    }

    column = inline_0205c96c(obj);
    row = inline_0205c96c_2(obj);
    x = column * *(int*)(obj + 0xd4) + (x - 0x10);
    y = row * *(int*)(obj + 0xd8) + (top - 2);
    list = *(void**)(ctx + RG(0x2d8, 0x228));
    entries = *(struct Container0205a3d0**)(ctx + RG(0x2e0, 0x230));
    key = *(unsigned short*)(ctx + RG(0x2e4, 0x234));
    if (list == NULL || entries == NULL) {
        return;
    }

    SpriteEntryList_PlayAnimation(entries, key);
    entry = SpriteEntryList_Find(entries, key);
    if (entry != NULL) {
        entry->f15 |= 8;
    }
    entry = SpriteEntryList_Find(entries, key);
    if (entry != NULL) {
        entry->f4 = x;
        entry->unknown_6_ = y;
    }
    SpriteContext_DrawEntries(list);
}
