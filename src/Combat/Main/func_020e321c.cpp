#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct CheckField0AndGlobalHalfStruct0202c508 { int field0; };
extern "C" int LinkSession_IsHostOrSolo(CheckField0AndGlobalHalfStruct0202c508* obj);

struct Struct_0208ab34_2 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
struct Struct_020e30a4 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
extern "C" Struct_0208ab34_2* func_020e3054(Struct_0208ab34_2* list, int key);
extern "C" Struct_020e30a4* func_020e30a4(Struct_020e30a4* list);

struct Struct_020e3004_2 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
extern "C" void func_020e303c(Struct_020e3004_2* s);

extern "C" void func_ov017_021ceae4(unsigned char a, unsigned char b, unsigned char c);

// USA: func_020e321c
extern "C" ARM void func_020e321c(Struct_0208ab34_2* a, int b, unsigned char c) {
    int* g = (int*)LinkSession_GetInstance();
    if (!LinkSession_IsActive(g)) return;

    if (LinkSession_IsHostOrSolo((CheckField0AndGlobalHalfStruct0202c508*)g)) {
        unsigned char tag = 0;
        Struct_0208ab34_2* e = func_020e3054(a, b);
        if (e && e->f2 == 1 && e->f0 == c) return;

        if (!e || e->f2 == 0) {
            if (!e) {
                e = (Struct_0208ab34_2*)func_020e30a4((Struct_020e30a4*)a);
            }
            if (e) {
                func_020e303c((Struct_020e3004_2*)e);
                e->f1 = (unsigned char)b;
                tag = 1;
                e->f2 = tag;
                e->f0 = c;
            }
        }

        if (c == 0) return;
        func_ov017_021ceae4(tag, b, c);
    } else {
        func_ov017_021ceae4(1, b, c);
        Struct_0208ab34_2* e = func_020e3054(a, b);
        if (!e) {
            e = (Struct_0208ab34_2*)func_020e30a4((Struct_020e30a4*)a);
        }
        func_020e303c((Struct_020e3004_2*)e);
        e->f1 = (unsigned char)b;
        e->f2 = 2;
        e->f0 = c;
    }
}
