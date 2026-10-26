#include <globaldefs.h>
#include "Resource/QuestScriptOwner.h"
#include "Resource/Script.h"

unsigned char data_02109406;
unsigned char data_02109404;
unsigned char data_02109405;
unsigned char data_02109408;
unsigned char data_02109407;
unsigned short data_0210940c;
unsigned short data_0210940a;
SafeAllocator* data_02109410;
unsigned char* data_02109414;

extern short data_020f13d8;
extern Script::OpcodeLookupEntry data_020f1444[];

// USA: func_0209576c
extern "C" ARM void func_0209576c(Struct_020956b8* header, SafeAllocator* allocator,
                                 const void* data, unsigned int length, unsigned char mode) {
    if (allocator != NULL && data != NULL && length != 0) {
        data_02109410 = allocator;
        header->unknown_a4_ = NULL;
        data_02109404 = mode;
        data_02109406 = 0;
        data_020f13d8 = -1;
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1444);
        script.Load(data, length);
        script.Execute();
    }
}
