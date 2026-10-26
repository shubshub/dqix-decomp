#include <globaldefs.h>

struct Struct_020c2c94 {
    unsigned short ctrl;
    unsigned char pad[0xe];
    long long unknown_10_;
    long long unknown_18_;
};

// USA: func_020c2c94
extern "C" ARM void fix32_QueueComputeReciprocal(int arg0) {
    struct Struct_020c2c94* r = (struct Struct_020c2c94*)0x4000280;
    r->ctrl = 1;
    r->unknown_10_ = 0x100000000000LL;
    r->unknown_18_ = (unsigned int)arg0;
}
