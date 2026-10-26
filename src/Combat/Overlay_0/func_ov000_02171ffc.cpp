#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include "GameState/GameState.h"

struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* p);
extern "C" int func_02083b00(unsigned char* obj, int index);

struct Struct_ov000_02171ffc {
    unsigned int bit0 : 1;
    unsigned int unknown_0_1_ : 1;
    unsigned int rest : 30;
};

struct Struct_ov000_02171ffc_2 {
    char unk0[0x2f4];
    struct Struct_ov000_02171ffc flags;
};

struct Struct_ov000_02171ffc_3 {
    char unk0[LOW_REGION(0x144, 0x150)];
    struct Struct_ov000_02171ffc_2* data;
};

struct Struct_ov000_02171ffc_4 {
    char unk0[0x18];
    short count;
};

struct ActionEntry {
    char unk0[0x16];
    short unknown_16_;
};

struct Struct_ov000_02171ffc_5 {
    char unk0[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int kind : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[0x14 - 0xc];
    unsigned int unknown_14_0_ : 28;
    unsigned int category : 4;
};

struct Struct_ov000_0215ab88 {
    char unk0[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0x26 - 0x1d];
    short unknown_26_;
    char unknown_28_[0x2c - 0x28];
    short unknown_2c_;
    char unknown_2e_[0x4c - 0x2e];
    int combatantId;
};

extern "C" struct ActionEntry* func_ov000_02171d90(struct Struct_ov000_0215ab88* obj, int key);
extern "C" struct Struct_ov000_02171ffc_5* func_ov000_02170cf8(struct Struct_ov000_0215ab88* obj, int id);

// USA: func_ov000_02171ffc
extern "C" ARM int func_ov000_02171ffc(struct Struct_ov000_0215ab88* obj) {
    struct Struct_ov000_02171ffc_3* combatant = (struct Struct_ov000_02171ffc_3*)func_0200ff1c(GameState::GetInstance(), obj->combatantId);
    if (combatant == 0) {
        return 2;
    }
    short var1 = obj->unknown_26_;
    int result = 2;
    if (obj->unknown_1c_ == 4) {
        struct ActionEntry* entry = func_ov000_02171d90(obj, obj->unknown_2c_);
        if (entry == 0) {
            return result;
        }
        var1 = entry->unknown_16_;
    }
    if (var1 == 0x20a) {
        return 3;
    }
    struct Struct_ov000_02171ffc_5* info = func_ov000_02170cf8(obj, (unsigned short)var1);
    if (info == 0) {
        return 2;
    }
    if (var1 == 1) {
        if (combatant != 0) {
            struct Struct_ov000_02171ffc_4* sub = (struct Struct_ov000_02171ffc_4*)func_02054000((struct Struct_02054000*)combatant);
            if (sub != 0 && sub->count > 0) {
                struct Struct_ov000_02171ffc* flags = &combatant->data->flags;
                if (flags->unknown_0_1_) {
                    result = 3;
                } else if (flags->bit0) {
                    result = 4;
                }
            }
        }
    } else {
        int kind = info->kind;
        if (kind == 1) {
            result = info->category;
        } else if (kind == 2) {
            result = info->category;
        }
    }
    if (result == 6 && combatant != 0) {
#if defined(jpn)
        result = func_02083b00((unsigned char*)combatant->data, 0xe6) ? 3 : 2;
#else
        result = 2;
        if (func_02083b00((unsigned char*)combatant->data, 0xe6)) {
            result = 3;
        }
#endif
    }
    return result;
}
