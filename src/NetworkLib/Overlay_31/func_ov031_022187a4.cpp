#include <globaldefs.h>

struct Struct_ov031_022187a4 {
    char* unknown_0_;
    char* current;
    char* end;
    int size;
};

typedef char* (*Type_ov031_022187a4)(const char*, int);
extern char data_ov031_02249eec[];

// USA: func_ov031_022187a4
extern "C" ARM int func_ov031_022187a4(char* obj, void* out, int length) {
    Type_ov031_022187a4 var0 = *(Type_ov031_022187a4*)(obj + 0x1010);
    Struct_ov031_022187a4* buffer = (Struct_ov031_022187a4*)out;
    if (length == 0) return 0;
    buffer->unknown_0_ = var0(data_ov031_02249eec, length);
    if (buffer->unknown_0_ == NULL) return 0;
    buffer->current = buffer->unknown_0_;
    buffer->size = length;
    buffer->end = buffer->unknown_0_ + buffer->size;
    return 1;
}
