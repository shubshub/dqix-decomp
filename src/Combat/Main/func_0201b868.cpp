#include <globaldefs.h>

extern unsigned short data_020e6ea8[];

// USA: func_0201b868
extern "C" ARM int func_0201b868(void* obj, int id) {
    unsigned short v = (unsigned short)id;
    int i;
    if (v >= 0x4e20 && v <= 0x752f) return 1;
    for (i = 0; data_020e6ea8[i] != 0; i++) {
        if (v == data_020e6ea8[i]) return 1;
    }
    return 0;
}
