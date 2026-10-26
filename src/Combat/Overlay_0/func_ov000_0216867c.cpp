#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79c6
#else
#define REGION_OFFSET_0 0x77d6
#endif


struct Struct_ov000_0216867c {
    signed char id;
    unsigned char flags;
    short unknown_2_;
    short unknown_4_;

    signed char inline_ov000_0216867c() const { return id; }
};

struct Struct_ov000_0216867c_2 {
    char pad[REGION_OFFSET_0];
    Struct_ov000_0216867c entries[4];
    unsigned char count;
};

// USA: func_ov000_0216867c
extern "C" ARM void func_ov000_0216867c(Struct_ov000_0216867c_2* owner, int id) {
    int removed = 0;
    int j = 0;
    for (int i = 0; i < owner->count; i++) {
        if (id == owner->entries[i].inline_ov000_0216867c()) {
            removed = 1;
        } else {
            owner->entries[j].id = owner->entries[i].id;
            owner->entries[j].flags = owner->entries[i].flags;
            owner->entries[j].unknown_2_ = owner->entries[i].unknown_2_;
            owner->entries[j].unknown_4_ = owner->entries[i].unknown_4_;
            j++;
        }
    }
    if (removed) {
        owner->count--;
    }
}
