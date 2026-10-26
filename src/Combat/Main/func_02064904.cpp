#include <globaldefs.h>

struct Struct_0205faf4_8;
struct Struct_0205faf4_7;
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7* t, int id);
extern "C" int* func_02094d6c(void);

// USA: func_02064904
extern "C" ARM void* func_02064904(void* arg0, int id, unsigned int arg2) {
    struct Struct_0205faf4_8* elem = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), id);
    void* result = NULL;
    if (elem != NULL && arg2 <= 9) {
        switch (arg2) {
            case 0: result = (char*)elem + 0xa; break;
            case 1: result = (char*)elem + 0xa; break;
            case 2: result = (char*)elem + 0xc; break;
            case 3: result = (char*)elem + 0xe; break;
            case 4: result = (char*)elem + 0x4; break;
            case 5: result = (char*)elem + 0x6; break;
            case 6: result = (char*)elem + 0x8; break;
            case 7: result = (char*)elem + 0xa; break;
            case 8: result = (char*)elem + 0xc; break;
            case 9: result = (char*)elem + 0xe; break;
        }
    }
    return result;
}
