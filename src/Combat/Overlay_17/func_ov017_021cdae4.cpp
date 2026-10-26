#include <globaldefs.h>

extern "C" void func_020103c8(int val, int arg);

// USA: func_ov017_021cdae4
extern "C" ARM void func_ov017_021cdae4(int flag, void* rec, int val) {
    if (flag != 0) {
        return;
    }
    func_020103c8(val, *(int*)((char*)rec + 4));
}
