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

extern "C" SearchStruct* func_0202ae18(void);
void* GetData02100044_0202ae24(void);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
extern "C" void func_0202b0f4(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void* FillBitArray0x1524WithFF(BitArrayObj0205e854* obj);
int TestFlagBitAt0xe_0202c578(SearchStruct* obj, int value);
int GetGlobalField0x10_0202d6a8(void);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
int* GetGlobal02109030_020936f8(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_02094030(int* obj, short a, short b, signed char c);
void SetSearchFlagBitAt0xc_0202c1e8(SearchStruct* obj, int value);
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
extern "C" ARM unsigned char func_ov017_021af098(Struct_ov017_021af098* arg0) {
    GameState* var0 = GameState::GetInstance();
    unsigned int* var1 = (unsigned int*)GetGameResources();
    Struct_0202b2f0* var2 = func_0202ae18();
    Struct_0205e854* var3 = (Struct_0205e854*)func_0202ae24();

    if (func_0202c1a4((Struct_0202c1a4*)var2) == 0) {
        func_0202c178(var2, 0);
        if (g_keyManager.TestKeysPressed(2)) {
            obj->fieldF = -1;
            SetFlags00((GameResources*)flags, 2);
            func_0202b0f4(search);
            ClearTwoBytesAtField_02195748((unsigned char*)flags);
            SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
            FillBitArray0x1524WithFF(bits);
            ClearFlags00((GameResources*)flags, 0x40);
            obj->complete = 1;
        } else if (TestFlagBitAt0xe_0202c578(search, 0) != 0 || GetGlobalField0x10_0202d6a8() == 8) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
            int* g = GetGlobal02109030_020936f8();
            ResetAndSetFlag0x3c9Bit0_020939dc(g);
            func_02094030(g, 4, -1, 0);
            return 3;
        } else {
            arg0->unknown_12_ = arg0->unknown_12_ + var0->GetEffectiveDeltaTime();
            if (arg0->unknown_12_ > 5000) {
                arg0->unknown_f_ = 0;
                SetFlags00((GameResources*)var1, 2);
                func_0202b0f4(var2);
                func_ov017_02195748((unsigned char*)var1);
                func_ov017_02192594((unsigned char*)var1);
                func_0205e854(var3);
                ClearFlags00((GameResources*)var1, 0x40);
                arg0->unknown_1_ = 1;
                return arg0->unknown_8_;
            }
        }
        return arg0->unknown_8_;
    }

    if (func_0202c1a4((Struct_0202c1a4*)var2) >= 4) {
        arg0->unknown_f_ = 0;
        SetFlags00((GameResources*)var1, 2);
        func_0202b0f4(var2);
        func_ov017_02195748((unsigned char*)var1);
        func_ov017_02192594((unsigned char*)var1);
        func_0205e854(var3);
        ClearFlags00((GameResources*)var1, 0x40);
        arg0->unknown_1_ = 1;
        return arg0->unknown_8_;
    }

    arg0->unknown_10_ = func_0202c1a4((Struct_0202c1a4*)var2);
    func_0202c1e8(var2, func_0202c1a4((Struct_0202c1a4*)var2));
    ClearFlags00((GameResources*)var1, 2);
    func_0205e870((Struct_0205e870*)var3);
    func_0205e7dc((unsigned char*)var3, 0x2c);
    func_0205e7dc((unsigned char*)var3, 0x2a);
    func_0205e7dc((unsigned char*)var3, 0x2e);
    func_0205e7dc((unsigned char*)var3, 0x3d);
    func_0205e7dc((unsigned char*)var3, 0x33);
    func_ov017_021cc0cc();
    arg0->unknown_12_ = 0;
    return 2;
}
