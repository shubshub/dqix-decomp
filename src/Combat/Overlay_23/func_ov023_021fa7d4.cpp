#include <globaldefs.h>

struct Struct_0205af18;
extern "C" int func_0205af18(int unused, struct Struct_0205af18* obj);
extern "C" void* func_ov023_021fa854(char* obj, unsigned int idx);
extern "C" void func_ov023_021f6e34(void* obj, int idx, unsigned int bit);
extern "C" void SpriteContext_Destroy(void* obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov023_021f6d9c(void* param2, void* arg1);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov023_021fa7d4
extern "C" ARM void func_ov023_021fa7d4(void* obj, void* param2) {
    func_ov023_021f6d9c(param2, (char*)obj + RG(0x78, 0x74));
    for (unsigned int i = 0; i < *(unsigned short*)((char*)obj + RG(0x72, 0x6e)); i++) {
        void* entry = func_ov023_021fa854((char*)obj + RG(0x24, 0x20), (unsigned short)i);
        if (entry != 0) {
            int bits = func_0205af18((int)((char*)obj + RG(0x24, 0x20)), (struct Struct_0205af18*)entry);
            unsigned char byteVal = *(unsigned char*)((char*)obj + RG(0x74, 0x70));
            func_ov023_021f6e34(param2, byteVal, bits);
        }
    }
    SpriteContext_Destroy((char*)obj + RG(0x24, 0x20));
    char* global = (char*)MessageSystem_GetInstance();
    *(int*)(global + RG(0x2d8, 0x228)) = 0;
    *(unsigned char*)(global + RG(0x2e6, 0x236)) = 1;
}
