#include <globaldefs.h>

struct Struct_0205bd20;
int TouchGrid_IsSelectionTapped(struct Struct_0205bd20* s, int key);
struct Struct_0205c570;
int GetActiveScaledSum0205c570(struct Struct_0205c570*);

// USA: func_0205cecc
ARM int GetScaledSumIfActive0205cecc(void* s) {
    if (TouchGrid_IsSelectionTapped(
            (struct Struct_0205bd20*)((char*)s + 0x20), 1) == 0) {
        return -1;
    }
    return GetActiveScaledSum0205c570((struct Struct_0205c570*)((char*)s + 0x1c));
}
