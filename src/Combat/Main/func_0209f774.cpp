#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include <std_library_functions.h>

// USA: func_0209f774
extern "C" ARM void func_0209f774(void *manager, int mode) {
    Struct_0209e5b4_3 *state = static_cast<Struct_0209e5b4_3 *>(manager);
    int recordSize                = sizeof(Struct_0209e5b4);
    if (mode == 0) {
        int count;
        int i;
        state->kept.count = 0;
        count             = state->source[0x8e07];
        for (i = 0; i < count; i++) {
            Struct_0209e5b4 *record = reinterpret_cast<Struct_0209e5b4 *>(state->source + 0x5c60 + i * recordSize);
            if (record != NULL && record->unknown_1f_ != 0) {
                int index = state->kept.count++;
                memcpy(&state->kept.records[index], record, recordSize);
            }
        }
        return;
    }
    state->scratch.count = 0;
    memset(state->scratch.records, 0, sizeof(state->scratch.records));
    int i;
    for (i = 0; i < state->kept.count; i++) {
        Struct_0209e5b4 *record = &state->kept.records[i];
        if (record->unknown_1f_ != 0) {
            int index = state->scratch.count++;
            memcpy(&state->scratch.records[index], record, recordSize);
        }
    }
    state->kept.count = state->scratch.count;
    memcpy(state->kept.records, state->scratch.records, sizeof(state->scratch.records));
}
