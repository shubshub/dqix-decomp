#include <globaldefs.h>

struct Struct_020bec80_2;
extern "C" void func_020bec80(struct Struct_020bec80_2* p);
extern "C" void func_020bf1a0(void* entry);

struct Struct_02110a4c_4 {
    unsigned char unknown0[0x110];
    int active : 1;
    unsigned char unknown_111_[0x12c - 0x114];
    void* resource;
    unsigned char unknown_130_[0x14c - 0x130];
    void** owner;
    int priority;
    unsigned char unknown_154_[0x174 - 0x154];
};
extern struct Struct_02110a4c_4 data_02110a4c[];

// USA: func_020bee20
extern "C" ARM void* func_020bee20(void** self, int index, int value) {
    if (*self != NULL) {
        func_020bec80((struct Struct_020bec80_2*)self);
    }
    Struct_02110a4c_4* entry = &data_02110a4c[index];
    if (entry->resource == NULL) {
        return NULL;
    }
    if (entry->active) {
        if (value < entry->priority) {
            return NULL;
        }
        func_020bf1a0(entry);
    }
    entry->priority = value;
    entry->active = 1;
    entry->owner = self;
    *self = entry;
    return entry;
}
