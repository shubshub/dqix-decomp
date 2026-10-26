#include <globaldefs.h>

struct Struct_ov031_02211b28;
struct Struct_ov031_0224e5ac {
    void* field0;
    void* field4;
};

extern Struct_ov031_0224e5ac data_ov031_0224e5ac;
extern "C" void* func_ov031_02211b28(Struct_ov031_02211b28*, int);
typedef Struct_ov031_02211b28* (*Type_ov031_02211b64)(void*, int, int);

// USA: func_ov031_02211b64
extern "C" ARM void* func_ov031_02211b64(void* tag, void* size, int alignment) {
    Type_ov031_02211b64 var0 = (Type_ov031_02211b64)data_ov031_0224e5ac.field4;
    Struct_ov031_02211b28* header = var0(tag, (int)size + 0x20, alignment);
    if (header == NULL) return NULL;
    return func_ov031_02211b28(header, (int)size);
}
