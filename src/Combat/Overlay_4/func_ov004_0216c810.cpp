#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0205e9f4;
struct Actor0209c3b4;
struct TableA68;
struct Struct0200fb08;
struct Struct_ov004_0216b7bc;

extern "C" void func_0209ca70(void* obj, int val);
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void* func_ov004_0216b1c4(void* a, int id);
extern "C" void* func_ov004_0216ae9c(void* a, int id);
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern "C" void func_ov011_02184ad8(struct Struct_ov004_0216b7bc* obj);
extern "C" void* func_02072a68(struct TableA68* table, int key);

class Struct_ov004_0216c810_3 {
public:
    virtual void v00(); virtual void inline_ov004_0216c810_23(); virtual void inline_ov004_0216c810_24(); virtual void inline_ov004_0216c810_25();
    virtual void v04(); virtual void inline_ov004_0216c810_27(); virtual void inline_ov004_0216c810_28(); virtual void inline_ov004_0216c810_29();
    virtual void v08(); virtual void inline_ov004_0216c810_31(); virtual void v10(); virtual void inline_ov004_0216c810();
    virtual void inline_ov004_0216c810_2(); virtual void inline_ov004_0216c810_3(); virtual void v14(); virtual void inline_ov004_0216c810_5();
    virtual void inline_ov004_0216c810_6();
    virtual void inline_ov004_0216c810_7(int pal);
    virtual void v18(); virtual void inline_ov004_0216c810_9(); virtual void v20(); virtual void inline_ov004_0216c810_11();
    virtual void inline_ov004_0216c810_12(); virtual void inline_ov004_0216c810_13(); virtual void v24(); virtual void inline_ov004_0216c810_15();
    virtual void inline_ov004_0216c810_16(); virtual void inline_ov004_0216c810_17(); virtual void v28(); virtual void inline_ov004_0216c810_19();
    virtual void v30();
    virtual void inline_ov004_0216c810_21(int color);
    char pad4[8];
    unsigned char unknown_c_;
};

struct MessageWindow0216c810 {
    char pad0[0x998];
    int busy;
    char unknown_99c_[0x19af - 0x99c];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x19ca - 0x19b0];
    unsigned char unknown_19ca_;
};

struct Struct_ov004_0216c810_2 {
    char pad0[0x7f73];
    unsigned char unknown_7f73_;
};

struct Struct_ov004_02170174 {
    unsigned char v[6];
};

struct Struct_ov004_02171034_2 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char flag2;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    char pad5[5];
    unsigned short messageId;
    int cursorY;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_0216c810_3* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(void* node);
extern "C" void func_ov011_021848a0(void* a, int val);
extern "C" void func_ov004_0216b498(void* a, int mode, int sub);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);
extern "C" void func_ov023_021f9ba8(void* node, unsigned short count);
extern "C" struct TableA68* func_ov023_021fa598(void* node);
extern "C" MessageWindow0216c810* MessageSystem_GetInstance();
extern "C" void func_0204500c(MessageWindow0216c810* win, void* entry, int a, int b);
extern "C" void func_ov023_021f8120(void* node);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int arg9);
extern "C" void func_ov004_0216ba70(void* a);

extern char g_bgmPlayer[];
extern struct Obj0205e9f4 g_sePlayer;
extern Struct_ov004_02171034_2 data_ov004_02171034;
extern Struct_ov004_02170174 data_ov004_02170174;

// USA: func_ov004_0216c810
extern "C" ARM int func_ov004_0216c810(void* a) {
    GameState* gs;
    Struct_ov004_0216c810_2* bs;
    int mode;
    int sub;
    int msg;
    Struct_ov004_0216c810_3* node;

    func_0209ca70(g_bgmPlayer, 3);
    func_0205e9f4(&g_sePlayer, 3);
    data_ov004_02171034.unknown_4_ = 3;
    data_ov004_02171034.unknown_1_ = 3;
    data_ov004_02171034.messageId = 0;
    if (data_ov004_02171034.unknown_3_ != 4) {
        func_0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, 2);
    }
    gs = GameState::GetInstance();
    GameState_GetParty(gs);
    mode = 0;
    sub = 0;
    data_ov004_02171034.flag2 = 0;
    func_ov023_021f6880(func_ov011_021849c8(a), 0xb)->unknown_c_ |= 8;

    if (data_ov004_02171034.unknown_3_ == 0) {
        func_ov023_021f6880(func_ov011_021849c8(a), 1)->unknown_c_ |= 8;
        func_ov011_021848a0(a, 0xc9);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 1) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->unknown_c_ &= ~8;
        mode = 1;
        sub = 0;
        msg = 0x12e;
        func_ov004_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 3; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->inline_ov004_0216c810_7(8);
            node->inline_ov004_0216c810_21(8);
        }
        func_ov004_0216b20c(a, 0x33, 0x96, 0);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x34);
        if (node) {
            node->inline_ov004_0216c810_7(0xa);
            node->inline_ov004_0216c810_21(0xa);
        }
        bs = (Struct_ov004_0216c810_2*)gs;
        int count = bs->unknown_7f73_;
        if (count > 0) {
            Struct_ov004_0216c810_3* found = func_ov023_021f6880(func_ov011_021849c8(a), 0x12e);
            Struct_ov004_0216c810_3* counter;
            if (found == 0) {
                counter = 0;
            } else if (func_ov023_021f6f10(found) != 7) {
                counter = 0;
            } else {
                counter = found;
            }
            if (counter) {
                func_ov023_021f9ba8(counter, count);
            }
            bs->unknown_7f73_ = 0;
        }
    } else if (data_ov004_02171034.unknown_3_ == 2) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->unknown_c_ &= ~8;
        mode = 2;
        sub = 0;
        msg = 0x12d;
        func_ov004_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 2; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->inline_ov004_0216c810_7(5);
            node->inline_ov004_0216c810_21(5);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x33);
        if (node) {
            node->inline_ov004_0216c810_7(0xa);
            node->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.unknown_3_ == 3) {
        mode = 3;
        msg = 0x12c;
        func_ov004_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        func_ov004_0216b2c8(a, msg, 0x32, sub);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->inline_ov004_0216c810_7(8);
            node->inline_ov004_0216c810_21(8);
        }
    } else if (data_ov004_02171034.unknown_3_ == 4) {
        func_02012028(gs, 0);
        func_ov011_021848a0(a, 0x190);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 5) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->unknown_c_ &= ~8;
        mode = 1;
        sub = 0;
        msg = 0x12e;
        func_ov004_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 3; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->inline_ov004_0216c810_7(0);
            node->inline_ov004_0216c810_21(0);
        }
        func_ov004_0216b20c(a, 0x33, 0x96, 0);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x34);
        if (node) {
            node->inline_ov004_0216c810_7(0xa);
            node->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.unknown_3_ == 6) {
        func_02012028(gs, 0);
        void* list = func_ov011_021849c8(a);
        Struct_ov004_0216c810_3* box = func_ov023_021f6880(list, 1);
        if (box == 0) return 0;
        if (func_ov023_021f6f10(box) != 0xb) return 0;
        box->unknown_c_ |= 8;
        Struct_ov004_0216c810_3* text = func_ov023_021f6880(list, 0x192);
        if (text == 0) return 0;
        if (func_ov023_021f6f10(text) != 4) return 0;
        struct TableA68* table = func_ov023_021fa598(text);
        MessageWindow0216c810* win = MessageSystem_GetInstance();
        win->busy = 1;
        func_0204500c(win, func_02072a68(table, 0x5dc), 0, 0xe3);
        win->unknown_19ca_ = 0;
        win->unknown_19af_ = 0;
        func_02012028(gs, 0);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 7) {
        func_02012028(gs, 0);
        func_ov011_021848a0(a, 0x258);
        return 0;
    }

    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)a);
    int y;
    void* panel = func_ov004_0216ae9c(a, 0xd2);
    func_ov023_021f8120(panel);
    y = 0x60;
    unsigned char kind = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    Struct_ov004_02170174 rows = data_ov004_02170174;
    int n;
    switch (mode) {
    case 0:
        func_ov023_021f7eb8(panel, a, y, 1, 1, 0x12, 5, 0, 1, 0);
        y += 0xb40;
        break;
    case 1:
        switch (sub) {
        case 0:
            n = rows.v[kind];
            func_ov023_021f7eb8(panel, a, y, 1, 1, n, 6, 0, 1, 0);
            y += n * 0xc0;
            break;
        default:
            n = rows.v[kind];
            func_ov023_021f7eb8(panel, a, y, 1, 1, n, 6, 0, 1, 0);
            y += n * 0xc0;
            break;
        }
        break;
    case 2:
        n = rows.v[kind];
        func_ov023_021f7eb8(panel, a, y, 1, 1, n, 5, 0, 1, 0);
        y += n * 0xa0;
        break;
    case 3:
        func_ov023_021f7eb8(panel, a, y, 1, 1, 0xc, 3, 0, 1, 0);
        y += 0xb40;
        break;
    }
    data_ov004_02171034.cursorY = y;
    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)a);
    if (mode == 1 && data_ov004_02171034.unknown_3_ != 5) {
        func_ov004_0216ba70(a);
    }
    return 0;
}
