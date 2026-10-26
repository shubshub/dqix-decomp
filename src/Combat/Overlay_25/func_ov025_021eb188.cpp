#include <globaldefs.h>

struct Struct_ov025_021e88d8 {
    int a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

extern "C" void* func_ov025_021eb3e0(void* obj);

// USA: func_ov025_021eb188
extern "C" ARM int func_ov025_021eb188(void* arg0, struct Struct_ov025_021e88d8* entry) {
    char* rec = (char*)arg0 + 0x194 + 0x400;
    unsigned char i = 0;
    while (i < 4) {
        if (*(unsigned short*)(rec + 4) == entry->b) {
            return 1;
        }
        i++;
        rec += 0xc;
    }
    struct Struct_ov025_021e88d8* slot = (struct Struct_ov025_021e88d8*)func_ov025_021eb3e0(arg0);
    if (slot == 0 || entry == 0) {
        return 0;
    }
    slot->b = entry->b;
    slot->c = entry->c;
    slot->d = entry->d;
    slot->e = 1;
    return 1;
}
