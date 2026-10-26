#include <globaldefs.h>

struct Obj02176150 { char pad[0xe]; short val; };

extern "C" void func_ov000_0217616c(struct Obj02176150*);

// USA: func_ov000_02176150
extern "C" ARM void func_ov000_02176150(struct Obj02176150* obj, short val) {
    if (val == obj->val) return;
    obj->val = val;
    func_ov000_0217616c(obj);
}
