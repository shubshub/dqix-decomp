#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct Struct_0205e3ec { unsigned int unknown_0_[4]; };
struct Struct_0205e330_3 { unsigned char unknown_0_; unsigned char unknown_1_; unsigned char unknown_2_[2]; struct Struct_0205e3ec unknown_4_; };
extern "C" struct Struct_0205e330_3* func_0205e3ec(struct Struct_0205e330_3* arg0, struct Struct_0205e330_3* arg1);

struct Struct_0205e1e4_2 {
    char unknown_0_[0x18];
    struct Struct_0205e1e4_2* unknown_18_;
};
struct Struct_0205e1e4 {
    struct Struct_0205e1e4_2* unknown_0_;
    struct Struct_0205e1e4_2* unknown_4_;
    int unknown_8_;
};
extern "C" struct Struct_0205e1e4_2* func_0205e1e4(struct Struct_0205e1e4* arg0);

struct Struct_0205e18c_2 {
    char unknown_0_[0x18];
    struct Struct_0205e18c_2* unknown_18_;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* unknown_0_;
    struct Struct_0205e18c_2* unknown_4_;
    int unknown_8_;
};
extern "C" void func_0205e18c(struct Struct_0205e18c* arg0, struct Struct_0205e18c_2* arg1);

struct Struct_0205e57c_6;
extern "C" int func_0205e830(struct Struct_0205e57c_6* arg0, int arg1);

struct SearchStruct0202c1a4;
extern "C" void* LinkSession_GetInstance(void);
void* LinkSession_GetOwnRecord(void* base);
int LinkSession_IsSlotMember(SearchStruct* obj, int index);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_0205e57c {
    unsigned char unknown_0_[0xfc0];
    int unknown_fc0_;
};

struct Struct_0205e57c_2 {
    Struct_0202b2f0_2 unknown_0_;
    struct Struct_0205e330_3 unknown_10_[5];
};

struct Struct_0205e57c_3 {
    struct Struct_0205e330_3 unknown_0_;
    short unknown_14_;
    unsigned short unknown_16_;
    struct Struct_0205e57c_3* unknown_18_;
};

struct Struct_0205e57c_4 {
    struct Struct_0205e57c_3* unknown_0_;
    struct Struct_0205e57c_3* unknown_4_;
    int unknown_8_;
};

struct Struct_0205e57c_5 {
    struct Struct_0205e57c_3 unknown_0_[0xc0];
    struct Struct_0205e57c_4 unknown_1500_;
    struct Struct_0205e57c_4 unknown_150c_;
    struct Struct_0205e57c_4 unknown_1518_;
};

static int data_0210874c;
static int data_02108750;

// USA: func_0205e57c
extern "C" ARM void func_0205e57c(struct Struct_0205e57c_5* arg0) {
    static unsigned char sSeq;

    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    if (sSeq >= 0xfa) {
        sSeq = 0;
    }
    if (((struct Struct_0205e57c*)var0)->unknown_fc0_ != 0) {
        return;
    }

    struct SlotEntry0205e57c* table = (struct SlotEntry0205e57c*)LinkSession_GetOwnRecord(search);
    for (int i = 0; i < 5; i++) {
        if (table->slots[i].a != 0xff) {
            sPendingBytes += 0x10;
        }
        var1->unknown_10_[var2].unknown_0_ = 0xff;
    }

    for (int j = 0; j < 5; j++) {
        int allFree;
        if (table->slots[j].a != 0xff) continue;
        struct Node0205e57c* node = obj->pending.head;
        if (node == NULL) continue;
        if (node->flags & 1) {
            allFree = 1;
            struct SlotEntry0205e57c* cur = (struct SlotEntry0205e57c*)LinkSession_GetOwnRecord(LinkSession_GetInstance());
            for (int k = 0; k < 5; k++) {
                if (cur->slots[k].a != 0xff) {
                    allFree = 0;
                    break;
                }
            }
            if (var4) {
                var5->unknown_16_ &= ~1;
            }
        }
        if (var5->unknown_16_ & 1) continue;
        func_0205e1e4((struct Struct_0205e1e4*)&arg0->unknown_150c_);
        func_0205e3ec(&var1->unknown_10_[var3], &var5->unknown_0_);
        var1->unknown_10_[var3].unknown_1_ = ++sSeq;
        func_0205e18c((struct Struct_0205e18c*)&arg0->unknown_1500_, (struct Struct_0205e18c_2*)var5);
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
            if (!TestBitInArray0x1524((struct BitArrayObj0205e830*)obj, entry->slots[s].a)) continue;
            struct Node0205e57c* node = (struct Node0205e57c*)DequeueNode((struct QList0205e1e4*)&obj->free);
            if (node == NULL) continue;
            CopyStruct0205e3ec(&node->data, &entry->slots[s]);
            node->group = g;
            EnqueueNode((struct QList0205e18c*)&obj->active, (struct QNode0205e18c*)node);
            sActiveBytes += 0x10;
        }
    }
}
