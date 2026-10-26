#include <globaldefs.h>

#include "Resource/Script.h"

struct StreamHeader;
extern "C" int data_02108da8;
extern Script::OpcodeLookupEntry data_020f0ca0[];

// USA: func_0207249c
extern "C" ARM int func_0207249c(int arg0, int arg1, StreamHeader* arg2, int arg3) {
    *((int*)((char*)&data_02108da8 + 4)) = arg0;
    *((int*)((char*)&data_02108da8 + 0)) = arg1;
    Script s;
    s.Initialize();
    s.SetOpcodeLookup(data_020f0ca0);
    s.Load(arg2, arg3);
    s.Execute();
}
