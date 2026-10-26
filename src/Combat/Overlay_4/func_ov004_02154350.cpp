#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov004_02154350_3 { unsigned int field_0; SafeAllocator allocator; };
struct Struct_ov004_02154350 { short category; short index; unsigned char total; unsigned char matched; };
struct Struct_ov004_02154350_2 { Struct_ov004_02154350 entries[20]; unsigned short total; unsigned short matched; unsigned char unknown_7c_; };
struct ItemTable;
struct ObjStruct_021e1474;
extern "C" Struct_ov004_02154350_3* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov004_02153b6c(void*, int, int, int, short*, short*);
extern "C" void func_ov004_021545f0(Struct_ov004_02154350_2*, int, short, short, unsigned char, unsigned char);
extern "C" void func_ov023_021e1518(void*);
extern "C" void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, ItemTable*);
extern Struct_ov004_02154350_2* data_ov004_021707c0;

class Struct_ov004_02154350_4 {
public:
    virtual void v00(); virtual void inline_ov004_02154350(); virtual void inline_ov004_02154350_2(); virtual void inline_ov004_02154350_3();
    virtual void v04(); virtual void inline_ov004_02154350_5(); virtual void inline_ov004_02154350_6(); virtual void inline_ov004_02154350_7();
    virtual void v08(); virtual void inline_ov004_02154350_9(); virtual void v10(); virtual void inline_ov004_02154350_11();
    virtual void inline_ov004_02154350_12(); virtual void inline_ov004_02154350_13(); virtual void v14(); virtual void inline_ov004_02154350_15();
    virtual void inline_ov004_02154350_16(); virtual void inline_ov004_02154350_17(); virtual void v18(); virtual void inline_ov004_02154350_19();
    virtual void v20(); virtual void inline_ov004_02154350_21(); virtual void inline_ov004_02154350_22(); virtual void inline_ov004_02154350_23();
    virtual void v24(); virtual void inline_ov004_02154350_25(); virtual void inline_ov004_02154350_26(); virtual void inline_ov004_02154350_27();
    virtual void v28(); virtual void inline_ov004_02154350_29(); virtual void v30(); virtual void inline_ov004_02154350_31();
    virtual void inline_ov004_02154350_32(); virtual void inline_ov004_02154350_33(); virtual void v34(); virtual void inline_ov004_02154350_35();
    virtual void inline_ov004_02154350_36(); virtual void inline_ov004_02154350_37(); virtual void v38(); virtual void inline_ov004_02154350_39();
    virtual void v40(); virtual void inline_ov004_02154350_41(); virtual void inline_ov004_02154350_42(); virtual void inline_ov004_02154350_43();
    virtual void v44(); virtual void inline_ov004_02154350_45(); virtual void inline_ov004_02154350_46(); virtual void inline_ov004_02154350_47();
    virtual void v48(); virtual void inline_ov004_02154350_49(); virtual void v50(); virtual void inline_ov004_02154350_51();
    virtual void inline_ov004_02154350_52(); virtual void inline_ov004_02154350_53(); virtual void v54(); virtual void inline_ov004_02154350_55();
    virtual void inline_ov004_02154350_56(); virtual void inline_ov004_02154350_57();
    virtual ItemTable* GetContainer();
    virtual ObjStruct_021e1474* GetEntries();
};

// USA: func_ov004_02154350
extern "C" ARM int func_ov004_02154350(void* self) {
    Struct_ov004_02154350_3* node = func_ov011_021845f8(self, 0);
    if (!node) return 0;
    Struct_ov004_02154350_2* table = (Struct_ov004_02154350_2*)node->allocator.Allocate(0x7e);
    data_ov004_021707c0 = table;
    if (!table) return 0;
    for (unsigned char i = 0; i < 20; i++) {
        table->entries[i].category = -1;
        table->entries[i].index = -1;
        table->entries[i].total = 0;
        table->entries[i].matched = 0;
    }
    table->total = 0;
    table->matched = 0;
    table->unknown_7c_ = 0;
    short matched = 0;
    short total = 0;
    unsigned char i = 0;
    signed char category;
    for (category = 0; category <= 11; category++) {
        func_ov004_02153b6c(self, -1, 0, category, &matched, &total);
        func_ov004_021545f0(data_ov004_021707c0, i, 0, category, total, matched);
        i++;
    }
    for (category = 1; category <= 6; category++, i++) {
        func_ov004_02153b6c(self, -1, category, -1, &matched, &total);
        func_ov004_021545f0(data_ov004_021707c0, i, category, -1, total, matched);
    }
    func_ov004_02153b6c(self, -1, 7, -1, &matched, &total);
    func_ov004_021545f0(data_ov004_021707c0, i, 7, -1, total, matched);
    Struct_ov004_02154350_2* var7 = data_ov004_021707c0;
    for (unsigned char j = 0; j < 20; j++) {
        Struct_ov004_02154350* entry = &var7->entries[j];
        var7->total += entry->total;
        var7->matched += entry->matched;
    }
    Struct_ov004_02154350_4* source = (Struct_ov004_02154350_4*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
    Struct_ov004_02154350_4* destination = (Struct_ov004_02154350_4*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (source && destination) {
        ObjStruct_021e1474* entries = destination->GetEntries();
        if (entries) {
            func_ov023_021e1518(entries);
            RefreshEntryStatusFlags_021e1474(entries, source->GetContainer());
        }
    }
    return 0;
}
