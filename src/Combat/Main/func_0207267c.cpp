#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Elem02072a28 { short a; int b; };
struct List02072a28;
void AppendShortWordPair02072a28(List02072a28* list, Elem02072a28* src);
int STD_GetStringLength(const char* text);
struct ScriptStringState0207267c {
    unsigned char skipCount;
    unsigned char padding;
    unsigned short filterCount;
    char* destination;
    short* filterIds;
    SafeAllocator* allocator;
    List02072a28* list;
};
extern Struct_02108db0_2 data_02108db0;
extern char data_020f0cf0[];

// USA: func_0207267c
extern "C" ARM int func_0207267c(Script::Parameter* arg0) {
    Struct_0207267c var0;
    var0.unknown_4_ = 0;
    var0.unknown_0_ = (arg0++)->ToInt();
    int var1 = 1;
    if (data_02108db0.unknown_8_ != NULL && data_02108db0.unknown_2_ != 0) {
        var1 = 0;
        for (unsigned short var2 = 0; var2 < data_02108db0.unknown_2_; var2++) {
            if (var0.unknown_0_ == data_02108db0.unknown_8_[var2]) var1 = 1;
        }
    }
    if (!var1) return 1;
    for (unsigned char var3 = 0; var3 < data_02108db0.unknown_0_; var3++) {
        (arg0++)->ToString();
    }
    int var4;
    const char* var5 = arg0->ToString();
    if (data_02108db0.unknown_4_ != NULL) {
        if (var5 != NULL) strcpy(data_02108db0.unknown_4_, var5);
        return 1;
    }
    length = 0;
    if (text != NULL) length = STD_GetStringLength(text);
    entry.b = (int)data_02108db0.allocator->Allocate(length + 1);
    if (entry.b == 0) return 0;
    ((char*)entry.b)[length] = 0;
    if (entry.b != 0) sprintf((char*)entry.b, data_020f0cf0, text);
    AppendShortWordPair02072a28(data_02108db0.list, &entry);
    return 1;
}
