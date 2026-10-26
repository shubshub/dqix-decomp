#include <globaldefs.h>

extern "C" void NSBXX_Model_SetPolygonID(void* obj, unsigned int value);

// USA: func_ov017_021923e0
extern "C" ARM void func_ov017_021923e0(void* obj, unsigned int value) {
    void* q = *(void**)((char*)obj + 0x8);
    if (q == NULL) {
        return;
    }
    void* p = *(void**)((char*)q + 0x54);
    if (p == NULL) {
        return;
    }
    NSBXX_Model_SetPolygonID(p, value);
}
