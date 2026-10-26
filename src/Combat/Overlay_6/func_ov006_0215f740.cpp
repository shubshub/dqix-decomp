#include <globaldefs.h>

#if defined(jpn)
#define data_ov006_02160030 data_ov006_02161384
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_ov006_02154614;

struct Struct_ov006_02157a60 {
    int unknown_0_;
    char** texts_;
    void* canvasBuffer_;
    void* allocators_;
    Struct_ov006_02154614* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    char subBackground_[0x20];
    char ingredients_[0x28];
    char unknown_9c_[0xc];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    char renderer_[0x54];
    char layout_[0x4c];
    char table_[0xc];
    char menuTexts_[0x18];
    char itemNames_[0xc];
    char results_[4][0x74];
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
    char unknown_3b8_[0x70];
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

struct Struct_ov006_02160030 {
    int sprites_[9];
};

extern "C" short* func_ov006_0215919c(void* self);
extern "C" void func_ov006_02155710(Struct_ov006_02154614* arg0, short item, signed char sprites);

extern "C" const Struct_ov006_02160030 data_ov006_02160030;

// USA: func_ov006_0215f740
extern "C" ARM void func_ov006_0215f740(Struct_ov006_02157a60* self) {
    short* items = func_ov006_0215919c(self);
    if (items == 0)
        return;
    unsigned short position = (unsigned short)(self->page_ * 8);
    position += self->unknown_364_ - 0x64;
    Struct_ov006_02160030 sprites = data_ov006_02160030;
    short category = self->unknown_362_ - 0x5b;
    if (category < 0)
        category = 0;
    if (category > 8)
        category = 8;
    func_ov006_02155710(*(Struct_ov006_02154614**)((char*)self + LOW_REGION(8, 0x10)), items[position], sprites.sprites_[category]);
}
