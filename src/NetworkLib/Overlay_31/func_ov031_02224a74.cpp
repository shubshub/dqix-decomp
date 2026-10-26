#include <globaldefs.h>

extern "C" int func_ov031_0223d394(int mask);
extern "C" void func_ov031_02225148(int index);
extern "C" int func_ov031_0223d354(int mask);
extern "C" int func_ov031_0223d3d4(int mask);
extern "C" void func_ov031_02236878(int index);
extern "C" void func_ov031_02224f20(int);
extern "C" ARM void func_ov031_022247bc(void);
extern "C" ARM void func_ov031_022247ec(void);

struct Struct_ov031_02224a74 {
    unsigned char pad[0x11c];
    unsigned char field11c;   // 0x11c
    unsigned char unknown_11d_;   // 0x11d
    unsigned char pad2[0x121 - 0x11e];
    signed char unknown_121_;     // 0x121
    unsigned char pad3[0x123 - 0x122];
    unsigned char unknown_123_;   // 0x123
    unsigned char field124;   // 0x124
    unsigned char unknown_125_;   // 0x125
};

extern Struct_ov031_02224a74* data_ov031_02250bfc;
extern "C" unsigned char* data_ov031_0224b424[];
extern "C" unsigned char data_ov031_02248a04[];
extern "C" unsigned char data_ov031_022489b8[];

// USA: func_ov031_02224a74
extern "C" ARM void func_ov031_02224a74(void) {
    if (func_ov031_0223d394(0x20)) func_ov031_02225148(0);
    if (func_ov031_0223d394(0x40)) func_ov031_02225148(1);
    if (func_ov031_0223d394(0x10)) func_ov031_02225148(2);
    if (func_ov031_0223d394(0x80)) func_ov031_02225148(3);

    if (func_ov031_0223d354(1)) {
        Struct_ov031_02224a74* obj = data_ov031_02250bfc;
        int r4 = obj->unknown_121_;
        if (r4 < 0x2f) {
            if (obj->field124 == 0) {
                func_ov031_02236878(9);
                return;
            }
            unsigned char r3 = obj->unknown_11d_;
            obj->field11c = data_ov031_0224b424[r3][r4];
            if (data_ov031_02250bfc->unknown_11d_ == 1) {
                func_ov031_02224f20(0);
            }
            return;
        } else {
            int idx = r4 - 0x2f;
            if (idx < 4) {
                switch (idx) {
                case 0:
                    func_ov031_022247bc();
                    return;
                case 1:
                    func_ov031_022247ec();
                    return;
                case 2:
                    if (obj->field124 == 0) {
                        func_ov031_02236878(9);
                        return;
                    }
                    break;
                case 3:
                    if (obj->unknown_123_ == 0) {
                        func_ov031_02236878(9);
                        return;
                    }
                    break;
                }
                if (obj->unknown_11d_ == 1) {
                    func_ov031_02224f20(0);
                }
                data_ov031_02250bfc->field11c = data_ov031_02248a04[r4 - 0x2f];
                return;
            } else {
                obj->field11c = data_ov031_022489b8[r4 - 0x33];
            }
        }
    }

    if (func_ov031_0223d394(2)) {
        Struct_ov031_02224a74* obj2 = data_ov031_02250bfc;
        if (obj2->unknown_123_ == 0) {
            if (obj2->unknown_125_ != 0) {
                return;
            }
            func_ov031_02236878(9);
            data_ov031_02250bfc->unknown_125_ = 1;
            return;
        }
        obj2->field11c = 0x80;
        goto after_field36_check;
    } else if (func_ov031_0223d3d4(2)) {
        data_ov031_02250bfc->unknown_125_ = 0;
    }
after_field36_check:

    if (func_ov031_0223d354(0x400)) {
        func_ov031_022247bc();
    }
    if (func_ov031_0223d354(0x800)) {
        func_ov031_022247ec();
    }
}
