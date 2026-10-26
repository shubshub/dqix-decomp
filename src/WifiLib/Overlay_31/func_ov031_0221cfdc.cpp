#include <globaldefs.h>

struct Struct_ov031_0224e6e0_4 {
    int field_0x0;
    void* first;
    int unknown_8_;
    void* second;
};
extern Struct_ov031_0224e6e0_4 data_ov031_0224e6e0;
extern "C" void func_ov031_0221c4ac(int handle);

// USA: func_ov031_0221cfdc
extern "C" THUMB void func_ov031_0221cfdc() {
    if (data_ov031_0224e6e0.second) {
        func_ov031_0221c4ac((int)data_ov031_0224e6e0.second);
        data_ov031_0224e6e0.second = 0;
    }
    if (data_ov031_0224e6e0.first) {
        func_ov031_0221c4ac((int)data_ov031_0224e6e0.first);
        data_ov031_0224e6e0.first = 0;
    }
}
