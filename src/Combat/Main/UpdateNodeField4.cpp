#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" int func_020dfbfc(void* a, int b, int c);

// USA: func_020dfbdc
ARM int UpdateNodeField4(void* a, struct Node020dfbdc* node) {
    node->text = func_020dfbfc(a, node->text, 0);
    return 1;
}
