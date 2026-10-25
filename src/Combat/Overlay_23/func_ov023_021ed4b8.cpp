#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

int GameState_GetProtagonistIndex(GameState* battleStruct);
int MessageSystem_GetInstance(void);
void NameText_InitFromPartyMember(void* obj, int combatantId);

struct Obj02046574;
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);

extern "C" void func_02046380(void* global);
extern "C" void MessageSystem_FormatText(int a, int b, void* c, void* d, int e, int f, int g);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
void Text_Append(char*, const char*);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Struct_ov023_021ed4b8 { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; };

// USA: func_ov023_021ed4b8
extern "C" ARM void func_ov023_021ed4b8(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021ed4b8_580=0x15c, Enum_ov023_021ed4b8_2400=0x800};
#else
 enum {Enum_ov023_021ed4b8_580=0x244, Enum_ov023_021ed4b8_2400=0x960};
#endif
    unsigned char var0 = ((struct Struct_ov023_021ed4b8*)(arg0 + 0xc0))->unknown_0_0_;
    func_0205de24((struct Struct_0205de24_2*)(arg0 + 0xc4), var0, 3);

    *(unsigned short*)(arg0 + 0x164) = 0x1e;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x166) = 6;
#else
    *(unsigned short*)(arg0 + 0x166) = 0x7;
#endif

    *(unsigned short*)(arg0 + 0x168) = 0x1;
    *(unsigned short*)(arg0 + 0x16a) = 0x9;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x16c) = 0xa;
#else
    *(unsigned short*)(arg0 + 0x16c) = 0x7;
#endif

    *(unsigned short*)(arg0 + 0x16e) = 0xa;
    *(unsigned short*)(arg0 + 0x170) = 0xc;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x172) = 0x14;
#else
    *(unsigned short*)(arg0 + 0x172) = 0xc;
#endif

    *(unsigned char*)(arg0 + 0x17b) = 0xc;
    *(unsigned char*)(arg0 + 0x175) = 2;
    unsigned char var1 = 0;
    *(unsigned char*)(arg0 + 0x179) = var1;
    *(unsigned char*)(arg0 + 0x17a) = var1;

    unsigned char var2 = *(unsigned char*)(arg0 + 0x28);
    char* var3 = *(char**)(arg0 + 0x20);
    char* var4 = var3 + var2 * Enum_ov023_021ed4b8_580;

    memset(*(void**)(arg0 + 0x1c), var1, Enum_ov023_021ed4b8_2400);

#if defined(jpn)
    int key = KeyTable_Get((struct Container020e0310*)(obj + 4), 0x64);
    Text_Append(*(char**)(obj + 0x1c), (char*)key);
    GameState* bs = GameState::GetInstance();
#else
    GameState* var6 = GameState::GetInstance();
#endif

    int id = GameState_GetProtagonistIndex(bs);
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, id);
    if (combatant == NULL) return;

    int g = MessageSystem_GetInstance();
    func_02046380((void*)g);

#if defined(jpn)
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, *(char**)((char*)combatant + 0x134));
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 1, elem + 0xc);

#else
    char localbuf[0xc];
    int combatantId = combatant->obj3D_.actorIndex_;
    NameText_InitFromPartyMember(localbuf, combatantId);

    *(void**)((char*)g + 0x0) = localbuf;
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 1, elem + 0xc);

    int key = KeyTable_Get((struct Container020e0310*)(obj + 0x4), 0x64);
    MessageSystem_FormatText(g, 1, (void*)(long)key, *(void**)(obj + 0x1c), 0xe3, 0, 1);

#endif
#if defined(jpn)
    Window_OpenPane(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0);
#else
    Window_OpenPane(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
