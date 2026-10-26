#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int func_02041dd0(char* dst, int kind);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" int func_02041a28(char* dst, int x);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int func_ov000_02170c7c(void* entry);

struct Struct_ov000_02178648 {
    char pad0[0x3c];
    unsigned int unknown_3c_0_ : 30;
    unsigned int flag30 : 1;
    unsigned int unknown_3f_7_ : 1;
};

struct Struct_ov000_02178648_2 {
    char pad0[0x4c];
    int field4c;
#if defined(jpn)
    char pad1[0x488 - 0x50];
#else
    char pad1[0x448 - 0x50];
#endif
};

// USA: func_ov000_02178648
extern "C" ARM void func_ov000_02178648(char* obj, char* dst) {
    if (dst == NULL) return;

#if defined(jpn)
    signed char cursor = *(signed char*)(obj + 0x1fa3);
#else
    signed char cursor = *(signed char*)(obj + 0x1d6b);
#endif
    int n = 0;
    unsigned char count;
    GameState* gs = GameState::GetInstance();
    GameState_GetParty(gs);

    if (func_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    count = *(unsigned char*)(obj + 0x79);
    for (unsigned char i = 0; i < count; i++) {
        struct Struct_ov000_02178648_2* entry = &((struct Struct_ov000_02178648_2*)(obj + 0x958))[*(signed char*)(obj + i + 0x70)];
        GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
        if (member != NULL) {
            func_02041dd0(dst, func_ov000_02170c7c(entry));
            Text_AppendNTag(dst, n, (const char*)member->baseStats_);
            Text_AppendPaletteTag(dst, 0xf);
            func_02041a28(dst, 0x46);
            struct Struct_ov000_02178648* info = (struct Struct_ov000_02178648*)member->baseStats_;
            Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)((unsigned short)info->flag30 + 0x7551)));
            if (i != count - 1) {
                Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
            }
        }
        n++;
    }
#if !defined(jpn)
    func_02041a28(dst, 0x7a);
#endif
}
