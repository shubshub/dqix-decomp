#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Timing.h"
#include "std_library_functions.h"

struct Struct_ov031_02244050_2 {
    unsigned char unknown_0_[0x88];
    char name[0x24];
    int length;
};
union Struct_ov031_02244050_4 {
    Struct_ov031_02244050_2 entries[12];
    unsigned char bytes[0x840];
};
struct Struct_ov031_02244050_5 {
    unsigned int field_0 : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};
struct Struct_02245528 {
    unsigned char unknown_0_[0x34];
    unsigned char category;
    unsigned char phase;
    unsigned char unknown_36_;
    unsigned char step;
    int count;
    int selected;
    unsigned int present;
    unsigned char flags;
    unsigned char unknown_45_[3];
    int offset;
    unsigned char unknown_4c_[4];
    Struct_ov031_02244050_2 records[4];
    unsigned char unknown_310_[0x378 - 0x310];
    Struct_ov031_02244050_5 settings;
    unsigned char unknown_37c_[0xb4];
    unsigned long long unknown_430_;
};
struct Struct_ov031_02291e04_3 {
    unsigned char unknown_0_[0xc];
    int unknown_c_;
#if defined(jpn)
    int unknown_10_;
    Struct_ov031_02244050_4* records;
    int field_18;
    int error;
    int field_20;
    int unknown_1c_;
    int connected;
    unsigned char unknown_2c_[0xc];
#else
    int unknown1_10_;
    int connected;
    int field_18;
    int unknown_1c_;
    Struct_ov031_02244050_4* records;
    int error;
    unsigned char unknown_28_[0x10];
#endif
};
struct Struct_ov031_02244050 {
    unsigned char unknown_0_[0x104];
    Struct_ov031_02244050_5 settings;
};
struct Struct_ov031_02244050_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x5c0c];
#else
    unsigned char unknown1_0_[0x5e6c];
#endif
    Struct_ov031_02244050 save;
    Struct_ov031_02244050* inline_ov031_02244050() { return &save; }
};
struct Struct0200fb08;
extern Struct_ov031_02291e04_3 data_ov031_02291e04;
extern char data_ov031_0224c938[];
extern char data_ov031_0224c93d[];
#if defined(jpn)
struct Struct_ov031_0224a198 {
    char names[4][8];
};
extern Struct_ov031_0224a198 data_ov031_0224a198;
#else
extern char data_ov031_022495b4[4][8];
extern char data_ov031_02249582[][3];
#endif
extern "C" void func_ov031_022433d0();
extern "C" void func_ov031_02243404();
extern "C" int func_ov031_02212ab4(void*, const char*, const char*);
extern "C" int func_ov031_02212c18(int);
extern "C" void func_ov031_02212bcc(void*);
extern "C" int func_ov031_02212c3c(void*, void*, int);
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" int func_ov031_022123d4();
extern "C" int func_ov031_02212c84(void*, int, int);
extern "C" void func_ov031_022120f8();
extern "C" void func_ov031_02245528(Struct_02245528*, int);
extern "C" void func_ov023_021f6158(void*);
extern "C" int func_ov031_02212184();
extern "C" void func_ov031_02245478(Struct_02245528*);

// USA: func_ov031_02244050
extern "C" ARM void func_ov031_02244050(Struct_02245528* session) {
    switch (session->phase) {
    case 0:
        switch (session->step) {
        case 0:
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212ab4((void*)func_ov031_022433d0, data_ov031_0224c938, data_ov031_0224c93d)) session->phase = 8;
            else session->step++;
            break;
        case 1:
            if (data_ov031_02291e04.unknown_c_) session->step++;
            break;
        case 2:
            if (data_ov031_02291e04.error) session->phase = 8;
            else session->step++;
            break;
        case 3:
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c18((int)&session->count)) session->phase = 8;
            else session->step++;
            break;
        case 4:
            if (data_ov031_02291e04.unknown_c_) session->step++;
            break;
        case 5:
            if (data_ov031_02291e04.error == 1) { session->phase = 8; break; }
            if (session->count == 0) {
                session->phase = 5;
                data_ov031_02291e04.unknown_1c_ = 0;
                func_ov031_02212bcc((void*)func_ov031_02243404);
                break;
            }
            data_ov031_02291e04.records = (Struct_ov031_02244050_4*)((SafeAllocator*)session)->Allocate(0x840);
            if (!data_ov031_02291e04.records) { session->phase = 7; break; }
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c3c(data_ov031_02291e04.records, 0, session->count)) session->phase = 8;
            else session->step++;
            break;
        case 6:
            if (data_ov031_02291e04.unknown_c_) session->step++;
            break;
        case 7: {
            if (data_ov031_02291e04.error) { session->phase = 8; break; }
#if defined(jpn)
            Struct_ov031_0224a198 kinds = data_ov031_0224a198;
            for (int record = 0; record < session->count; record++) {
                int kind;
                int var3 = record * sizeof(Struct_ov031_02244050_2);
                for (kind = 0; kind < 4; kind++) {
                    if (!strstr((char*)&data_ov031_02291e04.records->bytes[var3] + 0x88, kinds.names[kind])) continue;
                    if (session->present & (1 << kind)) continue;
                    session->present |= 1 << kind;
                    memcpy(&session->records[kind], &data_ov031_02291e04.records->bytes[var3], 0xb0);
                }
            }
#else
            int language = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
            for (int record = 0; record < session->count; record++) {
                int var6 = record * sizeof(Struct_ov031_02244050_2);
                for (int kind = 0; kind < 4; kind++) {
                    Struct_ov031_02244050_2* entry = (Struct_ov031_02244050_2*)&data_ov031_02291e04.records->bytes[var6];
                    if (!strstr(entry->name, data_ov031_022495b4[kind])) continue;
                    if (kind == 0 && !strstr(entry->name + 11, data_ov031_02249582[language])) continue;
                    if (session->present & (1 << kind)) continue;
                    session->present |= 1 << kind;
                    memcpy(&session->records[kind], &data_ov031_02291e04.records->entries[record], 0xb0);
                }
            }
#endif
            session->phase = 3;
            session->step++;
            break;
        }
        }
        if (func_ov031_022123d4()) session->phase = 8;
        return;
    case 3:
        if (session->selected >= 3 && session->selected % 3 == 0) {
            unsigned long long now = (GetCurrentTimestamp() << 6) / 0x82ea;
            if (session->unknown_430_ + 1000 > now) return;
        }
        while (!(session->present & (1 << session->selected)) && session->selected < 4) session->selected++;
        if (session->selected < 4) {
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.unknown_c_ = 0;
            if (!func_ov031_02212c84(&session->records[session->selected], session->offset, session->records[session->selected].length)) {
                session->phase = 8;
                return;
            }
            data_ov031_02291e04.connected = 0;
        } else {
            data_ov031_02291e04.connected = 1;
            data_ov031_02291e04.unknown_c_ = 1;
        }
        session->phase = 4;
        return;
    case 4:
        if (data_ov031_02291e04.connected && data_ov031_02291e04.unknown_c_) {
            if (session->selected < 3) {
                session->offset += session->records[session->selected].length;
                session->selected++;
                session->phase = 3;
                if (session->selected % 3 == 0) session->unknown_430_ = (GetCurrentTimestamp() << 6) / 0x82ea;
            } else {
                session->phase = 5;
                data_ov031_02291e04.unknown_1c_ = 0;
                func_ov031_02212bcc((void*)func_ov031_02243404);
            }
        } else if (data_ov031_02291e04.error == 1) session->phase = 8;
        return;
    case 5:
        if (data_ov031_02291e04.unknown_1c_ != 1) return;
        session->step = 0;
        func_ov031_022120f8();
        session->phase = 6;
        return;
    case 6: {
        func_ov031_02245528(session, 0);
        Struct_ov031_02244050* saved = ((Struct_ov031_02244050_3*)GameState::GetInstance())->inline_ov031_02244050();
        saved->settings.field_0 = session->settings.field_0;
        saved->settings.unknown_1_4_ = session->settings.unknown_1_4_;
        saved->settings.unknown_2_0_ = session->settings.unknown_2_0_;
        saved->settings.unknown_2_5_ = session->settings.unknown_2_5_;
        saved->settings.unknown_3_2_ = session->settings.unknown_3_2_;
        func_ov023_021f6158(&saved->settings);
        session->flags |= 1;
        return;
    }
    case 7:
        if (!data_ov031_02291e04.unknown_c_) return;
        data_ov031_02291e04.error = 0;
        data_ov031_02291e04.unknown_1c_ = 0;
        func_ov031_02212bcc((void*)func_ov031_02243404);
        session->phase = 9;
        if (data_ov031_02291e04.error == 1) session->phase = 8;
        return;
    case 9:
        if (data_ov031_02291e04.unknown_1c_ && func_ov031_02212184()) func_ov031_02245478(session);
        return;
    case 8:
        session->phase = 7;
        return;
    }
}
