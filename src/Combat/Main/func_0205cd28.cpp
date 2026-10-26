#if defined(jpn)
#define CONTROLLER_OFFSET_LO 4
#define CONTROLLER_OFFSET_HI 0x1800
#else
#define CONTROLLER_OFFSET_LO 0x9e0
#define CONTROLLER_OFFSET_HI 0x1000
#endif
#include <globaldefs.h>

struct Field440Obj0202f6a4;

extern "C" void func_02042b10(void*, void*);
extern "C" void func_02042b1c(unsigned char*);
extern "C" void WindowFrame_Open(Field440Obj0202f6a4*);
extern "C" int func_0205cd6c(unsigned char*);
extern "C" unsigned char* MessageSystem_GetInstance();

// USA: func_0205cd28
extern "C" ARM void func_0205cd28(unsigned char* self) {
    unsigned char* global = MessageSystem_GetInstance();
    func_02042b10(global, self + 0xb4);
    if (func_0205cd6c(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI) == 0) {
        WindowFrame_Open((Field440Obj0202f6a4*)(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI));
    }
    func_02042b1c(global);
}
