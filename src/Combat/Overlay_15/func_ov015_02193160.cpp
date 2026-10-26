#include <globaldefs.h>

struct Struct_ov015_0218bae8 { void* base; int pad4; int count; };
extern "C" void* func_ov015_0218bae8(struct Struct_ov015_0218bae8* obj, int idx);

struct Struct_ov015_02193160 {
    char pad[0x3c];
    struct Struct_ov015_0218bae8 list;
};

// USA: func_ov015_02193160
extern "C" ARM void* func_ov015_02193160(struct Struct_ov015_02193160 *obj, unsigned char arg1, int *arg2) {
    int idx = *arg2;
    while (idx < obj->list.count) {
        void *entry = func_ov015_0218bae8(&obj->list, idx);
        if (!entry)
            goto notfound;
        if (arg1 == *((unsigned char *)entry + 0xa)) {
            *arg2 = idx;
            return entry;
        }
        idx++;
    }
notfound:
    return NULL;
}
