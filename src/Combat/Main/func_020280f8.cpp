#include <globaldefs.h>

struct InitStruct;
extern "C" void NodeGraph_Reset(struct InitStruct* s);

// USA: func_020280f8
extern "C" ARM void func_020280f8(struct InitStruct* s) {
    NodeGraph_Reset(s);
}
