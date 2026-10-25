#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct AllocationNode02154350 { unsigned int field_0; SafeAllocator allocator; };
struct Entry02154350 { short category; short index; unsigned char total; unsigned char matched; };
struct Table02154350 { Entry02154350 entries[20]; unsigned short total; unsigned short matched; unsigned char side; };
struct ItemTable;
struct ObjStruct_021e1474;
extern "C" AllocationNode02154350* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov004_02153b6c(void*, int, int, int, short*, short*);
extern "C" void func_ov004_021545f0(Table02154350*, int, short, short, unsigned char, unsigned char);
void ClearElements_021e1518(void*);
void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, ItemTable*);
extern Table02154350* data_ov004_021707c0;

class Struct_ov004_02154350_4 {
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

// USA: func_ov004_02154350
extern "C" ARM int func_ov004_02154350(void* arg0) {
    Struct_ov004_02154350_3* var0 = func_ov011_021845f8(arg0, 0);
    if (!var0) return 0;
    Struct_ov004_02154350_2* var1 = (Struct_ov004_02154350_2*)var0->unknown_4_.Allocate(0x7e);
    data_ov004_021707c0 = var1;
    if (!var1) return 0;
    for (unsigned char var2 = 0; var2 < 20; var2++) {
        var1->unknown_0_[var2].unknown_0_ = -1;
        var1->unknown_0_[var2].unknown_2_ = -1;
        var1->unknown_0_[var2].unknown_4_ = 0;
        var1->unknown_0_[var2].unknown_5_ = 0;
    }
    var1->unknown_78_ = 0;
    var1->unknown_7a_ = 0;
    var1->unknown_7c_ = 0;
    short var3 = 0;
    short var4 = 0;
    unsigned char var5 = 0;
    signed char var6;
    for (var6 = 0; var6 <= 11; var6++) {
        func_ov004_02153b6c(arg0, -1, 0, var6, &var3, &var4);
        func_ov004_021545f0(data_ov004_021707c0, var5, 0, var6, var4, var3);
        var5++;
    }
    for (var6 = 1; var6 <= 6; var6++, var5++) {
        func_ov004_02153b6c(arg0, -1, var6, -1, &var3, &var4);
        func_ov004_021545f0(data_ov004_021707c0, var5, var6, -1, var4, var3);
    }
    func_ov004_02153b6c(arg0, -1, 7, -1, &var3, &var4);
    func_ov004_021545f0(data_ov004_021707c0, var5, 7, -1, var4, var3);
    Struct_ov004_02154350_2* var7 = data_ov004_021707c0;
    for (unsigned char var8 = 0; var8 < 20; var8++) {
        Struct_ov004_02154350* var9 = &var7->unknown_0_[var8];
        var7->unknown_78_ += var9->unknown_4_;
        var7->unknown_7a_ += var9->unknown_5_;
    }
    Struct_ov004_02154350_4* var10 = (Struct_ov004_02154350_4*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0x2d);
    Struct_ov004_02154350_4* var11 = (Struct_ov004_02154350_4*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0x39);
    if (var10 && var11) {
        Struct_ov002_0215b2c8* var12 = var11->inline_ov004_02154350_59();
        if (var12) {
            func_ov023_021e1518(var12);
            func_ov023_021e1474(var12, var10->inline_ov004_02154350_58());
        }
    }
    return 0;
}
