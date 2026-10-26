#include <globaldefs.h>

struct Struct_020afec4 {
    unsigned int id;
    unsigned int size;
};
struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short unknown_c_;
    unsigned short count;
};

// USA: func_020b0288
extern "C" ARM struct Struct_020afec4 *func_020b0288(struct Hdr02b0288 *h, unsigned int key) {
    unsigned char *p = (unsigned char *)h + h->unknown_c_;
    unsigned short count = h->count;
    unsigned short i = 0;
    if (count > i) {
        do {
            struct Struct_020afec4 *e = (struct Struct_020afec4 *)p;
            if (e->id == key) {
                return e;
            }
            p += e->size;
            i++;
        } while (count > i);
    }
    return NULL;
}
