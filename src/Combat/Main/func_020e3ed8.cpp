#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020e3b8c {
    char pad[0x14];
    int arr[2];
};

// USA: func_020e3ed8
extern "C" ARM void func_020e3ed8(struct Struct_020e3b8c* p) {
    int x = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < 2; i++) {
        if (p->arr[i] != -1) {
            ((BackgroundLoader*)(x))->RemoveTask((int)(p->arr[i]));
        }
    }
}
