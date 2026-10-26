#if defined(jpn)
#define R(j,u) (j)
#define func_0202920c func_02028dc4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov015_02190c98(void* obj);
extern "C" void GlyphBitmapContext_Clear();
extern "C" void func_02028d58(int value);
extern "C" void func_02029988(void* p, int flag);
extern "C" void func_0202920c(int a, int b, int c, int d, int e);
extern "C" void GlyphBitmapContext_Flush();
extern "C" void func_020bbcb4();
extern "C" void func_ov015_02190acc(void* obj);

struct Struct_ov015_02190428 {
    char pad0[0x328];
    unsigned short unknown_328_;
    char pad1[0x330 - 0x328 - 2];
    unsigned char unknown_330_;
    char pad2[0x334 - 0x330 - 1];
    unsigned char unknown_334_;
    char pad3[0x348 - 0x334 - 1];
    int unknown_348_;
    float unknown_34c_;
    unsigned char unknown_350_;
    char pad4[0x354 - 0x350 - 1];
    int unknown_354_;
};

// USA: func_ov015_02190428
extern "C" ARM void func_ov015_02190428(struct Struct_ov015_02190428* obj) {
    if (!func_ov015_02190c98(obj)) return;
    GlyphBitmapContext_Clear();
    if (obj->unknown_330_ != 2) obj->unknown_350_ = 0;
    func_02028d58(obj->unknown_354_);
    func_02029988((char*)obj + 0x2c4, 1);
    obj->unknown_334_ = 0;
    func_02028d58(0);
    func_0202920c(0xf, 0x81, 0x17, 6, 0x9e);
    func_0202920c(1, 0x82, 0x18, 4, 0x9c);
    int v = (int)(24.0f + obj->unknown_34c_ * (float)(int)obj->unknown_328_);
    func_0202920c(0xf, 0x82, v, 4, obj->unknown_348_);
    func_ov015_02190acc(obj);
    GlyphBitmapContext_Flush();
    func_020bbcb4();
}
