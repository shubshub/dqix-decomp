#include <globaldefs.h>

struct Struct_ov000_02184288_4 {
    int unk0;
    void* ptr;
    int unknown_8_;
};
extern struct Struct_ov000_02184288_4 data_ov000_02184288;

// USA: func_ov000_02174504
extern "C" ARM void* func_ov000_02174504(void) {
    return data_ov000_02184288.ptr;
}
