#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { Enum_ov003_0217d9d8_2478 = 0x7de };
enum { Enum_ov003_0217d9d8_2464 = 0x870 };
#else
enum { kRegionValue998_868 = 0x998 };
enum { Enum_ov003_0217d9d8_2478 = 0x9ae };
enum { Enum_ov003_0217d9d8_2464 = 0x9a0 };
#endif


extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov003_0217dd10(char* obj, int key);
extern "C" void MessageSystem_Reset(char* obj);

struct Struct_ov003_0217d9d8 {
    char pad0[4];
    signed char field4;
    signed char field5;
};

// USA: func_ov003_0217d9d8
extern "C" ARM void func_ov003_0217d9d8(struct Struct_ov003_0217d9d8* obj) {
    char* g = (char*)MessageSystem_GetInstance();
    signed char b1 = obj->field5;

    if (b1 == 0) {
        func_ov003_0217dd10((char*)obj, 0x1869f);
        *(int*)(g + kRegionValue998_868) = 1;
        obj->field5 = 1;
        return;
    }

    if (b1 != 1) return;

    *(unsigned char*)(g + 0x1000 + Enum_ov003_0217d9d8_2478) = 0;
    if (*(int*)(g + Enum_ov003_0217d9d8_2464) != 0) return;

    MessageSystem_Reset(g);
    obj->field4 = 4;
    obj->field5 = 0;
}
