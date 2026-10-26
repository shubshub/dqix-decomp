#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_ov015_0218b6bc;
extern "C" void func_ov015_0218b9ac(Struct_ov015_0218b6bc* obj, int n);

extern Struct_ov015_0218b6bc* data_ov015_02194560;

// USA: func_ov015_0218b6bc
extern "C" ARM int func_ov015_0218b6bc(Script::Parameter* params, int count) {
    Struct_ov015_0218b6bc* list = data_ov015_02194560;
    func_ov015_0218b9ac(list, params->ToInt());
    return 1;
}
