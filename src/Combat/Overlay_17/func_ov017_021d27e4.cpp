#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

extern "C" int func_020dc920(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_0207c378(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_02052d7c(void* arg0, int arg1, short arg2);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov017_021c3fb4(int arg0, int arg1);
extern "C" void func_ov017_021c4418(int arg0, int arg1);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);

int GameState_GetProtagonistIndex(GameState*);
void* GameState_GetParty(GameState*);
void* MessageSystem_GetInstance();
int GameObject_IsGesturing(signed char*);
int FieldTaskQueue_IsEmpty(void**);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
int TryClearFlags0x130_02048418(unsigned char*, unsigned short);
void EnqueueEventTag34_021d27a0(int, int, int);
void* SearchBothTables02079e2c(char*, int);
struct Obj02048350;
int ConsumeCounter02048350(struct Obj02048350*, int);

extern "C" void func_ov017_021a5a68();
typedef void (*Type_ov017_021d27e4)(int tag, int first, int second);
typedef void (*Type_ov017_021d27e4_2)(void* obj, int arg);

#if defined(jpn)
enum { Enum_ov017_021d27e4_2456 = 0x868, Enum_ov017_021d27e4_336 = 0x144 };
#else
enum { Enum_ov017_021d27e4_2456 = 0x998, Enum_ov017_021d27e4_336 = 0x150 };
#endif

struct Struct_ov017_021d27e4 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 14;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    char unknown_c_[0xc];
    short unknown_18_;
    unsigned char unknown_1a_[6];
};

struct Struct_ov017_021d27e4_2 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    unsigned char unknown_4_;
    signed char unknown_5_;
    signed char unknown_6_;
};

struct Struct_ov017_021d27e4_3 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
};

struct Struct_ov017_021d6d0c {
    signed char unknown_0_[11];
};

#if defined(jpn)
extern Struct_ov017_021d6d0c data_ov017_021d7154;
#else
extern Struct_ov017_021d6d0c data_ov017_021d6d0c;
#endif

// USA: func_ov017_021d27e4
extern "C" ARM void func_ov017_021d27e4(void* unused0, Evt021d27e4* evt, GameState* gs, GameResources* ctx) {
    GameState_GetProtagonistIndex(gs);
    unsigned char* party = static_cast<unsigned char*>(GameState_GetParty(gs));
    signed char first = evt->first;
    signed char second = evt->second;
    unsigned char* ids = party + 0xf78;
    int hasFirst = 0;
    int hasSecond = 0;
    int count = party[0xf7c];
    int i;
    for (i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == first) hasFirst = 1;
        if (id == second) hasSecond = 1;
    }

    switch (arg1->unknown_4_) {
    case 1: {
        if (!hasSecond) return;
        int ok = 1;
        if ((*reinterpret_cast<int*>(static_cast<char*>(MessageSystem_GetInstance()) + MessageActiveOffset)) != 0) ok = 0;
        if (GameObject_IsGesturing((signed char*)gs->GetLeader()) != 0) ok = 0;
        if (FieldTaskQueue_IsEmpty((void**)ctx->fieldTaskQueue_) == 0) ok = 0;
        if (func_020dc920((unsigned char)first, 1, 1, 0) == 0) ok = 0;
        if (ok) {
            int flagged = 0;
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, second);
            if (c != NULL) {
                if (**(unsigned int**)((char*)c + 0x130) & 4) flagged = 1;
            }
            if (flagged) {
                party = static_cast<unsigned char*>(GameState_GetParty(gs));
#if defined(jpn)
                Struct_ov017_021d6d0c var12 = data_ov017_021d7154;
#else
                Struct_ov017_021d6d0c var12 = data_ov017_021d6d0c;
#endif
                int var13 = 0;
                for (int var14 = 0; var14 < 11; var14++) {
                    if (var14 == 2 || var14 == 3 || var14 == 4) continue;
                    Struct_ov017_021d27e4* var15 = reinterpret_cast<Struct_ov017_021d27e4*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(var11) + Enum_ov017_021d27e4_336) + 0x194) + (unsigned char)var14;
                    if (var15 != NULL && var15->unknown_a_2_) {
                        func_0207c378((char*)var0 + 0x1d4, var15->unknown_18_, 1, var15->unknown_8_0_);
                        func_02052d7c(var11, var12.unknown_0_[var14], -1);
                        var13 = 1;
                    }
                }
                if (var13) {
                    func_02048418((unsigned char*)var11, 4);
                    func_ov017_021c9e00(var2, 0, 0, 1);
                    func_ov017_021c3fb4(var2, 1);
                    func_ov017_021c4418(var2, -1);
                    GameResources* var16 = GetGameResources();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(var16, var2, 1, 0, 0);
                    ((Type_ov017_021d27e4)func_ov017_021d27a0)(2, var1, var2);
                    return;
                }
            }
        }
        ((Type_ov017_021d27e4)func_ov017_021d27a0)(3, var1, var2);
        return;
    }
    case 2: {
        if (!var4) return;
        Struct_ov017_021d27e4_3* var17 = (Struct_ov017_021d27e4_3*)func_02079e2c((char*)func_020797dc(), 0xd1);
        if (var17 != NULL) {
            GameObject* var18 = func_0200ff1c(arg2, var1);
            if (var18 != NULL) {
                func_02048350((struct Struct_02048350_2*)var18, var17->unknown_8_0_);
                func_ov017_021c9e00(var1, 0, 0, 1);
            }
        }
        ((Type_ov017_021d27e4_2)func_ov017_021a5a68)(arg3->unknown_ptr_array_371c[0], 0xb);
        return;
    }
    case 3:
        if (!var4) return;
        ((Type_ov017_021d27e4_2)func_ov017_021a5a68)(arg3->unknown_ptr_array_371c[0], 0xc);
        return;
    }
}
