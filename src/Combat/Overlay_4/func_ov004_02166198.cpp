#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>


struct Struct_ov004_02166198 {
    unsigned short id : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short special : 1;
    unsigned short flag11 : 1;
    unsigned short unknown_1_4_ : 1;
    unsigned short reserved : 3;
};
struct Struct_02065990_3 {
    unsigned char field_0x0[0xa8];
    Struct_ov004_02166198* items;
    unsigned char bytes[0xcc];
};
struct PackedNibbleArray0206e120;
struct Struct_0205faf4_13;
struct MenuEntry {
    short index;
    unsigned short state : 2;
    unsigned short special : 1;
    unsigned short unknown_2_3_ : 1;
    unsigned short unknown_2_4_ : 1;
    unsigned short flag11 : 1;
    unsigned short reserved : 10;
    char name[4];
    int unknown_8_;
};
struct Struct_ov004_02166198_2 {
    MenuEntry* unknown_0_;
    MenuEntry* special;
    unsigned char unknown_8_[0x28];
    SafeAllocator allocator;
    unsigned char unknown_44_[4];
    short unknown_48_;
    short unknown_4a_;
    short unknown_4c_;
    short count;
};
extern "C" int* func_02094d6c();
extern "C" void* Scenario_GetInstance();
extern "C" unsigned char func_020965ac(Struct_02065990_3*, unsigned char);
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_0206e2dc(Struct_0205faf4_13*, int);
extern "C" int func_02096088(void*, int);
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
    MenuEntry* var0;
    MenuEntry* special;
    Struct_ov004_02166198* items;
    Struct_ov004_02166198_2* lists = data_ov004_0217101c.inline_ov004_02166198();
    short count = lists->count;
    Struct_02065990_3* table = (Struct_02065990_3*)(func_02094d6c());
    items = table->items;
    void* save = Scenario_GetInstance();
    short var7 = 0;
    short var8 = 0;
    Struct_ov004_02166198* var9;
    short var10;
    for (var10 = 1; var10 <= count; var10++) {
        int id = func_020965ac(table, (unsigned char)(var10));
        var9 = items;
        int j;
        for (j = 0; j < 0xcc; j++, var9++) {
            if (var9->id == id) break;
        }
        if (j == 0xcc) continue;
        if (var9->id == 0 || var9->id >= 0xff) continue;
        int state = func_0206e120((PackedNibbleArray0206e120*)(save), var9->id);
        if (var9->special) {
            if (func_0206e2dc((Struct_0205faf4_13*)(save), var9->id)) var8++;
        } else {
            switch (state) {
            case 1:
                if (func_02096088(table, var9->id)) var7++;
                break;
            case 2:
            case 3:
                var7++;
                break;
#if !defined(jpn)
            case 0:
                if (func_02096088(table, var9->id)) var7++;
                break;
#endif
            }
        }
    }
    lists->unknown_48_ = var7;
    lists->unknown_4a_ = var8;
    lists->unknown_0_ = 0;
    lists->special = 0;
    lists->allocator.Reset();
    if (var7) lists->unknown_0_ = (MenuEntry*)(lists->allocator.Allocate(var7 * sizeof(MenuEntry)));
    if (var8) lists->special = (MenuEntry*)(lists->allocator.Allocate(var8 * sizeof(MenuEntry)));
    short var14 = 0;
    short var15 = 0;
    var0 = lists->unknown_0_;
    special = lists->special;
    for (short i = 1; i <= count; i++) {
        int state;
        int id = func_020965ac(table, (unsigned char)(i));
        Struct_ov004_02166198* item = items;
        int j;
        for (j = 0; j < 0xcc; j++, item++) {
            if (item->id == id) break;
        }
        if (j == 0xcc) continue;
        if (item->id == 0 || item->id >= 0xff) continue;
        state = func_0206e120((PackedNibbleArray0206e120*)(save), item->id);
        bool var21 = false;
        if (item->special) {
            if (func_0206e2dc((Struct_0205faf4_13*)(save), item->id)) {
                var21 = true;
                if (state == 1 && func_02096088(table, item->id)) state = 3;
            }
        } else {
            switch (state) {
            case 1:
                if (func_02096088(table, item->id)) { var21 = true; state = 3; }
                break;
            case 2:
            case 3:
                var21 = true;
                break;
#if !defined(jpn)
            case 0:
                if (func_02096088(table, item->id)) { var21 = true; state = 3; }
                break;
#endif
            }
        }
        if (!var21) continue;
        short* index = &var14;
        MenuEntry* entry = &var0[var14];
        if (item->special) {
            index = &var15;
            entry = &special[var15];
        }
        entry->index = -1;
        entry->state = 0;
        entry->special = 0;
        entry->unknown_2_3_ = 0;
        entry->unknown_2_4_ = 0;
        entry->flag11 = 0;
        entry->unknown_8_ = 0;
        memset(entry->name, 0, sizeof(entry->name));
        entry->index = i;
        entry->state = (unsigned short)(state);
        entry->special = item->special;
        entry->unknown_2_3_ = item->unknown_1_4_;
        entry->unknown_2_4_ = item->unknown_1_1_;
        entry->flag11 = item->flag11;
#if defined(jpn)
        sprintf(entry->name, data_ov004_02170e54, i);
#else
        sprintf(entry->name, data_ov004_021705a0, i);
#endif
        entry->unknown_8_ = 0;
        (*index)++;
    }
    func_ov004_021660f4();
}
