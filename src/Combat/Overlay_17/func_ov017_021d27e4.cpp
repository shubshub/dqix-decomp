#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" int func_0207c378(void* obj, int value, int amount, int key);
extern "C" void func_02052d7c(void* obj, int index, short value);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021c3fb4(int id, int flag);
extern "C" void func_ov017_021c4418(int id, int flag);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void* MessageSystem_GetInstance();
extern "C" int GameObject_IsGesturing(signed char*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" int func_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_021d27a0(int, int, int);
extern "C" void* func_02079e2c(char*, int);
struct Struct_02048350_2;
extern "C" int func_02048350(struct Struct_02048350_2*, int);

extern "C" void func_ov017_021a5a68();
typedef void (*Type_ov017_021d27e4)(int tag, int first, int second);
typedef void (*Type_ov017_021d27e4_2)(void* obj, int arg);

#if defined(jpn)
enum { MessageActiveOffset = 0x868, Enum_ov017_021d27e4_336 = 0x144 };
#else
enum { MessageActiveOffset = 0x998, Enum_ov017_021d27e4_336 = 0x150 };
#endif

struct Struct_ov017_021d27e4 {
    char pad0[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 14;
    unsigned int active : 1;
    unsigned int rest : 13;
    char unknown_c_[0xc];
    short value;
    unsigned char unknown_1a_[6];
};

struct Struct_ov017_021d27e4_2 {
    unsigned char tag;
    char pad0[3];
    unsigned char type;
    signed char first;
    signed char second;
};

struct Struct_ov017_021d27e4_3 {
    char pad0[8];
    unsigned int low : 8;
};

struct Struct_ov017_021d6d0c {
    signed char slots[11];
};

#if defined(jpn)
extern Struct_ov017_021d6d0c data_ov017_021d7154;
#else
extern Struct_ov017_021d6d0c data_ov017_021d6d0c;
#endif

// USA: func_ov017_021d27e4
extern "C" ARM void func_ov017_021d27e4(void* unused0, Struct_ov017_021d27e4_2* evt, GameState* gs, GameResources* ctx) {
    GameState_GetProtagonistIndex(gs);
    unsigned char* party = static_cast<unsigned char*>(GameState_GetParty(gs));
    signed char first = evt->first;
    signed char second = evt->second;
    unsigned char* ids = party + 0xf78;
    int var4 = 0;
    int var5 = 0;
    int count = party[0xf7c];
    int i;
    for (i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == first) var4 = 1;
        if (id == second) var5 = 1;
    }

    switch (evt->type) {
    case 1: {
        if (!var5) return;
        int ok = 1;
        if ((*reinterpret_cast<int*>(static_cast<char*>(MessageSystem_GetInstance()) + MessageActiveOffset)) != 0) ok = 0;
        if (GameObject_IsGesturing((signed char*)gs->GetLeader()) != 0) ok = 0;
        if (FieldTaskQueue_IsEmpty((void**)ctx->fieldTaskQueue_) == 0) ok = 0;
        if (func_020dc920((unsigned char)first, 1, 1, 0) == 0) ok = 0;
        if (ok) {
            int var10 = 0;
            GameObject* c = func_0200ff1c(gs, second);
            if (c != NULL) {
                if (**(unsigned int**)((char*)c + 0x130) & 4) var10 = 1;
            }
            if (var10) {
                party = static_cast<unsigned char*>(GameState_GetParty(gs));
#if defined(jpn)
                Struct_ov017_021d6d0c map = data_ov017_021d7154;
#else
                Struct_ov017_021d6d0c map = data_ov017_021d6d0c;
#endif
                int done = 0;
                for (int j = 0; j < 11; j++) {
                    if (j == 2 || j == 3 || j == 4) continue;
                    Struct_ov017_021d27e4* slot = reinterpret_cast<Struct_ov017_021d27e4*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(c) + Enum_ov017_021d27e4_336) + 0x194) + (unsigned char)j;
                    if (slot != NULL && slot->active) {
                        func_0207c378((char*)party + 0x1d4, slot->value, 1, slot->unknown_8_0_);
                        func_02052d7c(c, map.slots[j], -1);
                        done = 1;
                    }
                }
                if (done) {
                    func_02048418((unsigned char*)c, 4);
                    func_ov017_021c9e00(second, 0, 0, 1);
                    func_ov017_021c3fb4(second, 1);
                    func_ov017_021c4418(second, -1);
                    GameResources* g = GetGameResources();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(g, second, 1, 0, 0);
                    ((Type_ov017_021d27e4)func_ov017_021d27a0)(2, first, second);
                    return;
                }
            }
        }
        ((Type_ov017_021d27e4)func_ov017_021d27a0)(3, first, second);
        return;
    }
    case 2: {
        if (!var4) return;
        Struct_ov017_021d27e4_3* entry = (Struct_ov017_021d27e4_3*)func_02079e2c((char*)func_020797dc(), 0xd1);
        if (entry != NULL) {
            GameObject* c = func_0200ff1c(gs, first);
            if (c != NULL) {
                func_02048350((struct Struct_02048350_2*)c, entry->low);
                func_ov017_021c9e00(first, 0, 0, 1);
            }
        }
        ((Type_ov017_021d27e4_2)func_ov017_021a5a68)(ctx->unknown_ptr_array_371c[0], 0xb);
        return;
    }
    case 3:
        if (!var4) return;
        ((Type_ov017_021d27e4_2)func_ov017_021a5a68)(ctx->unknown_ptr_array_371c[0], 0xc);
        return;
    }
}
