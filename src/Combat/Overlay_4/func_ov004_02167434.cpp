#include <globaldefs.h>


struct Struct_ov004_02167434_2 {
    short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[4];
    struct Struct_ov004_02167434_2* unknown_8_;
};

struct Struct_ov004_02167434 {
    char unknown_0_[8];
    struct Struct_ov004_02167434_2* unknown_8_;
    char unknown_c_[0x3c];
    short unknown_48_;
    short unknown_4a_;
    short unknown_4c_;
    char unknown_4e_[3];
    unsigned char unknown_51_[1];
};

struct Struct_0205d594 {
    char unknown_0_[0x2cc];
    unsigned char unknown_2cc_[1];
};

struct Struct_02065990_3;
struct Struct_02065990_2;

short GetScaledFieldValue_02166684(int a);
extern "C" short func_ov004_021666bc(void* a1, char* outFlag);
struct GetTableByteOrFFData* GetGlobal02109418_02094d6c(void);
extern "C" struct Ctx0205ec34* Scenario_GetInstance(void);
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData* s, unsigned char idx);
extern "C" int func_02095d30(struct GetTableByteOrFFData* list, int value, int mode);
extern "C" void func_ov004_02166198(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02165ef4(void* arg0);
extern "C" void func_ov004_02166730(void* arg0, int arg1);
extern "C" void* func_ov004_02165e70(void* arg0, int arg1);
extern "C" void func_0208bf28(struct Struct_02065990_2* arg0, int arg1, unsigned char arg2);
extern "C" void func_ov004_02166bd8(void* arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);

extern struct Struct_ov004_02167434* data_ov004_0217101c;
static inline Struct_ov004_02167434* inline_ov004_02167434() {
#if defined(jpn)
    return *(Struct_ov004_02167434**)((char*)&data_ov004_0217101c + 4);
#else
    return data_ov004_0217101c;
#endif
}

extern "C" static inline unsigned char* func_0205d594(struct Struct_0205d594* arg0) { return arg0->unknown_2cc_; }

// USA: func_ov004_02167434
extern "C" ARM int func_ov004_02167434(void* a1) {
    short target = GetScaledFieldValue_02166684((int)a1);
    short id;
    char flag;
    short key = func_ov004_021666bc(a1, &flag);
    struct GetTableByteOrFFData* table = GetGlobal02109418_02094d6c();
    struct Ctx0205ec34* ctx = Scenario_GetInstance();
    unsigned char slot = GetTableByteOrFF_020965ac(table, (unsigned char)key);
    func_02095d30(table, slot, 1);

    unsigned char var7 = var6 >> 1;
    unsigned char* var8 = func_0205d594(var5);
    unsigned char var9 = (unsigned char)(var6 & 1) == 0 ? 0xf0 : 0xf;
    unsigned char var10 = var8[var7] & ~var9;
    inline_ov004_02167434()->unknown_51_[var7] &= var9;
    inline_ov004_02167434()->unknown_51_[var7] |= var10;

    func_ov004_02166198();
    func_ov004_02165f2c();

    struct Struct_ov004_02167434* var11 = inline_ov004_02167434();
    struct Struct_ov004_02167434_2* var12 = var11->unknown_8_;
    if (var11->unknown_4c_ != 0 && var12 != 0) {
        func_ov004_02165ef4(arg0);
        short var13 = 0;
        while (var12 != 0 && var0 != var13) {
            if (var12->unknown_8_ == 0) {
                break;
            }
            var13++;
            var12 = var12->unknown_8_;
        }
        func_ov004_02166730(arg0, var12->unknown_0_);
        unsigned char var14 = var2;
        var1 = var12->unknown_0_;
        void* var15 = func_ov004_02165e70(arg0, 7);
        if (var15 != 0) {
            func_0208bf28((struct Struct_02065990_2*)((char*)var15 + 0x34), var1, var14);
        }
        func_ov004_02166bd8(arg0);
        func_ov011_021848a0(arg0, 0x6c);
    } else {
        unsigned char var16 = var2;
        void* var17 = func_ov004_02165e70(arg0, 7);
        if (var17 != 0) {
            func_0208bf28((struct Struct_02065990_2*)((char*)var17 + 0x34), 9999, var16);
        }
        func_ov004_02166bd8(arg0);
        if (var11->unknown_48_ == 0 && var11->unknown_4a_ == 0) {
            func_ov011_021848a0(arg0, 0x6b);
        } else {
            func_ov011_021848a0(arg0, 0x12c);
        }
    }
    return 0;
}
