#include <globaldefs.h>

extern "C" ARM char* func_ov031_02235c70(void);
extern "C" int func_ov031_02230330(char* arg);
extern "C" int func_ov031_0222fd9c(void);
extern "C" int func_ov031_02236878(int index);
extern "C" ARM void func_ov031_02230984(int idx);
extern "C" void func_ov031_02230d2c(void);
extern "C" void func_ov031_0222f20c(int idx);

// USA: func_ov031_0222f188
extern "C" ARM int func_ov031_0222f188(void) {
    int tag = func_ov031_02230330(func_ov031_02235c70());
    if (tag == 0xe) return 0;
    if (func_ov031_0222fd9c() == 0) {
        func_ov031_02236878(9);
        return 1;
    }
    func_ov031_02230984(tag);
    switch (tag) {
        case 2:
        case 3:
        case 7:
        case 8:
            func_ov031_02230d2c();
            break;
        default:
            break;
    }
    func_ov031_0222f20c(tag);
    return 1;
}
