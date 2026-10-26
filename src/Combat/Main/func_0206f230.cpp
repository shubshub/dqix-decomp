#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/MonsterDefinition.h"

extern "C" char* func_020da150(SafeAllocator* allocator, const char* source);

extern Struct_0206f01c_2* data_02108d14;

// USA: func_0206f230
extern "C" ARM void func_0206f230(struct Struct_0206f01c_2* output, SafeAllocator* allocator,
#if defined(jpn)
                                          struct Struct_0206efd8* source, int arg3, short* arg4, int arg5) {
#else
                                          struct Struct_0206efd8* source, int arg3, short* arg4, int arg5,
                                          SafeAllocator* arg6, unsigned char* arg7) {
#endif
    short* var0;
    int request;
    bool isNew;
    int var3;
    unsigned char var4;
    struct Struct_0206ef48 var5;
    short var6[0x200];
    short var7;
    int position;
    struct MonsterDefinition* destination;
    short* var10;
    short id;
    short* var12;
    int selected;
    struct MonsterDefinition* definition;

    data_02108d14 = output;
    if (arg5 == 0) {
        return;
    }
    var4 = 0;
    func_0206f170(&var5, source, &var4, func_0206ef48);
    var7 = 0;
    for (var0 = arg4, request = 0; request < arg5; request++, var0++) {
        id = *var0;
        if (func_0206f470(&var5.table, id,
                                     func_0206ef40) != NULL) {
            var12 = var6;
            isNew = true;
            for (position = 0; position < var7; position++, var12++) {
                if (*var12 == id) {
                    isNew = false;
                    break;
                }
                if (*var12 > id) {
                    memmove(var12 + 1, var12, (var7 - position) * sizeof(short));
                    break;
                }
            }
            if (isNew) {
                *var12 = id;
                var7 = var7 + 1;
                if (var7 >= 0x200) {
                    break;
                }
            }
        }
    }

    output->arr = (struct MonsterDefinition*)allocator->Allocate(var7 * sizeof(struct MonsterDefinition));
    if (output->arr == NULL) {
        return;
    }
#if !defined(jpn)
    if (arg6 != NULL && arg7 != NULL) {
        allocator->Allocate(0x80 - var7 * 8);
    }
#endif

    var3 = 0;
    destination = output->arr;
    for (var10 = var6, selected = 0; selected < var7; selected++, var10++) {
        definition = (struct MonsterDefinition*)func_0206f470(
            &var5.table, *var10, func_0206ef40);
        if (definition == NULL) {
            continue;
        }
        memcpy(destination, definition, sizeof(struct MonsterDefinition));
#if defined(jpn)
        destination->name = func_020da150(allocator, definition->name);
#else
        if (arg6 != NULL && arg7 != NULL) {
            destination->name = func_020da150(arg6, definition->name);
            destination->unknown_14_ = func_020da150(arg6, definition->unknown_14_);
            allocator->Allocate(arg7[selected]);
        } else {
            destination->name = func_020da150(allocator, definition->name);
            destination->unknown_14_ = func_020da150(allocator, definition->unknown_14_);
        }
#endif
        destination->unknown_4_ = func_020da150(allocator, definition->unknown_4_);
        destination++;
        var3 = (short)(var3 + 1);
    }
    output->header.count = var3;
}
