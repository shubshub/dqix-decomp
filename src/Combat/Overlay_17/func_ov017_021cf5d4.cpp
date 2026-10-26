#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

struct S02046b1c;
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_02046b1c(struct S02046b1c* p);
extern "C" void func_02070378(char*);
struct Struct_02011b24;
extern "C" void func_02011b24(struct Struct_02011b24* block);

struct Struct_ov017_021cf5d4 {
    unsigned char pad0[4];
    unsigned short field4;
    signed char field6;
    unsigned char unknown_7_;
};

struct Struct_ov017_021cf5d4_2 {
    short field0;
    char field2;
    char pad[0x70 - 3];
};

// USA: func_ov017_021cf5d4
extern "C" ARM void func_ov017_021cf5d4(void* unused0, struct Struct_ov017_021cf5d4* evt, GameState* battle, unsigned char* table) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec};
#else
 enum {regionalOffset0=0x6fc};
#endif
    int v = GameState_GetProtagonistIndex(battle);
    if (evt->field6 != v) {
        return;
    }
    struct S02046b1c* list = *(struct S02046b1c**)(table + 0x3000 + regionalOffset0);
    if (func_02046b1c(list) != 0) {
        return;
    }
    struct Struct_ov017_021cf5d4_2 buf;
    func_02070378((char*)&buf);
    buf.field0 = evt->field4;
    buf.field2 = 1;
    if (evt->unknown_7_ != 0) {
        func_02011b24((struct Struct_02011b24*)battle);
    }
    GameState_SetZoneTransition(battle, &buf);
}
