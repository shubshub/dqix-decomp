#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_0216aaec_2400 = 0x800, Enum_ov004_0216aaec_4 = 9 };
#define MessageSystem_FormatText func_020474a8
#else
enum { Enum_ov004_0216aaec_2400 = 0x960, Enum_ov004_0216aaec_4 = 4 };
#endif

#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"


struct Struct_ov004_02170138 {
    int ids[7];
};

struct Ctx0216aaec {
    char pad[0x8c];
    unsigned char bits[0x234];
};

struct Struct_ov004_0216aaec_2 {
    char pad[4];
    SafeAllocator allocator;
};

struct Struct_ov004_0216aaec_3 {
    char pad[0x20];
    void* buffer;
};

struct TableA68;
struct StoreStruct;
struct Struct_02021410;
struct SetFlagStruct;

extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int func_0201081c(char* state);
extern "C" struct Struct_ov004_0216aaec_2* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" struct Struct_ov004_0216aaec_3* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" struct TableA68* func_ov023_021fa598(void* obj);
extern "C" struct StoreStruct* MessageSystem_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" void func_02046380(struct StoreStruct* g);
extern "C" void func_020465c0(struct StoreStruct* s, int index, int value);
extern "C" void* func_02072a68(struct TableA68* table, int key);
#if defined(jpn)
extern "C" void MessageSystem_FormatText(struct StoreStruct* a, int b, void* c, void* d);
#else
extern "C" void MessageSystem_FormatText(struct StoreStruct* a, int b, void* c, void* d, int e, int f, int g);
#endif
extern "C" void func_ov023_021f8960(char* base, short a, unsigned short b);
extern "C" void func_02021410(struct Struct_02021410* s, int a, int b);
extern "C" void MapDisplay_SetHoldSubScreenDark(struct SetFlagStruct* p, int value);

extern struct Struct_ov004_02170138 data_ov004_02170138;

// USA: func_ov004_0216aaec
extern "C" ARM int func_ov004_0216aaec(void* a) {
    GameState* state = GameState::GetInstance();
    struct Ctx0216aaec* ctx = (struct Ctx0216aaec*)Scenario_GetInstance();
    struct Struct_ov004_02170138 list = data_ov004_02170138;
    unsigned char count = 0;
    int i;
    for (i = 0; i < 7; i++) {
        if (Scenario_TestFlag((int)ctx, ctx->bits, list.ids[i])) {
            count++;
        }
    }
    int key = func_0201081c((char*)state);

    struct Struct_ov004_0216aaec_2* alloc = func_ov011_021845f8(a, 4);
    if (alloc == 0) {
        return 0;
    }
    alloc->allocator.GetSizeWithLargestBlockRemoved();
#if defined(jpn)
    void* buf = alloc->allocator.Allocate(4);
#endif

    struct Struct_ov004_0216aaec_3* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x192);
    if (node == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node) != 4) {
        return 0;
    }
    struct TableA68* table = func_ov023_021fa598(node);
    struct StoreStruct* g = MessageSystem_GetInstance();
#if !defined(jpn)
    void* buf = alloc->allocator.Allocate(4);
#endif
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
        key = 1000;
    }
    memset(buf, 0, Enum_ov004_0216aaec_2400);
    func_02046380(g);
    func_020465c0(g, 0, count);
#if defined(jpn)
    MessageSystem_FormatText(g, 0xc, func_02072a68(table, (short)key), buf);
#else
    MessageSystem_FormatText(g, 0xc, func_02072a68(table, (short)key), buf, 0xd7, 0, 1);
#endif

    struct Struct_ov004_0216aaec_3* holder = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
    if (holder != 0) {
        holder->buffer = buf;
    }

    struct Struct_ov004_0216aaec_3* panel = func_ov023_021f6880(func_ov011_021849c8(a), 0xc8);
    if (panel != 0 && func_ov023_021f6f10(panel) == 6) {
        func_ov023_021f8960((char*)panel, 0, Enum_ov004_0216aaec_4);
    }

    struct Struct_02021410* toggle = (struct Struct_02021410*)GetGameResources()->unknown_ptr_36d0;
    func_02021410(toggle, 1, 0);
    MapDisplay_SetHoldSubScreenDark((struct SetFlagStruct*)toggle, 0);
    return 0;
}
