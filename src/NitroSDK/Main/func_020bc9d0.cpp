#include <globaldefs.h>
#include <NitroSDK/Memory/SignedAllocator.h>
#include <NitroSDK/Interrupts.h>

struct Struct_020bc9d0;

extern "C" void func_020bcbc4(Struct_020bc9d0* stream);
extern "C" int func_020bbeb0();
extern "C" void func_020d2038(int arg0, int format, int buffer, int arg3, int arg4, int length, int volume,
                   int shift, int timer, int arg9);
extern "C" void func_020d1f70(int arg0, int tick, int arg2, int callback, int arg);
extern "C" void func_020bcd20(void* arg);
extern "C" void func_020bcd30(void* stream, int status);

struct Struct_0210fcf4 {
    void* buffer;
    int volume;
};

struct Struct_020bc9d0_2 {
    char link[8];
    char unknown_8_[0xc];
    char unknown_14_[0xc];
    int format;
    int unknown_24_0_ : 1;
    int unknown_24_1_ : 1;
    unsigned long unknown_28_;
    int unknown_2c_;
    void* callback;
    void* unknown_34_;
    int unknown_38_;
    int volume;
    int unknown_40_;
    unsigned long unknown_44_;
    int unknown_48_;
    unsigned char unknown_4c_[16];
};

extern Struct_0210fcf4 data_0210fcf4[16];
extern SignedAllocatorList data_0210fca8;

// USA: func_020bc9d0
extern "C" ARM int func_020bc9d0(Struct_020bc9d0_2* stream, int format, void* buffer, unsigned long arg3,
                                 int timer, int arg5, void* callback, void* arg) {
    Struct_0210fcf4* channel;
    unsigned int samples;
    unsigned int var2;
    int var3;
    int index;

    if (stream->unknown_24_0_)
        func_020bcbc4((Struct_020bc9d0*)stream);

    arg3 /= 32 * arg5 * stream->unknown_48_;
    stream->unknown_28_ = arg3 * arg5 * 32;

    samples = stream->unknown_28_;
    if (format == 1)
        samples >>= 1;
    var2 = timer * samples / arg5;

    stream->unknown_40_ = func_020bbeb0();
    if (stream->unknown_40_ < 0)
        return 0;

    for (index = 0; index < stream->unknown_48_; index++) {
        var3 = stream->unknown_4c_[index];
        channel = &data_0210fcf4[var3];
        channel->buffer = (unsigned char*)buffer + stream->unknown_28_ * index;
        channel->volume = 0;
        func_020d2038(var3, format, (int)channel->buffer, 1, 0, (int)(stream->unknown_28_ >> 2), 127, 0,
                      timer << 5, 64);
    }

    func_020d1f70(stream->unknown_40_, var2, var2, (int)func_020bcd20, (int)stream);
    data_0210fca8.InsertAtEnd((SignedAllocatorHeader*)stream);

    stream->format = format;
    stream->unknown_2c_ = arg5;
    stream->callback = callback;
    stream->unknown_34_ = arg;
    stream->unknown_38_ = 0;
    stream->volume = 0;
    stream->unknown_24_0_ = 1;

    {
        int var5 = DisableIRQInterrupts();
        stream->unknown_2c_ = 1;
        func_020bcd30(stream, 0);
        stream->unknown_2c_ = arg5;
        SetIRQInterruptState(var5);
    }
    return 1;
}
