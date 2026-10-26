#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* MessageSystem_GetInstance();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02187480
extern "C" ARM int func_ov011_02187480(unsigned int obj) {
    int state = *(int*)((char*)MessageSystem_GetInstance() + R(0x870, 0x9a0));
    int flag = 1;
    if (state == 0 || state == 3) flag = 0;
    func_ov011_02184c68(obj, flag);
    return 1;
}
