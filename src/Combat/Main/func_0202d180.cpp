#include <globaldefs.h>
extern "C" int func_020d68dc(int, unsigned int, void*);

extern char data_021015a0;
extern char data_02101600;
extern char data_021016e0;
extern "C" void func_0202c848(int arg);
extern "C" void func_0202d1e4(unsigned short* a);

typedef int (*Type_0202d180)(void*, void*);

// USA: func_0202d180
extern "C" ARM int func_0202d180(void) {
    *(int*)(&data_021015a0 + 0x10) = 3;
    Type_0202d180 fn = *(Type_0202d180*)(&data_021015a0 + 0x30);
    int r = fn(&data_02101600, &data_021016e0);
    int result = func_020d68dc((int)((void*)func_0202d1e4), (unsigned int)(r), (void*)(&data_02101600));
    if (result == 2) {
        return 1;
    }
    func_0202c848(result);
    *(int*)(&data_021015a0 + 0x10) = 9;
    return 0;
}
