#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Struct_02073ec4_2;
struct Struct_0209ba70 { unsigned short a; short b; };
extern "C" void func_0209be44(struct Struct_02073ec4_2* table, int key, struct Struct_0209ba70* src);

struct Struct_0209ba2c {
    struct Struct_02073ec4_2* table;
    unsigned char pad[0x10];
    int active;
    int key;
};
extern struct Struct_0209ba2c* data_02109bb0;

struct Struct_0209ba70_2 {
    struct Variant02030b0c primary;
    struct Variant02030b0c unknown_8_;
};

// USA: func_0209ba70
extern "C" ARM int func_0209ba70(struct Struct_0209ba70_2* v) {
    struct Struct_0209ba70 sub;
    if (data_02109bb0->active == 0) {
        return 1;
    }
    *(int*)&sub = ((Script::Parameter*)&v->primary)->ToInt();
    if (v->unknown_8_.tag == 2) {
        sub.b = (short)(int)(((Script::Parameter*)((struct Struct_0201d530*)&v->unknown_8_))->ToFloat() * 4096.0f);
    } else if (v->unknown_8_.tag == 1) {
        sub.b = (short)(((Script::Parameter*)&v->unknown_8_)->ToInt() << 12);
    }
    if (sub.b == 0) {
        sub.b = 0x1000;
    }
    func_0209be44(data_02109bb0->table, data_02109bb0->key, &sub);
    return 1;
}
