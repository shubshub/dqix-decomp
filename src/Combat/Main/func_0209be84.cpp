#include <globaldefs.h>

struct Struct_02073ec4_2;
struct Struct_0209be84_2 {
    unsigned short id : 12;
    unsigned short hi : 4;
    short b;
};
struct Struct_0209be84 {
    unsigned short key;
    unsigned short count;
    int unknown_4_;
    struct Struct_0209be84_2 sub[6];
};
extern "C" struct Struct_0209be84* func_0209bd94(struct Struct_02073ec4_2*, int);

#pragma optimize_for_size off

// USA: func_0209be84
extern "C" ARM struct Struct_0209be84_2* func_0209be84(struct Struct_02073ec4_2* table, unsigned int arg1, int key) {
    struct Struct_0209be84* p = func_0209bd94(table, key);
    int i;
    if (p != NULL) {
        for (i = 0; i < p->count; i++) {
            if (p->sub[i].id == arg1) {
                return &p->sub[i];
            }
        }
    }
    return NULL;
}
