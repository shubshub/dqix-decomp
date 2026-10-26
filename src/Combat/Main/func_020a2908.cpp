#include <globaldefs.h>

struct Struct_020a2908;
extern "C" ARM struct Struct_020a2908* func_020a2928(struct Struct_020a2908* dst, struct Struct_020a2908* src);

// USA: func_020a2908
extern "C" ARM void func_020a2908(unsigned char* obj, struct Struct_020a2908* src) {
    func_020a2928((struct Struct_020a2908*)(obj + 0x298), src);
    obj[0x245] |= 4;
}
