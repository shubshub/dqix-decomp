#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short unknown_ae_;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_0204f138(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);

extern "C" void* LinkSession_GetInstance(void);
extern "C" void SpriteContext_DrawSprite(void* list, void* entry);

struct Struct_ov003_0216d990 {
    unsigned char unknown_0_[0x14];
    int posX;
    int unknown_18_;
};

// USA: func_ov003_0216d990
extern "C" ARM void func_ov003_0216d990(char* obj) {
    void* g = LinkSession_GetInstance();
    if (*(short*)(obj + 4) != 2 || *(short*)(obj + 6) != 2) return;
    if (LinkSession_IsActive((int*)g) != 0) return;

    struct Struct_ov003_0216d990* tag = 0;
#if defined(jpn)
    enum { baseOffset = 0x113c, Enum_ov003_0216d990_4794 = 0x114a, listOffset = 0x10fc };
#else
    enum { baseOffset = 0x12ac, Enum_ov003_0216d990_4794 = 0x12ba, listOffset = 0x126c };
#endif
    char* base = *(char**)(obj + baseOffset);
    if (base != 0 && *(unsigned short*)(obj + Enum_ov003_0216d990_4794) > 6) {
        tag = (struct Struct_ov003_0216d990*)(base + 0xf0);
    }
    if (tag == 0) return;

#if defined(jpn)
    tag->posX = 0xde000;
    tag->unknown_18_ = 0x14000;
#else
    struct Elem_0205d81c* elem = func_0205d81c(*(struct Struct_0205d81c**)(obj + 0x1000 + 0x2c0), 0);
    if (elem == 0) return;

    short var4 = elem->posX << 3;
    short var5 = elem->unknown_ae_ << 3;
    short* xMin;
    short* var7;
    short* var8;
    short* var9;
    func_0204f138((unsigned char*)elem, (unsigned char**)&xMin, (unsigned char**)&var7, (unsigned char**)&var8,
                             (unsigned char**)&var9);
    int x = xMin[1] + var8[1] + var4;
    int y = var7[1] + var5;
    x = (short)x;
    y = (short)y;
    tag->posX = (x + 2) << 12;
    tag->unknown_18_ = (y - 2) << 12;
#endif
    SpriteContext_DrawSprite(obj + listOffset, tag);
}
