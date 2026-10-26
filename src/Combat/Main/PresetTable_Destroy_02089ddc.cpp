#include <globaldefs.h>

struct ResetFieldsStruct;
extern "C" void PresetTable_Reset(struct ResetFieldsStruct* s);

// Main, originally ForwardResetStructFields02089ddc (USA 0x02089ddc, EUR 0x02089dec, JPN 0x0208a6d8)
extern "C" ARM void PresetTable_Destroy(struct ResetFieldsStruct* s) {
    PresetTable_Reset(s);
}
