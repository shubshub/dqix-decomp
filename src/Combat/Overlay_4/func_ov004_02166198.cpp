#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>


struct Struct_ov004_02166198 {
    unsigned short unknown_0_0_ : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short unknown_1_2_ : 1;
    unsigned short unknown_1_3_ : 1;
    unsigned short unknown_1_4_ : 1;
    unsigned short unknown_1_5_ : 3;
};
struct Struct_02065990_3 {
    unsigned char unknown_0_[0xa8];
    Struct_ov004_02166198* unknown_a8_;
    unsigned char unknown_ac_[0xcc];
};
struct Struct_0205faf4_3;
struct Struct_0205faf4_13;
struct Struct_ov000_02179cdc_2 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 1;
    unsigned short unknown_2_3_ : 1;
    unsigned short unknown_2_4_ : 1;
    unsigned short unknown_2_5_ : 1;
    unsigned short unknown_2_6_ : 10;
    char unknown_4_[4];
    int unknown_8_;
};
struct Struct_ov004_02166198_2 {
    Struct_ov000_02179cdc_2* unknown_0_;
    Struct_ov000_02179cdc_2* unknown_4_;
    unsigned char unknown_8_[0x28];
    SafeAllocator unknown_30_;
    unsigned char unknown_44_[4];
    short unknown_48_;
    short unknown_4a_;
    short unknown_4c_;
    short unknown_4e_;
};
int* GetGlobal02109418_02094d6c();
extern "C" void* Scenario_GetInstance();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
int TestBitInByteArrayAt0x84_02096088(void*, int);
extern "C" void func_ov004_021660f4();
struct Struct_ov004_0217101c_2 {
#if defined(jpn)
    void** unknown_0_;
    Struct_ov004_02166198_2* unknown1_0_;
#else
    Struct_ov004_02166198_2* unknown1_0_;
    void** unknown_4_;
#endif
    Struct_ov004_02166198_2* inline_ov004_02166198() { return unknown1_0_; }
};
extern Struct_ov004_0217101c_2 data_ov004_0217101c;
#if defined(jpn)
extern char data_ov004_02170e54[];
#else
extern char data_ov004_021705a0[];
#endif

// USA: func_ov004_02166198
extern "C" ARM void func_ov004_02166198() {
    MenuEntry* regular;
    MenuEntry* special;
    TableItem* items;
    MenuLists* lists = data_ov004_0217101c.GetMain();
    short count = lists->count;
    GetTableByteOrFFData* table = (GetTableByteOrFFData*)(GetGlobal02109418_02094d6c());
    items = table->items;
    void* save = Scenario_GetInstance();
    short regularCount = 0;
    short specialCount = 0;
    TableItem* firstItem;
    short firstIndex;
    for (firstIndex = 1; firstIndex <= count; firstIndex++) {
        int id = GetTableByteOrFF_020965ac(table, (unsigned char)(firstIndex));
        firstItem = items;
        int j;
        for (j = 0; j < 0xcc; j++, firstItem++) {
            if (firstItem->id == id) break;
        }
        if (var12 == 0xcc) continue;
        if (var9->unknown_0_0_ == 0 || var9->unknown_0_0_ >= 0xff) continue;
        int var13 = func_0206e120((Struct_0205faf4_3*)(var6), var9->unknown_0_0_);
        if (var9->unknown_1_2_) {
            if (func_0206e2dc((Struct_0205faf4_13*)(var6), var9->unknown_0_0_)) var8++;
        } else {
            switch (var13) {
            case 1:
                if (func_02096088(var5, var9->unknown_0_0_)) var7++;
                break;
            case 2:
            case 3:
                var7++;
                break;
#if !defined(jpn)
            case 0:
                if (func_02096088(var5, var9->unknown_0_0_)) var7++;
                break;
#endif
            }
        }
    }
    var3->unknown_48_ = var7;
    var3->unknown_4a_ = var8;
    var3->unknown_0_ = 0;
    var3->unknown_4_ = 0;
    var3->unknown_30_.Reset();
    if (var7) var3->unknown_0_ = (Struct_ov000_02179cdc_2*)(var3->unknown_30_.Allocate(var7 * sizeof(Struct_ov000_02179cdc_2)));
    if (var8) var3->unknown_4_ = (Struct_ov000_02179cdc_2*)(var3->unknown_30_.Allocate(var8 * sizeof(Struct_ov000_02179cdc_2)));
    short var14 = 0;
    short var15 = 0;
    var0 = var3->unknown_0_;
    var1 = var3->unknown_4_;
    for (short var16 = 1; var16 <= var4; var16++) {
        int var17;
        int var18 = func_020965ac(var5, (unsigned char)(var16));
        Struct_ov004_02166198* var19 = var2;
        int var20;
        for (var20 = 0; var20 < 0xcc; var20++, var19++) {
            if (var19->unknown_0_0_ == var18) break;
        }
        if (var20 == 0xcc) continue;
        if (var19->unknown_0_0_ == 0 || var19->unknown_0_0_ >= 0xff) continue;
        var17 = func_0206e120((Struct_0205faf4_3*)(var6), var19->unknown_0_0_);
        bool var21 = false;
        if (var19->unknown_1_2_) {
            if (func_0206e2dc((Struct_0205faf4_13*)(var6), var19->unknown_0_0_)) {
                var21 = true;
                if (var17 == 1 && func_02096088(var5, var19->unknown_0_0_)) var17 = 3;
            }
        } else {
            switch (var17) {
            case 1:
                if (func_02096088(var5, var19->unknown_0_0_)) { var21 = true; var17 = 3; }
                break;
            case 2:
            case 3:
                var21 = true;
                break;
#if !defined(jpn)
            case 0:
                if (func_02096088(var5, var19->unknown_0_0_)) { var21 = true; var17 = 3; }
                break;
#endif
            }
        }
        if (!var21) continue;
        short* var22 = &var14;
        Struct_ov000_02179cdc_2* var23 = &var0[var14];
        if (var19->unknown_1_2_) {
            var22 = &var15;
            var23 = &var1[var15];
        }
        var23->unknown_0_ = -1;
        var23->unknown_2_0_ = 0;
        var23->unknown_2_2_ = 0;
        var23->unknown_2_3_ = 0;
        var23->unknown_2_4_ = 0;
        var23->unknown_2_5_ = 0;
        var23->unknown_8_ = 0;
        memset(var23->unknown_4_, 0, sizeof(var23->unknown_4_));
        var23->unknown_0_ = var16;
        var23->unknown_2_0_ = (unsigned short)(var17);
        var23->unknown_2_2_ = var19->unknown_1_2_;
        var23->unknown_2_3_ = var19->unknown_1_4_;
        var23->unknown_2_4_ = var19->unknown_1_1_;
        var23->unknown_2_5_ = var19->unknown_1_3_;
#if defined(jpn)
        sprintf(var23->unknown_4_, data_ov004_02170e54, var16);
#else
        sprintf(var23->unknown_4_, data_ov004_021705a0, var16);
#endif
        var23->unknown_8_ = 0;
        (*var22)++;
    }
    func_ov004_021660f4();
}
