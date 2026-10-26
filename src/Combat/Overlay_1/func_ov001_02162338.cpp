#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"

extern "C" void func_ov017_021d6134(void* obj, int enable);
extern "C" void Overlay_Load(unsigned int id);
extern "C" int Overlay_Unload(unsigned int id);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" int func_ov029_021d8e94(void* invoker, void* callback, int arg);
extern "C" int func_ov029_021d8f84(void* invoker, void* callback, int arg);
extern "C" int func_ov029_021d9074(void* invoker, void* callback, int arg);
int InvokeCallbackReturn1bf27f_0215a6fc(void (*callback)());
int InvokeCallbackReturn1befcb_0215a718(void (*callback)());
int InvokeCallbackReturn1beb10_0215a734(void (*callback)());
void IncrementCounterBy1_021622f0();
void IncrementCounterBy2_02162308();
void IncrementCounterBy3_02162320();
extern char data_ov001_02165880;

static inline int inline_ov001_02162338(int arg0, int arg1) {
    return arg0 == arg1;
}

// USA: func_ov001_02162338
// EUR: func_ov001_02162338
#if defined(jpn)
extern "C" int data_ov029_021d9c40_fake(void (*arg0)());
extern "C" int data_ov029_0216398c_fake(void (*arg0)());
extern "C" int data_ov029_0216399c_fake(void (*arg0)());
#endif

extern "C" ARM int func_ov001_02162338(void* arg0, int arg1) {
#if defined(jpn)
    func_ov017_021d6134(obj, 1);
    unsigned int id = OVERLAY_ID(29);
    Overlay_Load(id);
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
    if (data_ov029_021d9c40_fake(func_ov001_021622f0)
        && data_ov029_0216398c_fake(func_ov001_02162308)
        && data_ov029_0216399c_fake(func_ov001_02162320)
        && *(unsigned int*)(&data_ov001_02165880 + 0x28) >= 6) {
        func_ov017_021d6134(arg0, 0);
    }
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
    Overlay_Unload(id);
    return 1;
#else
    func_ov017_021d6134(obj, 1);
    unsigned int id = OVERLAY_ID(29);
    Overlay_Load(id);
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
#if defined(eur)
    if (arg1 > 1 && func_ov017_021d60f4((char*)arg0 + 8) == 2) {
#else
    if (arg1 > 1 && func_ov017_021d60f4((char*)arg0 + 8) == 1) {
#endif
        if (inline_ov001_02162338(func_ov029_021d8e94(func_ov001_0215a6fc, func_ov001_021622f0, 0), 0x1bf27f)
            && inline_ov001_02162338(func_ov029_021d8f84(func_ov001_0215a718, func_ov001_02162308, 0), 0x1befcb)
            && inline_ov001_02162338(func_ov029_021d9074(func_ov001_0215a734, func_ov001_02162320, 0), 0x1beb10)
            && *(unsigned int*)(&data_ov001_02165880 + 0x28) >= 6) {
            func_ov017_021d6134(arg0, 0);
        }
    } else {
        func_ov017_021d6134(arg0, 0);
    }
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
    Overlay_Unload(id);
    return 1;
#endif
}
