#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov002_0215a920(void*);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov002_0215a8cc
extern "C" ARM int func_ov002_0215a8cc(char* p) {
    if (*(unsigned char*)(p + 0x2000 + RG(0x53c, 0x364)) == 0) return 0;
    unsigned int val1 = *(unsigned int*)(p + 0x2000 + RG(0x540, 0x368));
    *(short*)(p + RG(0x1b00 + 0xe0, 0x1a00 + 0xa8)) = (short)val1;
    void* blk = (void*)(p + RG(0x13c + 0x2400, 0x364 + 0x2000));
    unsigned int val2 = *(unsigned int*)(p + 0x2000 + RG(0x544, 0x36c));
    *(short*)(p + RG(0x1b00 + 0xfe, 0x1a00 + 0xc6)) = (short)val2;
    func_ov002_0215a920(blk);
    char* other = (char*)GetGameResources();
    void* obj2 = *(void**)(other + 0x3000 + RG(0x71c, 0x50c));
    func_ov002_0215a920((char*)obj2 + 0x24);
    return 1;
}
