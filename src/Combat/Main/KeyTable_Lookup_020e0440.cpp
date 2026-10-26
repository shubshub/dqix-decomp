#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
extern "C" int func_020dfbd4(short*);

struct Struct_020e0028 {
    int a;
    int b;
};

typedef int (*Type_020e0028)(struct Struct_020e0028 *);

extern "C" struct Struct_020e0028 *func_020e0310(struct Container020e0310 *c, int key, Type_020e0028 fn);

// Main, originally LookupFieldByKey020e0440 (USA 0x020e0440, EUR 0x020e0450, JPN 0x020e20b4)
extern "C" ARM int KeyTable_Lookup(struct Container020e0310 *c, int key) {
    struct Struct_020e0028 *elem;
    if (c == NULL) return 0;
    elem = func_020e0310(c, key, (Type_020e0028)func_020dfbd4);
    if (elem != NULL) return elem->b;
    return 0;
}
