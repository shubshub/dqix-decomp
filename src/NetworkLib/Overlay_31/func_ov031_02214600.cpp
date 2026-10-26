#include <globaldefs.h>

struct Struct_ov031_02214600_2 {
    unsigned char type;
    unsigned char count;
    unsigned char reserved;
    unsigned char size;
    unsigned char data[0x20];
};

struct Struct_ov031_02214600 {
    unsigned char mode : 4;
    unsigned char flags : 4;
};

extern "C" int func_ov031_0221474c(void*);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern unsigned char data_ov031_02245fe0[];

// USA: func_ov031_02214600
extern "C" ARM int func_ov031_02214600(void* obj) {
    Struct_ov031_02214600_2* entry = (Struct_ov031_02214600_2*)((char*)obj + 0x300);
    int index = func_ov031_0221474c(obj);
    unsigned int mode = ((Struct_ov031_02214600*)((char*)obj + 0xd0c))->mode;
    entry += index;
    if (mode == 0 || mode == 6) {
        VectorizedInvertedMemcpy(data_ov031_02245fe0, entry->data, 8);
        entry->size = 8;
        entry->count = 8;
        index = (index + 1) & 0xff;
    }
    return index;
}
