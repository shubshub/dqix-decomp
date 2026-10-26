#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int val; };
extern "C" void func_0209bd40(char* obj, int value);

struct Struct_0209bb1c {
    char* buffer;
    unsigned char pad[0x10];
    int active;
    int unknown_18_;
};
extern struct Struct_0209bb1c* data_02109bb0;

// USA: func_0209bb1c
extern "C" ARM int func_0209bb1c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active == 0) return 1;
    int value = ((Script::Parameter*)variant)->ToInt();
    func_0209bd40(data_02109bb0->buffer, value);
    data_02109bb0->unknown_18_ = value;
    return 1;
}
