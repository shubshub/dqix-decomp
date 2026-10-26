#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_0218048c_7538 = 0x1faa };
#else
enum { Enum_ov000_0218048c_7538 = 0x1d72 };
#endif

struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Entry_0205d6a0;

extern "C" void Window_ClearLayers(struct Cont0205d1e0*);
extern "C" void Window_FlushLayers(struct Cont0205d274*);
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void Window_ClosePane(struct Entry_0205d6a0*, int);
extern "C" void func_ov000_02174b14(void* obj);

struct Struct_ov000_0218048c {
    char pad0[0x24];
    unsigned char unknown_24_;
    char pad1[0x4c - 0x25];
    int unknown_4c_;
#if defined(jpn)
    char pad2[0x488 - 0x50];
#else
    char pad2[0x448 - 0x50];
#endif
};

// USA: func_ov000_0218048c
extern "C" ARM void func_ov000_0218048c(char* obj) {
    int idx;
    Window_ClearLayers((struct Cont0205d1e0*)(obj + 0x188));
    Window_FlushLayers((struct Cont0205d274*)(obj + 0x188));
    Window_TransferLayers((struct Obj0205d2bc*)(obj + 0x188));
    Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x188), 1);
    for (idx = 0; idx < 4; idx++) {
        signed char e = *(signed char*)(obj + idx + 0x6c);
        struct Struct_ov000_0218048c* entry = (struct Struct_ov000_0218048c*)(obj + 0x958) + e;
        if (entry->unknown_24_ & 0x2) {
            entry->unknown_24_ |= 0x4;
            *(int*)(obj + 0x17c) = entry->unknown_4c_;
        }
    }
    *(unsigned short*)(obj + Enum_ov000_0218048c_7538) &= ~0x8;
    *(int*)(obj + 0x914) = 0;
    *(int*)(obj + 0x910) = 0;
    func_ov000_02174b14(obj);
}
