#include <globaldefs.h>

struct Struct_0208103c {
    char unk0[0xe];
    short unknown_e_;
    char unk10[0x30 - 0x10];
};

struct Struct_0207f524;

extern "C" struct Struct_0208103c* func_0207f6ac(struct Struct_0207f524*, int);

// USA: func_0208103c
extern "C" ARM void func_0208103c(void* obj, int id, int value) {
    struct Struct_0208103c* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 4), id);
    if (e != NULL) {
        e->unknown_e_ = (short)value;
    }
}
