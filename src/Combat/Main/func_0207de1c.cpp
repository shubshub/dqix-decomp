#include <globaldefs.h>

struct Struct_0207d798 {
    short h0;
    unsigned short h2;
    char unknown_4_;
    char unknown_5_;
    char pad6[2];
    char b8;
    char unknown_9_;
    char unknown_a_;
    char unknown_b_;
};
extern "C" void func_0207d7c0(struct Struct_0207d798* o);

// USA: func_0207de1c
extern "C" ARM struct Struct_0207d798* func_0207de1c(struct Struct_0207d798* arr) {
    func_0207d7c0(&arr[0]);
    func_0207d7c0(&arr[1]);
    func_0207d7c0(&arr[2]);
    func_0207d7c0(&arr[3]);
    return arr;
}
