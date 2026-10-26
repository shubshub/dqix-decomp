#include <globaldefs.h>


#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

extern "C" void* func_020d41d8(void);
extern "C" int func_020d41e8(void);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d4168(void* a, unsigned int b);
extern "C" void func_020ca3ec(int val, void* dst, int size);
extern "C" void func_020ca408(void* src, void* dst, int size);

struct Struct_020d5900 {
    unsigned short tag;
    unsigned char pad[2];
    unsigned char payload[0x1c];
};

// USA: func_020d5900
extern "C" ARM int func_020d5900(int value, void* data) {
    func_020d41d8();
    int state = func_020d41e8();
    if (state != 0) return state;
    func_020d404c(0x23, value);
    struct Struct_020d5900 buf;
    func_020ca3ec(0, &buf, 0x20);
    buf.tag = 0x23;
    func_020ca408(data, buf.payload, 0x1c);
    int r = func_020d4168(&buf, 0x20);
    return (r == 0) ? 2 : r;
}
