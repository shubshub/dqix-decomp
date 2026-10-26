#include <globaldefs.h>

#if defined(jpn)
#define func_020db9cc func_020dd3d4
#endif

extern "C" void VCountIrq_PushDisable(void);
extern "C" void func_020db264(void* obj, int arg1, int arg2, int arg3, int arg4);
struct Struct_020db264;
extern "C" void func_020db360(struct Struct_020db264* obj, int b);
struct Struct_020db3f4_3;
extern "C" void func_020db844(struct Struct_020db3f4_3* a, int b, int c, int d);
extern "C" void func_020db894(void* obj);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_020db9cc
extern "C" ARM int func_020db9cc(void* obj, int arg1, int arg2, int arg3) {
    char* p = (char*)obj;
    if (*(int*)(p + 0x40) == 0) return 1;
    if (*(unsigned char*)(p + 0x50) == 0) return 1;
    if (*(unsigned char*)(p + 0x6c) == 0) return 1;

    int flag = 1;
    VCountIrq_PushDisable();

    if (arg2 == -16 || arg2 == 0x10) {
        if (*(unsigned char*)(p + 0x3c) != arg1) {
            flag = 1;
        } else {
            *(short*)(p + 0x66) = (short)arg2;
            *(short*)(p + 0x68) = (arg3 << 1) + 4;
            if (*(short*)(p + 0x68) >= 0 && *(short*)(p + 0x6a) == arg2) {
                func_020db264(obj, 1, *(unsigned char*)(p + 0x52), *(unsigned char*)(p + 0x53), *(unsigned char*)(p + 0x54));
                flag = 0;
                *(short*)(p + 0x68) = 0;
            }
        }
    } else {
        func_020db894(obj);
        func_020db264(obj, 0, 0, 0, 0);
        func_020db844((struct Struct_020db3f4_3*)obj, arg1, arg2, arg3);
        func_020db360((struct Struct_020db264*)obj, flag);
        flag = 0;
    }

    VCountIrq_PopDisable();
    return flag;
}
