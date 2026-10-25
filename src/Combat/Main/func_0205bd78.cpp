#include <globaldefs.h>

struct Struct_0205bd04;
extern "C" int func_0205bd04(struct Struct_0205bd04*);

struct Struct_0205bcdc;
void GridCursor_SelectIfValid(struct Struct_0205bcdc*, int);

struct Struct_0205bd78 {
    int unknown_0_;
    char unknown_4_[0x1c];
    int* unknown_20_;
    int* unknown_24_;
    int* unknown_28_;
    int* unknown_2c_;
    char unknown_30_[0x4];
    int unknown_34_;
    short unknown_38_;
    short unknown_3a_;
    short* unknown_3c_;
    short* unknown_40_;
    short* unknown_44_;
    short* unknown_48_;
};

// USA: func_0205bd78
extern "C" ARM int func_0205bd78(struct Struct_0205bd78* arg0, int arg1, int arg2) {
    if (arg0->unknown_34_ == 0) return -1;
    if (arg0->unknown_3c_ == 0) return -1;
    if (arg0->unknown_40_ == 0) return -1;
    if (arg0->unknown_44_ == 0) return -1;
    if (arg0->unknown_48_ == 0) return -1;

    arg1 -= arg0->unknown_38_;
    arg2 -= arg0->unknown_3a_;

    int row = 0;
    while (row < *s->field24) {
        int col = 0;
        while (col < *s->field20) {
            int idx = col * *s->field24 + row;
            if (s->field34 > idx) {
                short a = s->field3c[idx];
                short b = s->field40[idx];
                short c = s->field44[idx];
                short d = s->field48[idx];
                int right = a + c;
                int bottom = b + d;
                if (x >= a && right >= x && y >= b && bottom >= y) {
                    *s->field2c = row;
                    *s->field28 = col;
                    int result = GetScaledSumIfActive0205bd04((struct Struct_0205bd04*)s);
                    if (s->field0 <= result) result = -1;
                    GridCursor_SelectIfValid((struct Struct_0205bcdc*)s, result);
                    return result;
                }
            }
            var1++;
        }
        var0++;
    }
    return -1;
}
