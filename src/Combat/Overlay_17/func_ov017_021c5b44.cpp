#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" GameObject* func_ov017_021a278c(void* unused, int val);
struct ListHead02046b38;
struct ListNode02046b38;
extern "C" int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* obj, int combatantId);
extern "C" void func_ov017_021b7104(unsigned char* dst, void* src);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_021c5b44 {
#if defined(jpn)
    unsigned char pad0[0x4ec];
#else
    unsigned char pad0[0x6fc];
#endif
    void* unknown_6fc_;
    unsigned char pad2[0x718 - 0x6fc - 4];
    void* unknown_718_;
};

struct Struct_ov017_021c5b44_2 {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned short field4;
    unsigned char pad6[2];
    unsigned int field8;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short field10;
    unsigned char field12;
    unsigned char unknown_13_;
    unsigned int field14;
};

// USA: func_ov017_021c5b44
extern "C" ARM void func_ov017_021c5b44(unsigned char arg0, int combatantId, unsigned int arg2, unsigned char arg3, unsigned char arg4) {
    GameState::GetInstance();
    void* var0 = (void*)(int)((int)GetGameResources());
    struct Struct_ov017_021c5b44* ctx = (struct Struct_ov017_021c5b44*)((char*)var0 + 0x3000);
    int id2 = -1;
    void* list = ctx->unknown_6fc_;
    void* node = ctx->unknown_718_;

    GameObject* combatant = func_ov017_021a278c(var0, combatantId);
    if (combatant != 0) {
        id2 = combatant->obj3D_.actorIndex_;
    }

    if (!func_02046b38((struct ListHead02046b38*)list, (struct ListNode02046b38*)node)) {
        func_ov017_021b6f18(node);

        struct Struct_ov017_021c5b44_2 buf;
        func_ov017_02196c08((unsigned char*)&buf);

        buf.field0 = 0;
        buf.field1 = arg0;
        buf.field4 = combatantId;
        buf.field2 = id2;
        buf.field8 = arg2;
        buf.unknown_f_ = arg3;

        func_ov017_021b6e70(&buf, id2);

        buf.field12 = arg4;

        func_ov017_021b7104((unsigned char*)node, &buf);

        func_020469b4((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
    }
}
