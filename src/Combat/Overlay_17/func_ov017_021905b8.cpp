#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneResourceTree.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct Struct_0207da94;
struct Struct_020e3544;
struct Struct_020e3b08;
struct Struct_0207959c;
struct Struct_0207958c;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void func_0207dba8(void* p);
extern "C" void func_ov017_02190264(void* self, int id);
extern "C" void func_ov000_0215fb04(void* arg0, int id);
extern "C" void func_ov017_02192654(int bit, int id, int cond);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_0202c600(SearchStruct* obj, int value);
extern "C" void func_0202c718(SearchStruct* obj, int value);
extern "C" void LinkSession_RemoveMember(SearchStruct* obj, int value);
extern "C" Struct_0207da94* func_0207d78c(void);
extern "C" void func_ov017_0218d500(void* obj);
extern "C" void func_0207da94(Struct_0207da94* list, int idx);
extern "C" Struct_020e3544* func_020e2ff8(void);
extern "C" void func_020e3544(Struct_020e3544* p, int id);
extern "C" Struct_020e3b08* func_020e3808(void);
extern "C" void func_020e3b08(Struct_020e3b08* entries, int bit);
extern "C" int func_0207959c(Struct_0207959c* obj, int mode);
extern "C" void func_0207958c(Struct_0207958c* s);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" unsigned short func_ov017_021b8480(void* obj);

struct Struct_ov017_021905b8 {
    char data[6];
    signed char owner;
    unsigned char unknown_7_;
    unsigned char f8;
    signed char unknown_9_;
};

struct Monster_021905b8 {
    char pad0[0x16a];
    unsigned short id;
};

struct Struct_ov017_021905b8_3 {
    char pad0[2];
    unsigned char active;
};

struct Struct_ov017_021905b8_4 {
    char pad0[8];
    unsigned short id;
};

struct Struct_ov017_021905b8_5 {
#if defined(jpn)
    char pad0[0xe24];
#else
    char pad0[0xea8];
#endif
    int state;
};

// USA: func_ov017_021905b8
extern "C" ARM void func_ov017_021905b8(GameResources* self, int id, int arg2) {
    GameState* gs = GameState::GetInstance();
    SearchStruct* search = LinkSession_GetInstance();
    if (id <= 0) {
        return;
    }
    if (id == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) || id == GameState_GetLeaderIndex(gs) ||
        id == GameState_GetProtagonistIndex(gs)) {
        func_0202c600(search, id);
        func_0202c718(search, id);
        return;
    }

    Struct_0207da94* entries = func_0207d78c();
    func_0207dba8(entries);
    func_ov017_0218d500(self);
    func_0202c600(search, id);
    func_0202c718(search, id);
    if (arg2) {
        LinkSession_RemoveMember(search, id);
    }
    func_ov017_02190264(self, id);
    func_0207da94(entries, (unsigned char)id);

#if defined(jpn)
    Struct_ov017_021905b8* slot = (Struct_ov017_021905b8*)((char*)gs + 0x7280);
#else
    Struct_ov017_021905b8* slot = (Struct_ov017_021905b8*)((char*)gs + 0x74c0);
#endif
    for (int i = 0; i < 3; i++, slot++) {
        if (slot->owner == id) {
            VectorizedMemset(slot, 0, 6);
            slot->owner = -1;
            slot->unknown_7_ = 0;
            slot->f8 = 0;
            slot->unknown_9_ = -1;
            break;
        }
    }

    func_020e3544(func_020e2ff8(), id);

    Struct_ov017_021905b8_3* zone = (Struct_ov017_021905b8_3*)self->unknown_ptr_3718;
    if (zone->active != 0) {
        void* var6 = func_ov017_021b8470(zone);
        if (var6 != NULL) {
            func_ov000_0215fb04(var6, id);
        }
    }

    for (int i = 0; i < 0x30; i++) {
        Monster_021905b8* mon = (Monster_021905b8*)gs->GetFieldMonsterByIndex(i + 0x70);
        if (mon != NULL && func_0207959c((Struct_0207959c*)mon, id)) {
            int cond;
            Struct_ov017_021905b8_3* z = (Struct_ov017_021905b8_3*)self->unknown_ptr_3718;
            cond = 1;
            if (z->active != 0 && func_ov017_021b8480(z) == 0) {
                Struct_ov017_021905b8_4* var11 = (Struct_ov017_021905b8_4*)func_ov017_021b8478(z);
                if (var11 != NULL && var11->id == mon->id) {
                    Struct_ov017_021905b8_5* st = (Struct_ov017_021905b8_5*)func_ov017_021b8468(z);
                    if (st != NULL && st->state == 7) {
                        cond = 0;
                    }
                }
            }
            func_ov017_02192654(LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search), mon->id, cond);
            func_0207958c((Struct_0207958c*)mon);
        }
    }

    func_020e3b08(func_020e3808(), id);
}
