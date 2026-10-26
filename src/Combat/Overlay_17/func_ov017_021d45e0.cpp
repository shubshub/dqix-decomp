#include <globaldefs.h>

struct Struct_ov017_021c8f3c_3 { unsigned short a; short b; unsigned short c; unsigned short d; unsigned short e; unsigned char f; };
extern "C" void func_ov017_021c90f8(Struct_ov017_021c8f3c_3* dst, Struct_ov017_021c8f3c_3* src);

struct Struct_ov017_021d45e0 {
    unsigned char flags;
    unsigned char pad1;
    unsigned short id;
    unsigned char pad2[14];
    Struct_ov017_021c8f3c_3 data;
};

extern "C" ARM void func_ov017_021d46a4(Struct_ov017_021d45e0* arr, Struct_ov017_021d45e0* slot);

// USA: func_ov017_021d45e0
extern "C" ARM void func_ov017_021d45e0(Struct_ov017_021d45e0* arr, Struct_ov017_021c8f3c_3* rec) {
    Struct_ov017_021d45e0* found = NULL;
    Struct_ov017_021d45e0* var1 = NULL;
    int i = 0;
    for (i = 0; i < 0x30; i++) {
        if (rec->a == arr[i].id) {
            found = &arr[i];
            break;
        }
        if (var1 == NULL && arr[i].flags == 0) {
            var1 = &arr[i];
        }
    }
    if (found != NULL) {
        func_ov017_021c90f8(&found->data, rec);
        found->id = rec->a;
        found->flags |= 0x2;
        func_ov017_021d46a4(arr, found);
        return;
    }
    if (var1 == NULL) {
        return;
    }
    func_ov017_021c90f8(&var1->data, rec);
    var1->id = rec->a;
    var1->flags |= 0x2;
    func_ov017_021d46a4(arr, var1);
}
