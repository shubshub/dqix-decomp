#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneResourceTree.h"

struct Struct_0202b2f0;
struct Struct_0202c1a4;
struct Struct_0207da94;
struct Struct_020e3544;
struct Struct_020e3b08;
struct Struct_0207959c;
struct Struct_0207958c;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void func_0207dba8(void* p);
extern "C" void func_ov017_02190264(void* self, int id);
extern "C" void func_ov000_0215fb04(void* stack, int id);
extern "C" void func_ov017_02192654(int bit, int id, int cond);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int GameState_GetProtagonistIndex(GameState* battleStruct);
void ClearSearchFlagBit0202c600(SearchStruct* obj, int value);
void ClearSearchFlagBit0202c718(SearchStruct* obj, int value);
void LinkSession_RemoveMember(SearchStruct* obj, int value);
Entry0207da94* GetData02108ea8_0207d78c(void);
void ClearByteField17201_0218d500(void* obj);
void ProcessEntries0207da94(Entry0207da94* list, int idx);
Entry020e3544* GetData02153637_020e2ff8(void);
void ClearMatchingEntries020e3544(Entry020e3544* p, int id);
BitEntry020e3b08* GetData02153660_020e3808(void);
void ClearBitInEntries(BitEntry020e3b08* entries, int bit);
int CheckField0x17dBits4And5Equal0207959c(Obj0207959c* obj, int mode);
void ClearField0x17dBits0x38_0207958c(ClearField0x17dBits0x38Struct* s);
void* GetField6b0_021b8470(void* obj);
unsigned short GetField6b4_021b8480(void* obj);

struct Struct_ov017_021905b8 {
    char unknown_0_[6];
    signed char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
};

struct Struct_ov017_021905b8_2 {
    char unknown_0_[0x16a];
    unsigned short unknown_16a_;
};

struct Struct_ov017_021905b8_3 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_021905b8_4 {
    char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021905b8_5 {
#if defined(jpn)
    char unknown_0_[0xe24];
#else
    char unknown1_0_[0xea8];
#endif
    int unknown_ea8_;
};

// USA: func_ov017_021905b8
extern "C" ARM void func_ov017_021905b8(GameResources* self, int id, int remove) {
    GameState* gs = GameState::GetInstance();
    SearchStruct* search = LinkSession_GetInstance();
    if (id <= 0) {
        return;
    }
    if (id == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) || id == GameState_GetLeaderIndex(gs) ||
        id == GameState_GetProtagonistIndex(gs)) {
        ClearSearchFlagBit0202c600(search, id);
        ClearSearchFlagBit0202c718(search, id);
        return;
    }

    Entry0207da94* entries = GetData02108ea8_0207d78c();
    func_0207dba8(entries);
    ClearByteField17201_0218d500(self);
    ClearSearchFlagBit0202c600(search, id);
    ClearSearchFlagBit0202c718(search, id);
    if (remove) {
        LinkSession_RemoveMember(search, id);
    }
    func_ov017_02190264(arg0, arg1);
    func_0207da94(var2, (unsigned char)arg1);

#if defined(jpn)
    Struct_ov017_021905b8* var3 = (Struct_ov017_021905b8*)((char*)var0 + 0x7280);
#else
    Struct_ov017_021905b8* var3 = (Struct_ov017_021905b8*)((char*)var0 + 0x74c0);
#endif
    for (int var4 = 0; var4 < 3; var4++, var3++) {
        if (var3->unknown_6_ == arg1) {
            VectorizedMemset(var3, 0, 6);
            var3->unknown_6_ = -1;
            var3->unknown_7_ = 0;
            var3->unknown_8_ = 0;
            var3->unknown_9_ = -1;
            break;
        }
    }

    func_020e3544(func_020e2ff8(), arg1);

    Struct_ov017_021905b8_3* var5 = (Struct_ov017_021905b8_3*)arg0->unknown_ptr_3718;
    if (var5->unknown_2_ != 0) {
        void* var6 = func_ov017_021b8470(var5);
        if (var6 != NULL) {
            func_ov000_0215fb04(var6, arg1);
        }
    }

    for (int i = 0; i < 0x30; i++) {
        Monster_021905b8* mon = (Monster_021905b8*)gs->GetFieldMonsterByIndex(i + 0x70);
        if (mon != NULL && CheckField0x17dBits4And5Equal0207959c((Obj0207959c*)mon, id)) {
            int cond;
            Zone_021905b8* z = (Zone_021905b8*)self->unknown_ptr_3718;
            cond = 1;
            if (z->active != 0 && GetField6b4_021b8480(z) == 0) {
                ZoneSlot_021905b8* zs = (ZoneSlot_021905b8*)func_ov017_021b8478(z);
                if (zs != NULL && zs->id == mon->id) {
                    ZoneState_021905b8* st = (ZoneState_021905b8*)func_ov017_021b8468(z);
                    if (st != NULL && st->state == 7) {
                        cond = 0;
                    }
                }
            }
            func_ov017_02192654(LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search), mon->id, cond);
            ClearField0x17dBits0x38_0207958c((ClearField0x17dBits0x38Struct*)mon);
        }
    }

    func_020e3b08(func_020e3808(), arg1);
}
