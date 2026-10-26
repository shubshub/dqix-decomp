#include <globaldefs.h>
extern "C" void func_020555a0(struct Struct_020555a0*);


struct Struct_020579ec {
    char pad[0x1ec];
    Struct_020579ec* next;  // 0x1ec
};

// USA: func_020579ec
extern "C" ARM void func_020579ec(Struct_020579ec** arg0) {
    Struct_020579ec* n = *arg0;
    while (n != NULL) {
        func_020555a0((struct Struct_020555a0*)(n));
        n = n->next;
    }
}
