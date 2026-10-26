#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" int func_020dfbfc(void* a, int b, int c);

// USA: func_020dfbdc
extern "C" ARM int func_020dfbdc(void* a, struct Node020dfbdc* node) {
    node->text = func_020dfbfc(a, node->text, 0);
    return 1;
}
