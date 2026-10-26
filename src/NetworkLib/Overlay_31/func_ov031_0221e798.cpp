#include <globaldefs.h>


struct Struct_ov031_0221e798 {
    int value;
    int rest;
};

extern "C" THUMB void func_ov031_0221e6e8(int a, int* b);

// USA: func_ov031_0221e798
extern "C" THUMB void func_ov031_0221e798(Struct_ov031_0221e798* node, int a, int value) {
    node->value = value;
    func_ov031_0221e6e8(a, &node->rest);
}
