#include <globaldefs.h>

extern "C" void LinkSession_End(void* obj);

// USA: func_0202c7a8
ARM void* InitReturnSelf0202c7a8(void* obj) {
    LinkSession_End(obj);
    return obj;
}
