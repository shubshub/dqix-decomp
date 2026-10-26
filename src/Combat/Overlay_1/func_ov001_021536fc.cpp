#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_ov001_021536fc { int val; char* str; };
struct Struct_ov001_02165800_2 { int count; void* allocator; Struct_ov001_021536fc** entries; };
extern Struct_ov001_02165800_2 data_ov001_02165800;

// USA: func_ov001_021536fc
extern "C" ARM int func_ov001_021536fc(void* variant) {
    int val = ((Script::Parameter*)variant)->ToInt();
    Struct_ov001_021536fc* entries = *data_ov001_02165800.entries;
    entries[data_ov001_02165800.count].val = val;

    char* s = (char*)(void*)((Script::Parameter*)((char*)variant + 8))->ToString();
    if (!s) {
        return 0;
    }

    unsigned int len = strlen(s);
    void* buf = ((SafeAllocator*)data_ov001_02165800.allocator)->Allocate(len + 1);
    (*data_ov001_02165800.entries)[data_ov001_02165800.count].str = (char*)buf;
    if ((*data_ov001_02165800.entries)[data_ov001_02165800.count].str == 0) {
        return 0;
    }

    strcpy((*data_ov001_02165800.entries)[data_ov001_02165800.count].str, s);
    data_ov001_02165800.count += 1;
    return 1;
}
