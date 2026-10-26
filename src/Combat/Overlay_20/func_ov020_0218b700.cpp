#include <globaldefs.h>

extern "C" unsigned int func_02043000(char* obj);
extern "C" char* MessageSystem_GetInstance();

// USA: func_ov020_0218b700
extern "C" ARM void func_ov020_0218b700() {
    func_02043000(MessageSystem_GetInstance());
}
