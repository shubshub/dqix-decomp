#include <globaldefs.h>

struct Struct_ov027_021e3424_5 {
    unsigned char pad0[4];
    char* arr;
    unsigned char pad1[0xc - 0x8];
    int count;
};

extern Struct_ov027_021e3424_5 data_ov027_021e3424;

// USA: func_ov027_021dd864
extern "C" ARM int func_ov027_021dd864(int id) {
    unsigned short i = 0;
    unsigned int flags;
    int count = data_ov027_021e3424.count;
    if (count <= 0) goto allSet;
    {
        flags = *(unsigned int*)(data_ov027_021e3424.arr + (id - 1) * 4 + 0x1e0);
        do {
            if (!(flags & (1 << i))) return 0;
            i++;
        } while (i < count);
    }
allSet:
    return 1;
}
