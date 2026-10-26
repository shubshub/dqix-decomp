#include "GameState/GameState.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct Struct_020a0b8c;
struct Struct_020a0bcc;
struct S_a0af4;
struct KeyMap020a095c;
struct ObjStruct_021e1474;
struct ItemTable;
struct Struct_0205d81c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c *s);
extern "C" void func_020a0bcc(struct Struct_020a0bcc *s);
extern "C" int func_020a0af4(struct S_a0af4 *s, int key);
extern "C" void func_020a095c(struct KeyMap020a095c *m, int key, int val);
extern "C" void func_ov023_021e1518(void *p);
extern "C" void RefreshEntryStatusFlags_021e1474(struct ObjStruct_021e1474 *obj,
                                                                                              struct ItemTable *c);
extern "C" void func_ov023_021e1870(void *a, void *b, int c, int d, int e);
extern "C" void func_ov023_021e1814(void *a, void *b, int c, int d, int e);
struct Struct_ov002_0215b458_4 {
    char pad[0xc5];
    unsigned char flags;
};
extern "C" struct Struct_ov002_0215b458_4 *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_0205d7a0(void *p, int idx);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);

struct Struct_ov002_0215b458 {
    char pad[0x18];
    short key;
};
struct Struct_ov002_0215b458_2 {
    struct Struct_ov002_0215b458_2 *next;
    struct Struct_ov002_0215b458 *item;
};
struct Party0215b458 {
    short *keys;
    signed char *unknown_4_;
};

// USA: func_ov002_0215b458
extern "C" ARM void func_ov002_0215b458(char *base, int flag) {
    GameState *gs;
    char *sub;
    int sel;
    short *keys;
    struct Party0215b458 *party;
    int count;
    signed char *var6;
    struct Struct_ov002_0215b458_2 *node;
    gs    = GameState::GetInstance();
    party = (struct Party0215b458 *) GameState_GetParty(gs);
    sel   = GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
    keys  = party->keys;
    var6  = party->unknown_4_;
    count = func_020a0b8c((struct Struct_020a0b8c *) party);
    if (count == 0) return;

    sub = base + 4;
    func_ov023_021e1518(sub + 0x800);
    RefreshEntryStatusFlags_021e1474(
        (struct ObjStruct_021e1474 *) (sub + 0x800), (struct ItemTable *) (base + 0x3ec + 0x400));
    if (*(unsigned char *) (base + 0x2000 + 0x48d) == 2) {
        func_ov023_021e1870(sub + 0x800, (void *) 1, -1, -1, 0);
        *(unsigned char *) (base + 0x2000 + 0x48d) = 1;
    } else {
        func_ov023_021e1814(sub + 0x800, (void *) 1, -1, -1, 0);
        *(unsigned char *) (base + 0x2000 + 0x48d) = 2;
    }
    memset(*(void **) (base + 0x2000 + 0x534), 0, 0x140);
    memset(*(void **) (base + 0x2000 + 0x538), 0, 0xa0);
    memcpy(*(void **) (base + 0x2000 + 0x534), keys, count * 2);
    memcpy(*(void **) (base + 0x2000 + 0x538), var6, count);
    func_020a0bcc((struct Struct_020a0bcc *) party);

    for (node = *(struct Struct_ov002_0215b458_2 **) (sub + 0x800); node != NULL; node = node->next) {
        struct Struct_ov002_0215b458 *item = node->item;
        if (item == NULL) continue;
        short key = item->key;
        for (short j = 0; j < count; j++) {
            if (key == (*(short **) (base + 0x2000 + 0x534))[j]) {
                func_020a095c((struct KeyMap020a095c *) party, key,
                                                                  (*(signed char **) (base + 0x2000 + 0x538))[j]);
                break;
            }
        }
    }

    if (sel >= 0 && flag) {
        int idx = func_020a0af4((struct S_a0af4 *) party, sel);
        if (idx >= 0) {
            *(short *) (base + 0x1b00 + 0xe8) = idx;
            func_0205d7a0(base + 0x2c8 + 0xc00, idx);
            struct Struct_ov002_0215b458_4 *e =
                func_0205d81c((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 5);
            if (e != NULL) {
                e->flags &= ~2;
            }
        }
    }
    func_ov002_0215b9a4(base, 5, 0);
}
