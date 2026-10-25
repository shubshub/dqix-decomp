#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020200c0_3 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};

struct Struct_0203bebc_4 {
    int unknown_0_;
    signed char unknown_4_;
};

void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
void* MessageSystem_GetInstance(void);
void* Font_GetCharacter(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);
int GetWordFromTable02042648(int idx);
void CleanInvalidateCacheRange(const void* p, unsigned int len);
extern "C" void LoadToSubObjVRAM(const void* data, unsigned int offset, unsigned int length);
extern "C" int func_0205b36c(void* arg0, void* arg1, short arg2, int arg3, unsigned char arg4, unsigned char arg5);

#if defined(jpn)
#include "Resource/FontGlyphTable.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_0203bebc_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[10];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

struct Struct_0203bebc_3 {
    void* unknown_0_;
    Struct_0203bebc_2 unknown_4_[96];
    int unknown_604_;
    char* unknown_608_;
    unsigned int unknown_60c_;
    unsigned short unknown_610_;
    unsigned short unknown_612_;
    unsigned char unknown_614_[256];
};

struct Struct_020e8200 {
    unsigned int unknown_0_[8];
};

extern Struct_0203bebc_3* data_02105244;
extern const Struct_020e8200 data_020e8200;
extern "C" void __clear(void*, int);
#endif

// USA: func_0203bebc
#if defined(jpn)
extern "C" ARM void func_0203bebc(void* arg0, int arg1, char* arg2, char** arg3,
                                int arg4, void* arg5)
#else
extern "C" ARM void func_0203bebc(void* arg0, void* arg1, void* arg2)
#endif
{
#if defined(jpn)
    Struct_0203bebc_2* var0 = static_cast<Struct_0203bebc_2*>(arg0);
    if (arg2 == NULL) return;
    memset(var0->unknown_4_, 0, 10);
    memcpy(var0->unknown_4_, arg2, 6);
    var0->unknown_4_[6] = 0;

    switch (DISPCNTSUB & 0x300010) {
    case 0x10:
        var0->unknown_2_ = (unsigned int)arg5 >> 5;
        break;
    case 0x100010:
        var0->unknown_2_ = (unsigned int)arg5 >> 6;
        break;
    case 0x200010:
        var0->unknown_2_ = (unsigned int)arg5 >> 7;
        break;
    }
    var0->unknown_0_ = arg4;
    Struct_0203bebc* var1 = func_020429bc(10);
    if (var1 == NULL) return;
    int var2 = var1->unknown_3_;
    unsigned char var3[256];
    __clear(var3, 256);
    for (unsigned char var4 = 0; var4 < 3; ++var4) {
        unsigned char var5 = 0;
        const unsigned char* var6 = reinterpret_cast<const unsigned char*>(arg3[var4]);
        if (var6 == NULL) continue;
        unsigned char* var7 = var3 + var4 * 5;
        for (int var8 = 0; var8 < var2; ++var8) {
            for (int var9 = 0; var9 < 10; ++var9) {
                if (*var6 & (1 << var5)) {
                    if (var9 & 1) {
                        var7[var9 >> 1] = (var7[var9 >> 1] & 0xf) | 0xf0;
                    } else {
                        var7[var9 >> 1] &= 0xf0;
                        var7[var9 >> 1] |= 0xf;
                    }
                }
                ++var5;
                if (var5 >= 8) {
                    var5 = 0;
                    ++var6;
                }
            }
            var7 += 16;
        }
    }

    unsigned int var10;
    unsigned int var11;
    unsigned int var12;
    unsigned int var13;
    unsigned char* const var14 = data_02105244->unknown_614_;
    memset(var14, 0, 256);
    Struct_020e8200 var15 = data_020e8200;
    var11 = 0;
    for (var12 = 0; var12 < 8; ++var12) {
        var10 = 0;
        for (var13 = 0; var13 < 8; ++var13) {
            memcpy(var14 + var11, var3 + var15.unknown_0_[var12] + var10, 4);
            var10 += 16;
            var11 += 4;
        }
    }
    CleanInvalidateCacheRange(var14, 256);
    if (arg1 == 0) {
        LoadToMainObjVRAM(var14, (unsigned int)arg5, 256);
    } else if (arg1 == 1) {
        LoadToSubObjVRAM(var14, (unsigned int)arg5, 256);
    }
#else
    int limit;
    char* g = (char*)MessageSystem_GetInstance();
    void* fp = *(void**)(g + 0x60);
    memset(fp, 0, 0x400);

    struct Struct_020200c0_3 var19[4];
    int var20 = 0;
    int var21 = 0;
    for (int var22 = 0; var22 < 4; var22++) {
        struct Struct_020200c0_3* var23 = &var19[var22];
        var23->unknown_0_ = var20;
        var23->unknown_4_ = var21;
        var23->unknown_6_ = 0;
        var23->unknown_8_ = 0x20;
        var23->unknown_a_ = 0x10;
        var20 += 0x100;
        var21 += var23->unknown_8_;
    }

    struct Struct_020200c0_4 var24;
    func_0205b20c(&var24);
    func_0205b220(&var24, (int)var18);
    func_0205b228(&var24, (int)var19, 4);

    *(short*)((char*)arg0 + 0x22) = (short)((unsigned int)arg2 >> 7);
    memset(arg0, 0, 0x20);
    memcpy(arg0, arg1, ((unsigned char*)arg0)[0x20]);

    int total = 0;
    limit = ((unsigned char*)entry)[0x20];
    int prev = 0xff;
    int font = GetWordFromTable02042648(0);
    unsigned char ch;
    int cnt = 0;
    unsigned char* p = (unsigned char*)buf;
    for (; cnt < limit; cnt++) {
        ch = *p;
        if (ch == 0) break;
        int c = font;
        struct Glyph020425b4* gl = (struct Glyph020425b4*)Font_GetCharacter(ch, 0);
        if (gl != 0) {
            c = gl->width;
            func_0205b36c(&localObj, gl, (short)total, 0, 0xf, 0);
        }
        int var33 = var25 + func_020425e4(var26, var28, 0);
        var25 = var33 + (var31 + 1);
        var26 = var28;
        var30++;
    }

    CleanInvalidateCacheRange(var18, 0x400);
    LoadToSubObjVRAM(var18, (unsigned int)arg2, 0x400);
    ((unsigned char*)arg0)[0x21] = var25 - 1;
#endif
}
