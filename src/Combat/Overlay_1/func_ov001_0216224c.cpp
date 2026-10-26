#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void func_020a1ef0(int id);
extern int data_ov001_021658b8;
extern "C" void func_ov028_021d96bc(int);

// USA: func_ov001_0216224c
extern "C" ARM int func_ov001_0216224c(void) {
    func_020a1ef0(5);
    SetFlags00(GetGameResources(), 0x1000);
    func_ov028_021d96bc(data_ov001_021658b8);
    return 1;
}
