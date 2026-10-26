#include <globaldefs.h>
#include "NitroSDK/Mutex.h"
#include "Resource/ResourceMutex.h"
#include "NitroSDK/Filesystem/OverlayFSManagement.h"
#include "NitroSDK/Filesystem/FSInnerDefs.h"
#include "NitroSDK/Filesystem/FileAccessor.h"

extern "C" void func_020d9834(int flag);
void NitroVM_Initialize(NitroVM* vm);
void DecompressAndStaticInitializeOverlay(const OverlayMetadata& overlay);
extern "C" int func_020a1ccc(unsigned int id);

extern volatile int data_01ffd348;
extern volatile unsigned char data_01ffd344;
extern volatile unsigned char data_01ffd340;
extern signed char data_01ffd364;
extern Mutex data_01ffd34c;
extern struct OverlayMetadata data_01ffd394[35];

extern int data_020e8f20[][2];

// USA: func_020a1a40
extern "C" ARM int func_020a1a40(unsigned int id) {
    int result = 0;
    int (*table)[2];
    int var2;
    volatile signed char* row;
    int cur;
    const OverlayMetadata* var5;
    NitroVM machine;
    bool ok;
    if (id < 0x23) {
        table = data_020e8f20;
        var2 = data_01ffd348;
        row = &data_01ffd364 + var2 * 6;
        cur = row[table[id][0]];
        if (cur != (int)id) {
            func_020a1ccc(cur);
            while (data_01ffd340) {
                func_020d9834(0);
            }
            data_01ffd340 = 1;
            LockResourceMutex();
            var5 = &data_01ffd394[id];
            NitroVM_Initialize(&machine);
            ok = LoadCompressedOverlay(*var5, &machine);
            UnlockResourceMutex();
            if (ok) {
                result = 0;
                for (;;) {
                    if (!GET_FLAG_BIT(machine.flags, NITROVM_FLAG_IN_HANDLE_QUEUE)) {
                        break;
                    }
                    func_020d9834(0);
                }
                LockResourceMutex();
                NitroVM_FinishRead(&machine);
                DecompressAndStaticInitializeOverlay(*var5);
                UnlockResourceMutex();
                data_01ffd340 = 0;
                if (data_01ffd344) {
                    LockMutex(&data_01ffd34c);
                }
                row[table[id][0]] = id;
                if (data_01ffd344) {
                    UnlockMutex(&data_01ffd34c);
                }
                result = 1;
            } else {
                data_01ffd340 = 0;
            }
        } else {
            result = 1;
        }
    }
    return result;
}
