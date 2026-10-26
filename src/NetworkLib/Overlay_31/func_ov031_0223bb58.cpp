#include <globaldefs.h>

struct Struct_ov031_0223bb58 {
    unsigned int word0;
    unsigned short unknown_4_;
    unsigned short pad6;
};

// USA: func_ov031_0223bb58
extern "C" ARM void func_ov031_0223bb58(void* obj, int idx, int a, int b) {
    Struct_ov031_0223bb58* arr = *(Struct_ov031_0223bb58**)((char*)obj + 0x8);
    if (idx >= 0) {
        arr[idx].word0 = (arr[idx].word0 & ~0xc00) | (a << 10);
        arr[idx].unknown_4_ = (arr[idx].unknown_4_ & ~0xf000) | (b << 12);
    } else {
        for (int i = 0; i < *((unsigned char*)obj + 0xc); i++) {
            arr[i].word0 = (arr[i].word0 & ~0xc00) | (a << 10);
            arr[i].unknown_4_ = (arr[i].unknown_4_ & ~0xf000) | (b << 12);
        }
    }
}
