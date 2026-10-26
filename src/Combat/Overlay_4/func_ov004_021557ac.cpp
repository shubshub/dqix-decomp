#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


struct Struct_ov004_021557ac_2 { unsigned int field_0; SafeAllocator allocator; };
struct Struct_ov004_021557ac_3 { short category; short index; unsigned char total; unsigned char matched; };
struct Struct_ov004_021557ac_4 { Struct_ov004_021557ac_3 entries[2]; unsigned short total; unsigned short matched; unsigned char unknown_10_; };
struct ItemTable;
struct ObjStruct_021e1474;
struct Save021557ac { unsigned char field_0[0x8c]; unsigned char bits[1]; };
struct Item021557ac { unsigned int field_0; unsigned int unknown_4_; unsigned int field_8; unsigned int flags; };
extern "C" Struct_ov004_021557ac_2* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" Save021557ac* Scenario_GetInstance();
extern "C" int func_020deb58(ItemTable*, int, int, int, int);
extern "C" Item021557ac* func_020dec30(ItemTable*, int, int, int, int, int);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void func_ov023_021e1518(void*);
extern "C" void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, ItemTable*);
extern Struct_ov004_021557ac_4* data_ov004_021707c4;

class Struct_ov004_021557ac {
public:
    virtual void v00(); virtual void inline_ov004_021557ac_2(); virtual void inline_ov004_021557ac_3(); virtual void inline_ov004_021557ac_4();
    virtual void v04(); virtual void inline_ov004_021557ac_6(); virtual void inline_ov004_021557ac_7(); virtual void inline_ov004_021557ac_8();
    virtual void v08(); virtual void inline_ov004_021557ac_10(); virtual void v10(); virtual void inline_ov004_021557ac_12();
    virtual void inline_ov004_021557ac_13(); virtual void inline_ov004_021557ac_14(); virtual void v14(); virtual void inline_ov004_021557ac_16();
    virtual void inline_ov004_021557ac_17(); virtual void inline_ov004_021557ac_18(); virtual void v18(); virtual void inline_ov004_021557ac_20();
    virtual void v20(); virtual void inline_ov004_021557ac_22(); virtual void inline_ov004_021557ac_23(); virtual void inline_ov004_021557ac_24();
    virtual void v24(); virtual void inline_ov004_021557ac_26(); virtual void inline_ov004_021557ac_27(); virtual void inline_ov004_021557ac_28();
    virtual void v28(); virtual void inline_ov004_021557ac_30(); virtual void v30(); virtual void inline_ov004_021557ac_32();
    virtual void inline_ov004_021557ac_33(); virtual void inline_ov004_021557ac_34(); virtual void v34(); virtual void inline_ov004_021557ac_36();
    virtual void inline_ov004_021557ac_37(); virtual void inline_ov004_021557ac_38(); virtual void v38(); virtual void inline_ov004_021557ac_40();
    virtual void v40(); virtual void inline_ov004_021557ac_42(); virtual void inline_ov004_021557ac_43(); virtual void inline_ov004_021557ac_44();
    virtual void v44(); virtual void inline_ov004_021557ac_46(); virtual void inline_ov004_021557ac_47(); virtual void inline_ov004_021557ac_48();
    virtual void v48(); virtual void inline_ov004_021557ac_50(); virtual void v50(); virtual void inline_ov004_021557ac_52();
    virtual void inline_ov004_021557ac_53(); virtual void inline_ov004_021557ac_54(); virtual void v54(); virtual void inline_ov004_021557ac_56();
    virtual void inline_ov004_021557ac_57(); virtual void inline_ov004_021557ac_58();
    virtual ItemTable* GetContainer();
    virtual ObjStruct_021e1474* GetEntries();
};

// USA: func_ov004_021557ac
extern "C" ARM int func_ov004_021557ac(void* self) {
    Struct_ov004_021557ac_2* node = func_ov011_021845f8(self, 0);
    if (!node) return 0;
    Struct_ov004_021557ac_4* table = (Struct_ov004_021557ac_4*)node->allocator.Allocate(0x12);
    data_ov004_021707c4 = table;
    if (!table) return 0;
    for (unsigned char index = 0; index < 2; index++) {
        table->entries[index].category = -1;
        table->entries[index].index = -1;
        table->entries[index].total = 0;
        table->entries[index].matched = 0;
    }
    table->total = 0;
    table->matched = 0;
    table->unknown_10_ = 0;
    unsigned char index = 0;
    short category = 8;
    short i;
    short matched = 0;
    long total = 0;
    for (; category <= 9; category++, index++) {
        Struct_ov004_021557ac* source = (Struct_ov004_021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
        if (source && func_ov023_021f6f10(source) == 0x11) {
            ItemTable* container = source->GetContainer();
            Save021557ac* save = Scenario_GetInstance();
            total = func_020deb58(container, 0, -1, (signed char)category, -1);
            matched = 0;
            for (i = 0; i < total; i++) {
                Item021557ac* item = func_020dec30(container, i, 0, -1, (signed char)category, -1);
                if (item) {
                    int id = (unsigned short)((item->flags << 9) >> 21);
                    if (id > 0 && Scenario_TestFlag((int)save, save->bits, id + 0x76 + 0xc00)) matched++;
                }
            }
        }
        table = data_ov004_021707c4;
        table->entries[index].category = category;
        table->entries[index].index = -1;
        table->entries[index].total = total;
        table->entries[index].matched = matched;
    }
    Struct_ov004_021557ac_4* var13 = data_ov004_021707c4;
    for (unsigned char j = 0; j < 2; j++) {
        Struct_ov004_021557ac_3* entry = &var13->entries[j];
        var13->total += entry->total;
        var13->matched += entry->matched;
    }
    Struct_ov004_021557ac* source = (Struct_ov004_021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
    Struct_ov004_021557ac* destination = (Struct_ov004_021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (source && destination) {
        ObjStruct_021e1474* entries = destination->GetEntries();
        if (entries) {
            func_ov023_021e1518(entries);
            RefreshEntryStatusFlags_021e1474(entries, source->GetContainer());
        }
    }
    return 0;
}
