#include <globaldefs.h>

extern "C" void func_0200ef44(void* obj, int count, int size, void* initFn);
char* CachedTextEntry_Destroy(char* obj);
void CachedTextTable_Clear(char* obj);

// USA: func_0203c75c
ARM char* InitBattleObject0203c75c(char* obj) {
    CachedTextTable_Clear(obj + 0x10);
    CachedTextTable_Clear(obj + 0x10);
#if defined(jpn)
    func_0200ef44(obj + 0x14, 0x60, 0x10, (void*)CachedTextEntry_Destroy);
#else
    func_0200ef44(obj + 0x14, 0x20, 0x28, (void*)CachedTextEntry_Destroy);
#endif
    return obj;
}
