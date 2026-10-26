#include <globaldefs.h>

struct Struct_ov004_02153860 { char pad[5]; unsigned char field5; };
extern "C" Struct_ov004_02153860* func_ov004_021538b4(Struct_ov004_02153860* base, int key);
extern Struct_ov004_02153860* data_ov004_021707c0;

// USA: func_ov004_021538f0
extern "C" ARM short func_ov004_021538f0(void) {
    short total = 0;
    for (short i = 7; i <= 7; i++) {
        Struct_ov004_02153860* entry = func_ov004_021538b4(data_ov004_021707c0, i);
        if (entry) total = total + entry->field5;
    }
    return total;
}
