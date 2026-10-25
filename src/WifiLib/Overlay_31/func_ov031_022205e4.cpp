#include <globaldefs.h>

#if defined(jpn)
#define data_ov031_0224b1d4 data_ov031_0224bdd4
#define data_ov031_0224fb20 data_ov031_02250720
#endif

struct Struct_ov031_0224fb18 {
    unsigned char unknown_0_[6];
};
struct Struct_ov031_0224b1d4 {
    unsigned char unknown_0_[4];
};
struct Struct_ov031_022205e4 {
    Struct_ov031_0224fb18 unknown_0_;
    Struct_ov031_0224fb18 unknown_6_;
    Struct_ov031_0224b1d4 unknown_c_;
};
struct Struct_ov031_0224b114_2 {
    int unknown_0_;
    int unknown_4_;
};
extern InternetAddress data_ov031_0224b1d4 __attribute__((aligned(4)));
extern HardwareAddress data_ov031_0224fb20;
extern HardwareAddress data_ov031_0224fb18;
extern AddressDebug data_ov031_0224b114;
extern "C" int func_ov031_022205d8(void* address);
extern "C" int memcmp(const void* first, const void* second, unsigned int size);
extern "C" void func_ov031_022228f4(char* destination, const HardwareAddress* address);

#define COPY_ADDRESS(destination, source) do { \
    Struct_ov031_0224fb18* targetAddress = &(destination); \
    const Struct_ov031_0224fb18* sourceAddress = &(source); \
    targetAddress->unknown_0_[0] = sourceAddress->unknown_0_[0]; \
    targetAddress->unknown_0_[1] = sourceAddress->unknown_0_[1]; \
    targetAddress->unknown_0_[2] = sourceAddress->unknown_0_[2]; \
    targetAddress->unknown_0_[3] = sourceAddress->unknown_0_[3]; \
    targetAddress->unknown_0_[4] = sourceAddress->unknown_0_[4]; \
    targetAddress->unknown_0_[5] = sourceAddress->unknown_0_[5]; \
} while (0)

// USA: func_ov031_022205e4
// KEEP-NAME: func_ov031_022205e4
extern "C" THUMB int func_ov031_022205e4(AddressPair* output) {
    char firstText[32];
    char secondText[32];
    HardwareAddress addresses[2];
    unsigned char* network = output->network.bytes;
    const unsigned char* sourceNetwork = data_ov031_0224b1d4.bytes;
    network[0] = sourceNetwork[0];
    network[1] = sourceNetwork[1];
    network[2] = sourceNetwork[2];
    network[3] = sourceNetwork[3];
    COPY_ADDRESS(addresses[1], data_ov031_0224fb20);
    addresses[1].bytes[0] &= 0xfd;
    func_ov031_022205d8(&addresses[0]);
    const HardwareAddress* primary = &addresses[0];
    COPY_ADDRESS(data_ov031_0224fb18, *primary);
    const HardwareAddress* second;
    if (memcmp(&addresses[1], primary, 6) <= 0) {
        COPY_ADDRESS(output->first, addresses[0]);
        second = &addresses[1];
    } else {
        COPY_ADDRESS(arg0->unknown_0_, var2[1]);
        var6 = &var2[0];
    }
    COPY_ADDRESS(arg0->unknown_6_, *var6);
    if (data_ov031_0224b114.unknown_4_) {
        func_ov031_022228f4(var0, &var2[0]);
        func_ov031_022228f4(var1, &var2[1]);
    }
    return 1;
}
