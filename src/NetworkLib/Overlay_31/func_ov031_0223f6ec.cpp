#include <globaldefs.h>

struct Struct_ov031_0223ea84;
extern "C" int func_ov031_022412e8(Struct_ov031_0223ea84*, int*);
extern "C" int func_ov031_0223fb8c(const char*, int);

struct Struct_ov031_0223f6ec {
    unsigned char field_0x0[0x10];
    int* value;
};

// USA: func_ov031_0223f6ec
extern "C" ARM int func_ov031_0223f6ec(Struct_ov031_0223ea84* input, Struct_ov031_0223f6ec* output) {
    int address;
    int length = func_ov031_022412e8(input, &address);
    if (length >= 0) {
        *output->value = func_ov031_0223fb8c((const char*)address, length);
        return *output->value >= 0;
    }
    return 0;
}
