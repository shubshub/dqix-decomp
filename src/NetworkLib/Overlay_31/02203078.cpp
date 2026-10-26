#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224c980 {
    char unknown0[8];
    unsigned short unknown_8_;
};

struct Struct_ov031_02203078 {
    int active;
    char unknown4[6];
    unsigned short unknown_a_;
};

extern Struct_ov031_0224c980 data_ov031_0224c980;

// USA: func_ov031_02203078
extern "C" ARM unsigned short func_ov031_02203078(void) {
    int var0;
    ProcessorContext* context;
    unsigned short var2;
    ProcessorContext* var3 = data_02111304.firstContext;
    do {
        var0 = 0;
        ++data_ov031_0224c980.unknown_8_;
        if (data_ov031_0224c980.unknown_8_ < 1024 ||
            data_ov031_0224c980.unknown_8_ >= 5000) {
            data_ov031_0224c980.unknown_8_ = 1024;
        }
        context = var3;
        if (context != NULL) {
            var2 = data_ov031_0224c980.unknown_8_;
            do {
                Struct_ov031_02203078* record = (Struct_ov031_02203078*)context->unknown_A4;
                if (record != NULL && record->active != 0 &&
                    record->unknown_a_ == var2) {
                    var0 = 1;
                    break;
                }
                context = context->pNext;
            } while (context != NULL);
        }
    } while (var0 != 0);
    return data_ov031_0224c980.unknown_8_;
}
