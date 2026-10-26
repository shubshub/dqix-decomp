#include <globaldefs.h>

struct Struct_ov023_021fff08 {
    char pad[0x4];
    void *ptr;
};

extern struct Struct_ov023_021fff08 data_ov023_021fff08;

// USA: func_ov023_021f5598
extern "C" ARM void func_ov023_021f5598(void *value) {
    data_ov023_021fff08.ptr = value;
}
