#include <globaldefs.h>

struct InitStruct;
void NodeGraph_Reset(struct InitStruct* s);

// USA: func_020280f8
ARM void InitializeStruct020280f8(struct InitStruct* s) {
    NodeGraph_Reset(s);
}
