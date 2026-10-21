# Naming pass

Tracks every name we've decided on by hand, versus the placeholder names still in the code. The
placeholders are address names like `func_ov009_02188e70`, or guessed names like `AdvanceStatStep_021865dc`.

- **Decided** means it's applied in the code and renamed in `symbols.txt` for usa, eur and jpn.
- **Placeholder** means it still has its old name. The suggested names below aren't decided yet.

**Every time something is named, update this file in the same commit**: move its row from Placeholders to
Decided, or add a row. `python tools/naming_check.py` fails when a renamed function is missing from the
Decided table, and the local pre-commit hook runs it.

## Conventions

- **Functions:** `Owner_MethodName`. The owner is the class the function will belong to, followed by the
  method name in PascalCase, for example `CharacterCreationUI_LoadSlotLayout`. Once we move to real classes
  the `_` becomes `::`, giving `CharacterCreationUI::LoadSlotLayout()`.
- **Types:** use the prefix of the header they live in. Character creation types are `Creation...`, like
  `CreationNavigation` and `CreationSlotLayout`.
- **Classes that already exist** (like `GameState` in `include/GameState/GameState.h`): make the function a real
  member now, for example `GameState::GetResources()`, instead of `GameState_GetResources`.
- **Data:** `Owner_camelCaseName`, for example `CharacterCreationUI_slotLayouts`.
- **Origin comment:** every renamed function gets this directly above it:
  `// Overlay N, originally func_... (USA/EUR addr, JPN addr)`. Use `Main` for arm9 main functions.
- **Vocabulary for character creation:** a *tab* is one page (gender, body type, ...). A *slot* is a
  position on a tab you can pick: a button, swatch or key. A *choice* is the value picked (`bodyType[sex]`).

## Decided

### Functions

| Name | Original | Overlay | USA/EUR | JPN | What it does |
|---|---|---|---|---|---|
| `GameState::GetResources` | `GetWord0x0_0200fb8c` | Main | `0x0200fb8c` (EUR `0x0200fb9c`) | `0x0200f9e8` | Returns the game state's `pResources_` (its first field). A real member of `GameState`; its 104 callers use `->GetResources()` |
| `CharacterCreationUI_HandleInput` | `func_ov009_02188ee8` | 9 | `0x02188ee8` | `0x02189e04` | Each tab's per-frame input: stylus and D-pad, stores the tab's choice, applies a change; returns -1 (nothing), -2 (confirm), -3 (back) or 101–108 (go to tab 1–8) |
| `GridCursor_GetSelectedIndex` | `ComputeScaledSum0205bb84` | Main | `0x0205bb84` (EUR `0x0205bb94`) | `0x0205cee4` | Returns the selected item's index: `row × columns + column` plus the page offset. Used by menus across the game (26 files) |
| `CharacterCreationUI_SwitchTab` | `SetStatValue021855dc` (jpn `func_ov009_021867bc`) | 9 | `0x021855dc` | `0x021867bc` | Switches to tab N: sets `state`, resets `step` to 0, records the furthest tab reached, sets `CreationFlag_TabLoading` (except tabs 9, 11, 12). The new tab's handler loads its layout on the next frame |
| `CharacterCreationUI_ResetTargetLayout` | `ResetFields021847c4` | 9 | `0x021847c4` | `0x02185828` | Sets every field of the target `CreationSlotLayout` to -1 before a tab's layout is loaded into it |
| `CharacterCreationUI_HandleGenderSelection` | `func_ov009_021863d0` | 9 | `0x021863d0` | `0x02187500` | Gender tab handler (tab 1), run every frame by the tab table |
| `CharacterCreationUI_ApplyChoice` | `func_ov009_02188944` | 9 | `0x02188944` | `0x02189704` | Applies the current tab's choice to the preview models |
| `CharacterCreationUI_SlotToStyleIndex` | `func_ov009_02188b14` | 9 | `0x02188b14` | `0x021898cc` | Converts a face or hairstyle slot into the style number; the order depends on gender |
| `CharacterCreationUI_GetBodyDimensions` | `GetEntryPair02188bf8` | 9 | `0x02188bf8` | `0x021899b0` | Looks up a body type's width and height for the current gender |
| `CharacterCreationUI_SetupSlotNavigation` | `func_ov009_02188c2c` | 9 | `0x02188c2c` | `0x02189af0` | Sets up cursor movement over the current tab's slots (grid size, count, starting slot) |
| `CharacterCreationUI_MoveCursorToSlot` | `func_ov009_02188e70` | 9 | `0x02188e70` | `0x02189d30` | Places and sizes the highlight box on a slot (column = slot % columns, row = slot / columns), with no slide from the old position |
| `CharacterCreationUI_LoadSlotLayout` | `func_ov009_02188d9c` | 9 | `0x02188d9c` | `0x02189c60` | Copies the current tab's entry from `CharacterCreationUI_slotLayouts` into `editor->grid` |
| `CharacterModel_ApplyColors` | `func_ov023_021e540c` | 23 | `0x021e540c` | `0x021e55f0` | Writes a character model's hair, skin and eye palettes into VRAM |
| `CharacterModel_SetScale` | `func_ov023_021e5e68` | 23 | `0x021e5e68` | `0x021e604c` | Scales a character model's parts by body width and height, keeping the head and hair at normal size |
| `CharacterModel_InvalidatePart` | `func_ov023_021e6158` | 23 | `0x021e6158` | `0x021e633c` | Sets one part's loaded model ID to -1, so it reads as having nothing loaded until the next rebuild |

The `CharacterModel_` functions belong to the character model in overlay 23 (10 `Object3D` parts,
`0xc20` bytes), which has no shared type yet; its per-file copies are named like `CharacterModel_021e5974`.

`GridCursor` is the generic menu grid cursor in main, used by menus across the game (character creation's copy is
`navigation`). Its other functions are still placeholders: `Init0205bef8`, `SetupPointerTable0205ba68`,
`SetField0AndPropagate0205bacc`, `GetField0_0205bafc`, `func_0205bb04`, `func_0205bf58`.

### Types

| Name | Original | Where | What it is |
|---|---|---|---|
| `CreationSlotLayout` | `CreationChoiceGrid`, `Struct021847c4` | `include/Resource/CreationSlotLayout.h` | Where a tab's slots sit on the touchscreen: `x, y, width, height, stepX, stepY, columns, rows` |

### Constants

| Name | Original | Where | What it is |
|---|---|---|---|
| `CreationFlag` | (none) | `include/Resource/CharacterCreationUI.h` | Enum of `CharacterCreationUI::flags` bits whose meaning is known |
| `CreationFlag_StylusRotation` | `0x1` | same | The preview model can be spun with the stylus; set once a tab's fade-in finishes |
| `CreationFlag_ChoiceChanged` | `0x10` | same | The input handler stored a different choice this frame |
| `CreationFlag_ConfirmTouched` | `0x20` | same | The confirm button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_BackTouched` | `0x40` | same | The back button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_TabLoading` | `0x80` | same | Set on going to a tab (`SetStatValue021855dc`), cleared by `func_ov009_02184e58` once the tab's graphics have loaded |

### Macros

| Name | Original | In | What it does |
|---|---|---|---|
| `MOVE_CURSOR_TO_TAB_ICON` | `TAB_CURSOR` | `CharacterCreationUI_HandleInput` (both halves) | Puts the 16×16 highlight on tab icon N in the top row (`x = 0x78 + N × 16`, `y = 8`) |

### Data

| Name | Original | Overlay | USA/EUR | JPN | What it is |
|---|---|---|---|---|---|
| `CharacterCreationUI_slotLayouts` | `data_ov009_0218ac04` (jpn `data_ov009_0218bb6c`) | 9 | `0x0218ac04` | `0x0218bb6c` | One `{tab, x, y, w, h, stepX, stepY, cols, rows}` entry per tab, ending in -1. Defined in C for usa; jpn and eur still take it from the ROM |

### Locals

| Name | Original | In |
|---|---|---|
| `currentLayout` | `out` | `CharacterCreationUI_LoadSlotLayout` |
| `characterCreationStep` | `state` | `CharacterCreationUI_ApplyChoice` (usa half) |

## Placeholders

### Role known

| Current name | Overlay | USA | What it does | Suggested |
|---|---|---|---|---|
| `func_ov009_0218454c` | 9 | `0x0218454c` | Character creation constructor: clears its fields | `CharacterCreationUI_Init` |
| `func_ov009_02184a18` | 9 | `0x02184a18` | Per-frame update: model updates, then calls the current tab's handler | `CharacterCreationUI_Update` |
| `func_ov009_02185634` | 9 | `0x02185634` | Tab 0: loading and setup, creates both preview models | `CharacterCreationUI_HandleSetup` |
| `AdvanceStatStep_021865dc` | 9 | `0x021865dc` | Body type tab handler (tab 2) | `CharacterCreationUI_HandleBodyTypeSelection` |
| `AdvanceStatStep_021868c4` | 9 | `0x021868c4` | Hairstyle tab handler (tab 3) | `CharacterCreationUI_HandleHairStyleSelection` |
| `func_ov009_021869d8` | 9 | `0x021869d8` | Hair colour tab handler (tab 4) | `CharacterCreationUI_HandleHairColorSelection` |
| `func_ov009_021866f0` | 9 | `0x021866f0` | Face tab handler (tab 5) | `CharacterCreationUI_HandleFaceSelection` |
| `func_ov009_02186aec` | 9 | `0x02186aec` | Eye colour tab handler (tab 6) | `CharacterCreationUI_HandleEyeColorSelection` |
| `func_ov009_02186c00` | 9 | `0x02186c00` | Skin colour tab handler (tab 7) | `CharacterCreationUI_HandleSkinColorSelection` |
| `func_ov009_02186e00` | 9 | `0x02186e00` | Name entry tab handler (tab 8) | `CharacterCreationUI_HandleNameEntry` |
| `SyncEntryPairAndRefreshFlags_02188454` | 9 | `0x02188454` | Swaps the two preview models once the hidden one has loaded | `CharacterCreationUI_SwapPreviewModels` |
| `UpdateFlag021885b8` | 9 | `0x021885b8` | Starts rebuilding the hidden preview model when flag 2 is set | `CharacterCreationUI_RebuildNextModel` |
| `func_ov009_02188604` | 9 | `0x02188604` | Preview model rotation, including dragging with the stylus | `CharacterCreationUI_UpdatePreviewRotation` |
| `func_ov009_02189854` | 9 | `0x02189854` | Turns a touch point into a slot, button or tab | `CharacterCreationUI_SlotFromTouch` |
| `func_ov023_021e5020` | 23 | `0x021e5020` | Per-frame character model update: polls loads, applies colours once loaded | `CharacterModel_Update` |
| `func_ov023_021e5974` | 23 | `0x021e5974` | Loads a character model's part files from `data/pack_lv5/chara_pd.gp2` | `CharacterModel_Load` |
| `func_ov023_021e447c` | 23 | `0x021e447c` | Swaps another screen's pair of preview models; the screen is unknown | |

### Data

| Current name | Overlay | USA | What it is | Suggested |
|---|---|---|---|---|
| `data_ov009_0218ab9c` | 9 | `0x0218ab9c` | Tab handler table: 13 member function pointers, picked by `state` | `CharacterCreationUI_tabHandlers` |
| `data_ov009_0218aa70` | 9 | `0x0218aa70` | Body width and height per gender and body type | `CharacterCreationUI_bodyDimensions` |
| `data_ov009_0218a9bc` | 9 | `0x0218a9bc` | Slot to style number order | `CharacterCreationUI_styleOrder` |
| `data_ov009_0218aa40` | 9 | `0x0218aa40` | Default appearance template used at setup | `CharacterCreationUI_defaultAppearance` |

### Fields

| Current name | In | What it is | Suggested |
|---|---|---|---|
| `Object3D::unknown_2_` | `include/World/Object3D.h` | ID of the model loaded in this part; -1 means none | `loadedModelId_` |
| `CharacterCreationUI::grid` | `include/Resource/CharacterCreationUI.h` | The current tab's `CreationSlotLayout` | `slotLayout` |
| `CharacterCreationUI::character` / `nextCharacter` | `include/Resource/CharacterCreationUI.h` | The visible and hidden preview models; typed `void*` until a shared `CharacterModel` type exists | |

### Role unknown

| Current name | Overlay | USA | Notes |
|---|---|---|---|
| `func_ov009_0218742c` | 9 | `0x0218742c` | Tab 9 handler |
| `func_ov009_02187b34` | 9 | `0x02187b34` | Tab 10 handler; turns stylus rotation off and rotates the preview to a set angle (`0x7a`) |
| `AdvanceListStep_021883cc` | 9 | `0x021883cc` | Tab 11 handler; leads to tab 12 (done). Backing out of the gender tab goes to tab 11 |
