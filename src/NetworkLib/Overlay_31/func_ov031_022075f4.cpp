#include <globaldefs.h>

struct Struct_ov031_0224e234 {
    void* unk0;
    void* unk4;
    void* unknown_8_;
    void* (*unknown_c_)(void*, unsigned int);
};

extern Struct_ov031_0224e234 data_ov031_0224e234;

// USA: func_ov031_022075f4
extern "C" ARM void* func_ov031_022075f4(unsigned int size) {
    unsigned int total = size + 4;
    void* ptr = data_ov031_0224e234.unknown_c_(0, total);
    if (ptr != NULL) {
        *(unsigned int*)ptr = total;
        ptr = (char*)ptr + 4;
    }
    return ptr;
}
