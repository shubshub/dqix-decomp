#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
struct Struct_02099004 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 6;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_;
    char unknown_8_[3][0x26];
};
struct Struct_021098e8 { unsigned char unknown_0_; unsigned char unknown_1_[3]; Struct_02099004* unknown_4_; char* unknown_8_; };
extern Struct_021098e8 data_021098e8;
extern const char data_020f1670[];
extern const char data_020f1677[];
extern const char data_020f1683[];
extern const char data_020f1686[];
extern "C" void* func_020421a0();
extern "C" void func_020474a8(void*, int, const char*, char*);

// JPN: func_0209abd0
extern "C" ARM int func_02099004(Script::Parameter* arg0, int arg1) {
    char var0[2];
    char var1[2];
    char var2[6];
    char var3[0xe];
    int var4;
    int var5;

    (arg0++)->ToInt();
    if (data_021098e8.unknown_4_->unknown_2_5_ != (arg0++)->ToInt()) return 0;
    void* var6 = func_020421a0();
    (arg0++)->ToInt();
    const char* var7 = (arg0++)->ToString();
    if (!data_021098e8.unknown_4_->unknown_3_7_) {
        var7 = (arg0++)->ToString();
    } else arg0++;
    if (data_021098e8.unknown_0_ & 0x10) var7 += 9;
    func_020474a8(var6, 12, var7, data_021098e8.unknown_8_);
    char* var8 = data_021098e8.unknown_8_;
    char* var9 = var8 + strlen(var8);
    memcpy(var2, data_020f1670, sizeof(var2));
    func_020474a8(var6, 12, data_020f1677, var3);
    memcpy(var0, data_020f1683, sizeof(var0));
    memcpy(var1, data_020f1686, sizeof(var1));
    if ((data_021098e8.unknown_0_ & 0x20) && !(data_021098e8.unknown_4_->unknown_8_[0][0] == '\x81' && data_021098e8.unknown_4_->unknown_8_[0][1] == 'E')) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        int var10 = strlen(var3);
        memcpy(var9, var3, var10);
        var9 += var10;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[0], 0x26);
        for (var4 = 0; var4 < 0x13; var4++) {
            if (var9[var4 * 2] == '\x81' && (var9 + var4 * 2)[1] == 'E') {
                memset(var9 = var9 + var4 * 2, 0, (0x13 - var4) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        memcpy(var9 + 0x28, var1, sizeof(var1));
        var9 += 0x2a;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[1], 0x26);
        for (var5 = 0; var5 < 0x13; var5++) {
            if (var9[var5 * 2] == '\x81' && (var9 + var5 * 2)[1] == 'E') {
                memset(var9 = var9 + var5 * 2, 0, (0x13 - var5) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        memcpy(var9 + 0x28, var1, sizeof(var1));
        var9 += 0x2a;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[2], 0x26);
        for (var4 = 0; var4 < 0x13; var4++) {
            if (var9[var4 * 2] == '\x81' && (var9 + var4 * 2)[1] == 'E') {
                memset(var9 = var9 + var4 * 2, 0, (0x13 - var4) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        var9 += 0x28;
    }
label0:
    const char* var11 = arg0[0].ToString();
    const char* var12 = arg0[1].ToString();
    const char* var13 = arg0[2].ToString();
    const char* var14 = arg0[3].ToString();
    if (data_021098e8.unknown_0_ & 2) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var11, var9);
        var9 += strlen(var9);
    } else if (data_021098e8.unknown_0_ & 4) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var12, var9);
        var9 += strlen(var9);
    } else if (data_021098e8.unknown_0_ & 8) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var13, var9);
        var9 += strlen(var9);
    }
    if (data_021098e8.unknown_0_ & 1) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var14, var9);
        var9 += strlen(var9);
    }
    return 1;
}
#else
struct Struct_02099004 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 6;
    unsigned int unknown_3_7_ : 1;
    signed int unknown_4_0_ : 9;
    unsigned int unknown_5_1_ : 23;
    char unknown_8_[1];
};
struct Struct_021098e8 { unsigned char unknown_0_; unsigned char unknown_1_[3]; char* unknown_4_; Struct_02099004* unknown_8_; };
extern Struct_021098e8 data_021098e8;
extern unsigned char data_020e8dac[2];
struct PagePrefix02099004 { char text[7]; };
extern const PagePrefix02099004 data_020e8dae;
int MessageSystem_GetInstance();
int STD_GetStringLength(const char*);
char* StandardStrings_Get(int);
void AppendFormattedData02098f70(int*, void*, int, int);
extern "C" void MessageSystem_FormatText(int, int, const char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" int Font_DecodeText(const char*, char*, int);

// USA: func_02099004
extern "C" ARM int func_02099004(Script::Parameter* params, int count) {
    (params++)->ToInt();
    if (data_021098e8.profile->selector != (params++)->ToInt()) return 0;
    int base = MessageSystem_GetInstance();
    (params++)->ToInt();
    const char* text = (params++)->ToString();
    if (!data_021098e8.profile->ageEnabled) {
        text = (params++)->ToString();
    } else params++;
    if (data_021098e8.flags & 0x10) text += 17;
    MessageSystem_FormatText(base, 12, text, data_021098e8.output, 0xe3, 0, 1);
    char* output = data_021098e8.output;
    char* cursor = output + strlen(output);
    PagePrefix02099004 prefix = data_020e8dae;
    int prefixLength = STD_GetStringLength(prefix.text);
    char message[0x20];
    char formatted[0x400];
    char body[0x20];
    const char* messageText = StandardStrings_Get(0x3ea);
    MessageSystem_FormatText(base, 12, messageText, message, 0xe3, 0, 1);
    char separator[2];
    separator[0] = data_020e8dac[0];
    separator[1] = data_020e8dac[1];
    const char* profileText;
    if ((data_021098e8.flags & 0x20) && (profileText = data_021098e8.profile->text)[0]) {
        memcpy(cursor, prefix.text, prefixLength);
        cursor += prefixLength;
        int messageLength = strlen(message);
        memcpy(cursor, message, messageLength);
        cursor += messageLength;
        int textLength = STD_GetStringLength(profileText);
        int position = 0;
        do {
            int length = textLength - position;
            if (length > 19) length = 19;
            __clear(body, sizeof(body));
            memcpy(body, profileText + position, length);
            __clear(formatted, sizeof(formatted));
            Font_DecodeText(body, formatted, 1);
            cursor += sprintf(cursor, formatted);
            position += 19;
            if (position >= textLength) break;
            cursor += sprintf(cursor, separator);
        } while (1);
    }
    const char* var16 = arg0[0].ToString();
    const char* var17 = arg0[1].ToString();
    const char* var18 = arg0[2].ToString();
    const char* var19 = arg0[3].ToString();
    const char* var20 = 0;
    if (data_021098e8.unknown_0_ & 2) var20 = var16;
    else if (data_021098e8.unknown_0_ & 4) var20 = var17;
    else if (data_021098e8.unknown_0_ & 8) var20 = var18;
    if (var20) func_02098f70((int*)&var3, (void*)var20, (int)var4.unknown_0_, var5);
    var20 = 0;
    if (data_021098e8.unknown_0_ & 1) var20 = var19;
    if (var20) func_02098f70((int*)&var3, (void*)var20, (int)var4.unknown_0_, var5);
    return 1;
}
#endif
