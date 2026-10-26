#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);

struct U16Field0x6_020375f8;

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void func_ov017_021c2b28(void* objRaw, unsigned char a, unsigned char b);

struct Struct_ov017_021d24f0 {
    char pad0[4];
    unsigned char field4;
    char pad1[3];
    int field8;
};

// USA: func_ov017_021d24f0
extern "C" ARM void func_ov017_021d24f0(void* unused0, Struct_ov017_021d24f0* node, GameState* battleStruct) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x990};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0xbb0};
#endif
    int base = ((int)GetGameResources());
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)base + 0x3000 + regionalOffset0);
    if (func_02046b60((struct ListHead02046b60*)list, 0xa)) return;
    GameObject* c = battleStruct->GetLeader();
    unsigned short u = ((Object3D*)((struct U16Field0x6_020375f8*)c))->GetField06();
    if (node->field8 != u) return;
    if (func_02046b60((struct ListHead02046b60*)list, 0x1a)) return;
    struct TailNode020469b4* n2 = *(struct TailNode020469b4**)((char*)base + 0x3000 + regionalOffset1);
    if (*((unsigned char*)n2 + 2) != 0) return;
    func_ov017_021c2b28((void*)n2, 1, node->field4);
    func_020469b4(list, n2);
}
