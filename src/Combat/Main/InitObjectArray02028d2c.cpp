#include <globaldefs.h>
void ZoneRecord_Destroy(void*);

extern "C" void ZoneRecords_Reset(void* obj);
extern "C" void func_0200ef44(void* obj, int count, int size, void* initFn);

// USA: func_02028d2c
ARM void* InitObjectArray02028d2c(void* obj) {
    ZoneRecords_Reset(obj);
#if defined(jpn)
    func_0200ef44(obj, 4, 0x314, (void*)ZoneRecord_Destroy);
#else
    func_0200ef44(obj, 4, 0x318, (void*)ZoneRecord_Destroy);
#endif
    return obj;
}
