#include <globaldefs.h>

struct B190Outer;
int GetBits12To15Clamped_0205af18(int unused, struct B190Outer* obj);
void* GetEntryPtr_021fa854(char* obj, unsigned int idx);
void ClearBit_021f6e34(void* obj, int idx, unsigned int bit);
void SpriteContext_Destroy(void* obj);
int MessageSystem_GetInstance();
extern "C" void func_ov023_021f6d9c(void* param2, void* field78);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov023_021fa7d4  (semantic: ClearEntriesAndSetGlobalFlags_021fa7d4)
extern "C" ARM void func_ov023_021fa7d4(void* obj, void* param2) {
    func_ov023_021f6d9c(param2, (char*)obj + RG(0x78, 0x74));
    for (unsigned int i = 0; i < *(unsigned short*)((char*)obj + RG(0x72, 0x6e)); i++) {
        void* entry = GetEntryPtr_021fa854((char*)obj + RG(0x24, 0x20), (unsigned short)i);
        if (entry != 0) {
            int bits = GetBits12To15Clamped_0205af18((int)((char*)obj + RG(0x24, 0x20)), (struct B190Outer*)entry);
            unsigned char byteVal = *(unsigned char*)((char*)obj + RG(0x74, 0x70));
            ClearBit_021f6e34(param2, byteVal, bits);
        }
    }
    SpriteContext_Destroy((char*)obj + RG(0x24, 0x20));
    char* global = (char*)MessageSystem_GetInstance();
    *(int*)(global + RG(0x2d8, 0x228)) = 0;
    *(unsigned char*)(global + RG(0x2e6, 0x236)) = 1;
}
