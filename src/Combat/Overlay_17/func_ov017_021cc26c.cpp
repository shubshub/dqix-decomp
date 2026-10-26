#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

struct Obj02052f44;
extern "C" int GameObject_StartGestureSequence(struct Obj02052f44* obj, signed char* src, int len);

struct Struct_ov017_021cc26c {
    unsigned char pad0[4];
    unsigned char id;
    unsigned char len;
    unsigned char pad6[0xa - 0x6];
    unsigned char flag;
};

// USA: func_ov017_021cc26c
extern "C" ARM void func_ov017_021cc26c(int unused0, Struct_ov017_021cc26c* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    int id = src->id;
    int len = src->len;
    GameObject* combatant = func_0200ff1c(battleStruct, id);
    if (combatant == NULL) return;

    if (src->flag != 0) {
        if (GameObject_IsGesturing((signed char*)combatant) == 0) return;
        func_020531f0(combatant);
        return;
    }

    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    void* h = func_ov017_021b8478(table);
    if (h != NULL) {
        if (func_020a35e0((unsigned char*)h, id & 0xff) != 0) return;
    }
    GameObject_StartGestureSequence((struct Obj02052f44*)combatant, (signed char*)((char*)src + 6), len);
}
