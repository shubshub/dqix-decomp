#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;
struct Struct_02088514;

struct Struct_ov000_02182b44 {
    short v[8];
};

struct Struct_ov000_0215a23c {
    char pad[4];
    unsigned short f4;
};

struct Struct_ov000_0215a23c_2 {
    char pad[0x29c];
    unsigned int lo : 4;
    unsigned int kind : 5;
    unsigned int rest : 23;
    char pad2[0x2ac - 0x2a0];
    short unknown_2ac_;
};

struct Struct_ov000_0215a23c_3 {
    char pad[0x138];
    Struct_ov000_0215a23c* stats;
#if defined(jpn)
    char pad2[0x144 - 0x13c];
#else
    char pad2[0x150 - 0x13c];
#endif
    unsigned char* f150;
};

extern "C" {
extern const Struct_ov000_02182b44 data_ov000_02182b44;
extern const Struct_ov000_02182b44 data_ov000_02182b54;
void __clear(void* buf, int n);
int func_ov000_0215e9fc(void* self, short* buf, int max, int start);
int func_ov000_0215eb1c(void* self, short* buf, int max, int start);
void func_ov000_0215c758(void* self, short* targets, int count, int kind, short* arg4, short* arg5,
                         unsigned long long* bits);
short func_ov000_0215a004(void* self, int src, int id, int value, unsigned long long* bits, int a5, int a6, int a7);
int func_ov000_02159dbc(void* self, int id);
extern "C" Struct_ov000_0215a23c_3* func_0200fea4(GameState* gs, int id);
extern "C" Struct_ov000_0215a23c_2* func_02053c6c(Struct_ov000_0215a23c_3* unit);
}

extern "C" int func_ov000_0215fc60(char* base);
extern "C" int func_02085230(unsigned char* slots);
extern "C" int func_ov000_02158324(GameObject* c);
extern "C" int func_ov000_0215830c(GameObject* c);
extern "C" int GameObject_GetPartyMemberLevel(void* c);
extern "C" short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3);
extern "C" short func_ov000_0215a1d4(void* unused, int id, int delta, short* arg3);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_02088514(Struct_02088514* obj);
float NextRandomFloatBetween(Random* random, float minimum, float maximum);

static inline Struct_ov000_0215a23c_3* inline_ov000_021537b8_2(int id) {
    GameState* gs = GameState::GetInstance();
    return (Struct_ov000_0215a23c_3*)gs->GetCombatantByIndex(id);
}

static inline Struct_ov000_0215a23c_3* inline_ov000_0215a23c(int id) {
    GameState* gs = GameState::GetInstance();
    return func_0200fea4(gs, id);
}

// USA: func_ov000_0215a23c
extern "C" ARM void func_ov000_0215a23c(void* self) {
    if (func_ov000_0215fc60((char*)self) != 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    Struct_ov000_02182b44 targets = data_ov000_02182b44;
    short var2[8];
    short var3[8];
    unsigned long long bits[8];
    __clear(var2, sizeof(var2));
    __clear(var3, sizeof(var3));
    __clear(bits, sizeof(bits));
    short* res = var2;
    short* tgt = targets.v;
    short* var7 = var3;
    unsigned long long* var8 = bits;
    short n = 0;
    Struct_ov000_02182b44 idBuf = data_ov000_02182b54;
    short* ids = idBuf.v;
    int count = func_ov000_0215e9fc(self, ids, 8, 1);

    for (int i = 0; i < count; i++) {
        Struct_ov000_0215a23c_3* c = (Struct_ov000_0215a23c_3*)func_0200ff1c(gs, ids[i]);
        if (c != 0) {
            int amount = 0;
            if (func_02085230(c->f150)) {
                amount += 0x19;
            }
            if (func_ov000_02158324((GameObject*)c)) {
                int bonus = 10;
                int half = GameObject_GetPartyMemberLevel(c) >> 1;
                if (half > 10) {
                    bonus = half;
                }
                amount += bonus;
            }
            if (amount > 0) {
                res[n] = func_ov000_0215a16c(self, ids[i], amount, &var3[n]);
                tgt[n] = ids[i];
                bits[n] = 0;
                bits[n] |= 0x4000000000ULL;
                if (var3[n] > 0) {
                    n++;
                }
            }
        }
    }
    if (n > 0) {
        func_ov000_0215c758(self, tgt, n, 0, res, var7, var8);
    }

    n = 0;
    for (int i = 0; i < count; i++) {
        Struct_ov000_0215a23c_3* c = (Struct_ov000_0215a23c_3*)func_0200ff1c(gs, ids[i]);
        if (c == 0) {
            continue;
        }
        Struct_ov000_0215a23c_2* f = func_02053c6c(c);
        if (f == 0) {
            continue;
        }
        int amount = 0;
        if (func_ov000_0215830c((GameObject*)c)) {
            amount = GameObject_GetPartyMemberLevel(c) / 10;
            if (amount < 3) {
                amount = 3;
            }
        }
        if (func_02083b00(c->f150, 0x3f) && f->unknown_2ac_ > 0 && f->kind == 3) {
            float range = (float)(unsigned int)GameObject_GetPartyMemberLevel(c) / 10.0f;
            amount += (int)(1.0f + NextRandomFloatBetween((Random*)self, 0.0f, range));
        }
        if (amount > 0) {
            res[n] = func_ov000_0215a1d4(self, ids[i], amount, &var3[n]);
            tgt[n] = ids[i];
            bits[n] |= 0x800000000ULL;
            if (var3[n] > 0) {
                n++;
            }
        }
    }
    if (n > 0) {
        func_ov000_0215c758(self, tgt, n, 1, res, var7, var8);
    }

    n = 0;
    for (int i = 0; i < count; i++) {
        Struct_ov000_0215a23c_3* c = inline_ov000_021537b8_2(ids[i]);
        if (c != 0 && func_02088514((Struct_02088514*)c->stats)) {
            int value = c->stats->f4 >> 4;
            if (value > 999) {
                value = 999;
            }
            if (value <= 0) {
                value = 1;
            }
            if (value > 0) {
                bits[n] |= 2;
                res[n] = func_ov000_0215a004(self, ids[i], ids[i], value, &bits[n], 0, 0, 1);
                var3[n] = value;
                tgt[n] = ids[i];
                n++;
            }
        }
    }
    if (n > 0) {
        func_ov000_0215c758(self, tgt, n, 2, res, var7, var8);
    }

    count = func_ov000_0215eb1c(self, idBuf.v, 0x10, 1);
    for (int i = 0; i < count; i++) {
        Struct_ov000_0215a23c_3* c = inline_ov000_0215a23c(ids[i]);
        if (c != 0) {
            int amount = 0;
            short mp = 0;
            if (func_ov000_0215830c((GameObject*)c)) {
                amount = func_ov000_02159dbc(self, ids[i]);
                if (amount < 3) {
                    amount = 3;
                }
            }
            func_ov000_0215a1d4(self, ids[i], amount, &mp);
        }
    }

    n = 0;
    for (int i = 0; i < count; i++) {
        Struct_ov000_0215a23c_3* c = inline_ov000_021537b8_2(ids[i]);
        if (c != 0 && func_02088514((Struct_02088514*)c->stats)) {
            int value = c->stats->f4 >> 4;
            if (value > 999) {
                value = 999;
            }
            if (value <= 0) {
                value = 1;
            }
            if (value > 0) {
                bits[n] |= 2;
                res[n] = func_ov000_0215a004(self, ids[i], ids[i], value, &bits[n], 0, 0, 1);
                var3[n] = value;
                tgt[n] = ids[i];
                n++;
            }
        }
    }
    if (n > 0) {
        func_ov000_0215c758(self, tgt, n, 2, res, var7, var8);
    }
}
