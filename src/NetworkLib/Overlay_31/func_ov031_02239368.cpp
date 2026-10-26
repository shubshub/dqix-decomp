#include <globaldefs.h>
#include "NitroSDK/RequestSubmission.h"

extern "C" ARM void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_022393e4(int v);

struct Struct_ov031_02290d18_3 { unsigned char pad[4]; unsigned char* inner; };
extern Struct_ov031_02290d18_3 data_ov031_02290d18;

// USA: func_ov031_022398e8
extern "C" ARM int func_ov031_022398e8(void) {
    func_ov031_02239368(6);
    int r = func_020d68b4(data_ov031_02290d18.inner + 0x1e00, 0xd);
    if (r == 2) {
        return 1;
    }
    func_ov031_022393e4(r);
    return 0;
}
