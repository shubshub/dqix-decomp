#include <globaldefs.h>

struct Struct_ov031_022489c4_3 { unsigned short x, y; };
struct Struct_ov031_022493b8_3 { unsigned short x, y, right, bottom; };
struct Struct_ov031_0222481c {
    char unknown_0_[0x11c];
    unsigned char unknown_11c_;
    char unknown_11d_;
    signed char selection;
    char unknown_11f_[3];
    unsigned char unknown_122_;
    unsigned char alternate;
};
extern Struct_ov031_0222481c* data_ov031_02250bfc;
extern Struct_ov031_022493b8_3 data_ov031_022493b8;
extern Struct_ov031_022489c4_3 data_ov031_02248a0c[47];
extern Struct_ov031_022489c4_3 data_ov031_022489c8;
extern Struct_ov031_022489c4_3 data_ov031_022489fc[2];
extern Struct_ov031_022489c4_3 data_ov031_022489ec[2];
extern Struct_ov031_022489c4_3 data_ov031_022489dc[2];
extern Struct_ov031_022489c4_3 data_ov031_022489c4;
extern "C" int func_ov031_0223d414(Struct_ov031_022493b8_3*);
extern "C" void func_ov031_0223cb34(Struct_ov031_022489c4_3*, Struct_ov031_022489c4_3*, Struct_ov031_022493b8_3*);
extern "C" void func_ov031_02224a20(int);
extern "C" void func_ov031_02236878(int);

// USA: func_ov031_0222481c
extern "C" ARM void func_ov031_0222481c() {
    Struct_ov031_022493b8_3 var0;
    if (!func_ov031_0223d414(&data_ov031_022493b8)) goto clear;
    {
        int i = 0;
        Struct_ov031_022489c4_3* point = data_ov031_02248a0c;
        do {
            func_ov031_0223cb34(point, &data_ov031_022489c8, &var0);
            if (func_ov031_0223d414(&var0)) {
                if (data_ov031_02250bfc->selection != i) goto clear;
                func_ov031_02224a20(i);
                goto reset;
            }
            i++;
            point++;
        } while (i < 47);
    }
    {
        Struct_ov031_022489c4_3* var3 = data_ov031_022489fc;
        Struct_ov031_022489c4_3* point = data_ov031_022489ec;
        int i = 2;
        do {
            func_ov031_0223cb34(point, var3, &var0);
            if (func_ov031_0223d414(&var0)) {
                if (data_ov031_02250bfc->selection != i + 47) goto clear;
                func_ov031_02224a20(i + 47);
                if (i != 3) return;
                data_ov031_02250bfc->unknown_122_++;
                if (data_ov031_02250bfc->unknown_122_ < 40) return;
                if (!data_ov031_02250bfc->alternate) {
                    func_ov031_02236878(9);
                    data_ov031_02250bfc->selection = -1;
                    return;
                }
                data_ov031_02250bfc->unknown_11c_ = 0x80;
                data_ov031_02250bfc->unknown_122_ -= 7;
                return;
            }
            i++;
            var3++;
            point++;
        } while (i < 4);
    }
    {
        Struct_ov031_022489c4_3* point = data_ov031_022489dc;
        int i = 0;
        do {
            func_ov031_0223cb34(point, &data_ov031_022489c4, &var0);
            if (func_ov031_0223d414(&var0)) {
                if (data_ov031_02250bfc->selection != i + 51) goto clear;
                func_ov031_02224a20(i + 51);
                goto reset;
            }
            i++;
            point++;
        } while (i < 2);
    }
clear:
    func_ov031_02224a20(-1);
reset:
    data_ov031_02250bfc->unknown_122_ = 0;
}
