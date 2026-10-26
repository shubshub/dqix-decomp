#include <globaldefs.h>

struct Struct_0206ea7c_2 {
    unsigned int v[7];
};

struct Get28ByteElementAt0x334Struct {
    char pad[0x334];
    struct Struct_0206ea7c_2 arr[1];
};

// USA: func_0206ea7c
extern "C" ARM struct Struct_0206ea7c_2* func_0206ea7c(struct Get28ByteElementAt0x334Struct* s, int i) {
    return &s->arr[i];
}
