#include <globaldefs.h>

struct Struct_ov031_02213024 { unsigned char pad[0x17]; unsigned char unknown_17_; };
struct Struct_ov031_0224e5c4_3 { unsigned char pad[0xc]; Struct_ov031_02213024* unknown_c_; };
extern Struct_ov031_0224e5c4_3 data_ov031_0224e5c4;
extern "C" ARM int func_ov031_022134b0(void);

// USA: func_ov031_02213024
extern "C" ARM int func_ov031_02213024(void) {
    unsigned char result = 0xff;
    unsigned int v = func_ov031_022134b0();
    if (v >= 0xa && v <= 0x10) {
        result = data_ov031_0224e5c4.unknown_c_->unknown_17_;
    }
    return result;
}
