#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_02045d14_3 {
    const char* unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 1;
    signed char unknown_5_7_ : 1;
    char unknown_6_[2];
};
struct Struct_02045d14 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[512];
};
struct Struct_02045d14_2 {
    char unknown_0_[0x800];
    int unknown_800_;
};
struct Struct_02045c00_2 {
    char unknown_0_[0x1b4];
    Struct_02045d14_2 unknown_1b4_;
    char unknown_9b8_[0x17b8 - 0x9b8];
    unsigned char unknown_17b8_[0x80];
    char unknown_1838_[0x1e28 - 0x1838];
    char* unknown_1e28_;
    inline Struct_02045d14_2* inline_02045d14() { return &unknown_1b4_; }
};
typedef Struct_02045c00_2 Struct_02045c00_2;
extern "C" void __clear(void*, unsigned int);
extern "C" void func_0204483c(TextEncoder*, const char*, char*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
int Dispatch02044420(void*, void*);
CharacterEntry* Font_FindCharacter(int, int);
int FindEntryIndexByKey020424e4(int, int);
int FindMatchingEntryIndex(Container02045c00*, int);
extern "C" unsigned short func_020459b8(TextEncoder*, int, CharacterEntry*, int);

// USA: func_02045d14
extern "C" ARM unsigned short func_02045d14(Struct_02045c00_2* arg0, const char* arg1, unsigned short* arg2, int arg3) {
    unsigned short var0;
    int var1;
    int var2;
    int var3;
    Struct_02045d14_3* var4;
    Struct_02045d14_2* var5;
    Struct_02045d14 var6;
    if (arg1 == 0 || arg2 == 0) return 0;
    __clear(var6.unknown_4_, sizeof(var6.unknown_4_));
    func_0204483c(arg0, arg1, var6.unknown_4_);
    var0 = 0;
    var1 = 0;
    var2 = 0;
    if (arg0->unknown_1e28_) func_0207df90(arg0->unknown_1e28_);
    while (1) {
        if (var2 > 0 && arg2[var2 - 1] == 0xff01) break;
        memcpy(&var6.unknown_0_, var6.unknown_4_ + var1, 2);
        if ((var6.unknown_0_ & 0xff00) == 0xff00) {
            memcpy(&var6.unknown_2_, var6.unknown_4_ + var1, 2);
            arg2[var2] = var6.unknown_2_;
            var1 += 2;
            ++var2;
            ++var0;
            var3 = func_02044420(arg0, &var6.unknown_2_);
            unsigned int var7 = var3 * sizeof(unsigned short);
            memcpy(arg2 + var2, var6.unknown_4_ + var1, var7);
            var0 += var3;
            var1 += var3 * 2;
            var2 += var3;
        } else {
            entry = Font_FindCharacter((int)(work.buffer + offset), table);
            int index = FindEntryIndexByKey020424e4((int)(work.buffer + offset), table);
            if (entry != 0 && index >= 0) {
                int match = FindMatchingEntryIndex(self, (int)entry);
                if (match == -1) {
                    output[outIndex] = func_020459b8(self, index & 0xff, entry, table);
                    cache = self->GetCache();
                    ++cache->nextEntry;
                    cache->nextEntry &= 0x7f;
                } else {
                    unsigned short var10 = var9;
                    arg2[var2] = var10;
                    if (arg0->unknown_17b8_[var10] < 0xff) ++arg0->unknown_17b8_[var10];
                }
                var1 += var4->unknown_5_0_;
            } else {
                arg2[var2] = 0xff19;
                ++var1;
            }
            ++var2;
            ++var0;
        }
    }
    if (arg0->unknown_1e28_) func_0207dfac(arg0->unknown_1e28_);
    return var0;
}
