#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021913d0(void* obj, unsigned short v);
extern "C" void func_ov017_02191484(void* obj);

struct Src021ce458 { unsigned char pad[4]; unsigned short field4; unsigned short field6; };

// USA: func_ov017_021ce458
ARM void CallHandlerIfFieldMatch_021ce458(int unused0, Src021ce458* src, int unused2, void* obj) {
    void* g = Zone3D_GetInstance();
    if (src->field6 == *(unsigned short*)g) {
        func_ov017_021913d0(obj, src->field4);
        return;
    }
    func_ov017_02191484(obj);
}
