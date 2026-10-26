#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c508;
extern "C" void func_0205c508(struct Struct_0205c508* s, int* out1, int* out2);

extern "C" int func_ov000_0217542c(void* obj);
extern "C" int func_02053c6c(unsigned char* obj);

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);

struct Struct_ov000_02179ed8 {
    char pad[0x23];
    signed char field23;
    char pad2[0x4c - 0x24];
    int field4c;
};

// USA: func_ov000_02179ed8
extern "C" ARM void func_ov000_02179ed8(char* obj, struct Struct_ov000_02179ed8* entry, char* dst) {
    if (entry != NULL && dst != NULL) {
        int a, b;
        func_0205c508((struct Struct_0205c508*)(obj + 0x1dc), &a, &b);
        int aShifted = a << 24;
        GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(entry->field4c);
        if (combatant != NULL) {
#if defined(jpn)
            int field950 = *(int*)((char*)func_02053c6c((unsigned char*)combatant) + 0x8b8);
#else
            int field950 = *(int*)((char*)func_02053c6c((unsigned char*)combatant) + 0x950);
#endif
            signed char byteVal = entry->field23;
            if (func_ov000_0217542c(obj)) {
                Text_AppendFrameTag(dst, byteVal - (aShifted >> 24), 8, 5, 5, 5);
            }
            Text_AppendCursorTag(dst, byteVal - (aShifted >> 24));
            Text_AppendNTag(dst, byteVal - (aShifted >> 24), (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)(field950 + 0x63)));
        }
    }
}
