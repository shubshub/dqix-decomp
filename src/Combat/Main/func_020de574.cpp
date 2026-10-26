#include <globaldefs.h>

struct Struct_020de574_2 {
    unsigned char pad0[0x10];
    int unknown_10_;
};

struct Struct_020de574 {
    unsigned char pad0[4];
    int cur;
};

// USA: func_020de574
extern "C" ARM int func_020de574(Struct_020de574_2 *table, Struct_020de574 *cursor) {
    int flag = 1;
    int v = (int)((char *)cursor->cur - (char *)0);
    if (v != -1) {
        if (table->unknown_10_ != 0) {
            flag = 0;
        }
    }
    cursor->cur = flag ? 0 : table->unknown_10_ + v;
    return 1;
}
