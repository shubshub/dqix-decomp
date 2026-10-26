#include <globaldefs.h>

struct Struct_ov031_02249408 {
    char unknown_0_[2];
    char separator;
    char unknown_3_;
    unsigned char unknown_4_[9];
};

struct Struct_ov031_02290e4c {
    int type;
    int area;
    char unknown_8_[10];
    char ssid[33];
    unsigned char address[6];
    unsigned char unknown_39_[3];
};

extern Struct_ov031_02249408 data_ov031_02249408;
Struct_ov031_02290e4c data_ov031_02290e4c;
extern "C" int func_ov031_02212274(void* object);
extern "C" void func_ov031_0223fb98(char* destination, unsigned int value);
extern "C" void func_ov031_0223fb74(void* destination, const void* source, unsigned int size);
extern "C" int func_ov031_0223e454(unsigned char* destination, const signed char* source, int size);

// USA: func_ov031_0223e8d4
extern "C" ARM int func_ov031_0223e8d4(unsigned char* destination) {
    Struct_ov031_02249408 packet = data_ov031_02249408;
    if (func_ov031_02212274(&data_ov031_02290e4c)) {
        int value = data_ov031_02290e4c.type;
        if (value >= 0 && value < 10)
            packet.unknown_0_[1] = value + '0';
        else if (value >= 10 && value < 100)
            func_ov031_0223fb98(packet.unknown_0_, value);
        if (data_ov031_02290e4c.type == 4 || data_ov031_02290e4c.type == 8) {
            value = data_ov031_02290e4c.area;
            if (value >= 0 && value < 10)
                packet.unknown_3_ = value + '0';
            func_ov031_0223fb74(packet.unknown_4_, data_ov031_02290e4c.unknown_8_, 9);
        }
        func_ov031_0223e454(destination, (const signed char*)&packet, sizeof(packet));
        return 1;
    }
    return 0;
}
