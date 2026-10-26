#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_02158d8c {
    char pad[0x1c];
    struct Struct_ov006_02158d8c* next;
};

// USA: func_ov006_02158d8c
extern "C" ARM struct Struct_ov006_02158d8c* func_ov006_02158d8c(void* objRaw, short arg1) {
    char* obj = (char*)objRaw;
    struct Struct_ov006_02158d8c* n = *(struct Struct_ov006_02158d8c**)(obj + R(0x28, 0x30));
    short i = 0;
    while (n != NULL && arg1 != 0) {
        if (n->next == NULL) {
            obj = obj + 0x300;
            *(short*)(obj + 0x6a) = i + 0x29;
            break;
        }
        arg1--;
        i++;
        n = n->next;
    }
    return n;
}
