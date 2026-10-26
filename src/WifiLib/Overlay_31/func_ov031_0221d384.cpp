#include <globaldefs.h>

extern "C" THUMB int func_ov031_0221ecb4(int arg);

extern int data_ov031_0224b070;

// USA: func_ov031_0221d384
extern "C" THUMB int func_ov031_0221d384(int id) {
    if (id == -1) {
        *(int*)((char*)&data_ov031_0224b070 + 4) = id;
        return 0;
    }
    if (*(int*)((char*)&data_ov031_0224b070 + 4) != id) {
        *(int*)((char*)&data_ov031_0224b070 + 4) = id;
        return func_ov031_0221ecb4(id);
    }
    return 0;
}
