#include <globaldefs.h>

struct Struct_ov006_02154614;
struct Struct_ov006_02158d50_2;
struct Struct_02080fa8;
struct Container020e0310;
struct Container02080f8c;
struct Struct_02080cc0;
struct Struct_0207fdcc_2;

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    char unk_4[0x18];
    Struct_ov006_021537d0* unknown_1c_;
};

struct Struct_ov006_021555b0 {
    short id_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    void* canvasBuffer_;
    void* allocators_;
    Struct_ov006_02154614* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    Struct_ov006_021537d0* unknown_2c_;
    Struct_ov006_021537d0* unknown_30_;
    Struct_ov006_021537d0* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int renderer_[0x54 / 4];
#if defined(jpn)
    int layout_[0x48 / 4];
#else
    int layout_[0x4c / 4];
#endif
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
#if defined(jpn)
    char unknown1_170_[0xc];
#endif
    int results_[4][0x74 / 4];
    int ticks_;
    int menuResult_;
    int task_;
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
    short item_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short message_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    unsigned char unknown_38c_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short flags_;
    unsigned char female_;
    unsigned char background_;
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

extern "C" Struct_ov006_021537d0* func_ov006_02158d50(Struct_ov006_02158d50_2* self, short page);
extern "C" void func_02080bac(void* menu, int id);
extern "C" void func_0208065c(void* menu, int id);
extern "C" void func_02080fa8(Struct_02080fa8* menu, int id, int value);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void func_02080f8c(Container02080f8c* menu, int id, int text);
extern "C" void func_02080cc0(Struct_02080cc0* menu, int id, int value);
extern "C" Struct_ov006_021555b0* func_ov006_02153c6c(void* ingredients, short id);
extern "C" const char** func_020e5294(void* names, int item);
extern "C" void* memset(void* buffer, int value, unsigned int size);
extern "C" void func_020e4864(const char* source, char* output, int, int, int, int);
extern "C" void func_020805f4(void* menu, int id);
extern "C" void func_020806b0(void* menu, int id);
extern "C" void func_02080b2c(void* menu, int id);
extern "C" void func_02080c68(void* menu, int id, int value);
extern "C" void func_02081ea4(Struct_0207fdcc_2* menu, int id, int value);
extern "C" void func_02081130(void* menu, int id, int value);
extern "C" void func_020813ec(void* menu, int id);

// USA: func_ov006_0215f7e8
extern "C" ARM void func_ov006_0215f7e8(Struct_ov006_02157a60* self) {
    Struct_ov006_021537d0* var0 = func_ov006_02158d50((Struct_ov006_02158d50_2*)self, self->page_);
    self->unknown_30_ = var0;
    if (var0 == 0)
        return;
    self->flags_ &= ~4;
    if (self->pages_ > 1)
        self->flags_ |= 4;
    void* menu = self->menu_;
    func_02080bac(menu, 9);
    func_0208065c(menu, 9);
    func_02080fa8((Struct_02080fa8*)menu, 0x3a, self->page_ + 1);
    func_02080fa8((Struct_02080fa8*)menu, 0x3b, self->pages_);
    Struct_ov006_021537d0* entry = self->unknown_30_;
    const char* unknown = KeyTable_Get((Container020e0310*)self->menuTexts_, 0x25);
    short item = 0x29;
    for (unsigned char i = 0; i < 0x10; i++)
    {
        if (entry != 0)
        {
            func_02080f8c((Container02080f8c*)menu, item, (int)unknown);
            func_02080cc0((Struct_02080cc0*)menu, item, 3);
            Struct_ov006_021555b0* record = func_ov006_02153c6c(self->ingredients_, entry->id_);
            if (record != 0)
            {
                const char* text = unknown;
#if defined(jpn)
                if (record->unknown_2_1_)
                    text = KeyTable_Get((Container020e0310*)self->itemNames_, entry->item_);
                func_02080f8c((Container02080f8c*)menu, item, (int)text);
#else
                if (record->unknown_2_1_)
                {
                    const char** name = func_020e5294(self->itemNames_, entry->item_);
                    if (name != 0)
                    {
                        memset(self->texts_[i], 0, 4);
                        func_020e4864(*name, self->texts_[i], 1, 0, 0, 0);
                        text = self->texts_[i];
                    }
                }
                func_02080f8c((Container02080f8c*)menu, item, (int)text);
                func_020805f4(menu, item);
#endif
                func_02080cc0((Struct_02080cc0*)menu, item, 0xf);
            }
            entry = entry->unknown_1c_;
        }
        else
        {
            func_020806b0(menu, item);
            func_02080b2c(menu, item);
        }
        item++;
    }
    func_02080c68(menu, 9, 0);
    func_02081ea4((Struct_0207fdcc_2*)menu, 9, 0);
    func_02081130(menu, 9, (self->flags_ & 4) ? 1 : 0);
    func_020813ec(menu, 9);
}
