#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include <std_library_functions.h>

struct Struct_0209f968 {
    unsigned char pad0[0x12];
    short unknown_12_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    unsigned char pad18[0x28];
};

// USA: func_0209f968
extern "C" ARM void func_0209f968(void *manager, int mode, int key, int arg3) {
    Struct_0209e5b4_3 *state = static_cast<Struct_0209e5b4_3 *>(manager);
    int recordSize                = sizeof(Struct_0209e5b4);
    int groupCount                = *reinterpret_cast<int *>(state->source + 0x8e20);
    if (mode != 0) {
        state->kept.count = 0;
        int count         = state->source[0x8e07];
        for (int group = 0; group < groupCount; group++) {
            for (int slot = 0; slot < 4; slot++) {
                state->scratch.count = 0;
                memset(state->scratch.records, 0, sizeof(state->scratch.records));
                for (int i = 0; i < count; i++) {
                    Struct_0209f968 *record =
                        reinterpret_cast<Struct_0209f968 *>(state->source + 0x5c60 + i * recordSize);
                    if (record != NULL && record->unknown_16_ == group && record->unknown_12_ == slot && record->unknown_14_ == key) {
                        int index = state->scratch.count++;
                        memcpy(&state->scratch.records[index], record, recordSize);
                    }
                }
                if (state->scratch.count >= arg3 && state->scratch.count + state->kept.count < 16) {
                    memcpy(&state->kept.records[state->kept.count], state->scratch.records,
                           state->scratch.count * recordSize);
                    state->kept.count += state->scratch.count;
                }
            }
        }
    } else {
        state->scratch.count = 0;
        memset(state->scratch.records, 0, sizeof(state->scratch.records));
        for (int group = 0; group < groupCount; group++) {
            for (int slot = 0; slot < 4; slot++) {
                int var11 = 0;
                Struct_0209e5b4 var12[16] = {};
                for (int i = 0; i < state->kept.count; i++) {
                    Struct_0209f968 *record =
                        reinterpret_cast<Struct_0209f968 *>(&state->kept.records[i]);
                    if (record->unknown_16_ == group && record->unknown_12_ == slot && record->unknown_14_ == key) {
                        memcpy(&var12[var11++], record, recordSize);
                    }
                }
                if (var11 >= arg3 && var11 + state->scratch.count < 16) {
                    memcpy(&state->scratch.records[state->scratch.count], var12, var11 * recordSize);
                    state->scratch.count += var11;
                }
            }
        }
        state->kept.count = state->scratch.count;
        memcpy(state->kept.records, state->scratch.records, sizeof(state->scratch.records));
    }
}
