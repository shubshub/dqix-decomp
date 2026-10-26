#include <globaldefs.h>

struct Container0203a54c;

void NumberPopups_UnloadSprites(struct Container0203a54c* c);
void* SprSprite_Destroy(void* obj);
extern "C" void func_0200ef44(void* base, int count, int size, void* (*ctor)(void*));

// USA: func_0203a8d4
ARM struct Container0203a54c* InitSubObjectArraysReturnSelf_0203a8d4(struct Container0203a54c* obj) {
    NumberPopups_UnloadSprites(obj);
    func_0200ef44((char*)obj + 0x2a8, 5, 0x88, SprSprite_Destroy);
    func_0200ef44(obj, 5, 0x88, SprSprite_Destroy);
    return obj;
}
