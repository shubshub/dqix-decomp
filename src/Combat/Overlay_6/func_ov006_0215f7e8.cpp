#include <globaldefs.h>

struct Struct_ov006_02154614;
struct Struct_ov006_02158d50_2;
struct Struct_02080fa8;
struct Struct_0201099c_3;
struct Struct_02080f8c;
struct Struct_02080cc0;
struct Struct_0207fdcc_2;

struct Struct_ov006_021537d0 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0x18];
    Struct_ov006_021537d0* unknown_1c_;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    void* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
    void* unknown_24_;
    void* unknown_28_;
    Struct_ov006_021537d0* unknown_2c_;
    Struct_ov006_021537d0* unknown_30_;
    Struct_ov006_021537d0* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* unknown_44_;
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
    int unknown_54_[0x20 / 4];
    int unknown_74_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int unknown_ac_[0x54 / 4];
#if defined(jpn)
    int unknown_f8_[0x48 / 4];
#else
    int unknown_100_[0x4c / 4];
#endif
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[0xc];
#if defined(jpn)
    char unknown1_170_[0xc];
#endif
    int unknown_17c_[4][0x74 / 4];
    int unknown_34c_;
    int unknown_350_;
    int unknown_354_;
    int unknown_358_;
    short unknown_35c_;
    short unknown_35e_;
    short unknown_360_;
    short unknown_362_;
    short unknown_364_;
    short unknown_366_;
    short unknown_368_;
    short unknown_36a_;
    short unknown_36c_;
    short unknown_36e_;
    short unknown_370_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short unknown_37e_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    unsigned char unknown_38a_;
    unsigned char unknown_38b_;
    unsigned char unknown_38c_[3];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short unknown_394_;
    unsigned char unknown_396_;
    unsigned char unknown_397_;
    unsigned char unknown_398_[3];
    int unknown_39c_;
    int unknown_3a0_;
    int unknown_3a4_;
    unsigned int unknown_3a8_;
    int unknown_3ac_;
    int unknown_3b0_;
    int unknown_3b4_;
    int unknown_3b8_[0x70 / 4];
    int unknown_428_;
    signed char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    unsigned char unknown_433_;
    unsigned char unknown_434_;
};

Recipe* FindNode_02158d50(Obj02158d50* self, short page);
void ClearSublistEntriesFlag1_02080bac(void* menu, int id);
void ClearSublistEntriesFlag2_0208065c(void* menu, int id);
void SetEntryFirstField02080fa8(Container02080fa8* menu, int id, int value);
const char* KeyTable_Get(Container020e0310* texts, int id);
void SetEntryFirstField02080f8c(Container02080f8c* menu, int id, int text);
void SetEntryHighNibble0x13(Container02080cc0* menu, int id, int value);
extern "C" RecipeRecord* func_ov006_02153c6c(void* ingredients, short id);
const char** CallFunc020e52a0_020e5294(void* names, int item);
extern "C" void* memset(void* buffer, int value, unsigned int size);
extern "C" void func_020e4864(const char* source, char* output, int, int, int, int);
void Forward0207f7acObjPlus4Size0x40_020805f4(void* menu, int id);
void AddSublistEntryFlag2_020806b0(void* menu, int id);
void SetEntryFlagById02080b2c(void* menu, int id);
void SetEntryLowNibbleAndElement02080c68(void* menu, int id, int value);
void SetElementFlag0x40_02081ea4(Obj2081* menu, int id, int value);
void SetOrClearEntryFlag0x102081130(void* menu, int id, int value);
extern "C" void func_020813ec(void* menu, int id);

// USA: func_ov006_0215f7e8
extern "C" ARM void func_ov006_0215f7e8(Struct_ov006_02157a60* arg0) {
    Struct_ov006_021537d0* var0 = func_ov006_02158d50((Struct_ov006_02158d50_2*)arg0, arg0->unknown_388_);
    arg0->unknown_30_ = var0;
    if (var0 == 0)
        return;
    self->flags_ &= ~4;
    if (self->pages_ > 1)
        self->flags_ |= 4;
    void* menu = self->menu_;
    ClearSublistEntriesFlag1_02080bac(menu, 9);
    ClearSublistEntriesFlag2_0208065c(menu, 9);
    SetEntryFirstField02080fa8((Container02080fa8*)menu, 0x3a, self->page_ + 1);
    SetEntryFirstField02080fa8((Container02080fa8*)menu, 0x3b, self->pages_);
    Recipe* entry = self->pageStart_;
    const char* unknown = KeyTable_Get((Container020e0310*)self->menuTexts_, 0x25);
    short item = 0x29;
    for (unsigned char i = 0; i < 0x10; i++)
    {
        if (var2 != 0)
        {
            func_02080f8c((Struct_02080f8c*)var1, var4, (int)var3);
            func_02080cc0((Struct_02080cc0*)var1, var4, 3);
            Struct_ov006_021555b0* var6 = func_ov006_02153c6c(arg0->unknown_74_, var2->unknown_0_);
            if (var6 != 0)
            {
                const char* var7 = var3;
#if defined(jpn)
                if (record->made_)
                    text = KeyTable_Get((Container020e0310*)self->itemNames_, entry->item_);
                SetEntryFirstField02080f8c((Container02080f8c*)menu, item, (int)text);
#else
                if (var6->unknown_2_1_)
                {
                    const char** var8 = func_020e5294(arg0->unknown_170_, var2->unknown_2_);
                    if (var8 != 0)
                    {
                        memset(arg0->unknown_4_[var5], 0, 4);
                        func_020e4864(*var8, arg0->unknown_4_[var5], 1, 0, 0, 0);
                        var7 = arg0->unknown_4_[var5];
                    }
                }
                func_02080f8c((Struct_02080f8c*)var1, var4, (int)var7);
                func_020805f4(var1, var4);
#endif
                func_02080cc0((Struct_02080cc0*)var1, var4, 0xf);
            }
            var2 = var2->unknown_1c_;
        }
        else
        {
            func_020806b0(var1, var4);
            func_02080b2c(var1, var4);
        }
        var4++;
    }
    func_02080c68(var1, 9, 0);
    func_02081ea4((Struct_0207fdcc_2*)var1, 9, 0);
    func_02081130(var1, 9, (arg0->unknown_394_ & 4) ? 1 : 0);
    func_020813ec(var1, 9);
}
