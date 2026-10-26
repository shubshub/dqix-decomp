#include <globaldefs.h>

#if defined(jpn)
enum { stateOffset = 0x1804, Enum_0205cd94_7712 = 0x1c44 };
#else
enum { stateOffset = 0x19e0, Enum_0205cd94_7712 = 0x1e20 };
#endif
extern "C" void func_02042b10(void*, void*);

extern "C" int MessageSystem_GetInstance();
extern "C" int func_0205cd6c(unsigned char* obj);
extern "C" void func_02042b1c(unsigned char* base);

// USA: func_0205cd94
extern "C" ARM void func_0205cd94(unsigned char* p) {
    unsigned char* base = (unsigned char*)MessageSystem_GetInstance();
    func_02042b10((void*)(base), (void*)(p + 0xb4));
    if (func_0205cd6c(base + stateOffset) == 0) {
        *(int*)((char*)*(int**)(base + Enum_0205cd94_7712) + 0x8) = 2;
        *(int*)((char*)*(int**)(base + Enum_0205cd94_7712) + 0x14) = 0x1000;
    }
    func_02042b1c(base);
}
