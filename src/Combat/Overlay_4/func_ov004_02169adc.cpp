#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_ov004_02168ed8(void* obj, int id, int mask);
extern "C" void func_ov004_02168eac(void* obj, int id, int mask);
#define func_ov023_021f6600 func_ov004_02168ed8
#define func_ov023_021f65d4 func_ov004_02168eac
#else
extern "C" void func_ov023_021f6600(void* obj, int id, int mask);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
#endif
extern "C" void func_ov011_021848a0(void* obj, int val);
extern void* data_ov004_02171030;

#if defined(jpn)
enum { Enum_ov004_02169adc_400 = 0x10 };
#else
enum { Enum_ov004_02169adc_400 = 0x190 };
#endif

// USA: func_ov004_02169adc
extern "C" ARM int func_ov004_02169adc(void* obj) {
    func_ov023_021f6600(obj, 0x1e, 0x18);
    func_ov023_021f6600(obj, 0x1f, 0x18);
    func_ov023_021f65d4(obj, 2, 8);
    void* p = *(void**)((char*)data_ov004_02171030 + Enum_ov004_02169adc_400);
    if (!p) return 0;
    if (*(unsigned char*)p != 0) {
        func_ov011_021848a0(obj, 0x48);
    }
    return 0;
}
