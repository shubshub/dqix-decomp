#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02159c04_2464 = 0x870 };
enum { Enum_ov003_02159c04_2478 = 0x7de };
#else
enum { Enum_ov003_02159c04_2464 = 0x9a0 };
enum { Enum_ov003_02159c04_2478 = 0x9ae };
#endif

extern "C" void* MessageSystem_GetInstance(void);
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);

struct Struct_0205dee8;
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

extern "C" int func_ov003_0215b7a4(void* p);

// USA: func_ov003_02159c04
extern "C" ARM void func_ov003_02159c04(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();

    if (*(int*)(g + Enum_ov003_02159c04_2464) == 3) {
        *(unsigned char*)(g + 0x1000 + Enum_ov003_02159c04_2478) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 0);
        func_0205dee8((struct Struct_0205dee8*)(s + 0xf4), 1);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 1) return;

    int r = func_ov003_0215b7a4(self);
    switch (r) {
    case -1:
        return;
    case 0:
        *(unsigned char*)(s + 0x588) = 3;
        break;
    case 1:
        *(unsigned char*)(s + 0x588) = 4;
        break;
    case 2:
        *(unsigned char*)(s + 0x588) = 5;
        break;
    case 3:
        *(unsigned char*)(s + 0x588) = 6;
        break;
    case 4:
        *(unsigned char*)(s + 0x588) = 7;
        break;
    case -2:
    case 5:
        *(unsigned char*)(s + 0x588) = 8;
        break;
    default:
        break;
    }
    *(unsigned char*)(s + 0x580) = 0;
}
