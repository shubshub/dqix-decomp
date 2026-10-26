#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_020c54a4(int enable, unsigned int arg1, unsigned int arg2, unsigned short arg3);
typedef void (*Type_ov001_02161e8c)(int, unsigned int, unsigned int, unsigned int);

struct Struct_ov001_02161e8c { unsigned int v[14]; };
struct Struct_ov001_02161e8c_2 { struct Struct_ov001_02161e8c unknown_0_; };

struct Struct_ov001_02161e8c_3 { char pad[0x85]; unsigned char flag; };

// USA: func_ov001_02161e8c
extern "C" ARM int func_ov001_02161e8c(void* param0) {
    Struct_ov001_02161e8c_3* holder = (Struct_ov001_02161e8c_3*)LightingManager::GetInstance();
    if (func_ov017_021d60f4(param0) == 0) {
        holder->flag = 0;
        func_020c54a4(0, 0, 0, 0);
    } else {
        Struct_ov001_02161e8c_2 copy;
        Struct_ov001_02161e8c_2 tmp;
        Struct_ov001_02161e8c_2* var3 = &tmp;
        var3->unknown_0_ = ((Struct_ov001_02161e8c_2*)((char*)LightingManager::GetInstance() + 0x4c))->unknown_0_;
        copy.unknown_0_ = var3->unknown_0_;
        holder->flag = 1;
        ((Type_ov001_02161e8c)func_020c54a4)(1, copy.unknown_0_.v[1], copy.unknown_0_.v[2], copy.unknown_0_.v[3]);
    }
    return 1;
}
