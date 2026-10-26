#include <globaldefs.h>

struct Struct_ov016_0218edac;
struct Struct_ov016_0218edac_3 {
    void (*unknown_0_)(Struct_ov016_0218edac*);
    void (*unknown_4_)(Struct_ov016_0218edac*);
    void (*unknown_8_[4])(Struct_ov016_0218edac*);
    void (*close)(Struct_ov016_0218edac*);
};
struct Struct_ov016_0218edac {
    Struct_ov016_0218edac_3* unknown_0_;
};
struct Struct_ov016_0218edac_2 {
    Struct_ov016_0218edac* stream;
    unsigned char unknown_4_[0x30];
    void* unknown_34_;
    unsigned char unknown_38_[0x20];
    void* buffer;
    void** unknown_5c_;
    void** unknown_60_;
    void* parameters;
    void* unknown_68_;
    void* unknown_6c_;
    void* unknown_70_[2];
    unsigned char unknown_78_[0x1c];
    void* scratch;
    #if defined(jpn)
    unsigned char unknown_98_[0xc];
#else
    unsigned char unknown1_98_[0x10];
#endif
    unsigned int capacity;
};
extern "C" void func_ov016_0218bca8(void*);

// USA: func_ov016_0218edac
extern "C" ARM void func_ov016_0218edac(Struct_ov016_0218edac_2* resources) {
    if (resources->stream) {
        resources->stream->unknown_0_->close(resources->stream);
        if (resources->stream) resources->stream->unknown_0_->unknown_4_(resources->stream);
    }
    func_ov016_0218bca8(resources->unknown_34_);
    if (resources->unknown_5c_) {
        unsigned int i = 0;
        if (i < resources->capacity) do {
            func_ov016_0218bca8(resources->unknown_5c_[i]);
            i++;
        } while (i < resources->capacity);
        func_ov016_0218bca8(resources->unknown_5c_);
    }
    if (resources->unknown_60_) {
        unsigned int i = 0;
        if (i < resources->capacity) do {
            func_ov016_0218bca8(resources->unknown_60_[i]);
            i++;
        } while (i < resources->capacity);
        func_ov016_0218bca8(resources->unknown_60_);
    }
    if (resources->parameters) func_ov016_0218bca8(resources->parameters);
    if (resources->unknown_68_) func_ov016_0218bca8(resources->unknown_68_);
    if (resources->unknown_6c_) func_ov016_0218bca8(resources->unknown_6c_);
    int i = 0;
    do {
        if (resources->unknown_70_[i]) func_ov016_0218bca8(resources->unknown_70_[i]);
        resources->unknown_70_[i] = 0;
        i++;
    } while (i < 2);
    if (resources->scratch) func_ov016_0218bca8(resources->scratch);
    if (resources->buffer) func_ov016_0218bca8(resources->buffer);
    resources->stream = 0;
    resources->unknown_5c_ = 0;
    resources->unknown_60_ = 0;
    resources->unknown_68_ = 0;
    resources->unknown_6c_ = 0;
    resources->parameters = 0;
    resources->buffer = 0;
    resources->scratch = 0;
}
