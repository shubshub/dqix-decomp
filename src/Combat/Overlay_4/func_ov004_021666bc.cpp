#include <globaldefs.h>

extern "C" short func_ov004_02166684(int a);

struct Struct_ov004_021666bc {
    short id;
    unsigned short bit0 : 2;
    unsigned short bit2 : 1;
    unsigned short pad : 13;
    char pad4[4];
    struct Struct_ov004_021666bc* next;
};
extern struct Struct_ov004_021666bc* data_ov004_0217101c;

#if defined(jpn)
enum { Enum_ov004_021666bc_0 = 1 };
#else
enum { Enum_ov004_021666bc_0 = 0 };
#endif

// USA: func_ov004_021666bc
#pragma optimize_for_size off
extern "C" ARM short func_ov004_021666bc(int a, char* outFlag) {
    short count = func_ov004_02166684(a);
    struct Struct_ov004_021666bc* node = (&data_ov004_0217101c)[Enum_ov004_021666bc_0]->next;
    *outFlag = 0;
    while (node != 0 && count != 0) {
        count--;
        node = node->next;
    }
    if (node != 0) {
        *outFlag = node->bit2 != 0;
        return node->id;
    } else {
        return -1;
    }
}
