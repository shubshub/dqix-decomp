#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020ae694(int mode, int key1, unsigned short key2);
extern "C" void func_020ae4ec(int param0, int param1);

// USA: func_020ae990
extern "C" ARM void func_020ae990(int a) {
    if (*(unsigned short*)Zone3D_GetInstance() != 0x1647) return;
    if (a == 0) {
        func_020ae694(1, 0, 4);
    } else {
        func_020ae694(0, 0, 4);
    }
    func_020ae4ec(0x2e, a != 0);
}
