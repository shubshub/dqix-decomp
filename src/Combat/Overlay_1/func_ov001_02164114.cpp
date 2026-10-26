#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov017_021d4cc0(void* obj, int* arr, int count);

struct Struct_ov001_02164d6c { unsigned int key; int index; };
extern struct Struct_ov001_02164d6c data_ov001_02164d6c[];
extern int data_ov001_02165d74[1000];

// USA: func_ov001_02164114
extern "C" ARM void func_ov001_02164114(void* obj) {
    memset(data_ov001_02165d74, 0, 0xfa0);
    struct Struct_ov001_02164d6c* e = data_ov001_02164d6c;
    while (e != 0) {
        if (e->key == 0) {
            break;
        }
        if (e->index >= 0 && e->index < 0x3e8) {
            if (data_ov001_02165d74[e->index] != 0) {
                while (1) {}
            }
            data_ov001_02165d74[e->index] = e->key;
        }
        e++;
    }
    func_ov017_021d4cc0(obj, data_ov001_02165d74, 0x3e8);
}
