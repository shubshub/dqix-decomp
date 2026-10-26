#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, Enum_ov017_0218d0ec_1816 = 0x508 };
#else
enum { RegionOffset6fc = 0x6fc, Enum_ov017_0218d0ec_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"



extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" int func_0201201c(void* obj);

struct Struct_ov017_0218d0ec_3;

extern "C" void func_ov017_021cdaa0(void);
extern "C" int func_ov017_021b8b54(void* obj);

struct Struct_ov017_0218d0ec_4 { unsigned char pad0[0x94]; float accum; int tableIndex; };

struct Struct020fb3f0 { unsigned char pad0[8]; unsigned char* field8; };
struct Struct_ov017_0218d0ec_2 { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; };

// USA: func_ov017_0218d0ec
extern "C" ARM void func_ov017_0218d0ec(unsigned char* ov) {
    GameState* bs = GameState::GetInstance();
    Struct020fb3f0* p1 = (Struct020fb3f0*)Zone3D_GetInstance();
    void* p2 = LinkSession_GetInstance();

    if (FieldTaskQueue_GetCurrentKind(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 3) return;
    if (func_0200fb9c((char*)bs) == 6) return;
    if (func_0201201c(bs) == 5) return;

    Struct_ov017_0218d0ec_2* nb = (Struct_ov017_0218d0ec_2*)(p1->field8 + 0xc);
    unsigned int nibble = nb->unknown_0_0_;
    int var5 = 1;
    if (nibble != 0 && nibble != 7) var5 = 0;

    int idx1 = bs->GetTimeOfDay();
    if (var5 != 0) {
        ((GameState*)((struct Struct_ov017_0218d0ec_3*)bs))->AdvanceDayTimer();
    }

    int idx2 = bs->GetTimeOfDay();
    if (LinkSession_IsHostOrSolo(p2) != 0 && idx1 != idx2) {
        func_ov017_021cdaa0();
    }

    if (FieldTaskQueue_GetCurrentKind(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 0xa) {
        if (func_ov017_021b8b54(*(void**)(ov + 0x3000 + Enum_ov017_0218d0ec_1816)) != 0) return;
    }
    if (FieldTaskQueue_GetCurrentKind(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 4) return;
    if (FieldTaskQueue_GetCurrentKind(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 0x16) return;

    Struct_ov017_0218d0ec_4* d = (Struct_ov017_0218d0ec_4*)LightingManager::GetInstance();
    int var9 = d->tableIndex;
    if (var9 != bs->GetTimeOfDay()) {
        if (bs->GetTimeOfDay() == 1 || bs->GetTimeOfDay() == 0) {
            void* base = Scenario_GetInstance();
            Scenario_SetFlag(base, (unsigned char*)base + 0x8c, 0x1140, 1);
        }
    }

    d->accum = bs->GetDayTimer();
    d->tableIndex = bs->GetTimeOfDay();
}
