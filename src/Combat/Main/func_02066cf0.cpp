#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"

#if defined(jpn)
struct Struct_02066cf0_2 {
    char pad[0xc];
    int x;
    int y;
    int z;
    signed char key[2];
    char pad1a[2];
};

struct Struct_02066cf0_3 {
    int context;
    void* target;
    int unknown_8_;
    unsigned int drawn;
    unsigned int unknown_10_;
    char unknown_14_[4];
    unsigned short* text;
    char unknown_1c_[4];
    int field20;
    int field24;
    char pad28[0x10];
    int field38;
    char unknown_3c_[4];
    unsigned int start;
    unsigned int end;
    char unknown_48_[0x868 - 0x48];
    int active;
    char unknown_86c_[0x880 - 0x86c];
    int fade;
    char unknown_884_[4];
    Struct_02066cf0_2 glyphs[128];
    char unknown_1688_[0x1718 - 0x1688];
    char palette[0x10];
    int unknown_1728_;
    int unknown_172c_;
    int advance;
    int lineHeight;
    int yOffset;
    char unknown_173c_[0x174c - 0x173c];
    unsigned short font;
    char unknown_174e_[0x1772 - 0x174e];
    unsigned short unknown_1772_;
    short unknown_1774_;
    char unknown_1776_[0x1789 - 0x1776];
    unsigned char effects;
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
    unsigned char hidden;
    char unknown_17fe_;
    unsigned char unknown_17ff_0_ : 1;
    unsigned char unknown_17ff_1_ : 7;
    char unknown_1800_[4];
    char holder[0x1c4c - 0x1804];
    void* texture;
};

struct Struct_0205ce28_2;
extern "C" void func_0206b804(char* obj, int* out1, int* out2);
extern "C" int func_0205ce28(struct Struct_0205ce28_2* obj);
struct Field440Obj0202f6a4;
extern "C" void WindowFrame_Open(struct Field440Obj0202f6a4* obj);
extern "C" void WindowFrame_Update(void* obj, int amount);
struct Struct_02066a6c_2;
extern "C" void func_02066cc0(struct Struct_02066a6c_2* obj, short* outX, short* outY);
struct Struct_02042b98_3;
extern "C" void func_02042c24(struct Struct_02042b98_3* holder, int x, int y);
extern "C" void WindowFrame_Draw(void* obj, int a, int b);
extern "C" void func_020e2310(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6);
extern "C" void func_02044530(char* obj, int flag);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02066a6c(void* obj, int flag);
extern "C" void func_020e2110(void* target);
extern "C" void func_020675fc(void* obj);
extern "C" int func_02069408(Struct_02066cf0_3* obj, unsigned short ch);
extern "C" int func_02069430(Struct_02066cf0_3* obj, unsigned short ch);
extern "C" void func_0206cf44(Struct_02066cf0_3* obj);
extern "C" void func_02044f5c(Struct_02066cf0_3* obj, int* arg1, int* arg2);
extern "C" int func_02067ea0(Struct_02066cf0_3* obj, int x, int y, unsigned short* base, unsigned short* arg4, int alpha, int flag);
extern "C" void func_02066934(Struct_02066cf0_3* obj, int arg1, Struct_02066cf0_2* glyph, short x, short y, int flags);
extern "C" void func_02066794(void* arg0, int w, int h, Struct_02066cf0_2* glyph, short x, short y, int flags);
extern "C" void func_020417b0(Struct_02066cf0_2* glyph, unsigned short font, void* palette, int alpha);
extern "C" void func_0204459c(void* obj, int flag);
extern "C" void func_020653e4(int a, int b);
extern int data_0210773c;

extern "C" ARM void func_02066cf0(Struct_02066cf0_3* obj, int flag) {
    unsigned short ch;
    int line;
    int x;
    int y;
    unsigned int pos;

    if (obj->hidden) return;

    int offsetX, offsetY;
    func_0206b804((char*)obj, &offsetX, &offsetY);

    if ((obj->active && obj->unknown_17e1_) || obj->unknown_17fc_) {
        if (obj->unknown_17fc_) {
            if (func_0205ce28((Struct_0205ce28_2*)obj->holder)) {
                WindowFrame_Open((Field440Obj0202f6a4*)obj->holder);
                WindowFrame_Update(obj->holder, 1);
            }
        }

        if (obj->active && obj->unknown_17e1_) {
            func_02066a6c(obj, flag);
        }

        short var7, var8;
        func_02066cc0((Struct_02066a6c_2*)obj->holder, &var7, &var8);
        func_02042c24((Struct_02042b98_3*)obj->holder, (short)(var7 + offsetX), (short)(var8 + offsetY));

        if (flag == 0) {
            if (obj->target) {
                func_020e2110(obj->target);
            } else {
                WindowFrame_Draw(obj->holder, 1, 1);
            }
        }

        func_02042c24((Struct_02042b98_3*)obj->holder, var7, var8);
    }

    if (!obj->active) return;
    func_020675fc(obj);

    void* palette = 0;
    Struct_02066cf0_2* glyph;
    if (obj->unknown_17e9_ == 1) {
        palette = obj->palette;
    }

    if (!obj->field20 | !obj->field24) return;
    if (!obj->field38) return;

    func_02044530((char*)obj, flag);

    int var11[16];
    int var12[16];
    line = 0;
    __clear(var11, sizeof(var11));
    __clear(var12, sizeof(var12));

    int var13 = 0x1f;
    int indent = 0;
    int alpha = 0x1f;
    if (obj->effects & 4) {
        alpha = obj->fade >> 16;
        if (flag != 0) {
            alpha &= 0x1f;
            if (alpha != 0) {
                var13 = 0xf - (alpha >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, alpha, var13);
        }
    }

    if (obj->unknown_17f6_) {
        if (!func_02069408(obj, obj->text[obj->end])) return;
    }

    if (obj->effects & 0x40) {
        func_0206cf44(obj);
    }

    if (obj->unknown_17e8_) {
        func_02044f5c(obj, var11, var12);
        for (int i = 0; i < 0x10; i++) {
            var12[i] = obj->unknown_172c_;
        }
    } else {
        if (obj->unknown_1774_ < 0) indent = 10;
        for (int i = 0; i < 0x10; i++) {
            var11[i] = obj->unknown_1728_;
            var12[i] = obj->unknown_172c_;
        }
    }

    unsigned int end = obj->end;
    pos = obj->start;
    if (obj->unknown_17f4_ && obj->unknown_1774_ >= 0 && pos < obj->unknown_1772_) pos = obj->unknown_1774_;

    unsigned char var19 = 1;
    int var20, var21;
    unsigned short* var22 = 0;
    unsigned short* var23 = 0;
    y = var12[0] - obj->yOffset;
    x = var11[0];

    for (; pos < end; pos++) {
        ch = obj->text[pos];

        if (func_02069430(obj, ch)) {
            if (func_02069408(obj, ch)) {
                break;
            }
            if (ch == 0xff18) {
                line++;
                x = var11[line];
                y += obj->lineHeight;
                var19 = 1;
            } else if (ch == 0xff1a) {
                if (var19) x += obj->advance;
                else x += obj->unknown_8_;
            } else if (ch == 0xff1b) {
                x += obj->advance >> 1;
            } else if (ch == 0xff1c || ch == 0xff1f || ch == 0xff20 || ch == 0xff21) {
            } else if (ch == 0xff36) {
                var21 = y;
                var20 = x + indent;
                var22 = &obj->text[pos];
            } else if (ch == 0xff37) {
                var23 = &obj->text[pos];
            } else if (ch == 0xff19) {
                x += obj->advance;
            } else if (ch == 0xff22) {
                pos++;
                x = var11[line] + obj->text[pos];
            } else if (ch == 0xff23) {
                pos++;
                y = var12[line] + obj->text[pos];
            } else if (ch == 0xff24) {
                x = var11[line] + obj->text[pos + 1];
                pos += 2;
                y = var12[line] + obj->text[pos];
            } else if (ch == 0xff25) {
                pos++;
                x += obj->text[pos];
            } else if (ch == 0xff26) {
                pos++;
                y += obj->text[pos];
            } else if (ch == 0xff27) {
                x += obj->text[pos + 1];
                pos += 2;
                y += obj->text[pos];
            }
            continue;
        }

        glyph = &obj->glyphs[ch];
        var19 = 0;
        if (var22 && var23) {
            pos += func_02067ea0(obj, var20, var21, var22, var23, alpha, flag);
            var22 = 0;
            var23 = 0;
            continue;
        }

        int var24 = x + indent;
        if (flag != 0) {
            if (obj->drawn <= pos) {
                func_02066934(obj, obj->context, glyph, (short)var24, (short)(y + 2), 0xf);
            }
        } else if (obj->unknown_17ff_0_) {
            if (obj->unknown_10_ != obj->end) {
                void* var25 = AllocateVRAMStagingMemory(0x3000);
                if (var25 != 0) {
                    int vramOffset = (int)(((unsigned int)*(int*)((char*)obj->texture + 0x50) << 16) >> 13);
                    func_02066794(var25, 0x100, 0x60, glyph, (short)var24, (short)(y - 0x74), 0xf);
                    StageMemoryToVRAM(VRAMSubregion_TextureImage, var25, vramOffset + 0x700, 0x3000, true, false);
                    FreeVRAMStagingMemory(var25);
                }
            }
        } else if (obj->target) {
            char key[3] = {0};
            key[0] = glyph->key[0];
            key[1] = glyph->key[1];
            func_020e2310((char*)obj->target, 0, var24, y - 0x74, (int)key, 0xc, 0xf);
        } else {
            glyph->x = var24;
            glyph->y = y;
            glyph->z = 0;
            func_020417b0(glyph, obj->font, palette, alpha);
        }

        x += obj->advance;
    }

    func_0204459c(obj, flag);
    obj->drawn = end;

    if (!obj->unknown_17ff_0_) return;
    void* texture = obj->texture;
    if (!texture) return;

    unsigned int var29 = (unsigned int)(*(int*)((char*)texture + 0x50) << 16) >> 13;

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

    int size = 0x80;
    float t = 0.0f;
    int var32 = (int)(size * t);
    float var33 = 1.0f - t;
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
struct Struct_0205ce28_2;
extern "C" void func_0206b804(char* obj, int* out1, int* out2);
extern "C" int func_0205ce28(struct Struct_0205ce28_2* obj);
struct Field440Obj0202f6a4;
extern "C" void WindowFrame_Open(struct Field440Obj0202f6a4* obj);
extern "C" void WindowFrame_Update(void* obj, int amount);
struct Struct_02066a6c_2;
extern "C" void func_02066cc0(struct Struct_02066a6c_2* obj, short* outX, short* outY);
struct Struct_02042b98_3;
extern "C" void func_02042c24(struct Struct_02042b98_3* holder, int x, int y);
extern "C" void WindowFrame_Draw(void* obj, int a, int b);
extern "C" bool func_02067a9c(void* obj, void* src);
extern "C" void func_0206b6b8(unsigned char* obj);
extern "C" int Font_GetFallbackWidth(int idx);
extern "C" bool func_02044494(void* obj, void* src);
extern "C" int Font_GetKerning(int a, int b, int tableIdx);
extern "C" int MessageSystem_GetInstance();
struct Struct_020416cc_2;
extern "C" int func_020416cc(struct Struct_020416cc_2* holder);
extern "C" void func_020e2310(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6);
struct Struct_02066a6c_4;
extern "C" void func_02066ce0(struct Struct_02066a6c_4* s, int a, int b, short c);
extern "C" void func_02044530(char* obj, int flag);

extern "C" void func_02044830(void*, int*, int*);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02066a6c(void* obj, int flag);
extern "C" void func_020e2110(void* target);
extern "C" void func_020675fc(void* obj);
extern "C" void func_020654b8(void* obj, int arg1, void* glyph, short x, short y, int flags);
extern "C" void func_02045864(int x, int y, void* arg2, void* arg3, int p5, int p6, int p7, unsigned char table);
extern "C" void func_020417b0(void* glyph, unsigned short font, void* palette, int alpha);
extern "C" void func_0204459c(void* obj, int flag);
extern "C" void func_020653e4(int a, int b);

extern short data_020e7e54[];
extern short data_020e7e3c[];
extern int data_021077fc;

struct Struct_02066cf0 {
    char pad[4];
    signed char advance;
};

struct Struct_02066cf0_2 {
    char pad[0x17];
    unsigned char width;
    Struct_02066cf0* unknown_18_;
};

struct Struct_02066cf0_3 {
    char pad0[0x34];
    int context;
    void* target;
    char unknown_3c_[4];
    unsigned int drawn;
    int field44;
    char unknown_48_[4];
    unsigned short* text;
    char unknown_50_[4];
    int field54;
    int unknown_58_;
    char unknown_5c_[0x10];
    int unknown_6c_;
    char unknown_70_[4];
    unsigned int start;
    unsigned int end;
    char unknown_7c_[0xc];
    unsigned int unknown_88_;
    char pad8c[0x998 - 0x8c];
    int active;
    char unknown_99c_[0x9b0 - 0x99c];
    int fade;
    char unknown_9b4_[4];
    Struct_02066cf0_2 glyphs[80];
    char unknown_1278_[0x1848 - 0x1278];
    char palette[0x10];
    int unknown_1858_;
    int unknown_185c_;
    char unknown_1860_[4];
    int lineHeight;
    int yOffset;
    char unknown_186c_[0x187c - 0x186c];
    unsigned short font;
    char unknown_187e_[0x195b - 0x187e];
    unsigned char effects;
    char unknown_195c_[0x19b1 - 0x195c];
    unsigned char unknown_19b1_;
    char unknown_19b2_[0x19b8 - 0x19b2];
    unsigned char unknown_19b8_;
    unsigned char unknown_19b9_;
    char unknown_19ba_[0x19c5 - 0x19ba];
    unsigned char unknown_19c5_;
    char unknown_19c6_[0x19cb - 0x19c6];
    unsigned char unknown_19cb_;
    unsigned char hidden;
    char unknown_19cd_;
    unsigned char unknown_19ce_;
    char unknown_19cf_[0x19dc - 0x19cf];
    unsigned char table;
    char unknown_19dd_[3];
    char holder[0x1e28 - 0x19e0];
    void* texture;
};

struct GlobalFlags02066cf0 {
    char pad[0x195b];
    unsigned char effects;
};

// USA: func_02066cf0
extern "C" ARM void func_02066cf0(Struct_02066cf0_3* obj, int flag) {
    Struct_02066cf0_2* glyph;
    int x;
    int y;
    unsigned int pos;
    unsigned char width;

    if (obj->hidden) return;

    int offsetX, offsetY;
    func_0206b804((char*)obj, &offsetX, &offsetY);

    if ((obj->active && obj->unknown_19b1_) || obj->unknown_19cb_) {
        if (obj->unknown_19cb_) {
            if (func_0205ce28((Struct_0205ce28_2*)obj->holder)) {
                WindowFrame_Open((Field440Obj0202f6a4*)obj->holder);
                WindowFrame_Update(obj->holder, 1);
            }
        }

        if (obj->active && obj->unknown_19b1_) {
            func_02066a6c(obj, flag);
        }

        short var43, var44;
        func_02066cc0((Struct_02066a6c_2*)obj->holder, &var43, &var44);
        func_02042c24((Struct_02042b98_3*)obj->holder, (short)(var43 + offsetX), (short)(var44 + offsetY));

        if (flag == 0) {
            if (obj->target) {
                func_020e2110(obj->target);
            } else {
                WindowFrame_Draw(obj->holder, 1, 1);
            }
        }

        func_02042c24((Struct_02042b98_3*)obj->holder, var43, var44);
    }

    if (!obj->active) return;
    func_020675fc(obj);

    void* palette = 0;
    if (obj->unknown_19b9_ == 1) {
        palette = obj->palette;
    }

    if (!obj->field54 || !obj->unknown_58_) return;
    if (!obj->unknown_6c_) return;

    func_02044530((char*)obj, flag);

    int var46[16];
    int var47[16];
    int line = 0;
    __clear(var46, sizeof(var46));
    __clear(var47, sizeof(var47));

    int var49 = 0x1f;
    int alpha = 0x1f;
    if (obj->effects & 4) {
        alpha = obj->fade >> 16;
        if (flag != 0) {
            alpha &= 0x1f;
            if (alpha != 0) {
                var49 = 0xf - (alpha >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, alpha, var49);
        }
    }

    unsigned short ch;
    if (obj->unknown_19c5_) {
        ch = obj->text[obj->end];
        if (!func_02067a9c(obj, &ch)) return;
    }

    if (obj->effects & 0x40) {
        func_0206b6b8((unsigned char*)obj);
    }

    if (obj->unknown_19b8_) {
        func_02044830(obj, var46, var47);
        for (int i = 0; i < 0x10; i++) {
            var47[i] = obj->unknown_185c_;
        }
    } else {
        for (int i = 0; i < 0x10; i++) {
            var46[i] = obj->unknown_1858_ + 0xc;
            var47[i] = obj->unknown_185c_;
        }
    }

    unsigned char prevWidth;
    unsigned int end = obj->end;
    pos = obj->start;
    unsigned int var56 = obj->unknown_88_;
    prevWidth = 0xff;
    if (pos < var56) pos = var56;

    unsigned char spacing = Font_GetFallbackWidth(obj->table);
    y = var47[0] - obj->yOffset;
    x = var46[0];

    for (; pos < end; pos++) {
        ch = obj->text[pos];

        if (func_02044494(obj, &ch)) {
            if (func_02067a9c(obj, &ch)) {
                break;
            }
            if (ch == 0xff18) {
                int lineHeight = obj->lineHeight;
                x = var46[line + 1];
                line++;
                y += lineHeight;
                prevWidth = 0xff;
            } else if (ch == 0xff19) {
                x += spacing + 1;
                prevWidth = 0xff;
            }
            continue;
        }

        glyph = &obj->glyphs[ch];
        width = glyph->width;
        x += Font_GetKerning(prevWidth, width, obj->table);
        prevWidth = width;

        if (flag != 0) {
            if (obj->drawn <= pos) {
                func_020654b8(obj, obj->context, glyph, (short)x, (short)(y + 2), 0xf);
            }
        } else if (obj->unknown_19ce_) {
            if (obj->field44 != obj->end) {
                void* var59 = AllocateVRAMStagingMemory(0x3000);
                if (var59 != 0) {
                    unsigned char j;
                    int vramOffset = (int)(((unsigned int)*(int*)((char*)obj->texture + 0x50) << 16) >> 13);
                    unsigned char table = obj->table;
                    Struct_02066cf0* var63 = glyph->unknown_18_;

                    if (var63) {
                        unsigned char effects = ((GlobalFlags02066cf0*)MessageSystem_GetInstance())->effects;
                        if (effects & 0x80) {
                            for (j = 0; j < 4; j++) {
                                func_02045864(data_020e7e54[j] + (short)x, data_020e7e3c[j] + (short)(y - 0x74),
                                              var63, var59, 0x100, 0x60, 0xf, table);
                            }
                            func_02045864((short)x + 1, (short)(y - 0x74) + 1, var63, var59, 0x100, 0x60, 0xf, table);
                        } else if (effects & 2) {
                            short var65 = y - 0x74;
                            short var66 = x;
                            func_02045864(var66 + 1, var65 + 1, var63, var59, 0x100, 0x60, 0xf, table);
                            func_02045864(var66, var65, var63, var59, 0x100, 0x60, 0xf, table);
                        } else {
                            func_02045864((short)x, (short)(y - 0x74), var63, var59, 0x100, 0x60, 0xf, table);
                        }
                    }

                    StageMemoryToVRAM(VRAMSubregion_TextureImage, var59, vramOffset, 0x3000, true, false);
                    FreeVRAMStagingMemory(var59);
                }
            }
        } else if (obj->target) {
            int a4 = func_020416cc((Struct_020416cc_2*)glyph);
            func_020e2310((char*)obj->target, 0, x, y - 0x74, a4, 0xf, obj->table);
        } else {
            func_02066ce0((Struct_02066a6c_4*)glyph, x, y, 0);
            func_020417b0(glyph, obj->font, palette, alpha);
        }

        if (glyph->unknown_18_) {
            x += glyph->unknown_18_->advance + 1;
        }
    }

    func_0204459c(obj, flag);
    obj->drawn = end;

    if (!obj->unknown_19ce_) return;
    void* texture = obj->texture;
    if (!texture) return;

    unsigned int var69 = *(int*)((char*)texture + 0x50) << 16;

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

    int size = 0x80;
    float t = 0.0f;
    int var72 = (int)(size * t);
    float var73 = 1.0f - t;
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
