#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_02069234;

struct Struct_02069234_2 {
    void* f0;
    char* fmt;
    unsigned int kind : 4;
    unsigned int : 28;
    char pad2[0xc];
    short duration;
};

struct Struct_02000c9c_23 {
    char pad[0x294];
    Struct_02069234_2 effect;
    Struct_02069234_2* inline_02069234() { return &effect; }
};

struct Struct_02069234_4 {
    char unk[0x150];
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
    char text[0x14d4];
    signed char combatantId;
};

extern "C" char* func_020424ac(char* str);
extern "C" int func_020d857c(signed char* a, signed char* b);
extern "C" int STD_GetStringLength(const char* s);
extern "C" int func_02005a94(void* p);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" char* func_020e4958(char** dst, void* val, int a2, int a3, int a4, int a5);

typedef void (*Type_02000c9c_14)(char* tag, char** dst, Struct_02069234* sb, int index);

struct Struct_020e7e8c {
    char* prefix;
    Type_02000c9c_14 handler;
};

struct Struct_02069234_3 {
    char* key;
    signed char unknown_4_;
    signed char value;
    char pad[2];
};

struct Struct_020e7f04 {
    Struct_02069234_3 e[16];
};

extern Struct_020e7e8c data_020e7e8c[];
extern Struct_020e7f04 data_020e7f04;
extern char data_020f0904[4];
extern char data_020f0909[6];
extern char data_020f0910[];

// USA: func_02069234
extern "C" ARM void func_02069234(Struct_02069234* sb, char* str, char* dst) {
    char* cursor;
    if (str == 0 || dst == 0) {
        return;
    }
    cursor = dst;

    for (;;) {
        char c = *str;
        if (c == 0) {
            break;
        }
        if (c == '<') {
            char* gt = func_020424ac(str);
            if (gt == 0) {
                goto copy_char;
            }
            int handled = 0;
            char* tag = str + 1;
            struct Struct_020e7e8c* rec = data_020e7e8c;
            for (; rec->prefix != 0; rec++) {
                if (!func_020d857c((signed char*)tag, (signed char*)rec->prefix)) {
                    continue;
                }
                if (rec->handler != 0) {
                    int index = 0;
                    int len = STD_GetStringLength(rec->prefix);
                    signed char d = tag[len];
                    if (d >= '1' && d <= '9') {
                        index = func_02005a94(tag + len) - 1;
                    }
                    rec->handler(tag, &cursor, sb, index);
                }
                str = gt + 1;
                handled = 1;
                break;
            }
            if (handled) {
                continue;
            }

            int var9;
            int var10;
            int var11;
            int var12;
            var12 = var11 = var9 = -1;
            void* val;
            var10 = 0;
            val = 0;
            struct Struct_020e7f04 var14 = data_020e7f04;
            handled = 0;
            struct Struct_02069234_3* opt = var14.e;
            for (;;) {
                char* key = opt->key;
                if (key == 0) {
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
                    switch (opt->unknown_4_) {
                        case 0: var9 = opt->value; break;
                        case 1: var10 = opt->value; break;
                        case 2: var11 = opt->value; break;
                        case 3: var12 = opt->value; break;
                        case 4: val = sb->unknown_18_[index]; break;
                        case 5: val = sb->unknown_20_[index]; break;
                        case 6: val = sb->unknown_0_[index]; break;
                        case 7: val = sb->unknown_10_[index]; break;
                        case 8: val = sb->unknown_8_[index]; break;
                        case 9: val = sb->unknown_2c_; break;
                    }
                }
                opt++;
            }

            if (val != 0) {
                cursor = func_020e4958(&cursor, val, var9, var10, var11, var12);
            }
            if (!handled) {
                goto copy_char;
            }
            str = gt + 1;
            continue;
        }
        if (c == '[') {
            if (memcmp(str, data_020f0904, 4) == 0) {
                str += 4;
                GameState* gameState = GameState::GetInstance();
                Struct_02069234_4* combatant = (Struct_02069234_4*)func_0200ff1c(gameState, sb->combatantId);
                if (combatant != 0) {
                    Struct_02069234_2* var22 = combatant->unknown_150_->inline_02069234();
                    if (var22 != 0) {
                        if (var22->duration > 0) {
                            if (var22->kind == 0) {
                                cursor += sprintf(cursor, var22->fmt);
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
            *cursor = c;
            cursor++;
            str++;
            continue;
        }
        goto copy_char;
    skip_bracket:
        while (*str != ']' && *str != 0) {
            str++;
        }
        if (*str == 0) {
            cursor += sprintf(cursor, data_020f0910);
            break;
        }
        str++;
        continue;
    copy_char:
        *cursor = *str++;
        cursor++;
    }
    *cursor = 0;
}
