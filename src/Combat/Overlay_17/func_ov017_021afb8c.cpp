#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);
extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" int StandardStrings_Get(int value);
extern "C" void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);
extern "C" void func_0205c790(char* obj);
struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
extern "C" void func_0205cb74(char* obj, int value);
extern "C" void func_0205cc50(void* obj, int a, int b);
#if defined(jpn)
extern "C" void func_0205dfa8(void*);
extern "C" int sprintf(char*,const char*,...);
extern char data_ov017_021d7f74[];
extern char data_ov017_021d8104[];
#endif
struct Struct_0205c77c;
extern "C" void func_0205c77c(struct Struct_0205c77c* p, int val);
extern "C" void func_0205cd28(unsigned char* obj);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov017_021afb8c
extern "C" ARM void func_ov017_021afb8c(char* self, char* name) {
#if defined(jpn)
 enum {regionalOffset0=0x20c, regionalOffset1=0x20b};
#else
 enum {regionalOffset0=0x27c, regionalOffset1=0x27b};
#endif
    if ((unsigned char)self[2] != 0 && (unsigned char)self[9] != 2) {
#if defined(jpn)
        char buf2[0x64];
        sprintf(buf2,data_ov017_021d8104,name);

#else
        void* g = (void*)MessageSystem_GetInstance();
        char buf1[0x30];
        __clear(buf1, 0x30);
        Font_DecodeText(name, buf1, 1);
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, buf1);

        int ret = StandardStrings_Get(0x24);
        char buf2[0x64];
        MessageSystem_FormatText(g, 0xc, ret, buf2, 0x100, 0, 1);

#endif
        func_0205c790(self + 0x48);
        GridCursor_SetDimensions((struct GridCursor*)(self + 0x68), 1, 1, 0);
        GridCursor_SetDimensions((struct GridCursor*)(self + 0xb8), 1, 1, 0);
        GridCursor_SetCount((struct GridCursor*)(self + 0x68), 1);
        GridCursor_SetCount((struct GridCursor*)(self + 0xb8), 1);

        func_0205cb74(self + 0x48, (int)buf2);

        *(short*)(self + 0xfc) = 0xc;
        *(short*)(self + 0xfe) = 0x40;
#if defined(jpn)
        func_0205dfa8(self + 0x48);
#else
        func_0205cc50(self + 0x48, 0, -4);
#endif

        self[regionalOffset0] = 1;
        func_0205c77c((struct Struct_0205c77c*)(self + 0x4c), 1);
        self[regionalOffset1] = 1;
        self[regionalOffset0] = 1;
        func_0205c77c((struct Struct_0205c77c*)(self + 0x4c), 1);

        short v = *(short*)(self + 0x100);
        *(short*)(self + 0xfc) = (0x100 - v) / 2;
        *(short*)(self + 0xfe) = 0x40;

        func_0205cd28((unsigned char*)(self + 0x48));
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x800000);
    }
}
