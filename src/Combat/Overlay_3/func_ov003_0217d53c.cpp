#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217d53c_267 = 0x107 };
enum { Enum_ov003_0217d53c_14076 = 0x34ec };
enum { Enum_ov003_0217d53c_2464 = 0x870 };
enum { Enum_ov003_0217d53c_14132 = 0x3524 };
enum { Enum_ov003_0217d53c_14092 = 0x34fc };
#else
enum { Enum_ov003_0217d53c_267 = 0x10b };
enum { Enum_ov003_0217d53c_14076 = 0x36fc };
enum { Enum_ov003_0217d53c_2464 = 0x9a0 };
enum { Enum_ov003_0217d53c_14132 = 0x3734 };
enum { Enum_ov003_0217d53c_14092 = 0x370c };
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" char* MessageSystem_GetInstance(void);
extern "C" char* Zone3D_GetInstance(void);
extern "C" int func_020457e0(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int arg);
extern "C" void* GameState_GetZoneTransition(GameState* state);
extern "C" void func_02070378(char* obj);

struct Progress02012fe4 {
#if defined(jpn)
    unsigned char pad0[0x1b3c];
#else
    unsigned char pad0[0xb3c];
#endif
    int chapter;
};

#if !defined(jpn)
static inline struct Progress02012fe4* GetProgress(void* run) {
    return (struct Progress02012fe4*)((int)run + 0x1840);
}
#endif

struct Struct_ov003_0217d53c {
    unsigned char pad0[0x8];
    unsigned short messageId;
    unsigned char padA[Enum_ov003_0217d53c_267 - 0xa];
    unsigned char active;
};

struct EventRecord_0217d53c {
    unsigned short id;
    unsigned char pad2[0x7 - 0x2];
    unsigned char unknown_7_;
    unsigned char pad8[0xc - 0x8];
    unsigned char unknown_c_;
    unsigned char padD[0x14 - 0xd];
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov003_0217d53c_3 {
    unsigned char pad0[0x4];
    unsigned char state;
    signed char busy;
};

// USA: func_ov003_0217d53c
extern "C" ARM void func_ov003_0217d53c(Struct_ov003_0217d53c_3* self) {
    GameState* gs = GameState::GetInstance();
    char* global = MessageSystem_GetInstance();
    char* res = (char*)GetGameResources();
    struct TailList020469b4* list = *(struct TailList020469b4**)(res + Enum_ov003_0217d53c_14076);
#if defined(jpn)
    Progress02012fe4* current = (Progress02012fe4*)(Zone3D_GetInstance() + 0x860);
#else
    char* current = Zone3D_GetInstance();
#endif
    if (self->busy != 0 || *(int*)(global + Enum_ov003_0217d53c_2464) != 0) return;
    if (func_020457e0(global) == 0) {
        Struct_ov003_0217d53c* event = *(Struct_ov003_0217d53c**)(res + Enum_ov003_0217d53c_14132);
        func_ov017_021baedc(event, 1);
        event->active = 1;
        switch (
#if defined(jpn)
            current->chapter
#else
            GetProgress(current)->chapter
#endif
        ) {
            case 0:
            case 1:
            case 2:
                event->messageId = 0xd067;
                break;
            case 3:
            case 4:
                event->messageId = 0xd068;
                break;
            case 5:
                event->messageId = 0xd069;
                break;
            case 6:
                event->messageId = 0xd06a;
                break;
        }
        func_020469b4(list, (struct TailNode020469b4*)event);
        unsigned char* header = *(unsigned char**)(res + Enum_ov003_0217d53c_14092);
        FieldTask_InitEnterZone(header, 0);
        EventRecord_0217d53c* record = (EventRecord_0217d53c*)GameState_GetZoneTransition(gs);
        func_02070378((char*)record);
        record->id = 0xc3bc;
        record->unknown_7_ = 1;
        record->unknown_14_ = 0x266;
        record->unknown_18_ = -0x7b33;
        record->unknown_c_ = 1;
        func_020469b4(list, (struct TailNode020469b4*)header);
        self->state = 4;
        self->busy = 0;
    } else {
        self->state = 4;
        self->busy = 0;
    }
}
