#include <globaldefs.h>

struct Struct_02071ffc_2;
struct Struct_02071ffc_3;
struct Struct_02071ffc_5;

extern "C" void func_0207214c(struct Struct_02071ffc_2* list);
extern "C" void func_020721f8(struct Struct_02071ffc_3* list);
extern "C" void func_020722a4(struct Struct_02071ffc_5** list, int n);

struct Struct_02071ffc {
    unsigned char pad0[0xc];
    unsigned int unknown_c_0_ : 20;
    unsigned int unknown_e_4_   : 8;
    unsigned int unknown_f_4_ : 4;
    unsigned int unknown_10_0_ : 21;
    unsigned int active   : 1;
    unsigned int unknown_12_6_: 1;
    unsigned int unknown_12_7_  : 8;
    unsigned int unknown_13_7_ : 1;
    unsigned char unknown_14_[8];
    struct Struct_02071ffc* next;
};

struct Struct_02071ffc_4 {
    struct Struct_02071ffc* head;
    struct Struct_02071ffc* array;
    unsigned char pad8[2];
    unsigned short count;
};

// USA: func_02071ffc
extern "C" ARM struct Struct_02071ffc* func_02071ffc(struct Struct_02071ffc_4* obj, int p1, int p2, int p3, short p4, short* arg5) {
    unsigned short count = obj->count;
    struct Struct_02071ffc* arr = obj->array;
    unsigned short i1, i2, var4;
    struct Struct_02071ffc* n;

    obj->head = NULL;
    for (i1 = 0; i1 < count; i1++) {
        struct Struct_02071ffc* e = (struct Struct_02071ffc*)((char*)arr + (i1 << 5));
        e->next = NULL;
        e->active = 1;
    }
    if (p1 >= 0) {
        for (i2 = 0; i2 < count; i2++) {
            struct Struct_02071ffc* e = (struct Struct_02071ffc*)((char*)arr + (i2 << 5));
            e->active = (e->unknown_e_4_ == (unsigned int)p1);
        }
    }
    if (p2 >= 0) {
        for (var4 = 0; var4 < count; var4++) {
            struct Struct_02071ffc* e = (struct Struct_02071ffc*)((char*)arr + (var4 << 5));
            e->active = (e->unknown_12_7_ == (unsigned int)p2);
        }
    }
    if (p3 == 0) {
        func_0207214c((struct Struct_02071ffc_2*)obj);
    } else {
        func_020721f8((struct Struct_02071ffc_3*)obj);
    }

    *arg5 = 0;
    n = obj->head;
    while (n != NULL) {
        (*arg5)++;
        n = n->next;
    }

    func_020722a4((struct Struct_02071ffc_5**)obj, p4);
    return obj->head;
}
