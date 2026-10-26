#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

#if defined(jpn)
enum { Enum_02023a9c_1792 = 0x600, Enum_02023a9c_140 = 0xe0, Enum_02023a9c_138 = 0xde, Enum_02023a9c_132 = 0xd8, Enum_02023a9c_142 = 0xe2 };
#else
enum { Enum_02023a9c_1792 = 0x700, Enum_02023a9c_140 = 0x8c, Enum_02023a9c_138 = 0x8a, Enum_02023a9c_132 = 0x84, Enum_02023a9c_142 = 0x8e };
#endif

// Main, originally SetFlag0x8eIfBitTestFails_02023a9c (USA 0x02023a9c, EUR 0x02023aac, JPN 0x02023464)
extern "C" ARM int MapDisplay_IsRedChestUnopened(char* base, int index) {
    void* g = Scenario_GetInstance();
    int offset = index * 0x1c;
    char* entry = base;
    entry += offset;
    entry += Enum_02023a9c_1792;

    unsigned short var3 = *(unsigned short*)(entry + Enum_02023a9c_140);
    if (var3 == 0) return 0;

    unsigned short var4 = *(unsigned short*)(entry + Enum_02023a9c_138);
    if (var4 == 0) {
        unsigned short f84 = *(unsigned short*)(entry + Enum_02023a9c_132);
        if (Scenario_TestFlag((int)g, (unsigned char*)g + 0x8c, f84 + 0x12 + 0x200)) {
            char* entry2 = base;
            entry2 += offset;
            entry2 += Enum_02023a9c_1792;
            *(unsigned short*)(entry2 + Enum_02023a9c_142) = 0;
            return 0;
        }
    }
    return 1;
}
