#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov016_0218e800_5 {
    virtual void v0();
    virtual void v1();
    virtual int inline_ov016_0218e800_2(int offset);
    virtual int inline_ov016_0218e800_3(void* buffer, int size);
    virtual int inline_ov016_0218e800_4(void* buffer, int size);
    virtual int inline_ov016_0218e800_5();

    int inline_ov016_0218e800_6() { return position; }

    int unknown_4_;
    int position;
};

struct Stream_0218e800 {
    unsigned char unknown_0_[4];
    unsigned int width;
    unsigned int height;
    unsigned char unknown_c_[0x30];
    void* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
    unsigned char unknown_48_[0x454 - 0x48];
};

struct AudioDecoder {
    unsigned char unknown_0_[0x1cc];
    int mode;
    unsigned char unknown_1d0_[0x8c0 - 0x1d0];
    unsigned char unknown_8c0_[0xc34];
    int state;
};

struct Struct_ov016_0218e800_6 {
    char magic[4];
    signed char tag0;
    signed char unknown_5_;
    unsigned short unknown_6_;
    unsigned int unknown_8_;
    unsigned int width;
    unsigned int height;
    unsigned int unknown_14_;
    unsigned short unknown_18_;
    unsigned short channelCount;
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_;
};

struct Struct_ov016_0218e800 {
    const unsigned char* unknown_0_;
    const unsigned char* unknown_4_;
    unsigned short* dst;
    unsigned int pitch;
    int width;
    int height;
    const unsigned char* field_18;
};

struct Struct_ov016_0218e800_2 {
    Struct_ov016_0218e800_5* file;
    Struct_ov016_0218e800_6 header;
    Stream_0218e800* stream;
    int (*advance)(Stream_0218e800*);
    Struct_ov016_0218e800 target;
    AudioDecoder* audio;
    unsigned char** framesY;
    unsigned char** unknown_60_;
    unsigned int* unknown_64_;
    unsigned char* unknown_68_;
    unsigned char* unknown_6c_;
    unsigned char* buffers[2];
    unsigned int unknown_78_[2];
    int unknown_80_[2];
    unsigned int unknown_88_[2];
    int unknown_90_;
    void* unknown_94_;
    unsigned int unknown_98_;
    unsigned int unknown_9c_;
    unsigned int available;
#if !defined(jpn)
    int unknown_a4_;
#endif
    unsigned int unknown_a8_;
    unsigned int idx[6];
    unsigned int frame;
    unsigned char unknown_c8_[4];
    int unknown_cc_;
    int unknown_d0_;
    int base;
};

extern "C" void* func_ov016_0218bc8c(unsigned int);
extern "C" void* func_ov016_0218fcd4(void);
extern "C" void* func_ov016_0218fd50(void);
extern "C" void* func_ov016_0218fdc0(void);
extern "C" void* func_ov016_0218fe30(void);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, unsigned int size);
extern unsigned char data_ov016_02191d78[];

// USA: func_ov016_0218e800
extern "C" ARM int func_ov016_0218e800(Struct_ov016_0218e800_2* self, Struct_ov016_0218e800_5* file, unsigned int arg2) {
    char var0[2];
    unsigned short var1;
    unsigned int var2;

    self->file = file;
    self->base = file->inline_ov016_0218e800_6();
    if (!self->file->inline_ov016_0218e800_3(&self->header, 0x30)) return 0;

    if (self->header.magic[0] != 'M' || self->header.magic[1] != 'O' || self->header.magic[2] != 'D' ||
        self->header.magic[3] != 'S' || self->header.tag0 != 'N' ||
        (self->header.unknown_5_ != '2' && self->header.unknown_5_ != '3') || self->header.unknown_6_ != 10)
        return 0;

    if (self->header.tag0 == 'N' && self->header.unknown_5_ == '3') {
        do {
            if (!self->file->inline_ov016_0218e800_3(var0, 2)) return 0;
            if (!self->file->inline_ov016_0218e800_3(&var1, 2)) return 0;
            if (!self->file->inline_ov016_0218e800_2(self->file->inline_ov016_0218e800_6() + var1 * 4)) return 0;
        } while (var0[0] != 'H' || var0[1] != 'E');
    }

    if (self->header.unknown_18_ != 0 && self->header.unknown_18_ != 1 && self->header.unknown_18_ != 2
#if !defined(jpn)
        && self->header.unknown_18_ != 3 && self->header.unknown_18_ != 4
#endif
        )
        return 0;

    self->stream = (Stream_0218e800*)func_ov016_0218bc8c(sizeof(Stream_0218e800));
    MIi_CpuClearFast(0, self->stream, sizeof(Stream_0218e800));
    self->advance = (int (*)(Stream_0218e800*))func_ov016_0218fcd4();
    self->stream->unknown_3c_ = func_ov016_0218fd50();
    self->stream->unknown_40_ = data_ov016_02191d78;
    self->stream->unknown_44_ = (unsigned char*)func_ov016_0218fe30() + 0x40;
    self->target.width = self->header.width;
    self->target.height = self->header.height;
    self->target.field_18 = (const unsigned char*)func_ov016_0218fdc0();
    self->stream->width = self->header.width;
    self->stream->height = self->header.height;

    if (self->header.width > 0x100) return 0;
    if (arg2 < 6) return 0;

    self->unknown_a8_ = arg2;
    self->framesY = (unsigned char**)func_ov016_0218bc8c(arg2 * 4);
    if (!self->framesY) return 0;
    self->unknown_60_ = (unsigned char**)func_ov016_0218bc8c(self->unknown_a8_ * 4);
    if (!self->unknown_60_) return 0;

    unsigned int i;
    for (i = 0; i < self->unknown_a8_; i++) {
        self->framesY[i] = (unsigned char*)func_ov016_0218bc8c(self->header.height << 8);
        if (!self->framesY[i]) return 0;
        self->unknown_60_[i] = (unsigned char*)func_ov016_0218bc8c((self->header.height >> 1) << 8);
        if (!self->unknown_60_[i]) return 0;
        MIi_CpuClearFast(0, self->framesY[i], self->header.height << 8);
        VectorizedMemset(self->unknown_60_[i], 0x80, (self->header.height >> 1) << 8);
    }

    self->unknown_64_ = (unsigned int*)func_ov016_0218bc8c(self->unknown_a8_ * 4);
    if (!self->unknown_64_) return 0;

    self->unknown_98_ = 0;
    self->idx[0] = 0;
    for (int k = 1; k < 6; k++) {
        self->idx[k] = self->unknown_a8_ - k;
    }
    self->frame = 0;
    self->available = 0;
    self->unknown_9c_ = 0;

    for (int b = 0; b < 2; b++) {
        self->buffers[b] = (unsigned char*)func_ov016_0218bc8c(self->header.unknown_20_ + 0x400);
        if (!self->buffers[b]) return 0;
    }

    if (self->header.unknown_18_ != 0) {
        self->audio = (AudioDecoder*)func_ov016_0218bc8c(self->header.channelCount * sizeof(AudioDecoder));
        if (!self->audio) return 0;
        MIi_CpuClearFast(0, self->audio, self->header.channelCount * sizeof(AudioDecoder));
    }

    int saved = self->file->inline_ov016_0218e800_6();
    self->file->inline_ov016_0218e800_2(self->header.unknown_28_ + self->base);
    self->unknown_94_ = func_ov016_0218bc8c(self->header.unknown_2c_ << 3);
    if (!self->file->inline_ov016_0218e800_3(self->unknown_94_, self->header.unknown_2c_ << 3)) return 0;
    self->file->inline_ov016_0218e800_2(saved);

    if (self->header.unknown_18_ == 1) {
        int j;
        int var8 = self->file->inline_ov016_0218e800_6();
        self->file->inline_ov016_0218e800_2(self->header.unknown_24_ + self->base);
        for (j = 0; j < self->header.channelCount; j++) {
            if (!self->file->inline_ov016_0218e800_3(self->audio[j].unknown_8c0_, sizeof(self->audio[j].unknown_8c0_))) return 0;
            self->audio[j].state = 2;
        }
        self->file->inline_ov016_0218e800_2(var8);
    } else if (self->header.unknown_18_ == 2) {
        for (int j = 0; j < self->header.channelCount; j++) {
            self->audio[j].mode = 2;
        }
    }

    self->file->inline_ov016_0218e800_3(&var2, 4);
    self->unknown_78_[0] = var2 >> 14;
    self->unknown_88_[0] = var2 & 0x3fff;
    self->unknown_80_[0] = 0;
    self->file->inline_ov016_0218e800_3(self->buffers[0], self->unknown_78_[0] + 4);
    self->unknown_90_ = 1;
    return 1;
}
