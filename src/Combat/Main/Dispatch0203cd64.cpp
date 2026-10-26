#include <globaldefs.h>

extern "C" void NpcWalker_SelectDirectionAnimation(void* obj);
extern "C" void func_0203f53c(void* obj, int arg, int size);

// USA: func_0203cd64
ARM void Dispatch0203cd64(char* obj, int arg1) {
    int flags = *(int*)(obj + 0x5c);
    if (!(flags & 0x10) && !(flags & 0x20)) {
        NpcWalker_SelectDirectionAnimation(obj);
    }
    func_0203f53c(obj, arg1, ((unsigned char*)obj)[0x95] != 0 ? 0xe40 : 0x1000);
}
