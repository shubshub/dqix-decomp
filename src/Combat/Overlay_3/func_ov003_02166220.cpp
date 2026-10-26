#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_02080cc0;
struct Container02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;
struct Struct020865b0;
struct Struct_ov003_0215f56c_3;
struct Struct_ov003_02165c9c_5;

extern "C" int func_02080b54(void* obj, int id);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov003_02166164(Struct_ov003_02165c9c_5*, int, int);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
#if defined(jpn)
extern "C" short PartyMemberRecord_GetVocation(Struct020865b0*);
#else
extern "C" int PartyMemberRecord_GetVocation(Struct020865b0*);
#endif
extern "C" int func_ov003_0215f56c(Struct_ov003_0215f56c_3*);
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
extern "C" int func_02080b40(void*, int);
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_02080fe0(void*, int, int);
extern "C" void func_02080fa8(struct Struct_02080fa8*, int, int);
extern "C" void func_0208103c(void*, int, int);
extern "C" void func_02080828(void*, int, short*, short*);
extern "C" void func_020808c8(void*, short, short*, short*);
extern "C" void func_02080854(void*, int, int, int);
extern "C" int KeyTable_Get(struct Container020e0310*, int);
extern "C" void func_ov003_0215f5e8(void* menu, int page, int count);
extern "C" void func_ov003_02160c58(void* self, short* arg1, short* arg2);
extern "C" void func_02081198(struct Struct_02081198* owner, int id, int enable);
extern "C" void func_02081164(struct Struct_02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

struct Struct_ov003_02166220 {
    char pad0[2];
    unsigned char unk2[0xd];
    unsigned char unkF[0x140 - 0xf];
    char name[0x34];
    unsigned char bit0 : 1;
    char unknown_175_[0x23c - 0x175];
};

struct Party02166220 {
    char pad0[0xf7c];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0xf80 - 0xf7d];
    Struct_ov003_02166220 members[(0x2c8c - 0xf80) / 0x23c];
    char pad[0x2c8c - 0xf80 - ((0x2c8c - 0xf80) / 0x23c) * 0x23c];
    unsigned char count;
};

struct Struct_ov003_02166220_3 {
    short v[2];
};

struct Struct_ov003_0217f3ec_3 {
#if defined(jpn)
    char pad[0x14];
#else
    char pad[0x20];
#endif
    Struct_ov003_02166220_3 ids;
};

extern Struct_ov003_0217f3ec_3 data_ov003_0217f3ec;

struct Struct_ov003_02166220_4 {
#if defined(jpn)
    char pad[0x1c4];
    Container020e0310 cont2dc;
    char unknown_1cc_[0x20c - 0x1cc];
    struct Struct_02080cc0* elementObj;
    char unknown_210_[0x290 - 0x210];
    unsigned char unknown_468_[4];
    char unknown_294_[0x2c7 - 0x294];
    signed char page;
    char unknown_2c8_[0x2e5 - 0x2c8];
    unsigned char unknown_4bd_;
#else
    char pad[0x2dc];
    Container020e0310 cont2dc;
    char unknown_2e4_[0x324 - 0x2e4];
    struct Struct_02080cc0* elementObj;
    char unknown_328_[0x39c - 0x328];
    char names[4][0x30];
    char unknown_45c_[0x468 - 0x45c];
    unsigned char unknown_468_[4];
    char unknown_46c_[0x49f - 0x46c];
    signed char page;
    char unknown_4a0_[0x4bd - 0x4a0];
    unsigned char unknown_4bd_;
#endif
};

struct Struct_ov003_02166220_5 {
#if defined(jpn)
    char pad[0x2a];
#else
    char pad[0x36];
#endif
    short unknown_36_;
};

// USA: func_ov003_02166220
extern "C" ARM void func_ov003_02166220(Struct_ov003_02166220_4* self) {
    struct Struct_02080cc0* elementObj = self->elementObj;
    Party02166220* party;
    short count;
    Struct_ov003_02166220* entry;
    short var4;
#if defined(jpn)
    short v;
#else
    int v;
#endif
    int k;
    short row;
    int idA;
    int color;
    int var10;
    short i;
    int off;
    short j;
    int key;
    unsigned char kind;
    short var16, var17, var18, var19;
    short var20, var21;
    Struct_ov003_02166220_3 ids;

    func_02080b54(elementObj, 6);
    party = (Party02166220*)GameState_GetParty(GameState::GetInstance());
    count = party->count;
    idA = 0x15;
    var4 = 100;
    row = self->page * 4;
    self->unknown_4bd_ = (unsigned char)idA;
    v = -1;
    var10 = 0xcb;
    memset(self->unknown_468_, 0, 4);
    func_ov003_02166164((Struct_ov003_02165c9c_5*)self, count > 4, 1);
#if !defined(jpn)
    memset(self->names, 0, sizeof(self->names));
#endif

    for (i = 0; i < 4; i++) {
        entry = &party->members[row];
#if defined(jpn)
        func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)entry->name);
#else
        off = i * 0x30;
        Font_DecodeText(entry->name, (char*)self->names + off, 1);
        func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)&self->names[0][off]);
#endif
        if (PartyMemberRecord_GetVocation((Struct020865b0*)entry) != 0) {
            v = (short)(PartyMemberRecord_GetVocation((Struct020865b0*)entry) + 0x11);
        }
        func_02080fe0(elementObj, (short)(idA + 4), v);
        func_02080fa8((struct Struct_02080fa8*)elementObj, (short)(idA + 8),
                                                             entry->unk2[PartyMemberRecord_GetVocation((Struct020865b0*)entry)]);
        color = func_ov003_0215f56c((Struct_ov003_0215f56c_3*)entry);
        if (idA == ((struct Struct_ov003_02166220_5*)elementObj)->unknown_36_ && color == 0xf) {
            color = 0xa;
        }
        if (row < count) {
            for (j = 0; j < 3; j++) {
                k = idA + j * 4;
                ((void (*)(struct Struct_02080cc0*, short, int))func_02080cc0)(elementObj, k, color);
                func_02080b40(elementObj, (short)k);
            }
#if !defined(jpn)
            func_02080cc0(elementObj, var4, color);
            func_02080b40(elementObj, var4);
#endif
            self->unknown_468_[i] = entry->bit0 + 1;
            kind = entry->unkF[PartyMemberRecord_GetVocation((Struct020865b0*)entry)];
            func_0208103c(elementObj, var10, (short)(kind + 100));
            if (kind != 0) {
                color = 5;
                if (kind == 0xa) {
                    color = 0xd;
                }
                key = i + 0x19;
                func_02080828(elementObj, (short)key, &var16, &var17);
                func_020808c8(elementObj, key, &var18, &var19);
#if defined(jpn)
                func_02080854(elementObj, var10, (short)(var16 + var18 + 1), (short)(var17 + 2));
#else
                func_02080854(elementObj, var10, (short)(var16 + var18 + 1), var17);
#endif
                func_02080cc0(elementObj, var10, color);
                func_02080b40(elementObj, var10);
            }
        } else {
            func_02080cc0(elementObj, idA, color);
            func_02080b40(elementObj, idA);
            func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)KeyTable_Get(&self->cont2dc, 0x7530));
        }
        row++;
        idA = (short)(idA + 1);
        var10 = (short)(var10 + 1);
#if !defined(jpn)
        var4++;
#endif
    }

    func_ov003_0215f5e8(elementObj, self->page, count);
    func_ov003_02160c58(self, &var20, &var21);
    party = (Party02166220*)GameState_GetParty(GameState::GetInstance());
    var21 = var21 - (party->unknown_f7c_ - 1);
    func_02080fa8((struct Struct_02080fa8*)elementObj, 0x23, var21);
    func_02080fa8((struct Struct_02080fa8*)elementObj, 0x24, var20);

    ids = data_ov003_0217f3ec.ids;
    for (int n = 0; n < 2; n++) {
        short id = ids.v[n];
        func_02081198((struct Struct_02081198*)elementObj, id, 1);
        func_02081164((struct Struct_02081164*)elementObj, id, 1);
        func_020813ec(elementObj, id);
    }
    func_ov003_02160678(self);
    func_ov003_02160794(self);
}
