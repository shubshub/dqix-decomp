#include <globaldefs.h>

struct Struct_ov031_0224e588 {
    int* state;
};

extern Struct_ov031_0224e588 data_ov031_0224e588;

// USA: func_ov031_02210ef8
extern "C" ARM int func_ov031_02210ef8(void) {
    if (data_ov031_0224e588.state == NULL) {
        return 0;
    }
    return *data_ov031_0224e588.state == 7;
}
