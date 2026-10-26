#include <globaldefs.h>

extern "C" int func_ov001_02164624(int, int);
extern int data_ov001_02165884;

// USA: func_ov001_02159b04
extern "C" ARM int func_ov001_02159b04(void* obj, void* arg) {
    return func_ov001_02164624(data_ov001_02165884, *(int*)((char*)arg + 0x70)) == 0;
}
