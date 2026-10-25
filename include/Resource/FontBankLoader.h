#pragma once

struct Struct_0208cb08 {
    void* unknown_0_;
    void* unknown_4_;
    char unknown_8_[4];
    int unknown_c_;
    int unknown_10_;
    int unknown_14_[8];
    int unknown_34_;
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    char unknown_44_[16];
    unsigned char unknown_54_;
    unsigned char unknown_55_;
    unsigned char unknown_56_;
    unsigned char unknown_57_;
    unsigned char unknown_58_;
    char unknown_59_[8];
    unsigned char unknown_61_;
    unsigned char unknown_62_;
    unsigned char unknown_63_;
    unsigned char unknown_64_;
};

FontBankLoader* FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(FontBankLoader* loader);
void BlankFunction02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char primaryMode,
                           unsigned char supplementalMode);
void BlankFunction02094b30(FontBankLoader* loader, int fontBankId, int useBaseArchive);
void BlankFunction02094b34(FontBankLoader* loader, int first, int second, unsigned char primaryMode,
                           unsigned char supplementalMode);
void BlankFunction02094b38(FontBankLoader* loader, int fontBankId);
void BlankFunction02094b3c(FontBankLoader* loader, int event);
void BlankFunction02094b40(FontBankLoader* loader);
void* AlwaysFalse02094b44(FontBankLoader* loader, int event);
int AlwaysTrue02094b4c(FontBankLoader* loader);
int AlwaysFalse02094b54(FontBankLoader* loader, int event, char* data, int size);
