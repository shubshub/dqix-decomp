#include <globaldefs.h>

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);

// USA: func_ov000_0216fcfc
ARM int GetFieldByKeyFromWork0x88_ov000_0216fcfc(void* obj, int key) {
    return KeyTable_Get((struct Container020e0310*)((char*)obj + 0x88), key);
}
