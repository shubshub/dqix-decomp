#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020a696c_10118 = 0x27c6, Enum_020a696c_10124 = 0x27cc, Enum_020a696c_10128 = 0x27d0, Enum_020a696c_68 = 0x64, Enum_020a696c_72 = 0x68 };
#else
enum { Enum_020a696c_10118 = 0x2786, Enum_020a696c_10124 = 0x278c, Enum_020a696c_10128 = 0x2790, Enum_020a696c_68 = 0x44, Enum_020a696c_72 = 0x48 };
#endif
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(GameState* battleStruct);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void func_020a6aa4(Vector3i* obj, int x, int y, int z);

// USA: func_020a696c
extern "C" ARM void func_020a696c(void* unused0, int arg1, int arg2) {
    GameState* battleStruct = GameState::GetInstance();
    void* base = Zone3D_GetInstance(battleStruct);
    void* fieldPtr = GameState_GetZoneTransition(battleStruct);

    if (arg2 == 0x170c) {
        if ((arg1 >= 0x4e20 && arg1 <= 0x752f) || arg1 == 0x76c) {
            unsigned char* p = (unsigned char*)fieldPtr;
            if (p[0x5] == 0 && p[0x62] == 0) {
                unsigned short u = *(unsigned short*)((char*)base + Enum_020a696c_10118);
                *(unsigned short*)fieldPtr = u;
                switch (u) {
                case 0:
                case 1:
                {
                    Vector3i localBuf;
                    int code = 0x170c;
                    *(unsigned short*)fieldPtr = code;
                    func_020a6aa4(&localBuf, -0x7000, code >> 3, 0x5e66);
                    *reinterpret_cast<Vector3i*>((char*)fieldPtr + 0x10) = localBuf;
                    p[0x7] = 1;
                    break;
                }
                default:
                    if (u != 0x76c) {
                        *(int*)((char*)fieldPtr + 0x10) = 0x100000;
                        *(int*)((char*)fieldPtr + 0x14) = 0;
                        *(int*)((char*)fieldPtr + 0x18) = 0x100000;
                        p[0x7] = 1;
                    }
                    break;
                }
            }
        }
    }

    if (arg1 == 0x2710 && arg2 >= 0x4e20 && arg2 <= 0x752f) {
        *(int*)((char*)base + Enum_020a696c_10124) = *(int*)((char*)base + Enum_020a696c_68);
        *(int*)((char*)base + Enum_020a696c_10128) = *(int*)((char*)base + Enum_020a696c_72);
    }
}
