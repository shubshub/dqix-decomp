#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);
#if defined(jpn)
#define func_ov013_02185e40 func_ov013_02186f4c
extern "C" void Window_OpenPane(void*, char*, int, int, int, int, void*);
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,NULL)
enum { windowOffset=0x34, subScreenOffset=0x5cc, canvasOffset=0x5dc, textSize=0x800 };
#else
extern "C" void Window_OpenPane(void* window, char* text, int c, int d, int e, int f, void* g, int h);
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,NULL,0)
enum { windowOffset=0x38, subScreenOffset=0x640, canvasOffset=0x654, textSize=0x960 };
#endif
extern "C" void func_ov013_02185e40(void* arg0, char* arg1);

struct Struct_ov013_02185cc0_3 {
    char unknown_0_[8];
    unsigned short* unknown_8_;
};
extern "C" Struct_ov013_02185cc0_3* func_ov013_02184338(void* arg0, unsigned int arg1);
extern "C" void* func_020421b0(int arg0);
void CleanInvalidateCacheRange(const void* start, unsigned int size);
void CleanCacheRange(const void* start, unsigned int size);
extern "C" void LoadToSubObjVRAM(const void* src, unsigned int offset, unsigned int size);
extern "C" void LoadToMainObjVRAM(const void* src, unsigned int offset, unsigned int size);

extern const int data_ov013_02187d9c[2];
extern const int data_ov013_02187da4[2];

struct Struct_ov013_02185cc0 {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
};

struct Struct_ov013_02185cc0_2 {
    char unknown_0_[0x18];
    void* unknown_18_;
    char unknown_1c_[Enum_ov013_02185cc0_56 - 0x1c];
    Struct_ov013_02185cc0 unknown_38_;
    char unknown_ee_[Enum_ov013_02185cc0_1600 - Enum_ov013_02185cc0_56 - sizeof(Struct_ov013_02185cc0)];
    bool unknown_640_;
    char unknown_641_[Enum_ov013_02185cc0_1620 - Enum_ov013_02185cc0_1600 - 1];
    void* unknown_654_;
    char* unknown_658_;
    char unknown_65c_[0x6a8 - 0x65c];
    unsigned char unknown_6a8_;
};

// USA: func_ov013_02185cc0
extern "C" ARM void func_ov013_02185cc0(Struct_ov013_02185cc0_2* arg0) {
    bool var0;
    void* var1;
    void* var2;
    unsigned char var3;
    func_0205de24((struct Struct_0205de24_2*)&arg0->unknown_38_, 0, 2);
    arg0->unknown_38_.unknown_a0_ = 0xf;
    arg0->unknown_38_.unknown_a2_ = 0xb;
    arg0->unknown_38_.unknown_a4_ = 1;
    arg0->unknown_38_.unknown_a6_ = 0xd;
    arg0->unknown_38_.unknown_a8_ = 6;
    arg0->unknown_38_.unknown_aa_ = 5;
    arg0->unknown_38_.unknown_ac_ = 0xa;
    arg0->unknown_38_.unknown_ae_ = 0xd;
    arg0->unknown_38_.unknown_b1_ = 4;
#if defined(jpn)
    if (arg0->unknown_640_) {
        arg0->unknown_38_.unknown_b5_ = 0;
    } else {
        arg0->unknown_38_.unknown_b5_ = 1;
    }
#else
    arg0->unknown_38_.unknown_b5_ = arg0->unknown_640_ ? 0 : 1;
#endif
    memset(arg0->unknown_658_, 0, Enum_ov013_02185cc0_2400);
    func_ov013_02185e40(arg0, arg0->unknown_658_);
    DRAW_TEXT(&arg0->unknown_38_, arg0->unknown_658_);
#if !defined(jpn)
    var1 = arg0->unknown_18_;
    var2 = arg0->unknown_654_;
    var3 = arg0->unknown_6a8_;
    var0 = arg0->unknown_640_;
    if (var1 != NULL && var2 != NULL)
    {
        const int* var4 = data_ov013_02187da4;
        if (var0)
            var4 = data_ov013_02187d9c;
        Struct_ov013_02185cc0_3* var5 = func_ov013_02184338(var1, (unsigned short)var4[0]);
        unsigned short* var6;
        if (var5 != NULL && (var6 = var5->unknown_8_) != NULL)
        {
            memcpy(var2, func_020421b0((unsigned char)(var3 * 4 + 0x28)), 0x80);
            unsigned int var7 = (unsigned short)(var6[2] & 0x3ff) << var4[1];
            CleanInvalidateCacheRange(var2, 0x80);
            if (var0)
                LoadToSubObjVRAM(var2, var7, 0x80);
            else
                LoadToMainObjVRAM(var2, var7, 0x80);
            CleanCacheRange(var2, 0x80);
        }
    }
#endif
}
