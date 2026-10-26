#include <globaldefs.h>

extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" void OS_GetMacAddress(void* dst);
extern "C" int func_020c7170(char*, unsigned long, const char*, ...);
extern "C" void func_ov031_0223dd60(void*, const void*, int);
extern "C" void func_ov031_0223c980(void* obj, int a, int b, int c, int d, int e, int f, void* g);
extern "C" void func_ov031_0221ae00(void* buf);
extern "C" void func_ov031_0223caec(void* ptr);

extern const char data_ov031_0224b8ac[];
extern const char data_ov031_0224b8cc[];
extern const char data_ov031_0224b8e0[];

struct Struct_ov031_02228c60 {
    unsigned long long first;
    unsigned long long second;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

// USA: func_ov031_02228c60
extern "C" ARM void func_ov031_02228c60(void) {
    void* obj;
    Struct_ov031_02228c60 settings;
    unsigned long long value;
    unsigned int parts[4];
    int i;
    unsigned short text[20];
    char buf[20];
    unsigned char mac[6] __attribute__((aligned(4)));

    obj = func_ov031_0223c560(0, 0);
    OS_GetMacAddress(mac);
    func_020c7170(buf, 20, data_ov031_0224b8ac, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    func_ov031_0223dd60(text, buf, 20);
    func_ov031_0223c980(obj, 8, 0x40, 0xf0, 0x1c, 2, 0x480, text);

    func_ov031_0221ae00(&settings);
    value = settings.first;
    if (value != 0) {
        parts[3] = (value % 10) * 1000;
        value /= 10;
        i = 0;
        do {
            parts[2 - i] = value % 10000;
            value /= 10000;
            i++;
        } while (i < 3);
        func_020c7170(buf, 20, data_ov031_0224b8cc, parts[0], parts[1], parts[2], parts[3]);
        func_ov031_0223dd60(text, buf, 20);
    } else {
        func_020c7170(buf, 20, data_ov031_0224b8e0);
        func_ov031_0223dd60(text, buf, 20);
    }
    func_ov031_0223c980(obj, 8, 0x78, 0xf0, 0x1c, 2, 0x480, text);
    func_ov031_0223caec(obj);
}
