#include <globaldefs.h>

struct Struct_020bbc68_2;
struct Struct_020bbc78;
struct Struct_020bbc38 { char pad[0xc]; int size; };

extern "C" Struct_020bbc38* func_020bbc68(Struct_020bbc68_2* list);
extern "C" int func_020bbc78(Struct_020bbc78* arg0);
extern "C" int func_020bbc38(Struct_020bbc38* arg0);

extern char data_0210cf94[];

// USA: func_020bbcb4
extern "C" ARM void func_020bbcb4(void) {
    char* q = data_0210cf94;
    Struct_020bbc38* var1 = func_020bbc68((Struct_020bbc68_2*)q);
    if (!func_020bbc78((Struct_020bbc78*)q)) return;
    do {
        func_020bbc38(var1);
        *(int*)(q + 0x10) -= var1->size;
        var1 = func_020bbc68((Struct_020bbc68_2*)q);
    } while (func_020bbc78((Struct_020bbc78*)q));
}
