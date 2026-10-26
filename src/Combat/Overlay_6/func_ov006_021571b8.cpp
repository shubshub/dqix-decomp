// KEEP-NAME
// USA: func_ov006_021571b8
#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

extern "C" void func_ov023_021dced4(void*, unsigned char);

extern "C" ARM void func_ov006_021571b8(void* object, unsigned char value) {
    Struct_ov006_02154614* var0 = (Struct_ov006_02154614*)object;
    func_ov023_021dced4(&var0->window_, value);
}
