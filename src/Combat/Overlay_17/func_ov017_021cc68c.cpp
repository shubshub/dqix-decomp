#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cc68c {
    unsigned char tag;
    unsigned char pad[3];
    unsigned char field4;
    unsigned char field5;
    unsigned char pad2[14];
};

// USA: func_ov017_021cc68c
extern "C" ARM void func_ov017_021cc68c(int a) {
    Struct_ov017_021cc68c buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 9;
    buf.field5 = (unsigned char)a;
    buf.field4 = 1;
    func_0205e330(p, &buf, 0);
}
