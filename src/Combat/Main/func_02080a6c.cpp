#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f524;
extern "C" void* func_0207f0ac(struct Struct_0207f0ac* list, int id);
extern "C" void* func_0207f6ac(struct Struct_0207f524* list, int id);

struct Struct_02080a6c {
    short* arr;
    char pad1[0xa - 4];
    short fieldA;
    short fieldC;
    char pad2[0x13 - 0xe];
    unsigned char count;
};

struct Struct_02080a6c_2 {
    char pad[6];
    short unknown_6_;
    short f8;
    short fa;
    short fc;
};

// USA: func_02080a6c
extern "C" ARM void func_02080a6c(void* param0, int id, short param2, short* param3, short* param4, short* arg5, short* arg6) {
    struct Struct_02080a6c* result = (struct Struct_02080a6c*)func_0207f0ac((struct Struct_0207f0ac*)((char*)param0 + 0xc), id);
    if (!result) {
        return;
    }
    *param3 = (short)(result->fieldA << 3);
    *param4 = (short)(result->fieldC << 3);
    unsigned char i;
    for (i = 0; i < result->count; i++) {
        if (result->arr[i] == param2) {
            struct Struct_02080a6c_2* var2 = (struct Struct_02080a6c_2*)func_0207f6ac((struct Struct_0207f524*)((char*)param0 + 4), param2);
            if (!var2) {
                return;
            }
            *param3 = *param3 + var2->unknown_6_;
            *param4 = *param4 + var2->f8;
            *arg5 = var2->fa;
            *arg6 = var2->fc;
            return;
        }
    }
}
