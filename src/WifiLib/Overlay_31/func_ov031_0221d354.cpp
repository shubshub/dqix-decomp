#include <globaldefs.h>

struct Struct_ov031_0221d354 {
    unsigned char address[6];
    unsigned short token;
};

extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" unsigned short func_ov031_0221e664();
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);

// USA: func_ov031_0221d354
extern "C" THUMB void func_ov031_0221d354(int count, Struct_ov031_0221d354* entries, const void* address)
{
    int i;
    Struct_ov031_0221d354* cursor = entries;
    i = 0;
    if (count > 0) do {
        func_ov031_0221e51c(cursor->address, address, 6);
        cursor->token = func_ov031_0221e664();
        cursor->token = func_ov031_0221e5f8(cursor->token);
        ++i;
        ++cursor;
    } while (i < count);
}
