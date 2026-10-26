#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
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
extern "C" void func_ov023_021fbdcc(void*, int);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern char data_ov004_0216fffa;

// USA: func_ov004_02168290
extern "C" ARM int func_ov004_02168290(void* obj) {
    void* var0 = func_ov023_021f6880(func_ov011_021849c8(obj), 7);
    if (var0 && func_ov024_021f6f10(var0) == 0x10) {
        void* node2 = func_ov023_021f6880(func_ov011_021849c8(obj), 0xe);
        if (!node2) {
            return 0;
        }
        if (func_ov024_021f6f10(node2) != 7) {
            return 0;
        }
        int idx = func_ov023_021f9bc8((char*)node2);
        short val = *(short*)(&data_ov004_0216fffa + idx * 4);
        func_ov023_021fbdcc(var0, val);
    }
    func_ov011_021848a0(obj, 0x68);
    return 0;
}
