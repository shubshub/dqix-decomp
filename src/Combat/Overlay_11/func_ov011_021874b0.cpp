#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov011_02184c68(void* obj, int val);

// USA: func_ov011_021874b0
extern "C" ARM int func_ov011_021874b0(void* obj) {
    int val = *(int*)((char*)(int)MessageSystem_GetInstance() + R(0x868, 0x998));
    func_ov011_02184c68(obj, val);
    return 1;
}
