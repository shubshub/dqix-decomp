#include <globaldefs.h>

extern "C" void __clear(void* buf, int count);

struct Struct_02071da4_2 {
    short f0;
    short f2;
    short f4;
    short unknown_6_;
    short f8;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
    char unknown_c_[0x14];
};

struct Struct_02071da4 {
    char pad0[4];
    struct Struct_02071da4_2* entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_02071da4
extern "C" ARM struct Struct_02071da4_2* func_02071da4(struct Struct_02071da4* list, short* arg1, unsigned char* arg2, unsigned char* out) {
    unsigned char total;
    unsigned char k;
    struct Struct_02071da4_2* arr;
    unsigned int n;
    struct Struct_02071da4_2* e;
    unsigned short i;
    unsigned char cnt;
    unsigned char var7;
    unsigned char j;
    unsigned char diff;
    unsigned char t;
    unsigned char t2;
    unsigned char buf[3];
    unsigned char c;
    int var14;
    int var15;
    int var16;

    if (arg1 == NULL || arg2 == NULL) {
        return NULL;
    }
    total = 0;
    for (k = 0; k < 3; k++) {
        if (arg1[k] > 0) {
            total = total + 1;
        }
    }

    arr = list->entries;
    n = list->count;
    for (i = 0; i < n; i++) {
        e = &arr[i];
        cnt = 0;
        cnt += (e->f4 > 0);
        cnt += (e->unknown_6_ > 0);
        cnt += (e->f8 > 0);
        if (cnt == total) {
            __clear(buf, 3);
            for (j = 0; j < cnt; j++) {
                short v = arg1[j];
                c = arg2[j];
                if (v == e->f4) {
                    var14 = e->unknown_a_0_;
                    if (c % var14 == 0) {
                        buf[0] = c / var14;
                    } else {
                        break;
                    }
                } else if (v == e->unknown_6_) {
                    var15 = e->unknown_a_4_;
                    if (c % var15 == 0) {
                        buf[1] = c / var15;
                    } else {
                        break;
                    }
                } else if (v == e->f8) {
                    var16 = e->unknown_b_0_;
                    if (c % var16 == 0) {
                        buf[2] = c / var16;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            var7 = 0;
            for (t = 0; t < 3; t++) {
                if (buf[t] != 0) {
                    var7 = var7 + 1;
                }
            }

            if (cnt == var7) {
                diff = 0;
                for (t2 = 1; t2 < cnt; t2++) {
                    if (buf[0] != buf[t2]) {
                        diff = 1;
                        break;
                    }
                }
                if (diff == 0) {
                    *out = buf[0];
                    return e;
                }
            }
        }
    }
    return NULL;
}
