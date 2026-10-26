#include <globaldefs.h>
#if defined(jpn)
#define HANDLER_BYTES 0xa0
#define data_021142c4 data_02113f64
#define data_020f22d0 data_020f243c
#else
#define HANDLER_BYTES 0xb4
#endif
#include "std_library_functions.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_020d3c28 {
    unsigned char entries[HANDLER_BYTES];
    int count;
};
extern struct Struct_020d3c28* data_021142c4;
extern int data_020f22d0;

// USA: func_020d3c84
extern "C" ARM void func_020d3c84(struct Struct_020d3c28* arr, struct StreamHeader* buffer, int length) {
    char local[0x430];
    memset(arr, 0, HANDLER_BYTES);
    arr->count = 0;
    data_021142c4 = arr;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f22d0);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
