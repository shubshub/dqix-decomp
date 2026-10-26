#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct SearchStruct {
    char pad0[0xfc0];
    int unknown_fc0_;
};

struct SearchStruct0202c1a4;
struct FlagWord020466f4;
struct BitArrayObj0205e854;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int LinkSession_IsSlotLost(SearchStruct* obj, int value);
extern "C" int WH_GetSystemState(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
extern "C" int* func_020936f8(void);
extern "C" void func_020939dc(void* obj);
extern "C" void func_02094030(int*, short, short, signed char);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" int LinkSession_IsSlotConnected(SearchStruct* obj, int value);
extern "C" void LinkSession_End(void* obj);
extern "C" void func_ov017_02195748(unsigned char* base);
extern "C" void func_ov017_02192594(unsigned char* base);
extern "C" void* func_0205e854(BitArrayObj0205e854* obj);

struct Struct_ov017_021af2f8 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2[6];
    unsigned char field8;
    unsigned char unknown_9_[6];
    signed char unknown_f_;
    signed char field10;
};

// USA: func_ov017_021af2f8
extern "C" ARM unsigned char func_ov017_021af2f8(Struct_ov017_021af2f8* obj) {
    GameState::GetInstance();
    unsigned int* flags = (unsigned int*)GetGameResources();
    SearchStruct* search = LinkSession_GetInstance();
    LinkSession_GetReceivedRecord(search, 0);
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)LinkMessageQueue_GetInstance();

    if (LinkSession_IsSlotLost(search, 0) != 0 || WH_GetSystemState() == 8) {
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
        int* g = func_020936f8();
        func_020939dc(g);
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
            if (entry->active == 0) {
                done = 1;
                break;
            }
        }
        if (obj->field10 != LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            obj->unknown_f_ = 0;
        }
    }

    if (obj->unknown_f_ == -1 || done) {
        if (g_keyManager.TestKeysPressed(2)) {
            obj->unknown_f_ = -1;
            SetFlags00((GameResources*)flags, 2);
            LinkSession_End(search);
            func_ov017_02195748((unsigned char*)flags);
            func_ov017_02192594((unsigned char*)flags);
            func_0205e854(bits);
            ClearFlags00((GameResources*)flags, 0x40);
            obj->field1 = 1;
        }
    } else if (obj->unknown_f_ == 1) {
        if (search->unknown_fc0_ == 0) {
            obj->field1 = 1;
        }
    } else {
        SetFlags00((GameResources*)flags, 2);
        LinkSession_End(search);
        func_ov017_02195748((unsigned char*)flags);
        func_ov017_02192594((unsigned char*)flags);
        func_0205e854(bits);
        ClearFlags00((GameResources*)flags, 0x40);
        obj->field1 = 1;
    }
    return obj->field8;
}
