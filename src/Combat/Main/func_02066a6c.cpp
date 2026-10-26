#include <globaldefs.h>

#if defined(jpn)
struct Struct_02066a6c_8 { char unknown_0_[0x1c]; };
struct Struct_02066a6c_9 { short unknown_0_; short unknown_2_; int unknown_4_; int unknown_8_; int unknown_c_; int unknown_10_; int unknown_14_; int unknown_18_; };
struct Struct_02066a6c { char unknown_0_[0x440]; Struct_02066a6c_9* unknown_440_; };
struct Struct_02066a6c_2;
struct Struct_02066a6c_5 {
    void* unknown_0_;
    char unknown_4_[0x7e0]; Struct_02066a6c_9 unknown_7e4_; Struct_02066a6c_9 unknown_800_;
    char unknown_81c_[0x6c]; Struct_02066a6c_8 unknown_888_[128];
    char unknown_1688_[0xc4]; unsigned short unknown_174c_;
    char unknown_174e_[4]; unsigned short unknown_1752_[16];
    unsigned short unknown_1772_;
    char unknown_1774_[0x80]; unsigned char unknown_17f4_; unsigned char unknown_17f5_;
    char unknown_17f6_[0xe]; Struct_02066a6c unknown_1804_;
};
void LoadStateBytePair0206b804(char*, int*, int*);
void GetField440XY_02066cc0(Field440XYObj*, short*, short*);
struct Holder02042c24;
void SetSubstructXY02042c24(Holder02042c24*, int, int);
void WindowFrame_Draw(void*, int, int);
extern "C" void func_020681b4(GlyphJpn02066a6c*, int, int, short);
extern "C" void func_020417b0(GlyphJpn02066a6c*, int, int, int);
extern "C" void func_02066934(DisplayJpn02066a6c*, void*, GlyphJpn02066a6c*, int, int, int);

extern "C" ARM void func_02066a6c(Struct_02066a6c_5* arg0, int arg1) {
    if (!arg0->unknown_17f5_) return;
    Struct_02066a6c* var0 = &arg0->unknown_1804_;
    unsigned int var1;
    unsigned short* var2;
    unsigned char var3;
    var1 = 0;
    var2 = NULL;
    if (arg0->unknown_17f4_) {
        var2 = arg0->unknown_1752_;
        var1 = arg0->unknown_1772_ & 255;
    }
    if (var2) {
        int var4, var5;
        short var6, var7;
        func_0206b804((char*)arg0, &var4, &var5);
        func_02066cc0((Struct_02066a6c_2*)var0, &var6, &var7);
        var7 -= 19;
        var0->unknown_440_ = &arg0->unknown_800_;
        if (var0->unknown_440_) {
            var0->unknown_440_->unknown_10_ = 4096;
            var0->unknown_440_->unknown_14_ = 4096;
        }
        if (var0->unknown_440_) var0->unknown_440_->unknown_8_ = 2;
        if (arg1) func_02042c24((Struct_02042b98_3*)var0, var6, var7);
        else {
            SetSubstructXY02042c24((Holder02042c24*)holder, (short)(x + offsetX), (short)(y + offsetY));
            WindowFrame_Draw(holder, 1, 0);
        }
        short var8 = 8 - ((var1 * 10) & 7);
        var6 += (var8 + 18) >> 1;
        var7 += 5;
        for (var3 = 0; var3 < var1; var3++) {
            unsigned short var9 = var2[var3];
            if ((var9 & 0xff00) == 0xff00) {
                if (var9 == 0xff01) break;
                if (var9 == 0xff19) { var6 += 10; continue; }
                if (var9 == 0xff1a) { var6 += 10; continue; }
                if (var9 == 0xff1b) { var6 += 5; continue; }
                var9 &= 0x7f;
            }
            Struct_02066a6c_8* var10 = &arg0->unknown_888_[var9];
            if (arg1) func_02066934(arg0, arg0->unknown_0_, var10, var6, var7, 15);
            else {
                func_020681b4(var10, var6, var7, 0);
                func_020417b0(var10, arg0->unknown_174c_, 0, 31);
            }
            var6 += 10;
        }
    }
    var0->unknown_440_ = &arg0->unknown_7e4_;
}
#else
struct Struct_02066a6c_3 { char unknown_0_[4]; signed char unknown_4_; };
struct Struct_02066a6c_4 {
    char unknown_0_[12]; int unknown_c_; int unknown_10_; short unknown_14_; short unknown_16_; Struct_02066a6c_3* unknown_18_;
};
struct Struct_02066a6c_6 { short unknown_0_; short unknown_2_; int unknown_4_; int unknown_8_; int unknown_c_; int unknown_10_; int unknown_14_; int unknown_18_; };
struct Struct_02042b98_3 { char unknown_0_[0x440]; Struct_02066a6c_6* unknown_440_; };
struct Struct_02066a6c_2;
struct Struct_02066a6c_7 {
    char unknown_0_[0x34]; void* unknown_34_;
    char unknown_38_[0x8dc]; Struct_02066a6c_6 unknown_914_; Struct_02066a6c_6 unknown_930_;
    char unknown_94c_[0x6c]; Struct_02066a6c_4 unknown_9b8_[80];
    char unknown_1278_[0x604]; unsigned short unknown_187c_;
    char unknown_187e_[4]; unsigned short unknown_1882_[96];
    unsigned short unknown_1942_; short unknown_1944_;
    char unknown_1946_[0x7d]; unsigned char unknown_19c3_; unsigned char unknown_19c4_;
    char unknown_19c5_[0x17]; unsigned char unknown_19dc_;
    char unknown_19dd_[3]; Struct_02042b98_3 unknown_19e0_;
};
void LoadStateBytePair0206b804(char*, int*, int*);
void GetField440XY_02066cc0(Field440XYObj*, short*, short*);
void SetSubstructXY02042c24(Holder02042c24*, int, int);
void WindowFrame_Draw(void*, int, int);
int Font_GetFallbackWidth(int);
void SetIntIntShortAt0xc_02066ce0(SetIntIntShortAt0xcStruct*, int, int, short);
extern "C" void func_020417b0(SetIntIntShortAt0xcStruct*, int, int, int);
extern "C" void func_020654b8(Display02066a6c*, void*, SetIntIntShortAt0xcStruct*, int, int, int);

// USA: func_02066a6c
extern "C" ARM void func_02066a6c(Struct_02066a6c_7* arg0, int arg1) {
    if (!arg0->unknown_19c4_) return;
    Struct_02042b98_3* var11 = &arg0->unknown_19e0_;
    int var12;
    unsigned short* var13;
    Struct_02066a6c_4* var14;
    int var15;
    int var16;
    var12 = 0;
    var13 = NULL;
    if (arg0->unknown_19c3_) {
        var13 = arg0->unknown_1882_;
        var12 = arg0->unknown_1942_ & 255;
    }
    if (var13) {
        int var17, var18;
        short var19, var20;
        func_0206b804((char*)arg0, &var17, &var18);
        func_02066cc0((Struct_02066a6c_2*)var11, &var19, &var20);
        var20 -= 19;
        var11->unknown_440_ = &arg0->unknown_930_;
        if (var11->unknown_440_) {
            var11->unknown_440_->unknown_10_ = 4096;
            var11->unknown_440_->unknown_14_ = 4096;
        }
        if (var11->unknown_440_) var11->unknown_440_->unknown_8_ = 2;
        if (arg1) func_02042c24(var11, var19, var20);
        else {
            SetSubstructXY02042c24(holder, (short)(x + offsetX), (short)(y + offsetY));
            WindowFrame_Draw(holder, 1, 0);
        }
        short remainder = 8 - (obj->width & 7);
        x += (remainder + 18) >> 1;
        y += 5;
        unsigned char fontWidth = Font_GetFallbackWidth(obj->table);
        for (i = 0; i < count; i++) {
            spacing = fontWidth + 1;
            unsigned short code = text[i];
            if ((code & 0xff00) == 0xff00) {
                if (code == 0xff01) break;
                if (code == 0xff19) { x += spacing; continue; }
            }
            var14 = &arg0->unknown_9b8_[var23];
            if (arg1) func_020654b8(arg0, arg0->unknown_34_, var14, var19, var20, 15);
            else {
                func_02066ce0(var14, var19, var20, 0);
                func_020417b0(var14, arg0->unknown_187c_, 0, 31);
            }
            if (var14->unknown_18_) var19 += var14->unknown_18_->unknown_4_ + 1;
        }
    }
    var11->unknown_440_ = &arg0->unknown_914_;
}
#endif
