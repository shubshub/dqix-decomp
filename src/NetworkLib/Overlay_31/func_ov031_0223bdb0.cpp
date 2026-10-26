#include <globaldefs.h>
#include <NitroSDK/NSBXX/RenderCommands_Common.h>


#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

struct Struct_ov031_0223bdb0 {
    unsigned short count;
    unsigned short reserved;
    unsigned int offset;
};
struct Struct_ov031_0223bdb0_2 {
    unsigned short fields[3];
    unsigned short reserved;
};
extern Struct_ov031_0223bdb0* data_ov031_02290d2c[];
extern "C" void func_020ca3b8(const void* source, void* destination, unsigned int size);

// USA: func_ov031_0223bdb0
extern "C" ARM void func_ov031_0223bdb0(int tableIndex, int entryIndex, void* destination) {
    Struct_ov031_0223bdb0* table = data_ov031_02290d2c[tableIndex];
    const unsigned char* source = (const unsigned char*)table + table[entryIndex].offset;
    int count = table[entryIndex].count;
    Struct_ov031_0223bdb0_2 var3;
    func_020ca3ec(0, &var3, sizeof(var3));
    Struct_ov031_0223bdb0_2* output = (Struct_ov031_0223bdb0_2*)destination;
    int i = 0;
    if (count <= 0) {
        return;
    }
    do {
        func_020ca3b8(source, &var3, 6);
        func_020ca408(&var3, output, sizeof(var3));
        i++;
        source += 6;
        output++;
    } while (i < count);
}
