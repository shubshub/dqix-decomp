#pragma once

// Character creation's enums, apart from CharacterCreationUI.h so files with their own creation struct
// can use them.

// CharacterCreationUI::mode: why character creation was opened (the constructor's third argument).
enum CreationMode
{
    CreationMode_NewGame = 0,             // the hero, from the new-game flow (overlay 21)
    CreationMode_PartyMemberCreation = 1, // a new party member, in-game (overlay 3)
};

// Bits of CharacterCreationUI::flags whose meaning is known; the rest are still bare numbers.
enum CreationFlag
{
    CreationFlag_StylusRotation = 0x1, // the preview model can be spun with the stylus
    CreationFlag_LoadNextCharacter = 0x2, // a choice changed: rebuild nextCharacter from characterData
    CreationFlag_SwapCharacters = 0x4,    // nextCharacter is loading; swap it with character once it's done
    CreationFlag_TurnToTarget = 0x8,      // turn character towards targetAngle, then clear
    CreationFlag_ChoiceChanged = 0x10, // the input handler stored a different choice this frame
    CreationFlag_ConfirmTouched = 0x20, // the confirm button was touched this frame
    CreationFlag_BackTouched = 0x40,    // the back button was touched this frame
    CreationFlag_TabLoading = 0x80,    // set on going to a tab, cleared once its graphics have loaded
    CreationFlag_RefreshSummary = 0x100, // rebuild the info window's list of choices (Gender: Male, ...)
    CreationFlag_ShowFinishModels = 0x200, // new game finish: update and draw the wings and the ring effect
    CreationFlag_MemberCreated = 0x400, // mode 1: a party member was created (tab 9); backing out clears it
    CreationFlag_NameAccepted = 0x800, // CharacterCreationUI_CheckName passed the name
    CreationFlag_RedrawTabHighlight = 0x1000, // draw the current tab's highlight line into tileMaps[0]
    CreationFlag_RedrawPanel = 0x2000, // redraw the bottom screen's panel (the keyboard's page, a message)
    CreationFlag_RefreshName = 0x8000, // redraw the Name line of the info window
    CreationFlag_DimBackground = 0x10000,  // new game finish: darken the top screen over dimTimer
    CreationFlag_RescaleOnSwap = 0x20000,  // sex changed: re-read the body size and rescale both models
    CreationFlag_ResetAngleOnSwap = 0x40000, // sex changed: turn character to its default angle before the swap
    CreationFlag_KeyboardOk = 0x200000,    // jpn: the keyboard's OK key was pressed
    CreationFlag_NameRejected = 0x400000, // CharacterCreationUI_CheckName refused the name: its message shows
    CreationFlag_DimWithQuad = 0x800000,  // with DimBackground: fade a black 3D quad in instead
    CreationFlag_HideButtons = 0x1000000, // leave the Confirm and Back button sprites off
};

// CharacterCreationUI::state: the current tab. Each tab's confirm goes to the next tab and back to the
// previous one; name entry's confirm goes to Confirm, and the gender tab's back to Close.
enum CreationTab
{
    CreationTab_Setup = 0,
    CreationTab_Gender = 1,
    CreationTab_BodyType = 2,
    CreationTab_HairStyle = 3,
    CreationTab_HairColor = 4,
    CreationTab_Face = 5,
    CreationTab_SkinColor = 6,
    CreationTab_EyeColor = 7,
    CreationTab_NameEntry = 8,
    CreationTab_Confirm = 9,       // yes/no on the finished character
    CreationTab_NewGameFinish = 10, // new game only: the hero turns to the front, fade out
    CreationTab_Close = 11,        // leave character creation
    CreationTab_Done = 12,
};

// A name: the buffer each sex's name is typed into, and how many characters it holds.
enum CreationName
{
    CreationName_BufferSize = 0x48,
    CreationName_MaxLength = 8,
};

// What CharacterCreationUI_HandleInput returns. A tab icon comes back as CreationInput_TabIcon + its tab.
enum CreationInput
{
    CreationInput_NothingTouched = -4, // CharacterCreationUI_GetTouchedInput: no button, tab icon or slot
    CreationInput_Back = -3,
    CreationInput_Confirm = -2,
    CreationInput_None = -1,
    CreationInput_TabIcon = 100,
    CreationInput_FirstTabIcon = CreationInput_TabIcon + CreationTab_Gender,
    CreationInput_LastTabIcon = CreationInput_TabIcon + CreationTab_NameEntry,
};

// CharacterCreationUI::step on the six choice tabs (body type, hair style, hair colour, face, skin and eye colour).
enum ChoiceTabStep
{
    ChoiceTabStep_Setup = 0,      // slots, layout, cursor on the stored choice, stylus rotation on
    ChoiceTabStep_ShowChoice = 1, // once the tab's graphics have loaded, apply the stored choice to the preview
    ChoiceTabStep_Input = 2,
};

// The divisor the tabs pass to Camera_EasePositionTo / _EaseTargetTo: each update moves the camera 1/30 of the
// remaining way (fx32 30.0).
enum CreationCamera
{
    CreationCamera_EaseSteps = 0x1e000,
};

// Y angles of the preview character (0x6488 is a full turn).
enum CreationAngle
{
    CreationAngle_Default = 0x1eb, // where HandleSetup starts it; the eye colour tab, L+R and a sex change turn it back here
    CreationAngle_Finish = 0x7a,   // what CharacterCreationUI_HandleNewGameFinish turns it to
    CreationAngle_HalfTurn = 0x3244,
    CreationAngle_FullTurn = 0x6488, // FIX_2PI
};

// How long character creation's fades take, in frames (250 ms).
enum CreationFade
{
    CreationFade_Frames = 15,
};

// CharacterCreationUI::resourceStep while a tab's graphics load (logged in-game on a tab change: 1, 2, then 0).
enum TabLoadStep
{
    TabLoadStep_Queue = 0,  // CharacterCreationUI_LoadTabGraphics queues the tab's archive
    TabLoadStep_Wait = 1,   // waiting for the loader
    TabLoadStep_Loaded = 2, // CharacterCreationUI_ApplyTabGraphics builds the layers and sets it back to 0
};

// Keys in character creation's text table (str_cm_<LG>.nat). The file names: key N is tab N's archive, N + 50 the
// file inside it, and N + 100 the female version of tabs 2, 3 and 5. The summary's choice texts: base + the choice
// (Gender, HairStyle and Face also + sex * FemaleOffset). Texts quoted from the usa ROM's str_cm_en.nat.
enum CreationText
{
    CreationText_InnerFileOffset = 50,
    CreationText_FemaleOffset = 100,
    CreationText_Gender = 10000,    // "Male", 10100 "Female"
    CreationText_BodyType = 11000,  // "Type 1", ...
    CreationText_Face = 12000,
    CreationText_EyeColor = 13000,
    CreationText_SkinColor = 14000,
    CreationText_HairStyle = 15000,
    CreationText_HairColor = 16000,
    CreationText_BlankName = 17010, // "*****": jpn's empty name
    CreationText_NewLine = 17011,   // "\n", after each summary line and between Yes and No
    CreationText_WidthTag = 17012,  // "<W=10>": shown for an empty name, and a new pane's first text
    CreationText_Yes = 18010,       // "Yes": the Yes/No menu writes CreationText_Yes + its item
    CreationText_No = 18011,        // "No"
    CreationText_FirstRandomName = 20000, // random names: 20000 + sex * 1000 + n
    CreationText_RandomNameStride = 1000,
};

// CharacterCreationUI::sex, the index of every per-sex choice array.
enum CreationSex
{
    CreationSex_Male = 0,
    CreationSex_Female = 1,
};

// CharacterCreationUI::allocators: what each one holds (CharacterCreationUI_Allocate creates them, in this order).
enum CreationAllocator
{
    CreationAllocator_MainLayers = 0,
    CreationAllocator_TabLayers = 1,
    CreationAllocator_BottomText = 2,
    CreationAllocator_Characters = 3,
    CreationAllocator_ItemTable = 4,
    CreationAllocator_Texts = 5,
    CreationAllocator_Sprites = 6,
    CreationAllocator_NameFilter = 7,
    CreationAllocator_KeyboardLayout = 8, // usa only
};

// CharacterCreationUI::windows.
enum CreationWindowIndex
{
    CreationWindowIndex_Summary = 0, // the summary list (main screen)
    CreationWindowIndex_Bottom = 1,  // the bottom screen's text
};

// windows[CreationWindowIndex_Bottom]: its panes by id, and its buffer.
enum BottomWindow
{
    BottomWindow_PaneCount = 4,
    BottomWindow_BufferBytes = 0x400,
    BottomWindow_YesNoPane = 1,      // CharacterCreationUI_OpenYesNoWindow opens it, _RefreshYesNoMenu writes it
    BottomWindow_UnknownPane2 = 2,
    BottomWindow_NamePane = 3,
};

// The sprite sets: CharacterCreationUI::mainSprites (subScreen 0) and subSprites (subScreen 1).
enum MainSprites
{
    MainSprites_Count = 6,
};

enum SubSprites
{
    SubSprites_Count = 25,
    SubSprites_FirstFile = 4, // cell_cm_<LG>.pac files 0-3 go to the main set, 4-7 to this one
};

// CharacterCreationUI::step on the confirm tab ("Begin your adventure with this character?").
enum ConfirmStep
{
    ConfirmStep_Open = 0,     // open the Yes/No window (sound effect 5)
    ConfirmStep_Show = 1,     // half-darken the bottom screen's BG0, show the buttons again
    ConfirmStep_Input = 2,    // Yes/No input
    ConfirmStep_Accept = 3,
    ConfirmStep_Decline = 0xff,
};

// The row of tab icons at the top of the touchscreen: icon N is the 16 x 16 square at x = FirstX + N * Size,
// y = Y, for tab N + 1 (CharacterCreationUI_GetTouchedInput, _PlaceSprites, _HandleInput).
enum CreationTabIcon
{
    CreationTabIcon_Count = 8,
    CreationTabIcon_FirstX = 0x78,
    CreationTabIcon_Y = 8,
    CreationTabIcon_Size = 16,
};

// CharacterCreationUI::layers: the six background layers CharacterCreationUI_HandleSetup creates.
enum CreationLayer
{
    CreationLayer_Backdrop = 0,     // main BG1
    CreationLayer_TabHighlight = 1, // main BG2: the current tab's line of the summary
    CreationLayer_SummaryText = 2,  // main BG3: windows[0]
    CreationLayer_Page = 3,         // sub BG0: the tab's page (the keyboard's pages on name entry)
    CreationLayer_Selection = 4,    // sub BG1: the tab's choices and the bottom panel
    CreationLayer_BottomText = 5,   // sub BG2: windows[1]
};
