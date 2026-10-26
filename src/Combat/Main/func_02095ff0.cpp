#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
struct Struct_02095ff0;
extern "C" void func_020a0364(struct Struct_02095ff0* p, unsigned int amount);
extern "C" ARM int func_020ac4c0(void* dst);
extern "C" ARM int func_020ac494(void* src);
extern "C" ARM void func_0209609c(int unused, unsigned char* arr, int index);
extern "C" ARM int func_02096100(int unused, unsigned char* arr, int idx);

// USA: func_02095ff0
extern "C" ARM void func_02095ff0(void* obj, int idx) {
    unsigned char buf[0xb0];
    if (idx > 0xcc || idx < 0) return;

    void* f = Scenario_GetInstance();
    if (Scenario_TestFlag((int)f, (unsigned char*)f + 0x8c, 0x1138)) {
        short* p = (short*)((char*)f + 0x2ca);
        *p = *p + 1;
    }

    if (!func_02096100((int)obj, (unsigned char*)obj + 0x84, idx)) {
        func_020ac4c0(buf);
        func_020a0364((struct Struct_02095ff0*)buf, 1);
        func_020ac494(buf);
    }

    func_0209609c((int)obj, (unsigned char*)obj + 0x84, idx);
}
