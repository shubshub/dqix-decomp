#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_0221fd18_2 {
    unsigned int unknown_0_;
    unsigned char unknown_4_[0x20];
    char unknown_24_[4];
    unsigned char unknown_28_[6];
    unsigned short unknown_2e_;
};

struct Struct_ov031_0221fd18 {
    unsigned int unknown_0_;
    Struct_ov031_0221fd18_2 unknown_4_[1];
};

extern "C" int memcmp(const void* first, const void* second, unsigned int size);
extern char data_ov031_0224b180[];

// USA: func_ov031_0221fd18
extern "C" THUMB int func_ov031_0221fd18(Struct_ov031_0221fd18* arg0, Struct_ov031_0221fd18* arg1, unsigned int* arg2) {
    int var0 = 0;
    int var1 = 0;
    int var2;
    int var3;
    unsigned int var4;
    unsigned int var5;
    unsigned int var6;
    Struct_ov031_0221fd18_2* var7 = arg0->unknown_4_;
    Struct_ov031_0221fd18_2* var8 = arg1->unknown_4_;

    for (var5 = 0; var5 < arg0->unknown_0_; var5++) {
        char var9[0x22] = {0};
        memcpy(var9, var7->unknown_4_, 0x20);
        var9[var7->unknown_0_] = 0;
        var4 = arg1->unknown_0_;
        var6 = 0;
        if (var6 < var4) {
            unsigned int var10 = var7->unknown_0_;
            do {
                if (var10 == 0 || var10 > 0x20) {
                    break;
                }
                if (var10 == 1 && (var7->unknown_4_[0] == 0 || var7->unknown_4_[0] == ' ')) {
                    break;
                }
                if (memcmp(name, other->ssid, strlen(name)) == 0 &&
                    memcmp(entry->bssid, other->bssid, 6) == 0 &&
                    entry->security != other->security && entry->security == 0) {
                    found = 1;
                    break;
                }
                var8++;
            } while (++var6 < var4);
        }
        if (var0) {
            break;
        }
        var7++;
        var8 = arg1->unknown_4_;
    }
    if (!found) {
        char name[0x22] = {0};
        savedDefault = 0;
        scannedDefault = 0;
        entry = saved->entries;
        other = scanned->entries;
        for (j = 0; j < scanned->count; j++) {
            memcpy(name, other->ssid, 0x20);
            name[other->ssidLength] = 0;
            if (memcmp(name, data_ov031_0224b180, strlen(data_ov031_0224b180)) == 0 &&
                other->security == 0) {
                scannedDefault = 1;
                break;
            }
            var8++;
        }
        for (i = 0; i < saved->count; i++) {
            memcpy(name, entry->ssid, 0x20);
            name[entry->ssidLength] = 0;
            if (strlen(name) == strlen(data_ov031_0224b180) &&
                memcmp(name, data_ov031_0224b180, strlen(data_ov031_0224b180)) == 0 &&
                entry->security == 0) {
                savedDefault = 1;
                break;
            }
            var7++;
        }
        if (var2 && !var3) {
            var0 = 1;
        }
    }
    if (var0) {
        *arg2 = var5;
        var1 = 1;
    }
    return var1;
}
