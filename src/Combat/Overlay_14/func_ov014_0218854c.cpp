#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov014_0218854c func_ov014_0218942c
#endif

struct Struct_02081164;

extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_02080798(void* obj, int id, int value);
extern "C" void func_02081164(struct Struct_02081164* obj, int id, int value);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_0218854c
extern "C" ARM void func_ov014_0218854c(void* self) {
    int flag = (*((unsigned char*)self + 0x17e) & 8) ? 1 : 0;
    short val = 0x1b + flag;
    func_0208103c(*(void**)((char*)self + 0xc0), 0x1a, val);
#if !defined(jpn)
    func_02080798(*(void**)((char*)self + 0xc0), 0x1a, 1);
#endif
    func_02081164(*(struct Struct_02081164**)((char*)self + 0xc0), 4, 1);
    func_02080c68(*(void**)((char*)self + 0xc0), 4, 1);
    func_020813ec(*(void**)((char*)self + 0xc0), 4);
}
