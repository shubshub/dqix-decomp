#if defined(jpn)
enum {regionalOffset0=0xb94};
#else
enum {regionalOffset0=0xc18};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_02167f10(void* obj);
extern "C" void func_ov025_021def64(void* obj, void* ptr, int n);
extern "C" void func_ov000_0216dbf0(void* ptr, int* out, int a, int b);
extern "C" void Camera_Shake(unsigned char* obj, int a, int b);

struct Struct_ov025_021dce7c {
    unsigned short field0;
};

// USA: func_ov025_021dce7c
extern "C" ARM int func_ov025_021dce7c(unsigned char* obj, struct Struct_ov025_021dce7c* ptr, int arg2) {
    if (ptr) {
        GameState::GetInstance();
        if (ptr->field0 == 781 || ptr->field0 == 582) {
            int local = arg2;
            func_ov000_02167f10(obj);
            func_ov025_021def64(obj, ptr, 0x18);
            func_ov000_0216dbf0(obj + regionalOffset0, &local, 1, 1);
            Camera_Shake(obj + regionalOffset0, 409, 2000);
            return 1;
        }
    }
    return 0;
}
