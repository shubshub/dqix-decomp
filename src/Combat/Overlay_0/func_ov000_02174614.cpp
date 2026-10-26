#include <globaldefs.h>

extern "C" void* memset(void* dst, int value, unsigned int size);

struct Struct_ov000_02174614 {
    char pad0[0x38];
    int unknown_38_;
    char unknown_3c_[0x4c - 0x3c];
    int id;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char active;
#if defined(jpn)
    char unknown_c8_[0x488 - 0xc8];
#else
    char unknown_88_[0x448 - 0x88];
#endif
};

struct Struct_ov000_02174614_2 {
    char pad0[0x6c];
    signed char order[4];
    char unknown_70_[0x958 - 0x70];
    Struct_ov000_02174614 entries[4];
#if defined(jpn)
    char unknown_1b78_[0x1f98 - 0x1b78];
#else
    char unknown_1a78_[0x1d60 - 0x1a78];
#endif
    unsigned char selected[8];
    signed char cursor;
};

extern "C" int func_ov000_021719f8(int* obj);
extern "C" void func_ov000_0217f518(Struct_ov000_02174614* entry);
extern "C" void func_ov000_0217636c(Struct_ov000_02174614* entry, int mode);

// USA: func_ov000_02174614
extern "C" ARM void func_ov000_02174614(Struct_ov000_02174614_2* table, int id)
{
    Struct_ov000_02174614* entry;
    if (id < 0) {
        int i;
        memset(table->selected, 0, sizeof(table->selected));
        table->cursor = 0;
        table->selected[table->cursor] = 1;
        for (i = 0; i < 4; i++) {
            entry = &table->entries[table->order[i]];
            if (entry->id >= 0 && entry->active != 0 && !func_ov000_021719f8((int*)entry)) {
                func_ov000_0217f518(entry);
                if (entry->unknown_38_ != 0) {
                    func_ov000_0217636c(entry, 0);
                }
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        entry = &table->entries[table->order[i]];
        if (id == entry->id) {
            func_ov000_0217f518(entry);
            if (entry->unknown_38_ != 0) {
                func_ov000_0217636c(entry, 0);
            }
            return;
        }
    }
}
