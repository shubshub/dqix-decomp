#include <globaldefs.h>


extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
struct Struct_02061c04_11;
extern "C" void func_ov017_021b994c(struct Struct_02061c04_11* obj);

struct SearchStruct0202c1a4 {
    char pad[0x100d];
    unsigned char unknown_100d_;
};

struct Struct_02061c04_11 {
    char pad[0x12c];
    unsigned int field12c;
    unsigned char unknown_130_;
    unsigned char unknown_131_;
    unsigned char unknown_132_;
    unsigned char unknown_133_;
    char pad2[0x136 - 0x134];
    unsigned char unknown_136_;
};

struct Struct_ov017_021b9a98 { char pad[0x34]; };

// USA: func_ov017_021b9a98
extern "C" ARM void func_ov017_021b9a98(Struct_02061c04_11* obj, int unused1, unsigned char arg2, unsigned char arg3, unsigned short flag) {
    SearchStruct0202c1a4* search = (SearchStruct0202c1a4*)LinkSession_GetInstance();
    signed char arrEntry = LinkSession_GetOwnSlot(search);
    if (arg2 != arrEntry && arg2 != 4) return;

    if (obj->unknown_130_ == 0) return;

    LinkSession_UpdateMemberCount(search);

    int cnt = obj->unknown_131_ + 1;
    obj->unknown_131_ = (unsigned char)cnt;
    if ((cnt & 0xff) >= search->unknown_100d_ - 1) obj->unknown_130_ = 0;

    if (obj->unknown_136_ == 0) {
        if (flag == 0) {
            obj->unknown_133_ = 0;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list = Scenario_GetInstance();
            Struct_ov017_021b9a98 c;
            if (Scenario_RunTrigger(list, 0x1a, &c)) {
                EventQuery_RunQueuedCommands(&c);
            }
            func_ov017_021b994c(obj);
            obj->unknown_136_ = 1;
        } else {
            int var5 = obj->unknown_132_ + 1;
            obj->unknown_132_ = (unsigned char)var5;
            if ((var5 & 0xff) < search->unknown_100d_ - 1) return;

            obj->unknown_133_ = 1;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list2 = Scenario_GetInstance();
            Struct_ov017_021b9a98 c2;
            if (Scenario_RunTrigger(list2, 0x1a, &c2)) {
                EventQuery_RunQueuedCommands(&c2);
            }
            func_ov017_021b994c(obj);
            obj->unknown_136_ = 1;
        }
    }
}
