#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_02069234;

struct Struct_02069234_2 {
    void* unknown_0_;
    char* unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int : 28;
    char unknown_c_[0xc];
    short unknown_18_;
};

struct Struct_02000c9c_23 {
    char unknown_0_[0x294];
    Struct_02069234_2 unknown_294_;
    Struct_02069234_2* inline_02069234() { return &unknown_294_; }
};

struct Struct_02069234_4 {
    char unknown_0_[0x150];
    Struct_02000c9c_23* unknown_150_;
};

struct Struct_02069234 {
    void* unknown_0_[2];
    void* unknown_8_[2];
    void* unknown_10_[2];
    void* unknown_18_[2];
    void* unknown_20_[2];
    void* unknown_28_;
    void* unknown_2c_;
    char unknown_30_[0x37c];
    char unknown_3ac_[0x14d4];
    signed char unknown_1880_;
};

char* FindUnescapedAngleBracket_020424ac(char* str);
int IsPrefixMatch020d857c(signed char* a, signed char* b);
int STD_GetStringLength(const char* s);
extern "C" int func_02005a94(void* p);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" char* func_020e4958(char** dst, void* val, int a2, int a3, int a4, int a5);

typedef void (*Type_02000c9c_14)(char* tag, char** dst, Struct_02069234* sb, int index);

struct Struct_020e7e8c {
    char* unknown_0_;
    Type_02000c9c_14 unknown_4_;
};

struct Struct_02069234_3 {
    char* unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_;
    char unknown_6_[2];
};

struct Struct_020e7f04 {
    Struct_02069234_3 unknown_0_[16];
};

extern Struct_020e7e8c data_020e7e8c[];
extern Struct_020e7f04 data_020e7f04;
extern char data_020f0904[4];
extern char data_020f0909[6];
extern char data_020f0910[];

// USA: func_02069234
extern "C" ARM void func_02069234(Struct_02069234* arg0, char* arg1, char* arg2) {
    char* var0;
    if (arg1 == 0 || arg2 == 0) {
        return;
    }
    var0 = arg2;

    for (;;) {
        char var1 = *arg1;
        if (var1 == 0) {
            break;
        }
        if (var1 == '<') {
            char* var2 = func_020424ac(arg1);
            if (var2 == 0) {
                goto copy_char;
            }
            int var3 = 0;
            char* var4 = arg1 + 1;
            struct Struct_020e7e8c* var5 = data_020e7e8c;
            for (; var5->unknown_0_ != 0; var5++) {
                if (!func_020d857c((signed char*)var4, (signed char*)var5->unknown_0_)) {
                    continue;
                }
                if (rec->handler != 0) {
                    int index = 0;
                    int len = STD_GetStringLength(rec->prefix);
                    signed char d = tag[len];
                    if (d >= '1' && d <= '9') {
                        index = func_02005a94(tag + len) - 1;
                    }
                    var5->unknown_4_(var4, &var0, arg0, var6);
                }
                arg1 = var2 + 1;
                var3 = 1;
                break;
            }
            if (var3) {
                continue;
            }

            int var9;
            int var10;
            int var11;
            int var12;
            var12 = var11 = var9 = -1;
            void* var13;
            var10 = 0;
            var13 = 0;
            struct Struct_020e7f04 var14 = data_020e7f04;
            var3 = 0;
            struct Struct_02069234_3* var15 = var14.unknown_0_;
            for (;;) {
                char* var16 = var15->unknown_0_;
                if (var16 == 0) {
                    break;
                }
                int len = STD_GetStringLength(key);
                if (memcmp(tag, key, len) == 0) {
                    handled = 1;
                    tag += len;
                    int index = 0;
                    if (opt->value < 0) {
                        signed char d = *tag;
                        if (d >= '1' && d <= '9') {
                            index = func_02005a94(tag) - 1;
                        }
                    }
                    switch (var15->unknown_4_) {
                        case 0: var9 = var15->unknown_5_; break;
                        case 1: var10 = var15->unknown_5_; break;
                        case 2: var11 = var15->unknown_5_; break;
                        case 3: var12 = var15->unknown_5_; break;
                        case 4: var13 = arg0->unknown_18_[var18]; break;
                        case 5: var13 = arg0->unknown_20_[var18]; break;
                        case 6: var13 = arg0->unknown_0_[var18]; break;
                        case 7: var13 = arg0->unknown_10_[var18]; break;
                        case 8: var13 = arg0->unknown_8_[var18]; break;
                        case 9: var13 = arg0->unknown_2c_; break;
                    }
                }
                var15++;
            }

            if (var13 != 0) {
                var0 = func_020e4958(&var0, var13, var9, var10, var11, var12);
            }
            if (!var3) {
                goto copy_char;
            }
            arg1 = var2 + 1;
            continue;
        }
        if (c == '[') {
            if (memcmp(str, data_020f0904, 4) == 0) {
                str += 4;
                GameState* gameState = GameState::GetInstance();
                Combatant02069234* combatant = (Combatant02069234*)GetCombatantWithFlag0x100_0200ff1c(gameState, sb->combatantId);
                if (combatant != 0) {
                    StatusEffectEntry02069234* eff = combatant->statusTable->GetEffect();
                    if (eff != 0) {
                        if (eff->duration > 0) {
                            if (eff->kind == 0) {
                                cursor += sprintf(cursor, eff->fmt);
                            }
                        }
                    }
                }
                goto skip_bracket;
            }
            if (memcmp(str, data_020f0909, 6) == 0) {
                str += 6;
                cursor += sprintf(cursor, sb->text);
                goto skip_bracket;
            }
            *var0 = var1;
            var0++;
            arg1++;
            continue;
        }
        goto copy_char;
    skip_bracket:
        while (*arg1 != ']' && *arg1 != 0) {
            arg1++;
        }
        if (*arg1 == 0) {
            var0 += sprintf(var0, data_020f0910);
            break;
        }
        arg1++;
        continue;
    copy_char:
        *var0 = *arg1++;
        var0++;
    }
    *var0 = 0;
}
