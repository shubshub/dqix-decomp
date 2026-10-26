#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"

extern "C" {
    void* LinkSession_GetInstance(GrottoStruct* grotto);
    int LinkSession_IsHostOrSolo(void* something);
    void* Zone3D_GetInstance(void);
}

struct FlagWord020466f4;
struct ListHead02046b60;
struct Struct_02093b90_2;

struct Struct_020dc2d0 {
    char pad[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
};

extern "C" void func_020dc214(int mode);
extern "C" int* func_020936f8(void);
extern "C" void func_020941b0(struct Struct_02093b90_2* p);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);

#if defined(jpn)
enum { Enum_020dc2d0_1788 = 0x4ec };
#else
enum { Enum_020dc2d0_1788 = 0x6fc };
#endif

// USA: func_020dc2d0
extern "C" ARM void func_020dc2d0(int mode) {
    GameState* battle = GameState::GetInstance();
    GrottoStruct* grotto = battle->GetGrottoStruct();
    void* something = LinkSession_GetInstance(grotto);
    void* ptr = Zone3D_GetInstance();
    int flag1;
    int flag2;
    Struct_020dc2d0* field8 = *(Struct_020dc2d0**)((char*)ptr + 0x8);

    int base = ((int)GetGameResources());
    flag1 = 0;
    void* list = *(void**)(base + 0x3000 + Enum_020dc2d0_1788);
    flag2 = flag1;

    int var9 = func_02046b60((ListHead02046b60*)list, 0x43);
    if (var9) {
        flag1 = 1;
    }

    if (grotto->unknown_0[0] != 0 && grotto->unknown_0[1] != 0) {
        if (LinkSession_IsHostOrSolo(something) != 0 && field8 != NULL) {
            if (field8->unknown_c_0_ == 0) {
                flag1 = 1;
            }
        }
    }

    if (mode == 1) {
        flag1 = 1;
    } else if (mode == 2) {
        flag1 = 0;
    } else if (mode == 3) {
        flag2 = 1;
    }

    if (flag1) {
        func_020dc214(1);
    } else if (flag2) {
        func_020dc214(2);
    } else {
        func_020dc214(0);
    }

    func_020941b0((Struct_02093b90_2*)func_020936f8());
    FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x41);
}
