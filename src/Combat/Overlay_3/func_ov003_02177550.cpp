#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion89c = 0x818
};
enum {
    Enum_ov003_02177550_4163 = 0xfbf
};
#else
enum {
    kRegion89c = 0x89c
};
enum {
    Enum_ov003_02177550_4163 = 0x1043
};
#endif
#include "GameState/GameState.h"

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2 *obj, int key);
extern "C" void func_02080c68(void *obj, int id, int value);
extern "C" void func_02080bac(void *obj, int id);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c *obj, int id, int value);
extern "C" void func_020805f4(void *obj, int value);
extern "C" void func_0208103c(void *obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0 *obj, int id, int value);
extern "C" int func_02080b2c(void *obj, int id);
struct Struct_02052df8;
extern "C" int func_02052df8(Struct_02052df8 *obj, int index);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8 *obj, int id, int value);
struct Struct_02080fc4;
extern "C" void func_02080fc4(struct Struct_02080fc4 *obj, int id, int value);
extern "C" int func_020dd4c4(int id, void *node);
extern "C" int func_ov003_021753a0(void *obj, int id, void *a, void *b);
extern "C" void func_020813ec(void *obj, int key);

#if defined(jpn)
extern int data_ov003_0217e3ac[];
#else
extern int data_ov003_0217fb3c[];
#endif

struct Struct_ov003_02177550 {
    char pad0[4];
    int value;
    unsigned int kind : 4;
    unsigned int pad8 : 28;
    unsigned int lo : 7;
    unsigned int unknown_c_7_ : 4;
    unsigned int hi : 21;
    char pad10[0x18 - 0x10];
    short count;
};

struct Struct_ov003_02177550_2 {
    char pad0[8];
    Struct_ov003_02177550 *node;
    char unknown_c_[kRegion89c - 0xc];
    struct Struct_0207fdcc_2 *unknown_89c_;
    char unknown_8a0_[Enum_ov003_02177550_4163 - kRegion89c - 4];
    signed char combatantId;
};

// JPN: func_ov003_02177550 (0217650c)
// USA: func_ov003_02177550
extern "C" ARM void func_ov003_02177550(Struct_ov003_02177550_2 *self) {
    GameState *battle     = GameState::GetInstance();
    GameObject *combatant = func_0200ff1c(battle, self->combatantId);
    if (combatant == NULL) {
        return;
    }
    struct Struct_0207fdcc_2 *var2;
    Struct_ov003_02177550 *node = self->node;
    var2            = self->unknown_89c_;
    if (node == NULL) {
        return;
    }

    func_02080c20(var2, 0xf);
    func_02080c68(var2, 0xf, 0);
    func_02080bac(var2, 0xf);
    func_02080f8c((struct Container02080f8c *) var2, 0x70, node->value);
#if !defined(jpn)
    func_020805f4(var2, 0x70);
#endif
    int var4         = func_020dd4c4(self->combatantId, node);
    unsigned int var5 = node->unknown_c_7_;
    if (var5 != 0) {
        func_0208103c(var2, 0x71, (short) (var5 + 0x2f));
    }

    if (var4 != 0) {
        func_0208103c(var2, 0x75, 0xb);
        func_02080cc0((struct Struct_02080cc0 *) var2, 0x75, 3);
        func_02080b2c(var2, 0x72);
        func_02080b2c(var2, 0x73);
        func_02080b2c(var2, 0x74);
        func_02080b2c(var2, 0x159);
        func_02080b2c(var2, 0x15a);
    } else {
        func_02080cc0((struct Struct_02080cc0 *) var2, 0x75, 0xf);
#if defined(jpn)
        int index = data_ov003_0217e3ac[node->kind];
#else
        int index = data_ov003_0217fb3c[node->kind];
#endif
        if (index < 0) {
            return;
        }
        int var7 = func_02052df8((Struct_02052df8 *) combatant, index);
        if (var7 == node->count) {
            func_0208103c(var2, 0x75, 0x22);
            func_02080b2c(var2, 0x72);
            func_02080b2c(var2, 0x73);
            func_02080b2c(var2, 0x74);
            func_02080b2c(var2, 0x159);
            func_02080b2c(var2, 0x15a);
        } else {
            func_02080b2c(var2, 0x75);
            unsigned short cur;
            unsigned short max;
            if (func_ov003_021753a0(self, self->combatantId, &cur, &max) != 0) {
                func_02080fa8((struct Struct_02080fa8 *) var2, 0x72, cur);
                int nibble = 0xf;
                if (cur > max) {
                    nibble = 9;
                } else if (cur < max) {
                    nibble = 5;
                }
                func_02080cc0((struct Struct_02080cc0 *) var2, 0x73, nibble);
                func_02080fa8((struct Struct_02080fa8 *) var2, 0x73, max);
                func_02080b2c(var2, 0x159);
                func_02080b2c(var2, 0x15a);
            } else {
                float var11;
                float var12;
                func_ov003_021753a0(self, self->combatantId, &var11, &var12);
                func_02080fc4((struct Struct_02080fc4 *) var2, 0x159, *(int *) &var11);
                int nibble = 0xf;
                if (var11 > var12) {
                    nibble = 3;
                } else if (var11 < var12) {
                    nibble = 5;
                }
                func_02080cc0((struct Struct_02080cc0 *) var2, 0x15a, nibble);
                func_02080fc4((struct Struct_02080fc4 *) var2, 0x15a, *(int *) &var12);
                func_02080b2c(var2, 0x72);
                func_02080b2c(var2, 0x73);
            }
        }
    }

    func_020813ec(var2, 0xf);
}
