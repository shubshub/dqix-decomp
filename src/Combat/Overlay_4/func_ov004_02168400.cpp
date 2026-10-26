#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#define data_ov004_0216fff8 data_ov004_02170750
#define data_ov004_0216fffa data_ov004_02170752
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" int func_ov004_02167a0c(void* unused, int count);
extern "C" int func_ov004_02167a6c(void* a, void* b);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern char data_ov004_0216fff8;
extern char data_ov004_0216fffa;

// USA: func_ov004_02168400
#pragma opt_common_subs off
extern "C" ARM int func_ov004_02168400(void* obj) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0xe);
    if (!node) {
        return 0;
    }
    if (func_ov024_021f6f10(node) != 7) {
        return 0;
    }
    int idx = func_ov023_021f9bc8((char*)node);
    if (idx >= 0 && idx < 6) {
        func_ov004_02167a0c(obj, *(short*)(&data_ov004_0216fff8 + idx * 4));
        func_ov004_02167a6c(obj, (void*)(int)*(short*)(&data_ov004_0216fffa + idx * 4));
    }
    func_ov011_021848a0(obj, 0x8c);
    return 0;
}
