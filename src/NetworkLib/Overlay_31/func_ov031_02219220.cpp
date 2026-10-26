#include <globaldefs.h>
struct Struct_ov031_02219220 { unsigned char pad[0x1000 + 4]; int unknown_1004_; };
extern Struct_ov031_02219220 *data_ov031_0224e60c;
// USA: func_ov031_02219220
extern "C" ARM int func_ov031_02219220(void) {
    return data_ov031_0224e60c->unknown_1004_;
}
