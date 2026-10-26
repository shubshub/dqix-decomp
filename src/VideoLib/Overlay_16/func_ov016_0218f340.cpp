#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

struct Struct_ov016_0218f340_2 {
    unsigned char* input;
    void* output;
    unsigned char state[0x14f0];
};
struct Struct_ov016_0218f340 {
    unsigned char unknown_0_[0x1c];
    unsigned short format;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x14];
    unsigned char** input;
    unsigned char unknown_38_[0x20];
    Struct_ov016_0218f340_2* unknown_58_;
    unsigned char field_0x5c[0x48];
#if !defined(jpn)
    int reset;
#endif
    unsigned char unknown_a8_[0x20];
    int available;
    int unknown_cc_;
    int frame;
};
extern "C" int func_ov016_0219000c(Struct_ov016_0218f340_2*);
extern "C" void func_ov016_021909cc_unk(Struct_ov016_0218f340_2*);
extern "C" void func_ov016_0218fea0(Struct_ov016_0218f340_2*, unsigned char*);
extern "C" void func_ov016_0218feb4(Struct_ov016_0218f340_2*, unsigned char*, int, void*);
extern "C" void func_020ca3b8(void*, void*, int);

// USA: func_ov016_0218f340
extern "C" ARM int func_ov016_0218f340(Struct_ov016_0218f340* stream, void* output) {
    if (stream->unknown_cc_ == stream->available) return 0;
    if (stream->format == 0) return 0;
    if (stream->format == 1) {
        stream->unknown_58_[stream->frame].input = *stream->input;
        stream->unknown_58_[stream->frame].output = output;
        *stream->input += func_ov016_0219000c(&stream->unknown_58_[stream->frame]);
    } else
#if !defined(jpn)
    if (stream->format == 2)
#endif
    {
        stream->unknown_58_[stream->frame].input = *stream->input;
        stream->unknown_58_[stream->frame].output = output;
        func_ov016_021909cc_unk(&stream->unknown_58_[stream->frame]);
        *stream->input += 0x28;
    }
#if !defined(jpn)
    else if (stream->format == 3) {
        if (stream->reset == 1) {
            func_ov016_0218fea0(&stream->unknown_58_[stream->frame], *stream->input);
            *stream->input += 4;
        }
        func_ov016_0218feb4(&stream->unknown_58_[stream->frame], *stream->input, 0x80, output);
        *stream->input += 0x80;
    } else {
        func_020ca3b8(*stream->input, output, 0x200);
        *stream->input += 0x200;
    }
#endif
    if (++stream->frame == stream->unknown_1e_) {
        stream->frame = 0;
#if !defined(jpn)
        stream->reset = 0;
#endif
    }
    ++stream->unknown_cc_;
    return 1;
}
