#include <globaldefs.h>

struct ResetFieldsStruct;
void PresetTable_Reset(struct ResetFieldsStruct* s);

// Main, originally ForwardResetStructFields02089ddc (USA 0x02089ddc, EUR 0x02089dec, JPN 0x0208a6d8)
ARM void PresetTable_Destroy(struct ResetFieldsStruct* s) {
    PresetTable_Reset(s);
}
