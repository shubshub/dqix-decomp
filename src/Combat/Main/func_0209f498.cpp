#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include "std_library_functions.h"

// USA: func_0209f498
extern "C" ARM void func_0209f498(void *manager, int mode) {
    Struct_0209e5b4_3 *owner = static_cast<Struct_0209e5b4_3 *>(manager);
    int recordSize                = sizeof(Struct_0209e5b4);
    if (mode == 0) {
        int total;
        owner->kept.count = 0;
        total             = owner->source[0x8e07];
        for (int i = 0; i < total; ++i) {
            Struct_0209e5b4 *record = reinterpret_cast<Struct_0209e5b4 *>(owner->source + 0x5c60) + i;
            if (record != NULL) {
                int excluded = 0;
                if (record->unknown_12_ >= 7 && record->unknown_12_ <= 18) {
                    excluded = 1;
                }
                if (excluded != 0) {
                    continue;
                }
                int var6 = 0;
                for (int j = 0; j < 8; ++j) {
                    if (record->unknown_30_[j] > 0) {
                        var6 = 1;
                        break;
                    }
                }
                if (var6 == 0) {
                    int index = owner->kept.count++;
                    memcpy(&owner->kept.records[index], record, recordSize);
                }
            }
        }
        return;
    }
    owner->scratch.count = 0;
    memset(owner->scratch.records, 0, sizeof(owner->scratch.records));
    for (int i = 0; i < owner->kept.count; ++i) {
        Struct_0209e5b4 *record = &owner->kept.records[i];
        int excluded            = 0;
        if (record->unknown_12_ >= 7 && record->unknown_12_ <= 18) {
            excluded = 1;
        }
        if (excluded == 0) {
            int var12 = 0;
            for (int j = 0; j < 8; ++j) {
                if (record->unknown_30_[j] > 0) {
                    var12 = 1;
                    break;
                }
            }
            if (var12 == 0) {
                int index = owner->scratch.count++;
                memcpy(&owner->scratch.records[index], record, recordSize);
            }
        }
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.records, owner->scratch.records, sizeof(owner->kept.records));
}
