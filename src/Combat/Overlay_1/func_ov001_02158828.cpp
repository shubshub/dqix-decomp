#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_ov001_02164d10[];

struct Struct_ov001_02158828 {
    int f0;
    unsigned char arr1[0xc];
    unsigned char arr2[0xc];
    int f1c;
    int f20;
    int f24;
    char unknown_28_[0x20];
    void* unknown_48_;
};

// USA: func_ov001_02158828
extern "C" ARM void func_ov001_02158828(struct Struct_ov001_02158828* obj) {
    obj->f0 = 0;
    memset(obj->arr1, 0, 0xc);
    memset(obj->arr2, 0, 0xc);
    obj->f1c = 0;
    obj->f20 = 0;
    obj->f24 = 0;
    strcpy(obj->unknown_28_, data_ov001_02164d10);
    obj->unknown_48_ = NULL;
}
