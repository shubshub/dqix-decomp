#include <globaldefs.h>

#if defined(jpn)
enum { kEnabled = 0x1c4, kActive = 0x1c3 };
#else
enum { kEnabled = 0x234, kActive = 0x233 };
#endif

void InitBigStruct0205c790(char* obj);

struct GridCursor;
void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);

void GridCursor_SetCount(struct GridCursor* s, int val);

void ProcessCombatEntry0205cb74(char* obj, int value);

#if defined(jpn)
extern "C" void func_0205dfa8(void* obj);
extern "C" void func_0206cfd4(char*);
#else
extern "C" void func_0205cc50(void* obj, int a, int b);
#endif

int MessageSystem_GetInstance(void);
void StoreClampedDeltas_0206b7b0(char* base);

struct Struct_0205bcdc;
void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);

extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(struct ResetBytesAndSetByte0x16Data* p, int val);

void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);

// JPN: func_020665bc
// USA: func_020652d0
#if defined(jpn)
extern "C" ARM void func_020665bc(char* obj, int a, const char* b, const char* c) {
#else
ARM void InitCombatPairState020652d0(char* obj, int a, int b, int c) {
#endif
    InitBigStruct0205c790(obj);

    obj[0xb1] = 1;
    obj[0xb0] = 1;
    GridCursor_SetDimensions((struct GridCursor*)(obj + 0x20), 1, 2, 0);
    GridCursor_SetDimensions((struct GridCursor*)(obj + 0x70), 1, 2, 0);

    GridCursor_SetCount((struct GridCursor*)(obj + 0x20), 2);
    GridCursor_SetCount((struct GridCursor*)(obj + 0x70), 2);

#if defined(jpn)
    ProcessCombatEntry0205cb74(obj, (int)b);
    ProcessCombatEntry0205cb74(obj, (int)c);
#else
    ProcessCombatEntry0205cb74(obj, b);
    ProcessCombatEntry0205cb74(obj, c);
#endif

    *(short*)(obj + 0xb4) = 0;
    *(short*)(obj + 0xb6) = 0;

#if defined(jpn)
    func_0205dfa8(obj);
    func_0206cfd4((char*)MessageSystem_GetInstance());
    func_0205dfa8(obj);
#else
    func_0205cc50(obj, 1, -4);
    StoreClampedDeltas_0206b7b0((char*)MessageSystem_GetInstance());
    func_0205cc50(obj, 1, -4);
#endif

    GridCursor_SelectIfValid((struct Struct_0205bcdc*)(obj + 0x20), a);
    GridCursor_SetSelectedIndex(obj + 0x70, a);

    obj[kEnabled] = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(obj + 0x4), 1);

    obj[kActive] = 1;
    obj[kEnabled] = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(obj + 0x4), 1);

    SetupGlobalObjType1AndInitSelfPointer_0205cd28((unsigned char*)obj);

    int bit = (*(volatile unsigned short*)0x4000304 & 0x8000) >> 15;
    if (bit == 1) {
        obj[0xb0] = 0;
    }
}
