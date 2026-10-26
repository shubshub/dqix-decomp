#include <globaldefs.h>

struct Struct_020db264;
extern "C" int func_020db9a8(struct Struct_020db264* obj);

extern "C" void* OamManager_GetInstance(void* obj);
extern "C" void OamManager_SetUploadEnabled(char*, int, int);

// USA: func_020db360
extern "C" ARM void func_020db360(struct Struct_020db264* obj, int b) {
    void* obj2 = OamManager_GetInstance(obj);
    int swapBit = func_020db9a8(obj);
    OamManager_SetUploadEnabled((char*)obj2, swapBit & 0xff, b);
    OamManager_SetUploadEnabled((char*)obj2, (swapBit ^ 1) & 0xff, 1);
}
