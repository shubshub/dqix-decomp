#if defined(jpn)
enum { Enum_ov017_021a4cf0_1808 = 0x500, Enum_ov017_021a4cf0_1828 = 0x4c4, RegionOffset6fc = 0x4ec };
#else
enum { Enum_ov017_021a4cf0_1808 = 0x710, Enum_ov017_021a4cf0_1828 = 0x724, RegionOffset6fc = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/EntryGetterTypes.h"


extern "C" void* func_0203cf4c(void);
struct Struct_0203dce4_2;
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);
extern "C" int func_02040528(int* obj);
extern "C" int* func_02094d6c(void);
extern "C" void func_02095924(int* g, int val);
extern "C" void* Scenario_GetInstance(void* arg);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
struct Struct_02000c9c_59;
extern "C" void func_ov017_021b8d1c(void* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern int data_ov017_021d76d8;
extern int data_ov017_021d83a8;

struct Struct_ov017_021a4cf0 {
    int f0;
    char pad[0x14 - 0x4];
    int f14;
    char pad2[0x34 - 0x18];
};

// USA: func_ov017_021a4cf0
extern "C" ARM void func_ov017_021a4cf0(char* self) {
    void* list = func_0203cf4c();
    short id = *(short*)((char*)&data_ov017_021d76d8 + 0x2);
    struct Struct_0203dce4* entry = func_0203dce4((struct Struct_0203dce4_2*)list, id);
    if (entry == NULL) {
        return;
    }
    int* field = (int*)func_02040528(&entry->flags);
    if (field == NULL) {
        return;
    }
    void* var4 = *(void**)(self + 0x3000 + Enum_ov017_021a4cf0_1808);
    if (*((unsigned char*)var4 + 0x130) != 0) {
        return;
    }
    int* g = func_02094d6c();
    unsigned short v = *(unsigned short*)field;
    func_02095924(g, v & 0xff);
    GameState* bs = GameState::GetInstance();
    unsigned short v2 = *(unsigned short*)field;
    *(int*)((char*)bs + 0x5000 + Enum_ov017_021a4cf0_1828) = v2;
    void* r = Scenario_GetInstance((char*)bs + 0x5000);
    struct Struct_ov017_021a4cf0 c;
    c.f0 = *(unsigned short*)field;
    c.f14 = *(unsigned short*)&data_ov017_021d83a8;
    if (Scenario_RunTrigger(r, 0, &c)) {
        EventQuery_RunQueuedCommands(&c);
        return;
    }
    func_ov017_021b8d1c(*(void**)(self + 0x3000 + Enum_ov017_021a4cf0_1808));
    *(int*)((char*)(*(void**)(self + 0x3000 + Enum_ov017_021a4cf0_1808)) + 0x114) = (int)field;
    *(int*)((char*)(*(void**)(self + 0x3000 + Enum_ov017_021a4cf0_1808)) + 0x124) = *(unsigned short*)&data_ov017_021d83a8;
    func_020469b4((struct TailList020469b4*)(*(void**)(self + 0x3000 + RegionOffset6fc)),
                      (struct TailNode020469b4*)(*(void**)(self + 0x3000 + Enum_ov017_021a4cf0_1808)));
}
