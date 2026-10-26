#if defined(jpn)
#define data_ov015_021942a2 data_ov015_02194f64
#define data_ov015_021943a5 data_ov015_02194f37
#define data_ov015_021943b0 data_ov015_02194f48
#define data_ov015_021943b7 data_ov015_02194f57
#define data_ov015_021943bd data_ov015_02194f71
#define data_ov015_021943c6 data_ov015_02194f7e
#define data_ov015_021943d0 data_ov015_02194f8b
#define data_ov015_021943d9 data_ov015_02194f98
#define data_ov015_021943df data_ov015_02194f9e
#define data_ov015_021943ef data_ov015_02194fb1
#define data_ov015_021943f8 data_ov015_02194fb8
#define data_ov015_021943ff data_ov015_02194fbd
#define data_ov015_0219440c data_ov015_02194fc4
#define data_ov015_0219441a data_ov015_02194fcb
#define data_ov015_02194426 data_ov015_02194fd0
#define data_ov015_02194434 data_ov015_02194fd7
#define data_ov015_0219443d data_ov015_02194fe0
#define data_ov015_02194442 data_ov015_02194fe5
#define data_ov015_0219444b data_ov015_02194fee
#define data_ov015_02194452 data_ov015_02194ff5
#define data_ov015_02194459 data_ov015_02194ffc
#define data_ov015_0219445e data_ov015_02195001
#define data_ov015_02194463 data_ov015_02195006
#define data_ov015_02194470 data_ov015_02195017
#define data_ov015_0219447f data_ov015_0219502e
#define data_ov015_0219448e data_ov015_02195041
#define data_ov015_02194496 data_ov015_02195048
#define data_ov015_0219449e data_ov015_02195053
#define data_ov015_021944a9 data_ov015_0219505a
#define data_ov015_021944b6 data_ov015_0219506e
#define data_ov015_021944c5 data_ov015_02195083
#define data_ov015_021944d4 data_ov015_02195096
#define data_ov015_021944e3 data_ov015_021950b6
#define data_ov015_021944ec data_ov015_021950d0
#define data_ov015_021944f3 data_ov015_021950d7
#define data_ov015_021944fa data_ov015_021950de
#define data_ov015_02194503 data_ov015_021950eb
#define data_ov015_02194508 data_ov015_021950f5
#define data_ov015_0219450f data_ov015_021950fc
#define data_ov015_02194517 data_ov015_02195104
#define data_ov015_0219451b data_ov015_02195109
#define data_ov015_0219451f data_ov015_0219510e
extern const char data_ov015_021950a5[];
extern const char data_ov015_021950c3[];
extern const char data_ov015_021950f0[];
#endif
#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/BCFG.h"

struct MenuItem02192700 { char data[0x40]; };

struct MenuList02192700 {
    char pad0[0x62];
    unsigned short visibleCount;
    char unknown_64_[0x6d - 0x64];
    unsigned char flags;
};

struct Struct_ov015_02192700_3 {
    char pad0[0xc];
    char* name;
};

struct Struct_ov015_02192700_4 {
    struct Struct_ov015_02192700_3* value;
    struct Struct_ov015_02192700_4* next;
};

struct Struct_ov015_0218bb14 { char* name; int b; };
struct Struct_ov015_0218bb14_2 { void* f0; struct Struct_ov015_0218bb14* arr; void* f8; int count; };

struct Struct_ov015_02192700_5 {
    char* name;
    int f4;
    short key;
};

struct Struct_ov015_02192700_6 {
    int f0;
    int f4;
};

struct Element020dedd0 {
    int f0;
    char* name;
};

struct BCFG;

struct Struct_ov015_02192700_7 {
    int f0;
    char unknown_4_[0x24];
    struct Struct_ov015_02192700_7* next;
};

struct Struct_ov015_02192700_8 {
    char pad0[0x2c];
    struct Struct_ov015_02192700_4* list;
    void* unknown_30_;
    struct Struct_ov015_02192700_3* field34;
    char unknown_38_[0x3c - 0x38];
    struct Struct_ov015_0218bb14_2 entries;
    char container[0x64 - 0x4c];
    char search[0x194 - 0x64];
    int unknown_194_;
    char unknown_198_[0x19c - 0x198];
    unsigned char unknown_19c_[5];
    char unknown_1a1_[0x1a4 - 0x1a1];
    int state;
    char unknown_1a8_[0x268 - 0x1a8];
    short unknown_268_[(0x2c4 - 0x268) / 2];
    struct MenuList02192700 menu;
    char unknown_332_[0x344 - 0x332];
    struct MenuItem02192700* items;
    int unknown_348_;
    float unknown_34c_;
    unsigned char unknown_350_;
    char unknown_351_[0x354 - 0x351];
    int unknown_354_;
};

extern "C" void __clear(void* buf, int n);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
struct Struct_02029634_3;
extern "C" void func_0202a91c(Struct_02029634_3*);
extern "C" void DebugMenu_Init(struct MenuList02192700* menu);
extern "C" void DebugMenuItem_SetText(void* self, const char* src);
extern "C" void DebugMenuItem_Init(char*);
extern "C" const char* StandardStrings_Get(int id);
struct ListHead0202a944;
struct ListNode0202a944;
extern "C" void DebugMenu_AddItem(ListHead0202a944*, ListNode0202a944*);
extern "C" struct Struct_ov015_0218bb14* func_ov015_0218bb14(struct Struct_ov015_0218bb14_2* list, int idx);
extern "C" struct Struct_ov015_02192700_5* func_ov015_02193160(struct Struct_ov015_02192700_8* obj, int state, int* arg2);
struct Struct_0206f01c_2;
extern "C" struct Struct_ov015_02192700_6* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" int func_ov015_02190d08(struct Struct_ov015_02192700_8* obj);
struct ItemTable;
extern "C" struct Element020dedd0* ItemTable_Find(ItemTable*, int);
struct Struct_ov015_02192700_9;
extern "C" void func_ov015_0219313c(Struct_ov015_02192700_9*, int, int);
struct Struct_ov015_02192700_10;
extern "C" void func_ov015_02193150(Struct_ov015_02192700_10*, int);
extern "C" void DebugMenu_UpdateLayout(struct MenuList02192700* menu);
extern "C" void DebugMenu_Open(char*, int);
extern "C" struct Struct_ov015_02192700_7* func_ov015_0218f344(void* obj);

extern AllocatorUnion g_mainAllocator;
extern const char data_ov015_021942a2[];
extern const char data_ov015_021943a5[];
extern const char data_ov015_021943b0[];
extern const char data_ov015_021943b7[];
extern const char data_ov015_021943bd[];
extern const char data_ov015_021943c6[];
extern const char data_ov015_021943d0[];
extern const char data_ov015_021943d9[];
extern const char data_ov015_021943df[];
extern const char data_ov015_021943ef[];
extern const char data_ov015_021943f8[];
extern const char data_ov015_021943ff[];
extern const char data_ov015_0219440c[];
extern const char data_ov015_0219441a[];
extern const char data_ov015_02194426[];
extern const char data_ov015_02194434[];
extern const char data_ov015_0219443d[];
extern const char data_ov015_02194442[];
extern const char data_ov015_0219444b[];
extern const char data_ov015_02194452[];
extern const char data_ov015_02194459[];
extern const char data_ov015_0219445e[];
extern const char data_ov015_02194463[];
extern const char data_ov015_02194470[];
extern const char data_ov015_0219447f[];
extern const char data_ov015_0219448e[];
extern const char data_ov015_02194496[];
extern const char data_ov015_0219449e[];
extern const char data_ov015_021944a9[];
extern const char data_ov015_021944b6[];
extern const char data_ov015_021944c5[];
extern const char data_ov015_021944d4[];
extern const char data_ov015_021944e3[];
extern const char data_ov015_021944ec[];
extern const char data_ov015_021944f3[];
extern const char data_ov015_021944fa[];
extern const char data_ov015_02194503[];
extern const char data_ov015_02194508[];
extern const char data_ov015_0219450f[];
extern const char data_ov015_02194517[];
extern const char data_ov015_0219451b[];
extern const char data_ov015_0219451f[];

static inline const char* GetName(struct Struct_ov015_02192700_3* value) {
    return value->name;
}

// USA: func_ov015_02192700
extern "C" ARM void func_ov015_02192700(struct Struct_ov015_02192700_8* obj, int a1) {
    char title[0x80];
    char line[0x100];
    char marked[0x80];
    int idx;
    int count;

    if (obj->items != 0) {
        AllocatorUnion_Free(&g_mainAllocator, obj->items);
        obj->items = 0;
    }
    obj->unknown_354_ = a1;
    __clear(title, 0x80);
    func_0202a91c((Struct_02029634_3*)&obj->menu);
    DebugMenu_Init(&obj->menu);
    obj->menu.flags |= 6;

    if (obj->unknown_194_ == 0 || obj->unknown_194_ == 2) {
        switch (obj->state) {
        case 0:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943a5);
            break;
        case 1:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943b0);
            break;
        case 2:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943b7);
            break;
        case 3:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021942a2);
            break;
        case 4:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943bd);
            break;
        case 6:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943c6);
            break;
        case 7:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943d0);
            break;
        case 5:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943d9);
            break;
        case 8:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943df);
            break;
        case 15:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943ef);
            break;
        case 17:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943f8);
            break;
        case 18:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021943ff);
            break;
        case 19:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219440c);
            break;
        case 20:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219441a);
            break;
        case 21:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194426);
            break;
        case 23:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194434);
            break;
        case 24:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219443d);
            break;
        case 25:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194442);
            break;
        case 26:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219444b);
            break;
        case 27:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194452);
            break;
        case 28:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194459);
            break;
        case 22:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219445e);
            break;
        case 29:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194463);
            break;
        case 30:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194470);
            break;
        case 31:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219447f);
            break;
        case 16:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219448e);
            break;
        case 11:
            DebugMenuItem_SetText(&obj->menu, data_ov015_02194496);
            break;
        case 12:
            DebugMenuItem_SetText(&obj->menu, data_ov015_0219449e);
            break;
        case 33:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944a9);
            break;
        case 32:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944b6);
            break;
        case 13:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944c5);
            break;
        case 14:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944d4);
            break;
        case 34:
#if defined(jpn)
            DebugMenuItem_SetText(&obj->menu, data_ov015_021950a5);
#else
            DebugMenuItem_SetText(&obj->menu, data_ov015_021942a2);
#endif
            break;
        case 35:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944e3);
            break;
        case 36:
#if defined(jpn)
            DebugMenuItem_SetText(&obj->menu, data_ov015_021950c3);
#else
            DebugMenuItem_SetText(&obj->menu, data_ov015_021942a2);
#endif
            break;
        case 38:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944ec);
            break;
        case 39:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944f3);
            break;
        case 40:
            DebugMenuItem_SetText(&obj->menu, data_ov015_021944fa);
            break;
        case 37:
            if (obj->field34 != 0) {
                sprintf(title, data_ov015_02194503, obj->field34->name);
            }
            DebugMenuItem_SetText(&obj->menu, title);
            break;
        }

        count = 0;
        if (obj->state == 2 || obj->state == 3 || obj->state == 36) {
            struct Struct_ov015_02192700_4* it;
            for (it = obj->list; it != 0; it = it->next) {
                count++;
            }
            if (count == 0) {
                obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(struct MenuItem02192700));
            } else {
                obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
            }
            if (count == 0) {
                DebugMenuItem_Init((char*)obj->items);
#if defined(jpn)
                DebugMenuItem_SetText(obj->items, data_ov015_021950f0);
#else
                DebugMenuItem_SetText(obj->items, StandardStrings_Get(1000));
#endif
                DebugMenu_AddItem((ListHead0202a944*)&obj->menu, (ListNode0202a944*)obj->items);
                count = 1;
            } else {
                struct Struct_ov015_02192700_4* node = obj->list;
                for (count = 0; node != 0; count++) {
                    DebugMenuItem_Init((char*)&obj->items[count]);
                    DebugMenuItem_SetText(&obj->items[count], GetName(node->value));
                    DebugMenu_AddItem((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[count]);
                    node = node->next;
                }
            }
        } else if (obj->state == 40) {
            obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, obj->entries.count * sizeof(struct MenuItem02192700));
            for (; count < obj->entries.count; count++) {
                struct Struct_ov015_0218bb14* entry = func_ov015_0218bb14(&obj->entries, count);
                DebugMenuItem_Init((char*)&obj->items[count]);
                DebugMenuItem_SetText(&obj->items[count], entry->name);
                DebugMenu_AddItem((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[count]);
            }
        } else {
            struct Struct_ov015_02192700_5* entry;

            idx = 0;
            entry = func_ov015_02193160(obj, obj->state, &idx);
            while (entry != 0) {
                idx++;
                count++;
                entry = func_ov015_02193160(obj, obj->state, &idx);
            }
            obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
            count = 0;
            idx = 0;
            entry = func_ov015_02193160(obj, obj->state, &idx);
            while (entry != 0) {
                DebugMenuItem_Init((char*)&obj->items[count]);
                if (obj->state == 6) {
                    struct Struct_ov015_02192700_6* found = func_0206f4f0((Struct_0206f01c_2*)obj->search, entry->key);
                    if (found != 0) {
                        __clear(line, 0x100);
                        sprintf(line, data_ov015_02194508, found->f4 + 1, found->f0);
                        DebugMenuItem_SetText(&obj->items[count], line);
                    } else if ((unsigned short)entry->key == 0) {
                        DebugMenuItem_SetText(&obj->items[count], entry->name);
                    } else {
                        DebugMenuItem_SetText(&obj->items[count], data_ov015_0219450f);
                    }
                } else if (func_ov015_02190d08(obj) != 0) {
                    struct Element020dedd0* elem = ItemTable_Find((ItemTable*)obj->container, entry->key);
                    if (elem != 0) {
                        if (elem->name != 0) {
                            DebugMenuItem_SetText(&obj->items[count], elem->name);
                        } else {
                            DebugMenuItem_SetText(&obj->items[count], entry->name);
                        }
                    } else {
                        DebugMenuItem_SetText(&obj->items[count], entry->name);
                    }
                } else if (obj->state == 38) {
                    unsigned char var11;

                    __clear(marked, 0x80);
                    var11 = 0;
                    switch (count) {
                    case 0:
                        var11 = obj->unknown_19c_[0];
                        break;
                    case 1:
                        var11 = obj->unknown_19c_[1];
                        break;
                    case 2:
                        var11 = obj->unknown_19c_[2];
                        break;
                    case 3:
                        var11 = obj->unknown_19c_[3];
                        break;
                    case 4:
                        var11 = obj->unknown_19c_[4];
                        break;
                    }
                    if (var11 != 0) {
                        sprintf(marked, data_ov015_02194517);
                    } else {
                        sprintf(marked, data_ov015_0219451b);
                    }
                    strcat(marked, entry->name);
                    DebugMenuItem_SetText(&obj->items[count], marked);
                } else {
                    DebugMenuItem_SetText(&obj->items[count], entry->name);
                }
                DebugMenu_AddItem((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[count]);
                count++;
                idx++;
                entry = func_ov015_02193160(obj, obj->state, &idx);
            }
        }
        func_ov015_0219313c((Struct_ov015_02192700_9*)&obj->menu, 0, count - 1);
        func_ov015_02193150((Struct_ov015_02192700_10*)&obj->menu, obj->unknown_268_[obj->state]);
        DebugMenu_UpdateLayout(&obj->menu);
        DebugMenu_Open((char*)&obj->menu, 1);
    } else {
        struct Struct_ov015_02192700_7* it;
        struct Struct_ov015_02192700_7* holder;

        DebugMenuItem_SetText(&obj->menu, data_ov015_0219451f);
        count = 0;
        for (it = func_ov015_0218f344(obj->unknown_30_); it != 0; it = it->next) {
            struct BCFG* var14 = (struct BCFG*)it->unknown_4_;
            if (var14 != 0) {
                count += var14->GetNumAnimations();
            }
        }
        obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
        holder = func_ov015_0218f344(obj->unknown_30_);
        idx = 0;
        for (; holder != 0; holder = holder->next) {
            struct BCFG* var15 = (struct BCFG*)holder->unknown_4_;
            if (var15 != 0) {
                int num = var15->GetNumAnimations();
                for (int i = 0; i < num; i++) {
                    const char* name = (const char*)var15->GetAnimationRecord(i);
                    if (name != 0) {
                        DebugMenuItem_Init((char*)&obj->items[idx]);
                        DebugMenuItem_SetText(&obj->items[idx], name);
                        DebugMenu_AddItem((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[idx++]);
                    }
                }
            }
        }
        func_ov015_0219313c((Struct_ov015_02192700_9*)&obj->menu, 0, count - 1);
        func_ov015_02193150((Struct_ov015_02192700_10*)&obj->menu, 0);
        DebugMenu_UpdateLayout(&obj->menu);
        DebugMenu_Open((char*)&obj->menu, 1);
    }

    int visible = obj->menu.visibleCount;
    float ratio = (float)visible / (float)count;
    if (ratio > 1.0f) {
        ratio = 1.0f;
    }
    obj->unknown_348_ = (int)(156.0f * ratio);
    int hidden = count - visible;
    obj->unknown_34c_ = (float)(156 - obj->unknown_348_) / (float)hidden;
    if (obj->unknown_348_ < 4) {
        obj->unknown_34c_ -= (float)(4 - obj->unknown_348_) / (float)hidden;
        obj->unknown_348_ = 4;
    }
    obj->unknown_350_ = 1;
}
