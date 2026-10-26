#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

extern "C" void func_0204f138(unsigned char* base, unsigned char** a, unsigned char** b, unsigned char** c, unsigned char** d);

struct Struct_0205bd58;
extern "C" void func_0205bd58(struct Struct_0205bd58* s, int a, int b, int c, int d, int e);

struct Struct_0205d904 {
    char pad[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

// USA: func_0205d904
extern "C" ARM void func_0205d904(unsigned char* obj) {
    struct Elem_0205d81c* e;
    unsigned char* p1;
    unsigned char* p2;
    unsigned char* p3;
    unsigned char* p4;
    struct Struct_0205d904* e2;

    e = func_0205d81c((struct Struct_0205d81c*)obj, obj[0xb0]);
    if (e == NULL) return;

    func_0204f138((unsigned char*)e, &p1, &p2, &p3, &p4);
    func_0205bd58((struct Struct_0205bd58*)(obj + 4), 0x12, (int)p1, (int)p2, (int)p3, (int)p4);

    e2 = (struct Struct_0205d904*)e;
    {
        short a = e2->unknown_ac_;
        short b = e2->unknown_ae_;
        *(short*)(obj + 0x3c) = a << 3;
        *(short*)(obj + 0x3e) = b << 3;
    }
}
