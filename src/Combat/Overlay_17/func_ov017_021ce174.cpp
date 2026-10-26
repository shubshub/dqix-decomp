#include <globaldefs.h>



struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);
extern "C" void* Scenario_GetInstance(void);
extern "C" void GameState_SetStoryChapter(char* obj, int v);
extern "C" void GameState_SetStoryPart(char* obj, int v);
extern "C" void GameState_SetStoryStep(char* base, int val);
extern "C" void func_0206e080(char* base, int index);
extern "C" void func_0206e0d0(char* base, int index);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

struct Struct_ov017_021ce174 {
    char pad0[4];
    unsigned char unknown_4_0_ : 7;
    unsigned char flag7 : 1;
    short val6;
    unsigned short bit8;
};

// USA: func_ov017_021ce174
extern "C" ARM void func_ov017_021ce174(void* unused, struct Struct_ov017_021ce174* obj, char* target, int arg3, struct SearchStruct0202c1a4* search) {
    if (!obj->flag7) {
        if (LinkSession_GetOwnSlot(search) == 0) {
            return;
        }
    }

    unsigned char* base = (unsigned char*)Scenario_GetInstance();

    switch (obj->unknown_4_0_) {
    case 0:
        GameState_SetStoryChapter(target, obj->val6);
        GameState_SetStoryPart(target, 1);
        GameState_SetStoryStep(target, 1);
        func_0206e080((char*)base, base[0x332]);
        break;
    case 1:
        GameState_SetStoryPart(target, obj->val6);
        GameState_SetStoryStep(target, 1);
        func_0206e0d0((char*)base, base[0x332]);
        break;
    case 2:
        GameState_SetStoryStep(target, obj->val6);
        break;
    case 3:
        Scenario_SetFlag(base, base + 0x8c, obj->bit8, obj->val6);
        break;
    case 4:
        Scenario_SetFlag(base, base + base[0x332] * 0x1c + 0x3, obj->bit8, obj->val6);
        break;
    case 5:
        Scenario_SetFlag(base, base + base[0x332] * 0x1c + 0x10, obj->bit8, obj->val6);
        break;
    default:
        break;
    }
}
