#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov016_0218e800_5 {
    virtual void inline_ov016_0218e800_7();
    virtual void inline_ov016_0218e800();
    virtual int inline_ov016_0218e800_2(int arg0);
    virtual int inline_ov016_0218e800_3(void* arg0, int arg1);
    virtual int inline_ov016_0218e800_4(void* arg0, int arg1);
    virtual int inline_ov016_0218e800_5();

    int inline_ov016_0218e800_6() { return unknown_8_; }

    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov016_0218e800_3 {
    unsigned char unknown_0_[4];
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned char unknown_c_[0x30];
    void* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
    unsigned char unknown_48_[0x454 - 0x48];
};

struct Struct_ov016_0218e800_4 {
    unsigned char unknown_0_[0x1cc];
    int unknown_1cc_;
    unsigned char unknown_1d0_[0x8c0 - 0x1d0];
    unsigned char unknown_8c0_[0xc34];
    int unknown_14f4_;
};

struct Struct_ov016_0218e800_6 {
    char unknown_0_[4];
    signed char unknown_4_;
    signed char unknown_5_;
    unsigned short unknown_6_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_;
};

struct Struct_ov016_0218e800 {
    const unsigned char* unknown_0_;
    const unsigned char* unknown_4_;
    unsigned short* unknown_8_;
    unsigned int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    const unsigned char* unknown_18_;
};

struct Struct_ov016_0218e800_2 {
    Struct_ov016_0218e800_5* unknown_0_;
    Struct_ov016_0218e800_6 unknown_4_;
    Struct_ov016_0218e800_3* unknown_34_;
    int (*unknown_38_)(Struct_ov016_0218e800_3*);
    Struct_ov016_0218e800 unknown_3c_;
    Struct_ov016_0218e800_4* unknown_58_;
    unsigned char** unknown_5c_;
    unsigned char** unknown_60_;
    unsigned int* unknown_64_;
    unsigned char* unknown_68_;
    unsigned char* unknown_6c_;
    unsigned char* unknown_70_[2];
    unsigned int unknown_78_[2];
    int unknown_80_[2];
    unsigned int unknown_88_[2];
    int unknown_90_;
    void* unknown_94_;
    unsigned int unknown_98_;
    unsigned int unknown_9c_;
    unsigned int unknown_a0_;
#if !defined(jpn)
    int unknown_a4_;
#endif
    unsigned int unknown_a8_;
    unsigned int unknown_ac_[6];
    unsigned int unknown_c4_;
    unsigned char unknown_c8_[4];
    int unknown_cc_;
    int unknown_d0_;
    int unknown_d4_;
};

void* SafeAllocatorAllocate_0218bc8c(unsigned int);
void* GetOrStreamPoolBlockD_0218fcd4(void);
void* GetOrStreamPoolBlockA_0218fd50(void);
void* GetOrStreamPoolBlockB_0218fdc0(void);
void* GetOrStreamPoolBlockC_0218fe30(void);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, unsigned int size);
extern unsigned char data_ov016_02191d78[];

// USA: func_ov016_0218e800
extern "C" ARM int func_ov016_0218e800(Struct_ov016_0218e800_2* arg0, Struct_ov016_0218e800_5* arg1, unsigned int arg2) {
    char var0[2];
    unsigned short var1;
    unsigned int var2;

    arg0->unknown_0_ = arg1;
    arg0->unknown_d4_ = arg1->inline_ov016_0218e800_6();
    if (!arg0->unknown_0_->inline_ov016_0218e800_3(&arg0->unknown_4_, 0x30)) return 0;

    if (arg0->unknown_4_.unknown_0_[0] != 'M' || arg0->unknown_4_.unknown_0_[1] != 'O' || arg0->unknown_4_.unknown_0_[2] != 'D' ||
        arg0->unknown_4_.unknown_0_[3] != 'S' || arg0->unknown_4_.unknown_4_ != 'N' ||
        (arg0->unknown_4_.unknown_5_ != '2' && arg0->unknown_4_.unknown_5_ != '3') || arg0->unknown_4_.unknown_6_ != 10)
        return 0;

    if (arg0->unknown_4_.unknown_4_ == 'N' && arg0->unknown_4_.unknown_5_ == '3') {
        do {
            if (!arg0->unknown_0_->inline_ov016_0218e800_3(var0, 2)) return 0;
            if (!arg0->unknown_0_->inline_ov016_0218e800_3(&var1, 2)) return 0;
            if (!arg0->unknown_0_->inline_ov016_0218e800_2(arg0->unknown_0_->inline_ov016_0218e800_6() + var1 * 4)) return 0;
        } while (var0[0] != 'H' || var0[1] != 'E');
    }

    if (arg0->unknown_4_.unknown_18_ != 0 && arg0->unknown_4_.unknown_18_ != 1 && arg0->unknown_4_.unknown_18_ != 2
#if !defined(jpn)
        && arg0->unknown_4_.unknown_18_ != 3 && arg0->unknown_4_.unknown_18_ != 4
#endif
        )
        return 0;

    self->stream = (Stream_0218e800*)SafeAllocatorAllocate_0218bc8c(sizeof(Stream_0218e800));
    MIi_CpuClearFast(0, self->stream, sizeof(Stream_0218e800));
    self->advance = (int (*)(Stream_0218e800*))GetOrStreamPoolBlockD_0218fcd4();
    self->stream->lumaTable = GetOrStreamPoolBlockA_0218fd50();
    self->stream->chromaTable = data_ov016_02191d78;
    self->stream->rangeTable = (unsigned char*)GetOrStreamPoolBlockC_0218fe30() + 0x40;
    self->target.width = self->header.width;
    self->target.height = self->header.height;
    self->target.field_18 = (const unsigned char*)GetOrStreamPoolBlockB_0218fdc0();
    self->stream->width = self->header.width;
    self->stream->height = self->header.height;

    if (arg0->unknown_4_.unknown_c_ > 0x100) return 0;
    if (arg2 < 6) return 0;

    arg0->unknown_a8_ = arg2;
    arg0->unknown_5c_ = (unsigned char**)func_ov016_0218bc8c(arg2 * 4);
    if (!arg0->unknown_5c_) return 0;
    arg0->unknown_60_ = (unsigned char**)func_ov016_0218bc8c(arg0->unknown_a8_ * 4);
    if (!arg0->unknown_60_) return 0;

    unsigned int i;
    for (i = 0; i < self->frameCount; i++) {
        self->framesY[i] = (unsigned char*)SafeAllocatorAllocate_0218bc8c(self->header.height << 8);
        if (!self->framesY[i]) return 0;
        self->framesC[i] = (unsigned char*)SafeAllocatorAllocate_0218bc8c((self->header.height >> 1) << 8);
        if (!self->framesC[i]) return 0;
        MIi_CpuClearFast(0, self->framesY[i], self->header.height << 8);
        VectorizedMemset(self->framesC[i], 0x80, (self->header.height >> 1) << 8);
    }

    arg0->unknown_64_ = (unsigned int*)func_ov016_0218bc8c(arg0->unknown_a8_ * 4);
    if (!arg0->unknown_64_) return 0;

    arg0->unknown_98_ = 0;
    arg0->unknown_ac_[0] = 0;
    for (int var4 = 1; var4 < 6; var4++) {
        arg0->unknown_ac_[var4] = arg0->unknown_a8_ - var4;
    }
    arg0->unknown_c4_ = 0;
    arg0->unknown_a0_ = 0;
    arg0->unknown_9c_ = 0;

    for (int var5 = 0; var5 < 2; var5++) {
        arg0->unknown_70_[var5] = (unsigned char*)func_ov016_0218bc8c(arg0->unknown_4_.unknown_20_ + 0x400);
        if (!arg0->unknown_70_[var5]) return 0;
    }

    if (self->header.audioCodec != 0) {
        self->audio = (AudioDecoder*)SafeAllocatorAllocate_0218bc8c(self->header.channelCount * sizeof(AudioDecoder));
        if (!self->audio) return 0;
        MIi_CpuClearFast(0, self->audio, self->header.channelCount * sizeof(AudioDecoder));
    }

    int var6 = arg0->unknown_0_->inline_ov016_0218e800_6();
    arg0->unknown_0_->inline_ov016_0218e800_2(arg0->unknown_4_.unknown_28_ + arg0->unknown_d4_);
    arg0->unknown_94_ = func_ov016_0218bc8c(arg0->unknown_4_.unknown_2c_ << 3);
    if (!arg0->unknown_0_->inline_ov016_0218e800_3(arg0->unknown_94_, arg0->unknown_4_.unknown_2c_ << 3)) return 0;
    arg0->unknown_0_->inline_ov016_0218e800_2(var6);

    if (arg0->unknown_4_.unknown_18_ == 1) {
        int var7;
        int var8 = arg0->unknown_0_->inline_ov016_0218e800_6();
        arg0->unknown_0_->inline_ov016_0218e800_2(arg0->unknown_4_.unknown_24_ + arg0->unknown_d4_);
        for (var7 = 0; var7 < arg0->unknown_4_.unknown_1a_; var7++) {
            if (!arg0->unknown_0_->inline_ov016_0218e800_3(arg0->unknown_58_[var7].unknown_8c0_, sizeof(arg0->unknown_58_[var7].unknown_8c0_))) return 0;
            arg0->unknown_58_[var7].unknown_14f4_ = 2;
        }
        arg0->unknown_0_->inline_ov016_0218e800_2(var8);
    } else if (arg0->unknown_4_.unknown_18_ == 2) {
        for (int var9 = 0; var9 < arg0->unknown_4_.unknown_1a_; var9++) {
            arg0->unknown_58_[var9].unknown_1cc_ = 2;
        }
    }

    arg0->unknown_0_->inline_ov016_0218e800_3(&var2, 4);
    arg0->unknown_78_[0] = var2 >> 14;
    arg0->unknown_88_[0] = var2 & 0x3fff;
    arg0->unknown_80_[0] = 0;
    arg0->unknown_0_->inline_ov016_0218e800_3(arg0->unknown_70_[0], arg0->unknown_78_[0] + 4);
    arg0->unknown_90_ = 1;
    return 1;
}
