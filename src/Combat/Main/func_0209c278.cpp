#include <globaldefs.h>
extern "C" void func_0209c20c(struct Actor0209c20c*);

extern "C" void SoundPlayer_Reset(void*);

// USA: func_0209c278
extern "C" ARM void func_0209c278(void* obj) {
    func_0209c20c((struct Actor0209c20c*)(obj));
    SoundPlayer_Reset(obj);
}
