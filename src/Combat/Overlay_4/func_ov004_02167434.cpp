#include <globaldefs.h>


struct Struct_ov004_02167434_2 {
    short id;
    unsigned short flags;
    char pad4[4];
    struct Struct_ov004_02167434_2* next;
};

struct Struct_ov004_02167434 {
    char pad0[8];
    struct Struct_ov004_02167434_2* head;
    char unknown_c_[0x3c];
    short unknown_48_;
    short unknown_4a_;
    short count;
    char unknown_4e_[3];
    unsigned char nibbles[1];
};

struct Ctx0205ec34 {
    char pad[0x2cc];
    unsigned char nibbles[1];
};

struct Struct_02065990_3;
struct Struct_02065990_2;

extern "C" short func_ov004_02166684(int a);
extern "C" short func_ov004_021666bc(void* a1, char* outFlag);
extern "C" struct Struct_02065990_3* func_02094d6c(void);
extern "C" struct Ctx0205ec34* Scenario_GetInstance(void);
extern "C" unsigned char func_020965ac(Struct_02065990_3* s, unsigned char idx);
extern "C" int func_02095d30(struct Struct_02065990_3* list, int value, int mode);
extern "C" void func_ov004_02166198(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02165ef4(void* a1);
extern "C" void func_ov004_02166730(void* a1, int a2);
extern "C" void* func_ov004_02165e70(void* a, int key);
extern "C" void func_0208bf28(struct Struct_02065990_2* obj, int value, unsigned char b);
extern "C" void func_ov004_02166bd8(void* a1);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern struct Struct_ov004_02167434* data_ov004_0217101c;
static inline Struct_ov004_02167434* inline_ov004_02167434() {
#if defined(jpn)
    return *(Struct_ov004_02167434**)((char*)&data_ov004_0217101c + 4);
#else
    return data_ov004_0217101c;
#endif
}

extern "C" static inline unsigned char* func_0205d594(struct Ctx0205ec34* c) { return c->nibbles; }

// USA: func_ov004_02167434
extern "C" ARM int func_ov004_02167434(void* a1) {
    short target = func_ov004_02166684((int)a1);
    short id;
    char flag;
    short key = func_ov004_021666bc(a1, &flag);
    struct Struct_02065990_3* table = func_02094d6c();
    struct Ctx0205ec34* ctx = Scenario_GetInstance();
    unsigned char slot = func_020965ac(table, (unsigned char)key);
    func_02095d30(table, slot, 1);

    unsigned char idx = slot >> 1;
    unsigned char* src = func_0205d594(ctx);
    unsigned char mask = (unsigned char)(slot & 1) == 0 ? 0xf0 : 0xf;
    unsigned char saved = src[idx] & ~mask;
    inline_ov004_02167434()->nibbles[idx] &= mask;
    inline_ov004_02167434()->nibbles[idx] |= saved;

    func_ov004_02166198();
    func_ov004_02165f2c();

    struct Struct_ov004_02167434* list = inline_ov004_02167434();
    struct Struct_ov004_02167434_2* node = list->head;
    if (list->count != 0 && node != 0) {
        func_ov004_02165ef4(a1);
        short i = 0;
        while (node != 0 && target != i) {
            if (node->next == 0) {
                break;
            }
            i++;
            node = node->next;
        }
        func_ov004_02166730(a1, node->id);
        unsigned char b = flag;
        id = node->id;
        void* obj = func_ov004_02165e70(a1, 7);
        if (obj != 0) {
            func_0208bf28((struct Struct_02065990_2*)((char*)obj + 0x34), id, b);
        }
        func_ov004_02166bd8(a1);
        func_ov011_021848a0(a1, 0x6c);
    } else {
        unsigned char b = flag;
        void* obj = func_ov004_02165e70(a1, 7);
        if (obj != 0) {
            func_0208bf28((struct Struct_02065990_2*)((char*)obj + 0x34), 9999, b);
        }
        func_ov004_02166bd8(a1);
        if (list->unknown_48_ == 0 && list->unknown_4a_ == 0) {
            func_ov011_021848a0(a1, 0x6b);
        } else {
            func_ov011_021848a0(a1, 0x12c);
        }
    }
    return 0;
}
