#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0206e748_2 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char unknown_3_[4];
    unsigned char unknown_7_[9];
    unsigned char flags2[4];
    unsigned char unknown_14_[8];
};

struct Struct_0206e748 {
    Struct_0206e748_2 cur[5];
    unsigned char pad8c[0x334 - 0x8c];
    Struct_0206e748_2 snap[5];
    unsigned char bits[0x44];
    int dirty;
    int unknown_408_;
    unsigned char nibbles[0xf];
};

// USA: func_0206e748
extern "C" ARM void func_0206e748(Struct_0206e748* obj, unsigned char type, unsigned char idx, unsigned short bit, int value) {
    if (type == 0) {
        unsigned int q = bit / 8;
        unsigned char m = 1 << (bit % 8);
        if (q < 0x42) {
            if (value) {
                if (obj->bits[q] & m) return;
                obj->bits[q] |= m;
            } else {
                if (!(obj->bits[q] & m)) return;
                obj->bits[q] &= ~m;
            }
        }
    } else if (type == 1) {
        unsigned int q = bit / 8 + 0x40;
        unsigned char m = 1 << (bit % 8);
        if (q < 0x42) {
            if (value) {
                obj->bits[q] |= m;
            } else {
                obj->bits[q] &= ~m;
            }
        }
        obj->unknown_408_ = 1;
        return;
    } else if (type == 2) {
        if (idx < 5) {
            unsigned char a = (value >> 10) & 0x1f;
            unsigned char b = (value >> 5) & 0x1f;
            unsigned char c = value & 0x1f;
            if (a != obj->snap[idx].a) {
                memset(obj->snap[idx].unknown_3_, 0, 4);
                memset(obj->snap[idx].flags2, 0, 4);
            } else if (b != obj->snap[idx].b) {
                memset(obj->snap[idx].flags2, 0, 4);
            }
            obj->snap[idx].a = a;
            obj->snap[idx].b = b;
            obj->snap[idx].c = c;
            if (value & 0x8000) {
                obj->cur[idx].a = a;
                obj->cur[idx].b = b;
                obj->cur[idx].c = c;
            }
        }
    } else if (type == 3) {
        if (idx < 5) {
            unsigned int q = bit / 8;
            unsigned char m = 1 << (bit % 8);
            if (value) {
                if (obj->snap[idx].unknown_3_[q] & m) return;
                obj->snap[idx].unknown_3_[q] |= m;
            } else {
                if (!(obj->snap[idx].unknown_3_[q] & m)) return;
                obj->snap[idx].unknown_3_[q] &= ~m;
            }
            obj->unknown_408_ = 1;
            return;
        }
    } else if (type == 5) {
        if (idx < 5) {
            unsigned int q = bit / 8;
            unsigned char m = 1 << (bit % 8);
            if (value) {
                if (obj->snap[idx].flags2[q] & m) return;
                obj->snap[idx].flags2[q] |= m;
            } else {
                if (!(obj->snap[idx].flags2[q] & m)) return;
                obj->snap[idx].flags2[q] &= ~m;
            }
            obj->unknown_408_ = 1;
            return;
        }
    } else if (type == 7) {
        if (bit >= 0xae) {
            unsigned char j = bit - 0xae;
            unsigned char rem = j % 2;
            unsigned char q = j / 2;
            if (rem) {
                unsigned char n = obj->nibbles[q] >> 4;
                n = (n & 0xc) | value;
                obj->nibbles[q] &= 0xf;
                obj->nibbles[q] |= n << 4;
            } else {
                unsigned char n = obj->nibbles[q] & 0xf;
                n = (n & 0xc) | value;
                obj->nibbles[q] &= 0xf0;
                obj->nibbles[q] |= n;
            }
        }
    }
    obj->dirty = 1;
}
