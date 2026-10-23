#include <globaldefs.h>

struct Struct_020dfc40;
struct Struct_0201099c_14 {
    unsigned char unknown_0_[0xc];
    short unknown_c_;
    short unknown_e_;
    int unknown_10_;
    void* unknown_14_;
};

int ResetHandleState020dfe88(struct Obj020dfe88* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
int ReplaceBinExtensionWithNat020e05f8(char*, char const*, short);
extern "C" int func_020dfd40(void* self, char* a, char* b);

// USA: func_020dfc84
extern "C" ARM int func_020dfc84(void* arg0, void* arg1, char* arg2, char* arg3, short arg4, short arg5) {
    char var0[0x60];
    struct Struct_0201099c_14* var1;

    p = (struct Struct020dfc40*)self;
    ResetHandleState020dfe88((struct Obj020dfe88*)self);
    KeyTable_Reset(p);
    p->field_14 = field_14;
    p->field_c = field_c;
    p->field_e = 1;

    if (arg4 >= 0) {
        func_020e05f8(var0 + 0x20, arg2, arg4);
        if (arg3 != 0) {
            func_020e05f8(var0, arg3, arg4);
            func_020dfd40(arg0, var0 + 0x20, var0);
        } else {
            func_020dfd40(arg0, var0 + 0x20, 0);
        }
        return;
    }

    if (arg3 != 0) {
        func_020dfd40(arg0, arg2, arg3);
    } else {
        func_020dfd40(arg0, arg2, 0);
    }
}
