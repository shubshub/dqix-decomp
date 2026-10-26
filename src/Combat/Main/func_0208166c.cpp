#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02072a68 { short key; void* value; };
struct TableA68 { struct Struct_02072a68* entries; short count; };
extern "C" ARM void* func_02072a68(struct TableA68* table, int key);

struct Struct_0208166c {
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
};
struct Struct_0208166c_2 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

extern "C" ARM int func_02042190(int x);
extern "C" ARM int MessageSystem_GetInstance(void);

extern "C" int Font_GetTextWidth(void* p, int flag);
extern "C" int MessageSystem_FormatText(int a, int b, void* c, void* d, int e, int f, int g);
extern "C" int func_0204f41c(void* target, int a, int b, void* c, int d, int e, void* f, void* g, int h);

#define F13(e) ((struct Struct_0208166c*)((e) + 0x13))
#define F14(e) ((struct Struct_0208166c_2*)((e) + 0x14))

// USA: func_0208166c
extern "C" ARM void func_0208166c(void* arg0, void* arg1, void* arg2) {
    char* holder = (char*)arg0;
    char* target = (char*)arg1;
    char* entry = (char*)arg2;

    int var3 = F13(entry)->hiNibble;
    if (*(unsigned char*)(entry + 0x2a) & 0x4) {
        var3 = 5;
    }

    int boolResult = func_02042190(F13(entry)->loNibble);

    void* found = func_02072a68((struct TableA68*)*(void**)(holder + 0x0), *(short*)(entry + 0xe));
    if (found) {
        if (*(unsigned char*)(entry + 0x2a) & 0x8) {
            int var6 = *(short*)(target + 0xa8) << 0x13;
            int adj = Font_GetTextWidth(found, boolResult);
            int val = (int)((unsigned int)((var6 >> 0x10) - adj) << 0x10) >> 0x11;
            *(short*)(entry + 0x6) = (short)val;
        }
    }

    int loNibble = F13(entry)->loNibble;
    *(short*)(target + 0xb4) = (short)loNibble;
    *(short*)(target + 0xb6) = (short)(loNibble + 1);

    if (*(unsigned char*)(entry + 0x2a) & 0x10) {
        int var10 = F13(entry)->loNibble;
        if (var10 == 0xc) {
            *(short*)(target + 0xb4) = (short)var10;
            *(short*)(target + 0xb6) = 0x14;
        }
    }

    int r4 = 0;
    if (F14(entry)->unknown_0_0_) {
        r4 = Font_GetTextWidth(found, 0);
    }

    void* dataPtr = found;
    if (*(unsigned char*)(entry + 0x2a) & 0x20) {
        int g = MessageSystem_GetInstance();
        memset(*(void**)(holder + 0x18), 0, 0x960);
        MessageSystem_FormatText(g, F13(entry)->loNibble, found, *(void**)(holder + 0x18), *(unsigned char*)(entry + 0x2b), 0, 0);
        dataPtr = *(void**)(holder + 0x18);
        unsigned char var14 = *(unsigned char*)(entry + 0x2c);
        *(short*)(target + 0xb4) = (short)F13(entry)->loNibble;
        *(short*)(target + 0xb6) = var14;
    }

    short v6 = *(short*)(entry + 0x6);
    short v28 = *(short*)(entry + 0x28);
    short v8 = *(short*)(entry + 0x8);
    int var18 = (short)(v6 + v28 - r4);
    func_0204f41c(target, var18, v8, dataPtr, F13(entry)->loNibble, var3, entry + 0xa, entry + 0xc, 0);
}
