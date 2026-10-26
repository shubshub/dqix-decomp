#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0209cb74;
extern "C" void func_0209ccec(struct Struct_0209cb74*, int);
extern int data_02109be0;

// USA: func_0209cb74
extern "C" ARM int func_0209cb74(struct Variant02030b0c* p) {
    func_0209ccec((struct Struct_0209cb74*)&data_02109be0, ((Script::Parameter*)p)->ToInt());
    return 1;
}
