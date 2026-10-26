#include <globaldefs.h>

struct Struct_ov031_022489c4_2 { unsigned short x, y; };
struct Struct_ov031_022493b8_2 { unsigned short x, y, x2, y2; };

extern "C" void func_ov031_0223cb34(Struct_ov031_022489c4_2*, Struct_ov031_022489c4_2*, Struct_ov031_022493b8_2*);
extern "C" int func_ov031_0223d5ac(Struct_ov031_022493b8_2*);
extern "C" void func_ov031_02224f20(int);
extern "C" void func_ov031_0222506c(void);
extern "C" void func_ov031_022247bc(void);
extern "C" void func_ov031_022247ec(void);

struct Struct_ov031_022244d4 {
    unsigned char pad[0x11c];
    unsigned char field11c;
    unsigned char unknown_11d_;
    signed char unknown_11e_;
    unsigned char pad2[0x121 - 0x11f];
    signed char unknown_121_;
};
extern Struct_ov031_022244d4* data_ov031_02250bfc;

extern Struct_ov031_022493b8_2 data_ov031_022493b8;
extern Struct_ov031_022489c4_2 data_ov031_02248a0c[47];
extern Struct_ov031_022489c4_2 data_ov031_022489c8;
extern unsigned char* data_ov031_0224b424[];
extern Struct_ov031_022489c4_2 data_ov031_022489ec[2];
extern Struct_ov031_022489c4_2 data_ov031_022489fc[2];
extern unsigned char data_ov031_02248a04[];
extern Struct_ov031_022489c4_2 data_ov031_022489dc[2];
extern Struct_ov031_022489c4_2 data_ov031_022489c4;
extern unsigned char data_ov031_022489b8[];
extern Struct_ov031_022489c4_2 data_ov031_022489e4;
extern Struct_ov031_022489c4_2 data_ov031_022489f4;
extern Struct_ov031_022489c4_2 data_ov031_022489e8;
extern Struct_ov031_022489c4_2 data_ov031_022489f8;

// USA: func_ov031_022244d4
extern "C" ARM void func_ov031_022244d4(void) {
    data_ov031_02250bfc->field11c = 0;
    if (!func_ov031_0223d5ac(&data_ov031_022493b8)) return;
    Struct_ov031_022493b8_2 buf;
    int i;
    for (i = 0; i < 47; i++) {
        func_ov031_0223cb34(&data_ov031_02248a0c[i], &data_ov031_022489c8, &buf);
        if (func_ov031_0223d5ac(&buf)) {
            Struct_ov031_022244d4* p = data_ov031_02250bfc;
            if (p->unknown_11e_ != i) return;
            p->field11c = data_ov031_0224b424[p->unknown_11d_][i];
            if (data_ov031_02250bfc->unknown_11d_ == 1) {
                func_ov031_02224f20(0);
            }
            data_ov031_02250bfc->unknown_121_ = i;
            func_ov031_0222506c();
            return;
        }
    }
    Struct_ov031_022489c4_2* b = data_ov031_022489fc;
    Struct_ov031_022489c4_2* t = data_ov031_022489ec;
    for (i = 2; i < 4; i++, b++, t++) {
        func_ov031_0223cb34(t, b, &buf);
        if (func_ov031_0223d5ac(&buf)) {
            Struct_ov031_022244d4* p = data_ov031_02250bfc;
            if (p->unknown_11e_ != i + 47) return;
            p->field11c = data_ov031_02248a04[i];
            if (data_ov031_02250bfc->unknown_11d_ == 1) {
                func_ov031_02224f20(0);
            }
            data_ov031_02250bfc->unknown_121_ = i + 47;
            func_ov031_0222506c();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov031_0223cb34(&data_ov031_022489dc[i], &data_ov031_022489c4, &buf);
        if (func_ov031_0223d5ac(&buf)) {
            Struct_ov031_022244d4* p = data_ov031_02250bfc;
            if (p->unknown_11e_ != i + 51) return;
            p->field11c = data_ov031_022489b8[i];
            data_ov031_02250bfc->unknown_121_ = i + 51;
            func_ov031_0222506c();
            return;
        }
    }
    func_ov031_0223cb34(&data_ov031_022489e4, &data_ov031_022489f4, &buf);
    if (func_ov031_0223d5ac(&buf)) {
        if (data_ov031_02250bfc->unknown_11e_ != 47) return;
        func_ov031_022247bc();
        data_ov031_02250bfc->unknown_121_ = 47;
        func_ov031_0222506c();
        return;
    }
    func_ov031_0223cb34(&data_ov031_022489e8, &data_ov031_022489f8, &buf);
    if (!func_ov031_0223d5ac(&buf)) return;
    if (data_ov031_02250bfc->unknown_11e_ != 48) return;
    func_ov031_022247ec();
    data_ov031_02250bfc->unknown_121_ = 48;
    func_ov031_0222506c();
}
