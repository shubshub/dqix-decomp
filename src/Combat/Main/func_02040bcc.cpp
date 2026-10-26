#include <globaldefs.h>

extern "C" void func_0203cea4(unsigned int* obj);
struct Struct_02040bcc;
extern "C" void func_02041538(struct Struct_02040bcc*);

// USA: func_02040bcc
extern "C" ARM void func_02040bcc(char* self) {
    void* a = *(void**)(self + 0x14);
    if (a != NULL) {
        func_0203cea4((unsigned int*)a);
        return;
    }
    void* b = *(void**)(self + 0x18);
    if (b == NULL) return;
    func_02041538((struct Struct_02040bcc*)b);
}
