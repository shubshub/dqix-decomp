#include <globaldefs.h>
#include "World/FieldTask.h"

extern "C" {
    void FieldTask_Zoom(void*, void*);
    void FieldTask_OpenEquipScreen(void*, void*);
    void FieldTask_EnterZone(void*, void*);
    void FieldTask_ScriptedEvent(void*, void*);
    void FieldTask_Talk(void*, void*);
    void FieldTask_WalkThroughDoor(void*, void*);
    void FieldTask_Battle(void*, void*);
    void FieldTask_OpenMenu(void*, void*);
    void FieldTask_OpenCupboard(void*, void*);
    void FieldTask_VisitInn(void*, void*);
    void FieldTask_VisitChurch(void*, void*);
    void FieldTask_Bank(void*, void*);
    void FieldTask_VisitShop(void*, void*);
    void FieldTask_ReloadMemberModel(void*, void*);
    void FieldTask_SearchPot(void*, void*);
    void FieldTask_EnterBattle(void*, void*);
    void FieldTask_PartyPlanning(void*, void*);
    void FieldTask_CreatePartyMember(void*, void*);
    void func_ov017_021aa41c(void*, void*);
    void FieldTask_WipeoutPrompt(void*, void*);
    void FieldTask_Evac(void*, void*);
    void FieldTask_ReadBookshelf(void*, void*);
    void FieldTask_CallToArms(void*, void*);
    void FieldTask_OpenChest(void*, void*);
    void FieldTask_PickUpLootPoint(void*, void*);
    void func_ov017_021af66c(void*, void*);
    void FieldTask_LeaveMultiplayer(void*, void*);
    void FieldTask_OpenMonsterList(void*, void*);
    void func_ov017_021c0850(void*, void*);
    void FieldTask_TalkToErinn(void*, void*);
    void FieldTask_PerformAlchemy(void*, void*);
    void FieldTask_ConnectWifi(void*, void*);
    void FieldTask_RunMenuScreen(void*, void*);
    void FieldTask_ChangeVocation(void*, void*);
    void FieldTask_ProfileSettings(void*, void*);
    void func_ov017_021c16cc(void*, void*);
    void FieldTask_SetHeroWings(void*, void*);
    void FieldTask_SpotGrotto(void*, void*);
    void FieldTask_ShowGrottoName(void*, void*);
    void FieldTask_PutAwayTreasureMap(void*, void*);
    void FieldTask_GrottoBossIntro(void*, void*);
    void FieldTask_BoardVehicle(void*, void*);
    void FieldTask_ChooseStarflightStop(void*, void*);
    void FieldTask_ShipPrompt(void*, void*);
    void FieldTask_TalkToPlayerCharacter(void*, void*);
    void FieldTask_AcquireTreasureMap(void*, void*);
    void FieldTask_SetPartyHpToOne(void*, void*);
    void FieldTask_WarpArrival(void*, void*);
    void FieldTask_WarpToStarflight(void*, void*);
    void FieldTask_StarflightPrompt(void*, void*);
    void FieldTask_ReceiveItem(void*, void*);
    void FieldTask_SpawnFollower(void*, void*);
    void FieldTask_ShowTreasureMapSearchMessage(void*, void*);
    void FieldTask_DigPitfall(void*, void*);
    void FieldTask_Whistle(void*, void*);
    void FieldTask_CastSafePassage(void*, void*);
    void FieldTask_TalkToDeadMember(void*, void*);
    void FieldTask_ConfirmEvac(void*, void*);
    void FieldTask_QuestCancel(void*, void*);
    void FieldTask_ShowQuestTutorial(void*, void*);
    void FieldTask_SetVocationLevel(void*, void*);
    void FieldTask_LeaveGrotto(void*, void*);
}

struct Obj021b4710;
extern "C" void FieldTask_LoadZoneMonsters(Obj021b4710* p, void* context);
extern "C" void func_ov017_021acce4(void*, void*);
struct Obj020dbcc4;
extern "C" void func_020dbcc4(struct Obj020dbcc4* obj, void* context);
extern "C" void func_020dac94(void* objIn, void*);
struct Ctx021a7b38;
extern "C" void func_ov017_021a7b38(Ctx021a7b38* self, void* context);
struct Obj021aef0c;
extern "C" void func_ov017_021aef0c(Obj021aef0c* self, void* context);
struct Entry021b8c84;
extern "C" void FieldTask_ReloadZoneTriggers(Entry021b8c84* obj, void* context);

// Overlay 17, originally func_ov017_021a3544 (USA/EUR 0x021a3544, JPN 0x021a3fb8)
extern "C" ARM void FieldTask_Update(void* queue, void* task) {
    if (!task) return;

    switch (*(signed char*)task) {   // FieldTaskKind
    case FieldTaskKind_Zoom:
        FieldTask_Zoom(task, queue);
        break;
    case FieldTaskKind_OpenEquipScreen:
        FieldTask_OpenEquipScreen(task, queue);
        break;
    case FieldTaskKind_EnterZone:
        FieldTask_EnterZone(task, queue);
        break;
    case FieldTaskKind_Talk:
        FieldTask_Talk(task, queue);
        break;
    case FieldTaskKind_Battle:
        FieldTask_Battle(task, queue);
        break;
    case FieldTaskKind_OpenMenu:
        FieldTask_OpenMenu(task, queue);
        break;
    case FieldTaskKind_OpenCupboard:
        FieldTask_OpenCupboard(task, queue);
        break;
    case FieldTaskKind_ReloadZoneTriggers:
        FieldTask_ReloadZoneTriggers((Entry021b8c84*)task, queue);
        break;
    case FieldTaskKind_VisitInn:
        FieldTask_VisitInn(task, queue);
        break;
    case FieldTaskKind_VisitChurch:
        FieldTask_VisitChurch(task, queue);
        break;
    case FieldTaskKind_Bank:
        FieldTask_Bank(task, queue);
        break;
    case FieldTaskKind_ScriptedEvent:
        FieldTask_ScriptedEvent(task, queue);
        break;
    case FieldTaskKind_VisitShop:
        FieldTask_VisitShop(task, queue);
        break;
    case FieldTaskKind_ReloadMemberModel:
        FieldTask_ReloadMemberModel(task, queue);
        break;
    case FieldTaskKind_LoadZoneMonsters:
        FieldTask_LoadZoneMonsters((Obj021b4710*)task, queue);
        break;
    case FieldTaskKind_SearchPot:
        FieldTask_SearchPot(task, queue);
        break;
    case FieldTaskKind_EnterBattle:
        FieldTask_EnterBattle(task, queue);
        break;
    case FieldTaskKind_PartyPlanning:
        FieldTask_PartyPlanning(task, queue);
        break;
    case FieldTaskKind_CreatePartyMember:
        FieldTask_CreatePartyMember(task, queue);
        break;
    case 25:
        func_ov017_021aa41c(task, queue);
        break;
    case FieldTaskKind_WipeoutPrompt:
        FieldTask_WipeoutPrompt(task, queue);
        break;
    case FieldTaskKind_WalkThroughDoor:
        FieldTask_WalkThroughDoor(task, queue);
        break;
    case FieldTaskKind_Evac:
        FieldTask_Evac(task, queue);
        break;
    case FieldTaskKind_ReadBookshelf:
        FieldTask_ReadBookshelf(task, queue);
        break;
    case 31:
        func_ov017_021acce4(task, queue);
        break;
    case FieldTaskKind_CallToArms:
        FieldTask_CallToArms(task, queue);
        break;
    case FieldTaskKind_OpenChest:
        FieldTask_OpenChest(task, queue);
        break;
    case FieldTaskKind_PickUpLootPoint:
        FieldTask_PickUpLootPoint(task, queue);
        break;
    case 37:
        func_ov017_021aef0c((Obj021aef0c*)task, queue);
        break;
    case 38:
        func_ov017_021af66c(task, queue);
        break;
    case FieldTaskKind_LeaveMultiplayer:
        FieldTask_LeaveMultiplayer(task, queue);
        break;
    case FieldTaskKind_OpenMonsterList:
        FieldTask_OpenMonsterList(task, queue);
        break;
    case 41:
        func_ov017_021c0850(task, queue);
        break;
    case FieldTaskKind_TalkToErinn:
        FieldTask_TalkToErinn(task, queue);
        break;
    case FieldTaskKind_PerformAlchemy:
        FieldTask_PerformAlchemy(task, queue);
        break;
    case FieldTaskKind_ConnectWifi:
        FieldTask_ConnectWifi(task, queue);
        break;
    case FieldTaskKind_RunMenuScreen:
        FieldTask_RunMenuScreen(task, queue);
        break;
    case FieldTaskKind_ChangeVocation:
        FieldTask_ChangeVocation(task, queue);
        break;
    case FieldTaskKind_ProfileSettings:
        FieldTask_ProfileSettings(task, queue);
        break;
    case 48:
        func_ov017_021c16cc(task, queue);
        break;
    case FieldTaskKind_SetHeroWings:
        FieldTask_SetHeroWings(task, queue);
        break;
    case FieldTaskKind_SpotGrotto:
        FieldTask_SpotGrotto(task, queue);
        break;
    case FieldTaskKind_AcquireTreasureMap:
        FieldTask_AcquireTreasureMap(task, queue);
        break;
    case FieldTaskKind_ShowGrottoName:
        FieldTask_ShowGrottoName(task, queue);
        break;
    case FieldTaskKind_PutAwayTreasureMap:
        FieldTask_PutAwayTreasureMap(task, queue);
        break;
    case FieldTaskKind_GrottoBossIntro:
        FieldTask_GrottoBossIntro(task, queue);
        break;
    case FieldTaskKind_BoardVehicle:
        FieldTask_BoardVehicle(task, queue);
        break;
    case FieldTaskKind_ChooseStarflightStop:
        FieldTask_ChooseStarflightStop(task, queue);
        break;
    case FieldTaskKind_ShipPrompt:
        FieldTask_ShipPrompt(task, queue);
        break;
    case FieldTaskKind_TalkToPlayerCharacter:
        FieldTask_TalkToPlayerCharacter(task, queue);
        break;
    case FieldTaskKind_SetPartyHpToOne:
        FieldTask_SetPartyHpToOne(task, queue);
        break;
    case FieldTaskKind_WarpArrival:
        FieldTask_WarpArrival(task, queue);
        break;
    case FieldTaskKind_WarpToStarflight:
        FieldTask_WarpToStarflight(task, queue);
        break;
    case FieldTaskKind_StarflightPrompt:
        FieldTask_StarflightPrompt(task, queue);
        break;
    case 64:
        func_ov017_021a7b38((Ctx021a7b38*)task, queue);
        break;
    case FieldTaskKind_ReceiveItem:
        FieldTask_ReceiveItem(task, queue);
        break;
    case FieldTaskKind_SpawnFollower:
        FieldTask_SpawnFollower(task, queue);
        break;
    case FieldTaskKind_ShowTreasureMapSearchMessage:
        FieldTask_ShowTreasureMapSearchMessage(task, queue);
        break;
    case FieldTaskKind_DigPitfall:
        FieldTask_DigPitfall(task, queue);
        break;
    case FieldTaskKind_Whistle:
        FieldTask_Whistle(task, queue);
        break;
    case FieldTaskKind_CastSafePassage:
        FieldTask_CastSafePassage(task, queue);
        break;
    case FieldTaskKind_TalkToDeadMember:
        FieldTask_TalkToDeadMember(task, queue);
        break;
    case FieldTaskKind_ConfirmEvac:
        FieldTask_ConfirmEvac(task, queue);
        break;
    case FieldTaskKind_QuestCancel:
        FieldTask_QuestCancel(task, queue);
        break;
    case FieldTaskKind_ShowQuestTutorial:
        FieldTask_ShowQuestTutorial(task, queue);
        break;
    case 75:
        func_020dac94(task, queue);
        break;
    case 76:
        func_020dbcc4((Obj020dbcc4*)task, queue);
        break;
    case FieldTaskKind_SetVocationLevel:
        FieldTask_SetVocationLevel(task, queue);
        break;
    case FieldTaskKind_LeaveGrotto:
        FieldTask_LeaveGrotto(task, queue);
        break;
    default:
        break;
    }
}
