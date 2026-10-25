#if defined(jpn)
#define func_02045f3c func_02046c78
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#endif
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct ItemTable;
struct Field150Holder02052e14;
struct CombatObject { char pad[LOW_REGION(0x4f8, 0x4fc)]; int index; };
struct NameSprite {
#if defined(jpn)
    unsigned short unknown_0_[10];
#else
    char unknown1_0_[0x80];
#endif
};
struct CombatDisplay { char pad0[0xdf4]; ItemTable* container; char pad1[LOW_REGION(0x2f38, 0x2fc0)]; unsigned char state; char pad2[3]; unsigned char selected; char pad3[0xc7]; NameSprite names[8]; unsigned char raised[8]; };
void* MessageSystem_GetInstance();
short* GetField150Ptr0x488(Field150Holder02052e14*);
void* ItemTable_Find(ItemTable*, int);
CombatObject* GetField1c_021a193c(int*);
#if defined(jpn)
extern "C" void func_02045f3c(void*, unsigned short*, int, int, int, int, int, int);
#else
extern "C" void func_02045f3c(void*, Struct_ov005_0215b0a0*, int, int, int, int, int, int, int, int);
#endif
extern unsigned char data_ov005_0215cbfc[];
#define REG_GEOMETRY ((volatile unsigned int*)0x04000444)
#define REG_END (*(volatile unsigned int*)0x04000504)

// USA: func_ov005_0215b0a0
extern "C" ARM void func_ov005_0215b0a0(CombatDisplay* display) {
    void* renderer = MessageSystem_GetInstance();
    GameState* game = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->index);
    if (!combatant) return;
    short* effects = GetField150Ptr0x488((Field150Holder02052e14*)combatant);
    int y = LOW_REGION(29, 28);
#if defined(jpn)
    int var6;
#endif
    if (arg0->unknown_3db8_ == 0) {
        for (int var5 = 0; var5 < 8; var5++) {
#if defined(jpn)
            if (ItemTable_Find(display->container, effects[data_ov005_0215cbfc[i]])) color = 0x7fff;
            else color = 0x3def;
#else
            int color = ItemTable_Find(display->container, effects[data_ov005_0215cbfc[i]]) ? 0x7fff : 0x3def;
#endif
            if (var5 == arg0->unknown_3dbc_) var6 = 0xf0a;
            int var7 = var5 * 24;
#if !defined(jpn)
            if (arg0->unknown_4284_[var5]) var7 -= 5;
#endif
            REG_GEOMETRY[0] = 0;
            REG_GEOMETRY[0x2f] = 1;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0xffc01000;
#if defined(jpn)
            func_02045f3c(var0, arg0->unknown_3e84_[var5].unknown_0_, 160, var7 + 7, var6, 10, 0, 0);
#else
            func_02045f3c(var0, &arg0->unknown_3e84_[var5], 160, var7 + 6, var6, 10, 0, 0, 0, 9);
#endif
            REG_GEOMETRY[0x30] = 0;
            REG_GEOMETRY[1] = 1;
        }
    } else {
#if defined(jpn)
        if (ItemTable_Find(display->container, effects[data_ov005_0215cbfc[display->selected]])) color = 0x7fff;
        else color = 0x3def;
#else
        int color = ItemTable_Find(display->container, effects[data_ov005_0215cbfc[display->selected]]) ? 0x7fff : 0x3def;
#endif
        if (arg0->unknown_3db8_ == 3) var6 = 0xf0a;
#if !defined(jpn)
        if (arg0->unknown_4284_[arg0->unknown_3dbc_]) var4 -= 5;
#endif
        REG_GEOMETRY[0] = 0;
        REG_GEOMETRY[0x2f] = 1;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0xffc01000;
#if defined(jpn)
        func_02045f3c(var0, arg0->unknown_3e84_[arg0->unknown_3dbc_].unknown_0_, 160, var4, var6, 10, 0, 0);
#else
        func_02045f3c(var0, &arg0->unknown_3e84_[arg0->unknown_3dbc_], 160, var4, var6, 10, 0, 0, 0, 9);
#endif
        REG_END = 0;
        REG_GEOMETRY[1] = 1;
    }
}
