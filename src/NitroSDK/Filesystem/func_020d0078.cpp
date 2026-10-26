#include <globaldefs.h>

#include "Filesystem/BackupDevice.h"
#include "NitroSDK/Filesystem/FSInnerDefs.h"
#include "NitroSDK/Memory.h"

// USA: func_020d0078
extern "C" ARM void func_020d0078(unsigned int type) {
    Arm7CardReadData *const command = data_021118e0.pSharedData;

    VectorizedMemset(&command->backup.unknown_14_, 0, sizeof(command->backup.unknown_14_));
    command->backup.type              = type;
    command->backup.unknown_14_.unknown_40_ = 0x203f;
    if (type != 0) {
        const unsigned int size = 1 << (((int) type >> 8) & 0xff);
        const int var2        = type & 0xff;
        const int var3        = ((int) type >> 16) & 0xff;

        command->backup.unknown_14_.unknown_0_     = size;
        command->backup.unknown_14_.unknown_3c_ = 0xff;
        if (var2 == 1) {
            switch (size) {
                default: goto invalidType;
                case 0x200:
                    command->backup.unknown_14_.unknown_c_        = 0x10;
                    command->backup.unknown_14_.unknown_10_    = 1;
                    command->backup.unknown_14_.unknown_14_ = 5;
                    command->backup.unknown_14_.unknown_3c_   = 0xf0;
                    break;
                case 0x2000:
                    command->backup.unknown_14_.unknown_c_        = 0x20;
                    command->backup.unknown_14_.unknown_10_    = 2;
                    command->backup.unknown_14_.unknown_14_ = 5;
                    command->backup.unknown_14_.unknown_3c_   = 0;
                    break;
                case 0x10000:
                    command->backup.unknown_14_.unknown_c_        = 0x80;
                    command->backup.unknown_14_.unknown_10_    = 2;
                    command->backup.unknown_14_.unknown_14_ = 10;
                    command->backup.unknown_14_.unknown_3c_   = 0;
                    break;
                case 0x20000:
                    command->backup.unknown_14_.unknown_c_        = 0x100;
                    command->backup.unknown_14_.unknown_10_    = 3;
                    command->backup.unknown_14_.unknown_14_ = 5;
                    command->backup.unknown_14_.unknown_3c_   = 0;
                    break;
            }
            command->backup.unknown_14_.unknown_4_ = command->backup.unknown_14_.unknown_c_;
            command->backup.unknown_14_.unknown_40_ |= 0x40;
            command->backup.unknown_14_.unknown_40_ |= 0x4300;
        } else if (var2 == 2) {
            switch (size) {
                default: goto invalidType;
                case 0x40000:
                case 0x80000:
                case 0x100000:
                    command->backup.unknown_14_.unknown_18_    = 25;
                    command->backup.unknown_14_.unknown_1c_ = 300;
                    command->backup.unknown_14_.unknown_38_    = 300;
                    command->backup.unknown_14_.unknown_28_  = 5000;
                    command->backup.unknown_14_.unknown_40_ |= 0x480;
                    break;
                case 0x200000:
                    command->backup.unknown_14_.unknown_18_      = 23;
                    command->backup.unknown_14_.unknown_1c_   = 300;
                    command->backup.unknown_14_.unknown_28_    = 500;
                    command->backup.unknown_14_.unknown_2c_ = 5000;
                    command->backup.unknown_14_.unknown_20_      = 10000;
                    command->backup.unknown_14_.unknown_24_   = 60000;
                    command->backup.unknown_14_.unknown_3c_      = 0;
                    command->backup.unknown_14_.unknown_40_ |= 0x80;
                    command->backup.unknown_14_.unknown_40_ |= 0x5400;
                    break;
                case 0x400000:
                    command->backup.unknown_14_.unknown_28_       = 600;
                    command->backup.unknown_14_.unknown_2c_    = 3000;
                    command->backup.unknown_14_.unknown_30_    = 70;
                    command->backup.unknown_14_.unknown_34_ = 150;
                    command->backup.unknown_14_.unknown_20_         = 23000;
                    command->backup.unknown_14_.unknown_24_      = 800000;
                    command->backup.unknown_14_.unknown_3c_         = 0;
                    command->backup.unknown_14_.unknown_8_         = 0x1000;
                    command->backup.unknown_14_.unknown_40_ |= 0x1000;
                    command->backup.unknown_14_.unknown_40_ |= 0xc000;
                    break;
                case 0x800000:
                    if (var3 == 0) {
                        command->backup.unknown_14_.unknown_28_    = 1000;
                        command->backup.unknown_14_.unknown_2c_ = 3000;
                        command->backup.unknown_14_.unknown_20_      = 68000;
                        command->backup.unknown_14_.unknown_24_   = 160000;
                        command->backup.unknown_14_.unknown_3c_      = 0;
                        command->backup.unknown_14_.unknown_40_ |= 0x1000;
                        command->backup.unknown_14_.unknown_40_ |= 0x4000;
                    } else if (var3 == 1) {
                        command->backup.unknown_14_.unknown_28_    = 1000;
                        command->backup.unknown_14_.unknown_2c_ = 3000;
                        command->backup.unknown_14_.unknown_20_      = 68000;
                        command->backup.unknown_14_.unknown_24_   = 160000;
                        command->backup.unknown_14_.unknown_3c_      = 0x84;
                        command->backup.unknown_14_.unknown_40_ |= 0x1000;
                        command->backup.unknown_14_.unknown_40_ |= 0x4000;
                    }
                    break;
            }
            command->backup.unknown_14_.unknown_4_      = 0x10000;
            command->backup.unknown_14_.unknown_c_        = 0x100;
            command->backup.unknown_14_.unknown_10_    = 3;
            command->backup.unknown_14_.unknown_14_ = 5;
            command->backup.unknown_14_.unknown_40_ |= 0xb40;
        } else if (var2 == 3) {
            switch (size) {
                default: goto invalidType;
                case 0x2000:
                case 0x8000: break;
            }
            command->backup.unknown_14_.unknown_c_      = size;
            command->backup.unknown_14_.unknown_4_    = size;
            command->backup.unknown_14_.unknown_10_  = 2;
            command->backup.unknown_14_.unknown_3c_ = 0;
            command->backup.unknown_14_.unknown_40_ |= 0x40;
            command->backup.unknown_14_.unknown_40_ |= 0x4300;
        } else {
        invalidType:
            command->backup.type                 = 0;
            command->backup.unknown_14_.unknown_0_       = 0;
            data_021118e0.pSharedData->unknown_0 = 3;
            return;
        }
    }
}
