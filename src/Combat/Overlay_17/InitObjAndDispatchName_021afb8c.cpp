#include <globaldefs.h>

int MessageSystem_GetInstance(void);
extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
struct Obj02046574;
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
int StandardStrings_Get(int value);
extern "C" void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);
void InitBigStruct0205c790(char* obj);
struct GridCursor;
void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
void GridCursor_SetCount(struct GridCursor* s, int val);
void ProcessCombatEntry0205cb74(char* obj, int value);
extern "C" void func_0205cc50(void* obj, int a, int b);
#if defined(jpn)
extern "C" void func_0205dfa8(void*);
extern "C" int sprintf(char*,const char*,...);
extern char data_ov017_021d7f74[];
extern char data_ov017_021d8104[];
#endif
struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(struct ResetBytesAndSetByte0x16Data* p, int val);
void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov017_021afb8c  (semantic: InitObjAndDispatchName_021afb8c)
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
        InitBigStruct0205c790(self + 0x48);
        GridCursor_SetDimensions((struct GridCursor*)(self + 0x68), 1, 1, 0);
        GridCursor_SetDimensions((struct GridCursor*)(self + 0xb8), 1, 1, 0);
        GridCursor_SetCount((struct GridCursor*)(self + 0x68), 1);
        GridCursor_SetCount((struct GridCursor*)(self + 0xb8), 1);

        ProcessCombatEntry0205cb74(self + 0x48, (int)buf2);

        *(short*)(self + 0xfc) = 0xc;
        *(short*)(self + 0xfe) = 0x40;
#if defined(jpn)
        func_0205dfa8(self + 0x48);
#else
        func_0205cc50(self + 0x48, 0, -4);
#endif

        self[regionalOffset0] = 1;
        ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(self + 0x4c), 1);
        self[regionalOffset1] = 1;
        self[regionalOffset0] = 1;
        ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(self + 0x4c), 1);

        short v = *(short*)(self + 0x100);
        *(short*)(self + 0xfc) = (0x100 - v) / 2;
        *(short*)(self + 0xfe) = 0x40;

        SetupGlobalObjType1AndInitSelfPointer_0205cd28((unsigned char*)(self + 0x48));
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x800000);
    }
}
