#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int val; };

struct Struct_02073ec4_2;
extern "C" void func_0209be28(struct Struct_02073ec4_2* table, int key, int* value);

struct Struct_0209ba2c {
    struct Struct_02073ec4_2* table;
    unsigned char pad[0x10];
    int active;
    int key;
};
extern struct Struct_0209ba2c* data_02109bb0;

// USA: func_0209ba2c
extern "C" ARM int func_0209ba2c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active != 0) {
        int value = ((Script::Parameter*)variant)->ToInt();
        func_0209be28(data_02109bb0->table, data_02109bb0->key, &value);
    }
    return 1;
}
