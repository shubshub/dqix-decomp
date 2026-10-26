#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct SearchStruct;

struct SearchStruct0202c1a4;
struct FlagWord020466f4;
struct BitArrayObj0205e854;
struct Struct_0205e870;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void LinkSession_End(void* obj);
extern "C" void func_ov017_02195748(unsigned char* base);
extern "C" void func_ov017_02192594(unsigned char* base);
extern "C" void* func_0205e854(BitArrayObj0205e854* obj);
extern "C" int LinkSession_IsSlotLost(SearchStruct* obj, int value);
extern "C" int WH_GetSystemState(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
extern "C" int* func_020936f8(void);
extern "C" void func_020939dc(void* obj);
extern "C" void func_02094030(int* obj, short a, short b, signed char c);
extern "C" void LinkSession_AddMember(SearchStruct* obj, int value);
extern "C" void* func_0205e870(Struct_0205e870* obj);
extern "C" void func_0205e7dc(unsigned char* obj, int index);
extern "C" void func_ov017_021cc0cc(void);

struct Struct_ov017_021af098 {
    unsigned char pad0;
    unsigned char unknown_1_;
    unsigned char pad2[6];
    unsigned char state;
    unsigned char unknown_9_[6];
    signed char unknown_f_;
    signed char previousSlot;
    unsigned char unknown_11_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021af098
extern "C" ARM unsigned char func_ov017_021af098(Struct_ov017_021af098* obj) {
    GameState* gs = GameState::GetInstance();
    unsigned int* flags = (unsigned int*)GetGameResources();
    SearchStruct* search = LinkSession_GetInstance();
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)LinkMessageQueue_GetInstance();

    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) == 0) {
        LinkSession_GetReceivedRecord(search, 0);
        if (g_keyManager.TestKeysPressed(2)) {
            obj->unknown_f_ = -1;
            SetFlags00((GameResources*)flags, 2);
            LinkSession_End(search);
            func_ov017_02195748((unsigned char*)flags);
            func_ov017_02192594((unsigned char*)flags);
            func_0205e854(bits);
            ClearFlags00((GameResources*)flags, 0x40);
            obj->unknown_1_ = 1;
        } else if (LinkSession_IsSlotLost(search, 0) != 0 || WH_GetSystemState() == 8) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
            int* g = func_020936f8();
            func_020939dc(g);
            func_02094030(g, 4, -1, 0);
            return 3;
        } else {
            obj->unknown_12_ = obj->unknown_12_ + gs->GetEffectiveDeltaTime();
            if (obj->unknown_12_ > 5000) {
                obj->unknown_f_ = 0;
                SetFlags00((GameResources*)flags, 2);
                LinkSession_End(search);
                func_ov017_02195748((unsigned char*)flags);
                func_ov017_02192594((unsigned char*)flags);
                func_0205e854(bits);
                ClearFlags00((GameResources*)flags, 0x40);
                obj->unknown_1_ = 1;
                return obj->state;
            }
        }
        return obj->state;
    }

    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) >= 4) {
        obj->unknown_f_ = 0;
        SetFlags00((GameResources*)flags, 2);
        LinkSession_End(search);
        func_ov017_02195748((unsigned char*)flags);
        func_ov017_02192594((unsigned char*)flags);
        func_0205e854(bits);
        ClearFlags00((GameResources*)flags, 0x40);
        obj->unknown_1_ = 1;
        return obj->state;
    }

    obj->previousSlot = LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search);
    LinkSession_AddMember(search, LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search));
    ClearFlags00((GameResources*)flags, 2);
    func_0205e870((Struct_0205e870*)bits);
    func_0205e7dc((unsigned char*)bits, 0x2c);
    func_0205e7dc((unsigned char*)bits, 0x2a);
    func_0205e7dc((unsigned char*)bits, 0x2e);
    func_0205e7dc((unsigned char*)bits, 0x3d);
    func_0205e7dc((unsigned char*)bits, 0x33);
    func_ov017_021cc0cc();
    obj->unknown_12_ = 0;
    return 2;
}
