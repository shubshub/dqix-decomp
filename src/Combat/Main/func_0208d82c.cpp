#include <globaldefs.h>

struct Struct_0208b9a0 {
    unsigned int unknown_0_;      /* 0x00 */
    unsigned short h4;    /* 0x04 */
    unsigned short h6;    /* 0x06 */
    unsigned int w8;      /* 0x08 */
    unsigned short hc;    /* 0x0c */
    unsigned short he;    /* 0x0e */
};

// USA: func_0208d82c
extern "C" ARM void func_0208d82c(struct Struct_0208b9a0* h) {
    h->unknown_0_ = 0;
    h->h6 = 0;
    h->h4 = 0;
    h->w8 = 0;
    h->hc = 0;
    h->he = 0xfff;
}
