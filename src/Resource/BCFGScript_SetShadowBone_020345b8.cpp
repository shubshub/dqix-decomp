#include "Resource/BCFG.h"
#include "Resource/Script.h"

#pragma pool_strings on
#pragma dont_reuse_strings off

// The BCFG the opcode handlers fill while LoadFromScript runs its script, and where they allocate
struct BCFGScriptState
{
    SafeAllocator* allocator;
    BCFG* pBCFG;
} static currentBCFGScriptData;

// Main, originally BCFGScript_Opcode_64 (USA 0x020343a0, EUR 0x020343b0, JPN 0x02033dfc)
int BCFGScript_AllocateAnimations(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateAnimationEntries(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

// Main, originally BCFGScript_Opcode_65 (USA 0x020343c8, EUR 0x020343d8, JPN 0x02033e24)
int BCFGScript_EndAnimations(Script::Parameter* params, int paramCount)
{
    return 1;
}

// Main, originally BCFGScript_Opcode_66 (USA 0x020343d0, EUR 0x020343e0, JPN 0x02033e2c)
int BCFGScript_AddAnimation(Script::Parameter* params, int paramCount)
{
    const char* name = params[0].ToString();
    int success;
    if (name == NULL)
        success = false;
    else
    {
        BCFG::AnimationRecord entry;
        strcpy(entry.name, name);
        entry.startTime = 4096 * params[1].ToFloat();
        entry.endTime = 4096 * params[2].ToFloat();
        entry.frameRate = 4096 * params[3].ToFloat();
        entry.firstSizeC = NULL;
        entry.firstAlt = 0;
        currentBCFGScriptData.pBCFG->InsertAnimationRecord(&entry);
        success = true;
    }
    return success;
}

int BCFGScript_Opcode_6a(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateSizeCEntries(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

int BCFGScript_Opcode_6b(Script::Parameter* params, int paramCount)
{
    return 1;
}

// when enemies have these it's nearly always only attack1 or attack1a,
// i.e. the regular attack.
int BCFGScript_Opcode_6c(Script::Parameter* params, int paramCount)
{
    BCFG::SizeCEntry entry;

    entry.animationIndex = currentBCFGScriptData.pBCFG->SearchAnimationByName(params[0].ToString());
    entry.unk_4 = 4096 * params[1].ToFloat();
    entry.unk_0 = params[2].ToInt();
    currentBCFGScriptData.pBCFG->InsertSizeCEntry(&entry);
    return 1;
}

// Main, originally BCFGScript_Opcode_6d (USA 0x02034518, EUR 0x02034528, JPN 0x02033f74)
int BCFGScript_AllocateSoundTriggers(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateSoundTriggers(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

// Main, originally BCFGScript_Opcode_6e (USA 0x02034540, EUR 0x02034550, JPN 0x02033f9c)
int BCFGScript_EndSoundTriggers(Script::Parameter* params, int paramCount)
{
    return 1;
}

// Main, originally BCFGScript_Opcode_6f (USA 0x02034548, EUR 0x02034558, JPN 0x02033fa4)
int BCFGScript_AddSoundTrigger(Script::Parameter* params, int paramCount)
{
    BCFG::AltSizeCEntry entry;

    entry.animationIndex = currentBCFGScriptData.pBCFG->SearchAnimationByName(params[0].ToString());
    entry.triggerTime = 4096 * params[1].ToFloat();
    entry.maybeSoundEffect = params[2].ToInt();
    currentBCFGScriptData.pBCFG->InsertSoundTrigger(&entry);
    return 1;
}

// Main, originally BCFGScript_Opcode_71 (USA 0x020345b8, EUR 0x020345c8, JPN 0x02034014)
int BCFGScript_SetShadowBone(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->SetShadowBoneName(currentBCFGScriptData.allocator, params[0].ToString());
    return 1;
}

Script::OpcodeLookupEntry bcfgScriptOpcodes[] = {
    { 0x64, &BCFGScript_AllocateAnimations },
    { 0x65, &BCFGScript_EndAnimations },
    { 0x66, &BCFGScript_AddAnimation },
    { 0x6a, &BCFGScript_Opcode_6a },
    { 0x6b, &BCFGScript_Opcode_6b },
    { 0x6c, &BCFGScript_Opcode_6c },
    { 0x6d, &BCFGScript_AllocateSoundTriggers },
    { 0x6e, &BCFGScript_EndSoundTriggers },
    { 0x6f, &BCFGScript_AddSoundTrigger },
    { 0x71, &BCFGScript_SetShadowBone },
    { 0 }
};

void BCFG::Reset()
{
    animations_ = NULL;
    maybeAnimationCount = 0;
    maybeAnimationCapacity = 0;
    sizeCEntries_ = NULL;
    sizeCCapacity_ = 0;
    sizeCCount_ = 0;
    altSizeCEntries_ = NULL;
    altSizeCCount_ = 0;
    altSizeCCapacity_ = 0;
    unknown_18 = 0xffff;
    maybeRootBoneName_ = NULL;
}

void BCFG::LoadFromScript(SafeAllocator* alloc, const void *data, unsigned int length)
{
    if (length != 0 && data != NULL)
    {
        currentBCFGScriptData.pBCFG = this;
        currentBCFGScriptData.allocator = alloc;
        Script script;           
        script.Initialize();
        script.SetOpcodeLookup(bcfgScriptOpcodes);
        script.Load(data, length);
        script.Execute();
        if (currentBCFGScriptData.pBCFG->maybeRootBoneName_ == NULL)
            currentBCFGScriptData.pBCFG->SetShadowBoneName(alloc, "waist");
        currentBCFGScriptData.pBCFG = NULL;
        currentBCFGScriptData.allocator = NULL;
    }
}

void BCFG::AllocateAnimationEntries(SafeAllocator *alloc, int count)
{
    if (alloc == NULL)
        return;

    animations_ = (AnimationRecord*)alloc->Allocate(count * sizeof(AnimationRecord));
    if (animations_ != NULL)
    {
        maybeAnimationCount = 0;
        maybeAnimationCapacity = count;
    }
    else
    {
        maybeAnimationCount = 0;
        maybeAnimationCapacity = 0;
    }
}

void BCFG::InsertAnimationRecord(const AnimationRecord *entry)
{
    if (maybeAnimationCapacity > maybeAnimationCount)
    {
        AnimationRecord* dest = &animations_[maybeAnimationCount++];
        COPY_ARRAY(dest->name, entry->name);
        dest->startTime = entry->startTime;
        dest->endTime = entry->endTime;
        dest->frameRate = entry->frameRate;
        dest->firstSizeC = entry->firstSizeC;
        dest->firstAlt = entry->firstAlt;
    }
}

int BCFG::SearchAnimationByName(const char* name)
{
    for (int i = 0; i < maybeAnimationCount; i++)
    {
        if (strcmp(animations_[i].name, name) == 0)
            return i;
    }
    return -1;
}

BCFG::AnimationRecord* BCFG::GetAnimationRecord(int idx)
{
    if (idx < 0 || maybeAnimationCount <= idx)
        return NULL;
    return &animations_[idx];
}

int BCFG::GetNumAnimations() const
{
    return maybeAnimationCount;
}

void BCFG::AllocateSizeCEntries(SafeAllocator *alloc, int count)
{
    sizeCEntries_ = (SizeCEntry*)alloc->Allocate(count * sizeof(SizeCEntry));
    if (sizeCEntries_ != NULL)
    {
        sizeCCapacity_ = count;
        sizeCCount_ = 0;
    }
    else
    {
        sizeCCapacity_ = 0;
        sizeCCount_ = 0;
    }
}

void BCFG::InsertSizeCEntry(const SizeCEntry *entry)
{
    if (sizeCCapacity_ > sizeCCount_)
    {
        AnimationRecord* anim = GetAnimationRecord(entry->animationIndex);
        if (anim == NULL)
            return;
        SizeCEntry* dest = &sizeCEntries_[sizeCCount_];
        dest->unk_0 = entry->unk_0;
        dest->animationIndex = entry->animationIndex;
        dest->unk_4 = entry->unk_4;
        dest->pNext = entry->pNext;
        sizeCEntries_[sizeCCount_].pNext = anim->firstSizeC;
        anim->firstSizeC = &sizeCEntries_[sizeCCount_];
        sizeCCount_++;
    }
}

// Main, originally BCFG::AllocateAltSizeCEntries (USA 0x020348b4, EUR 0x020348c4, JPN 0x02034310)
void BCFG::AllocateSoundTriggers(SafeAllocator *alloc, int count)
{
    altSizeCEntries_ = (AltSizeCEntry*)alloc->Allocate(count * sizeof(AltSizeCEntry));
    if (altSizeCEntries_ != NULL)
    {
        altSizeCCapacity_ = count;
        altSizeCCount_ = 0;
    }
    else
    {
        altSizeCCapacity_ = 0;
        altSizeCCount_ = 0;
    }
}

// Main, originally BCFG::InsertAltSizeCEntry (USA 0x020348ec, EUR 0x020348fc, JPN 0x02034348)
void BCFG::InsertSoundTrigger(const AltSizeCEntry *entry)
{
    if (altSizeCCapacity_ > altSizeCCount_)
    {
        AnimationRecord* anim = GetAnimationRecord(entry->animationIndex);
        if (anim == NULL)
            return;
        AltSizeCEntry* dest = &altSizeCEntries_[altSizeCCount_];
        dest->maybeSoundEffect = entry->maybeSoundEffect;
        dest->animationIndex = entry->animationIndex;
        dest->triggerTime = entry->triggerTime;
        dest->pNext = entry->pNext;
        altSizeCEntries_[altSizeCCount_].pNext = anim->firstAlt;
        anim->firstAlt = &altSizeCEntries_[altSizeCCount_];
        altSizeCCount_++;
    }
}

// Main, originally BCFG::MaybeSetRootBoneName (USA 0x02034980, EUR 0x02034990, JPN 0x020343dc)
void BCFG::SetShadowBoneName(SafeAllocator *alloc, const char *name)
{
    maybeRootBoneName_ = (char*)alloc->Allocate(strlen(name) + 1);
    if (maybeRootBoneName_ != NULL)
        strcpy(maybeRootBoneName_, name);
}

// Main, originally BCFG::MaybeGetRootBoneName (USA 0x020349c0, EUR 0x020349d0, JPN 0x0203441c)
const char *BCFG::GetShadowBoneName()
{
    return maybeRootBoneName_;
}