#include <globaldefs.h>

extern void* data_ov017_021d83ac;
extern "C" void func_ov002_0216bfd4(void* obj, int mode);

// USA: func_ov017_021a5a28
extern "C" ARM void func_ov017_021a5a28(void* unused, int mode) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_0216bfd4(data_ov017_021d83ac, mode);
}
