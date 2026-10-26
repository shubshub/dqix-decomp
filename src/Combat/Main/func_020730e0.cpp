#if defined(jpn)
enum { Enum_020730e0_340 = 0x148 };
#else
enum { Enum_020730e0_340 = 0x154 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_02053c6c(unsigned char* obj);

struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);

extern "C" unsigned short (*CharacterColors_GetInstance(void))[2];

struct Struct_0206f81c;
extern "C" void* func_02083554(struct Struct_0206f81c* c, int id);

struct Obj020de2a4;
extern "C" int ItemRecord_GetPaletteSize(struct Obj020de2a4* obj, int a, int b);

extern "C" void func_02072afc(int id, int* arr, short* arr2);
extern "C" void func_02099d34(void* obj, int a, int b, int c);
extern "C" void func_02099e18(void* obj, int a, int b, int c);

struct Struct_020730e0_3 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 3;
    unsigned char unknown_0_4_ : 4;
};
struct Struct_020730e0_4 {
    unsigned char unknown_0_0_ : 4;
    unsigned char rest : 4;
};
struct Struct_020730e0 {
    unsigned char pad[0x14];
    struct Struct_020730e0_3 b14;
    struct Struct_020730e0_4 unknown_15_;
};

// USA: func_020730e0
extern "C" ARM void func_020730e0(int id, int index) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant;
    int var2;
    struct Struct_020730e0* table;
    int nibble;
    GameObject* combatant2;
    void* var6;
    int bufA[11];
    short var8[12];

    if (id < 0) {
        id = GameState_GetProtagonistIndex(bs);
    }

    combatant = func_0200ff1c(bs, id);
    if (!combatant || *(int*)((char*)combatant + Enum_020730e0_340) == 0) {
        return;
    }

    var2 = func_02053c6c((unsigned char*)combatant);
    if (var2 == 0) {
        return;
    }

    table = (struct Struct_020730e0*)func_02052e2c((struct Field150Holder02052e2c*)combatant);
    CharacterColors_GetInstance();

    func_02072afc(id, bufA, var8);
    if (var8[index] < 0) {
        return;
    }

    {
        void* entry = func_02083554((struct Struct_0206f81c*)var2, var8[index]);
        if (!entry) {
            return;
        }
        nibble = ItemRecord_GetPaletteSize((struct Obj020de2a4*)entry, 1, table->b14.bit0);
    }

    combatant2 = bs->GetGameObjectByIndex(bufA[index]);
    if (!combatant2) {
        return;
    }

    switch (index) {
        case 0:
        case 1:
        case 5:
        case 6:
        case 7:
            var6 = combatant2->obj3D_.pModel_;
            func_02099d34(var6, nibble, table->b14.unknown_0_1_, 4);
            break;
        case 4:
            var6 = combatant2->obj3D_.pModel_;
            func_02099d34(var6, nibble, table->b14.unknown_0_1_, 0x10);
            break;
        case 2:
            var6 = combatant2->obj3D_.pModel_;
            func_02099e18(var6, table->b14.unknown_0_1_, table->unknown_15_.unknown_0_0_, table->b14.unknown_0_4_);
            break;
        default:
            break;
    }
}
