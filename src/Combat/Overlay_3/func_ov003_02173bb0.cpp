#include <globaldefs.h>

struct Struct_ov003_02173b4c {
    unsigned char pad0[0x40];
    char* field40;
    unsigned char pad1[0xa];
    unsigned short unknown_4e_;
};

// USA: func_ov003_02173bb0
extern "C" ARM void* func_ov003_02173bb0(Struct_ov003_02173b4c* obj, unsigned int index) {
    char* base = obj->field40;
    char* result = NULL;
    if (base != NULL) {
        if (index < obj->unknown_4e_) {
            result = base + index * 0x28;
        }
    }
    return result;
}
