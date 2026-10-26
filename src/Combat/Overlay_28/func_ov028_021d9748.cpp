#include <globaldefs.h>

struct Struct_ov028_021d9b14 {
    char pad[0xa8];
    unsigned long long unknown_a8_;
};

extern struct Struct_ov028_021d9b14 data_ov028_021d9b14;

// USA: func_ov028_021d9748
extern "C" ARM unsigned long long func_ov028_021d9748() {
    return (data_ov028_021d9b14.unknown_a8_ << 6) / 0x82ea;
}
