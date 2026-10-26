#include <globaldefs.h>

extern "C" void func_0200ef44(void* obj, int count, int size, void* arg3);
extern "C" char* CachedTextEntry_Destroy(char* obj);
extern "C" void CachedTextTable_Clear(char* obj);

// USA: func_0203c75c
extern "C" ARM char* func_0203c75c(char* obj) {
    CachedTextTable_Clear(obj + 0x10);
    CachedTextTable_Clear(obj + 0x10);
#if defined(jpn)
    func_0200ef44(obj + 0x14, 0x60, 0x10, (void*)CachedTextEntry_Destroy);
#else
    func_0200ef44(obj + 0x14, 0x20, 0x28, (void*)CachedTextEntry_Destroy);
#endif
    return obj;
}
