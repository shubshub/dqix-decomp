#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct U16Field0x6_020375f8;

struct List_020283fc;
extern "C" int NodeGraph_FindNodeIndexById(struct List_020283fc* list, int id);

extern "C" int func_02073d58(int a, void* b, int c);

struct Struct_02003d14;
struct Struct_02073ec4_2;
struct Struct_02078e60_2 {
    unsigned short key;
    unsigned short pad2;
    unsigned int type : 3;
    unsigned int unknown_4_3_ : 10;
    unsigned int unknown_5_5_ : 8;
    unsigned int unknown_6_5_ : 11;
    unsigned char pad8[0x20 - 8];
};
extern "C" struct Struct_02078e60_2* func_0209bd94(struct Struct_02073ec4_2* table, int key);

struct Struct_02078e60_3 {
    unsigned char id;
    unsigned char flags;
};

struct ListEntry_02028430 {
    unsigned char id;
    unsigned char pad1;
    unsigned char count;
    unsigned char pad3[0xc - 3];
    struct Struct_02078e60_3** items;
};
extern "C" struct ListEntry_02028430* NodeGraph_GetNode(struct List_02028430* list, int index);

struct Struct_02078e60 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0xb8 - 6];
    unsigned short field0xb8;
    char unknown_ba_[0x168 - 0xba];
    unsigned short unknown_168_;
    char unknown_16a_[0x17d - 0x16a];
    unsigned char unknown_17d_;
};

extern "C" int rand(void);

// USA: func_02078e60
extern "C" ARM unsigned short func_02078e60(void* obj, char* out) {
    struct Struct_02078e60* o = (struct Struct_02078e60*)obj;
    struct Entry_02028bd0* table;
    struct Entry_02028bd0* entry;
    struct ListEntry_02028430* le;
    struct Struct_02078e60_2* found;
    struct Struct_02078e60_3* item;
    struct Struct_02078e60_3* var6[16];
    struct Struct_02078e60_3* pick;
    int n;
    int j;
    int any;
    int idx;

    *out = 0;
    table = ZoneRecords_GetInstance();
    entry = ZoneRecords_Find(table, ((Object3D*)((struct U16Field0x6_020375f8*)o))->GetField06());
    if (entry == NULL) {
        return 0;
    }
#if defined(jpn)
    le = NodeGraph_GetNode((struct List_02028430*)((char*)entry + 0x14), o->field0xb8);
#else
    le = NodeGraph_GetNode((struct List_02028430*)((char*)entry + 0x18), o->field0xb8);
#endif
    if (le == NULL) {
        return 0;
    }
    if (le->count == 0) {
        return 0;
    }
    if ((o->unknown_17d_ & 0x40) == 0) {
        if (func_02073d58(le->id, entry, o->f4) != 0) {
            *out = 1;
            return le->id;
        }
        *out = 0;
        o->unknown_17d_ |= 0x40;
        return le->id;
    }
#if defined(jpn)
    found = func_0209bd94((struct Struct_02073ec4_2*)((char*)entry + 0x5c), o->unknown_168_);
#else
    found = func_0209bd94((struct Struct_02073ec4_2*)((char*)entry + 0x60), o->unknown_168_);
#endif
    n = 0;
    any = 0;
    if (found != NULL) {
        for (j = 0; j < le->count; j++) {
            item = le->items[j];
            if ((item->flags & found->unknown_5_5_) == 0 && item->flags != 0) {
                continue;
            }
            if (func_02073d58(item->id, entry, -1) != 0) {
                any = 1;
            } else {
                var6[n++] = le->items[j];
            }
        }
    }
    if (any == 1 && n == 0) {
#if defined(jpn)
        idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x14), le->id);
#else
        idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x18), le->id);
#endif
        if (idx != -1) {
            o->field0xb8 = idx;
        }
        return le->id;
    }
    pick = 0;
    if (n != 0) {
        pick = var6[rand() % n];
    }
    if (pick == 0) {
#if defined(jpn)
        idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x14), le->id);
#else
        idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x18), le->id);
#endif
        if (idx != -1) {
            o->field0xb8 = idx;
        }
        return le->id;
    }
#if defined(jpn)
    idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x14), pick->id);
#else
    idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + 0x18), pick->id);
#endif
    if (idx != -1) {
        o->field0xb8 = idx;
    }
    return pick->id;
}
