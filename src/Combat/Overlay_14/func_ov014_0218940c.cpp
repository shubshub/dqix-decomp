#include <globaldefs.h>

struct Struct_ov014_021893e4_2;
struct Struct_ov014_021893e4;
extern "C" int* func_ov014_021893e4(struct Struct_ov014_021893e4_2* a, struct Struct_ov014_021893e4* b);

// USA: func_ov014_0218940c
extern "C" ARM int* func_ov014_0218940c(struct Struct_ov014_021893e4_2* table, int index, struct Struct_ov014_021893e4* key) {
    if (!key) return 0;
    int* slot = func_ov014_021893e4(table, key);
    return slot + index;
}
