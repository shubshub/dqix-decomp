#include <globaldefs.h>

struct Struct_ov031_0224e234_2 {
    void* unk0;
    void (*unknown_4_)(void*, void*, unsigned int);
};

extern Struct_ov031_0224e234_2 data_ov031_0224e234;

// USA: func_ov031_02207620
extern "C" ARM void func_ov031_02207620(void* ptr) {
    if (ptr != NULL) {
        unsigned int header = *((unsigned int*)ptr - 1);
        data_ov031_0224e234.unknown_4_(0, (unsigned int*)ptr - 1, header);
    }
}
