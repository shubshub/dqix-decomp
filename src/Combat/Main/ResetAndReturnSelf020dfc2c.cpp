#include <globaldefs.h>

struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_020dfc2c
ARM void* ResetAndReturnSelf020dfc2c(void* p) {
    KeyTable_Reset((struct Struct020dfc40*)p);
    return p;
}
