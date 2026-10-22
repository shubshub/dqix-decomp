# Naming pass

Tracks every name we've decided on by hand, versus the placeholder names still in the code. The
placeholders are address names like `func_ov009_02188e70`, or guessed names like `SyncEntryPairAndRefreshFlags_02188454`.

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
| `CharacterCreationUI_HandleBodyType` | `func_ov009_021865dc` (file `AdvanceStatStep_021865dc.cpp`) | 9 | `0x021865dc` | `0x02187708` | Body type tab handler (tab 2), run every frame by the tab table. Confirm goes to HairStyle, Back to Gender |
| `CharacterCreationUI_HandleSetup` | `func_ov009_02185634` | 9 | `0x02185634` | `0x02186814` | Tab 0 handler: loading and setup, creates both preview models, then goes to Gender |
| `CharacterCreationUI_HandleHairStyle` | `func_ov009_021868c4` (file `AdvanceStatStep_021868c4.cpp`) | 9 | `0x021868c4` | `0x021879f0` | Hairstyle tab handler (tab 3). Confirm goes to HairColor, Back to BodyType |
| `CharacterCreationUI_HandleHairColor` | `func_ov009_021869d8` | 9 | `0x021869d8` | `0x02187b04` | Hair colour tab handler (tab 4). Confirm goes to Face, Back to HairStyle |
| `CharacterCreationUI_HandleFace` | `func_ov009_021866f0` | 9 | `0x021866f0` | `0x0218781c` | Face tab handler (tab 5). Confirm goes to EyeColor, Back to HairColor |
| `CharacterCreationUI_HandleEyeColor` | `func_ov009_02186aec` | 9 | `0x02186aec` | `0x02187c18` | Eye colour tab handler (tab 6). Confirm goes to SkinColor, Back to Face |
| `CharacterCreationUI_HandleSkinColor` | `func_ov009_02186c00` | 9 | `0x02186c00` | `0x02187d2c` | Skin colour tab handler (tab 7). Confirm goes to NameEntry, Back to EyeColor |
| `CharacterCreationUI_HandleNameEntry` | `func_ov009_02186e00` | 9 | `0x02186e00` | `0x02187f2c` | Name entry tab handler (tab 8). Confirm goes to tab 9, Back to SkinColor; jpn has its own body |
| `CharacterCreationUI_HandleConfirm` | `func_ov009_0218742c` | 9 | `0x0218742c` | `0x021881fc` | Tab 9: yes/no on the finished character. No goes back to NameEntry; yes goes to tab 10 in a new game, or for a party member gives it its level's abilities, adds it to the party, sets `CreationFlag_MemberCreated` and goes to tab 11 |
| `CharacterCreationUI_HandleNewGameFinish` | `func_ov009_02187b34` | 9 | `0x02187b34` | `0x021888f0` | Tab 10, new game only: turns the hero to face front (`targetAngle_ = 0x7a`), loads the final model files, fades to white then black, then goes to tab 11 |
| `CharacterCreationUI_HandleClose` | `func_ov009_021883cc` (file `AdvanceListStep_021883cc.cpp`) | 9 | `0x021883cc` | `0x0218918c` | Tab 11: turns the brightness effect off, resets the windows and goes to tab 12 (done). Backing out of the Gender tab also comes here |
| `Keyboard_TypeCharacter` | `func_ov003_0215ec90` | 3 | `0x0215ec90` | none (its keyboard differs) | Key action 0 of the software keyboard (slot 0 of `data_ov003_0217f3c8`, which `Keyboard_HandleKey` indexes with the key's action byte): adds the key's character, shifted when the shift mode matches the page, after the text, or over the last one when it's full; refuses one that would pass the pixel width limit. Returns 2 (typed), 3 (typed, now full), 0 (didn't fit), 0xd (a command key). Writes the name on character creation's name entry |
| `Keyboard_Update` | `func_ov003_0215f000` | 3 | `0x0215f000` | not identified | The keyboard's per-frame update: D-pad moves the cursor (with auto-repeat while held), A (or L with `allowAlt_`) or a touch runs the key's action, B deletes (with `allowCancel_`); returns a `KeyboardResult`. Seen in-game: Right gives 1, typing `q` 2, each action key its code |
| `Keyboard_HandleKey` | `func_ov003_0215ef54` (file `Dispatch_0215ef54.cpp`) | 3 | `0x0215ef54` | not identified | Runs the selected key's action: calls slot `key->action_` of `data_ov003_0217f3c8` |
| `Keyboard_ResetToKey` | `func_ov003_0215f41c` (file `FindEntryByName_0215f41c.cpp`) | 3 | `0x0215f41c` | not identified | Resets the keyboard (no key, timers 0, lowercase page, shift off) and puts the cursor on the key labelled `text`; name entry passes `"1"`, the top-left key |
| `Keyboard_FindKeyByAction` | `func_ov003_0215f4a4` (file `FindElementByFieldD_0215f4a4.cpp`) | 3 | `0x0215f4a4` | not identified | The first key whose `action_` matches, or NULL |
| `Keyboard_SelectKeyByAction` | `StoreResultIfNonZero_0215f4e4` | 3 | `0x0215f4e4` | not identified | Puts the cursor on the first key with that action, if there is one; name entry moves it to OK |
| `Keyboard_GetKeySize` | `func_ov003_0215ec68` (file `Trans_0215ec68.cpp`) | 3 | `0x0215ec68` | not identified | Width and height of a key's size class (1 normal, 2 the tall shift key, 3 the space bar), from two tables; sizes the highlight box |
| `CharacterCreationUI_CheckName` | `func_ov009_02189a4c` (file `02189a4c.cpp`) | 9 | `0x02189a4c` | not identified (jpn's `func_ov009_0218ad0c` is a different, 0x444-byte check) | Loads the forbidden-word lists and checks the name against them: sets `CreationFlag_NameRejected` or `CreationFlag_NameAccepted`. Does nothing for an empty name |
| `CharacterCreationUI_PickRandomName` | `ResetEntrySkill0218a8b8` | 9 | `0x0218a8b8` | not identified | Clears the name and writes a random one: text `0x4e20 + sex × 1000 + rand() % count[sex]`. Select does it in-game (got "Rubin") |
| `CharacterCreationUI_RefreshNameText` | `BuildFieldTag_021d9e60` | 23 | `0x021d9e60` | `0x021da6f0` | When `CreationFlag_RefreshName` is set, redraws the Name line of the info window: on the name tab the name padded to 8 with `nameFill_`, centred; else text `0x4274` |
| `GridCursor_Init` | `Init0205bef8` | Main | `0x0205bef8` (EUR `0x0205bf08`) | `0x0205d258` | Resets a grid cursor: one cell, nothing selected, auto-repeat after 20 then every 10 |
| `GridCursor_SetDimensions` | `SetupPointerTable0205ba68` | Main | `0x0205ba68` (EUR `0x0205ba78`) | `0x0205cdc8` | Sets columns, rows and the cell order (`GridCursorOrder`): which of column and row counts first |
| `GridCursor_SetCount` | `SetField0AndPropagate0205bacc` | Main | `0x0205bacc` (EUR `0x0205badc`) | `0x0205ce2c` | Sets how many cells hold something, moving the selection back onto the last one if it was past it |
| `GridCursor_SetSelectedIndex` | `func_0205bb04` (file `ComputeDivisions0205bb04.cpp`) | Main | `0x0205bb04` (EUR `0x0205bb14`) | `0x0205ce64` | Selects cell N: page, column and row from the index; the inverse of `GridCursor_GetSelectedIndex` |
| `Font_FindCharacter` | `FindEntryByKey0204254c` | Main | `0x0204254c` (EUR `0x0204255c`) | not identified | The character entry of font N for a character (its text compared byte for byte); entries carry the glyph width at `+4` |
| `SePlayer_Play` | `DispatchWithShortB4_0205eaa0` | Main | `0x0205eaa0` (EUR `0x0205eab0`) | `0x0205fd8c` | Plays sound effect N from the archive the player holds (`+0xb4`). Logged in-game: 2 on every cursor move, 1 on every key press |
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
`navigation`). Its other functions are still placeholders: `InitStruct_0205ba2c`, `GetField0_0205bafc`, `func_0205bf58`.

The `Keyboard_` functions belong to the software keyboard in overlay 3 that names are typed on. Each file still has
its own copy of the `Keyboard` struct.

### Types

| Name | Original | Where | What it is |
|---|---|---|---|
| `CreationSlotLayout` | `CreationChoiceGrid`, `Struct021847c4` | `include/Resource/CreationSlotLayout.h` | Where a tab's slots sit on the touchscreen: `x, y, width, height, stepX, stepY, columns, rows` |
| `Keyboard` | `NameInput0215ec90` | file-local in `Keyboard_TypeCharacter` and `CharacterCreationUI_HandleNameEntry` | The software keyboard: the pressed `key`, the `text` being edited, its pixel `widthLimit` and `maxLen`, the page `state`, the `font` and the one-shot `shiftMode` |
| `KeyboardKey` | `Key0215ec90` | same files | One key: its character `code`, its `shiftedCode`, the action byte at `+0xd` (its slot in the key action table) and `isCommand` |
| `SePlayer` | `Obj0205eaa0` | `include/Sound/SePlayer.h` | The menu sound effect player; the one instance is `g_sePlayer` |
| `FontCharacter` | `CharacterInfo` | `CharacterCreationUI_HandleNameEntry_02186e00.cpp` (file-local) | What `Font_FindCharacter` returns: the character's `text_` and its glyph `width_` |
| `GridCursor` | `WindowCursor` | `CharacterCreationUI_HandleNameEntry_02186e00.cpp` (file-local) | The menu grid cursor (`CreationNavigation` in the header): `count_` is how many cells hold something |

### Constants

| Name | Original | Where | What it is |
|---|---|---|---|
| `CreationTab` | (none) | `include/Resource/CharacterCreationUI.h` | Enum of `CharacterCreationUI::state`, the current tab |
| `CreationTab_Confirm`, `_NewGameFinish`, `_Close` | 9, 10, 11 | `include/Resource/CharacterCreationUI.h` | The tabs `CharacterCreationUI_HandleConfirm`, `_HandleNewGameFinish` and `_HandleClose` run |
| `CreationFlag_RefreshSummary` | `0x100` | `include/Resource/CharacterCreationUI.h` | Read by `BuildElemPaletteTags_021d9a6c`, which rebuilds the info window's list (keys `0x2710 + sex × 100`, body type, hairstyle ...) and clears it |
| `CreationFlag_NameAccepted` | `0x800` | same | Set by `CharacterCreationUI_CheckName` for an allowed name; name entry then goes to the Confirm tab |
| `CreationFlag_RedrawPanel` | `0x2000` | same | Read by `func_ov009_02184ca4` and `func_ov023_021da274`: redraw the bottom panel (tile map 3, the keyboard's page, the rejection message), then cleared |
| `CreationFlag_RefreshName` | `0x8000` | same | Read by `CharacterCreationUI_RefreshNameText`, which redraws the Name line and clears it |
| `CreationFlag_NameRejected` | `0x400000` | same | Set by `CharacterCreationUI_CheckName` for a forbidden name; the panel shows its message and name entry waits for A, X, a touch or B |
| `CreationFlag_HideButtons` | `0x1000000` | same | `ConfigureEntryPositions_021da770` places the Confirm and Back sprites only while it's clear |
| `CreationName_BufferSize`, `_MaxLength` | `0x48`, 8 | same | A name's buffer and its 8 characters |
| `KeyboardPage` | 1, 2, 4, 8 | `include/Resource/Keyboard.h` | The keyboard's pages (lowercase, uppercase, accents, symbols); each key has a mask of the pages it shows on. Read from the live key list |
| `KeyboardAction` | 0-8 | same | A key's action, its slot in the key action table. The name keyboard has: type, caps (1), shift (2), A/1 (3), À (4), ← (5), OK (6), @ (7); 8 (random name) has no key |
| `KeyboardResult` | 0-13 | same | What `Keyboard_Update` returns. Each confirmed in-game by pressing the key and logging `keyboardResult_` |
| `KeyboardGrid` | 11, 6, 66 | same | The name keyboard as a 11 × 6 grid for the `GridCursor` |
| `GridCursorOrder` | 0, 1 | `include/Resource/GridCursor.h` | Cell order for `GridCursor_SetDimensions`; 1 counts across a row first (`GridCursor_GetSelectedIndex`) |
| `SoundEffect_Select`, `_Cursor` | 1, 2 | `include/Sound/SePlayer.h` | The menu sound effects, logged in-game: 1 on key presses, 2 on cursor moves |
| `CreationTab_Setup` … `CreationTab_NameEntry` | `0`–`8` | same | Setup, Gender, BodyType, HairStyle, HairColor, Face, EyeColor, SkinColor, NameEntry. Each tab's confirm goes to the next, back to the previous |
| `CreationTab_Done` | `12` | same | Character creation finished; tabs 9–11 are still numbers |
| `CreationInput` | (none) | same | Enum of what `CharacterCreationUI_HandleInput` returns |
| `CreationInput_Back` / `_Confirm` / `_None` | `-3` / `-2` / `-1` | same | B or the touchscreen Back button / A or the touchscreen Confirm button / nothing |
| `CreationInput_TabIcon` | `100` | same | A tab icon comes back as `CreationInput_TabIcon + tab`; `_FirstTabIcon` (101) and `_LastTabIcon` (108) bound the range |
| `Brightness` | (none) | `include/Resource/Brightness.h` | Master brightness levels, as `GetBrightness` returns them and the `Set*Brightness` functions take them (whose `duration` is in frames: `15` = 250 ms) |
| `Brightness_Black` / `_Normal` / `_White` | `-16` / `0` / `16` | same | Fully black / normal / fully white. `abs(GetBrightness(...)) == 16` (fully faded either way) is still a number in three overlay 17 files |
| `CreationMode` | (none) | `include/Resource/CharacterCreationUI.h` | Enum of `CharacterCreationUI::mode`: why character creation was opened (the constructor's third argument) |
| `CreationMode_NewGame` | `0` | same | The hero, from the new-game flow (overlay 21, `func_ov021_0218b5fc`). Success sets `GameState::characterCreated_` |
| `CreationMode_PartyMemberCreation` | `1` | same | A new party member, in-game (overlay 3, `0217e6b0.cpp`, which also passes the vocation). Success sets `CreationFlag_MemberCreated` |
| `CreationFlag` | (none) | `include/Resource/CharacterCreationUI.h` | Enum of `CharacterCreationUI::flags` bits whose meaning is known |
| `CreationFlag_StylusRotation` | `0x1` | same | The preview model can be spun with the stylus; set once a tab's fade-in finishes |
| `CreationFlag_ChoiceChanged` | `0x10` | same | The input handler stored a different choice this frame |
| `CreationFlag_ConfirmTouched` | `0x20` | same | The confirm button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_BackTouched` | `0x40` | same | The back button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_MemberCreated` | `0x400` | same | Mode 1 (party member creation): set by tab 9 once the new member is set up and added to the party, cleared on backing out of the gender tab. Mode 0's counterpart is `GameState::characterCreated_` |
| `CreationFlag_TabLoading` | `0x80` | same | Set on going to a tab (`SetStatValue021855dc`), cleared by `func_ov009_02184e58` once the tab's graphics have loaded |

### Macros

| Name | Original | In | What it does |
|---|---|---|---|
| `MOVE_CURSOR_TO_TAB_ICON` | `TAB_CURSOR` | `CharacterCreationUI_HandleInput` (both halves) | Puts the 16×16 highlight on tab icon N in the top row (`x = 0x78 + N × 16`, `y = 8`) |

### Data

| Name | Original | Overlay | USA/EUR | JPN | What it is |
|---|---|---|---|---|---|
| `CharacterCreationUI_slotLayouts` | `data_ov009_0218ac04` (jpn `data_ov009_0218bb6c`) | 9 | `0x0218ac04` | `0x0218bb6c` | One `{tab, x, y, w, h, stepX, stepY, cols, rows}` entry per tab, ending in -1. Defined in C for usa; jpn and eur still take it from the ROM |
| `g_sePlayer` | `data_02108760` | Main | `0x02108760` | `0x02108760` (same name) | The menu sound effect player passed to `SePlayer_Play` (279 files) |
| `g_stringFormat` | `data_020ef078` | Main | `0x020ef078` | same name | The string `"%s"` |
| `CharacterCreationUI_firstKeyText` | `data_ov009_0218ad26` | 9 | `0x0218ad26` | (usa/eur only) | `"1"`: the label of the key name entry starts on |
| `CharacterCreationUI_widestCharacter` | `data_ov009_0218ad2a` | 9 | `0x0218ad2a` | (usa/eur only) | `"W"`: its width × 8 + 7 gaps is the name's pixel limit (47) |
| `CharacterCreationUI_nameFill` | `data_ov009_0218bc59` | 9 | (jpn only) | `0x0218bc59` | The 2-byte character jpn copies into a name's empty slots |
| `__ptmf_null` | `data_020e6d5c` | Main | `0x020e6d5c` (EUR `0x020e6d6c`) | `0x020e7604` | The CodeWarrior runtime's null member-function pointer. The compiler copies it into the last entry of a local member-function-pointer array that ends in `0`, which is the slot every handler-table copy fills from it |

### Fields

| Name | Original | In | What it is |
|---|---|---|---|
| `GameState::characterCreated_` | raw `+0x63d4` (jpn `+0x6174`) | `include/GameState/GameState.h` | Set when character creation finishes (tab 9), cleared on backing out of it (gender tab, mode 0) and at game state setup; the scene loop goes on to the main game (overlay 17) only when it's set. Still read through raw offsets in `02000c9c.cpp` (`MOVIE_RETURN_FLAG_OFFSET`), `func_0200f3a4` and `func_ov009_0218742c` |
| `Keyboard::widthLimit_`, `textSize_`, `maxLength_` | `unk_c`, `size_`, `unk_14` | `CharacterCreationUI_HandleNameEntry` | The text's pixel limit, its buffer size and character limit (47, 0x48, 8 on name entry); `Keyboard_TypeCharacter` checks the first and last |
| `Keyboard::repeatTimer_`, `repeatDir_` | `unk_18`, `unk_1c` | same | D-pad auto-repeat timer and direction (names from `Keyboard_Update`) |
| `Keyboard::page_`, `font_`, `shift_` | `unk_1e`, `unk_1f`, `unk_20` | same | The page shown (seen changing 1, 2, 4, 8 with the page keys), the font, and the one-shot shift (seen 1 after ⇧) |
| `Keyboard::wrap_` | `unk_21` | same | The cursor wraps between the top and bottom rows; read by `func_ov003_0215e9ec` on every D-pad move (seen in-game), 0 on name entry |
| `Keyboard::allowAlt_`, `allowCancel_`, `autoRepeat_` | `unk_22`, `unk_23`, `unk_24` | same | L also presses a key; B deletes; holding a direction repeats (in `Keyboard_Update`) |
| `Keyboard::autoRepeat` | `wrap` | `Keyboard_Update` | It gates holding a direction to repeat, not wrapping |
| `KeyboardKey::pages_`, `action_`, `sizeClass_`, `disabled_`, `id_` | `flags_`, `unk_d`, `size_`, `unk_f`, `unk_10` | `CharacterCreationUI_HandleNameEntry` | From the live key list: the page mask, the `KeyboardAction`, the size class, set on the space bar (typing it gives `KeyboardResult_KeyDisabled`), and the grid id |
| `Keyboard_TypeCharacter`'s `page`, `shift`, `disabled`, `text`, `shiftedText` | `state`, `shiftMode`, `isCommand`, `code`, `shiftedCode` | `Keyboard_TypeCharacter` | The same fields, named the same way |
| `CharacterCreation::navigation_`, `lastCursorX_`, `lastCursorY_`, `characterData_`, `furthestState_` | `cursor_`, `lastX_`, `lastY_`, `member_`, `lastStates_` | `CharacterCreationUI_HandleNameEntry` | The header's names for the same offsets |
| `CharacterCreation::nameFill_` | `unk_db4` | same | The character `CharacterCreationUI_RefreshNameText` pads the shown name with |
| `FontCharacter::width_`, `GridCursor::count_` | `unk_4`, `unk_0` | same | The glyph width (×8 + 7 is the name limit); the cell count `GridCursor_SetCount` writes |

### Locals

| Name | Original | In |
|---|---|---|
| `currentLayout` | `out` | `CharacterCreationUI_LoadSlotLayout` |
| `nameChecked` | `checked` | `CharacterCreationUI_HandleNameEntry` |
| `widest` | `info` | `CharacterCreationUI_HandleNameEntry` |
| `okKey` | `key` | `CharacterCreationUI_HandleNameEntry` |
| `navigation` | `cursor` | `CharacterCreationUI_HandleNameEntry` |
| `tab`, `reached` | `state` | `CharacterCreationUI_HandleGenderSelection`, step 3's tab icon block |
| `characterCreationStep` | `state` | `CharacterCreationUI_ApplyChoice` (usa half) |

## Placeholders

### Role known

| Current name | Overlay | USA | What it does | Suggested |
|---|---|---|---|---|
| `func_ov009_0218454c` | 9 | `0x0218454c` | Character creation constructor: clears its fields | `CharacterCreationUI_Init` |
| `func_ov009_02184a18` | 9 | `0x02184a18` | Per-frame update: model updates, then calls the current tab's handler | `CharacterCreationUI_Update` |
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
| `GridCursor::unk_4` | `CharacterCreationUI_HandleNameEntry` | `InitStruct_0205ba2c` sets it to 1 and name entry sets it to 1 again; no reader found yet | (none yet) |
| `Object3D::unknown_2_` | `include/World/Object3D.h` | ID of the model loaded in this part; -1 means none | `loadedModelId_` |
| `CharacterCreationUI::grid` | `include/Resource/CharacterCreationUI.h` | The current tab's `CreationSlotLayout` | `slotLayout` |
| `CharacterCreationUI::character` / `nextCharacter` | `include/Resource/CharacterCreationUI.h` | The visible and hidden preview models; typed `void*` until a shared `CharacterModel` type exists | |

### Role unknown

| Current name | Overlay | USA | Notes |
|---|---|---|---|
| `func_ov009_02185c58` | 9 | (jpn only, `0x02185c58`) | jpn name entry waits for it to return non-zero before reading input; jpn-only asm, not seen running |
| `func_ov009_0218ad0c` | 9 | (jpn only, `0x0218ad0c`) | jpn name entry calls it on Confirm, where usa calls `CharacterCreationUI_CheckName`, but it is a different 0x444-byte function; jpn-only asm |
