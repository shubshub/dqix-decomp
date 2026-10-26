#if defined(jpn)
enum { RegionOffset998 = 0x868, RegionOffset6fc = 0x4ec, Enum_ov017_021a7c94_2972 = 0x97c };
#else
enum { RegionOffset998 = 0x998, RegionOffset6fc = 0x6fc, Enum_ov017_021a7c94_2972 = 0xb9c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct TailNode020469b4 { char unk0[2]; unsigned char inList; char unknown_3_; TailNode020469b4* next; };
struct TailList020469b4 { TailNode020469b4* head; TailNode020469b4* tail; };
struct Struct_ov017_021a7c94 { char pad[0x30]; short unknown_30_; short unknown_32_; int f34; };

extern "C" int MessageSystem_GetInstance(void);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void func_ov017_021d0198(int a, int b, int c, int d);
extern "C" void func_ov017_021a7d78(struct Struct_ov017_021a7c94* p);
extern "C" int func_020dc920(int, int, int, int);

// USA: func_ov017_021a7c94
extern "C" ARM void func_ov017_021a7c94(unsigned char* obj, int id, int arg2) {
    GameState* bs = GameState::GetInstance();
    int g = MessageSystem_GetInstance();
    GameObject* combatant = bs->GetLeader();
    int ok = 1;
    if (*(int*)(g + RegionOffset998) != 0) ok = 0;
    if (GameObject_IsGesturing((signed char*)combatant) != 0) ok = 0;
    if (FieldTaskQueue_IsEmpty((void**)*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc)) == 0) ok = 0;
    if (func_020dc920(id & 0xff, 1, 1, 0) == 0) ok = 0;
    int val = GameState_GetProtagonistIndex(bs);
    if (ok) {
        func_ov017_021a7d78(*(struct Struct_ov017_021a7c94**)(obj + 0x3000 + Enum_ov017_021a7c94_2972));
        (*(struct Struct_ov017_021a7c94**)(obj + 0x3000 + Enum_ov017_021a7c94_2972))->f34 = id;
        (*(struct Struct_ov017_021a7c94**)(obj + 0x3000 + Enum_ov017_021a7c94_2972))->unknown_30_ = (short)arg2;
        func_020469b4(*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc), (struct TailNode020469b4*)*(struct Struct_ov017_021a7c94**)(obj + 0x3000 + Enum_ov017_021a7c94_2972));
        func_ov017_021d0198(4, id, val, arg2);
    } else {
        func_ov017_021d0198(5, id, val, arg2);
    }
}
