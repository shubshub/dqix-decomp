#include <globaldefs.h>

struct Struct_0201c4d4_3 { unsigned char b[8]; };
struct Struct_0201c4d4_4 { unsigned char b[0x1c]; };
struct Struct_0201c4d4 { unsigned char low : 3; unsigned char high : 5; };

struct Struct_0201c4d4_2 {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    struct Struct_0201c4d4_3 unknown_5_;
    struct Struct_0201c4d4_4 unknown_d_;
    struct Struct_0201c4d4 unknown_29_;
    unsigned char unknown_2a_;
};

struct Struct_0201c1f8 {
    unsigned char* unknown_0_;
    int f4;
    int count;
    struct Struct_0201c4d4_2* entries;
    int unknown_10_;
    int capacity;
    int f18;
    int f1c;
};

// USA: func_0201c4d4
extern "C" ARM void func_0201c4d4(struct Struct_0201c1f8* q, struct Struct_0201c4d4_2* item) {
    struct Struct_0201c4d4_2* dst;

    if (q->unknown_0_) {
        if (q->count < q->f4) {
            (q->unknown_0_ + 0x1f)[(q->count - 1) * 0x20]++;
        }
    }

    if (q->f18 >= 0) {
        if (q->f18 != q->count - 1) {
            return;
        }
    }

    if (q->f1c >= 0) {
        if (q->f1c != item->unknown_29_.low) {
            return;
        }
    }

    if (!q->entries) {
        return;
    }
    if (q->unknown_10_ >= q->capacity) {
        return;
    }

    dst = &q->entries[q->unknown_10_];
    dst->f0 = item->f0;
    dst->f2 = item->f2;
    dst->f4 = item->f4;
    dst->unknown_5_ = item->unknown_5_;
    dst->unknown_d_ = item->unknown_d_;
    dst->unknown_29_ = item->unknown_29_;
    dst->unknown_2a_ = item->unknown_2a_;

    if (q->count > 0) {
        q->entries[q->unknown_10_].f4 = q->count - 1;
    }

    q->unknown_10_ = q->unknown_10_ + 1;
}
