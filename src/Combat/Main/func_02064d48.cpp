#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_02064d48_2112 = 0x860, Enum_02064d48_20 = 0x20 };
#else
enum { Enum_02064d48_2112 = 0x840, Enum_02064d48_20 = 0x14 };
#endif

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_020981e4(int a, int id);
extern "C" int func_02098268(int a, int x);

extern "C" void* Zone3D_GetInstance(void);

extern int data_02108ce0;

struct Struct_02064d48 {
    short id;
    unsigned char field2;
    unsigned char unknown_3_;
#if defined(jpn)
    char unknown_4_[12];
#endif
    char name[12];
    struct Struct_02064d48* next;
};

// USA: func_02064d48
extern "C" ARM int func_02064d48(const Script::Parameter* obj) {
    const Script::Parameter* parameters = obj;
    int b = parameters[0].ToInt();
    char* g = (char*)Zone3D_GetInstance();

    if (func_020981e4((int)(g + Enum_02064d48_2112), *(unsigned short*)g)) {
        if (func_02098268((int)(g + Enum_02064d48_2112), b)) {
            return 1;
        }
    }

    if (func_0206db20(*(void**)((char*)&data_02108ce0 + 4), b) == NULL) {
        return 1;
    }

    Struct_02064d48* node = (Struct_02064d48*)(*(SafeAllocator**)((char*)&data_02108ce0 + 0))->Allocate(Enum_02064d48_20);
    if (node == NULL) {
        return 0;
    }

    node->id = (short)b;
    node->field2 = (unsigned char)parameters[1].ToInt();

#if defined(jpn)
    const char* var4 = parameters[2].ToString();
    if (var4 != NULL) {
        strcpy(node->unknown_4_, var4);
    }
#else
    parameters[2].ToString();
#endif
    const char* name = parameters[3].ToString();
    if (name != NULL) {
        strcpy(node->name, name);
    }

    node->unknown_3_ = (unsigned char)parameters[4].ToInt();

    Struct_02064d48** var6 = *(Struct_02064d48***)((char*)&data_02108ce0 + 8);
    node->next = *var6;
    *var6 = node;
    return 1;
}
