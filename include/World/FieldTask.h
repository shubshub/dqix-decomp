#pragma once

#include "Memory/SafeAllocator.h"
#include "NitroSDK/Matrix.h"

// A field task is one node of overlay 17's task queue (GameResources::fieldTaskQueue_, +0x36fc). Each frame
// FieldTaskQueue_Update drops the head task once its done flag is set and runs the new head through
// FieldTask_Update, which calls the update for its kind; FieldTaskQueue_EndAll ends every queued task through
// its kind's end function. Each kind is named after its update, FieldTask_<Kind> (FieldTask_Update's switch); kinds whose
// update has no name yet are left out. Seen in-game, each handler running only while its action did: Talk, OpenCupboard,
// SearchPot, OpenChest.
enum FieldTaskKind {
    FieldTaskKind_Zoom = 1,
    FieldTaskKind_OpenEquipScreen = 2,
    FieldTaskKind_EnterZone = 3,
    FieldTaskKind_ScriptedEvent = 4,
    FieldTaskKind_Talk = 5,
    FieldTaskKind_WalkThroughDoor = 6,
    FieldTaskKind_Battle = 10,
    FieldTaskKind_OpenMenu = 12,
    FieldTaskKind_OpenCupboard = 13,
    FieldTaskKind_ReloadZoneTriggers = 14,
    FieldTaskKind_VisitInn = 15,
    FieldTaskKind_VisitChurch = 16,
    FieldTaskKind_Bank = 17,
    FieldTaskKind_VisitShop = 18,
    FieldTaskKind_ReloadMemberModel = 19,
    FieldTaskKind_LoadZoneMonsters = 20,
    FieldTaskKind_SearchPot = 21,
    FieldTaskKind_EnterBattle = 22,
    FieldTaskKind_PartyPlanning = 23,
    FieldTaskKind_CreatePartyMember = 24,
    FieldTaskKind_WipeoutPrompt = 26,
    FieldTaskKind_Evac = 28,
    FieldTaskKind_ReadBookshelf = 30,
    FieldTaskKind_CallToArms = 32,
    FieldTaskKind_OpenChest = 33,
    FieldTaskKind_PickUpLootPoint = 35,
    FieldTaskKind_LeaveMultiplayer = 39,
    FieldTaskKind_OpenMonsterList = 40,
    FieldTaskKind_TalkToErinn = 42,
    FieldTaskKind_PerformAlchemy = 43,
    FieldTaskKind_ConnectWifi = 44,
    FieldTaskKind_RunMenuScreen = 45,
    FieldTaskKind_ChangeVocation = 46,
    FieldTaskKind_ProfileSettings = 47,
    FieldTaskKind_SetHeroWings = 50,
    FieldTaskKind_SpotGrotto = 51,
    FieldTaskKind_ShowGrottoName = 52,
    FieldTaskKind_PutAwayTreasureMap = 53,
    FieldTaskKind_GrottoBossIntro = 54,
    FieldTaskKind_BoardVehicle = 55,
    FieldTaskKind_ChooseStarflightStop = 56,
    FieldTaskKind_ShipPrompt = 57,
    FieldTaskKind_TalkToPlayerCharacter = 58,
    FieldTaskKind_AcquireTreasureMap = 59,
    FieldTaskKind_SetPartyHpToOne = 60,
    FieldTaskKind_WarpArrival = 61,
    FieldTaskKind_WarpToStarflight = 62,
    FieldTaskKind_StarflightPrompt = 63,
    FieldTaskKind_ReceiveItem = 65,
    FieldTaskKind_SpawnFollower = 66,
    FieldTaskKind_ShowTreasureMapSearchMessage = 67,
    FieldTaskKind_DigPitfall = 68,
    FieldTaskKind_Whistle = 69,
    FieldTaskKind_CastSafePassage = 70,
    FieldTaskKind_TalkToDeadMember = 71,
    FieldTaskKind_ConfirmEvac = 72,
    FieldTaskKind_QuestCancel = 73,
    FieldTaskKind_ShowQuestTutorial = 74,
    FieldTaskKind_SetVocationLevel = 77,
    FieldTaskKind_LeaveGrotto = 78,
};

// The node every field task starts with: the list helpers' layout (AppendNodeToTail, InsertNodeAfterHead,
// ClearListUntilFlagZero).
struct FieldTask {
    signed char kind;      // FieldTaskKind (FieldTask_Update and FieldTaskQueue_EndAll switch on it signed)
    unsigned char done;    // set by the kind's end function; FieldTaskQueue_Update then drops the task
    unsigned char inList;  // set while queued (AppendNodeToTail, InsertNodeAfterHead; ClearListUntilFlagZero clears it)
    unsigned char running; // set while it's the queue's head and not done (ClearListUntilFlagZero)
    FieldTask* next;       // the next queued task
};

// A queue of field tasks (GameResources::fieldTaskQueue_ is the field's): FieldTaskQueue_Update runs it,
// AppendNodeToTail adds to it, FieldTaskQueue_EndAll empties it.
struct FieldTaskQueue {
    FieldTask* head;       // the task that runs
    FieldTask* tail;
};

// What func_0207d538 (and func_0207cf30) write an item's text with; FieldTask_OpenChest, SearchPotTask_Check,
// FieldTask_ReceiveItem and func_ov017_021bf9a0 build one on the stack.
struct LootTextContext {
    SafeAllocator allocator;
    char itemTable[0x18];  // ItemTable_Construct, then ItemTable_Init through InitStruct0207cbe8
    void* containerItems;  // the items to look it up in: the zone's containerItems_ for chests and pots
    int unknown30;         // zeroed by InitStruct0207cbe8
    int unknown34;         // likewise
};

// A FieldTaskKind_Whistle task: FieldTask_Whistle; the chest ambush queues it to start the mimic's encounter
// (FieldTask_InitWhistle sets it up).
struct WhistleTask : FieldTask {
    unsigned short timer;       // ms
    char padA[2];
    int summonedIndex;          // the summoned monster's actor index
    unsigned char step;
    unsigned char silent;       // no "<ACTOR> whistles." message or sound
    unsigned short summonedId;  // func_ov017_021a23e4's result
    int partyMember;            // who whistles (GetPartyMemberByIndex)
    int monsterId;              // the monster to summon (-1: any)
};

// FieldTask_OpenChest's steps (OpenChestTask::step).
enum OpenChestStep {
    OpenChestStep_Start = 0,        // turn to the chest; locked: check the keys, else start the opening animation
    OpenChestStep_LiftLid = 1,      // at 0.4 of the animation: mark the chest opened in the zone, queue event 164
    OpenChestStep_Open = 2,         // at 0.7: hand control back (unless the special item follows; the ambush flag
                                    // is only set in the next step, so a mimic gets it back here too)
    OpenChestStep_GiveContents = 4, // "<name> acquires ..." (or nothing), save that it's opened, empty it
    OpenChestStep_Finish = 5,       // end, or go on to the ambush
    OpenChestStep_Ambush = 6,       // a monster was inside: its message, then the encounter notice
    OpenChestStep_Locked = 8,       // no key that fits: the message stays 750 ms, then end
    OpenChestStep_Unlock = 9,       // a key fits: its message, 15 frames, then LiftLid
};

// A FieldTaskKind_OpenChest task: the player opening a chest (GameResources_StartOpenChest queues it).
struct OpenChestTask : FieldTask {
    unsigned char opener;       // party member index of who opens it
    unsigned char step;         // OpenChestStep
    unsigned char chestIndex;   // in the zone's chest records (Zone3D_GetChest)
    unsigned char special;      // the chest holds item 0x5617: load its extra resources and wait for them
    signed char delay;          // frames left in OpenChestStep_Unlock
    char padD;
    unsigned short timer;       // ms spent in OpenChestStep_Locked
    short facing;               // the angle the opener turns to: towards the chest (GameResources_StartOpenChest)
    char pad12[2];
    Vector3fix position;        // the chest's
    unsigned char fromZoneList; // chest kind 2: contents from the zone's list, not LootableContainerManager
    unsigned char ambush;       // a monster was inside (loot type 3)
    unsigned short monsterId;   // which (named through FieldTask_ambushMonsterIds and FieldTask_ambushMonsterNames)
    int unknown24;              // zeroed by FieldTask_InitOpenChest, otherwise unused here
    short unknown28;            // likewise
    char pad2a[2];
    SafeAllocator allocator;    // for the special item's resources
};

// FieldTask_SearchPot's steps: the index into SearchPotTask_steps, each step function returning the next.
enum SearchPotStep {
    SearchPotStep_Check = 0,       // the pot's container: not searched yet and holding something, else end
    SearchPotStep_PickSprite = 1,  // the item's icon (gold: d_i127)
    SearchPotStep_LoadSprite = 2,  // queue /data/ani/d_<letter><number>.spr (or the special item's resources)
    SearchPotStep_WaitSprite = 3,  // set the icon up once it's loaded
    SearchPotStep_ShowMessage = 4, // "<name> obtains ...", sound effect 14
    SearchPotStep_ShowItem = 5,    // the icon rises over the pot until its timer runs out
    SearchPotStep_Done = 6,        // no step: the task ends
};
