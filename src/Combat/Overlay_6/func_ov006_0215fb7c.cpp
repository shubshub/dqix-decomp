#include <globaldefs.h>

struct Struct_ov006_02154614;
struct Struct_02081164;
struct Struct_0207fdcc_2;

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

extern "C" void func_0208103c(void* menu, int id, int text);
extern "C" void func_0208108c(void* menu, int id);
extern "C" void func_02081164(Struct_02081164* menu, int id, int flag);
extern "C" void func_020813ec(void* menu, int id);
extern "C" void func_02080c68(void* menu, int id, int value);
extern "C" void func_02080c20(Struct_0207fdcc_2* menu, int id);

// USA: func_ov006_0215fb7c
extern "C" ARM void func_ov006_0215fb7c(Struct_ov006_02157a60* self) {
#if defined(jpn)
    void* menu = *(void**)((char*)self + 0xc);
#else
    void* menu = self->menu_;
#endif
    short text = 0x2f;
    switch (self->unknown_366_)
    {
    case 0x28:
        text = 0x15;
        break;
    case 0x27:
        text = 0x14;
        break;
    }
    switch (self->unknown_368_)
    {
    case 0x48:
        text = 0x1d;
        break;
    case 0x49:
        text = 0x1e;
        break;
    case 0x4a:
        text = 0x1f;
        break;
    case 0x4b:
        text = 0x20;
        break;
    case 0x4c:
        text = 0x21;
        break;
    case 0x4d:
        text = 0x22;
        break;
    case 0x4e:
        text = 0x23;
        break;
    case 0x4f:
        text = 0x24;
        break;
    case 0x50:
        text = 0x25;
        break;
    case 0x51:
        text = 0x26;
        break;
    case 0x52:
        text = 0x27;
        break;
    case 0x53:
        text = 0x28;
        break;
    case 0x40:
        text = 0x17;
        break;
    case 0x41:
        text = 0x18;
        break;
    case 0x42:
        text = 0x19;
        break;
    case 0x43:
        text = 0x1a;
        break;
    case 0x44:
        text = 0x1b;
        break;
    case 0x45:
        text = 0x1c;
        break;
    }
    func_0208103c(menu, 0x59, text);
    func_0208108c(menu, 0x59);
    func_02081164((Struct_02081164*)menu, 0xe, 1);
    func_020813ec(menu, 0xe);
    func_02080c68(menu, 0xe, 2);
    func_02080c20((Struct_0207fdcc_2*)menu, 0xe);
}
