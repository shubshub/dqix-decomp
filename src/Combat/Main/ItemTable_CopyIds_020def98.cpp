#include <globaldefs.h>
#include "Resource/ItemTable.h"

#include "Memory/SafeAllocator.h"

struct Struct_0201099c_9 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned char unknown_8_[0x18];
};

struct Struct_0208358c_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    short unknown_18_;
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
};

struct EntryDf618;
struct EntryDf6cc;
struct StructDE1D4;

typedef int (*Type_020de5fc)(Struct_0201099c_9*);

int GetField0x18Short_020de56c(void*);
Element020de650* BinarySearchByComparator020de650(ItemTable* c, int key, KeyFunc020de650 fn);
int CopyEntryAndAllocateStrings020df618(SafeAllocator*, void*, EntryDf618*, void**, int, EntryDf618*);
int CopyEntryAndIncrementCounter020df6cc(void*, EntryDf6cc*, int, EntryDf6cc*);
void ItemRecord_Copy(Record020836e4* dst, Record020836e4* src);
void ItemRecord_Clear(StructDE1D4*);

static inline void SwapRecords(Record020836e4* a, Record020836e4* b) {
    Record020836e4 tmp = *a;
    ItemRecord_Copy(a, b);
    ItemRecord_Copy(b, &tmp);
}

// Main, originally func_020def98 (USA 0x020def98, EUR 0x020defa8, JPN 0x020e0b10)
extern "C" ARM int ItemTable_CopyIds(SafeAllocator* allocator, ItemTable* dest,
    ItemTable* source, short* keys, short keyCount) {
    if (!dest || !source || !keys || !keyCount) return 0;
    Record020836e4* output = (Record020836e4*)dest->entries;
    if (!source->entries) return 0;
    if (allocator && !output) {
        int n = keyCount;
        int count = 0;
        int nameCount = 0;
        short* key = keys;
        for (int i = 0; i < n; i++, key++) {
            int value = *key;
            if (value < 0) continue;
            Element020de650* found = BinarySearchByComparator020de650(source, value, (KeyFunc020de650)GetField0x18Short_020de56c);
            if (!found) continue;
            int dup = 0;
            short* prev = keys;
            for (int j = 0; j < i; j++, prev++) {
                if (*prev == value) { dup = 1; break; }
            }
            if (var8) continue;
            var2++;
            if (var7->unknown_0_) var3++;
        }
        output = (Record020836e4*)allocator->Allocate((count + n) * 32);
        dest->count = count;
        dest->copiedNames = (unsigned short)nameCount;
        dest->entries = (Element020de650*)output;
    }
    if (!var0) return 0;
    int var11;
    int var12;
    int var13 = arg4;
    arg1->unknown_4_ = var13;
    arg1->unknown_6_ = arg1->unknown_2_0_;
    void* var14 = arg0 ? var0 + var13 : NULL;
    arg1->unknown_2_0_ = 0;
    var11 = 0;
    short* var15 = arg3;
    for (var12 = 0; var12 < var13; var12++, var15++) {
        short var16 = *var15;
        Struct_0201099c_9* var17 = NULL;
        if (var16 >= 0) var17 = func_020de650(arg2, var16, (Type_020de5fc)func_020de56c);
        if (!var17) {
            if (!arg0) { var0++; var11++; }
            continue;
        }
        if (arg0) {
            int var18 = 0;
            short* var19 = arg3;
            for (int var20 = 0; var20 < var12; var20++, var19++) {
                if (*var19 == var16) { var18 = 1; break; }
            }
            if (var18) continue;
            func_020df618(arg0, arg1, (Struct_020def98*)var0, &var14, (int)arg2, (Struct_020def98*)var17);
        } else {
            func_020df6cc(arg1, (Struct_020def98_2*)var0, (int)arg2, (Struct_020def98_2*)var17);
        }
        if (var11 >= var13) break;
        var0++;
        var11++;
    }
    dest->count = copied;
    dest->owned = 0;
    if (allocator && dest->count >= 2) {
        const ItemTable* c = dest;
        if (c != NULL) {
            int n = c->count;
            if (c->entries != NULL && n != 0) {
                int j;
                Record020836e4* prev;
                Record020836e4* q;
                int first;
                Record020836e4* p;
                int last;
                int m;
                int hi;
                int lo;
                lo = 0;
                hi = n - 1;
                for (;;) {
                    last = -1;
                    p = (Record020836e4*)c->entries + lo;
                    for (j = lo; j < hi; j++) {
                        if (p[0].field_18 > p[1].field_18) {
                            last = j;
                            SwapRecords(p, p + 1);
                        }
                        var27++;
                    }
                    if (last == -1) break;
                    hi = last;
                    first = -1;
                    q = (Record020836e4*)c->entries + hi;
                    for (m = hi; m > lo; m--) {
                        prev = q - 1;
                        if (prev->field_18 > q->field_18) {
                            first = m;
                            Record020836e4 tmp = *q;
                            ItemRecord_Copy(q, prev);
                            ItemRecord_Copy(prev, &tmp);
                        }
                        var25 = var24;
                    }
                    if (var26 == -1) break;
                    var31 = var26;
                }
            }
        }
    }
    int end = dest->capacity;
    Record020836e4* e = (Record020836e4*)dest->entries + dest->count;
    for (i = dest->count; i < end; i++, e++) ItemRecord_Clear((StructDE1D4*)e);
    return 1;
}
