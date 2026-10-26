#include <globaldefs.h>

extern "C" void func_020d1f0c(unsigned long arg0, unsigned long arg1, int arg2, int flags);
extern "C" unsigned long func_020d26ec();
extern "C" void func_020d24c4(int block);
extern "C" void func_020d2680(unsigned int arg0);
extern "C" int func_020c7ea0(void* queue, void** msg, int flags);
extern "C" void func_020bbe94(int mask);
extern "C" void func_020bbe64(int mask);
extern "C" void func_020bbef8(int arg0);
extern "C" void func_020d2104(int left, int right, int arg2, int arg3);

struct Struct_0210fdbc {
    int unknown_0_;
    int type;
    int format;
    void* unknown_c_;
    void* unknown_10_;
    unsigned long unknown_14_;
    unsigned long unknown_18_;
    int unknown_1c_;
    unsigned long unknown_20_;
    unsigned long unknown_24_;
    unsigned long unknown_28_;
    int unknown_2c_;
};

struct Struct_0210fd74 {
    char pad[0x48];
    int unknown_48_;
};

extern Struct_0210fd74 data_0210fd74;
extern Struct_0210fdbc data_0210fdbc;
extern char data_0210fd7c;

// USA: func_020bcf3c
extern "C" ARM void func_020bcf3c(void) {
    Struct_0210fdbc* cap = &data_0210fdbc;
    unsigned long var1;
    int var2;

    if (!data_0210fd74.unknown_48_)
        return;

    var2 = cap->unknown_2c_ >= 0 ? 1 : 0;

    func_020d1f0c(cap->unknown_24_, cap->unknown_28_, var2 ? 1 << cap->unknown_2c_ : 0, 0);

    if (var2) {
        var1 = func_020d26ec();
        func_020d24c4(1);
        func_020d2680(var1);

        while (func_020c7ea0(&data_0210fd7c, NULL, 0)) {
        }
    }

    if (cap->unknown_28_)
        func_020bbe94(cap->unknown_28_);
    if (cap->unknown_20_)
        func_020bbe64(cap->unknown_20_);
    if (var2)
        func_020bbef8(cap->unknown_2c_);

    if (cap->type == 1)
        func_020d2104(0, 0, 0, 0);

    cap->unknown_0_ = 0;
}
