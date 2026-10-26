#include <globaldefs.h>

#if defined(jpn)
#define data_ov031_0224b1d4 data_ov031_0224bdd4
#define data_ov031_0224fb20 data_ov031_02250720
#endif

struct Struct_ov031_0224fb18 {
    unsigned char bytes[6];
};
struct Struct_ov031_0224b1d4 {
    unsigned char bytes[4];
};
struct Struct_ov031_022205e4 {
    Struct_ov031_0224fb18 first;
    Struct_ov031_0224fb18 second;
    Struct_ov031_0224b1d4 unknown_c_;
};
struct Struct_ov031_0224b114_2 {
    int field_0x0;
    int enabled;
};
extern Struct_ov031_0224b1d4 data_ov031_0224b1d4 __attribute__((aligned(4)));
extern Struct_ov031_0224fb18 data_ov031_0224fb20;
extern Struct_ov031_0224fb18 data_ov031_0224fb18;
extern Struct_ov031_0224b114_2 data_ov031_0224b114;
extern "C" int func_ov031_022205d8(void* address);
extern "C" int memcmp(const void* first, const void* second, unsigned int size);
extern "C" void func_ov031_022228f4(char* destination, const Struct_ov031_0224fb18* address);

#define COPY_ADDRESS(destination, source) do { \
    Struct_ov031_0224fb18* targetAddress = &(destination); \
    const Struct_ov031_0224fb18* sourceAddress = &(source); \
    targetAddress->bytes[0] = sourceAddress->bytes[0]; \
    targetAddress->bytes[1] = sourceAddress->bytes[1]; \
    targetAddress->bytes[2] = sourceAddress->bytes[2]; \
    targetAddress->bytes[3] = sourceAddress->bytes[3]; \
    targetAddress->bytes[4] = sourceAddress->bytes[4]; \
    targetAddress->bytes[5] = sourceAddress->bytes[5]; \
} while (0)

// USA: func_ov031_022205e4
// KEEP-NAME: func_ov031_022205e4
extern "C" THUMB int func_ov031_022205e4(Struct_ov031_022205e4* output) {
    char firstText[32];
    char var1[32];
    Struct_ov031_0224fb18 addresses[2];
    unsigned char* var3 = output->unknown_c_.bytes;
    const unsigned char* var4 = data_ov031_0224b1d4.bytes;
    var3[0] = var4[0];
    var3[1] = var4[1];
    var3[2] = var4[2];
    var3[3] = var4[3];
    COPY_ADDRESS(addresses[1], data_ov031_0224fb20);
    addresses[1].bytes[0] &= 0xfd;
    func_ov031_022205d8(&addresses[0]);
    const Struct_ov031_0224fb18* primary = &addresses[0];
    COPY_ADDRESS(data_ov031_0224fb18, *primary);
    const Struct_ov031_0224fb18* second;
    if (memcmp(&addresses[1], primary, 6) <= 0) {
        COPY_ADDRESS(output->first, addresses[0]);
        second = &addresses[1];
    } else {
        COPY_ADDRESS(output->first, addresses[1]);
        second = &addresses[0];
    }
    COPY_ADDRESS(output->second, *second);
    if (data_ov031_0224b114.enabled) {
        func_ov031_022228f4(firstText, &addresses[0]);
        func_ov031_022228f4(var1, &addresses[1]);
    }
    return 1;
}
