#include <globaldefs.h>

struct Struct_ov001_02159d44 { void* entries; int count; char pad[0x88]; int unknown_90_; };

extern "C" void func_ov001_02159d9c(struct Struct_ov001_02159d44* a);
extern "C" void func_ov001_02159cfc(void* entry);

// USA: func_ov001_02159d44
extern "C" ARM int func_ov001_02159d44(struct Struct_ov001_02159d44* a, void* entries, int count) {
    a->entries = entries;
    a->count = count;
    func_ov001_02159d9c(a);
    if (a->entries != NULL && a->count > 0) {
        for (int i = 0; i < a->count; i++) {
            func_ov001_02159cfc((char*)a->entries + i * 0x40);
        }
    }
    a->unknown_90_ = 0x1000;
    return 0x1000;
}
