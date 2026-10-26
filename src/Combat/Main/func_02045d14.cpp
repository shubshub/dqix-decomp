#include <globaldefs.h>
#include <std_library_functions.h>

struct CharacterEntry {
    const char* text;
    signed char width;
    signed char length : 6;
    signed char reserved : 1;
    signed char unknown_5_7_ : 1;
    char padding[2];
};
struct Struct_02045d14 {
    unsigned short command;
    unsigned short unknown_2_;
    char buffer[512];
};
struct Struct_02045d14_2 {
    char pad0[0x800];
    int unknown_800_;
};
struct Struct_02045c00_2 {
    char pad0[0x1b4];
    Struct_02045d14_2 cache;
    char unknown_9b8_[0x17b8 - 0x9b8];
    unsigned char unknown_17b8_[0x80];
    char unknown_1838_[0x1e28 - 0x1838];
    char* pairTables;
    inline Struct_02045d14_2* inline_02045d14() { return &cache; }
};
typedef Struct_02045c00_2 Struct_02045c00_2;
extern "C" void __clear(void*, unsigned int);
extern "C" void func_0204483c(Struct_02045c00_2*, const char*, char*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" int func_02044420(void*, void*);
extern "C" CharacterEntry* Font_FindCharacter(int, int);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" int func_02045c00(Struct_02045c00_2*, int);
extern "C" unsigned short func_020459b8(Struct_02045c00_2*, int, CharacterEntry*, int);

// USA: func_02045d14
extern "C" ARM unsigned short func_02045d14(Struct_02045c00_2* self, const char* text, unsigned short* output, int table) {
    unsigned short count;
    int offset;
    int outIndex;
    int length;
    CharacterEntry* entry;
    Struct_02045d14_2* cache;
    Struct_02045d14 work;
    if (text == 0 || output == 0) return 0;
    __clear(work.buffer, sizeof(work.buffer));
    func_0204483c(self, text, work.buffer);
    count = 0;
    offset = 0;
    outIndex = 0;
    if (self->pairTables) VramState_Restore(self->pairTables);
    while (1) {
        if (outIndex > 0 && output[outIndex - 1] == 0xff01) break;
        memcpy(&work.command, work.buffer + offset, 2);
        if ((work.command & 0xff00) == 0xff00) {
            memcpy(&work.unknown_2_, work.buffer + offset, 2);
            output[outIndex] = work.unknown_2_;
            offset += 2;
            ++outIndex;
            ++count;
            length = func_02044420(self, &work.unknown_2_);
            unsigned int bytes = length * sizeof(unsigned short);
            memcpy(output + outIndex, work.buffer + offset, bytes);
            count += length;
            offset += length * 2;
            outIndex += length;
        } else {
            entry = Font_FindCharacter((int)(work.buffer + offset), table);
            int index = Font_FindCharacterIndex((int)(work.buffer + offset), table);
            if (entry != 0 && index >= 0) {
                int match = func_02045c00(self, (int)entry);
                if (match == -1) {
                    output[outIndex] = func_020459b8(self, index & 0xff, entry, table);
                    cache = self->inline_02045d14();
                    ++cache->unknown_800_;
                    cache->unknown_800_ &= 0x7f;
                } else {
                    unsigned short found = match;
                    output[outIndex] = found;
                    if (self->unknown_17b8_[found] < 0xff) ++self->unknown_17b8_[found];
                }
                offset += entry->length;
            } else {
                output[outIndex] = 0xff19;
                ++offset;
            }
            ++outIndex;
            ++count;
        }
    }
    if (self->pairTables) VramState_Save(self->pairTables);
    return count;
}
