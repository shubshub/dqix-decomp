#include <globaldefs.h>
struct Struct_ov024_021ea4d0;

extern short data_ov024_021fe7aa[];

// USA: func_ov024_021eb47c
extern "C" ARM int func_ov024_021eb47c(Struct_ov024_021ea4d0* a0, int value) {
    short* p = data_ov024_021fe7aa;
    while (*p != -1) {
        if (*p == value) return 1;
        p++;
    }
    return 0;
}
