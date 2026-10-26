#include <globaldefs.h>

struct ResetObj020d7a5c;
extern "C" struct ResetObj020d7a5c* TextQueue_GetInstance();
struct Obj020d7aa0;
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_0205c790(char* obj);

struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
extern "C" int StandardStrings_Get(int value);
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

// USA: func_ov017_021adb50
extern "C" ARM void func_ov017_021adb50(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x208, regionalOffset1=0x207};
#else
 enum {regionalOffset0=0x278, regionalOffset1=0x277};
#endif
    TextQueue_Reset((struct Obj020d7aa0*)TextQueue_GetInstance());
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    func_0205c790(self + 0x44);
    GridCursor_SetDimensions((struct GridCursor*)(self + 0x64), 1, 1, 0);
    GridCursor_SetDimensions((struct GridCursor*)(self + 0xb4), 1, 1, 0);
    GridCursor_SetCount((struct GridCursor*)(self + 0x64), 1);
    GridCursor_SetCount((struct GridCursor*)(self + 0xb4), 1);
#if defined(jpn)
    int val = (int)data_ov017_021d7f74;
#else
    int val = StandardStrings_Get(0x1f);
#endif

    func_0205cb74(self + 0x44, val);
    *(short*)(self + 0xf8) = 8;
    *(short*)(self + 0xfa) = 0x40;
#if defined(jpn)
    func_0205dfa8(self + 0x44);
#else
    func_0205cc50(self + 0x44, 0, -4);
#endif

    self[regionalOffset0] = 1;
    func_0205c77c((struct Struct_0205c77c*)(self + 0x48), 1);
    self[regionalOffset1] = 1;
    self[regionalOffset0] = 1;
    func_0205c77c((struct Struct_0205c77c*)(self + 0x48), 1);
#if defined(jpn)

#else
    short v = *(short*)(self + 0xfc);
    *(short*)(self + 0xf8) = (0x100 - v) / 2;
    *(short*)(self + 0xfa) = 0x40;

#endif
    func_0205cd28((unsigned char*)(self + 0x44));
}
