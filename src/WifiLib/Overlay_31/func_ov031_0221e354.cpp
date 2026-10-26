#include <globaldefs.h>

extern "C" void* func_ov031_0221c49c(int);
extern "C" void func_ov031_0221c4ac(void*);
extern "C" void func_ov031_0221e3d0(int, signed char*, int, const signed char*, int);
extern "C" void func_ov031_0221e404(signed char*, unsigned char*, int);
extern "C" void func_ov031_0221e428(unsigned char*, int, unsigned char*);

// USA: func_ov031_0221e354
extern "C" THUMB int func_ov031_0221e354(unsigned char* data, int length, const signed char* key, int arg3) {
    signed char* table = (signed char*)func_ov031_0221c49c(length / 2);
    if (table == 0) return -1;
    unsigned char* scratch = (unsigned char*)func_ov031_0221c49c(length);
    if (scratch == 0) {
        func_ov031_0221c4ac(table);
        return -1;
    }
    int round = 0;
    do {
        func_ov031_0221e3d0(round, table, length, key, arg3);
        func_ov031_0221e404(table, data, length);
        func_ov031_0221e428(data, length, scratch);
        round++;
    } while (round < 2);
    func_ov031_0221c4ac(table);
    func_ov031_0221c4ac(scratch);
    return 0;
}
