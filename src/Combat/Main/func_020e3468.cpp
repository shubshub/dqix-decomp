#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_0208ab34_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
extern "C" Struct_0208ab34_2* func_020e3054(Struct_0208ab34_2* list, int key);

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);

struct Struct_020e3004_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
extern "C" void func_020e303c(Struct_020e3004_2* s);

// USA: func_020e3468
extern "C" ARM void func_020e3468(Struct_0208ab34_2* list, int key) {
    void* searchObj = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)searchObj)) return;
    Struct_0208ab34_2* entry = func_020e3054(list, key);
    if (entry == NULL) return;
    signed char cur = LinkSession_GetOwnSlot((SearchStruct0202c1a4*)searchObj);
    if (entry->f0 != cur) return;
    func_020e303c((Struct_020e3004_2*)entry);
}
