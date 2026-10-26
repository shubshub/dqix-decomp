#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

struct S02046b1c;
int GameState_GetProtagonistIndex(GameState* battleStruct);
int GetField0x0List02046b1c(struct S02046b1c* p);
void InitStruct02070378(char*);
struct FieldFlagBlock;
void ResetAndEnableFieldFlag_02011b24(struct FieldFlagBlock* block);

struct Struct_ov017_021cf5d4 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    signed char unknown_6_;
    unsigned char unknown_7_;
};

struct Struct_ov017_021cf5d4_2 {
    short unknown_0_;
    char unknown_2_;
    char unknown_3_[0x70 - 3];
};

// USA: func_ov017_021cf5d4
extern "C" ARM void func_ov017_021cf5d4(void* arg0, struct Struct_ov017_021cf5d4* arg1, GameState* arg2, unsigned char* arg3) {
#if defined(jpn)
 enum {Enum_ov017_021cf5d4_1788=0x4ec};
#else
 enum {Enum_ov017_021cf5d4_1788=0x6fc};
#endif
    int v = GameState_GetProtagonistIndex(battle);
    if (evt->field6 != v) {
        return;
    }
    struct Struct_02046b1c* var1 = *(struct Struct_02046b1c**)(arg3 + 0x3000 + Enum_ov017_021cf5d4_1788);
    if (func_02046b1c(var1) != 0) {
        return;
    }
    struct Struct_ov017_021cf5d4_2 var2;
    func_02070378((char*)&var2);
    var2.unknown_0_ = arg1->unknown_4_;
    var2.unknown_2_ = 1;
    if (arg1->unknown_7_ != 0) {
        func_02011b24((struct Struct_02011b24*)arg2);
    }
    GameState_SetZoneTransition(battle, &buf);
}
