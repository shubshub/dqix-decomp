#include <globaldefs.h>
#include "Resource/KeyTable.h"

int KeyTable_EndLoad(struct Struct020dfc40*);

void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_020dfc6c
ARM void ResetAndDetach020dfc6c(struct Struct020dfc40* p) {
    KeyTable_EndLoad(p);
    KeyTable_Reset(p);
}
