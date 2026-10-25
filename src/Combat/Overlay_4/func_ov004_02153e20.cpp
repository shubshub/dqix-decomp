#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>


struct Struct_ov004_02153e20;

struct Struct_ov004_02153e20_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    unsigned int unknown_c_;
};

struct Struct_ov004_02153e20_3 {
    Struct_ov004_02153e20_3* unknown_0_;
    Struct_ov004_02153e20_2* unknown_4_;
};

struct Struct_ov004_02153e20_4 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

struct Struct_ov004_02153e20_5 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    int unknown_20_;
};

struct Struct_ov004_02153e20_6 {
    char unknown_0_[0x104];
    short unknown_104_;
    short unknown_106_;
};

class Struct_ov004_02153e20_7 {
public:
    virtual void inline_ov004_02153e20(); virtual void inline_ov004_02153e20_2(); virtual void inline_ov004_02153e20_3(); virtual void inline_ov004_02153e20_4();
    virtual void inline_ov004_02153e20_5(); virtual void inline_ov004_02153e20_6(); virtual void inline_ov004_02153e20_7(); virtual void inline_ov004_02153e20_8();
    virtual void inline_ov004_02153e20_9(); virtual void inline_ov004_02153e20_10(); virtual void inline_ov004_02153e20_11(); virtual void inline_ov004_02153e20_12();
    virtual void inline_ov004_02153e20_13(); virtual void inline_ov004_02153e20_14(); virtual void inline_ov004_02153e20_15(); virtual void inline_ov004_02153e20_16();
    virtual void inline_ov004_02153e20_17(); virtual void inline_ov004_02153e20_18(); virtual void inline_ov004_02153e20_19(); virtual void inline_ov004_02153e20_20();
    virtual void inline_ov004_02153e20_21(); virtual void inline_ov004_02153e20_22(); virtual void inline_ov004_02153e20_23(); virtual void inline_ov004_02153e20_24();
    virtual void inline_ov004_02153e20_25(); virtual void inline_ov004_02153e20_26(); virtual void inline_ov004_02153e20_27(); virtual void inline_ov004_02153e20_28();
    virtual void inline_ov004_02153e20_29(); virtual void inline_ov004_02153e20_30(); virtual void inline_ov004_02153e20_31(); virtual void inline_ov004_02153e20_32();
    virtual void inline_ov004_02153e20_33(); virtual void inline_ov004_02153e20_34(); virtual void inline_ov004_02153e20_35(); virtual void inline_ov004_02153e20_36();
    virtual void inline_ov004_02153e20_37(); virtual void inline_ov004_02153e20_38(); virtual void inline_ov004_02153e20_39(); virtual void inline_ov004_02153e20_40();
    virtual void inline_ov004_02153e20_41(); virtual void inline_ov004_02153e20_42(); virtual void inline_ov004_02153e20_43(); virtual void inline_ov004_02153e20_44();
    virtual void inline_ov004_02153e20_45(); virtual void inline_ov004_02153e20_46(); virtual void inline_ov004_02153e20_47(); virtual void inline_ov004_02153e20_48();
    virtual void inline_ov004_02153e20_49(); virtual void inline_ov004_02153e20_50(); virtual void inline_ov004_02153e20_51(); virtual void inline_ov004_02153e20_52();
    virtual void inline_ov004_02153e20_53(); virtual void inline_ov004_02153e20_54(); virtual void inline_ov004_02153e20_55(); virtual void inline_ov004_02153e20_56();
    virtual void inline_ov004_02153e20_57(); virtual void inline_ov004_02153e20_58(); virtual void inline_ov004_02153e20_59();
    virtual Struct_ov004_02153e20_3** inline_ov004_02153e20_60();
};

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_ov023_021f9d14(void* grid, void* ctx);
extern "C" void func_ov023_021f809c(void* obj, void* ctx);
int CheckType16ThenTestBit_02153d8c(void* ctx);

// USA: func_ov004_02153e20
extern "C" ARM int func_ov004_02153e20(void* ctx) {
    void* list = func_ov011_021849c8(ctx);
    short x, y;
    Board02153e20* board = (Board02153e20*)func_ov023_021f6880(list, 0x2c);
    if (!board) return 0;
    if (func_ov023_021f6f10(board) != 7) return 0;
    x = board->x;
    y = board->y;
    ListOwner02153e20* owner = (ListOwner02153e20*)func_ov023_021f6880(list, 0x39);
    if (!owner) return 0;
    if (func_ov023_021f6f10(owner) != 0x12) return 0;
    ListNode02153e20** head = owner->GetList();
    if (!head) return 0;
    ListNode02153e20* node = *head;
    if (!node) return 0;
    unsigned char* flags = Scenario_GetInstance();

    short var8 = var1 * 16;
    short var9 = 0;
    while (var6) {
        if (var9 == var8) break;
        var9++;
        var6 = var6->unknown_0_;
    }

    for (short var10 = 0; var10 < 16; var10++) {
        int var11 = var10 + 0x1a;
        Struct_ov004_02153e20_5* var12 = (Struct_ov004_02153e20_5*)func_ov023_021f6880(var0, var11);
        if (var12 && func_ov023_021f6f10(var12) == 8) {
            var12->unknown_20_ = 0;
            var12->unknown_c_ &= ~8;
            if (!var6) {
                func_ov023_021f9b30((Struct_ov004_02153e20*)var3, 0, (unsigned short)(var10 >> 1), (unsigned short)(var10 & 1));
                var12->unknown_c_ |= 8;
            } else {
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)board, (unsigned short)id, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                Entry02153e20* entry = node->entry;
                if (entry) {
                    int bits = (unsigned short)((entry->flags << 9) >> 21);
                    if (bits > 0) {
                        if (Scenario_TestFlag((int)flags, flags + 0x8c, bits + 0x76 + 0xc00)) {
                            slot->value = entry->value;
                        }
                    }
                }
                var6 = var6->unknown_0_;
            }
        }
    }

    func_ov023_021f9d14(var3, arg0);
    Struct_ov004_02153e20_6* var15 = (Struct_ov004_02153e20_6*)func_ov023_021f6880(var0, 3);
    if (!var15) return 0;
    if (func_ov023_021f6f10(var15) != 6) return 0;
    var15->unknown_104_ = var1;
    var15->unknown_106_ = var2;
    func_ov023_021f809c(var15, arg0);
    func_ov004_02153d8c(arg0);
    return 0;
}
