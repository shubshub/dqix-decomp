#include <globaldefs.h>
#include "std_library_functions.h"

#include "Combat/ResourceScriptEntry.h"

static ResourceScriptEntry *s_entry;
static unsigned int s_selection;
static unsigned int s_maxValue;
static int s_found;
static unsigned int s_counter;

struct Obj020823e4 {
    unsigned int field_0;
    unsigned short field_4;
    unsigned short field_6;
    unsigned int field_8;
    unsigned int field_c;
    unsigned int field_10;
};

void CopyFiveFields020823e4(struct Obj020823e4 *dst, struct Obj020823e4 *src);

// USA: func_02082064
extern "C" ARM int func_02082064(Script::Parameter *params, int numParams) {
    ResourceScriptFields fields;
    fields.value4Low = ++s_counter;
    fields.value0 = (params++)->ToInt();
    if (s_selection < s_counter && fields.value0 <= s_maxValue) {
        fields.value8.low = (params++)->ToInt();
        fields.value8.high = (params++)->ToInt();
        fields.value8.middle = (params++)->ToInt();
        fields.valueC.low = (params++)->ToInt();
        fields.valueC.middle = (params++)->ToInt();
        fields.value10.low = (params++)->ToInt();
        fields.valueC.high = (params++)->ToInt();
        fields.value10.middle = (params++)->ToInt();
        fields.value10.high = (params++)->ToInt();
        fields.value4High = (params++)->ToInt();
        CopyFiveFields020823e4((Obj020823e4 *) &s_entry->final, (Obj020823e4 *) &fields);
        s_found = 1;
    }
    if (s_counter == s_selection) {
        fields.value8.low = (params++)->ToInt();
        fields.value8.high = (params++)->ToInt();
        fields.value8.middle = (params++)->ToInt();
        fields.valueC.low = (params++)->ToInt();
        fields.valueC.middle = (params++)->ToInt();
        fields.value10.low = (params++)->ToInt();
        fields.valueC.high = (params++)->ToInt();
        fields.value10.middle = (params++)->ToInt();
        fields.value10.high = (params++)->ToInt();
        fields.value4High = (params++)->ToInt();
        CopyFiveFields020823e4((Obj020823e4 *) &s_entry->initial, (Obj020823e4 *) &fields);
    }
    return 1;
}

// USA: func_020823e4
ARM void CopyFiveFields020823e4(struct Obj020823e4 *dst, struct Obj020823e4 *src) {
    dst->field_0 = src->field_0;
    dst->field_4 = src->field_4;
    dst->field_8 = src->field_8;
    dst->field_c = src->field_c;
    dst->field_10 = src->field_10;
}

struct Variant02030b0c;

// USA: func_02082410
ARM int FillVariantByteTable02082410(Variant02030b0c *elem) {
    int i;
    for (i = 0; i < 0x11; i++) {
        s_entry->variants[i] = (unsigned char) ((Script::Parameter *) elem)->ToInt();
        elem = (Variant02030b0c *) ((char *) elem + sizeof(Script::Parameter));
    }
    int j;
    for (j = 0x11; j < 0x16; j++) {
        s_entry->variants[j] = 0x64;
    }
    return 1;
}

// Main, originally Clear0x54Bytes0208247c (USA 0x0208247c, EUR 0x0208248c, JPN 0x02082db8)
ARM void* ResourceScriptEntry_Init(void* obj) {
    return memset(obj, 0, 0x54);
}

// Main, originally func_02082490 (USA 0x02082490, EUR 0x020824a0, JPN 0x02082dcc)
extern "C" ARM int ResourceScriptEntry_LoadLevel(void *output, void *resource, unsigned int size, int selection, int extra) {
    ResourceScriptEntry *entry = (ResourceScriptEntry *) output;
    Script script;
    memset(entry, 0, sizeof(*entry));
    s_counter = 0;
    s_entry = entry;
    s_maxValue = extra;
    s_selection = selection;
    s_found = 0;
    script.Initialize();
    script.SetOpcodeLookup(data_020f0ff8);
    script.Load(resource, size);
    script.Execute();
    if (s_found != 0) {
        entry->difference.value4Low      = (unsigned short) (entry->final.value4Low - entry->initial.value4Low);
        entry->difference.value0         = entry->final.value0 - entry->initial.value0;
        entry->difference.value8.low     = entry->final.value8.low - entry->initial.value8.low;
        entry->difference.value8.high    = entry->final.value8.high - entry->initial.value8.high;
        entry->difference.value8.middle  = entry->final.value8.middle - entry->initial.value8.middle;
        entry->difference.valueC.low     = entry->final.valueC.low - entry->initial.valueC.low;
        entry->difference.valueC.middle  = entry->final.valueC.middle - entry->initial.valueC.middle;
        entry->difference.value10.low    = entry->final.value10.low - entry->initial.value10.low;
        entry->difference.valueC.high    = entry->final.valueC.high - entry->initial.valueC.high;
        entry->difference.value10.middle = entry->final.value10.middle - entry->initial.value10.middle;
        entry->difference.value10.high   = entry->final.value10.high - entry->initial.value10.high;
        entry->difference.value4High     = (unsigned short) (entry->final.value4High - entry->initial.value4High);
        return entry->final.value4Low;
    }
    return 0;
}

struct StreamHeader;

// USA: func_0208274c
ARM int InitAndRunScript0208274c(void *param0, StreamHeader *param1, int param2, int param3) {
    Script script;
    memset(param0, 0, sizeof(ResourceScriptEntry));
    s_counter = 0;
    s_maxValue = 0;
    s_selection = param3;
    s_entry = (ResourceScriptEntry *) param0;
    s_found = 0;
    script.Initialize();
    script.SetOpcodeLookup(data_020f0ff8);
    script.Load(param1, (unsigned int) param2);
    script.Execute();
    return 0;
}
