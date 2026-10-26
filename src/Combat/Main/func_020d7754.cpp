#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Struct_0214e33c {
    short field0;
    short pad2;
    short* field4;
    void* field8;
    void** fieldC;
};
extern struct Struct_0214e33c data_0214e33c;

struct Struct_020d7754 { short a; short b; char* c; };

extern "C" int STD_GetStringLength(const char* text);
extern "C" void func_020d78e0(void** arg0, void* arg1);
extern char data_020f2330[];

// USA: func_020d7754
extern "C" ARM int func_020d7754(Script::Parameter* params) {
    Struct_020d7754 entry;
    entry.c = NULL;
    entry.a = params[0].ToInt();
    entry.b = params[1].ToInt();
    int var1 = 1;
    if (data_0214e33c.field4 != NULL && data_0214e33c.field0 != 0) {
        var1 = 0;
        for (unsigned short i = 0; i < data_0214e33c.field0; i++) {
            if (entry.a == data_0214e33c.field4[i]) var1 = 1;
        }
    }
    if (!var1) return 1;
    const char* text = params[2].ToString();
    int length = STD_GetStringLength(text);
    entry.c = (char*)((SafeAllocator*)data_0214e33c.field8)->Allocate(length + 1);
    if (entry.c == NULL) return 0;
    entry.c[length] = 0;
    sprintf(entry.c, data_020f2330, text);
    func_020d78e0(data_0214e33c.fieldC, (void*)&entry);
    return 1;
}
