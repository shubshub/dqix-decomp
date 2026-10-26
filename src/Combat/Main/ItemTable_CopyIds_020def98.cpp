#include <globaldefs.h>
#include "Resource/ItemTable.h"

#include "Memory/SafeAllocator.h"

struct Element020de650 {
    void* name;
    void* desc;
    unsigned char data[0x18];
};

struct Record020836e4 {
    int field_0;
    int unknown_4_;
    int field_8;
    int unknown_c_;
    int unknown_10_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    short field_18;
    unsigned short field_1a;
    unsigned short field_1c;
};

struct Struct_020def98;
struct Struct_020def98_2;
struct StructDE1D4;

typedef int (*KeyFunc020de650)(Element020de650*);

extern "C" int func_020de56c(void*);
extern "C" Element020de650* BinarySearchByComparator020de650(ItemTable* c, int key, KeyFunc020de650 fn);
extern "C" int func_020df618(SafeAllocator*, void*, Struct_020def98*, void**, int, Struct_020def98*);
extern "C" int func_020df6cc(void*, Struct_020def98_2*, int, Struct_020def98_2*);
extern "C" void ItemRecord_Copy(Record020836e4* dst, Record020836e4* src);
extern "C" void ItemRecord_Clear(StructDE1D4*);

static inline void inline_020def98(Record020836e4* a, Record020836e4* b) {
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
            Element020de650* found = BinarySearchByComparator020de650(source, value, (KeyFunc020de650)func_020de56c);
            if (!found) continue;
            int var8 = 0;
            short* prev = keys;
            for (int j = 0; j < i; j++, prev++) {
                if (*prev == value) { var8 = 1; break; }
            }
            if (var8) continue;
            count++;
            if (found->name) nameCount++;
        }
        output = (Record020836e4*)allocator->Allocate((count + n) * 32);
        dest->count = count;
        dest->copiedNames = (unsigned short)nameCount;
        dest->entries = (Element020de650*)output;
    }
    if (!output) return 0;
    int copied;
    int i;
    int capacity = keyCount;
    dest->capacity = capacity;
    dest->nameCapacity = dest->copiedNames;
    void* names = allocator ? output + capacity : NULL;
    dest->copiedNames = 0;
    copied = 0;
    short* key = keys;
    for (i = 0; i < capacity; i++, key++) {
        short value = *key;
        Element020de650* found = NULL;
        if (value >= 0) found = BinarySearchByComparator020de650(source, value, (KeyFunc020de650)func_020de56c);
        if (!found) {
            if (!allocator) { output++; copied++; }
            continue;
        }
        if (allocator) {
            int var18 = 0;
            short* prev = keys;
            for (int j = 0; j < i; j++, prev++) {
                if (*prev == value) { var18 = 1; break; }
            }
            if (var18) continue;
            func_020df618(allocator, dest, (Struct_020def98*)output, &names, (int)source, (Struct_020def98*)found);
        } else {
            func_020df6cc(dest, (Struct_020def98_2*)output, (int)source, (Struct_020def98_2*)found);
        }
        if (copied >= capacity) break;
        output++;
        copied++;
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
                            inline_020def98(p, p + 1);
                        }
                        p++;
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
                        q = prev;
                    }
                    if (first == -1) break;
                    lo = first;
                }
            }
        }
    }
    int end = dest->capacity;
    Record020836e4* e = (Record020836e4*)dest->entries + dest->count;
    for (i = dest->count; i < end; i++, e++) ItemRecord_Clear((StructDE1D4*)e);
    return 1;
}
