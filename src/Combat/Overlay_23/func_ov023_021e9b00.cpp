#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void* obj);
extern "C" unsigned short func_0206e384(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9b00
extern "C" ARM int func_ov023_021e9b00(void* obj) {
    void* sub = Scenario_GetInstance(obj);
    unsigned int var1 = 0xffff | (func_0206e384((unsigned char*)sub) << 16);
    int count = 0;
    while (var1 != 0) {
        count += var1 & 1;
        var1 >>= 1;
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
