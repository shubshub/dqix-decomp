#if defined(jpn)
enum { Enum_ov017_02199578_17480 = 0x4198, Enum_ov017_02199578_17476 = 0x4194, Enum_ov017_02199578_17481 = 0x4199, Enum_ov017_02199578_17477 = 0x4195 };
#else
enum { Enum_ov017_02199578_17480 = 0x4448, Enum_ov017_02199578_17476 = 0x4444, Enum_ov017_02199578_17481 = 0x4449, Enum_ov017_02199578_17477 = 0x4445 };
#endif

#include <globaldefs.h>


extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" void* Scenario_GetInstance(void);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
void ResetFieldGroup4444_0218b664(char* base);

struct Struct_0202c1a4 {
    char unknown_0_[0x100d];
    unsigned char unknown_100d_;
};

struct Struct_ov017_02199578 { char unknown_0_[0x34]; };

// USA: func_ov017_02199578
#pragma opt_common_subs off
extern "C" ARM void func_ov017_02199578(void* obj, int unused1, int matchType, int unused2, signed char flag) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)LinkSession_GetInstance();
    signed char arrEntry = LinkSession_GetOwnSlot(search);
    if (matchType != arrEntry && matchType != 4) return;

    if (!*((unsigned char*)arg0 + Enum_ov017_02199578_17480)) return;

    LinkSession_UpdateMemberCount(search);

    int var2 = *((unsigned char*)arg0 + Enum_ov017_02199578_17476) + 1;
    *((unsigned char*)arg0 + Enum_ov017_02199578_17476) = (unsigned char)var2;
    if ((var2 & 0xff) >= var0->unknown_100d_ - 1) *((unsigned char*)arg0 + Enum_ov017_02199578_17480) = 0;

    if (!flag) {
        *((unsigned char*)obj + RegionOffset4449) = 0;
        void* list = Scenario_GetInstance();
        LocalBuf02199578 c;
        if (Scenario_RunTrigger(list, 0x1d, &c)) {
            EventQuery_RunQueuedCommands(&c);
        }
        func_ov017_0218b664((char*)arg0);
        return;
    }

    int var5 = *((unsigned char*)arg0 + Enum_ov017_02199578_17477) + 1;
    *((unsigned char*)arg0 + Enum_ov017_02199578_17477) = (unsigned char)var5;
    if ((var5 & 0xff) < var0->unknown_100d_ - 1) return;

    *((unsigned char*)obj + RegionOffset4449) = 1;
    void* list2 = Scenario_GetInstance();
    LocalBuf02199578 c2;
    if (Scenario_RunTrigger(list2, 0x1d, &c2)) {
        EventQuery_RunQueuedCommands(&c2);
    }
    func_ov017_0218b664((char*)arg0);
}
