#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov000_0217c32c {
    unsigned int pad0 : 7;
    unsigned int category : 4;
    unsigned int unknown_1_3_ : 21;
};

struct Struct_ov000_0217c32c_4 {
    struct Struct_ov000_0217c32c* item;
};

struct Struct_ov000_0217c32c_5 {
    char pad0[0x2b4];
    struct Struct_ov000_0217c32c_4 shield;
#if defined(jpn)
    char unknown_2b8_[0x8b8 - 0x2b8];
#else
    char unknown1_2b8_[0x950 - 0x2b8];
#endif
    int field950;
};

struct Struct_02054000 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    struct Struct_ov000_0217c32c_5* data;
};
extern "C" struct Struct_ov000_0217c32c_4* func_02054000(struct Struct_02054000* p);

struct Field150Holder02052e14;
extern "C" short* func_02052e14(struct Field150Holder02052e14* obj);
extern "C" void* func_02053c6c(unsigned char* obj);

struct Pair0209a338;
extern "C" void func_0209a338(struct Pair0209a338* p);
struct Struct_0209a348;
extern "C" void func_0209a348(struct Struct_0209a348* ctx, void* value);

struct Struct_0209a614_2 {
#if defined(jpn)
    unsigned short kind : 12;
    unsigned short pad0 : 4;
#else
    unsigned short kind : 11;
    unsigned short pad0 : 5;
#endif
    unsigned short id;
    unsigned int category : 5;
    unsigned int pad4 : 27;
    int field8;
};
struct Struct_0209a614 {
    struct Struct_0209a614_2* entries;
    int count;
};
extern "C" struct Struct_0209a614_2* func_0209a614(struct Struct_0209a614* list, int id);

struct Struct_ov000_0217c32c_2 {
    int name;
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Struct_ov000_0217c32c_3 {
    char pad0[0x4c];
    int combatantId;
#if defined(jpn)
    char unknown_50_[0xc8 - 0x50];
#else
    char unknown1_50_[0x88 - 0x50];
#endif
    unsigned char unknown_88_[0x13];
    char unknown_9b_[0x1a4 - 0x9b];
    struct Struct_ov000_0217c32c_2* items[0x93];
};

// USA: func_ov000_0217c32c
extern "C" ARM void func_ov000_0217c32c(struct Struct_ov000_0217c32c_3* menu) {
    struct Struct_02054000* c = (struct Struct_02054000*)func_0200ff1c(GameState::GetInstance(), menu->combatantId);
    if (c == NULL) {
        return;
    }
    struct Struct_ov000_0217c32c_4* weapon = func_02054000(c);
    struct Struct_ov000_0217c32c_4* shield = &c->data->shield;
    short* var3 = func_02052e14((struct Field150Holder02052e14*)c);
    if (var3 != NULL) {
        if (var3[7] < 0) {
            weapon = NULL;
        }
        if (var3[8] < 0) {
            shield = NULL;
        }
    }
    if (func_02053c6c((unsigned char*)c) == NULL) {
        return;
    }
    memset(menu->unknown_88_, 0, sizeof(menu->unknown_88_));
    struct Struct_0209a614 list;
    struct Struct_0209a614_2 entries[287];
    func_0209a338((struct Pair0209a338*)&list);
    func_0209a348((struct Struct_0209a348*)&list, entries);
    for (unsigned short i = 0; i < 0x93; i++) {
        struct Struct_ov000_0217c32c_2* item = menu->items[i];
        if (item == NULL) {
            return;
        }
        struct Struct_0209a614_2* found = func_0209a614(&list, item->id);
        if (found == NULL) {
            continue;
        }
        int var9;
        if (c->data->field950 == 0) {
            var9 = 1;
        } else if (weapon != NULL) {
            var9 = weapon->item->category == found->category;
        } else {
            var9 = found->category == 0xe;
        }
        if (shield != NULL && shield->item->category == found->category) {
            var9 = 1;
        }
        if (found->category > 0xe) {
            var9 = 1;
        }
        if (found->kind == 0x11e) {
            var9 = 1;
        }
        if (var9) {
            menu->unknown_88_[(unsigned char)(i >> 3)] |= 1 << (i & 7);
        }
    }
}
