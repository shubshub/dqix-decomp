#include <globaldefs.h>

struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Element0x318_02028bac;
extern "C" struct Element0x318_02028bac* ZoneRecords_GetAt(struct Element0x318_02028bac* base, int index);

struct Struct_02090294 {
#if defined(jpn)
    char pad0[0x296];
#else
    char pad0[0x276];
#endif
    signed char unknown_276_;
};

// USA: func_02090294
extern "C" ARM int func_02090294(struct Struct_02090294* obj) {
    struct Element0x318_02028bac* table = (struct Element0x318_02028bac*)ZoneRecords_GetInstance();
    int i = 0;
    int j;
retry:
    if (obj->unknown_276_ > 4) {
        obj->unknown_276_ = 0;
    }
    for (j = i; j < 4; j++) {
        struct Element0x318_02028bac* entry = ZoneRecords_GetAt(table, j);
        if (entry != 0) {
            if (*((signed char*)entry + 0xd) == obj->unknown_276_) {
                obj->unknown_276_++;
                goto retry;
            }
        }
    }
    int k;
    for (k = 0; k < 4; k++) {
        ZoneRecords_GetAt(table, k);
    }
    signed char old = obj->unknown_276_;
    obj->unknown_276_ = old + 1;
    return old;
}
