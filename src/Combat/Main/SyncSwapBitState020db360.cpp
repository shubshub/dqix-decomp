#include <globaldefs.h>

struct Struct020db9a8;
int GetSwapBitIfFlag54Clear(struct Struct020db9a8* obj);

extern "C" void* OamManager_GetInstance(void* obj);
void OamManager_SetUploadEnabled(char*, int, int);

// USA: func_020db360
ARM void SyncSwapBitState020db360(struct Struct020db9a8* obj, int b) {
    void* obj2 = OamManager_GetInstance(obj);
    int swapBit = GetSwapBitIfFlag54Clear(obj);
    OamManager_SetUploadEnabled((char*)obj2, swapBit & 0xff, b);
    OamManager_SetUploadEnabled((char*)obj2, (swapBit ^ 1) & 0xff, 1);
}
