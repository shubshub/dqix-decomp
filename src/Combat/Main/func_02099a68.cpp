#include <globaldefs.h>

struct Struct_02099a68_2 {
    unsigned short key;
    unsigned char pad[12];
    unsigned char fe;
    unsigned char pad2;
};

struct SearchList02099a68 {
    struct Struct_02099a68_2* data;
    int count;
};

// USA: func_02099a68
extern "C" ARM int func_02099a68(struct SearchList02099a68* list, unsigned short key) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (key == list->data[i].key) {
            unsigned int v = list->data[i].fe;
            v = (v << 26) >> 28;
            if (v == 8) return 0;
            return 1 << v;
        }
    }
    return 0;
}
