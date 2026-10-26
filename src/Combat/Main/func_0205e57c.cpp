#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct Struct_0205e3ec { unsigned int v[4]; };
struct Struct_0205e330_3 { unsigned char a; unsigned char b; unsigned char pad[2]; struct Struct_0205e3ec unknown_4_; };
extern "C" struct Struct_0205e330_3* func_0205e3ec(struct Struct_0205e330_3* dst, struct Struct_0205e330_3* src);

struct Struct_0205e1e4_2 {
    char pad[0x18];
    struct Struct_0205e1e4_2* next;
};
struct Struct_0205e1e4 {
    struct Struct_0205e1e4_2* head;
    struct Struct_0205e1e4_2* tail;
    int count;
};
extern "C" struct Struct_0205e1e4_2* func_0205e1e4(struct Struct_0205e1e4* list);

struct Struct_0205e18c_2 {
    char pad[0x18];
    struct Struct_0205e18c_2* next;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* head;
    struct Struct_0205e18c_2* tail;
    int count;
};
extern "C" void func_0205e18c(struct Struct_0205e18c* list, struct Struct_0205e18c_2* node);

struct Struct_0205e57c_6;
extern "C" int func_0205e830(struct Struct_0205e57c_6* obj, int index);

struct SearchStruct0202c1a4;
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkSession_GetOwnRecord(void* base);
extern "C" int LinkSession_IsSlotMember(SearchStruct* obj, int index);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_0205e57c {
    unsigned char pad[0xfc0];
    int busy;
};

struct SlotEntry0205e57c {
    SearchEntry0202c178 head;
    struct Struct_0205e330_3 slots[5];
};

struct Struct_0205e57c_3 {
    struct Struct_0205e330_3 data;
    short group;
    unsigned short flags;
    struct Struct_0205e57c_3* next;
};

struct Struct_0205e57c_4 {
    struct Struct_0205e57c_3* head;
    struct Struct_0205e57c_3* tail;
    int count;
};

struct Struct_0205e57c_5 {
    struct Struct_0205e57c_3 nodes[0xc0];
    struct Struct_0205e57c_4 unknown_1500_;
    struct Struct_0205e57c_4 pending;
    struct Struct_0205e57c_4 active;
};

static int data_0210874c;
static int data_02108750;

// USA: func_0205e57c
extern "C" ARM void func_0205e57c(struct Struct_0205e57c_5* obj) {
    static unsigned char sSeq;

    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    if (sSeq >= 0xfa) {
        sSeq = 0;
    }
    if (((struct Struct_0205e57c*)search)->busy != 0) {
        return;
    }

    struct SlotEntry0205e57c* table = (struct SlotEntry0205e57c*)LinkSession_GetOwnRecord(search);
    for (int i = 0; i < 5; i++) {
        if (table->slots[i].a != 0xff) {
            data_0210874c += 0x10;
        }
        table->slots[i].a = 0xff;
    }

    for (int j = 0; j < 5; j++) {
        int var4;
        if (table->slots[j].a != 0xff) continue;
        struct Struct_0205e57c_3* node = obj->pending.head;
        if (node == NULL) continue;
        if (node->flags & 1) {
            var4 = 1;
            struct SlotEntry0205e57c* cur = (struct SlotEntry0205e57c*)LinkSession_GetOwnRecord(LinkSession_GetInstance());
            for (int k = 0; k < 5; k++) {
                if (cur->slots[k].a != 0xff) {
                    var4 = 0;
                    break;
                }
            }
            if (var4) {
                node->flags &= ~1;
            }
        }
        if (node->flags & 1) continue;
        func_0205e1e4((struct Struct_0205e1e4*)&obj->pending);
        func_0205e3ec(&table->slots[j], &node->data);
        table->slots[j].b = ++sSeq;
        func_0205e18c((struct Struct_0205e18c*)&obj->unknown_1500_, (struct Struct_0205e18c_2*)node);
    }

    for (int g = 0; g < 4; g++) {
        if (!LinkSession_IsSlotMember(search, g)) continue;
        if (g == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search)) continue;
        struct SlotEntry0205e57c* entry = (struct SlotEntry0205e57c*)LinkSession_GetReceivedRecord(search, g);
        if (entry == NULL) continue;
        if (entry->head.flags.selected == 0) continue;
        for (int s = 0; s < 5; s++) {
            LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
            if (entry->slots[s].a == 0xff) continue;
            if (!func_0205e830((struct Struct_0205e57c_6*)obj, entry->slots[s].a)) continue;
            struct Struct_0205e57c_3* node = (struct Struct_0205e57c_3*)func_0205e1e4((struct Struct_0205e1e4*)&obj->unknown_1500_);
            if (node == NULL) continue;
            func_0205e3ec(&node->data, &entry->slots[s]);
            node->group = g;
            func_0205e18c((struct Struct_0205e18c*)&obj->active, (struct Struct_0205e18c_2*)node);
            data_02108750 += 0x10;
        }
    }
}
