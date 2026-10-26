#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_0202b2f0;

struct Struct_0202c1a4;
struct Struct_02038598_4;
struct Struct_0205e854;
struct Struct_0205e870;

extern "C" SearchStruct* LinkSession_GetInstance(void);
void* LinkMessageQueue_GetInstance(void);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void LinkSession_End(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void* FillBitArray0x1524WithFF(BitArrayObj0205e854* obj);
int LinkSession_IsSlotLost(SearchStruct* obj, int value);
int WH_GetSystemState(void);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
int* GetGlobal02109030_020936f8(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_02094030(int* obj, short a, short b, signed char c);
void LinkSession_AddMember(SearchStruct* obj, int value);
void* FillBitArray0x1524WithZero(BitArrayObj0205e870* obj);
void SetBitInArray0x1524_0205e7dc(unsigned char* obj, int index);
void EnqueueEventTag43_021cc0cc(void);

struct Struct_ov017_021af098 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    unsigned char unknown_8_;
    unsigned char unknown_9_[6];
    signed char unknown_f_;
    signed char unknown_10_;
    unsigned char unknown_11_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021af098
extern "C" ARM unsigned char func_ov017_021af098(Obj021af098* obj) {
    GameState* gs = GameState::GetInstance();
    unsigned int* flags = (unsigned int*)GetGameResources();
    SearchStruct* search = LinkSession_GetInstance();
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)LinkMessageQueue_GetInstance();

    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) == 0) {
        LinkSession_GetReceivedRecord(search, 0);
        if (g_keyManager.TestKeysPressed(2)) {
            obj->fieldF = -1;
            SetFlags00((GameResources*)flags, 2);
            LinkSession_End(search);
            ClearTwoBytesAtField_02195748((unsigned char*)flags);
            SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
            FillBitArray0x1524WithFF(bits);
            ClearFlags00((GameResources*)flags, 0x40);
            obj->complete = 1;
        } else if (LinkSession_IsSlotLost(search, 0) != 0 || WH_GetSystemState() == 8) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
            int* g = GetGlobal02109030_020936f8();
            ResetAndSetFlag0x3c9Bit0_020939dc(g);
            func_02094030(g, 4, -1, 0);
            return 3;
        } else {
            obj->elapsedMilliseconds = obj->elapsedMilliseconds + gs->GetEffectiveDeltaTime();
            if (obj->elapsedMilliseconds > 5000) {
                obj->fieldF = 0;
                SetFlags00((GameResources*)flags, 2);
                LinkSession_End(search);
                ClearTwoBytesAtField_02195748((unsigned char*)flags);
                SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
                FillBitArray0x1524WithFF(bits);
                ClearFlags00((GameResources*)flags, 0x40);
                obj->complete = 1;
                return obj->state;
            }
        }
        return arg0->unknown_8_;
    }

    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) >= 4) {
        obj->fieldF = 0;
        SetFlags00((GameResources*)flags, 2);
        LinkSession_End(search);
        ClearTwoBytesAtField_02195748((unsigned char*)flags);
        SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
        FillBitArray0x1524WithFF(bits);
        ClearFlags00((GameResources*)flags, 0x40);
        obj->complete = 1;
        return obj->state;
    }

    obj->previousSlot = LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search);
    LinkSession_AddMember(search, LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search));
    ClearFlags00((GameResources*)flags, 2);
    FillBitArray0x1524WithZero((BitArrayObj0205e870*)bits);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2c);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2a);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2e);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x3d);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x33);
    EnqueueEventTag43_021cc0cc();
    obj->elapsedMilliseconds = 0;
    return 2;
}
