#include <globaldefs.h>


extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void* func_ov004_02153c74(void*);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_ov023_021fbdcc(void*, int);

// USA: func_ov004_02153d8c
extern "C" ARM int func_ov004_02153d8c(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x2e);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 0x10) return 0;

    void* r = func_ov004_02153c74(a);
    short val = -1;
    if (r) {
        int field = *(int*)((char*)r + 0xc);
        val = *(short*)((char*)r + 0x18);
        unsigned int t = ((unsigned int)field << 9) >> 0x15;
        unsigned short var5 = (unsigned short)t;
        int bits = var5;
        if (bits > 0) {
            unsigned char* base = (unsigned char*)Scenario_GetInstance();
            if (!Scenario_TestFlag((int)base, base + 0x8c, bits + 0x76 + 0xc00)) {
                val = -1;
            }
        }
    }
    func_ov023_021fbdcc(node, val);
    return 0;
}
