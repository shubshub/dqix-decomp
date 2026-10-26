#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov011_021849d8(void* p);
extern "C" void func_ov011_021849d0(void* p, int v);

// USA: func_ov011_021855cc
extern "C" ARM int func_ov011_021855cc(void) {
    void* obj = func_ov017_021b2164();
    int val = func_ov011_021849d8(obj);
    int f = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)(f))->RemoveTask((int)(val));
    func_ov011_021849d0(obj, -1);
    return 1;
}
