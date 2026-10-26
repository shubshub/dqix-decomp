#include <globaldefs.h>

extern "C" void func_ov017_021ac2a8(void* obj);

// USA: func_ov017_021ac294
extern "C" ARM void func_ov017_021ac294(unsigned char* obj) {
    obj[1] = 1;
    func_ov017_021ac2a8(obj);
}
