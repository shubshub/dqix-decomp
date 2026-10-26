#include <globaldefs.h>

struct Struct_020df77c_2 {
    int key;
    int value;
};

struct Struct_020df77c_3 {
    unsigned short first;
    unsigned char pad0[6];
    Struct_020df77c_2 *entries;
    int unknown_c_;
};

struct Struct_020df77c {
    short pad0;
    short count;
    int cur;
};

// USA: func_020df77c
extern "C" ARM int func_020df77c(Struct_020df77c_3 *table, Struct_020df77c *cursor) {
    int off = cursor->cur;
    if (off == -1) {
        cursor->cur = 0;
    } else {
        int count;
        Struct_020df77c_2 *p = table->entries + table->first + off;
        cursor->cur = (int)p;
        count = cursor->count;
        for (int i = 0; i < count; i++) {
            int flag = 1;
            int v = (int)((char *)p->value - (char *)0);
            if (v != -1) {
                if (table->unknown_c_ != 0) {
                    flag = 0;
                }
            }
            p->value = flag ? 0 : table->unknown_c_ + v;
            p++;
        }
    }
    return 1;
}
