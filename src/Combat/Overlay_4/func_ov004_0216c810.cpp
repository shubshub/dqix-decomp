#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02108760_2;
struct Struct_0209c3b4_2;
struct Struct_02072a68_2;
struct Struct_02000c9c_8;
struct Struct_ov004_0216b7bc;

void SetModeClamped0209ca70(void* obj, int val);
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void SetByte0x7f70_02012028(void* obj, unsigned char value);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
void* GetNodeIfType6_0216ae9c(void* a, int id);
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

class Struct_ov004_0216c810_3 {
public:
    virtual void inline_ov004_0216c810_22(); virtual void inline_ov004_0216c810_23(); virtual void inline_ov004_0216c810_24(); virtual void inline_ov004_0216c810_25();
    virtual void inline_ov004_0216c810_26(); virtual void inline_ov004_0216c810_27(); virtual void inline_ov004_0216c810_28(); virtual void inline_ov004_0216c810_29();
    virtual void inline_ov004_0216c810_30(); virtual void inline_ov004_0216c810_31(); virtual void inline_ov004_0216c810_32(); virtual void inline_ov004_0216c810();
    virtual void inline_ov004_0216c810_2(); virtual void inline_ov004_0216c810_3(); virtual void inline_ov004_0216c810_4(); virtual void inline_ov004_0216c810_5();
    virtual void inline_ov004_0216c810_6();
    virtual void inline_ov004_0216c810_7(int arg0);
    virtual void inline_ov004_0216c810_8(); virtual void inline_ov004_0216c810_9(); virtual void inline_ov004_0216c810_10(); virtual void inline_ov004_0216c810_11();
    virtual void inline_ov004_0216c810_12(); virtual void inline_ov004_0216c810_13(); virtual void inline_ov004_0216c810_14(); virtual void inline_ov004_0216c810_15();
    virtual void inline_ov004_0216c810_16(); virtual void inline_ov004_0216c810_17(); virtual void inline_ov004_0216c810_18(); virtual void inline_ov004_0216c810_19();
    virtual void inline_ov004_0216c810_20();
    virtual void inline_ov004_0216c810_21(int arg0);
    char unknown_4_[8];
    unsigned char unknown_c_;
};

struct Struct_ov004_0216c810 {
    char unknown_0_[0x998];
    int unknown_998_;
    char unknown_99c_[0x19af - 0x99c];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x19ca - 0x19b0];
    unsigned char unknown_19ca_;
};

struct Struct_ov004_0216c810_2 {
    char unknown_0_[0x7f73];
    unsigned char unknown_7f73_;
};

struct Struct_ov004_02170174 {
    unsigned char unknown_0_[6];
};

struct Struct_ov004_02171034_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    char unknown_5_[5];
    unsigned short unknown_a_;
    int unknown_c_;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" UiNode0216c810* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(void* node);
extern "C" void func_ov011_021848a0(void* a, int val);
extern "C" void func_ov004_0216b498(void* a, int mode, int sub);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);
extern "C" void func_ov023_021f9ba8(void* node, unsigned short count);
extern "C" struct TableA68* func_ov023_021fa598(void* node);
MessageWindow0216c810* MessageSystem_GetInstance();
extern "C" void func_0204500c(MessageWindow0216c810* win, void* entry, int a, int b);
extern "C" void func_ov023_021f8120(void* node);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int a10);
extern "C" void func_ov004_0216ba70(void* a);

extern char g_bgmPlayer[];
extern struct Obj0205e9f4 g_sePlayer;
extern MenuState02171034 data_ov004_02171034;
extern Bytes6 data_ov004_02170174;

// USA: func_ov004_0216c810
extern "C" ARM int func_ov004_0216c810(void* arg0) {
    GameState* var0;
    Struct_ov004_0216c810_2* var1;
    int var2;
    int var3;
    int var4;
    Struct_ov004_0216c810_3* var5;

    SetModeClamped0209ca70(g_bgmPlayer, 3);
    SetStateAndDispatch0205e9f4(&g_sePlayer, 3);
    data_ov004_02171034.byte4 = 3;
    data_ov004_02171034.byte1 = 3;
    data_ov004_02171034.messageId = 0;
    if (data_ov004_02171034.state3 != 4) {
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, 2);
    }
    gs = GameState::GetInstance();
    GameState_GetParty(gs);
    mode = 0;
    sub = 0;
    data_ov004_02171034.flag2 = 0;
    func_ov023_021f6880(func_ov011_021849c8(a), 0xb)->flagsC |= 8;

    if (data_ov004_02171034.unknown_3_ == 0) {
        func_ov023_021f6880(func_ov011_021849c8(arg0), 1)->unknown_c_ |= 8;
        func_ov011_021848a0(arg0, 0xc9);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 1) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 1;
        var3 = 0;
        var4 = 0x12e;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var6 = 0; var6 < 3; var6++) {
            func_ov004_0216b2c8(arg0, var4, var6 + 0x32, var6);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(8);
            var5->inline_ov004_0216c810_21(8);
        }
        func_ov004_0216b20c(arg0, 0x33, 0x96, 0);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x34);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
        var1 = (Struct_ov004_0216c810_2*)var0;
        int var7 = var1->unknown_7f73_;
        if (var7 > 0) {
            Struct_ov004_0216c810_3* var8 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x12e);
            Struct_ov004_0216c810_3* var9;
            if (var8 == 0) {
                var9 = 0;
            } else if (func_ov023_021f6f10(var8) != 7) {
                var9 = 0;
            } else {
                var9 = var8;
            }
            if (var9) {
                func_ov023_021f9ba8(var9, var7);
            }
            var1->unknown_7f73_ = 0;
        }
    } else if (data_ov004_02171034.unknown_3_ == 2) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 2;
        var3 = 0;
        var4 = 0x12d;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var10 = 0; var10 < 2; var10++) {
            func_ov004_0216b2c8(arg0, var4, var10 + 0x32, var10);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(5);
            var5->inline_ov004_0216c810_21(5);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x33);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.unknown_3_ == 3) {
        var2 = 3;
        var4 = 0x12c;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        func_ov004_0216b2c8(arg0, var4, 0x32, var3);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(8);
            var5->inline_ov004_0216c810_21(8);
        }
    } else if (data_ov004_02171034.unknown_3_ == 4) {
        func_02012028(var0, 0);
        func_ov011_021848a0(arg0, 0x190);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 5) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 1;
        var3 = 0;
        var4 = 0x12e;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var11 = 0; var11 < 3; var11++) {
            func_ov004_0216b2c8(arg0, var4, var11 + 0x32, var11);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(0);
            var5->inline_ov004_0216c810_21(0);
        }
        func_ov004_0216b20c(arg0, 0x33, 0x96, 0);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x34);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.state3 == 6) {
        SetByte0x7f70_02012028(gs, 0);
        void* list = func_ov011_021849c8(a);
        UiNode0216c810* box = func_ov023_021f6880(list, 1);
        if (box == 0) return 0;
        if (func_ov023_021f6f10(box) != 0xb) return 0;
        box->flagsC |= 8;
        UiNode0216c810* text = func_ov023_021f6880(list, 0x192);
        if (text == 0) return 0;
        if (func_ov023_021f6f10(text) != 4) return 0;
        struct TableA68* table = func_ov023_021fa598(text);
        MessageWindow0216c810* win = MessageSystem_GetInstance();
        win->busy = 1;
        func_0204500c(win, FindEntryByKey_02072a68(table, 0x5dc), 0, 0xe3);
        win->flag19ca = 0;
        win->flag19af = 0;
        SetByte0x7f70_02012028(gs, 0);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 7) {
        func_02012028(var0, 0);
        func_ov011_021848a0(arg0, 0x258);
        return 0;
    }

    SetField1c8True_02184ad8((struct Obj_02184ad8*)a);
    int y;
    void* panel = GetNodeIfType6_0216ae9c(a, 0xd2);
    func_ov023_021f8120(panel);
    y = 0x60;
    unsigned char kind = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    Bytes6 rows = data_ov004_02170174;
    int n;
    switch (mode) {
    case 0:
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, 0x12, 5, 0, 1, 0);
        var17 += 0xb40;
        break;
    case 1:
        switch (var3) {
        case 0:
            var21 = var20.unknown_0_[var19];
            func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 6, 0, 1, 0);
            var17 += var21 * 0xc0;
            break;
        default:
            var21 = var20.unknown_0_[var19];
            func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 6, 0, 1, 0);
            var17 += var21 * 0xc0;
            break;
        }
        break;
    case 2:
        var21 = var20.unknown_0_[var19];
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 5, 0, 1, 0);
        var17 += var21 * 0xa0;
        break;
    case 3:
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, 0xc, 3, 0, 1, 0);
        var17 += 0xb40;
        break;
    }
    data_ov004_02171034.unknown_c_ = var17;
    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)arg0);
    if (var2 == 1 && data_ov004_02171034.unknown_3_ != 5) {
        func_ov004_0216ba70(arg0);
    }
    return 0;
}
