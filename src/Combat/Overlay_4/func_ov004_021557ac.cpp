#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


struct AllocationNode021557ac { unsigned int field_0; SafeAllocator allocator; };
struct Entry021557ac { short category; short index; unsigned char total; unsigned char matched; };
struct Table021557ac { Entry021557ac entries[2]; unsigned short total; unsigned short matched; unsigned char side; };
struct ItemTable;
struct ObjStruct_021e1474;
struct Save021557ac { unsigned char field_0[0x8c]; unsigned char bits[1]; };
struct Item021557ac { unsigned int field_0; unsigned int field_4; unsigned int field_8; unsigned int flags; };
extern "C" AllocationNode021557ac* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" Save021557ac* Scenario_GetInstance();
extern "C" int func_020deb58(ItemTable*, int, int, int, int);
extern "C" Item021557ac* func_020dec30(ItemTable*, int, int, int, int, int);
int Scenario_TestFlag(int, unsigned char*, int);
void ClearElements_021e1518(void*);
void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, ItemTable*);
extern Table021557ac* data_ov004_021707c4;

class Struct_ov004_021557ac {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57();
    virtual ItemTable* GetContainer();
    virtual ObjStruct_021e1474* GetEntries();
};

// USA: func_ov004_021557ac
extern "C" ARM int func_ov004_021557ac(void* arg0) {
    Struct_ov004_021557ac_2* var0 = func_ov011_021845f8(arg0, 0);
    if (!var0) return 0;
    Struct_ov004_021557ac_4* var1 = (Struct_ov004_021557ac_4*)var0->unknown_4_.Allocate(0x12);
    data_ov004_021707c4 = var1;
    if (!var1) return 0;
    for (unsigned char var2 = 0; var2 < 2; var2++) {
        var1->unknown_0_[var2].unknown_0_ = -1;
        var1->unknown_0_[var2].unknown_2_ = -1;
        var1->unknown_0_[var2].unknown_4_ = 0;
        var1->unknown_0_[var2].unknown_5_ = 0;
    }
    table->total = 0;
    table->matched = 0;
    table->side = 0;
    unsigned char index = 0;
    short category = 8;
    short i;
    short matched = 0;
    long total = 0;
    for (; category <= 9; category++, index++) {
        Node021557ac* source = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
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
        var1 = data_ov004_021707c4;
        var1->unknown_0_[var3].unknown_0_ = var4;
        var1->unknown_0_[var3].unknown_2_ = -1;
        var1->unknown_0_[var3].unknown_4_ = var7;
        var1->unknown_0_[var3].unknown_5_ = var6;
    }
    Struct_ov004_021557ac_4* var13 = data_ov004_021707c4;
    for (unsigned char var14 = 0; var14 < 2; var14++) {
        Struct_ov004_021557ac_3* var15 = &var13->unknown_0_[var14];
        var13->unknown_c_ += var15->unknown_4_;
        var13->unknown_e_ += var15->unknown_5_;
    }
    Struct_ov004_021557ac* var16 = (Struct_ov004_021557ac*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0x2d);
    Struct_ov004_021557ac* var17 = (Struct_ov004_021557ac*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0x39);
    if (var16 && var17) {
        Struct_ov002_0215b2c8* var18 = var17->inline_ov004_021557ac_60();
        if (var18) {
            func_ov023_021e1518(var18);
            func_ov023_021e1474(var18, var16->inline_ov004_021557ac_59());
        }
    }
    return 0;
}
