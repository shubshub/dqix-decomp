#include <globaldefs.h>
#if defined(jpn)
#define data_020f1f14 data_020f2080
#define data_0210cf84 data_0210cc3c
#endif

struct Struct_020f1f14_3 { int a; int b; int active; int flag; char pad[8]; };
extern struct Struct_020f1f14_3 data_020f1f14[];
extern unsigned short data_0210cf84;

// USA: func_020bb514
extern "C" ARM void func_020bb514(void) {
    int i;
    struct Struct_020f1f14_3* slot = data_020f1f14;
    unsigned int var2 = data_0210cf84;
    if (var2 > 1) var2 = var2 + 1;
    int count = (int)var2;
    i = 0;
    do {
        if (i < count) {
            slot->active = 1;
        } else {
            slot->active = 0;
        }
        if (slot->flag != 0) {
            slot->a = 0;
            slot->b = 0x10000;
        } else {
            slot->a = 0;
            slot->b = 0x20000;
        }
        i = i + 1;
        slot = slot + 1;
    } while (i < 5);
}
