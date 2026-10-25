#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217dfb4_20=0x10 };
extern "C" void func_02046380(void*);
struct Struct_020465c0;
extern "C" void func_020465c0(Struct_020465c0*,int,int);
extern "C" void func_020465f0(unsigned char*,int,unsigned char);
extern "C" void func_020465d8(unsigned char*,int,unsigned char);
extern "C" void func_02042428(char*, int);
#else
enum { Enum_ov003_0217dfb4_20=0x14 };
#endif

struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205d5d0;
struct Struct_0201099c_3;

struct Struct_ov003_0217dfb4 {
    char unknown_0_[0x68];
    int unknown_68_;
};

struct Struct_ov003_0217dfb4_2 {
    char unknown_0_[Enum_ov003_0217dfb4_20];
    int unknown_14_;
    unsigned char unknown_18_[0x30 - 0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_[0x90 - 0x33];
    struct Struct_ov003_0217dfb4* unknown_90_;
    char unknown_94_[0xcc - 0x94];
    char unknown_cc_[4];
};

extern "C" void* Zone3D_GetInstance(void);
int MessageSystem_GetInstance();
extern "C" void __clear(void* buf, int n);
int Window_GetSelectedIndex(struct Struct_0205c570* s);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
unsigned char* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* elem, int state);
void WindowPane_SetIndicatorPage(unsigned char* elem, unsigned char value);
void WindowPane_SetIndicatorPageCount(unsigned char* elem, int value);
extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dfb4
extern "C" ARM void func_ov003_0217dfb4(struct ListMenu0217dfb4* menu) {
    char buf[0x400];
    Zone3D_GetInstance();
#if defined(jpn)
    int global = MessageSystem_GetInstance();
#else
    MessageSystem_GetInstance();
#endif
    __clear(var0, 0x400);
    int var2;
    int var3;
    int var4 = arg0->unknown_90_->unknown_68_;
    var2 = (var4 + 1) * 6;
    if (var2 > arg0->unknown_30_) {
        var2 = arg0->unknown_30_;
    }
    if (menu->mode == 2) {
        Text_AppendFrameTag(buf, Window_GetSelectedIndex((struct Struct_0205c570*)menu->window) % 6, 8, 5, 5, 5);
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        Text_AppendNTag(buf, i % 6, name);
        if (i != end - 1) {
            Text_Append(buf, data_ov003_02180c7f);
        }
    }
    if (arg0->unknown_32_ > 1) {
#if defined(jpn)
        func_02046380((void*)global);
        StoreInArray0x8b0_020465c0((StoreStruct*)global, 0, page + 1);
        StoreInArray0x8b0_020465c0((StoreStruct*)global, 1, menu->field32);
        SetByteInRange_020465f0((unsigned char*)global, 0, 2);
        SetByteInRange_020465f0((unsigned char*)global, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)global, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)global, 1, 0);
        func_02042428(buf, 8);
        Text_Append(buf, (const char*)KeyTable_Get((Container020e0310*)menu->names, 0xc8));
#else
        unsigned char* elem = FindElementByC40205d81c((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            SetField0xd8State_02050400(elem, 1);
            WindowPane_SetIndicatorPage(elem, page);
            WindowPane_SetIndicatorPageCount(elem, menu->field32);
        }
#endif
    }
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)menu->window, 0, (int)buf, 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)menu->window, 0, (int)buf, 1, 0);
#endif
}
