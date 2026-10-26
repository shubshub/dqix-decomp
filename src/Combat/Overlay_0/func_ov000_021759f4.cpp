#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_ov000_021759f4_2 {
    char pad[0x3508];
    void* node;
};
#endif

struct Combatant020A36A8;

struct Struct_ov000_021643d4_8 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1c - 0x19];
    signed char field_0x1c;
    signed char unknown_1d_;
    char unknown_1e_[0x26 - 0x1e];
    short unknown_26_;
    char pad28[0x2e - 0x28];
    signed char unknown_2e_;
};

struct Struct_ov000_021759f4_3 {
#if defined(jpn)
    char pad0[0x8b8];
#else
    char pad0[0x950];
#endif
    int vocation;
};

struct Struct_ov000_021759f4_4 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    struct Struct_ov000_021759f4_3* data;
};

struct Struct_ov000_021759f4_5 {
    short field_0x0[4];
    signed char unknown_8_[4];
    signed char unknown_c_[4];
    char pad10[0x20 - 0x10];
    int unknown_20_;
#if defined(jpn)
    char pad24[0x1faa - 0x24];
#else
    char pad24[0x1d72 - 0x24];
#endif
    unsigned short flags;
};

struct Struct_ov000_021759f4 {
#if defined(jpn)
    char pad0[0xe30];
#else
    char pad0[0xeb4];
#endif
    unsigned char result;
};

extern "C" struct Combatant020A36A8* func_ov017_021b8478(void* obj);
extern "C" int func_020a36a8(struct Combatant020A36A8* obj);
extern "C" struct Struct_ov000_021759f4* func_ov017_021b8468(void* obj);
extern "C" struct Struct_ov000_021643d4_8* func_ov000_02161318(void* obj, int id);
extern "C" int func_ov000_021719f8(int* obj);
extern "C" void func_ov017_021c9cd8(unsigned char tag);
extern unsigned short data_ov000_02183444[];

// USA: func_ov000_021759f4
extern "C" ARM int func_ov000_021759f4(struct Struct_ov000_021759f4_5* work) {
#if defined(jpn)
    void* node = ((Struct_ov000_021759f4_2*)GetGameResources())->node;
#else
    void* node = GetGameResources()->unknown_ptr_3718;
#endif
    struct Combatant020A36A8* active = func_ov017_021b8478(node);
    if (work->flags & 0x200) {
        return 0;
    }
    if (work->flags & 0x400) {
        return 0;
    }
    if (active != NULL && !func_020a36a8(active)) {
        struct Struct_ov000_021759f4* source = func_ov017_021b8468(node);
        if (source != NULL) {
            return source->result;
        }
    }

    GameState* gs = GameState::GetInstance();
    unsigned char matched = 0;
    unsigned char count = 0;
    for (int i = 0; i < 4; i++) {
        struct Struct_ov000_021643d4_8* entry = func_ov000_02161318(work, i);
        if (entry == NULL) {
            break;
        }
        if (func_ov000_021719f8((int*)entry) != 0 || entry->unknown_10_[entry->unknown_18_] != 100 ||
            entry->field_0x1c != 5) {
            break;
        }
        GameObject* member = gs->GetPartyMemberByIndex(i);
        if (member == NULL) {
            break;
        }
        int vocation = ((struct Struct_ov000_021759f4_4*)member)->data->vocation;
        unsigned short var10 = data_ov000_02183444[vocation];
        if (var10 != entry->unknown_26_) {
            break;
        }
        work->field_0x0[i] = entry->unknown_26_;
        work->unknown_8_[i] = entry->unknown_1d_;
        work->unknown_c_[i] = entry->unknown_2e_;
        if (work->unknown_20_ >= 0 && (vocation == 6 || vocation == 0xb)) {
            matched++;
        }
        count++;
    }
    if (count == 4 && matched != 4) {
        func_ov017_021c9cd8(1);
        return 1;
    }
    return 0;
}
