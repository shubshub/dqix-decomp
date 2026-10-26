#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c { int field0; void* field4; };

struct Struct_0201c470 { unsigned char v[31]; };
struct Struct_0201c3a4_2 { struct Struct_0201c470 name; unsigned char flag; };
struct Struct_0201c470_2 { struct Struct_0201c3a4_2* base; int cap; int count; };
extern "C" void func_0201c470(struct Struct_0201c470_2* obj, struct Struct_0201c3a4_2* src);

struct Struct_020fdc14_3 {
    char pad[8];
    struct Struct_0201c470_2* obj;
};
extern struct Struct_020fdc14_3 data_020fdc14;

// USA: func_0201c3a4
extern "C" ARM int func_0201c3a4(struct Struct02030b7c* arg) {
    struct Struct_0201c3a4_2 buf;
    void* name = (void*)((Script::Parameter*)arg)->ToString();
    memset(&buf, 0, 0x1f);
    strcpy((char*)&buf, (char*)name);
    func_0201c470(data_020fdc14.obj, &buf);
    return 1;
}
