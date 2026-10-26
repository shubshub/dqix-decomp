#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

extern int data_ov001_021658e0[];
struct Struct_ov001_021658b8_11 { char pad[0x88]; int count; };
extern Struct_ov001_021658b8_11 data_ov001_021658b8;

// USA: func_ov001_0215edb8
extern "C" ARM int func_ov001_0215edb8(void* self) {
    int table = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < data_ov001_021658b8.count; i++) {
        if (((BackgroundLoader*)(table))->GetTaskStatus((int)(data_ov001_021658e0[i])) == 0) {
            func_ov017_021d6134(self, 1);
            return 1;
        }
    }
    func_ov017_021d6134(self, 0);
    return 1;
}
