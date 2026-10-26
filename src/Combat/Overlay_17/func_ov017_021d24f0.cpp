#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02038598_5;
extern "C" int func_02046b60(struct Struct_02038598_5* arg0, int arg1);

struct Struct_02039df4;

struct Struct_0201bdac;
struct Struct_0201bdac_2;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

extern "C" void func_ov017_021c2b28(void* arg0, unsigned char arg1, unsigned char arg2);

struct Struct_ov017_021d24f0 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    char unknown_5_[3];
    int unknown_8_;
};

// USA: func_ov017_021d24f0
extern "C" ARM void func_ov017_021d24f0(void* arg0, Struct_ov017_021d24f0* arg1, GameState* arg2) {
#if defined(jpn)
 enum {Enum_ov017_021d24f0_1788=0x4ec, Enum_ov017_021d24f0_2992=0x990};
#else
 enum {Enum_ov017_021d24f0_1788=0x6fc, Enum_ov017_021d24f0_2992=0xbb0};
#endif
    int base = ((int)GetGameResources());
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)base + 0x3000 + regionalOffset0);
    if (ListContainsId((struct ListHead02046b60*)list, 0xa)) return;
    GameObject* c = battleStruct->GetLeader();
    unsigned short u = ((Object3D*)((struct U16Field0x6_020375f8*)c))->GetField06();
    if (node->field8 != u) return;
    if (ListContainsId((struct ListHead02046b60*)list, 0x1a)) return;
    struct TailNode020469b4* n2 = *(struct TailNode020469b4**)((char*)base + 0x3000 + regionalOffset1);
    if (*((unsigned char*)n2 + 2) != 0) return;
    InitObj021c2b28((void*)n2, 1, node->field4);
    AppendNodeToTail(list, n2);
}
