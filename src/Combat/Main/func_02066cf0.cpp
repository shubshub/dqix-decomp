#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"

#if defined(jpn)
struct Struct_02066cf0_2 {
    char unknown_0_[0xc];
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    signed char unknown_18_[2];
    char unknown_1a_[2];
};

struct Struct_02066cf0_3 {
    int unknown_0_;
    void* unknown_4_;
    int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    char unknown_14_[4];
    unsigned short* unknown_18_;
    char unknown_1c_[4];
    int unknown_20_;
    int unknown_24_;
    char unknown_28_[0x10];
    int unknown_38_;
    char unknown_3c_[4];
    unsigned int unknown_40_;
    unsigned int unknown_44_;
    char unknown_48_[0x868 - 0x48];
    int unknown_868_;
    char unknown_86c_[0x880 - 0x86c];
    int unknown_880_;
    char unknown_884_[4];
    Struct_02066cf0_2 unknown_888_[128];
    char unknown_1688_[0x1718 - 0x1688];
    char unknown_1718_[0x10];
    int unknown_1728_;
    int unknown_172c_;
    int unknown_1730_;
    int unknown_1734_;
    int unknown_1738_;
    char unknown_173c_[0x174c - 0x173c];
    unsigned short unknown_174c_;
    char unknown_174e_[0x1772 - 0x174e];
    unsigned short unknown_1772_;
    short unknown_1774_;
    char unknown_1776_[0x1789 - 0x1776];
    unsigned char unknown_1789_;
    char unknown_178a_[0x17e1 - 0x178a];
    unsigned char unknown_17e1_;
    char unknown_17e2_[0x17e8 - 0x17e2];
    unsigned char unknown_17e8_;
    unsigned char unknown_17e9_;
    char unknown_17ea_[0x17f4 - 0x17ea];
    unsigned char unknown_17f4_;
    char unknown_17f5_;
    unsigned char unknown_17f6_;
    char unknown_17f7_[0x17fc - 0x17f7];
    unsigned char unknown_17fc_;
    unsigned char unknown_17fd_;
    char unknown_17fe_;
    unsigned char unknown_17ff_0_ : 1;
    unsigned char unknown_17ff_1_ : 7;
    char unknown_1800_[4];
    char unknown_1804_[0x1c4c - 0x1804];
    void* unknown_1c4c_;
};

struct CE28Obj;
void LoadStateBytePair0206b804(char* obj, int* out1, int* out2);
int IsField440Empty_0205ce28(struct CE28Obj* obj);
struct Field440Obj0202f6a4;
void WindowFrame_Open(struct Field440Obj0202f6a4* obj);
void WindowFrame_Update(void* obj, int amount);
struct Field440XYObj;
void GetField440XY_02066cc0(struct Field440XYObj* obj, short* outX, short* outY);
struct Holder02042c24;
void SetSubstructXY02042c24(struct Holder02042c24* holder, int x, int y);
void WindowFrame_Draw(void* obj, int a, int b);
void UpdateObj020e15f8Entry_020e2310(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6);
void CallFunc0205c96cIfMode6AndFlag_02044530(char* obj, int flag);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_02066a6c(void* arg0, int arg1);
extern "C" void func_020e2110(void* arg0);
extern "C" void func_020675fc(void* arg0);
extern "C" int func_02069408(Struct_02066cf0_3* arg0, unsigned short arg1);
extern "C" int func_02069430(Struct_02066cf0_3* arg0, unsigned short arg1);
extern "C" void func_0206cf44(Struct_02066cf0_3* arg0);
extern "C" void func_02044f5c(Struct_02066cf0_3* arg0, int* arg1, int* arg2);
extern "C" int func_02067ea0(Struct_02066cf0_3* arg0, int arg1, int arg2, unsigned short* arg3, unsigned short* arg4, int arg5, int arg6);
extern "C" void func_02066934(Struct_02066cf0_3* arg0, int arg1, Struct_02066cf0_2* arg2, short arg3, short arg4, int arg5);
extern "C" void func_02066794(void* arg0, int arg1, int arg2, Struct_02066cf0_2* arg3, short arg4, short arg5, int arg6);
extern "C" void func_020417b0(Struct_02066cf0_2* arg0, unsigned short arg1, void* arg2, int arg3);
extern "C" void func_0204459c(void* arg0, int arg1);
extern "C" void func_020653e4(int arg0, int arg1);
extern int data_0210773c;

extern "C" ARM void func_02066cf0(Struct_02066cf0_3* arg0, int arg1) {
    unsigned short var0;
    int var1;
    int var2;
    int var3;
    unsigned int var4;

    if (arg0->unknown_17fd_) return;

    int var5, var6;
    func_0206b804((char*)arg0, &var5, &var6);

    if ((obj->active && obj->showName) || obj->refreshHolder) {
        if (obj->refreshHolder) {
            if (IsField440Empty_0205ce28((CE28Obj*)obj->holder)) {
                WindowFrame_Open((Field440Obj0202f6a4*)obj->holder);
                WindowFrame_Update(obj->holder, 1);
            }
        }

        if (arg0->unknown_868_ && arg0->unknown_17e1_) {
            func_02066a6c(arg0, arg1);
        }

        short var7, var8;
        func_02066cc0((Struct_02066a6c_2*)arg0->unknown_1804_, &var7, &var8);
        func_02042c24((Struct_02042b98_3*)arg0->unknown_1804_, (short)(var7 + var5), (short)(var8 + var6));

        if (arg1 == 0) {
            if (arg0->unknown_4_) {
                func_020e2110(arg0->unknown_4_);
            } else {
                WindowFrame_Draw(obj->holder, 1, 1);
            }
        }

        func_02042c24((Struct_02042b98_3*)arg0->unknown_1804_, var7, var8);
    }

    if (!arg0->unknown_868_) return;
    func_020675fc(arg0);

    void* var9 = 0;
    Struct_02066cf0_2* var10;
    if (arg0->unknown_17e9_ == 1) {
        var9 = arg0->unknown_1718_;
    }

    if (!arg0->unknown_20_ | !arg0->unknown_24_) return;
    if (!arg0->unknown_38_) return;

    func_02044530((char*)arg0, arg1);

    int var11[16];
    int var12[16];
    var1 = 0;
    __clear(var11, sizeof(var11));
    __clear(var12, sizeof(var12));

    int var13 = 0x1f;
    int var14 = 0;
    int var15 = 0x1f;
    if (arg0->unknown_1789_ & 4) {
        var15 = arg0->unknown_880_ >> 16;
        if (arg1 != 0) {
            var15 &= 0x1f;
            if (var15 != 0) {
                var13 = 0xf - (var15 >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, var15, var13);
        }
    }

    if (arg0->unknown_17f6_) {
        if (!func_02069408(arg0, arg0->unknown_18_[arg0->unknown_44_])) return;
    }

    if (arg0->unknown_1789_ & 0x40) {
        func_0206cf44(arg0);
    }

    if (arg0->unknown_17e8_) {
        func_02044f5c(arg0, var11, var12);
        for (int var16 = 0; var16 < 0x10; var16++) {
            var12[var16] = arg0->unknown_172c_;
        }
    } else {
        if (arg0->unknown_1774_ < 0) var14 = 10;
        for (int var17 = 0; var17 < 0x10; var17++) {
            var11[var17] = arg0->unknown_1728_;
            var12[var17] = arg0->unknown_172c_;
        }
    }

    unsigned int var18 = arg0->unknown_44_;
    var4 = arg0->unknown_40_;
    if (arg0->unknown_17f4_ && arg0->unknown_1774_ >= 0 && var4 < arg0->unknown_1772_) var4 = arg0->unknown_1774_;

    unsigned char var19 = 1;
    int var20, var21;
    unsigned short* var22 = 0;
    unsigned short* var23 = 0;
    var3 = var12[0] - arg0->unknown_1738_;
    var2 = var11[0];

    for (; var4 < var18; var4++) {
        var0 = arg0->unknown_18_[var4];

        if (func_02069430(arg0, var0)) {
            if (func_02069408(arg0, var0)) {
                break;
            }
            if (var0 == 0xff18) {
                var1++;
                var2 = var11[var1];
                var3 += arg0->unknown_1734_;
                var19 = 1;
            } else if (var0 == 0xff1a) {
                if (var19) var2 += arg0->unknown_1730_;
                else var2 += arg0->unknown_8_;
            } else if (var0 == 0xff1b) {
                var2 += arg0->unknown_1730_ >> 1;
            } else if (var0 == 0xff1c || var0 == 0xff1f || var0 == 0xff20 || var0 == 0xff21) {
            } else if (var0 == 0xff36) {
                var21 = var3;
                var20 = var2 + var14;
                var22 = &arg0->unknown_18_[var4];
            } else if (var0 == 0xff37) {
                var23 = &arg0->unknown_18_[var4];
            } else if (var0 == 0xff19) {
                var2 += arg0->unknown_1730_;
            } else if (var0 == 0xff22) {
                var4++;
                var2 = var11[var1] + arg0->unknown_18_[var4];
            } else if (var0 == 0xff23) {
                var4++;
                var3 = var12[var1] + arg0->unknown_18_[var4];
            } else if (var0 == 0xff24) {
                var2 = var11[var1] + arg0->unknown_18_[var4 + 1];
                var4 += 2;
                var3 = var12[var1] + arg0->unknown_18_[var4];
            } else if (var0 == 0xff25) {
                var4++;
                var2 += arg0->unknown_18_[var4];
            } else if (var0 == 0xff26) {
                var4++;
                var3 += arg0->unknown_18_[var4];
            } else if (var0 == 0xff27) {
                var2 += arg0->unknown_18_[var4 + 1];
                var4 += 2;
                var3 += arg0->unknown_18_[var4];
            }
            continue;
        }

        var10 = &arg0->unknown_888_[var0];
        var19 = 0;
        if (var22 && var23) {
            var4 += func_02067ea0(arg0, var20, var21, var22, var23, var15, arg1);
            var22 = 0;
            var23 = 0;
            continue;
        }

        int var24 = var2 + var14;
        if (arg1 != 0) {
            if (arg0->unknown_c_ <= var4) {
                func_02066934(arg0, arg0->unknown_0_, var10, (short)var24, (short)(var3 + 2), 0xf);
            }
        } else if (arg0->unknown_17ff_0_) {
            if (arg0->unknown_10_ != arg0->unknown_44_) {
                void* var25 = AllocateVRAMStagingMemory(0x3000);
                if (var25 != 0) {
                    int var26 = (int)(((unsigned int)*(int*)((char*)arg0->unknown_1c4c_ + 0x50) << 16) >> 13);
                    func_02066794(var25, 0x100, 0x60, var10, (short)var24, (short)(var3 - 0x74), 0xf);
                    StageMemoryToVRAM(VRAMSubregion_TextureImage, var25, var26 + 0x700, 0x3000, true, false);
                    FreeVRAMStagingMemory(var25);
                }
            }
        } else if (arg0->unknown_4_) {
            char var27[3] = {0};
            var27[0] = var10->unknown_18_[0];
            var27[1] = var10->unknown_18_[1];
            func_020e2310((char*)arg0->unknown_4_, 0, var24, var3 - 0x74, (int)var27, 0xc, 0xf);
        } else {
            var10->unknown_c_ = var24;
            var10->unknown_10_ = var3;
            var10->unknown_14_ = 0;
            func_020417b0(var10, arg0->unknown_174c_, var9, var15);
        }

        var2 += arg0->unknown_1730_;
    }

    func_0204459c(arg0, arg1);
    arg0->unknown_c_ = var18;

    if (!arg0->unknown_17ff_0_) return;
    void* var28 = arg0->unknown_1c4c_;
    if (!var28) return;

    unsigned int var29 = (unsigned int)(*(int*)((char*)var28 + 0x50) << 16) >> 13;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x74000;
    *(volatile unsigned int*)0x04000470 = 0x400000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x80000;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0xfffff000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6e500000u | ((var29 + 0x700) >> 3);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_0210773c >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e1f00c0;

    *(volatile unsigned int*)0x0400046c = 0x100000;
    *(volatile unsigned int*)0x0400046c = 0x80000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = 0x7fff;

    int var30 = 0x80;
    float var31 = 0.0f;
    int var32 = (int)(var30 * var31);
    float var33 = 1.0f - var31;
    var32 = var32 << 12;
    func_020653e4(0, var32);

    unsigned int var34 = ((unsigned int)(unsigned short)(int)(4096.0f * var33)) << 16;
    *(volatile unsigned int*)0x0400048c = var34;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, var32);

    unsigned int var35 = ((unsigned int)(unsigned short)(int)(4096.0f * var33)) << 16;
    var35 |= 0x1000;
    *(volatile unsigned int*)0x0400048c = var35;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0x1000;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}
#else
struct CE28Obj;
void LoadStateBytePair0206b804(char* obj, int* out1, int* out2);
int IsField440Empty_0205ce28(struct CE28Obj* obj);
struct Field440Obj0202f6a4;
void WindowFrame_Open(struct Field440Obj0202f6a4* obj);
void WindowFrame_Update(void* obj, int amount);
struct Field440XYObj;
void GetField440XY_02066cc0(struct Field440XYObj* obj, short* outX, short* outY);
struct Holder02042c24;
void SetSubstructXY02042c24(struct Holder02042c24* holder, int x, int y);
void WindowFrame_Draw(void* obj, int a, int b);
bool IsCommandInRange02067a9c(void* obj, void* src);
void MeasureTextWidth0206b6b8(unsigned char* obj);
int Font_GetFallbackWidth(int idx);
bool IsHighByteFF02044494(void* obj, void* src);
int Font_GetKerning(int a, int b, int tableIdx);
int MessageSystem_GetInstance();
struct Holder020416cc;
int GetField0OfSubstructAt0x18(struct Holder020416cc* holder);
void UpdateObj020e15f8Entry_020e2310(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6);
struct SetIntIntShortAt0xcStruct;
void SetIntIntShortAt0xc_02066ce0(struct SetIntIntShortAt0xcStruct* s, int a, int b, short c);
void CallFunc0205c96cIfMode6AndFlag_02044530(char* obj, int flag);

extern "C" void func_02044830(void*, int*, int*);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_02066a6c(void* arg0, int arg1);
extern "C" void func_020e2110(void* arg0);
extern "C" void func_020675fc(void* arg0);
extern "C" void func_020654b8(void* arg0, int arg1, void* arg2, short arg3, short arg4, int arg5);
extern "C" void func_02045864(int arg0, int arg1, void* arg2, void* arg3, int arg4, int arg5, int arg6, unsigned char arg7);
extern "C" void func_020417b0(void* arg0, unsigned short arg1, void* arg2, int arg3);
extern "C" void func_0204459c(void* arg0, int arg1);
extern "C" void func_020653e4(int arg0, int arg1);

extern short data_020e7e54[];
extern short data_020e7e3c[];
extern int data_021077fc;

struct Struct_02066cf0 {
    char unknown_0_[4];
    signed char unknown_4_;
};

struct Struct_02066cf0_2 {
    char unknown_0_[0x17];
    unsigned char unknown_17_;
    Struct_02066cf0* unknown_18_;
};

struct Struct_02066cf0_3 {
    char unknown_0_[0x34];
    int unknown_34_;
    void* unknown_38_;
    char unknown_3c_[4];
    unsigned int unknown_40_;
    int unknown_44_;
    char unknown_48_[4];
    unsigned short* unknown_4c_;
    char unknown_50_[4];
    int unknown_54_;
    int unknown_58_;
    char unknown_5c_[0x10];
    int unknown_6c_;
    char unknown_70_[4];
    unsigned int unknown_74_;
    unsigned int unknown_78_;
    char unknown_7c_[0xc];
    unsigned int unknown_88_;
    char unknown_8c_[0x998 - 0x8c];
    int unknown_998_;
    char unknown_99c_[0x9b0 - 0x99c];
    int unknown_9b0_;
    char unknown_9b4_[4];
    Struct_02066cf0_2 unknown_9b8_[80];
    char unknown_1278_[0x1848 - 0x1278];
    char unknown_1848_[0x10];
    int unknown_1858_;
    int unknown_185c_;
    char unknown_1860_[4];
    int unknown_1864_;
    int unknown_1868_;
    char unknown_186c_[0x187c - 0x186c];
    unsigned short unknown_187c_;
    char unknown_187e_[0x195b - 0x187e];
    unsigned char unknown_195b_;
    char unknown_195c_[0x19b1 - 0x195c];
    unsigned char unknown_19b1_;
    char unknown_19b2_[0x19b8 - 0x19b2];
    unsigned char unknown_19b8_;
    unsigned char unknown_19b9_;
    char unknown_19ba_[0x19c5 - 0x19ba];
    unsigned char unknown_19c5_;
    char unknown_19c6_[0x19cb - 0x19c6];
    unsigned char unknown_19cb_;
    unsigned char unknown_19cc_;
    char unknown_19cd_;
    unsigned char unknown_19ce_;
    char unknown_19cf_[0x19dc - 0x19cf];
    unsigned char unknown_19dc_;
    char unknown_19dd_[3];
    char unknown_19e0_[0x1e28 - 0x19e0];
    void* unknown_1e28_;
};

struct Struct_02066cf0_4 {
    char unknown_0_[0x195b];
    unsigned char unknown_195b_;
};

// USA: func_02066cf0
extern "C" ARM void func_02066cf0(Struct_02066cf0_3* arg0, int arg1) {
    Struct_02066cf0_2* var36;
    int var37;
    int var38;
    unsigned int var39;
    unsigned char var40;

    if (arg0->unknown_19cc_) return;

    int var41, var42;
    func_0206b804((char*)arg0, &var41, &var42);

    if ((obj->active && obj->showName) || obj->refreshHolder) {
        if (obj->refreshHolder) {
            if (IsField440Empty_0205ce28((CE28Obj*)obj->holder)) {
                WindowFrame_Open((Field440Obj0202f6a4*)obj->holder);
                WindowFrame_Update(obj->holder, 1);
            }
        }

        if (arg0->unknown_998_ && arg0->unknown_19b1_) {
            func_02066a6c(arg0, arg1);
        }

        short var43, var44;
        func_02066cc0((Struct_02066a6c_2*)arg0->unknown_19e0_, &var43, &var44);
        func_02042c24((Struct_02042b98_3*)arg0->unknown_19e0_, (short)(var43 + var41), (short)(var44 + var42));

        if (arg1 == 0) {
            if (arg0->unknown_38_) {
                func_020e2110(arg0->unknown_38_);
            } else {
                WindowFrame_Draw(obj->holder, 1, 1);
            }
        }

        func_02042c24((Struct_02042b98_3*)arg0->unknown_19e0_, var43, var44);
    }

    if (!arg0->unknown_998_) return;
    func_020675fc(arg0);

    void* var45 = 0;
    if (arg0->unknown_19b9_ == 1) {
        var45 = arg0->unknown_1848_;
    }

    if (!arg0->unknown_54_ || !arg0->unknown_58_) return;
    if (!arg0->unknown_6c_) return;

    func_02044530((char*)arg0, arg1);

    int var46[16];
    int var47[16];
    int var48 = 0;
    __clear(var46, sizeof(var46));
    __clear(var47, sizeof(var47));

    int var49 = 0x1f;
    int var50 = 0x1f;
    if (arg0->unknown_195b_ & 4) {
        var50 = arg0->unknown_9b0_ >> 16;
        if (arg1 != 0) {
            var50 &= 0x1f;
            if (var50 != 0) {
                var49 = 0xf - (var50 >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, var50, var49);
        }
    }

    unsigned short var51;
    if (arg0->unknown_19c5_) {
        var51 = arg0->unknown_4c_[arg0->unknown_78_];
        if (!func_02067a9c(arg0, &var51)) return;
    }

    if (arg0->unknown_195b_ & 0x40) {
        func_0206b6b8((unsigned char*)arg0);
    }

    if (arg0->unknown_19b8_) {
        func_02044830(arg0, var46, var47);
        for (int var52 = 0; var52 < 0x10; var52++) {
            var47[var52] = arg0->unknown_185c_;
        }
    } else {
        for (int var53 = 0; var53 < 0x10; var53++) {
            var46[var53] = arg0->unknown_1858_ + 0xc;
            var47[var53] = arg0->unknown_185c_;
        }
    }

    unsigned char var54;
    unsigned int var55 = arg0->unknown_78_;
    var39 = arg0->unknown_74_;
    unsigned int var56 = arg0->unknown_88_;
    var54 = 0xff;
    if (var39 < var56) var39 = var56;

    unsigned char spacing = Font_GetFallbackWidth(obj->table);
    y = lineY[0] - obj->yOffset;
    x = lineX[0];

    for (; var39 < var55; var39++) {
        var51 = arg0->unknown_4c_[var39];

        if (func_02044494(arg0, &var51)) {
            if (func_02067a9c(arg0, &var51)) {
                break;
            }
            if (var51 == 0xff18) {
                int var58 = arg0->unknown_1864_;
                var37 = var46[var48 + 1];
                var48++;
                var38 += var58;
                var54 = 0xff;
            } else if (var51 == 0xff19) {
                var37 += var57 + 1;
                var54 = 0xff;
            }
            continue;
        }

        glyph = &obj->glyphs[ch];
        width = glyph->width;
        x += Font_GetKerning(prevWidth, width, obj->table);
        prevWidth = width;

        if (arg1 != 0) {
            if (arg0->unknown_40_ <= var39) {
                func_020654b8(arg0, arg0->unknown_34_, var36, (short)var37, (short)(var38 + 2), 0xf);
            }
        } else if (arg0->unknown_19ce_) {
            if (arg0->unknown_44_ != arg0->unknown_78_) {
                void* var59 = AllocateVRAMStagingMemory(0x3000);
                if (var59 != 0) {
                    unsigned char var60;
                    int var61 = (int)(((unsigned int)*(int*)((char*)arg0->unknown_1e28_ + 0x50) << 16) >> 13);
                    unsigned char var62 = arg0->unknown_19dc_;
                    Struct_02066cf0* var63 = var36->unknown_18_;

                    if (metrics) {
                        unsigned char effects = ((GlobalFlags02066cf0*)MessageSystem_GetInstance())->effects;
                        if (effects & 0x80) {
                            for (j = 0; j < 4; j++) {
                                func_02045864(data_020e7e54[j] + (short)x, data_020e7e3c[j] + (short)(y - 0x74),
                                              metrics, staging, 0x100, 0x60, 0xf, table);
                            }
                            func_02045864((short)var37 + 1, (short)(var38 - 0x74) + 1, var63, var59, 0x100, 0x60, 0xf, var62);
                        } else if (var64 & 2) {
                            short var65 = var38 - 0x74;
                            short var66 = var37;
                            func_02045864(var66 + 1, var65 + 1, var63, var59, 0x100, 0x60, 0xf, var62);
                            func_02045864(var66, var65, var63, var59, 0x100, 0x60, 0xf, var62);
                        } else {
                            func_02045864((short)var37, (short)(var38 - 0x74), var63, var59, 0x100, 0x60, 0xf, var62);
                        }
                    }

                    StageMemoryToVRAM(VRAMSubregion_TextureImage, var59, var61, 0x3000, true, false);
                    FreeVRAMStagingMemory(var59);
                }
            }
        } else if (arg0->unknown_38_) {
            int var67 = func_020416cc((Struct_020416cc_2*)var36);
            func_020e2310((char*)arg0->unknown_38_, 0, var37, var38 - 0x74, var67, 0xf, arg0->unknown_19dc_);
        } else {
            func_02066ce0((Struct_02066a6c_4*)var36, var37, var38, 0);
            func_020417b0(var36, arg0->unknown_187c_, var45, var50);
        }

        if (var36->unknown_18_) {
            var37 += var36->unknown_18_->unknown_4_ + 1;
        }
    }

    func_0204459c(arg0, arg1);
    arg0->unknown_40_ = var55;

    if (!arg0->unknown_19ce_) return;
    void* var68 = arg0->unknown_1e28_;
    if (!var68) return;

    unsigned int var69 = *(int*)((char*)var68 + 0x50) << 16;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x74000;
    *(volatile unsigned int*)0x04000470 = 0x400000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x80000;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0xfffff000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6e500000u | (var69 >> 16);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_021077fc >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e1f00c0;

    *(volatile unsigned int*)0x0400046c = 0x100000;
    *(volatile unsigned int*)0x0400046c = 0x80000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = 0x7fff;

    int var70 = 0x80;
    float var71 = 0.0f;
    int var72 = (int)(var70 * var71);
    float var73 = 1.0f - var71;
    var72 = var72 << 12;
    func_020653e4(0, var72);

    unsigned int var74 = ((unsigned int)(unsigned short)(int)(4096.0f * var73)) << 16;
    *(volatile unsigned int*)0x0400048c = var74;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, var72);

    unsigned int var75 = ((unsigned int)(unsigned short)(int)(4096.0f * var73)) << 16;
    var75 |= 0x1000;
    *(volatile unsigned int*)0x0400048c = var75;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0x1000;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}
#endif
