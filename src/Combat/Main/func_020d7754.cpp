#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Struct_0214e33c {
    short unknown_0_;
    short unknown_2_;
    short* unknown_4_;
    void* unknown_8_;
    void** unknown_c_;
};
extern struct Struct_0214e33c data_0214e33c;

struct Struct_020d7754 { short unknown_0_; short unknown_2_; char* unknown_4_; };

int STD_GetStringLength(const char* text);
void AppendListNode020d78e0(void** headSlot, void* srcData);
extern char data_020f2330[];

// USA: func_020d7754
extern "C" ARM int func_020d7754(Script::Parameter* arg0) {
    Struct_020d7754 var0;
    var0.unknown_4_ = NULL;
    var0.unknown_0_ = arg0[0].ToInt();
    var0.unknown_2_ = arg0[1].ToInt();
    int var1 = 1;
    if (data_0214e33c.unknown_4_ != NULL && data_0214e33c.unknown_0_ != 0) {
        var1 = 0;
        for (unsigned short var2 = 0; var2 < data_0214e33c.unknown_0_; var2++) {
            if (var0.unknown_0_ == data_0214e33c.unknown_4_[var2]) var1 = 1;
        }
    }
    if (!allowed) return 1;
    const char* text = params[2].ToString();
    int length = STD_GetStringLength(text);
    entry.c = (char*)((SafeAllocator*)data_0214e33c.field8)->Allocate(length + 1);
    if (entry.c == NULL) return 0;
    entry.c[length] = 0;
    sprintf(entry.c, data_020f2330, text);
    AppendListNode020d78e0(data_0214e33c.fieldC, (void*)&entry);
    return 1;
}
