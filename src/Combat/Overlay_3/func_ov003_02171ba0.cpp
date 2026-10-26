#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02171ba0_1820 = 0x618 };
enum { Enum_ov003_02171ba0_1836 = 0x628 };
enum { Enum_ov003_02171ba0_1828 = 0x620 };
#else
enum { Enum_ov003_02171ba0_1820 = 0x71c };
enum { Enum_ov003_02171ba0_1836 = 0x72c };
enum { Enum_ov003_02171ba0_1828 = 0x724 };
#endif

struct SearchStruct;
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int LinkSession_IsSlotLost(struct SearchStruct*, int);
extern "C" void LinkSession_RemoveMember(struct SearchStruct*, int);
extern "C" void LinkSession_End(void*);

struct Struct_0202bad4;
struct Struct_0202bad4_2;
extern "C" Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2*, int);

extern "C" void func_ov003_02171e1c(void*, void*);
extern "C" int func_0205e488(void*);

struct Struct_ov003_02171ba0 {
    unsigned char field0;
    char pad1[0x199 - 1];
    unsigned char field199;
    char pad2[Enum_ov003_02171ba0_1820 - 0x19a];
    int field71c;
    int unknown_720_;
    char pad3[Enum_ov003_02171ba0_1836 - Enum_ov003_02171ba0_1828];
    unsigned int unknown_72c_;
};

// USA: func_ov003_02171ba0
extern "C" ARM void func_ov003_02171ba0(struct Struct_ov003_02171ba0* obj) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* searchPtr = (struct SearchStruct*)LinkSession_GetInstance();
    void* ptr2 = LinkMessageQueue_GetInstance();

    if (LinkSession_IsSlotLost(searchPtr, obj->field199)) {
        LinkSession_RemoveMember(searchPtr, obj->field199);
    }
    obj->unknown_72c_ += battle->GetEffectiveDeltaTime();
    if (obj->unknown_72c_ > 0xbb8) {
        LinkSession_End(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (LinkSession_IsSlotLost(searchPtr, 0) && obj->field71c == 0) {
        func_0202bad4((struct Struct_0202bad4_2*)searchPtr, obj->field199);
        LinkSession_End(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (obj->unknown_720_ != 0 && obj->field71c != 0) {
        struct Struct_0202bad4* elem = func_0202bad4((struct Struct_0202bad4_2*)searchPtr, obj->field199);
        func_ov003_02171e1c(obj, (char*)elem + 0x68);
        LinkSession_End(searchPtr);
        obj->field0 = 0;
    }
    if (func_0205e488(ptr2) != 0) {
        obj->unknown_720_ = 1;
    }
}
