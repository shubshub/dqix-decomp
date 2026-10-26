#include <globaldefs.h>

extern "C" int func_ov000_02177330(void* obj);
extern "C" int func_ov000_02177558(void* obj);
extern "C" int func_ov000_02177798(void* obj);
extern "C" int func_ov000_02177a7c(void* obj);
extern "C" int func_ov000_02177cb8(void* obj);
extern "C" int func_ov000_02177f28(void* obj);
extern "C" int func_ov000_0217819c(void* obj);
extern "C" int func_ov000_021785fc(void* obj);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" void func_ov000_02176498(void* obj, int flag);
extern "C" void func_ov000_021788d8(void* obj, int a, int b);
extern "C" int func_ov000_02178cbc(void* obj, int a, int b);
extern "C" int func_ov000_02179128(void* obj, int a, int b);
extern "C" int func_ov000_021795e0(void* obj, int a, int b);
extern "C" void func_ov000_02179a14(void* obj, int a, int b);
extern "C" void func_ov000_02179c6c(void* obj, int id);
extern "C" void func_ov000_0217a0a4(void* obj);
extern "C" void func_ov000_0217a628(void* obj, int a, int b);

// USA: func_ov000_02177038
extern "C" ARM void func_ov000_02177038(void* obj, int arg, int slot, int arg3, int arg4) {
    if (*(int*)((char*)obj + 0x118) == 0) {
        return;
    }
    switch (slot) {
    case 1:
        func_ov000_02177330(obj);
        break;
    case 2:
        func_ov000_02177558(obj);
        break;
    case 3:
        func_ov000_02177798(obj);
        break;
    case 4:
        func_ov000_02177a7c(obj);
        break;
    case 5:
        func_ov000_02177cb8(obj);
        break;
    case 6:
        func_ov000_02177f28(obj);
        break;
    case 7:
        func_ov000_0217819c(obj);
        break;
    case 8:
        func_ov000_021785fc(obj);
        break;
    case 13:
        if (arg != 0) {
            func_ov000_02176498((void*)arg, func_ov000_0217542c(obj));
        }
        break;
    case 14:
        func_ov000_021788d8(obj, arg, arg4);
        break;
    case 15:
        func_ov000_02178cbc(obj, arg3, arg4);
        break;
    case 16:
        func_ov000_02179128(obj, arg3, arg4);
        break;
    case 17:
        func_ov000_021795e0(obj, arg3, arg4);
        break;
    case 18:
    case 19:
    case 20:
        func_ov000_02179a14(obj, arg, arg3);
        break;
    case 21:
        func_ov000_02179c6c(obj, arg);
        break;
    case 23:
        func_ov000_0217a0a4(obj);
        break;
    case 25:
        func_ov000_0217a628(obj, arg, arg4);
        break;
    }
}
