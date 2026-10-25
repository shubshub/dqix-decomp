#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
int MessageSystem_GetInstance(void);
extern "C" ARM void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
void Text_Append(char*, const char*);
#else
extern "C" ARM void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif


// USA: func_ov023_021ed354
extern "C" ARM void func_ov023_021ed354(char* arg0) {
    struct Struct_ov023_021ed354 { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; };
    unsigned char var0 = ((Struct_ov023_021ed354*)(arg0 + 0xa0))->unknown_0_0_;
    func_0205de24((struct Struct_0205de24_2*)(arg0 + 0xc4), var0, 3);

    *(unsigned short*)(arg0 + 0x164) = 0x1e;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x166) = 0xb;
#else
    *(unsigned short*)(arg0 + 0x166) = 0xa;
#endif

    *(unsigned short*)(arg0 + 0x168) = 0x1;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x16a) = 0xc;
#else
    *(unsigned short*)(arg0 + 0x16a) = 0xd;
#endif

#if defined(jpn)
    *(unsigned short*)(arg0 + 0x16c) = 0xa;
#else
    *(unsigned short*)(arg0 + 0x16c) = 0x7;
#endif

#if defined(jpn)
    *(unsigned short*)(arg0 + 0x16e) = 0xa;
#else
    *(unsigned short*)(arg0 + 0x16e) = 0x8;
#endif

    *(unsigned short*)(arg0 + 0x170) = 0xc;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x172) = 0x14;
#else
    *(unsigned short*)(arg0 + 0x172) = 0xc;
#endif

    *(unsigned char*)(arg0 + 0x17b) = 0xc;
    *(unsigned char*)(arg0 + 0x175) = 0x1;
    *(unsigned char*)(arg0 + 0x179) = 0;
    *(unsigned char*)(arg0 + 0x17a) = 0;

#if defined(jpn)
    char* elem = *(char**)(obj + 0x20) + *(unsigned char*)(obj + 0x28) * 0x15c;
    memset(*(void**)(obj + 0x1c), 0, 0x800);
    Text_Append(*(char**)(obj + 0x1c), *(char**)(elem + 4));

#else
    void* g = (void*)MessageSystem_GetInstance();
    memset(*(void**)(obj + 0x1c), 0, 0x960);

    void* base = *(void**)(obj + 0x20);
    unsigned char idx = *(unsigned char*)(obj + 0x28);
    int c = *(int*)((char*)base + idx * 0x244 + 4);
    MessageSystem_FormatText(g, 1, c, *(void**)(obj + 0x1c), 0xe3, 0, 1);


#endif
#if defined(jpn)
    Window_OpenPane(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0);
#else
    Window_OpenPane(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
