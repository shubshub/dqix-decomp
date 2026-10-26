#include <globaldefs.h>

#if defined(jpn)
enum { stateOffset = 0x1804 };
#else
enum { stateOffset = 0x19e0 };
#endif
extern "C" void func_02042b10(void*, void*);

extern "C" int MessageSystem_GetInstance();
extern "C" int func_0205cd6c(unsigned char* obj);
extern "C" void func_02042b1c(unsigned char* base);

// USA: func_0205cde8
extern "C" ARM int func_0205cde8(unsigned char* p) {
    unsigned char* base = (unsigned char*)MessageSystem_GetInstance();
    func_02042b10((void*)(base), (void*)(p + 0xb4));
    int result = func_0205cd6c(base + stateOffset) != 0;
    func_02042b1c(base);
    return result;
}
