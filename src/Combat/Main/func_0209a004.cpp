#include <globaldefs.h>

struct Struct_02099fe8 {
    char pad[0x28];
    short field;
    char pad2[2];
};

struct Struct_0209a004 {
    unsigned int count : 12;
    unsigned int : 19;
    unsigned int flag : 1;
};

struct Struct_0209a004_2 {
    struct Struct_0209a004 header;
    struct Struct_02099fe8* records;
};

extern "C" int func_02099fe8(struct Struct_02099fe8*);

// USA: func_0209a004
extern "C" ARM struct Struct_02099fe8* func_0209a004(void* arg0, int key) {
    struct Struct_0209a004_2* table = (struct Struct_0209a004_2*)arg0;
    struct Struct_02099fe8* found;
    int hi, lo, var4, count;
    struct Struct_02099fe8* records = table->records;
    if (records == NULL || (void*)func_02099fe8 == NULL) {
        found = NULL;
    } else {
        count = table->header.count;
        if (count == 0) {
            found = NULL;
        } else {
            lo = 0;
            hi = count - 1;
            while (lo <= hi) {
                var4 = lo + ((hi - lo + 1) >> 1);
                found = &records[var4];
                int v = func_02099fe8(found);
                if (v == key) goto done;
                if (v > key) hi = var4 - 1;
                else lo = var4 + 1;
            }
            found = NULL;
        }
    }
done:
    return found;
}
