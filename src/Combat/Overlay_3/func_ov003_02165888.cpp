#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_02080cc0;
struct Container02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;

extern "C" int func_02080b54(void* obj, int id);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" int* func_02053c6c(unsigned char* p);
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_02080fe0(void*, int, int);
extern "C" void func_02080fa8(struct Struct_02080fa8*, int, int);
extern "C" void func_0208103c(void*, int, int);
extern "C" void func_02080828(void*, int, short*, short*);
extern "C" void func_020808c8(void*, short, short*, short*);
extern "C" void func_02080854(void*, int, int, int);
extern "C" int KeyTable_Get(struct Container020e0310*, int);
extern "C" void func_02081198(struct Struct_02081198* owner, int id, int enable);
extern "C" void func_02081164(struct Struct_02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

#if defined(jpn)
struct Struct_ov003_02165888_2 {
    char pad[0x16c];
    unsigned short unknown_16c_;
    char unknown_16e_[0x186 - 0x16e];
    unsigned char unknown_186_0_ : 8;
    char unknown_187_[0x49c - 0x187];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x8b8 - 0x49d];
    int unknown_8b8_;
};

struct Struct_ov003_02165888_3 {
    char pad[0x2a];
    short field2a;
};

struct Struct_ov003_02165888 {
    char pad[0x1c4];
    Container020e0310 cont1c4;
    char unknown_1cc_[0x20c - 0x1cc];
    struct Struct_02080cc0* elementObj;
    char unknown_210_[0x290 - 0x210];
    unsigned char unknown_290_[4];
    char unknown_294_[0x2d5 - 0x294];
    unsigned char unknown_2d5_;
    char unknown_2d6_[0x2e5 - 0x2d6];
    unsigned char unknown_2e5_;
};

extern "C" ARM void func_ov003_02165888(Struct_ov003_02165888* self) {
    struct Struct_02080cc0* elementObj = self->elementObj;
    int idA;
    int color;
    int var3;
    int v;
    int key;
    GameState* gs;
    GameObject* member;
    char* nm;
    unsigned char* ids;
    unsigned char count;
    short var11, var12, var13, var14;
    unsigned char i;

    func_02080b54(elementObj, 0x13);
    gs = GameState::GetInstance();

    ids = (unsigned char*)self + 0xd1 + 0x200;
    idA = 0x55;
    self->unknown_2e5_ = (unsigned char)idA;
    count = self->unknown_2d5_;
    var3 = 0xcf;
    memset((unsigned char*)self + 0x290, 0, 4);

    for (i = 0; i < 4; i++) {
        color = 0xf;
        func_02080b2c(elementObj, var3);

        if (i < count) {
            int j;
            struct Struct_ov003_02165888_2* var17;
            member = gs->GetPartyMemberByIndex(ids[i]);
            if (member == 0) continue;

            for (color = 0; color < 3; color++) {
                func_02080b40(elementObj, (short)(idA + color * 4));
            }

            color = func_020dcc98((signed char)ids[i]);
            if (idA == ((struct Struct_ov003_02165888_3*)elementObj)->field2a && color == 0xf) {
                color = 0xa;
            }
            for (j = 0; j < 3; j++) {
                func_02080cc0(elementObj, (short)(idA + j * 4), color);
            }

            v = -1;
            var17 = (struct Struct_ov003_02165888_2*)func_02053c6c((unsigned char*)member);
            ((unsigned char*)self + i)[0x290] = (unsigned char)(var17->unknown_49c_0_ + 1);
            nm = (char*)member->baseStats_;
            func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            if (var17->unknown_8b8_ != 0) {
                v = (short)(var17->unknown_8b8_ + 0x11);
            }
            func_02080fe0(elementObj, (short)(idA + 4), v);
            func_02080fa8(
                (struct Struct_02080fa8*)elementObj, (short)(idA + 8),
                *(unsigned short*)((char*)var17 + var17->unknown_8b8_ * 2 + 0x16c));

            {
                struct Struct_ov003_02165888_2* p3 = *(struct Struct_ov003_02165888_2**)((char*)member + 0x144);
                unsigned char* row = (unsigned char*)p3 + p3->unknown_8b8_;
                unsigned char kind = row[0x186];
                func_0208103c(elementObj, var3, (short)(kind + 0x64));
                if (kind != 0) {
                    color = 5;
                    if (kind == 0xa) {
                        color = 0xd;
                    }
                    func_02080cc0(elementObj, var3, color);
                    func_02080b40(elementObj, var3);
                    key = i + 0x59;
                    func_02080828(elementObj, (short)key, &var11, &var12);
                    func_020808c8(elementObj, key, &var13, &var14);
                    func_02080854(elementObj, var3, (short)(var11 + var13 + 1), (short)(var12 + 2));
                    func_02080cc0(elementObj, var3, color);
                    func_02080b40(elementObj, var3);
                }
            }
        } else {
            if (idA == ((struct Struct_ov003_02165888_3*)elementObj)->field2a) {
                color = 0xa;
            }
            func_02080b40(elementObj, idA);
            nm = (char*)KeyTable_Get(&self->cont1c4, 0x7530);
            func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            func_02080cc0(elementObj, idA, color);
        }

        idA = (short)(idA + 1);
        var3 = (short)(var3 + 1);
    }

    func_02081198((struct Struct_02081198*)elementObj, 0x13, 1);
    func_02081164((struct Struct_02081164*)elementObj, 0x13, 1);
    func_020813ec(elementObj, 0x13);
    func_ov003_02160678(self);
    func_ov003_02160794(self);
}
#else
struct Struct_ov003_02154af4_4 {
    char pad[0x16c];
    unsigned short unknown_16c_;
    char unknown_16e_[0x186 - 0x16e];
    unsigned char unknown_186_0_ : 8;
    char unknown_187_[0x49c - 0x187];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};

struct Struct_ov003_02158334_2 {
    char pad[0x36];
    short unknown_36_;
};

struct Struct_ov003_02165888 {
    char pad[0x2dc];
    Container020e0310 cont2dc;
    char unknown_2e4_[0x324 - 0x2e4];
    struct Struct_02080cc0* elementObj;
    char unknown_328_[0x468 - 0x328];
    unsigned char unknown_468_[4];
    char unknown_46c_[0x4ad - 0x46c];
    unsigned char unknown_4ad_;
    char unknown_4ae_[0x4bd - 0x4ae];
    unsigned char unknown_4bd_;
};

// USA: func_ov003_02165888
extern "C" ARM void func_ov003_02165888(Struct_ov003_02165888* self) {
    struct Struct_02080cc0* elementObj = self->elementObj;
    int idA;
    int color;
    int var24;
    int v;
    int key;
    GameState* gs;
    GameObject* member;
    char* nm;
    unsigned char* ids;
    unsigned char count;
    short var32, var33, var34, var35;
    unsigned char i;
    int var37;

    func_02080b54(elementObj, 0x13);
    gs = GameState::GetInstance();

    ids = (unsigned char*)self + 0xa9 + 0x400;
    idA = 0x55;
    self->unknown_4bd_ = (unsigned char)idA;
    count = self->unknown_4ad_;
    var37 = 0x68;
    var24 = 0xcf;
    memset((unsigned char*)self + 0x68 + 0x400, 0, 4);

    for (i = 0; i < 4; i++) {
        color = 0xf;
        func_02080b2c(elementObj, var24);

        if (i < count) {
            int j;
            struct Struct_ov003_02154af4_4* var39;
            member = gs->GetPartyMemberByIndex(ids[i]);
            if (member == 0) continue;

            for (color = 0; color < 3; color++) {
                func_02080b40(elementObj, (short)(idA + color * 4));
            }
            func_02080b40(elementObj, var37);

            color = func_020dcc98((signed char)ids[i]);
            if (idA == ((struct Struct_ov003_02158334_2*)elementObj)->unknown_36_ && color == 0xf) {
                color = 0xa;
            }
            for (j = 0; j < 3; j++) {
                func_02080cc0(elementObj, (short)(idA + j * 4), color);
            }
            func_02080cc0(elementObj, var37, color);

            v = -1;
            var39 = (struct Struct_ov003_02154af4_4*)func_02053c6c((unsigned char*)member);
            ((unsigned char*)self + i)[0x468] = (unsigned char)(var39->unknown_49c_0_ + 1);
            nm = (char*)member->baseStats_;
            func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            if (var39->unknown_950_ != 0) {
                v = (short)(var39->unknown_950_ + 0x11);
            }
            func_02080fe0(elementObj, (short)(idA + 4), v);
            func_02080fa8(
                (struct Struct_02080fa8*)elementObj, (short)(idA + 8),
                *(unsigned short*)((char*)var39 + var39->unknown_950_ * 2 + 0x16c));

            {
                struct Struct_ov003_02154af4_4* p3 = *(struct Struct_ov003_02154af4_4**)((char*)member + 0x150);
                unsigned char* row = (unsigned char*)p3 + p3->unknown_950_;
                unsigned char kind = row[0x186];
                func_0208103c(elementObj, var24, (short)(kind + 0x64));
                if (kind != 0) {
                    color = 5;
                    if (kind == 0xa) {
                        color = 0xd;
                    }
                    func_02080cc0(elementObj, var24, color);
                    func_02080b40(elementObj, var24);
                    key = i + 0x59;
                    func_02080828(elementObj, (short)key, &var32, &var33);
                    func_020808c8(elementObj, key, &var34, &var35);
                    func_02080854(elementObj, var24, (short)(var32 + var34 + 1), var33);
                    func_02080cc0(elementObj, var24, color);
                    func_02080b40(elementObj, var24);
                }
            }
        } else {
            if (idA == ((struct Struct_ov003_02158334_2*)elementObj)->unknown_36_) {
                color = 0xa;
            }
            func_02080b40(elementObj, idA);
            nm = (char*)KeyTable_Get(&self->cont2dc, 0x7530);
            func_02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            func_02080cc0(elementObj, idA, color);
        }

        idA = (short)(idA + 1);
        var24 = (short)(var24 + 1);
        var37 = (short)(var37 + 1);
    }

    func_02081198((struct Struct_02081198*)elementObj, 0x13, 1);
    func_02081164((struct Struct_02081164*)elementObj, 0x13, 1);
    func_020813ec(elementObj, 0x13);
    func_ov003_02160678(self);
    func_ov003_02160794(self);
}
#endif
