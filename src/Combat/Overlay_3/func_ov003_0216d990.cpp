#include <globaldefs.h>

struct Struct_0205d0e0 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
int LinkSession_IsActive(int* obj);
void GetFourSubstructPointers_0204f138(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);

extern "C" void* LinkSession_GetInstance(void);
extern "C" void SpriteContext_DrawSprite(void* list, void* entry);

struct Struct_ov003_0216d990 {
    unsigned char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
};

// USA: func_ov003_0216d990
extern "C" ARM void func_ov003_0216d990(char* obj) {
    void* g = LinkSession_GetInstance();
    if (*(short*)(obj + 4) != 2 || *(short*)(obj + 6) != 2) return;
    if (LinkSession_IsActive((int*)g) != 0) return;

    struct Struct_ov003_0216d990* var1 = 0;
#if defined(jpn)
    enum { Enum_ov003_0216d990_4780 = 0x113c, Enum_ov003_0216d990_4794 = 0x114a, Enum_ov003_0216d990_4716 = 0x10fc };
#else
    enum { Enum_ov003_0216d990_4780 = 0x12ac, Enum_ov003_0216d990_4794 = 0x12ba, Enum_ov003_0216d990_4716 = 0x126c };
#endif
    char* var2 = *(char**)(arg0 + Enum_ov003_0216d990_4780);
    if (var2 != 0 && *(unsigned short*)(arg0 + Enum_ov003_0216d990_4794) > 6) {
        var1 = (struct Struct_ov003_0216d990*)(var2 + 0xf0);
    }
    if (var1 == 0) return;

#if defined(jpn)
    var1->unknown_14_ = 0xde000;
    var1->unknown_18_ = 0x14000;
#else
    struct Struct_0205d0e0* var3 = func_0205d81c(*(struct Struct_0205d81c**)(arg0 + 0x1000 + 0x2c0), 0);
    if (var3 == 0) return;

    short var4 = var3->unknown_ac_ << 3;
    short var5 = var3->unknown_ae_ << 3;
    short* var6;
    short* var7;
    short* var8;
    short* var9;
    func_0204f138((unsigned char*)var3, (unsigned char**)&var6, (unsigned char**)&var7, (unsigned char**)&var8,
                             (unsigned char**)&var9);
    int var10 = var6[1] + var8[1] + var4;
    int var11 = var7[1] + var5;
    var10 = (short)var10;
    var11 = (short)var11;
    var1->unknown_14_ = (var10 + 2) << 12;
    var1->unknown_18_ = (var11 - 2) << 12;
#endif
    SpriteContext_DrawSprite(obj + listOffset, tag);
}
