#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GameState::GetGameObjectByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    return objects_[idx];
}

// Main, originally GameState::GetMaybeWanderingMonsterByIndex (USA 0x0200fd90, EUR 0x0200fda0, JPN 0x0200fbec)
GameObject* GameState::GetWanderingMonsterByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 2))
        return NULL;
    return objects_[idx];
}

GameObject* GameState::GetProtagonist()
{
    return GetGameObjectByIndex(protagonistObjectIndex_);
}

// Main, originally GameState::GetUnknownGameObject (USA 0x0200fddc, EUR 0x0200fdec, JPN 0x0200fc38)
GameObject* GameState::GetLeader()
{
    return GetGameObjectByIndex(unknownObjectIndex_397c_);
}

GameObject* GameState::GetPartyMemberByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x800))
        return NULL;
    return objects_[idx];
}

// Main, originally GameState::GetMaybeFieldMonsterByIndex (USA 0x0200fe2c, EUR 0x0200fe3c, JPN 0x0200fc88)
GameObject* GameState::GetFieldMonsterByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x20))
        return NULL;
    return objects_[idx];
}

GameObject* GameState::GetCombatantByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x80))
        return NULL;
    return objects_[idx];
}