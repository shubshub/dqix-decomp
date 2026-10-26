#include <globaldefs.h>

extern "C" void func_02067e98(unsigned char* obj, int b);
extern "C" void func_02044d0c(unsigned char* p);

struct Struct_0204394c;
extern "C" void func_0204394c(struct Struct_0204394c* obj);

#if defined(jpn)
struct Struct_02044f3c {
    unsigned char b0 : 1;
};

extern "C" void func_02069878(unsigned char* obj, int b);
extern "C" void func_02044104(struct Struct_0204394c* obj);

extern "C" ARM void func_02044f3c(unsigned char* obj, int b, int arg2) {
    (obj + 0x1000)[0x7ed] = 1;
    func_02069878(obj, b);
    if ((obj + 0x1000)[0x7fd] == 0 && arg2 == 1) {
        (obj + 0x1000)[0x7de] = 0;
        (obj + 0x1000)[0x7df] = 0;
        (obj + 0x1000)[0x7fe] = 1;
        *(int*)(obj + 0xc) = 0;
        func_02044d0c(obj + 0x1000);
    }
    (obj + 0x1000)[0x7fd] = 0;
    ((Struct_02044f3c*)(obj + 0x1000 + 0x7ff))->b0 = 0;
    if (arg2 == 1) {
        (obj + 0x1000)[0x7fd] = 1;
    } else if (arg2 == 1) {
        ((Struct_02044f3c*)(obj + 0x1000 + 0x7ff))->b0 = 1;
    }
    if ((obj + 0x1000)[0x7fd] != 0) {
        (obj + 0x1000)[0x7fd] = 1;
        (obj + 0x1000)[0x7de] = 0;
        (obj + 0x1000)[0x7df] = 0;
        (obj + 0x1000)[0x7fe] = 1;
        *(int*)(obj + 0xc) = 0;
    }
    if (((Struct_02044f3c*)(obj + 0x1000 + 0x7ff))->b0) {
        *(int*)(obj + 0x10) = 0;
        func_02044104(*(struct Struct_0204394c**)(obj + 0x1000 + 0xc4c));
    }
}
#else
// USA: func_02044f3c
extern "C" ARM void func_02044f3c(unsigned char* obj, int b, int arg2) {
    (obj + 0x1000)[0x9bd] = 1;
    func_02067e98(obj, b);
    if ((obj + 0x1000)[0x9cc] == 0 && arg2 == 1) {
        (obj + 0x1000)[0x9ae] = 0;
        (obj + 0x1000)[0x9af] = 0;
        (obj + 0x1000)[0x9cd] = 1;
        *(int*)(obj + 0x40) = 0;
        func_02044d0c(obj + 0x1000);
    }
    (obj + 0x1000)[0x9cc] = 0;
    (obj + 0x1000)[0x9ce] = 0;
    if (arg2 == 1) {
        (obj + 0x1000)[0x9cc] = 1;
    } else if (arg2 == 1) {
        (obj + 0x1000)[0x9ce] = 1;
    }
    if ((obj + 0x1000)[0x9cc] != 0) {
        (obj + 0x1000)[0x9cc] = 1;
        (obj + 0x1000)[0x9ae] = 0;
        (obj + 0x1000)[0x9af] = 0;
        (obj + 0x1000)[0x9cd] = 1;
        *(int*)(obj + 0x40) = 0;
    }
    if ((obj + 0x1000)[0x9ce] != 0) {
        *(int*)(obj + 0x44) = 0;
        func_0204394c(*(struct Struct_0204394c**)(obj + 0x1000 + 0xe28));
    }
    ((char*)obj)[0x30] = -1;
    ((char*)obj)[0x31] = -1;
}
#endif
