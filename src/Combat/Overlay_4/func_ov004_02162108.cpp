#include <globaldefs.h>

struct Struct_ov004_021707e8_5 {
#if defined(jpn)
    unsigned char unknown1_0_[4];
    signed char unknown_6_;
    unsigned char unknown_5_;
    unsigned char unknown1_7_;
    unsigned char unknown_7_;
    signed char unknown_b_;
    unsigned char unknown_9_[3];
#else
    unsigned char unknown_0_[6];
    signed char unknown_6_;
    unsigned char unknown1_7_;
    unsigned char unknown_8_[3];
    signed char unknown_b_;
#endif
    char* unknown_c_;
    unsigned char unknown_10_[0xc];
    int unknown_1c_;
};

struct Struct_ov004_02162108 {
    short unknown_0_[7];
    unsigned char unknown_e_[7];
    unsigned char unknown_15_;
};

struct Struct_ov004_02170b90_4 {
    struct Struct_ov004_02162108 unknown_0_[26];
    unsigned char unknown_23c_;
    unsigned char unknown_23d_[2];
    unsigned char unknown_23f_;
};

class Struct_ov004_02162108_2 {
public:
    virtual void inline_ov004_02162108_46(); virtual void inline_ov004_02162108_47(); virtual void inline_ov004_02162108_48(); virtual void inline_ov004_02162108_49();
    virtual void inline_ov004_02162108_50(); virtual void inline_ov004_02162108_51(); virtual void inline_ov004_02162108_52(); virtual void inline_ov004_02162108_53();
    virtual void inline_ov004_02162108_54(); virtual void inline_ov004_02162108_55(); virtual void inline_ov004_02162108(); virtual void inline_ov004_02162108_2();
    virtual void inline_ov004_02162108_3(); virtual void inline_ov004_02162108_4(); virtual void inline_ov004_02162108_5(); virtual void inline_ov004_02162108_6();
    virtual void inline_ov004_02162108_7(); virtual void inline_ov004_02162108_8(); virtual void inline_ov004_02162108_9(); virtual void inline_ov004_02162108_10();
    virtual void inline_ov004_02162108_11(); virtual void inline_ov004_02162108_12(); virtual void inline_ov004_02162108_13(); virtual void inline_ov004_02162108_14();
    virtual void inline_ov004_02162108_15(); virtual void inline_ov004_02162108_16(); virtual void inline_ov004_02162108_17(); virtual void inline_ov004_02162108_18();
    virtual void inline_ov004_02162108_19(); virtual void inline_ov004_02162108_20(); virtual void inline_ov004_02162108_21(); virtual void inline_ov004_02162108_22();
    virtual void inline_ov004_02162108_23(); virtual void inline_ov004_02162108_24(); virtual void inline_ov004_02162108_25(); virtual void inline_ov004_02162108_26();
    virtual void inline_ov004_02162108_27(); virtual void inline_ov004_02162108_28(); virtual void inline_ov004_02162108_29(); virtual void inline_ov004_02162108_30();
    virtual void inline_ov004_02162108_31(); virtual void inline_ov004_02162108_32(); virtual void inline_ov004_02162108_33(); virtual void inline_ov004_02162108_34();
    virtual void inline_ov004_02162108_35(); virtual void inline_ov004_02162108_36(); virtual void inline_ov004_02162108_37(); virtual void inline_ov004_02162108_38();
    virtual void inline_ov004_02162108_39(); virtual void inline_ov004_02162108_40(); virtual void inline_ov004_02162108_41(); virtual void inline_ov004_02162108_42();
    virtual void inline_ov004_02162108_43(); virtual void inline_ov004_02162108_44();
    virtual void inline_ov004_02162108_45(int arg0);

    unsigned char unknown_4_[8];
    unsigned char unknown_c_;
    unsigned char unknown_d_[0x13];
    void* unknown_20_;
};

struct Struct_02072a68_2;

extern "C" void memset(void* arg0, int arg1, int arg2);
extern "C" void __clear(void* arg0, int arg1);
extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" Struct_ov004_02162108_2* func_ov004_0215e47c(void* arg0, int arg1);
extern "C" void func_ov004_0215e574(void* arg0, unsigned short arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" Struct_ov004_02162108_2* func_ov023_021f6880(void* arg0, int arg1);
extern "C" int func_ov023_021f6f10(Struct_ov004_02162108_2* arg0);
extern "C" struct Struct_02072a68_2* func_ov023_021fa598(Struct_ov004_02162108_2* arg0);
#if !defined(jpn)
extern "C" char* func_02072a68(struct Struct_02072a68_2* arg0, short arg1);
#endif
char* FindSubstring_020d2f88(char* str, char* sub);
int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int g, int mode, char* fmt, char* dst, int size, int a, int b);
void SetNodeFieldsAndMaybeNotify_0215f6f4(void* a, short v1, short v2, int flag);

extern struct Struct_ov004_021707e8_5 data_ov004_021707e8;
extern struct Struct_ov004_02170b90_4 data_ov004_02170b90[];
#if defined(jpn)
extern Struct_ov004_02170b90_4 data_ov004_02171660;
extern short data_ov004_021710a8[];
extern unsigned char data_ov004_02171090[];
#else
extern struct Struct_ov004_02170b90_4 data_ov004_02170dd0;
#endif
extern int data_ov004_0216fe90[];
extern short data_ov004_02170818[];
extern unsigned char data_ov004_02170814[];
extern char data_ov004_02170527[];

// JPN: func_ov004_02162108 (02162964)
// USA: func_ov004_02162108
extern "C" ARM int func_ov004_02162108(void* arg0) {
    data_ov004_021707e8.unknown1_7_ = 0x67;
    int var0 = 0;
#if !defined(jpn)
    memset(data_ov004_021707e8.unknown_c_, 0, 0x800);
#endif
    void* var1 = func_ov011_021849c8(arg0);
    if (data_ov004_021707e8.unknown_6_ == 0) {
        Struct_ov004_02162108_2* var2 = func_ov004_0215e47c(arg0, 3);
        if (var2 != 0) var2->unknown_c_ &= ~4;
    } else {
        Struct_ov004_02162108_2* var3 = func_ov004_0215e47c(arg0, 3);
        if (var3 != 0) var3->unknown_c_ |= 4;
    }
#if !defined(jpn)
    func_ov004_0215e574(arg0, 0xc, 0xff, 0, 0);
#endif

    if (data_ov004_02170b90[1].unknown_23f_ != 0) {
        for (int var4 = 0xd; var4 < 0xf; var4++) func_ov004_0215e49c(arg0, var4, 0x3a);
        for (int var5 = 0xf; var5 < 0x1d; var5++) func_ov004_0215e49c(arg0, var5, 0x11e);
        func_ov004_0215e49c(arg0, 0x31, 0x3a);
        func_ov004_0215e49c(arg0, 0x32, 0x3a);
        for (int var6 = 0; var6 < 3; var6++) {
            Struct_ov004_02162108_2* var7 = func_ov023_021f6880(var1, var6 + 0x65);
            if (var7 != 0) var7->unknown_c_ &= ~8;
        }
#if !defined(jpn)
        func_ov004_0215e574(arg0, 0xc, 0xff, 0, 0);
#endif

#if defined(jpn)
        Struct_ov004_02170b90_4* var8 = &data_ov004_02171660;
#else
        Struct_ov004_02170b90_4* var8 = &data_ov004_02170dd0;
#endif
        if (var8->unknown_23f_ <= 1) var8->unknown_23c_ = 0;
        int var9 = var8->unknown_23c_;
        if (var9 >= 26) var9 = 0;
        int var10 = 0;
        unsigned char var11[2];
        __clear(var11, 2);
        int var12 = 0;
        for (int var13 = var9; var13 < 26; var13++) {
            int var14 = data_ov004_0216fe90[var13];
            if (!var8->unknown_0_[var14 - 1].unknown_15_) continue;
            {
                int var15 = data_ov004_021707e8.unknown_1c_;
                int var16;
                short* var17;
                int var18 = 0xf;
#if defined(jpn)
                if (var14 != data_ov004_021710a8[var15] && var14 <= 0xe) var18 = 3;
                if (var14 == 0xd && data_ov004_02171090[var15] != 0) var18 = 0xf;
#else
                if (var14 != data_ov004_02170818[var15] && var14 <= 0xe) var18 = 3;
                if (var14 == 0xd && data_ov004_02170814[var15] != 0) var18 = 0xf;
#endif
                if (var18 == 0xf) var11[var10] = 1;
                short var19 = var10 + 0xd;
                var17 = var8->unknown_0_[var14 - 1].unknown_0_;
                func_ov004_0215e49c(arg0, var19, var13 + 0x19f);
#if !defined(jpn)
                if (var10 == 0) {
                    func_ov004_0215e574(arg0, var19, 0x80, 0, 0);
                } else {
                    func_ov004_0215e574(arg0, var19, 0x80, 0x80, 0);
                }
#endif
                Struct_ov004_02162108_2* var20 = func_ov023_021f6880(var1, var19);
                if (var20 != 0) var20->inline_ov004_02162108_45(var18);

                for (int var21 = 0; var21 < 7; var21++) {
                    int var22 = var17[var21];
                    short var23;
                    Struct_ov004_02162108_2* var24;
                    if (var22 < 0) break;
                    var23 = var21;
                    if (var10 == 0) {
                        var19 = var23 + 0xf;
                        var16 = 0;
                    } else {
                        var19 = var23 + 0x16;
                        var16 = 7;
                    }
#if defined(jpn)
                    func_ov004_0215e49c(arg0, var19, var22);
#else
                    msg = func_ov004_0215e47c(self, 0x320);
                    if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
                        int indent;
                        char* text;
                        struct TableA68* table;
                        Node02162108* label;
                        table = func_ov023_021fa598(msg);
                        text = data_ov004_021707e8.textBuf + (k + off) * 0x80;
                        memset(text, 0, 0x80);
                        indent = 0;
                        if (FindSubstring_020d2f88(_Z23FindEntryByKey_02072a68P8TableA68i(table, key), data_ov004_02170527)) indent = 0x14;
                        MessageSystem_FormatText(MessageSystem_GetInstance(), 0, _Z23FindEntryByKey_02072a68P8TableA68i(table, key), text, 0x78 - indent, 0, 0);
                        label = func_ov004_0215e47c(self, id);
                        if (label != 0 && func_ov023_021f6f10(label) == 8) label->data = text;
                    }
#endif
                    Struct_ov004_02162108_2* var29 = func_ov023_021f6880(var1, var19);
                    if (var29 != 0) var29->inline_ov004_02162108_45(var18);
                }
            }
            var9 = var13 + 1;
            var12 = 1;
            if (++var10 == 2) break;
        }
        if (var12) {
            int var30 = 0;
            for (; var9 < 26; var9++) {
                if (var8->unknown_0_[data_ov004_0216fe90[var9] - 1].unknown_15_) {
                    var30 = 1;
                    break;
                }
            }
            if (!var30) var9 = 26;
            var8->unknown_23c_ = var9;
        }
        if (var11[0] == 0 && var11[1] == 0) var0 = 1;
    } else {
        void* var31;
        for (int var32 = 0xd; var32 < 0xf; var32++) func_ov004_0215e49c(arg0, var32, 0x3a);
        for (int var33 = 0xf; var33 < 0x1d; var33++) func_ov004_0215e49c(arg0, var33, 0x11e);
        var31 = func_ov011_021849c8(arg0);
        for (int var34 = 0; var34 < 3; var34++) {
            Struct_ov004_02162108_2* var35 = func_ov023_021f6880(var31, var34 + 0x65);
            if (var35 != 0) var35->unknown_c_ |= 8;
        }
        func_ov004_0215e49c(arg0, 0x31, 0x1e0);
        func_ov004_0215e49c(arg0, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(arg0, 0x31, 0xff, 0, 0);
        func_ov004_0215e574(arg0, 0x32, 0xff, 0, 0);
#endif
        if (data_ov004_021707e8.unknown_6_ == 0) {
            Struct_ov004_02162108_2* var36 = func_ov004_0215e47c(arg0, 3);
            if (var36 != 0) var36->unknown_c_ &= ~4;
        }
    }

    int var37 = 0xf;
    if (var0) var37 = 3;
    Struct_ov004_02162108_2* var38 = func_ov023_021f6880(var1, 0xc);
    if (var38 != 0 && func_ov023_021f6f10(var38) == 8) var38->inline_ov004_02162108_45(var37);
    for (int var39 = 0; var39 < 4; var39++) {
        Struct_ov004_02162108_2* var40 = func_ov023_021f6880(var1, var39 + 0x64);
        if (var40 != 0 && func_ov023_021f6f10(var40) == 0x13) var40->inline_ov004_02162108_45(var37);
    }
    func_ov004_0215f6f4(arg0, data_ov004_021707e8.unknown_b_, data_ov004_021707e8.unknown_6_, var0);
    return 0;
}
