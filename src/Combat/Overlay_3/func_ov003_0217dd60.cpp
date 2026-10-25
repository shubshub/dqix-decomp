#include <globaldefs.h>

struct Struct0205de24;
struct GridCursor;
struct Struct_0205d81c;
struct Container020e0310;

struct Struct_ov003_0217dd60 {
    char unknown_0_[0x8];
    int unknown_8_;
    char unknown_c_[0x58 - 0xc];
    int unknown_58_;
    char unknown_5c_[0x68 - 0x5c];
    int unknown_68_;
    char unknown_6c_[0x94 - 0x6c];
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    char unknown_96_[0xa0 - 0x96];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[0xb5 - 0xb2];
    unsigned char unknown_b5_;
};

#if defined(jpn)
struct Struct_ov003_0217dd60_2 {
    char unknown_0_[0x14];
    unsigned char unknown_14_[0x2c - 0x14];
    unsigned char unknown_2c_;
    char unknown_2d_;
    unsigned char unknown_2e_;
    char unknown_2f_[0x8c - 0x2f];
    struct Struct_ov003_0217dd60* unknown_8c_;
    char unknown_90_[0xc8 - 0x90];
    char unknown_c8_[4];
};
#else
struct Struct_ov003_0217dd60_2 {
    char unknown_0_[0x10];
    int unknown_10_;
    char unknown_14_[0x18 - 0x14];
    unsigned char unknown_18_[0x30 - 0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_[0x90 - 0x33];
    struct Struct_ov003_0217dd60* unknown_90_;
    char unknown_94_[0xcc - 0x94];
    char unknown_cc_[4];
};
#endif

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24*, unsigned char, unsigned char);
void SetChannelBFlag0205cf04(void*);
void SetChannelAFlag0205cef8(void*);
int MessageSystem_GetInstance();
extern "C" void Zone3D_GetInstance();
extern "C" void __clear(void* buf, int n);
int KeyTable_Get(struct Container020e0310* c, int key);
void Text_AppendNTag(char* dst, int n, const char* name);
void Text_Append(char* dst, const char* src);
unsigned char* GetElementByB4IfAbsent_0205e00c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* elem, int state);
void WindowPane_SetIndicatorPage(unsigned char* elem, unsigned char value);
void WindowPane_SetIndicatorPageCount(unsigned char* elem, int value);
#if defined(jpn)
struct StoreStruct;
extern "C" void Window_OpenPane(void* window, char* buf, int a, int b, int c, int d, int e);
extern "C" void func_02046380(void* w);
void StoreInArray0x8b0_020465c0(struct StoreStruct*, int, int);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char* dst, int size);
#else
extern "C" void Window_OpenPane(void* window, char* buf, int a, int b, int c, int d, int e, int f);
#endif
void GridCursor_SetDimensions(struct GridCursor* t, int a, int b, int c);
void GridCursor_SetCount(struct GridCursor* n, int value);

extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dd60
#if defined(jpn)
extern "C" ARM void func_ov003_0217dd60(struct ListMenu0217dd60* menu) {
    char buf[0x400];
    Zone3D_GetInstance();
    struct StoreStruct* g = (struct StoreStruct*)MessageSystem_GetInstance();
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)menu->window, 0, 1);
    menu->window->fieldb1 = 0;
    {
        struct Struct_ov003_0217dd60* var2 = arg0->unknown_8c_;
        var2->unknown_a0_ = 14;
        var2->unknown_a2_ = 11;
    }
    {
        struct Struct_ov003_0217dd60* var3 = arg0->unknown_8c_;
        var3->unknown_a4_ = 9;
        var3->unknown_a6_ = 2;
    }
    {
        struct Struct_ov003_0217dd60* var4 = arg0->unknown_8c_;
        var4->unknown_a8_ = 13;
        var4->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* var5 = arg0->unknown_8c_;
        var5->unknown_ac_ = 10;
        var5->unknown_ae_ = 13;
    }
    arg0->unknown_8c_->unknown_b5_ = 1;
    func_0205cf04(arg0->unknown_8c_);
    func_0205cef8(arg0->unknown_8c_);
    int var6;
    int var7;
    int var8 = arg0->unknown_8c_->unknown_68_;
    __clear(var0, 0x400);
    var6 = (var8 + 1) * 6;
    if (var6 > arg0->unknown_2c_) {
        var6 = arg0->unknown_2c_;
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        Text_AppendNTag(buf, i % 6, name);
        if (i != end - 1) {
            Text_Append(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
        func_02046380(g);
        StoreInArray0x8b0_020465c0(g, 0, page + 1);
        StoreInArray0x8b0_020465c0(g, 1, menu->field32);
        SetByteInRange_020465f0((unsigned char*)g, 0, 2);
        SetByteInRange_020465f0((unsigned char*)g, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)g, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)g, 1, 0);
        func_02042428(buf, 8);
        Text_Append(buf, (const char*)KeyTable_Get((struct Container020e0310*)menu->names, 200));
    }
    if (menu->field32 > 1) {
        Window_OpenPane(menu->window, buf, 0, 0, 1, 1, 0);
    } else {
        Window_OpenPane(menu->window, buf, 0, 0, 0, 1, 0);
    }
    int field32 = menu->field32;
    struct ListWindow0217dd60* window = menu->window;
    window->field8 = field32;
    window->field58 = field32;
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct GridCursor*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct GridCursor*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->field95 = 1;
}
#else
extern "C" ARM void func_ov003_0217dd60(struct ListMenu0217dd60* menu) {
    char buf[0x400];
    Zone3D_GetInstance();
    MessageSystem_GetInstance();
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)menu->window, 0, 1);
    int field10Value = menu->field10;
    menu->window->fieldb1 = 0;
    short scaled = (short)(field10Value >> 3);
    {
        struct Struct_ov003_0217dd60* var16 = arg0->unknown_90_;
        var16->unknown_a0_ = var15;
        var16->unknown_a2_ = 11;
    }
    {
        struct Struct_ov003_0217dd60* var17 = arg0->unknown_90_;
        var17->unknown_a4_ = (32 - var15) >> 1;
        var17->unknown_a6_ = 2;
    }
    {
        struct Struct_ov003_0217dd60* var18 = arg0->unknown_90_;
        var18->unknown_a8_ = 12;
        var18->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* var19 = arg0->unknown_90_;
        var19->unknown_ac_ = 10;
        var19->unknown_ae_ = 13;
    }
    if (arg0->unknown_32_ > 1) {
        struct Struct_ov003_0217dd60* var20 = arg0->unknown_90_;
        var20->unknown_a0_ = var15;
        var20->unknown_a2_ = 12;
    }
    arg0->unknown_90_->unknown_b5_ = 1;
    func_0205cf04(arg0->unknown_90_);
    func_0205cef8(arg0->unknown_90_);
    int var21;
    int var22;
    int var23 = arg0->unknown_90_->unknown_68_;
    __clear(var13, 0x400);
    var21 = (var23 + 1) * 6;
    if (var21 > arg0->unknown_30_) {
        var21 = arg0->unknown_30_;
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        Text_AppendNTag(buf, i % 6, name);
        if (i != end - 1) {
            Text_Append(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
        unsigned char* elem = GetElementByB4IfAbsent_0205e00c((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            SetField0xd8State_02050400(elem, 1);
            WindowPane_SetIndicatorPage(elem, page);
            WindowPane_SetIndicatorPageCount(elem, menu->field32);
        }
    }
    if (menu->field32 > 1) {
        Window_OpenPane(menu->window, buf, 0, 0, 1, 1, 0, 0);
    } else {
        Window_OpenPane(menu->window, buf, 0, 0, 0, 1, 0, 0);
    }
    int field32 = menu->field32;
    struct ListWindow0217dd60* window = menu->window;
    window->field8 = field32;
    window->field58 = field32;
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct GridCursor*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct GridCursor*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->field95 = 1;
}
#endif
