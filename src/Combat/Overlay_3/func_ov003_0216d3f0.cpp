#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216d3f0_2456 = 0x868 };
enum { Enum_ov003_0216d3f0_2464 = 0x870 };
#else
enum { Enum_ov003_0216d3f0_2456 = 0x998 };
enum { Enum_ov003_0216d3f0_2464 = 0x9a0 };
#endif

#if defined(jpn)
extern "C" void func_ov003_0216d8d4(char*, int);
#endif

extern "C" int MessageSystem_GetInstance();
#if !defined(jpn)
extern "C" void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5);
#endif
extern "C" void MessageSystem_Reset(char* obj);

// USA: func_ov003_0216d3f0
extern "C" ARM void func_ov003_0216d3f0(char* obj) {
    char* g = (char*)MessageSystem_GetInstance();
    short state = *(short*)(obj + 6);
    if (state == 0) {
#if defined(jpn)
        func_ov003_0216d8d4(obj, 0x1c);
#else
        func_ov003_0216d8d4(obj, 0x1c, -1, -1, -1);
#endif
        *(int*)(g + Enum_ov003_0216d3f0_2456) = 1;
        *(short*)(obj + 6) = 1;
        return;
    }
    switch (state) {
    case 1:
        if (*(int*)(g + Enum_ov003_0216d3f0_2464) != 0) break;
        if (*(int*)(g + Enum_ov003_0216d3f0_2456) != 0) break;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        break;
    }
}
