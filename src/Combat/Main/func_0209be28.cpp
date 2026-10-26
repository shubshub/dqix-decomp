#include <globaldefs.h>

struct Struct_02073ec4_2;
struct Struct_0209be28 {
    unsigned short key;
    unsigned short count;
    int unknown_4_;
    unsigned char sub[0x18];
};
extern "C" struct Struct_0209be28* func_0209bd94(struct Struct_02073ec4_2*, int);

// USA: func_0209be28
extern "C" ARM void func_0209be28(struct Struct_02073ec4_2* table, int key, int* value) {
    struct Struct_0209be28* p = func_0209bd94(table, key);
    if (p != NULL) {
        p->unknown_4_ = *value;
    }
}
