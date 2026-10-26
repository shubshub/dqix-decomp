#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_0202b2f0 {
    char unknown_0_[0xfc0];
    int unknown_fc0_;
};

struct Struct_0202c1a4;
struct Struct_02038598_4;
struct Struct_0205e854;

extern "C" SearchStruct* LinkSession_GetInstance(void);
void* LinkMessageQueue_GetInstance(void);
int LinkSession_IsSlotLost(SearchStruct* obj, int value);
int WH_GetSystemState(void);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
int* GetGlobal02109030_020936f8(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_02094030(int*, short, short, signed char);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
int LinkSession_IsSlotConnected(SearchStruct* obj, int value);
extern "C" void LinkSession_End(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void* FillBitArray0x1524WithFF(BitArrayObj0205e854* obj);

struct Struct_ov017_021af2f8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    unsigned char unknown_8_;
    unsigned char unknown_9_[6];
    signed char unknown_f_;
    signed char unknown_10_;
};

// USA: func_ov017_021af2f8
extern "C" ARM unsigned char func_ov017_021af2f8(Struct_ov017_021af2f8* arg0) {
    GameState::GetInstance();
    unsigned int* flags = (unsigned int*)GetGameResources();
    SearchStruct* search = LinkSession_GetInstance();
    LinkSession_GetReceivedRecord(search, 0);
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)LinkMessageQueue_GetInstance();

    if (LinkSession_IsSlotLost(search, 0) != 0 || WH_GetSystemState() == 8) {
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
        int* g = GetGlobal02109030_020936f8();
        ResetAndSetFlag0x3c9Bit0_020939dc(g);
        func_02094030(g, 4, -1, 0);
        return 3;
    }

    int done = 0;
    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) == 0) {
        done = 1;
    } else {
        for (int i = 0; i < 4; i++) {
            if (i == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
                continue;
            }
            if (LinkSession_IsSlotConnected(search, i) == 0) {
                continue;
            }
            SearchEntry0202c178* entry = LinkSession_GetReceivedRecord(search, i);
            if (entry == 0) {
                continue;
            }
            if (var6->unknown_2_0_ == 0) {
                var4 = 1;
                break;
            }
        }
        if (obj->field10 != LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            obj->fieldF = 0;
        }
    }

    if (arg0->unknown_f_ == -1 || var4) {
        if (g_keyManager.TestKeysPressed(2)) {
            obj->fieldF = -1;
            SetFlags00((GameResources*)flags, 2);
            LinkSession_End(search);
            ClearTwoBytesAtField_02195748((unsigned char*)flags);
            SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
            FillBitArray0x1524WithFF(bits);
            ClearFlags00((GameResources*)flags, 0x40);
            obj->field1 = 1;
        }
    } else if (arg0->unknown_f_ == 1) {
        if (var1->unknown_fc0_ == 0) {
            arg0->unknown_1_ = 1;
        }
    } else {
        SetFlags00((GameResources*)flags, 2);
        LinkSession_End(search);
        ClearTwoBytesAtField_02195748((unsigned char*)flags);
        SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
        FillBitArray0x1524WithFF(bits);
        ClearFlags00((GameResources*)flags, 0x40);
        obj->field1 = 1;
    }
    return arg0->unknown_8_;
}
