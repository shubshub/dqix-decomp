#include <globaldefs.h>

struct Vec3Target0203a46c;
extern "C" void SprSprite_SetPosition(struct Vec3Target0203a46c* obj, int x, int y, int z);

// USA: func_ov017_0219b578
extern "C" ARM void func_ov017_0219b578(char* self, int arg1, int arg2) {
#if defined(jpn)
    struct Vec3Target0203a46c* obj = *(struct Vec3Target0203a46c**)(self + 0x3000 + 0x420);
#else
    struct Vec3Target0203a46c* obj = *(struct Vec3Target0203a46c**)(self + 0x3000 + 0x630);
#endif
    if (obj == 0) {
        return;
    }
    int var1 = *(int*)((char*)obj + 0x1c);
    int newX = (int)(((float)var1 / 4096.0f + (float)arg1) * 4096.0f);
    int var3 = *(int*)((char*)obj + 0x20);
    int newY = (int)(((float)var3 / 4096.0f + (float)arg2) * 4096.0f);
    SprSprite_SetPosition(obj, newX, newY, 0);
}
