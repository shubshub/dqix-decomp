#include <globaldefs.h>

struct Struct_0201099c_3;
struct Struct_0205de24_2;
struct Struct_02020cb8_5;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_020420e8(char* str, int id);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
char* GetGlobalField0x1c020421a0(void);
int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b);
extern "C" void memset(void* dst, int val, int size);
void AppendEntryNames_0215e13c(char* base, char* dst, int flag);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

struct Struct_ov003_0215df1c {
#if defined(jpn)
    char unknown_0_[0x64 + 0x18];
#else
    char unknown1_0_[0x64];
#endif
    char unknown_64_[0x7c - 0x64];
    char* unknown_7c_;
    char unknown_80_[0x98 - 0x80];
    char unknown_98_[0x138 - 0x98];
    short unknown_138_;
    short unknown_13a_;
    short unknown_13c_;
    short unknown_13e_;
    short unknown_140_;
    short unknown_142_;
    short unknown_144_;
    short unknown_146_;
    char unknown_148_;
    unsigned char unknown_149_;
    char unknown_14a_[3];
    unsigned char unknown_14d_;
    char unknown_14e_;
    unsigned char unknown_14f_;
    char unknown_150_[4];
    char unknown_154_[2][0x20];
    char unknown_194_[0x3bd - 0x194];
    unsigned char unknown_3bd_[3];
    unsigned char unknown_3c0_;
    signed char unknown_3c1_;
    char unknown_3c2_[0x3d0 - 0x3c2];
    int unknown_3d0_;
    char unknown_3d4_[0x3f2 - 0x3d4];
    unsigned char unknown_3f2_;
};

// USA: func_ov003_0215df1c
extern "C" ARM void func_ov003_0215df1c(struct Struct_ov003_0215df1c* arg0) {
    void* var0 = func_0202ae18();
    arg0->unknown_3c0_ = 3;
    arg0->unknown_3bd_[0] = 0;
    arg0->unknown_3bd_[1] = 1;
    arg0->unknown_3bd_[2] = 2;
    if (func_0202c540(var0)) {
        arg0->unknown_3c0_ = 2;
        arg0->unknown_3bd_[0] = 1;
        arg0->unknown_3bd_[1] = 2;
        arg0->unknown_3bd_[2] = 0xff;
    } else if (arg0->unknown_3d0_ == 0) {
        arg0->unknown_3c0_ = 2;
        arg0->unknown_3bd_[0] = 0;
        arg0->unknown_3bd_[1] = 2;
        arg0->unknown_3bd_[2] = 0xff;
    }

    short var1 = (arg0->unknown_3c0_ * 14 + 0x12) / 8;
#if defined(jpn)
    short var5 = 7;
#else
    int maxWidth = 0;
    for (int i = 0; i < self->count; i++) {
        short w = func_020420e8((char*)KeyTable_Get((struct Container020e0310*)self->messages, self->keys[i]), 0);
        if (maxWidth < w) {
            maxWidth = w;
        }
    }
    short var5 = (var2 + 0x18) >> 3;
#endif

    func_0205de24((struct Struct_0205de24_2*)arg0->unknown_98_, 0, 2);
    arg0->unknown_138_ = var5;
    arg0->unknown_13a_ = var1;
    arg0->unknown_13c_ = 0x1f - var5;
    arg0->unknown_13e_ = 2;
    arg0->unknown_140_ = 0xc;
    arg0->unknown_142_ = 8;
    arg0->unknown_144_ = 0xa;
    arg0->unknown_146_ = 0xe;
    arg0->unknown_14f_ = 0xa;
    arg0->unknown_149_ = 1;
    arg0->unknown_14d_ = 1;

    if (arg0->unknown_3f2_) {
#if defined(jpn)
        short var6 = *(short*)(func_020421a0() + 0x7e6);
#else
        short var6 = *(short*)(func_020421a0() + 0x916);
#endif
        short row = pos / 8;
        short offset = pos % 8;
        self->x = 0x20 - width;
        self->y = row - height;
        for (int i = 0; i < 2; i++) {
            Background_SetScroll((struct Obj0204b5e8*)self->scrollers[i], 2, -offset);
        }
    }

    arg0->unknown_3c1_ = 0;
#if defined(jpn)
    memset(arg0->unknown_7c_, 0, 0x800);
#else
    memset(arg0->unknown_7c_, 0, 0x960);
#endif
    func_ov003_0215e13c((char*)arg0, arg0->unknown_7c_, 0);
#if defined(jpn)
    func_0205d304(arg0->unknown_98_, arg0->unknown_7c_, 0, 1, 0, 1, 0);
#else
    func_0205d304(arg0->unknown_98_, arg0->unknown_7c_, 0, 1, 0, 1, 0, 0);
#endif
}
