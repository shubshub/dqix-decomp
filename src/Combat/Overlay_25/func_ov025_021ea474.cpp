#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f20(void* work);
struct Struct_ov000_0215440c_2;
extern "C" void* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov000_0215440c;
extern "C" void* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" int func_ov025_021ed380(char* obj, unsigned short id, short val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" void func_ov025_021ed350(char* obj, int idx, unsigned short val);
extern "C" void* func_02079e2c(char*, int);

struct Struct_ov025_021ea474 {
    unsigned short type;
    char pad2[0x16];
    unsigned short msgId;
    char pad1a[8];
    unsigned short unknown_22_;
};

struct Struct_ov025_021ea474_2 {
    char pad0[0xe];
    short who;
    char pad10[0x10];
    unsigned short id;
};

struct Struct_ov025_021ea474_3 {
    char pad0[0x138];
    char* stats;
};

struct Struct_ov025_021ea474_4 {
    char pad0[0x18];
    unsigned int f18;
};

// USA: func_ov025_021ea474
extern "C" ARM void func_ov025_021ea474(char* self) {
    if (*(int*)(self + 0x1c4) & 1) return;
    void* gs = GameState::GetInstance();
    Struct_ov025_021ea474* slot = (Struct_ov025_021ea474*)func_ov000_02160f20(func_ov000_02160130());
    if (slot != 0) {
        Struct_ov025_021ea474_2* first = (Struct_ov025_021ea474_2*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
        int who = 0;
        Struct_ov025_021ea474_2* node = (Struct_ov025_021ea474_2*)func_ov000_021600f8((Struct_ov000_0215440c*)slot, who);
        if (node != 0) who = node->who;
        if (slot->type == 0x92 || slot->type == 0x3a1) {
            Struct_ov025_021ea474_3* c = (Struct_ov025_021ea474_3*)((GameState*)gs)->GetCombatantByIndex(first->id);
            if (c != 0) who = *(short*)(c->stats + 0x2a);
        }
        func_ov025_021ed380(self + 0x5e8, slot->msgId, who, 0, 0, -1, 0);
        if (slot->msgId == 0xfa) {
            func_ov025_021ed350(self + 0x5e8, (unsigned short)(*(unsigned char*)(self + 0x738) - 1), 0x1130);
            func_ov025_021ed380(self + 0x5e8, 0x1e0, who, 0, 0, -1, 100);
        }
        Struct_ov025_021ea474_4* e = (Struct_ov025_021ea474_4*)func_02079e2c((char*)func_020797dc(), (short)slot->type);
        if ((e != 0 && ((e->f18 << 16) >> 28) == 2) || slot->type == 0x5c || slot->type == 0x67 ||
            slot->type == 0xa0 || slot->type == 0xbf) {
            func_ov025_021ed380(self + 0x5e8, slot->unknown_22_, who, 0, 0, -1, 0);
            slot->unknown_22_ = 0;
        }
    }
    *(int*)(self + 0x1c4) |= 1;
}
