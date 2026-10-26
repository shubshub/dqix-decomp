#pragma once

struct FontBankLoader {
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
    char customFontName[16];
    unsigned char unknown_54_;
    unsigned char unknown_55_;
    unsigned char unknown_56_;
    unsigned char loadStage;
    unsigned char unknown_58_;
    char cachedLocationSuffix[8];
    unsigned char unknown_61_;
    unsigned char unknown_62_;
    unsigned char unknown_63_;
    unsigned char unknown_64_;
};

extern "C" FontBankLoader* FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(FontBankLoader* loader);
extern "C" void func_02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char arg3,
                           unsigned char arg4);
extern "C" void func_02094b30(FontBankLoader* loader, int arg1, int arg2);
extern "C" void func_02094b34(FontBankLoader* loader, int first, int second, unsigned char arg3,
                           unsigned char arg4);
extern "C" void func_02094b38(FontBankLoader* loader, int arg1);
extern "C" void func_02094b3c(FontBankLoader* loader, int event);
extern "C" void func_02094b40(FontBankLoader* loader);
extern "C" void* func_02094b44(FontBankLoader* loader, int event);
extern "C" int func_02094b4c(FontBankLoader* loader);
extern "C" int func_02094b54(FontBankLoader* loader, int event, char* data, int size);
