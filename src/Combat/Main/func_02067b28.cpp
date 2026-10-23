#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0204254c {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};
struct Struct_02045c00_2;
struct Struct_02067b28 {
    char unknown_0_[0x4c];
    unsigned short* unknown_4c_;
    char* unknown_50_;
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
    short unknown_1944_;
    short unknown_1946_;
    char unknown_1948_[0x7a];
    unsigned char unknown_19c2_;
    unsigned char unknown_19c3_;
    unsigned char unknown_19c4_;
    char unknown_19c5_[0x17];
    unsigned char unknown_19dc_;
};
int IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
Entry0204254c* Font_FindCharacter(int, int);
int Font_FindCharacterIndex(int, int);
int FindMatchingEntryIndex(Container02045c00*, int);
extern "C" int func_020459b8(TextContext02067b28*, unsigned char, Entry0204254c*, unsigned char);
extern "C" int func_02001aec(const void*, const void*, int);
extern char data_020f08dc[3];

// USA: func_02067b28
extern "C" ARM void func_02067b28(Struct_02067b28* arg0) {
    if (!arg0->unknown_54_ || !arg0->unknown_58_) return;
    if (arg0->unknown_70_ <= arg0->unknown_6c_) return;
    while (arg0->unknown_6c_ < arg0->unknown_70_) {
        char* var0 = arg0->unknown_50_ + arg0->unknown_7c_;
        unsigned short* var1 = arg0->unknown_4c_ + arg0->unknown_6c_;
        unsigned short var2;
        memcpy(&var2, var0, 2);
        if (func_02044494(arg0, &var2)) {
            *var1 = var2;
            arg0->unknown_7c_ += 2;
            ++arg0->unknown_6c_;
            int var3 = func_02044420(arg0, &var2);
            memcpy(var1 + 1, var0 + 2, var3 * 2);
            arg0->unknown_7c_ += var3 * 2;
            arg0->unknown_6c_ += var3;
            continue;
        }
        if (!arg0->unknown_19c2_) {
            arg0->unknown_19c4_ = 1;
            if (arg0->unknown_1946_ <= 0) arg0->unknown_19c4_ = 0;
            if (!func_02001aec(var0, data_020f08dc, 2)) {
                if (arg0->unknown_1942_ == 0) arg0->unknown_19c4_ = 0;
                else {
                    arg0->unknown_934_ = arg0->unknown_1944_ + 18 + (short)(8 - (arg0->unknown_1944_ & 7));
                    arg0->unknown_936_ = 22;
                    arg0->unknown_19c2_ = 1;
                }
                arg0->unknown_19c3_ = 1;
            }
        }
        Entry0204254c* entry = Font_FindCharacter((int)source, state->table);
        int tableIndex = Font_FindCharacterIndex((int)source, state->table);
        if (entry && tableIndex >= 0) {
            int index = FindMatchingEntryIndex((Container02045c00*)state, (int)entry);
            state->inputCursor += entry->length;
            if (index < 0) {
                unsigned short inserted = func_020459b8(state, (unsigned char)tableIndex, entry, state->table);
                if (!state->wrapped) state->ring[state->ringIndex] = inserted;
                *destination = inserted;
                ++state->outputCursor;
                state->entryCursor = (state->entryCursor + 1) & 0x7f;
                break;
            }
            unsigned short var8 = var6;
            if (!arg0->unknown_19c2_) {
                arg0->unknown_1882_[arg0->unknown_1942_] = var8;
                ++arg0->unknown_1942_;
                arg0->unknown_1942_ &= 0x3f;
            }
            *var1 = var8;
            if (arg0->unknown_17b8_[var8] < 255) ++arg0->unknown_17b8_[var8];
        } else {
            signed char var9 = *var0;
            if (!arg0->unknown_19c2_ && var9 == 32) {
                arg0->unknown_1882_[arg0->unknown_1942_] = 0xff19;
                ++arg0->unknown_1942_;
                arg0->unknown_1942_ &= 0x3f;
            }
            *var1 = 0xff19;
            ++arg0->unknown_7c_;
        }
        ++arg0->unknown_6c_;
    }
    if (!arg0->unknown_19c2_) {
        ++arg0->unknown_1942_;
        arg0->unknown_1942_ &= 0x3f;
    }
}
