#include <globaldefs.h>

#include "Resource/Script.h"

struct StreamHeader;
extern "C" int data_02108ce0;
extern Script::OpcodeLookupEntry data_020f05f8[];

// USA: func_02064e2c
extern "C" ARM int func_02064e2c(int arg0, int arg1, int arg2, StreamHeader* arg3, int arg4) {
    *((int*)((char*)&data_02108ce0 + 8)) = arg0;
    *((int*)((char*)&data_02108ce0 + 4)) = arg1;
    *((int*)((char*)&data_02108ce0 + 0)) = arg2;
    Script s;
    s.Initialize();
    s.SetOpcodeLookup(data_020f05f8);
    s.Load(arg3, arg4);
    s.Execute();
    return 1;
}
