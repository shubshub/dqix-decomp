#if defined(jpn)
enum { Enum_ov017_0219bd1c_1804 = 0x4fc, RegionOffset6fc = 0x4ec };
#else
enum { Enum_ov017_0219bd1c_1804 = 0x70c, RegionOffset6fc = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Field3f8Struct;
extern "C" Field3f8Struct* GameState_GetZoneTransition(GameState* bs);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" unsigned char func_ov017_0219bcac(unsigned char v);
extern "C" void FieldTask_InitEnterZone(unsigned char* node, int v);
struct HeadList020469f8;
struct HeadNode020469f8;
extern "C" void func_020469f8(struct HeadList020469f8* list, struct HeadNode020469f8* node);
struct List02046a3c;
struct Node02046a3c;
extern "C" void func_02046a3c(struct List02046a3c* list, struct Node02046a3c* node);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_0219bd1c_2 {
    char pad[2];
    unsigned char flag2;
    unsigned char unknown_3_;
};

struct Field3f8Struct0219bd1c {
    char pad0[2];
    unsigned char unknown_2_;
    char pad1[0x6e - 3];
    unsigned char unknown_6e_;
};

// USA: func_ov017_0219bd1c
extern "C" ARM void func_ov017_0219bd1c(int arg0, unsigned char sb, int arg2, unsigned char arg3) {
    GameState* bs = GameState::GetInstance();
    void* var1 = GetGameResources();
    char* ctx = (char*)var1 + 0x3000;
    struct Field3f8Struct0219bd1c* field;
    void* list = *(void**)(ctx + RegionOffset6fc);
    struct Struct_ov017_0219bd1c_2* node = *(struct Struct_ov017_0219bd1c_2**)(ctx + Enum_ov017_0219bd1c_1804);
    field = (struct Field3f8Struct0219bd1c*)GameState_GetZoneTransition(bs);
    if (node->unknown_3_) return;
    if (node->flag2) {
        func_02046a8c(list, node);
    }
    func_ov017_0219bcac(arg3);
    field->unknown_2_ = 0;
    field->unknown_6e_ = sb;
    FieldTask_InitEnterZone((unsigned char*)node, 0);
    if (arg0) {
        func_020469f8((struct HeadList020469f8*)list, (struct HeadNode020469f8*)node);
    } else if (arg2) {
        func_02046a3c((struct List02046a3c*)list, (struct Node02046a3c*)node);
    } else {
        func_020469b4((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
    }
    ClearFlags00((GameResources*)var1, 4);
}
