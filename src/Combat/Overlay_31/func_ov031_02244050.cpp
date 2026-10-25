#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Timing.h"
#include "std_library_functions.h"

struct Struct_ov031_02244050_2 {
    unsigned char unknown_0_[0x88];
    char unknown_88_[0x24];
    int unknown_ac_;
};
union Struct_ov031_02244050_4 {
    Struct_ov031_02244050_2 unknown_0_[12];
    unsigned char unknown1_0_[0x840];
};
struct Struct_ov031_02244050_5 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};
struct Struct_02245528 {
    unsigned char unknown_0_[0x34];
    unsigned char unknown_34_;
    unsigned char unknown_35_;
    unsigned char unknown_36_;
    unsigned char unknown_37_;
    int unknown_38_;
    int unknown_3c_;
    unsigned int unknown_40_;
    unsigned char unknown_44_;
    unsigned char unknown_45_[3];
    int unknown_48_;
    unsigned char unknown_4c_[4];
    Struct_ov031_02244050_2 unknown_50_[4];
    unsigned char unknown_310_[0x378 - 0x310];
    Struct_ov031_02244050_5 unknown_378_;
    unsigned char unknown_37c_[0xb4];
    unsigned long long unknown_430_;
};
struct Struct_ov031_02291e04_3 {
    unsigned char unknown_0_[0xc];
    int unknown_c_;
#if defined(jpn)
    int unknown_10_;
    Struct_ov031_02244050_4* unknown1_20_;
    int unknown_18_;
    int unknown_24_;
    int unknown_20_;
    int unknown_1c_;
    int unknown_14_;
    unsigned char unknown_2c_[0xc];
#else
    int unknown1_10_;
    int unknown_14_;
    int unknown1_18_;
    int unknown_1c_;
    Struct_ov031_02244050_4* unknown1_20_;
    int unknown_24_;
    unsigned char unknown_28_[0x10];
#endif
};
struct Struct_ov031_02244050 {
    unsigned char unknown_0_[0x104];
    Struct_ov031_02244050_5 unknown_104_;
};
struct Struct_ov031_02244050_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x5c0c];
#else
    unsigned char unknown1_0_[0x5e6c];
#endif
    Struct_ov031_02244050 unknown_5e6c_;
    Struct_ov031_02244050* inline_ov031_02244050() { return &unknown_5e6c_; }
};
struct Struct_02000c9c_8;
extern Struct_ov031_02291e04_3 data_ov031_02291e04;
extern char data_ov031_0224c938[];
extern char data_ov031_0224c93d[];
#if defined(jpn)
struct Struct_ov031_0224a198 {
    char unknown_0_[4][8];
};
extern Struct_ov031_0224a198 data_ov031_0224a198;
#else
extern char data_ov031_022495b4[4][8];
extern char data_ov031_02249582[][3];
#endif
extern "C" void func_ov031_022433d0();
extern "C" void func_ov031_02243404();
extern "C" int func_ov031_02212ab4(void*, const char*, const char*);
int RunIfGlobalUnset_02212c18(int);
void SetCallbackAndRegister_02212bcc(void*);
int InitAndProcessArray_02212c3c(void*, void*, int);
int GameState_GetLanguage(Struct0200fb08*);
extern "C" int func_ov031_022123d4();
extern "C" int func_ov031_02212c84(void*, int, int);
extern "C" void func_ov031_022120f8();
extern "C" void func_ov031_02245528(Struct_02245528*, int);
extern "C" void func_ov023_021f6158(void*);
extern "C" int func_ov031_02212184();
extern "C" void func_ov031_02245478(Struct_02245528*);

// USA: func_ov031_02244050
extern "C" ARM void func_ov031_02244050(Struct_02245528* arg0) {
    switch (arg0->unknown_35_) {
    case 0:
        switch (arg0->unknown_37_) {
        case 0:
            data_ov031_02291e04.unknown_24_ = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212ab4((void*)func_ov031_022433d0, data_ov031_0224c938, data_ov031_0224c93d)) arg0->unknown_35_ = 8;
            else arg0->unknown_37_++;
            break;
        case 1:
            if (data_ov031_02291e04.unknown_c_) arg0->unknown_37_++;
            break;
        case 2:
            if (data_ov031_02291e04.unknown_24_) arg0->unknown_35_ = 8;
            else arg0->unknown_37_++;
            break;
        case 3:
            data_ov031_02291e04.unknown_24_ = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c18((int)&arg0->unknown_38_)) arg0->unknown_35_ = 8;
            else arg0->unknown_37_++;
            break;
        case 4:
            if (data_ov031_02291e04.unknown_c_) arg0->unknown_37_++;
            break;
        case 5:
            if (data_ov031_02291e04.unknown_24_ == 1) { arg0->unknown_35_ = 8; break; }
            if (arg0->unknown_38_ == 0) {
                arg0->unknown_35_ = 5;
                data_ov031_02291e04.unknown_1c_ = 0;
                func_ov031_02212bcc((void*)func_ov031_02243404);
                break;
            }
            data_ov031_02291e04.unknown1_20_ = (Struct_ov031_02244050_4*)((SafeAllocator*)arg0)->Allocate(0x840);
            if (!data_ov031_02291e04.unknown1_20_) { arg0->unknown_35_ = 7; break; }
            data_ov031_02291e04.unknown_24_ = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c3c(data_ov031_02291e04.unknown1_20_, 0, arg0->unknown_38_)) arg0->unknown_35_ = 8;
            else arg0->unknown_37_++;
            break;
        case 6:
            if (data_ov031_02291e04.unknown_c_) arg0->unknown_37_++;
            break;
        case 7: {
            if (data_ov031_02291e04.unknown_24_) { arg0->unknown_35_ = 8; break; }
#if defined(jpn)
            Struct_ov031_0224a198 var0 = data_ov031_0224a198;
            for (int var1 = 0; var1 < arg0->unknown_38_; var1++) {
                int var2;
                int var3 = var1 * sizeof(Struct_ov031_02244050_2);
                for (var2 = 0; var2 < 4; var2++) {
                    if (!strstr((char*)&data_ov031_02291e04.unknown1_20_->unknown1_0_[var3] + 0x88, var0.unknown_0_[var2])) continue;
                    if (arg0->unknown_40_ & (1 << var2)) continue;
                    arg0->unknown_40_ |= 1 << var2;
                    memcpy(&arg0->unknown_50_[var2], &data_ov031_02291e04.unknown1_20_->unknown1_0_[var3], 0xb0);
                }
            }
#else
            int language = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
            for (int record = 0; record < session->count; record++) {
                int record_offset = record * sizeof(SessionRecord02244050);
                for (int kind = 0; kind < 4; kind++) {
                    SessionRecord02244050* entry = (SessionRecord02244050*)&data_ov031_02291e04.records->bytes[record_offset];
                    if (!strstr(entry->name, data_ov031_022495b4[kind])) continue;
                    if (kind == 0 && !strstr(entry->name + 11, data_ov031_02249582[language])) continue;
                    if (session->present & (1 << kind)) continue;
                    session->present |= 1 << kind;
                    memcpy(&session->records[kind], &data_ov031_02291e04.records->entries[record], 0xb0);
                }
            }
#endif
            arg0->unknown_35_ = 3;
            arg0->unknown_37_++;
            break;
        }
        }
        if (func_ov031_022123d4()) arg0->unknown_35_ = 8;
        return;
    case 3:
        if (arg0->unknown_3c_ >= 3 && arg0->unknown_3c_ % 3 == 0) {
            unsigned long long var9 = (GetCurrentTimestamp() << 6) / 0x82ea;
            if (arg0->unknown_430_ + 1000 > var9) return;
        }
        while (!(arg0->unknown_40_ & (1 << arg0->unknown_3c_)) && arg0->unknown_3c_ < 4) arg0->unknown_3c_++;
        if (arg0->unknown_3c_ < 4) {
            data_ov031_02291e04.unknown_24_ = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c84(&arg0->unknown_50_[arg0->unknown_3c_], arg0->unknown_48_, arg0->unknown_50_[arg0->unknown_3c_].unknown_ac_)) {
                arg0->unknown_35_ = 8;
                return;
            }
            data_ov031_02291e04.unknown_14_ = 0;
        } else {
            data_ov031_02291e04.unknown_14_ = 1;
            data_ov031_02291e04.unknown_c_ = 1;
        }
        arg0->unknown_35_ = 4;
        return;
    case 4:
        if (data_ov031_02291e04.unknown_14_ && data_ov031_02291e04.unknown_c_) {
            if (arg0->unknown_3c_ < 3) {
                arg0->unknown_48_ += arg0->unknown_50_[arg0->unknown_3c_].unknown_ac_;
                arg0->unknown_3c_++;
                arg0->unknown_35_ = 3;
                if (arg0->unknown_3c_ % 3 == 0) arg0->unknown_430_ = (GetCurrentTimestamp() << 6) / 0x82ea;
            } else {
                arg0->unknown_35_ = 5;
                data_ov031_02291e04.unknown_1c_ = 0;
                func_ov031_02212bcc((void*)func_ov031_02243404);
            }
        } else if (data_ov031_02291e04.unknown_24_ == 1) arg0->unknown_35_ = 8;
        return;
    case 5:
        if (data_ov031_02291e04.unknown_1c_ != 1) return;
        arg0->unknown_37_ = 0;
        func_ov031_022120f8();
        arg0->unknown_35_ = 6;
        return;
    case 6: {
        func_ov031_02245528(arg0, 0);
        Struct_ov031_02244050* var10 = ((Struct_ov031_02244050_3*)GameState::GetInstance())->inline_ov031_02244050();
        var10->unknown_104_.unknown_0_0_ = arg0->unknown_378_.unknown_0_0_;
        var10->unknown_104_.unknown_1_4_ = arg0->unknown_378_.unknown_1_4_;
        var10->unknown_104_.unknown_2_0_ = arg0->unknown_378_.unknown_2_0_;
        var10->unknown_104_.unknown_2_5_ = arg0->unknown_378_.unknown_2_5_;
        var10->unknown_104_.unknown_3_2_ = arg0->unknown_378_.unknown_3_2_;
        func_ov023_021f6158(&var10->unknown_104_);
        arg0->unknown_44_ |= 1;
        return;
    }
    case 7:
        if (!data_ov031_02291e04.unknown_c_) return;
        data_ov031_02291e04.unknown_24_ = 0;
        data_ov031_02291e04.unknown_1c_ = 0;
        func_ov031_02212bcc((void*)func_ov031_02243404);
        arg0->unknown_35_ = 9;
        if (data_ov031_02291e04.unknown_24_ == 1) arg0->unknown_35_ = 8;
        return;
    case 9:
        if (data_ov031_02291e04.unknown_1c_ && func_ov031_02212184()) func_ov031_02245478(arg0);
        return;
    case 8:
        arg0->unknown_35_ = 7;
        return;
    }
}
