#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov000_02184294_9 {
#if defined(jpn)
    void* field8;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    void* field8;
#endif
};
extern Struct_ov000_02184294_9 data_ov000_02184294;

extern "C" void func_ov000_02175628(void* obj);
extern "C" void func_ov000_021756b8(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg3, int arg4, int one);

// USA: func_ov000_0217c094
extern "C" ARM int func_ov000_0217c094(char* obj) {
    func_ov000_02175628(data_ov000_02184294.field8);
    int t = g_keyManager.TestKeysPressed(0x802);
    if (t != 0 || g_touchInput.pressed_ != 0) {
        func_ov000_021756b8(data_ov000_02184294.field8);
        char* sub = obj + 8;
        signed char idx1 = *(signed char*)(sub + 0x10);
        *(unsigned char*)(sub + idx1 + 8) = 0;
        *(signed char*)(sub + 0x10) = *(signed char*)(sub + 0x10) - 1;
        func_ov000_0217ab8c(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
        func_ov000_02176e3c(data_ov000_02184294.field8, (int)obj, *(signed char*)(obj + *(signed char*)(obj + 0x18) + 0x10), data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
