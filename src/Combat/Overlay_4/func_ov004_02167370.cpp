#include <globaldefs.h>

extern "C" int func_ov004_021666bc(void* a1, int* out);
#if defined(jpn)
struct Struct_ov004_0217101c { unsigned int reserved; char* value; };
extern Struct_ov004_0217101c data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern char* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Struct_ov004_02167370 {
    unsigned short sel : 2;
    unsigned short bit2 : 1;
    unsigned short unknown_0_3_ : 1;
    unsigned short unknown_0_4_ : 12;
};

// USA: func_ov004_02167370
extern "C" ARM int func_ov004_02167370(void* a1) {
    int local;
    int key = func_ov004_021666bc(a1, &local);

    void* node = *(void**)(CONTEXT_VALUE + 8);
    while (node != NULL) {
        if (*(short*)((char*)node + 0) == key) break;
        node = *(void**)((char*)node + 8);
    }

    if (node == NULL) goto end;

    {
        struct Struct_ov004_02167370* var3 = (struct Struct_ov004_02167370*)((char*)node + 2);
        int msg = 0;
        switch (var3->sel) {
        case 0:
        case 1:
            msg = 0x6a;
            break;
        case 2:
            msg = (var3->unknown_0_3_ == 1) ? 0x68 : 0x67;
            break;
        case 3:
            msg = 0x69;
            break;
        }

        if (msg != 0) {
            func_ov011_021848a0(a1, msg);
        }
    }
end:
    return 0;
}
