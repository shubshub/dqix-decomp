#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02171af0_1836 = 0x628 };
#else
enum { Enum_ov003_02171af0_1836 = 0x72c };
#endif

#if defined(jpn)
extern "C" void func_ov003_021714f0(void*);
#endif
#include "GameState/GameState.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct Struct_ov003_021714f0;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void* p);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void LinkSession_AddMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" void func_ov003_02172518(struct Struct_ov003_021714f0* obj, int flag);

struct Struct_ov003_02171af0 {
    unsigned char field0;
    char pad1[0x199 - 1];
    unsigned char field199;
    char pad2[0x1b1 - 0x19a];
    unsigned char unknown_1b1_0_ : 6;
    unsigned char unknown_1b1_6_ : 1;
    unsigned char unknown_1b1_7_ : 1;
    char pad3[Enum_ov003_02171af0_1836 - 0x1b2];
    unsigned int unknown_72c_;
};

// USA: func_ov003_02171af0
extern "C" ARM void func_ov003_02171af0(struct Struct_ov003_02171af0* obj) {
    GameState* battle = GameState::GetInstance();
    void* ptr = LinkSession_GetInstance();

    obj->unknown_72c_ += battle->GetEffectiveDeltaTime();
    if (obj->unknown_72c_ > 0xbb8) {
        LinkSession_End(ptr);
        obj->unknown_72c_ = 0;
        obj->field0 = 0;
    }

    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)ptr) <= 0) {
        return;
    }

    signed char entry = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)ptr);
    LinkSession_AddMember((struct SearchStruct*)ptr, entry);
    LinkSession_AddMember((struct SearchStruct*)ptr, obj->field199);
    LinkSession_UpdateMemberCount(ptr);

#if defined(jpn)
    func_ov003_021714f0(obj);
#else
    int flag = obj->unknown_1b1_6_ ? 1 : 0;
    func_ov003_02172518((struct Struct_ov003_021714f0*)obj, flag);
#endif
    obj->field0 = 7;
}
