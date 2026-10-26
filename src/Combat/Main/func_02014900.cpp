#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"
#include "Filesystem/FileIO.h"

struct StreamHeader;
extern "C" void BmdjScriptState_RunScript(void*, void*, StreamHeader*, unsigned int);

// Main, originally Zone3D::ProcessBMDJFile_02014900 (USA 0x02014900, EUR 0x02014910, JPN 0x020146cc)
// KEEP-NAME: exported Zone3D member ABI, with an explicit receiver here.
extern "C" ARM int _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(
    Zone3D* zone, const void* source, unsigned int sourceLength, ZoneFeatures::Opcode64Entry* entry) {
    SafeAllocator* allocator = zone->pAllocator_68_;
    BmdjScriptNode* node = (BmdjScriptNode*)allocator->Allocate(sizeof(BmdjScriptNode));
    if (node == NULL) return 0;
    BmdjScriptNode_Init(node);
    node->unknown0 = entry->unk_0;
    node->position = entry->vector_4.vec;
    unsigned int var2;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, var2);
    if (script == NULL) return 0;
    BmdjScriptState_RunScript(&node->scriptState, allocator,
                                        (StreamHeader*)script, var2);
    node->next = zone->firstBMDJStruct_41c_;
    zone->firstBMDJStruct_41c_ = node;
    return 1;
}
