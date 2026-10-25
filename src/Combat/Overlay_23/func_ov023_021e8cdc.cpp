#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern int data_ov023_021fdd6c;
extern "C" void* __clear(void* dst, int count);
extern "C" int Font_EncodeText(void* src, void* dst, int flag);
int STD_GetStringLength(const char* s);
int Font_FindCharacterIndex(int key, int tableIdx);
extern "C" void Font_DecodeText(void* a, void* b, int flag);

struct Struct_0204254c {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};
struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);
int AppendXTag_02041a28(char* dst, int x);
void Text_Append(char* dst, const char* src);
int AppendYTag_02041a5c(char* dst, int y);

#if defined(jpn)
extern "C" void Font_GetTextWidth(char*, int);
extern "C" void func_02042428(char*, int);
struct Struct_02072a68_2;
extern "C" char* func_02072a68(Struct_02072a68_2*, int);
extern "C" int func_02041a90(char*, int, int);
#endif

// USA: func_ov023_021e8cdc
extern "C" ARM void func_ov023_021e8cdc(char* arg0) {
    int var0;
    if (*(int*)(arg0 + 0x5f4) == 0) return;
    char* var1 = *(char**)(arg0 + 0x5d8);

#if defined(jpn)
    char* battle = (char*)GameState::GetInstance() + 0x3c + 0x5400;
    Font_GetTextWidth(dst, 8);
    func_02042428(dst, 12);
    Text_Append(dst, FindEntryByKey_02072a68(*(TableA68**)(obj + 0x5f4), 0x73));
    dst += strlen(dst);
    char* src = battle + 8;
    if (*(char**)(obj + 0x600)) src = *(char**)(obj + 0x600);
    for (int row = 0; row < 3; ++row) {
        memcpy(dst, src, 0x26);
        src += 0x26;
        dst += 0x26;
        if (row != 2) {
            AppendXYTag_02041a90(dst, 1, row * 0x13 + 0x1b);
            dst += strlen(dst);
            memcpy(dst, FindEntryByKey_02072a68(*(TableA68**)(obj + 0x5f4), 0x7b), 2);
            dst += 2;
        }
    }
#else
    char* var5 = (char*)GameState::GetInstance() + 0x29c + 0x5400;

    char var6[0x43a];
    __clear(var6, 0x3a);
    __clear(var6 + 0x3a, 0x400);

    char* src = *(char**)(obj + 0x600);
    if (src != 0) {
        len = Font_EncodeText(src, buf, 1);
    } else {
        len = STD_GetStringLength(battle + 8);
        memcpy(buf, battle + 8, len);
    }

    signed char idxByte = (signed char)Font_FindCharacterIndex((int)&data_ov023_021fdd6c, 1);
    for (; len < 0x39; len++) buf[len] = idxByte;

    Font_DecodeText(buf, buf + 0x3a, 1);

    char* var9 = var6 + 0x3a;
    int var10 = 0xf;
    int var11 = var10;
    int var12 = 8;
    int var13 = 0;
    for (;;) {
        if (*p == 0) return;
        int step = 1;
        struct Entry0204254c* e = Font_FindCharacter((int)p, step);
        if (e != 0) {
            AppendXTag_02041a28(dst, x);
            Text_Append(dst, (const char*)e->val);
            step = e->field5;
        }
        var13++;
        var9 += var14;
        var10 += 0xc;
        if (var13 == 0x13) {
            var12 += 0x13;
            var10 = var11;
            var13 = 0;
            func_02041a5c(var1, var12);
        }
    }
#endif
}
