#include <globaldefs.h>

struct Struct_ov031_02222ce4;
struct Struct_020b0a1c_2;
struct Struct_ov031_0224926a_5 {
    unsigned short x;
    unsigned short y;
};
struct Struct_ov031_02236ea0 {
    void* letters[5];
    void* task;
    unsigned char unknown_18_;
};
struct Struct_ov031_02290d04_9 {
    void* screen;
    Struct_ov031_02236ea0* unknown_4_;
};
extern Struct_ov031_02290d04_9 data_ov031_02290d04;
extern unsigned char data_ov031_0224924c[3][5];
extern unsigned char data_ov031_0224925b[3][5];
extern Struct_ov031_0224926a_5 data_ov031_0224926a[5];
extern "C" Struct_020b0a1c_2* func_ov031_0223baa0(void*, int);
extern "C" void func_ov031_0223bdb0(int, int, Struct_020b0a1c_2*);
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
enum Enum_ov031_02236ea0 {
    Enum_ov031_02236ea0_0 = 0,
    Enum_ov031_02236ea0_1 = 1,
    Enum_ov031_02236ea0_2 = 2,
    Enum_ov031_02236ea0_3 = 3
};
extern "C" void func_ov031_0223bb58(void*, int, Enum_ov031_02236ea0, int);
extern "C" void func_ov031_022373b4(int);

// USA: func_ov031_02236ea0
extern "C" ARM void func_ov031_02236ea0(int kind) {
    int i;
    for (i = 0; i < 5; i += 2) {
        func_ov031_0223bdb0(1, data_ov031_0224924c[kind][i], func_ov031_0223baa0(data_ov031_02290d04.unknown_4_->letters[i], 0));
        func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02290d04.unknown_4_->letters[i], -1, 0);
        func_ov031_0223bbd8(data_ov031_02290d04.unknown_4_->letters[i], -1, data_ov031_0224926a[i].x, data_ov031_0224926a[i].y);
        func_ov031_0223bb58(data_ov031_02290d04.unknown_4_->letters[i], -1, Enum_ov031_02236ea0_0, data_ov031_0224925b[kind][i]);
    }
    func_ov031_022373b4(kind);
}
