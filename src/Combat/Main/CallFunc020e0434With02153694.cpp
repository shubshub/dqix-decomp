#include <globaldefs.h>
int KeyTable_Get(struct Container020e0310 *, int);

extern int data_02153694;

// USA: _Z37CallFunc020e0434With02153694_020e51cci
ARM int CallFunc020e0434With02153694_020e51cc(int value) {
    return KeyTable_Get((struct Container020e0310 *)(&data_02153694), (int)(value));
}
