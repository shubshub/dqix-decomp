#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_0221fd18_2 {
    unsigned int unknown_0_;
    unsigned char ssid[0x20];
    char unknown_24_[4];
    unsigned char bssid[6];
    unsigned short unknown_2e_;
};

struct Struct_ov031_0221fd18 {
    unsigned int count;
    Struct_ov031_0221fd18_2 entries[1];
};

extern "C" int memcmp(const void* first, const void* second, unsigned int size);
extern char data_ov031_0224b180[];

// USA: func_ov031_0221fd18
extern "C" THUMB int func_ov031_0221fd18(Struct_ov031_0221fd18* saved, Struct_ov031_0221fd18* arg1, unsigned int* index) {
    int found = 0;
    int result = 0;
    int var2;
    int var3;
    unsigned int count;
    unsigned int i;
    unsigned int j;
    Struct_ov031_0221fd18_2* entry = saved->entries;
    Struct_ov031_0221fd18_2* other = arg1->entries;

    for (i = 0; i < saved->count; i++) {
        char name[0x22] = {0};
        memcpy(name, entry->ssid, 0x20);
        name[entry->unknown_0_] = 0;
        count = arg1->count;
        j = 0;
        if (j < count) {
            unsigned int length = entry->unknown_0_;
            do {
                if (length == 0 || length > 0x20) {
                    break;
                }
                if (length == 1 && (entry->ssid[0] == 0 || entry->ssid[0] == ' ')) {
                    break;
                }
                if (memcmp(name, other->ssid, strlen(name)) == 0 &&
                    memcmp(entry->bssid, other->bssid, 6) == 0 &&
                    entry->unknown_2e_ != other->unknown_2e_ && entry->unknown_2e_ == 0) {
                    found = 1;
                    break;
                }
                other++;
            } while (++j < count);
        }
        if (found) {
            break;
        }
        entry++;
        other = arg1->entries;
    }
    if (!found) {
        char name[0x22] = {0};
        var2 = 0;
        var3 = 0;
        entry = saved->entries;
        other = arg1->entries;
        for (j = 0; j < arg1->count; j++) {
            memcpy(name, other->ssid, 0x20);
            name[other->unknown_0_] = 0;
            if (memcmp(name, data_ov031_0224b180, strlen(data_ov031_0224b180)) == 0 &&
                other->unknown_2e_ == 0) {
                var3 = 1;
                break;
            }
            other++;
        }
        for (i = 0; i < saved->count; i++) {
            memcpy(name, entry->ssid, 0x20);
            name[entry->unknown_0_] = 0;
            if (strlen(name) == strlen(data_ov031_0224b180) &&
                memcmp(name, data_ov031_0224b180, strlen(data_ov031_0224b180)) == 0 &&
                entry->unknown_2e_ == 0) {
                var2 = 1;
                break;
            }
            entry++;
        }
        if (var2 && !var3) {
            found = 1;
        }
    }
    if (found) {
        *index = i;
        result = 1;
    }
    return result;
}
