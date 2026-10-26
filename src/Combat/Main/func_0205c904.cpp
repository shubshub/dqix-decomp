#include <globaldefs.h>
#if defined(jpn)
#define FIRST_FLAG 0x1c3
#define SECOND_FLAG 0x1c4
#define TIMED_STATE 0x1804
#else
#define FIRST_FLAG 0x233
#define SECOND_FLAG 0x234
#define TIMED_STATE 0x19e0
#endif

extern "C" unsigned char* MessageSystem_GetInstance(void);
extern "C" void func_02042b10(void* obj, void* value);
extern "C" void WindowFrame_Update(void* obj, int amount);
extern "C" void func_02042b1c(unsigned char* base);
extern "C" int func_0205cde8(unsigned char* p);
extern "C" int Window_HandleInput(void* selfPtr, void* p1);

// USA: func_0205c904
extern "C" ARM void func_0205c904(unsigned char* obj, int flag) {
    if (obj[FIRST_FLAG] == 0) {
        return;
    }

    if (obj[SECOND_FLAG] == 0) {
        return;
    }

    unsigned char* ctx = MessageSystem_GetInstance();
    func_02042b10(ctx, obj + 0xb4);
    WindowFrame_Update(ctx + TIMED_STATE, flag);
    func_02042b1c(ctx);

    if (func_0205cde8(obj) == 0) {
        return;
    }

    Window_HandleInput(obj + 0x1c, (void*)flag);
}
