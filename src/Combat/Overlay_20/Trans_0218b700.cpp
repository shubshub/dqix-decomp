#include <globaldefs.h>

unsigned int InitControllerObject_02043000(char* obj);
char* MessageSystem_GetInstance();

// USA: func_ov020_0218b700  (semantic: Trans_0218b700)
extern "C" ARM void func_ov020_0218b700() {
    InitControllerObject_02043000(MessageSystem_GetInstance());
}
