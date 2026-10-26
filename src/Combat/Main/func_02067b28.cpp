#include <globaldefs.h>
#include <std_library_functions.h>

struct Entry0204254c {
    int value;
    char unknown_4_;
    signed char length : 6;
    signed char flags : 2;
    char unknown_6_[2];
};
struct Struct_02045c00_2;
struct Struct_02067b28 {
    char unknown_0_[0x4c];
    unsigned short* output;
    char* input;
    void* unknown_54_;
    void* unknown_58_;
    char unknown_5c_[0x10];
    unsigned int unknown_6c_;
    unsigned int unknown_70_;
    char unknown_74_[8];
    unsigned int unknown_7c_;
    char unknown_80_[0x8b4];
    short unknown_934_, unknown_936_;
    char unknown_938_[0x7c];
    unsigned int unknown_9b4_;
    char unknown_9b8_[0xe00];
    unsigned char unknown_17b8_[0x80];
    char unknown_1838_[0x4a];
    unsigned short unknown_1882_[64];
    char unknown_1902_[0x40];
    unsigned short unknown_1942_;
    short positionX;
    short available;
    char unknown_1948_[0x7a];
    unsigned char unknown_19c2_;
    unsigned char unknown_19c3_;
    unsigned char unknown_19c4_;
    char unknown_19c5_[0x17];
    unsigned char table;
};
extern "C" int func_02044494(void*, void*);
extern "C" int func_02044420(void*, void*);
extern "C" Entry0204254c* Font_FindCharacter(int, int);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" int func_02045c00(Struct_02045c00_2*, int);
extern "C" int func_020459b8(Struct_02067b28*, unsigned char, Entry0204254c*, unsigned char);
extern "C" int memcmp(const void*, const void*, int);
extern char data_020f08dc[3];

// USA: func_02067b28
extern "C" ARM void func_02067b28(Struct_02067b28* state) {
    if (!state->unknown_54_ || !state->unknown_58_) return;
    if (state->unknown_70_ <= state->unknown_6c_) return;
    while (state->unknown_6c_ < state->unknown_70_) {
        char* source = state->input + state->unknown_7c_;
        unsigned short* destination = state->output + state->unknown_6c_;
        unsigned short token;
        memcpy(&token, source, 2);
        if (func_02044494(state, &token)) {
            *destination = token;
            state->unknown_7c_ += 2;
            ++state->unknown_6c_;
            int length = func_02044420(state, &token);
            memcpy(destination + 1, source + 2, length * 2);
            state->unknown_7c_ += length * 2;
            state->unknown_6c_ += length;
            continue;
        }
        if (!state->unknown_19c2_) {
            state->unknown_19c4_ = 1;
            if (state->available <= 0) state->unknown_19c4_ = 0;
            if (!memcmp(source, data_020f08dc, 2)) {
                if (state->unknown_1942_ == 0) state->unknown_19c4_ = 0;
                else {
                    state->unknown_934_ = state->positionX + 18 + (short)(8 - (state->positionX & 7));
                    state->unknown_936_ = 22;
                    state->unknown_19c2_ = 1;
                }
                state->unknown_19c3_ = 1;
            }
        }
        Entry0204254c* entry = Font_FindCharacter((int)source, state->table);
        int tableIndex = Font_FindCharacterIndex((int)source, state->table);
        if (entry && tableIndex >= 0) {
            int index = func_02045c00((Struct_02045c00_2*)state, (int)entry);
            state->unknown_7c_ += entry->length;
            if (index < 0) {
                unsigned short var7 = func_020459b8(state, (unsigned char)tableIndex, entry, state->table);
                if (!state->unknown_19c2_) state->unknown_1882_[state->unknown_1942_] = var7;
                *destination = var7;
                ++state->unknown_6c_;
                state->unknown_9b4_ = (state->unknown_9b4_ + 1) & 0x7f;
                break;
            }
            unsigned short selected = index;
            if (!state->unknown_19c2_) {
                state->unknown_1882_[state->unknown_1942_] = selected;
                ++state->unknown_1942_;
                state->unknown_1942_ &= 0x3f;
            }
            *destination = selected;
            if (state->unknown_17b8_[selected] < 255) ++state->unknown_17b8_[selected];
        } else {
            signed char character = *source;
            if (!state->unknown_19c2_ && character == 32) {
                state->unknown_1882_[state->unknown_1942_] = 0xff19;
                ++state->unknown_1942_;
                state->unknown_1942_ &= 0x3f;
            }
            *destination = 0xff19;
            ++state->unknown_7c_;
        }
        ++state->unknown_6c_;
    }
    if (!state->unknown_19c2_) {
        ++state->unknown_1942_;
        state->unknown_1942_ &= 0x3f;
    }
}
