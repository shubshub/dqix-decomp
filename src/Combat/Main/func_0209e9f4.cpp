#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include "std_library_functions.h"

// USA: func_0209e9f4
extern "C" ARM void func_0209e9f4(void *manager, int arg1, int mask) {
    Struct_0209e5b4_3 *owner = static_cast<Struct_0209e5b4_3 *>(manager);
    int recordSize                = sizeof(Struct_0209e5b4);
    if (arg1 == 0) {
        int total;
        owner->kept.count = 0;
        total             = owner->source[0x8e07];
        for (int i = 0; i < total; ++i) {
            Struct_0209e5b4 *record = reinterpret_cast<Struct_0209e5b4 *>(owner->source + 0x5c60) + i;
            if (record != NULL && (record->unknown_8_ & mask) != 0) {
                int index = owner->kept.count++;
                memcpy(&owner->kept.records[index], record, recordSize);
            }
        }
        return;
    }
    owner->scratch.count = 0;
    memset(owner->scratch.records, 0, sizeof(owner->scratch.records));
    for (int i = 0; i < owner->kept.count; ++i) {
        Struct_0209e5b4 *record = &owner->kept.records[i];
        if ((record->unknown_8_ & mask) != 0) {
            int index = owner->scratch.count++;
            memcpy(&owner->scratch.records[index], record, recordSize);
        }
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.records, owner->scratch.records, sizeof(owner->kept.records));
}

// USA: func_0209eaec
extern "C" ARM void func_0209eaec(void *manager, int arg1, int mask) {
    Struct_0209e5b4_3 *owner = static_cast<Struct_0209e5b4_3 *>(manager);
    int recordSize                = sizeof(Struct_0209e5b4);
    if (arg1 == 0) {
        int total;
        owner->kept.count = 0;
        total             = owner->source[0x8e07];
        for (int i = 0; i < total; ++i) {
            Struct_0209e5b4 *record = reinterpret_cast<Struct_0209e5b4 *>(owner->source + 0x5c60) + i;
            if (record != NULL && (record->unknown_c_ & mask) != 0) {
                int index = owner->kept.count++;
                memcpy(&owner->kept.records[index], record, recordSize);
            }
        }
        return;
    }
    owner->scratch.count = 0;
    memset(owner->scratch.records, 0, sizeof(owner->scratch.records));
    for (int i = 0; i < owner->kept.count; ++i) {
        Struct_0209e5b4 *record = &owner->kept.records[i];
        if ((record->unknown_c_ & mask) != 0) {
            int index = owner->scratch.count++;
            memcpy(&owner->scratch.records[index], record, recordSize);
        }
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.records, owner->scratch.records, sizeof(owner->kept.records));
}
