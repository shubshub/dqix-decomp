#include <globaldefs.h>

struct Struct_ov000_02184288_4 {
    int unk0;
    void* ptr;
    int unknown_8_;
};
extern struct Struct_ov000_02184288_4 data_ov000_02184288;

// USA: func_ov000_021744f4
extern "C" ARM void func_ov000_021744f4(int unused, void* val) {
    data_ov000_02184288.ptr = val;
}
