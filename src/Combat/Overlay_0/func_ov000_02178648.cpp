#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_3;

int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int FormatCombatLogSuffix02041dd0(char* dst, int kind);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendPaletteTag_02041e70(char* dst, int palette);
int AppendXTag_02041a28(char* dst, int x);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
extern "C" int func_ov000_02170c7c(void* entry);

struct Struct_ov000_02178648 {
    char unknown_0_[0x3c];
    unsigned int unknown_3c_0_ : 30;
    unsigned int unknown_3f_6_ : 1;
    unsigned int unknown_3f_7_ : 1;
};

struct Struct_ov000_02178648_2 {
    char unknown_0_[0x4c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

// USA: func_ov000_02178648
extern "C" ARM void func_ov000_02178648(char* arg0, char* arg1) {
    if (arg1 == NULL) return;

#if defined(jpn)
    signed char var0 = *(signed char*)(arg0 + 0x1fa3);
#else
    signed char var0 = *(signed char*)(arg0 + 0x1d6b);
#endif
    int var1 = 0;
    unsigned char var2;
    GameState* var3 = GameState::GetInstance();
    func_02010828(var3);

    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var0);

    count = *(unsigned char*)(obj + 0x79);
    for (unsigned char i = 0; i < count; i++) {
        struct Entry02178648* entry = &((struct Entry02178648*)(obj + 0x958))[*(signed char*)(obj + i + 0x70)];
        GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
        if (member != NULL) {
            FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
            AppendNameTag_02041b70(dst, n, (const char*)member->baseStats_);
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendXTag_02041a28(dst, 0x46);
            struct MemberInfo02178648* info = (struct MemberInfo02178648*)member->baseStats_;
            AppendString02042058(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)((unsigned short)info->flag30 + 0x7551)));
            if (i != count - 1) {
                AppendString02042058(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
            }
        }
        var1++;
    }
#if !defined(jpn)
    func_02041a28(arg1, 0x7a);
#endif
}
