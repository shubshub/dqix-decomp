#include <globaldefs.h>

struct Obj020dfe88;
int ResetHandleState020dfe88(struct Obj020dfe88*);

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};

void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_020dfc6c
ARM void ResetAndDetach020dfc6c(struct Struct020dfc40* p) {
    ResetHandleState020dfe88((struct Obj020dfe88*)p);
    KeyTable_Reset(p);
}
