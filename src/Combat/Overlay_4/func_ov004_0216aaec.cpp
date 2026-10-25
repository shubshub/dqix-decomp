#include <globaldefs.h>

#if defined(jpn)
enum { kTextBytes = 0x800, kPanelOffset = 9 };
#define MessageSystem_FormatText func_020474a8
#else
enum { Enum_ov004_0216aaec_2400 = 0x960, Enum_ov004_0216aaec_4 = 4 };
#endif

#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"


struct Struct_ov004_02170138 {
    int unknown_0_[7];
};

struct Struct_ov004_0216aaec {
    char unknown_0_[0x8c];
    unsigned char unknown_8c_[0x234];
};

struct Struct_ov004_0216aaec_2 {
    char unknown_0_[4];
    SafeAllocator unknown_4_;
};

struct Struct_ov004_0216aaec_3 {
    char unknown_0_[0x20];
    void* unknown_20_;
};

struct Struct_02072a68_2;
struct Struct_020465c0;
struct Struct_02021410;
struct Struct_020213fc;

extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int GetField5cbcValue_0201081c(char* state);
extern "C" struct Allocated0216aaec* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" struct Node0216aaec* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" struct TableA68* func_ov023_021fa598(void* obj);
struct StoreStruct* MessageSystem_GetInstance(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* arg0);
extern "C" void func_02046380(struct Struct_020465c0* arg0);
extern "C" void func_020465c0(struct Struct_020465c0* arg0, int arg1, int arg2);
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);
#if defined(jpn)
extern "C" void MessageSystem_FormatText(struct StoreStruct* a, int b, void* c, void* d);
#else
extern "C" void MessageSystem_FormatText(struct StoreStruct* a, int b, void* c, void* d, int e, int f, int g);
#endif
extern "C" void func_ov023_021f8960(char* arg0, short arg1, unsigned short arg2);
extern "C" void func_02021410(struct Struct_02021410* arg0, int arg1, int arg2);
extern "C" void func_020213fc(struct Struct_020213fc* arg0, int arg1);

extern struct Struct_ov004_02170138 data_ov004_02170138;

// USA: func_ov004_0216aaec
extern "C" ARM int func_ov004_0216aaec(void* a) {
    GameState* state = GameState::GetInstance();
    struct Ctx0216aaec* ctx = (struct Ctx0216aaec*)Scenario_GetInstance();
    struct IdList0216aaec list = data_ov004_02170138;
    unsigned char count = 0;
    int i;
    for (i = 0; i < 7; i++) {
        if (Scenario_TestFlag((int)ctx, ctx->bits, list.ids[i])) {
            count++;
        }
    }
    int var5 = func_0201081c((char*)var0);

    struct Struct_ov004_0216aaec_2* var6 = func_ov011_021845f8(arg0, 4);
    if (var6 == 0) {
        return 0;
    }
    var6->unknown_4_.GetSizeWithLargestBlockRemoved();
#if defined(jpn)
    void* var10 = var6->unknown_4_.Allocate(4);
#endif

    struct Struct_ov004_0216aaec_3* var7 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x192);
    if (var7 == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(var7) != 4) {
        return 0;
    }
    struct TableA68* table = func_ov023_021fa598(node);
    struct StoreStruct* g = MessageSystem_GetInstance();
#if !defined(jpn)
    void* var10 = var6->unknown_4_.Allocate(4);
#endif
    if (func_0202c540(func_0202ae18()) != 0) {
        var5 = 1000;
    }
    memset(var10, 0, Enum_ov004_0216aaec_2400);
    func_02046380(var9);
    func_020465c0(var9, 0, var3);
#if defined(jpn)
    MessageSystem_FormatText(g, 0xc, FindEntryByKey_02072a68(table, (short)key), buf);
#else
    MessageSystem_FormatText(g, 0xc, FindEntryByKey_02072a68(table, (short)key), buf, 0xd7, 0, 1);
#endif

    struct Struct_ov004_0216aaec_3* var11 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
    if (var11 != 0) {
        var11->unknown_20_ = var10;
    }

    struct Struct_ov004_0216aaec_3* var12 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc8);
    if (var12 != 0 && func_ov023_021f6f10(var12) == 6) {
        func_ov023_021f8960((char*)var12, 0, Enum_ov004_0216aaec_4);
    }

    struct Struct_02021410* var13 = (struct Struct_02021410*)GetGameResources()->unknown_ptr_36d0;
    func_02021410(var13, 1, 0);
    func_020213fc((struct Struct_020213fc*)var13, 0);
    return 0;
}
