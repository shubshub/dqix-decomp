#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02171764_1836 = 0x628 };
enum { Enum_ov003_02171764_1824 = 0x61c };
enum { Enum_ov003_02171764_1820 = 0x618 };
enum { Enum_ov003_02171764_686 = 0x28a };
#else
enum { Enum_ov003_02171764_1836 = 0x72c };
enum { Enum_ov003_02171764_1824 = 0x720 };
enum { Enum_ov003_02171764_1820 = 0x71c };
enum { Enum_ov003_02171764_686 = 0x2ae };
#endif

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);

struct SearchStruct;
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);

struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int LinkSession_IsHostOrSolo(struct CheckField0AndGlobalHalfStruct0202c508* obj);

extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" int* func_020936f8(void);
extern "C" void func_02094030(int* a, unsigned short b, short c, unsigned char d);
extern "C" void LinkSession_RemoveMember(struct SearchStruct* obj, int value);

extern "C" void LinkSession_End(void* p);
extern "C" void func_ov003_02171e1c(void*, void*);
extern "C" int func_0205e488(void* obj);

// USA: func_ov003_02171764
extern "C" ARM void func_ov003_02171764(char* self) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    void* dataPtr = LinkMessageQueue_GetInstance();

    if (LinkSession_IsSlotLost(search, *(unsigned char*)(self + 0x199)) != 0) {
        if (LinkSession_IsHostOrSolo((struct CheckField0AndGlobalHalfStruct0202c508*)search) != 0) {
            func_ov017_021d1810(4, -1, 0);
            int* g = func_020936f8();
            func_02094030(g, 4, -1, 0);
        }
        LinkSession_RemoveMember(search, *(unsigned char*)(self + 0x199));
    }

    int fieldVal = battle->GetEffectiveDeltaTime();
    *(int*)(self + Enum_ov003_02171764_1836) = fieldVal;
    if ((unsigned int)fieldVal > 0xbb8) {
        LinkSession_End(search);
        self[0] = 4;
        return;
    }

    if (*(int*)(self + Enum_ov003_02171764_1824) != 0 && *(int*)(self + Enum_ov003_02171764_1820) != 0) {
        func_ov003_02171e1c(self, self + Enum_ov003_02171764_686);
        LinkSession_End(search);
        self[0] = 4;
    }

    if (func_0205e488(dataPtr) != 0) {
        *(int*)(self + Enum_ov003_02171764_1824) = 1;
    }
}
