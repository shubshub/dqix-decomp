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
| `CharacterCreationUI_HandleFace` | `func_ov009_021866f0` | 9 | `0x021866f0` | `0x0218781c` | Face tab handler (tab 5). Confirm goes to SkinColor, Back to HairColor |
| `CharacterCreationUI_HandleSkinColor` | `func_ov009_02186aec` | 9 | `0x02186aec` | `0x02187c18` | Skin colour tab handler (tab 6). Confirm goes to EyeColor, Back to Face. Seen in-game: it runs every frame while the bottom screen shows "6 Skin Colour", and picking a colour there changes the skin. (Named `HandleEyeColor` until the tab order was checked in-game) |
| `CharacterCreationUI_HandleEyeColor` | `func_ov009_02186c00` | 9 | `0x02186c00` | `0x02187d2c` | Eye colour tab handler (tab 7). Confirm goes to NameEntry, Back to SkinColor. Seen in-game: it runs while the screen shows "7 Eye Colour", and picking Type 5 turned the eyes green. (Named `HandleSkinColor` until the tab order was checked in-game) |
| `CharacterCreationUI_HandleNameEntry` | `func_ov009_02186e00` | 9 | `0x02186e00` | `0x02187f2c` | Name entry tab handler (tab 8). Confirm goes to tab 9, Back to EyeColor; jpn has its own body |
| `CharacterCreationUI_Allocate` | `func_ov009_021842a0` | 9 | `0x021842a0` | `0x021853a0` | Allocates the scene's buffers (keyboard, names, sprites, model allocators) from the caller's allocator. The new-game scene (`func_ov021_0218b5fc`) calls it right after the constructor. Seen in-game: runs once on entering character creation |
| `CharacterCreationUI_Init` | `func_ov009_0218454c` | 9 | `0x0218454c` | `0x021855a8` | The constructor: run on the freshly allocated scene (`func_ov021_0218b5fc`), sets `mode` and `vocation` from its arguments and every other field to empty or -1. Seen in-game: once on entry |
| `NameFilter_Reset` | `func_ov009_021847ec` | 9 | `0x021847ec` | `0x02185850` | Clears the name filter's word files and looks up its 15 pattern characters in font 1. Called by the constructor and at the start of every `CharacterCreationUI_CheckName`. The jpn body is different |
| `CharacterCreationUI_Destroy` | `ResetAndReinitCombatState_02184848` (symbol `func_ov009_02184848`) | 9 | `0x02184848` | `0x021858e4` | Undoes `_Init` and `_Allocate`: models, layers, windows, allocators. The new-game scene calls it after its loop. Seen in-game: once on backing out of the gender tab, after `_HandleClose` |
| `CharacterCreationUI_Update` | `func_ov009_02184a18` | 9 | `0x02184a18` | `0x02185aac` | The per-frame update: camera, windows, models, then the current tab's handler from `CharacterCreationUI_tabHandlers`. Returns 1 at `CreationTab_Done`, which ends the scene loop. Seen in-game: every frame |
| `CharacterCreationUI_Draw2D` | `func_ov009_02184bbc` | 9 | `0x02184bbc` | `0x02185ee8` | Builds the frame's 2D: tab highlight and panel tile maps, sprites, window text. The scene's draw (`Trans_0218bb30`) calls it after the 3D draw. Seen in-game: every frame |
| `CharacterCreationUI_Draw3D` | `SyncCombatantAndFlushMatrix_02184c30` (symbol `func_ov009_02184c30`) | 9 | `0x02184c30` | `0x02185f5c` | Draws `character` (and the two new-game finish models while flag `0x200`). Called from the scene's draw. Seen in-game: every frame |
| `CharacterCreationUI_UpdateVBlank` | `func_ov009_02184ca4` | 9 | `0x02184ca4` | `0x02185fd0` | Runs right after the scene waits for VBlank (`func_ov021_0218b5fc`): finishes a tab load, copies the layers to VRAM and refreshes the window text. Seen in-game: every frame |
| `CharacterCreationUI_LoadTabGraphics` | `UpdateCombatantState_02184d70` | 9 | `0x02184d70` | `0x02186098` | While `CreationFlag_TabLoading`: queues the tab's background archive (text key = tab, plus sex × 100 for body type, hairstyle and face), waits for it and marks it loaded (`resourceStep` 0, 1, 2). Seen in-game: every frame |
| `CharacterCreationUI_ApplyTabGraphics` | `func_ov009_02184e58` | 9 | `0x02184e58` | `0x02186158` | Once the tab's archive has loaded (`resourceStep` 2): builds the tab's layers, clears `CreationFlag_TabLoading` and sets `resourceStep` back to 0. Called by `_UpdateVBlank`; logged clearing `0x80` after a tab change |
| `CharacterCreationUI_SwapCharacters` | `SyncEntryPairAndRefreshFlags_02188454` (symbol `func_ov009_02188454`) | 9 | `0x02188454` | `0x02189214` | On `CreationFlag_SwapCharacters`, once `nextCharacter` has loaded: copies the rotation and animation across, swaps `character` and `nextCharacter`, clears the flag. Logged in-game on a gender change |
| `CharacterCreationUI_LoadNextCharacter` | `UpdateFlag021885b8` | 9 | `0x021885b8` | `0x02189378` | On `CreationFlag_LoadNextCharacter`: rebuilds `nextCharacter` from `characterData` and swaps the flag for `CreationFlag_SwapCharacters`. Logged in-game: flags `0x60013` → `0x60015` |
| `CharacterCreationUI_UpdateRotation` | `func_ov009_02188604` | 9 | `0x02188604` | `0x021893c4` | Turns `character`: towards `targetAngle` while flag `0x8`, otherwise (with `CreationFlag_StylusRotation`) by L, R or the bottom-left touch arrows; L and R together reset it. Seen in-game: every frame |
| `CharacterCreationUI_GetTouchedInput` | `GridTouchSelection.cpp`'s `func_ov009_02189854` | 9 | `0x02189854` | `0x0218a8b4` | Maps a touch to a `CreationInput`: the Confirm and Back buttons, a tab icon, or a slot (-4 when nothing). Seen in-game: touching (166, 173) and (150, 173) went forward a tab, (220, 173) and (214, 173) back |
| `ForbiddenWordFile_RelocatePattern` | `func_ov009_0218a420` | 9 | `0x0218a420` | not identified | Turns a pattern's word offsets into pointers into the file's texts (NULL for -1); `CharacterCreationUI_CheckName` calls it for each pattern |
| `NameFilter_CopyUppercase` | `ToUpperCopy0218a484` | 9 | `0x0218a484` | not identified | Copies a string, uppercasing a–z; writes no terminator (the callers clear the buffer first) |
| `NameFilter_FindWord` | `FindMatch0218a4c8` | 9 | `0x0218a4c8` | not identified | 1 if `memcmp` finds the word at any of the first `count` positions of the text |
| `NameFilter_MatchPattern` | `func_ov009_0218a518` | 9 | `0x0218a518` | not identified | Pattern matcher over font-index tokens: the letter class `:`, groups `[...]` with `^` and `-`, repeats `{a,b}` and `.{0,60}` |
| `NameFilter_GroupContains` | `FindByteInBuffer0218a888` | 9 | `0x0218a888` | not identified | 1 if a token is one of a `[...]` group's members; only `NameFilter_MatchPattern` calls it |
| `CharacterCreationUI_UpdateWaitTimer` | `DecrementCounterD96ClampZero_0218a930.cpp`'s `func_ov009_0218a930` | 9 | `0x0218a930` | `0x0218b908` | Subtracts the ticks from `waitTimer` (`+0xd96`) and returns 1 while time is left; `CharacterCreationUI_HandleNewGameFinish` returns while it does |
| `CharacterCreationUI_PressNameKey` | `ApplyNameKeyboardChoice_0218aab0.cpp`'s `func_ov009_0218aab0` | 9 | (jpn only) | `0x0218aab0` | jpn's name keyboard: types the 2-byte character of the key at the cell (text `0x4268 + keyboardPage`), or does the key's action (OK sets `CreationFlag_KeyboardOk`, delete, the page keys, random name in mode 1); returns 1 when a character was typed. Read from the jpn code; there is no jpn ROM here |
| `Camera_EasePositionTo` | `CallFunc020a0db8AtField0x16c_0202ee38` | Main | `0x0202ee38` (EUR `0x0202ee48`) | `0x0202e9a8` | Starts a move of the camera's position (`+4`) towards a vector: each update `AdvanceVec3TowardTarget020a1034` moves it (target − position) / steps and stops within `0x199`. Seen in-game: entering the face tab, the camera's `+4` reached the face tab's position table exactly |
| `Camera_EaseTargetTo` | `CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58` | Main | `0x0202ee58` (EUR `0x0202ee68`) | `0x0202e9c8` | The same for the camera's target (`+0x10`); also clears bit 2 of `+0x168`. Seen in-game with the face tab's target table |
| `CharacterModel_SetAngle` | `InitWordsQuad_021e60e0` | 23 | `0x021e60e0` | `0x021e62c4` | Sets rotation (0, angle, 0) on parts 0, 6, 1 and 5 (`+0`, `+0x408`, `+0xac`, `+0x35c`). Logged in-game: after a sex change `CharacterCreationUI_SwapCharacters` used it and part 0's rotation read `0x1eb` |
| `CharacterModel_GetRotation` | `CopyBlockAt80_021e613c.cpp`'s `func_ov023_021e613c` | 23 | `0x021e613c` | `0x021e6320` | Returns part 0's `rotation_` (`+0x50`); read live as the preview's angle |
| `CharacterModel_SetRotation` | `SetFourWordBlocks_021e6088` | 23 | `0x021e6088` | `0x021e626c` | Sets a whole rotation on the same four parts; `CharacterCreationUI_UpdateRotation` turns the model with it (seen in-game: the touch arrows changed part 0's angle) |
| `CharacterModel_GetBody` | `BlankFunction_021e6194.cpp`'s `func_ov023_021e6194` | 23 | `0x021e6194` | `0x021e6378` | A single `bx lr`: returns the model, i.e. its first part, the body (`Object3D`) whose animation the swap copies |
| `CharacterModel_Load` | `func_ov023_021e5974` | 23 | `0x021e5974` | `0x021e5b58` | Loads a character model's part files from `data/pack_lv5/chara_pd.gp2` (`d_<letter><number>.nsbmd`, the hair texture as `.nsbtx`) and its body's animations. Logged in-game: after a sex change it queued `d_b008.nsbmd`, `d_p215`, `d_f011`, `d_h180a.nsbmd`, `d_h183a.nsbtx`, `d_a008`, `d_r120`, `md0200w.nsbca`/`.bcfg` |
| `CharacterModel_Update` | `func_ov023_021e5020` | 23 | `0x021e5020` | `0x021e5204` | Per-frame model update: polls the part loads and applies the colours once loaded; `CharacterCreationUI_Update` calls it for both preview models every frame |
| `CharacterModel_Draw` | `SyncTagFieldsAndNotify_021e5628.cpp`'s `func_ov023_021e5628` | 23 | `0x021e5628` | `0x021e580c` | Draws a character model (unless loading or hidden): advances the body's animation, syncs the other parts to it and draws them. Seen in-game: turned off (`dq off`), the preview character vanished from the top screen |
| `CharacterModel_Init` | `InitTenAllocatorsAndClearFields_021e4e8c` | 23 | `0x021e4e8c` | `0x021e5080` | Initializes a character model: its 10 part `Object3D`s and their allocators, the animation allocator, tasks to -1, flags clear |
| `CharacterModel_CreateAllocators` | `CreateTenAndOne_021e4f64` | 23 | `0x021e4f64` | `0x021e5148` | Gives each of the 10 parts an allocator sized from `data_ov023_021fd6d4`, plus a 0x1000 animation allocator (`+0x780`) |
| `CharacterModel_ReserveVram` | `InitBlockArray_021e4fd8` | 23 | `0x021e4fd8` | `0x021e51bc` | Reserves texture and palette VRAM for each part (`func_0207de48` on `vramStates_[10]` at `+0x794`) |
| `CharacterModel_Destroy` | `DestroyTenAndOne_021e4f18` | 23 | `0x021e4f18` | `0x021e50fc` | Undoes the above: resets the 10 parts and destroys their allocators and the animation allocator; `CharacterCreationUI_Destroy` calls it for both preview models |
| `CharacterModel_SetItemTable` | `SetIntC0C_021e6198` | 23 | `0x021e6198` | `0x021e637c` | Stores the item table (`+0xc0c`) `CharacterModel_Load` looks each appearance id up in for its file letter; `HandleSetup` gives both preview models `itemTable` |
| `KeyTable_Get` | `GetFieldByKey020e0434` | Main | `0x020e0434` (EUR `0x020e0444`) | `0x020e2070` | Returns the value stored for a key (a binary search of `{key, value}` entries, `LookupFieldByKey020e0440`). Character creation's text table is one: read live, key `0x465a` holds "Yes" and 20000 "Irving". Used in 208 files, so named for what it does, not for text |
| `GridCursor_GetCount` | `GetField0_0205bafc` | Main | `0x0205bafc` (EUR `0x0205bb0c`) | `0x0205ce5c`  Returns the cursor's cell count (`+0x0`) |
| `GridCursor_Update` | `func_0205bf58` | Main | `0x0205bf58` (EUR `0x0205bf68`) | `0x0205d2b8`  The grid cursor's per-frame D-pad handling: a new press of Up/Down/Left/Right moves a row or column (wrapping by `wrapRows`/`wrapColumns`, paging while `pageCount > 1`), a held key repeats after `initialDelay` then every `repeatDelay`; returns 1 while a direction moved. Seen in-game: Down on the gender tab moved the cursor to Female |
| `Background_FillRect` | `func_0204bc74` | Main | `0x0204bc74` (EUR `0x0204bc84`) | `0x0204ca94`  Fills a rectangle of the map with one tile and palette (the 32 × 25 clears in `HandleConfirm`) |
| `Font_EncodeText` | `func_020426bc` | Main | `0x020426bc` (EUR `0x020426cc`) | not identified  Writes one byte per character of a text: its index in the font (0xff for a space, 0 if not found), then 0. `CharacterCreationUI_CheckName` encodes the name with it |
| `Font_GetCharacter` | `GetBoundedEntry020425b4` | Main | `0x020425b4` (EUR `0x020425c4`) | not identified  Returns entry N of the table `Font_FindCharacter` searches, or NULL out of range |
| `KeyTable_Load` | `func_020dfec0` | Main | `0x020dfec0` (EUR `0x020dfed0`) | `0x020e1a94`  Copies a key table from file data into memory from an allocator: the header, then the `{key, offset}` entries and the texts. `HandleSetup` loads character creation's text table (`str_cm_<LG>.nat`) with it, read live (`0x465a` = "Yes") |
| `KeyTable_GetCount` | `GetLow12Bits020e0424` | Main | `0x020e0424` (EUR `0x020e0434`) | not identified  Returns the entry count (header bits 0–11; 24 for res.nat) |
| `Keyboard_FindKeyByText` | `func_ov003_0215f4fc` | 3 | `0x0215f4fc` | not identified  The first key of the layout whose label starts with the text; `HandleConfirm` and `HandleSetup` find the "1" and space keys with it |
| `CharacterCreationUI_OpenYesNoWindow` | `func_ov023_021d9f88` | 23 | `0x021d9f88` | `0x021da7ac`  Sets `windows[1]` up as the 1 × 2 Yes/No menu, selection on Yes. Seen in-game: the confirm tab's Yes/No |
| `CharacterCreationUI_WriteYesNoText` | `func_ov023_021da100` | 23 | `0x021da100` | `0x021da8cc`  Writes texts `0x465a + i` (read live: "Yes", "No") into the Yes/No panes, highlighting the selection |
| `CharacterCreationUI_UpdateDim` | `func_ov023_021dac40` | 23 | `0x021dac40` | `0x021db4b4`  While `CreationFlag_DimBackground`, counts `dimTimer` down over 90 ticks: darkens the main screen's BG1, BG2 and sprites, or with `CreationFlag_DimWithQuad` fades in a black 3D quad. Seen in-game: the finish's darkened background |
| `Window_GetSelectedIndex` | `GetActiveScaledSum0205d794` | Main | `0x0205d794` (EUR `0x0205d7a4`) | `0x0205eaa8`  The selected item of a window's active pane (Yes 0, No 1 on the confirm tab) |
| `Window_IsSelectionTouched` | `IsActiveElementFlag2Set0205da38` | Main | `0x0205da38` (EUR `0x0205da48`) | `0x0205ed4c`  Whether the stylus is pressed on the active pane's selected item; its second argument is ignored |
| `Camera_IsEasing` | `AnySubObjectField0NonZero_0202eeb4` | Main | `0x0202eeb4` (EUR `0x0202eec4`) | `0x0202ea24`  Whether any of the camera's three ease records is running; `HandleNewGameFinish` waits on it |
| `PartyMember_LearnSpell` | `SetBitInArray0x910_02083b60` | Main | `0x02083b60` (EUR `0x02083b70`) | `0x0208446c`  Sets the spell's bit in the member's learned-spell bitset (`+0x910`); `HandleConfirm` teaches the vocation's level-1 spells from the spell table |
| `PartyMember_SetVocation` | `SetBit0x954StoreIndex0x950_02083ca0` | Main | `0x02083ca0` (EUR `0x02083cb0`) | `0x020845b8`  Stores the vocation (`+0x950`) and sets its bit in `+0x954` |
| `PartyMember_ApplyLevelStats` | `func_02083cbc` | Main | `0x02083cbc` (EUR `0x02083ccc`) | `0x020845d4`  Copies a level record's stats into the member (`+0x91c` on) |
| `SpellTable_Load` | `SetupAndRunBufferedScript0209a810` | Main | `0x0209a810` (EUR `0x0209a820`) | `0x0209c588`  Runs `data/prm/spelltable.bin` into a spell table (`spells[13][20]` of `{spell, level}`) |
| `Background_Init` | `ResetList0204af64` | Main | `0x0204af64` (EUR `0x0204af74`) | `0x0204bd84`  Resets every field of a background layer (`CharacterCreationUI_Init` on all six layers) |
| `Background_SetMapSize` | `SetWord0x18ClearByte0x1f_0204b11c` | Main | `0x0204b11c` (EUR `0x0204b12c`) | `0x0204bf3c`  Sets a layer's map size index (`+0x18`) and clears its map type (`+0x1f`) |
| `Background_SetPriority` | `func_0204b5b4` | Main | `0x0204b5b4` (EUR `0x0204b5c4`) | `0x0204c3d4`  Sets the layer's BG priority through `data_020f01d8[engine][bg]` (the SetBgNPriority functions), masked to 0–3 |
| `Background_SetScroll` | `DispatchViaTable0204b5e8` | Main | `0x0204b5e8` (EUR `0x0204b5f8`) | `0x0204c408`  Sets the layer's scroll through `data_020f01b8` (SetMainBG0Scroll and the sub-engine offset functions) |
| `Background_AllocateMap` | `AllocateAndClearBuffer0204b12c` | Main | `0x0204b12c` (EUR `0x0204b13c`) | `0x0204bf4c`  Allocates and clears the map buffer (`+0x14`) |
| `Background_AllocateScreens` | `AllocateArray0204af38` | Main | `0x0204af38` (EUR `0x0204af48`) | `0x0204bd58`  Allocates room for `count` 0x10-byte screens (`+0x10`, capacity `+0x1e`) |
| `Background_LoadFile` | `func_0204b174` | Main | `0x0204b174` (EUR `0x0204b184`) | `0x0204bf94`  Takes one file of a `.pac`: CHAR goes to VRAM, PALT to the palette, SCRN is kept as the next screen |
| `Background_FlushFile` | `DispatchByTag0204b2e0` | Main | `0x0204b2e0` (EUR `0x0204b2f0`) | `0x0204c100`  Flushes a file's data from the cache |
| `Background_UploadFile` | `DispatchByTagLookup0204b3a0` | Main | `0x0204b3a0` (EUR `0x0204b3b0`) | `0x0204c1c0`  Sends a file to VRAM through the engine/BG table |
| `Background_GetScreen` | `GetEntryByIndexStride0x10` | Main | `0x0204af14` (EUR `0x0204af24`) | `0x0204bd34`  Returns screen N, bounded by how many are loaded |
| `Background_DrawScreen` | `DispatchEntry0204b8d0` | Main | `0x0204b8d0` (EUR `0x0204b8e0`) | `0x0204c6f0`  Draws a rectangle of screen N into the map, optionally with another palette (`0xffff` keeps it) |
| `Background_CopyScreenRect` | `func_0204b620` | Main | `0x0204b620` (EUR `0x0204b630`) | `0x0204c440`  Copies a rectangle of a screen's tiles into a map |
| `Background_UploadMap` | `FlushAndDispatchList0204b0e8` | Main | `0x0204b0e8` (EUR `0x0204b0f8`) | `0x0204bf08`  `Background_FlushMap` then `Background_TransferMap` |
| `Pac_CountFiles` | `CountActiveEntries` | Main | `0x02046900` (EUR `0x02046910`) | `0x02047720`  Counts the records of a `.pac` archive |
| `Pac_GetFile` | `FindRecordByIndex` | Main | `0x020467f0` (EUR `0x02046800`) | `0x02047610`  Returns record N's data of a `.pac`; the record header gives the header size, data size and stride |
| `KeyTable_Reset` | `ResetStruct020dfc40` | Main | `0x020dfc40` (EUR `0x020dfc50`) | `0x020e1814`  Clears a key table, sets its index (`+0xc`) and task to -1 and removes a pending load task |
| `KeyTable_LoadInPlace` | `ApplyNodeUpdater020e038c` | Main | `0x020e038c` (EUR `0x020e039c`) | `0x020e1f60`  Sets up a key table in the file data itself, relocating it once (bit 31 marks it done); `CharacterCreationUI_CheckName` uses it on res.nat |
| `KeyboardLayout_Load` | `func_ov003_0215e6f8` | 3 | `0x0215e6f8` | not identified  Builds the key list by running `keyboard_cm.bin` / `keyboard_cs.bin` as a script |
| `CharacterCreationUI_CreateSummaryPane` | `func_ov023_021d99a4` | 23 | `0x021d99a4` | `0x021da1b4`  Lays out `windows[0]`'s pane, the summary list `CharacterCreationUI_RefreshSummary` writes |
| `CharacterCreationUI_CreateNamePane` | `SetupTag021d9da4` | 23 | `0x021d9da4` | `0x021da63c`  Lays out `windows[1]`'s pane 3, the name line `CharacterCreationUI_RefreshNameText` writes |
| `Window_SetPanes` | `LinkArrayPrevPointers0205cf78` | Main | `0x0205cf78` (EUR `0x0205cf88`) | `0x0205e2a8`  Gives a window its panes (`+0x9c`) and their count (`+0xb3`), linking each |
| `WindowPane_AllocateBuffer` | `AllocateBuffer0204c7a8` | Main | `0x0204c7a8` (EUR `0x0204c7b8`) | `0x0204d5c4`  Allocates a pane's text buffer |
| `SpriteContext_Init` | `InitStruct0205a444` | Main | `0x0205a444` (EUR `0x0205a454`) | `0x0205b7e0`  Zeroes a sprite context and sets it to the sub screen (`+0x50` = 1) |
| `Sprite_Init` | `Init0205a198` | Main | `0x0205a198` (EUR `0x0205a1a8`) | `0x0205b510`  Initializes a 0x28-byte sprite (scale 1.0) |
| `SpriteContext_LoadFile` | `func_0205a528` | Main | `0x0205a528` (EUR `0x0205a538`) | `0x0205b8c4`  Takes one file of a cell archive: NCER, NANR, NCGR or NCLR (the `cell_cm` files) |
| `Camera_SetPosition` | `SetVec3At0x4` | Main | `0x0202e5c0` (EUR `0x0202e5d0`) | `0x0202e130`  Sets the camera's position (`+4`). Seen in-game: the camera's `+4` is the position the face tab eases |
| `Camera_SetTarget` | `SetFields0x10To0x18_0202e5c8` | Main | `0x0202e5c8` (EUR `0x0202e5d8`) | `0x0202e138`  Sets the camera's target (`+0x10`) |
| `ItemTable_Init` | `ZeroInit020de848` | Main | `0x020de848` (EUR `0x020de858`) | `0x020e01c4`  Clears an item table (0x14 bytes and a flag) |
| `ItemTable_LoadIds` | `func_020de9a4` | Main | `0x020de9a4` (EUR `0x020de9b4`) | `0x020e0320`  Loads just the given item ids from the item data (binary search, skipping negative and repeated ids); `HandleSetup` loads `CharacterCreationUI_itemIds` |
| `VramState_Reserve` | `func_0207de48` | Main | `0x0207de48` (EUR `0x0207de58`) | `0x0207ebc8`  Saves the texture and palette VRAM managers' state, then reserves the given texture and palette sizes |
| `VramState_Restore` | `RestorePairTables0207df90` | Main | `0x0207df90` (EUR `0x0207dfa0`) | `0x0207ed10`  Puts a saved VRAM manager state back before loading into it |
| `VramState_Save` | `BackupPairTables0207dfac` | Main | `0x0207dfac` (EUR `0x0207dfbc`) | `0x0207ed2c`  Saves the VRAM manager state after a load |
| `Font_FindCharacterIndex` | `FindEntryIndexByKey020424e4` | Main | `0x020424e4` (EUR `0x020424f4`) | not identified | `Font_FindCharacter`'s loop returning the entry's index (or -1) instead of the entry; `NameFilter_Reset` looks up the pattern characters in font 1 with it |
| `Background_ClearMap` | `ClearBuffer0204b010` | Main | `0x0204b010` (EUR `0x0204b020`) | `0x0204be30` | Clears a background layer's map buffer (`+0x14`, size from its map type and size index) |
| `Background_FlushMap` | `func_0204b04c` | Main | `0x0204b04c` (EUR `0x0204b05c`) | `0x0204be6c` | Cleans the map buffer out of the data cache before a transfer |
| `Background_TransferMap` | `func_0204b088` | Main | `0x0204b088` (EUR `0x0204b098`) | `0x0204bea8` | Hands the map buffer to the layer's VRAM transfer function (`data_020f0218[engine][bg]`) |
| `Window_ClearLayers` | `ClearBuffers0204b010OverList0x98` | Main | `0x0205d1e0` (EUR `0x0205d1f0`) | `0x0205e510` | `Background_ClearMap` on each of a window's layers (`+0x98`, `+0xb2` of them) |
| `Window_FlushLayers` | `CallFunc0204b04cOverList0x98` | Main | `0x0205d274` (EUR `0x0205d284`) | `0x0205e5a4` | `Background_FlushMap` on each layer |
| `Window_TransferLayers` | `InitEntries0205d2bc` | Main | `0x0205d2bc` (EUR `0x0205d2cc`) | `0x0205e5ec` | `Background_TransferMap` on each layer |
| `Window_Update` | `func_0205d0e0` | Main | `0x0205d0e0` (EUR `0x0205d0f0`) | `0x0205e410` | A window's per-frame update: runs the active pane's input (`func_0205c5b0`), updates each pane and closes a pending one; returns what the input did. Logged in-game: on the Yes/No prompt its result (stored in `windowInput`) was 1 after Down and after Up |
| `Keyboard_Init` | `InitStruct0215efb8` | 3 | `0x0215efb8` | not identified | Sets a `Keyboard` to empty, field for field at `HandleNameEntry`'s offsets: page 1 (lowercase), font 0, no shift, wrap on, alt off, cancel allowed, auto-repeat on. `CharacterCreationUI_Allocate` calls it |
| `KeyboardLayout_Init` | `ResetStruct_0215e6d8` | 3 | `0x0215e6d8` | not identified | Zeroes a key list header (keys at `+0`, count at `+6`, as `Keyboard_FindKeyByAction` reads it) |
| `Window_DrawPanes` | `CallFunc0204c8f0OverList0x9c` | Main | `0x0205d228` (EUR `0x0205d238`) | `0x0205e558` | Draws each of a window's panes (`+0x9c`, `+0xb3` of them) into its layers (`SomeFunc0204c8f0`) |
| `CharacterCreationUI_DrawTabLayers` | `func_ov023_021da274` | 23 | `0x021da274` | `0x021daa30` | On `CreationFlag_RedrawTabHighlight` draws the current tab's highlight line into `layers[1]`; on `_RedrawPanel` redraws the bottom panel (and the keyboard page or Yes/No on tabs 8–9). Called from `_Draw2D` |
| `CharacterCreationUI_PlaceSprites` | `ConfigureEntryPositions_021da770.cpp`'s `func_ov023_021da770` | 23 | `0x021da770` | `0x021daf74` | Places the Confirm and Back buttons (unless `CreationFlag_HideButtons`), the tab icons up to `furthestState` and the slot highlight at `lastCursorX`/`Y`. Seen in-game: the buttons are gone while the Yes/No prompt shows |
| `CharacterCreationUI_PlaceCursorSprites` | `func_ov023_021da9b4` | 23 | `0x021da9b4` | `0x021db240` | The pointer at the current tab's line of the summary (seen on every screenshot) and the cursor on the Yes/No menu |
| `CharacterCreationUI_RefreshSummary` | `BuildElemPaletteTags_021d9a6c.cpp`'s `func_ov023_021d9a6c` | 23 | `0x021d9a6c` | `0x021da264` | On `CreationFlag_RefreshSummary`, rebuilds the summary list's choices. Seen in-game: with it turned off (`dq off`), choosing Female left the summary saying "Male"; turned back on, it said "Female" |
| `CharacterCreationUI_RefreshYesNoMenu` | `func_ov023_021da1dc` | 23 | `0x021da1dc` | `0x021da9a8` | Rebuilds the Yes/No menu (texts `0x465a`/`0x465b`, read live as "Yes" and "No") with the cursor at `selection`, from `windowInput` |
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
| `CharacterCreationUI_PickRandomName` | `ResetEntrySkill0218a8b8` | 9 | `0x0218a8b8` | `0x0218b850` (its own body, `CharacterCreationUI_PickRandomName_0218b850.cpp`) | Clears the name and writes a random one: text `0x4e20 + sex × 1000 + rand() % count[sex]`. Select does it in-game (got "Rubin") |
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
| `CreationTabHandler`, `CreationTabHandlers` | `StateFunc`, `StateTable` | `CharacterCreationUI_tabHandlers_0218ab9c.c` | One tab's handler as MWCC lays out a pointer to member function (`{func, adjust}`), and the table of 13 |
| `AppearanceModels` | `LookDefaults` (ZevyaDev/dqix-decomp#319) | `CharacterCreationUI_defaultAppearance_0218aa40.c` | `PartyMemberAppearance::models_` on its own |
| `BodyDimensions` | (same, #319) | `CharacterCreationUI_bodyDimensions_0218aa70.c` | `{width, height}` of one body type |
| `AppearanceEquipment` | `EquipmentMapping` (#319) | `CharacterCreationUI_equipmentFromAppearance_0218aac8.c` | `{appearanceSlot, equipmentSlot}` plus 5 bytes of padding |
| `GridCursor` | `WindowCursor` | `CharacterCreationUI_HandleNameEntry_02186e00.cpp` (file-local) | The menu grid cursor (`CreationNavigation` in the header): `count_` is how many cells hold something |
| `PartyMemberData`, `PartyMemberAppearance` | `Hero`, `Look` | `CharacterCreationUI_HandleSetup` (file-local) | The names `CharacterCreationUI_ApplyChoice` and `CharacterModel_Load` already use for the same struct (`appearance_` at `+0x488`, `vocation_` at `+0x568`) |
| `AppearanceModels` | `LookDefaults` | same | The type `CharacterCreationUI_defaultAppearance_0218aa40.c` defines (`short models[10]`) |
| `WindowPane`, `Window` | `Canvas`, `CanvasList` | same | A window's 0xe0-byte pane and the window (header `CreationWindow`); the owner of the decided `Window_*` functions |
| `SpriteContext`, `Sprite` | `Table0205a444`, `Entry0205a198` | same | The sprite set (header `SpriteContext0205ac40`, `subScreen` at `+0x50`) and one 0x28-byte sprite (header `B174Outer`) |
| `Keyboard`, `KeyboardKey` | `Ov3Obj`, the `unsigned char*` return value | same | The software keyboard and its key, with field names copied from `CharacterCreationUI_HandleNameEntry`'s copies |
| `MessageSystem` | raw `+0x5c` (jpn `+0x28`) | same | What `GetGlobalField0x1c020421a0` returns. `CharacterCreationUI_Destroy` calls it `messageSystem`, and overlay 11 casts it to `MessageSystem*` (`func_ov011_021873c4`, `CallFunc02184c68IfState3_02188534`). Only its text buffer is declared here |
| `CreationStyleOrder` (jpn) | `Ids10` | same | A 10-byte copy of `CharacterCreationUI_styleOrder` |
| method `SetSubScreen`, `SetSprites` (jpn) | `SetKind`, `SetEntries` | same | Inline setters of `subScreen_` and `sprites_`/`spriteCount_`; they are inlined (jpn object has 1 function symbol) |
| `CharacterCreation` (jpn body) | `CharacterCreationJ` | `CharacterCreationUI_ApplyTabGraphics` (file-local, one per region under `#if defined(jpn)`) | The scene at jpn offsets. Both regions now use the same name, as in the header's `CharacterCreationUI` |
| `BackgroundScreen` | `BackgroundPart` | same (file-local) | One screen of a layer, the 16-byte entry an SCRN file becomes. Its layout is the same as `func_0204b620`'s `TileSource0204b620`: width and height at `+0`/`+2`, tiles at `+0xc` |
| `Keyboard` (file-local: `key_`, `repeatTimer_`, `repeatDir_`) | `ChoiceList` (`entries`, `selection`, `counter`) | `CharacterCreationUI_HandleInput` (usa half) | `CharacterCreationUI::keyboard` (`+0xc0`). Same offsets (+0, +0x18, +0x1c) and the same names as `CharacterCreationUI_HandleNameEntry`'s `Keyboard`; `HandleNameEntry`'s Start step also zeroes `repeatTimer_` and `repeatDir_` |
| `CharacterCreation` (file-local) | `Overlay9TouchView` | `CharacterCreationUI_GetTouchedInput` | `CharacterCreationUI`'s usa/eur layout (the name `HandleNameEntry` uses for its own copy). Kept file-local because jpn's copy of this function is still asm and the file must compile the same in jpn |
| (removed) `CharacterCreation`, `CharacterControls`, `Navigation`, `TouchState` | usa half's own scene struct | `CharacterCreationUI_HandleInput` (usa half) | Replaced by the header's `CharacterCreationUI` and `CreationNavigation` (same offsets, same bytes); `TouchState` was never used |
| `CreationSlotLayout` (use) | `Overlay9Grid` | `CharacterCreationUI_GetTouchedInput` | The header type, same fields |
| `NameFilter` (in `CharacterCreationUI_CheckName`) | `NameSyntax` | `CharacterCreationUI_CheckName_02189a4c.cpp` (file-local) | The name filter at `CharacterCreationUI+0xfc`, field for field as `NameFilter_Reset` lays it out (usa) |
| `NameFilter` (in `NameFilter_MatchPattern`) | `PatternSyntax0218a518` | `NameFilter_MatchPattern_0218a518.cpp`: `typedef PatternSyntax0218a518 NameFilter` | The same object. The struct tag stays `PatternSyntax0218a518` because `NameFilter_GroupContains` is a C++ function mangled with it (`_Z24NameFilter_GroupContainsP21PatternSyntax0218a518Phii`); the typedef keeps the symbol (checked: relocation names unchanged) |
| `FontCharacter` (in `CharacterCreationUI_CheckName`) | `CharacterInfo` | same file (file-local) | What `Font_FindCharacter` / `GetBoundedEntry020425b4` return: the decided `FontCharacter` (`text_`, `width_`), with the byte at `+5` split as below |
| `KeyTableEntry` | `DictionaryPair` | same file (file-local) | One `{key_, text_}` entry of a key table (`Container020e0310::entries_`): `LookupFieldByKey020e0440` binary-searches by key and returns `+4`; res.nat's entries are `{key, text offset}` (ROM) |
| `CharacterCreation` | `Menu0218742c` | `CharacterCreationUI_HandleConfirm` (file-local) | The scene, laid out at the header's offsets (the name the other overlay 9 files give their local copy) |
| `PartyMemberData` | `Character0218742c` | same | What `characterData` points to; the same name as in `HandleNewGameFinish`, `ApplyChoice`, `SwapCharacters`, `HandleNameEntry` |
| `PartyMemberAppearance` | `equipmentKeys` (a `short[0x71]`) | same | `+0x488`, as `HandleNewGameFinish` declares it (`models`, `width`, `height`) |
| `ItemRecord` | `Equipment0218742c` | same | 32 bytes: one record of the item table (`FindElementByKey020dedd0` returns `Element020de650`, `v[8]`), copied whole into an equipment slot |
| `AppearanceEquipment` | `EquipmentMapping0218742c` (`keyIndex`, `destination`) | same | The decided type of `CharacterCreationUI_equipmentFromAppearance`, with its C definition's field names |
| `Keyboard` (fields `key_`, `page_`, `shift_`; `SetPage`, `SetShift`) | `ScriptNode0218742c` (`script`, `active`, `waiting`; `SetActive`, `SetWaiting`) | same, usa | `+0xc0` is `keyboard` (header); offsets 0, `0x1e`, `0x20` are the decided `Keyboard::key_`, `page_`, `shift_`. Step 0xff sets the key, `page_ = 1` and `shift_ = 0`, as `Keyboard_ResetToKey` does |
| `SpellTable`, `SpellTableEntry {spell, level}` | `Script0218742c`, `LearnedAbility0218742c {id, level}` | same | What `SetupAndRunBufferedScript0209a810` fills: it runs `data_020f1668` = `"data/prm/spelltable.bin"` (read from arm9.bin) into the 0x550-byte buffer. Each vocation row has 20 `{spell, level}`; Confirm sets bit `spell` of the member's `+0x910` for every entry with `level != 0` and `level <=` the member's level |
| `ResourceScriptEntry` (existing, `include/Combat/ResourceScriptEntry.h`) | `LoadedRecord0218742c {field_0[0x3c], tail[0x18]}` | same | The type `func_02082490` fills (its own source); `tail` is its `variants` at `+0x3c` |
| `FinishModelFile {allocator_, name_, taskSlot_}`, `FinishModelFiles` | `ModelFile {allocator_, name_, model_}`, `ModelFiles` | `CharacterCreationUI_HandleNewGameFinish` (file-local) | The type names and fields of `CharacterCreationUI_finishModelFiles`' C definition |

### Constants

| Name | Original | Where | What it is |
|---|---|---|---|
| `CreationTab` | (none) | `include/Resource/CreationEnums.h` | Enum of `CharacterCreationUI::state`, the current tab |
| `CreationTab_Confirm`, `_NewGameFinish`, `_Close` | 9, 10, 11 | `include/Resource/CreationEnums.h` | The tabs `CharacterCreationUI_HandleConfirm`, `_HandleNewGameFinish` and `_HandleClose` run |
| `CreationFlag_RefreshSummary` | `0x100` | `include/Resource/CreationEnums.h` | Read by `CharacterCreationUI_RefreshSummary`, which rebuilds the info window's list (keys `0x2710 + sex × 100`, body type, hairstyle ...) and clears it |
| `CreationFlag_NameAccepted` | `0x800` | same | Set by `CharacterCreationUI_CheckName` for an allowed name; name entry then goes to the Confirm tab |
| `CreationFlag_RedrawPanel` | `0x2000` | same | Read by `func_ov009_02184ca4` and `func_ov023_021da274`: redraw the bottom panel (tile map 3, the keyboard's page, the rejection message), then cleared |
| `CreationFlag_RefreshName` | `0x8000` | same | Read by `CharacterCreationUI_RefreshNameText`, which redraws the Name line and clears it |
| `CreationFlag_NameRejected` | `0x400000` | same | Set by `CharacterCreationUI_CheckName` for a forbidden name; the panel shows its message and name entry waits for A, X, a touch or B |
| `CreationFlag_HideButtons` | `0x1000000` | same | `ConfigureEntryPositions_021da770` places the Confirm and Back sprites only while it's clear |
| `CreationName_BufferSize`, `_MaxLength` | `0x48`, 8 | same | A name's buffer and its 8 characters |
| `NameEntryStep` | `0`–`3` | `CharacterCreationUI_HandleNameEntry_02186e00.cpp` (file-local, one per region body) | `step_` on the name entry tab: Setup (the keyboard's text, limits and first key), Start (one frame: key repeat reset, stylus rotation on, info window refreshed), Input (keyboard and buttons), NameRejected (entered when `CreationFlag_NameRejected` is set; A, X, a touch or B clears it and goes back to Input). jpn has no Start step, so its values are 0–2. Read from each step's code |
| `CreationFlag_RefreshInfoWindow` | `CreationFlag_RefreshName \| CreationFlag_RefreshSummary` | same (file-local) | Both info window refresh flags: the Name line (`CharacterCreationUI_RefreshNameText`) and the list (`BuildElemPaletteTags_021d9a6c`). Name entry sets the pair whenever the name changes, and only checks the name on START while neither is pending |
| `KeyboardPage` | 1, 2, 4, 8 | `include/Resource/Keyboard.h` | The keyboard's pages (lowercase, uppercase, accents, symbols); each key has a mask of the pages it shows on. Read from the live key list |
| `KeyboardAction` | 0-8 | same | A key's action, its slot in the key action table. The name keyboard has: type, caps (1), shift (2), A/1 (3), À (4), ← (5), OK (6), @ (7); 8 (random name) has no key |
| `KeyboardResult` | 0-13 | same | What `Keyboard_Update` returns. Each confirmed in-game by pressing the key and logging `keyboardResult_` |
| `KeyboardGrid` | 11, 6, 66 | same | The name keyboard as a 11 × 6 grid for the `GridCursor` |
| `GridCursorOrder` | 0, 1 | `include/Resource/GridCursor.h` | Cell order for `GridCursor_SetDimensions`; 1 counts across a row first (`GridCursor_GetSelectedIndex`) |
| `CharacterModelPart_Body`, `_Face`, `_Hair`, `_HairTexture` | 0, 2, 3, 4 | `include/Graphics/CharacterModel.h` | Part indices of a character model (`CharacterModel_InvalidatePart`, `parts_` in `func_ov023_021e5974`). Logged in-game: a gender change loaded `d_b008.nsbmd`, `d_p215`, `d_f011`, `d_h180a.nsbmd`, `d_h183a.nsbtx`, … in part order; 4 is the only `.nsbtx` and its number is the hair style's plus `hairColor_`. The body's model also picks the animation files (`md0200w.nsbca`) |
| `AppearanceModel_FirstHairStyle`, `_FirstFace` | `0x2328` (9000), `0x233c` (9020) | same | Model id of hair style 0 and face 0; `CharacterCreationUI_ApplyChoice` adds the style index. Read live: female slot 0 gives hair 9006 and face 9021 (`CharacterCreationUI_SlotToStyleIndex`'s female order starts 6 and 1), male face 9024 (order starts 4) |
| `SoundEffect_Select`, `_Cursor` | 1, 2 | `include/Sound/SePlayer.h` | The menu sound effects, logged in-game: 1 on key presses, 2 on cursor moves |
| `CreationTab_Setup` … `CreationTab_NameEntry` | `0`–`8` | same | Setup, Gender, BodyType, HairStyle, HairColor, Face, SkinColor, EyeColor, NameEntry. Each tab's confirm goes to the next, back to the previous. Read live: `state` 6 shows "6 Skin Colour" and 7 "7 Eye Colour" on the bottom screen (6 and 7 were the other way round until checked) |
| `CreationTab_Done` | `12` | same | Character creation finished; tabs 9–11 are still numbers |
| `CreationInput` | (none) | same | Enum of what `CharacterCreationUI_HandleInput` returns |
| `CreationInput_Back` / `_Confirm` / `_None` | `-3` / `-2` / `-1` | same | B or the touchscreen Back button / A or the touchscreen Confirm button / nothing |
| `CreationInput_TabIcon` | `100` | same | A tab icon comes back as `CreationInput_TabIcon + tab`; `_FirstTabIcon` (101) and `_LastTabIcon` (108) bound the range |
| `Brightness` | (none) | `include/Resource/Brightness.h` | Master brightness levels, as `GetBrightness` returns them and the `Set*Brightness` functions take them (whose `duration` is in frames: `15` = 250 ms) |
| `Brightness_Black` / `_Normal` / `_White` | `-16` / `0` / `16` | same | Fully black / normal / fully white. `abs(GetBrightness(...)) == 16` (fully faded either way) is still a number in three overlay 17 files |
| `CreationMode` | (none) | `include/Resource/CreationEnums.h` | Enum of `CharacterCreationUI::mode`: why character creation was opened (the constructor's third argument) |
| `CreationMode_NewGame` | `0` | same | The hero, from the new-game flow (overlay 21, `func_ov021_0218b5fc`). Success sets `GameState::characterCreated_` |
| `CreationMode_PartyMemberCreation` | `1` | same | A new party member, in-game (overlay 3, `0217e6b0.cpp`, which also passes the vocation). Success sets `CreationFlag_MemberCreated` |
| `CreationFlag` | (none) | `include/Resource/CreationEnums.h` | Enum of `CharacterCreationUI::flags` bits whose meaning is known |
| `CreationFlag_StylusRotation` | `0x1` | same | The preview model can be spun with the stylus; set once a tab's fade-in finishes |
| `CreationFlag_LoadNextCharacter` | `0x2` | same | Set by `CharacterCreationUI_ApplyChoice` after it invalidates parts of `nextCharacter`; `UpdateFlag021885b8` then rebuilds `nextCharacter` from `characterData` (`func_ov023_021e5974`) and swaps this bit for `CreationFlag_SwapCharacters`. Logged in-game on a gender change: flags `0x11` → `0x13` (ApplyChoice) → `0x60015` (UpdateFlag) |
| `CreationFlag_SwapCharacters` | `0x4` | same | `func_ov009_02188454` waits for `nextCharacter`'s `loading` to clear, copies the rotation and animation over, swaps `character` and `nextCharacter`, and clears it (logged clearing it after the gender change above) |
| `CreationFlag_TurnToTarget` | `0x8` | `include/Resource/CreationEnums.h` | `CharacterCreationUI_UpdateRotation` turns `character` towards `targetAngle` while it's set and clears it once close. Set by `CharacterCreationUI_HandleEyeColor` (angle `0x1eb`), `_HandleNewGameFinish` (`0x7a`) and by L and R together |
| `CreationFlag_ShowFinishModels` | `0x200` | same | Set only by `CharacterCreationUI_HandleNewGameFinish` once `model` and `secondModel` have loaded; `CharacterCreationUI_Update` and `_Draw3D` update and draw those two only while it's set |
| `CreationFlag_RedrawTabHighlight` | `0x1000` | same | `CharacterCreationUI_SwitchTab` sets it (with `RefreshSummary`); `func_ov023_021da274` draws the current tab's highlight line into `tileMaps[0]`, and `CharacterCreationUI_UpdateVBlank` uploads it and clears the bit. Logged in-game: `SwitchTab` writes `0x1101`, the next VBlank `0x101` |
| `CreationFlag_DimBackground`, `_DimWithQuad` | `0x10000`, `0x800000` | same | Set by `CharacterCreationUI_HandleNewGameFinish`. `AdjustAngleField_021dac40` counts `+0xd98` down over 90 ticks, darkening the main screen's BG1, BG2 and sprites to -16, or with `0x800000` fading a black full-screen 3D quad in |
| `CreationFlag_RescaleOnSwap`, `_ResetAngleOnSwap` | `0x20000`, `0x40000` | same | `CharacterCreationUI_HandleInput` sets both when the sex changes; `CharacterCreationUI_SwapCharacters` re-reads the body size for the new sex and rescales both models, and turns `character` to `0x1eb` before copying its rotation across. Logged in-game: set together on a gender change (`0x60013`), cleared by the swap; after turning the model with R (angle `0x34a2`) a gender change brought it back to `0x1eb`, a hairstyle change kept `0x34a2` |
| `CreationFlag_KeyboardOk` | `0x200000` | same | jpn only: `ApplyNameKeyboardChoice_0218aab0` sets it when the pressed key is the OK key, and `CharacterCreationUI_HandleInput` turns it into `CreationInput_Confirm`. Read from the jpn code; nothing in usa sets it |
| `ChoiceTabStep_Setup`, `_ShowChoice`, `_Input` | 0, 1, 2 | `include/Resource/CreationEnums.h` | `step` on the six choice tabs: set up the slots and cursor (stylus rotation on), wait for `CreationFlag_TabLoading` to clear and apply the stored choice, then input. Read from each handler |
| `CreationCamera_EaseSteps` | `0x1e000` | same | The divisor the face, eye colour and finish code pass to `Camera_EasePositionTo` / `_EaseTargetTo` (fx32 30.0) |
| `CreationAngle_Default`, `_Finish` | `0x1eb`, `0x7a` | same | The preview character's y angle: where `HandleSetup` starts it and the eye colour tab, L+R and a sex change turn it back (seen in-game: `0x1eb` at entry and after a sex change), and what `HandleNewGameFinish` turns it to |
| `CreationAngle_HalfTurn`, `_FullTurn` | `0x3244`, `0x6488` | `include/Resource/CreationEnums.h` | π and 2π in fx32 (`FIX_2PI`), as `CharacterCreationUI_UpdateRotation` wraps the angle. Seen in-game: turning past 0 wrapped to `0x4021` (`0x1eb` − `0x2652` + `0x6488`) |
| `BareBodyItem` | 1000 | `CharacterModel_Load` (file-local) | The item `CopyAndClampShorts_021e5fdc` puts in the body slot when nothing is equipped there (`0x3e8`) |
| `RotationTurn_Divisor`, `_Snap`; `ROTATE_SPEED` | 12, 40; `0.08f` | `CharacterCreationUI_UpdateRotation` (file-local) | Turning to `targetAngle` moves 1/12 of what's left each tick and snaps within 40; L, R or an arrow turns 0.08 radians a tick |
| `RotateArrow_*` | `0xa9`–`0xb1`, `0xe`–`0x17`, `0x3b`–`0x44` | same | The two rotate arrows' touch rectangles. Seen in-game: tapping (18, 173) turned the preview +`0x2652`, (63, 173) back by the same |
| `GenderStep_Setup`, `_FadeIn`, `_ShowChoice`, `_Input` | 0–3 | `CharacterCreationUI_HandleGenderSelection` (file-local) | The gender tab's steps; Setup falls through into FadeIn in the same frame. Logged in-game entering character creation: the handler wrote `step` 1, 2, 3 |
| `ConfirmStep_Open`, `_Show`, `_Input`, `_Accept`, `_Decline` | 0, 1, 2, 3, `0xff` | `include/Resource/CreationEnums.h` | The confirm tab's steps; `CharacterCreationUI_Update` keeps the Yes/No window's touch state only in `_Input` |
| `CloseStep_FadeOut`, `_Finish` | 0, 1 | `CharacterCreationUI_HandleClose` (file-local) | Fade to black, then (once the fade ends) empty both windows, undo the bottom screen's darkening and go to `CreationTab_Done`. Seen in-game: backing out of the gender tab ran it, then `_Destroy`, and the game went back to the boot logos |
| `TabLoadStep_Queue`, `_Wait`, `_Loaded` | 0, 1, 2 | `include/Resource/CreationEnums.h` | `resourceStep` while a tab's graphics load. Logged in-game on a tab change: `_LoadTabGraphics` wrote 1 then 2, `_ApplyTabGraphics` 0 |
| `CreationText_InnerFileOffset`, `_FemaleOffset` | 50, 100 | same | Text keys that are file names (from the ROM's `str_cm_en.nat`): key N is tab N's archive `data/ani/bg_cm_*.gp2`, N + 50 the `.pac` inside it, N + 100 the female version (`fig_f`, `ht_f`, `fac_f` for tabs 2, 3, 5) |
| `CreationText_FirstRandomName`, `_RandomNameStride` | 20000 (`0xe20 + 0x4000`), 1000 | same | `CharacterCreationUI_PickRandomName` picks text 20000 + sex × 1000 + rand() % 101. Read live: 20000 "Irving" … 20100 "Wayne", 21000 "Iris" … 21100 "Wanda", nothing at 20101 or 21101; the random name the game gave was "Joaquim". The compiler split 20000 into two adds |
| `CreationFade_Frames` | 15 | same | The 250 ms fades of the gender and close tabs (`SetBrightness`' duration is in frames) |
| `CreationFlag_ChoiceChanged` | `0x10` | same | The input handler stored a different choice this frame |
| `CreationFlag_ConfirmTouched` | `0x20` | same | The confirm button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_BackTouched` | `0x40` | same | The back button was touched this frame (cleared at the start of each input call) |
| `CreationFlag_MemberCreated` | `0x400` | same | Mode 1 (party member creation): set by tab 9 once the new member is set up and added to the party, cleared on backing out of the gender tab. Mode 0's counterpart is `GameState::characterCreated_` |
| `CreationFlag_TabLoading` | `0x80` | same | Set on going to a tab (`SetStatValue021855dc`), cleared by `func_ov009_02184e58` once the tab's graphics have loaded |
| `SetupStep_Init`, `_LoadBackgrounds`, `_LoadSprites`, `_QueueKeyboard`, `_LoadKeyboard`, `_Finish` | `0`–`5` (jpn: 0, 1, 2, then `_Finish` = 3, no keyboard steps) | `CharacterCreationUI_HandleSetup` (file-local) | `step_` on tab 0. Init loads the text and item tables, creates both models, loads the wings (new game), places the camera, sets the default choices and appearance, creates layers 0, 1, 2, 5 and queues `bg_cm_ms`. LoadBackgrounds waits for that archive, fills the layers, makes the window panes and sprite sets, and queues `cell_cm`. LoadSprites loads the sprite files. QueueKeyboard and LoadKeyboard load `keyboard_cm.bin` or `keyboard_cs.bin`. Finish poses both models, lays out the panes and switches to `CreationTab_Gender`. LIVE: the handler ran for about 7 frames on entry and wrote `step` 1, 2, 3, 4, 5 in order; then `SwitchTab` set 0 and the Gender tab started. Each step's contents are CODE |
| `CreationAllocator_MainLayers`, `_TabLayers`, `_BottomText`, `_Characters`, `_ItemTable`, `_Texts`, `_Sprites`, `_NameFilter`, `_KeyboardLayout` | `allocators_[0]`–`[8]` | same | What each allocator holds, from its users. [0]: layers 0–2 and window 0's buffers (also `_ApplyTabGraphics` rebuilding layers 0–2 on tab 10). [1]: layers 3 and 4 (`_ApplyTabGraphics`); jpn setup borrows it for the raw text file. [2]: layer 5 and window 1's buffers. [3]: both `CharacterModel`s. [4]: the item table. [5]: the text table. [6]: the `cell_cm` sprite data. [7]: jpn hands it to the name checker (`nameFilter_ + 0x1c`). [8] (usa): the keyboard layout. CODE |
| `CreationLayer_Backdrop`, `_TabHighlight`, `_SummaryText`, `_Page`, `_Selection`, `_BottomText` | 0–5 (indexes of `layers`) | `include/Resource/CreationEnums.h` | The six layers `CharacterCreationUI_HandleSetup` creates (from `setupBgSubScreen`/`setupBgNumbers`): main BG1 backdrop, main BG2 the current tab's line of the summary, main BG3 `windows[0]`'s text, sub BG0 the tab's page, sub BG1 its choices and the bottom panel, sub BG2 `windows[1]`'s text. `_ApplyTabGraphics` rebuilds 3 and 4 per tab, `_UpdateVBlank` uploads 1, 3 and 4 |
| `SetupLayers_Count`, `_BottomTextSlot` | `4`, `3` | same | The four layers step Init creates (`setupBg*` tables have 4 entries). Slot 3 is layer 5, the one on the sub screen, which takes `CreationAllocator_BottomText` |
| `CreationWindowIndex_Summary`, `_Bottom` | `canvasListA_`, `canvasListB_` (now `windows_[0]`, `[1]`) | same | The header's `windows[0]` (summary list, main screen) and `windows[1]` (bottom screen text). Their layers are `CreationLayer_SummaryText` and `_BottomText` (CODE) |
| `SummaryWindow_PaneCount`, `_BufferBytes`, `_PaneBytes` | `1`, `0x1000`, `0x200` | same | Window 0 has 1 pane. Its shared buffer (`windowBuffer0_`) is 0x1000 bytes, and the pane's own buffer is 0x200 (`AllocateBuffer0204c7a8` allocates that length into `pane+0xd4`). CODE |
| `BottomWindow_PaneCount`, `_BufferBytes` | `4`, `0x400` | same | Window 1: 4 panes (lengths from `CharacterCreationUI_window1PaneSizes`), with a 0x400-byte shared buffer (CODE) |
| `BottomWindow_NamePane` | `3` | same | Pane id 3 of `windows[1]`. `CharacterCreationUI_RefreshNameText` writes the name line into it (`TryApplyElemFields0205d5d0(&windows[1], 3, …)`), and `SetupTag021d9da4` creates it (`nextWindow = 3`). CODE |
| `BottomWindow_UnknownPane2` | `2` | same | **Placeholder.** Pane id 2 of `windows[1]` (created by `SetupTag021d9c7c`). `RefreshFieldIfFlag4000_021d9d34` writes text `0x4274` (`"<W=10>"` in usa) into it. What it shows on screen is unknown |
| `MainSprites_Count`, `SubSprites_Count` | `6`, `0x19` | same | Sprites per set: `CharacterCreationUI_Allocate` allocates 0xf0 and 0x3e8 bytes = 6 and 25 × 0x28 (CODE) |
| `SubSprites_FirstFile` | `4` | same | `cell_cm_<LG>.pac` files 0–3 are `cm_cellobj_mainscr_*` (NCGR/NCLR/NCER/NANR) and go to the main set; files 4–7 are `cm_cellobj_subscr_*` (ROM listing) |
| `SetupBgFile_WindowTiles`, `_LastBackdrop` | `0`, `3` | same | `bg_cm_ms_<LG>.pac` file 0 is `cm_win_clear_chara.bncg`, loaded into both text layers. Files 1–3 are `cm_mainscr_chara.bncg`, `cm_mainscr_npc.bnsc` and `cm_mainscr.bnsc`, the backdrop. Files 4+ are `cm_mainscr_sel_chara`, `cm_maniscr_sel` and both palettes, loaded into the highlight layer. Party mode's `fileCount--` drops file 7, `cm_mainscr_pltt` (ROM listing) |
| `BackdropScreen_Npc`, `_Hero` | `0`, `1` (local `visible`) | same | Screen index in the backdrop layer: screens are appended in file order, so 0 = `cm_mainscr_npc.bnsc` (party creation) and 1 = `cm_mainscr.bnsc` (new game). This is the same hero/npc split as `CharacterCreationUI_paletteSkipModes` (CODE + ROM) |
| `BackgroundMap_Columns`, `_Rows`, `_ScreenRows`, `_KeepPalette` | `0x20`, `0x19`, `0x18`, `0xffff` | same | `func_0204b620` and `func_0204bc74` use a 32-tile row stride and clip at 25 rows. 24 rows are one 192-pixel screen. A palette of `0xffff` makes `func_0204b620` keep each tile's own palette bits (CODE) |
| `SetupText_SpriteArchive` | `1000` (jpn `1000`) | same | Text key: `data/ani/cell_cm.gp2`. Plus `CreationText_InnerFileOffset` it is `0x41a` = 1050, `cell_cm_<LG>.pac` (ROM `str_cm_en.nat`) |
| `SetupText_WingsModel` | `0x7d0` | same | Text key 2000: `d_hane.nsbmd` (ROM), the model loaded into `wings_`. LIVE: the wings show at the new-game finish |
| `SetupText_BlankName` | `0x4272` | same (jpn only) | Text key 17010, `"*****"` in the usa table (ROM). jpn copies it into both names. jpn's own table was not read |
| `CreationItemIds_Count` | `0x29` | same | The 41 entries of `CharacterCreationUI_itemIds` (NAMING Data row) |
| `CharacterModelSize_Bytes` | `0xc20` | same | `sizeof` a `CharacterModel` (NAMING: 10 `Object3D` parts, 0xc20 bytes) |
| `TextFileBuffer_Bytes` | `0x1800` | same (jpn only) | The buffer jpn loads its text archive file into before `func_020dfec0` parses it (CODE) |
| `WingsTextureVram_Bytes`, `WingsPaletteVram_Bytes` | `kPairTableSize` / `kPairTableAlign` (`0xc00` / `0x30`), types `PairTableSize` / `PairTableAlign` | same | Arguments 2 and 3 of `func_0207de48` for `wingsVramState_`. Argument 3 goes to `func_020bb7cc`, whose file is the NNS frame palette VRAM manager. Argument 2 goes to `func_020bb588` in 0x20000 chunks, i.e. texture VRAM (the NAMING row for `wingsVramState` already says texture/palette). The enum types stay distinct, as the matching needs |
| `FinishEffectVram_TextureBytes`, `_PaletteBytes` | `0x1a00`, `0x20` | same | The same for `finishEffectVramState_` (CODE) |
| `DefaultCamera_X`, `_Y`, `_PositionZ` | `0xd000`, `0xf800`, `0x42ccc` | same | fx32 13.0, 15.5 and 66.8. The camera's position is (X, Y, PositionZ) and its target is (X, Y, 0). LIVE: camera `+4` is the position and `+0x10` the target. The same values as `CharacterCreationUI_faceTabExitCameraPosition`/`Target`, "the default view" |
| `CreationSex_Male`, `_Female` | `0`, `1` (indices of the choice arrays, value of `sex_`) | same | `sex_` is copied into `PartyMemberAppearance::female_`, and `CharacterModel_Load` picks the `'w'` animations when that is 1. Matches `CreationSex` in `CharacterCreationUI_DrawTabLayers` (jpn) |
| `AppearanceSlot_Face`, `_HairStyle` | `2`, `3` | same | `AppearanceModels::models[2]`/`[3]` are `PartyMemberAppearance::face_`/`hairStyle_` (NAMING Fields row) |
| `PlainOutfit_Body`, `_Arms`, `_Legs`, `_Feet` | `0x32cd`, `0x36b5`, `0x3f55`, `0x43fe` | same | Item ids a party member with a vocation is dressed in (ROM `iteminfo_en`): 13005 "A bog-standard bit of kit made of common cloth.", 16213 "Simple slacks made of standard stuff.", 17406 "Simple slip-ons that slip on simply.". 14005 has no description; every 14xxx id lacks one |
| `CelestrianOutfit_Body`, `_Arms`, `_Legs`, `_Feet` | `0x32cf`, `0x36b7`, `0x3f57`, `0x42e0` | same | The new-game hero's outfit (ROM): 13007 "Astral attire made from incredible ingredients.", 16215 "Strange stockings that somehow seem angelic.", 17120 "Unsophisticated footwear well-suited to apprenticing Celestrians." |
| `StartingWeapon_Knife`, `_CopperSword`, `_PeacockFan`, `_OakStaff`, `_BambooSpear`, `_BambooPole`, `_Boomerang` | `0x4a6a`, `0x4e24`, `0x4e84`, `0x4fb3`, `0x5014`, `0x5078`, `0x50dc` | same | The weapon per vocation (ROM descriptions): 19050 "A gnat of a knife…" (19xxx knives), 20004 "A commonplace cutter made of copper." (20000s blades), 20100 "A flamboyant fan made from peacock feathers.", 20403 "A staff whittled from the wood of an old oak tree.", 20500 "A simple spear fashioned from fresh bamboo.", 20600 "A long bamboo pole…" (20600s sticks), 20700 "A thrown weapon that can strike all enemies…" (20701 is "A slightly superior version of the basic boomerang"). `CharacterCreationUI_HandleConfirm` copies appearance slot 7 into equipment slot 8, so the member starts with it. The vocation case numbers (1–12) are **still numbers**: which vocation each is needs a LIVE log of `vocation` per vocation |
| `FinishLayer_Count` | 3 | same | The three layers the new-game finish rebuilds, as many as `CharacterCreationUI_finishBg*` have entries |
| `TabLayer_Page`, `_Selection`, `_Count` | 0, 1, 2 | same | The two layers a tab rebuilds, and the column order of `CharacterCreationUI_tabBg*` / `_tabScreenCounts`. Entry 0 is the page: its count becomes `pageScreenCount` |
| `BackgroundMapSize_Text256x256` | 0 | same | What `SetWord0x18ClearByte0x1f_0204b11c` writes to `+0x18` (it also clears `+0x1f`). `AllocateAndClearBuffer0204b12c` sizes the map as `data_020e7b98[+0x1f][+0x18]`. Row 0 of that table (ROM) is `0x800, 0x1000, 0x1000, 0x2000`, the text BG sizes, so [0][0] = `0x800` = 32 × 32 tiles = 256 × 256 px |
| `BackgroundMap_Columns`, `_ScreenRows`, `_ClipRows` | `0x20`, `0x18`, `0x19` | same | `func_0204b620` (the screen copy) and `func_0204bc74` (the fill) address the map at 32 tiles a row and clip at x 32 and y 25. The page and backdrop are drawn 32 × 24 (192 px / 8), and the layers are filled over all 25 rows |
| `BackgroundPalette_Keep` | `0xffff` | same | `func_0204b620` copies tiles unchanged for palette `0xffff`. Any other value replaces bits 12–15 (`palette << 12`) |
| `TabScreenCountsRow_FirstCount`, `_Size` | 1, 3 | same | `CharacterCreationUI_tabScreenCounts` rows are `{tab, page count, selection count}`. The loop steps by 3, and the count for layer i is at `row + i + 1` |
| `ChunkTag_Length` | 4 (and `char[5]`) | same | Archive files start with a 4-character tag (`"CHAR"`, `"PALT"`, `"SCRN"` at `0x020f0238` in ROM, the same ones `func_0204b174` compares). The tag is copied into a 5-byte zeroed buffer and compared over 4 bytes |
| `FinishArchiveFile_ClearTile` | 2 | same | File 2 of `bg_cm_msbg.pac` (text key 10/60), the new-game finish archive, is `cm_win_clear_chara.bncg`: 48 bytes = a 16-byte header plus one blank 4bpp tile (ROM). That file goes to the tab highlight and summary layers, and every other file goes to the backdrop |
| `PageScreen_Page` | 0 | same | Screen 0 of the page layer: the tab's page (`cm_figure_man.bnsc`, `cm_sex_back_npc.bnsc`, …, ROM) |
| `PageScreen_GenderNewGame` | 1 | same | On the gender tab (`bg_cm_sx`), screen 1 is `cm_sex_back.bnsc` and screen 0 is `cm_sex_back_npc.bnsc` (ROM, the same in all 5 language pacs). The code draws screen 1 only for `CreationMode_NewGame` on `CreationTab_Gender` |
| `PageScreen_French`, `_Italian`, `_German`, `_Spanish` | 1, 2, 3, 4 | same | In the tab 2–7 archives (`bg_cm_fig_m`, `ht_m`, `hc`, `fac_m`, `sc`, `ec`), page-layer screens 1–4 are `cm_*_fr`, `_it`, `_de`, `_es.bnsc`. Each is 94 bytes = 16 + 13 × 3 × 2, so 13 × 3 tiles (ROM). The code maps languages FR→1, IT→2, DE→3, ES→4 |
| `PageScreen_CountWithLanguageTexts` | 5 | same | The page layer holds 5 screens on tabs 2–7 (`tabScreenCounts` (2,5,·) … (7,5,·)), the page plus the four language texts. **Note:** the name tab's page layer also holds 5 (4 keyboard pages + `cm_name_que`), so with DS language FR/IT/DE/ES the code would also draw keyboard page N's top-left 13 × 3 tiles at (1, 1) there. Not checked in-game |
| `LanguageText_X`, `_Y`, `_Width`, `_Height` | 1, 1, `0xd`, 3 | same | Where the language text is drawn on the page: tile (1, 1), 13 × 3 tiles, the size of the `_fr`/`_it`/`_de`/`_es` screens (ROM). That it is the tab's title is **not** confirmed (needs DS language FR in-game) |
| `NameTabScreen_KeyboardPageCount`, `NameTabScreen_Que` | 4, 4 | same | On the name tab (`bg_cm_nm`, the same in all 5 language pacs, ROM), the page layer gets files 0–4 (`cm_name_chara.bncg` + `cm_name_small`, `_capital`, `_europe`, `_symbol.bnsc`) and the archive's last file, `cm_name_que.bnsc`. So screens 0–3 are the keyboard pages (lowercase, uppercase, accents, symbols, the `KeyboardPage` order) and screen 4 is `que` |
| `NameTabQue_X`, `_Y`, `_Width`, `_Height`, `_Palette` | `0x13`, `0x11`, 4, 2, 1 | same | `cm_name_que.bnsc` is 32 bytes = 16 + 4 × 2 × 2, so 4 × 2 tiles (ROM). In party member creation the code copies it to tile (19, 17), pixel (152, 136), of each keyboard page with palette 1. What it shows is not known (needs a party-creation vs new-game screenshot of the keyboard at that spot) |
| `OSLanguage_French`, `_German`, `_Italian`, `_Spanish` | 2, 3, 4, 5 | same | NitroSDK `OSLanguage`, as `NormalizeField5_0200fb08` returns it. It reads the owner info's language (`func_020c99c8`: `0x027ffc80 + 0x64` & 7) and keeps only 2 and 5 in usa (the ROM is EnFrEs; eur keeps 2–5). The usa archives order their screens `_fr, _it, _de, _es`, which matches the switch 2→1, 4→2, 3→3, 5→4 only with the SDK values |
| `CreationTab_NewGameFinish`, `_NameEntry`, `_Gender` | 10, 8, 1 | `include/Resource/CreationEnums.h` (existing) | Used in place of the bare `state` numbers |
| `TabLoadStep_Loaded`, `_Queue` | 2, 0 | same (existing) | Used in place of `loadStep_ != 2` / `= 0` |
| `CreationTabIcon_Count`, `_FirstX`, `_Y`, `_Size` | 8, `0x78`, 8, 16 | `include/Resource/CreationEnums.h` | The row of tab icons at the top of the touchscreen, icon N being the 16 × 16 square at `x = 0x78 + N × 16`, `y = 8`. `CharacterCreationUI_PlaceSprites` puts sprites 11–18 there (`(i * 16 + 0x78) << 12`, y `0x8000`) for the tabs reached; `GetTouchedInput` returns `CreationInput_FirstTabIcon + N` for a touch inside one; `RESET_NAVIGATION(8, 1, 8, state - 1)` makes the GridCursor this one-row grid. |
| `CreationButton_Top`, `_Bottom`, `_ConfirmStart`, `_ConfirmEnd`, `_BackStart`, `_BackEnd` | `0xa9`, `0xb1`, `0x8e`, `0xbe`, `0xc8`, `0xf0` | `CharacterCreationUI_GetTouchedInput` (file-local) | The Confirm and Back buttons' touch rectangles (y 169–177; x 142–190 and 200–240). Seen in-game: touching (166, 173) and (150, 173) confirmed, (220, 173) and (214, 173) went back. `CharacterCreationUI_PlaceSprites` puts the usa button sprites at x `0x8e` and `0xc8`, y `0xa9` |
| `CreationInput_NothingTouched` | `-4` | `include/Resource/CreationEnums.h` (`CreationInput`) | What `GetTouchedInput` returns when the touch hits no button, tab icon or slot. None of `HandleInput`'s branches match it (not Back/Confirm, not 101–108, not ≥ 0). |
| `JpnName_MaxLength`, `JpnName_Size` | 5, 10 | `CharacterCreationUI_HandleInput` (jpn half, file-local) | A jpn name holds up to 5 two-byte characters: `func_ov009_0218aab0` stops the write index at 5 (`if (changedIndex >= 5) --changedIndex`), `names[2][11]` is 10 bytes and a NUL, and the B check compares 10 bytes. With A, when a character was typed and the length reaches 5, the cursor goes to the keyboard's last cell |
| `JpnName_EmptyText` | `0x4272` | same | Text key of an empty jpn name: `func_ov009_0218b850` copies its 11 bytes into the name before writing a random name over it, and B compares the name with it (`memcmp` over 10 bytes): equal means nothing typed, so B goes back to the previous tab; otherwise B deletes a character (`func_ov009_0218b200`), like usa's `KeyboardResult_NothingToDelete`. The string itself is unread (no jpn ROM here) |
| `KEY_DOWN`, `KEY_A`, `KEY_B`, `KEY_UP`, `KEY_START`, `KEY_SELECT` (uses) | `0x80`, `1`, `2`, `0x40`, `8`, `4` | `CharacterCreationUI_HandleInput` | `TestKeysPressed` masks, `include/Input/Input.h` |
| `SoundEffect_Select`, `_Cursor` (uses) | 1, 2 | same | `SePlayer_Play`'s effect; the file now includes `Sound/SePlayer.h` instead of declaring it. Seen in-game: a choice change plays 2, key presses 1 |
| `KeyboardGrid_Columns`, `_Rows`, `_Cells` (uses) | 11, 6, 66 | same, both halves | The GridCursor shape on name entry (`RESET_NAVIGATION(11, 6, 66, ...)`, `SetDimensions(..., 11, 6, 0)`, jpn `rows == 6`); jpn's last cell is `KeyboardGrid_Cells - 1` (was 65). jpn uses the same 11 × 6 shape, so the constants fit there too |
| `GridCursorOrder_RowMajor`, `_ColumnMajor` (uses) | 1, 0 | same | `GridCursor_SetDimensions`'s order: `RESET_NAVIGATION` passes 1; usa's switch to name entry passes 0 (column-major, unlike everywhere else) |
| `AppearanceModel_FirstFace`, `_FirstHairStyle`; `CreationTab_Face`, `_HairStyle` (uses) | `0x233c`, `0x2328`; 5, 3 | same | The new sex's face and hair style model ids: `SlotToStyleIndex(self, tab, slot) + first id`, as `CharacterCreationUI_ApplyChoice` writes them |
| `CreationInput_None`, `CreationTab_Gender` (uses) | `-1`, `1` | same | `choice`'s start value; `state - 1` / `furthestState[sex] - 1` are the icon of a tab (icon N is tab N + `CreationTab_Gender`) |
| `CreationInput_Back`, `_Confirm` (uses) | `(unsigned)(choice + 3) <= 1` | same | Now `(unsigned)(choice - CreationInput_Back) <= CreationInput_Confirm - CreationInput_Back`: choice is Back or Confirm |
| `ForbiddenWordMatch_Whole`, `_Contains`, `_Suffix`, `_Prefix` | 0, 1, 2, 3 | `CharacterCreationUI_CheckName` (file-local) | `ForbiddenWordPattern::matchTypes_`: where the word must sit in a span of the name. 0: span length == word length and `NameFilter_FindWord` at the span's start; 1: span ≥ word, `NameFilter_FindWord` tries all `spanLength − wordLength + 1` offsets; 2: at `begin + spanLength − wordLength`; 3: at the span's start (code, the switch). Most single-word entries are 1 (927 of 1302, ROM) |
| `ForbiddenWordMatch_PatternWhole`, `_PatternContains`, `_PatternSuffix`, `_PatternPrefix` | 4, 5, 6, 7 | same | The same four tests through `NameFilter_MatchPattern` instead of `NameFilter_FindWord` (code). 71 of the 72 type 4–7 words contain pattern syntax, 1268 of the 1270 type 0–3 words contain none (the other two contain a literal `-`) (ROM) |
| `ForbiddenWord_MaxWords` | 5 | same | Words per tv.nat pattern: the sizes of `words_`, `lengths_`, `matchTypes_` (0x20-byte records, ROM) and of the `wordTokens` buffer |
| `FontId_Me` | 1 | same | The font argument of every `Font_*` / `func_020426bc` call here: `data_0210782c[1]` = `fi_me.bin` (see Font 1 above) |
| `MeFont_Zero`, `_LowerZ` | 8, 69 | same | Font 1 indexes of `'0'` and `'z'`: 8–17 are `0`–`9`, 18–43 `A`–`Z`, 44–69 `a`–`z` (ROM). The kept range digits-and-letters |
| `MeFont_UpperOE`, `_LowerOE` | 77, 83 | same | `<OE>`, `<oe>` (ROM), kept as is |
| `MeFont_SlashTag` | 107 | same | `</>` (ROM); CheckName writes the text of entry `slashId` (`/`, index 2) instead |
| `MeFont_FirstAccented`, `_LastAccented` | 120, 169 | same | `` <`A> `` … `<:u>` (ROM). A tag whose second character is a letter other than `s` is kept (`<AE>`, `<x>`); the rest become their uppercased third character (`` <`A> `` → `A`, `<,C>` → `C`, `<ss>` → `S`) (code + ROM) |
| `MeFont_Zero`, `MeFont_A`, `MeFont_Z` | `8` (`- 8`), `0x12`, `0x2b` | `NameFilter_MatchPattern` (file-local) | `'0'`, `'A'`, `'Z'` in font 1 (ROM). A repeat count's digit token − `MeFont_Zero` is its value; the letter class accepts `MeFont_A`..`MeFont_Z` |
| `NameToken_End`, `NameToken_Space` | 0, 0xff | both files (file-local) | What `func_020426bc` writes: the character's font index, 0xff for `' '`, 0 after the last (also 0 for a character it can't find) (`TokenizeAndEncode_020426bc.cpp`). CheckName also overwrites its comma tokens with 0xff after building the spans, so a `.{0,60}` skip stops at both |
| `NameSpanChunk_Length` | 18 / 19 | `CharacterCreationUI_CheckName` (file-local) | A counter of tokens from the start of the text, reset every 19; an open span is closed (joined to the next) at the 19th. Why 19 is not known: an 8-character name never reaches it, and overlay 12's message checker (`func_ov012_02184d80.cpp:241,251`) has the same code. See Placeholders |
| `NameFilterFile_Patterns`, `_ReservedNames` | `[0]`, `[1]` | same | Indexes of `fileSizes`: tv.nat's size (loaded first at `data_0211e33c`), res.nat's (loaded after it) (code: the two `LoadFileIntoMemory` calls) |
| `NameFilterFile_Alignment` | `511` / `~511` | same | res.nat is loaded at tv.nat's size rounded up to 512. Written as `(size + (512 − 1)) & ~(512 − 1)`: the `AlignUp` inline compiles differently here |
| `SkipPattern_MaxRepeat`, `_Length` | 60, `token[7]`, `token += 8` | `NameFilter_MatchPattern` (file-local) | `.{0,60}X`: a wildcard repeated 0–60 times is matched by skipping to the next `X` (failing at a space or the end); `.{0,60}` is 7 tokens, `X` the 8th (code). tv.nat uses `{0,60}` once (ROM) |
| `GroupKind_Set`, `_Range`, `_Negated`, `_NegatedSet`, `_NegatedRange` | `hasRange` 0, 1, 2, 2, 3 | same | A `[...]` group: 0 the members are a set (`NameFilter_GroupContains`); 1 a range (members[0] ≤ token ≤ last member); +2 when it contains `^`, which inverts the test and skips the `^` (code) |
| `ConfirmChoice_Yes`, `_No` | `case 0`, `case 1` | `CharacterCreationUI_HandleConfirm` (file-local) | `windows[1]`'s Yes/No selection: `func_ov023_021da100` writes item `i` as text `0x465a + i` ("Yes", "No", read live per the `RefreshYesNoMenu` row). Yes goes to `ConfirmStep_Accept`, No to `_Decline`. Live: choosing Yes started the finish |
| `NameEntryStep_Setup`, `_Start` | `step = 1` | same, usa only (copy of `HandleNameEntry`'s enum) | On No, Confirm puts the keyboard on its first key itself and goes to name entry at `_Start`, skipping the keyboard setup |
| `Vocation_Count` | `13` | same | Size of the per-vocation arrays: `experience`, `levels` (indexed by `self->vocation`) and the spell table's rows (indexed by `member->vocation`); `func_020830cc` also copies 13 of each |
| `SpellTable_SpellsPerVocation` | `20` | same | Entries per vocation row of `spelltable.bin` (`13 × 20 × 4 = 0x410` bytes at `+0x10c` of the 0x550-byte table `SetupAndRunBufferedScript0209a810` clears) |
| `EquipmentFromAppearance_Count` | `7` | same | Entries of `CharacterCreationUI_equipmentFromAppearance` (its C definition has 7) |
| `BackgroundMap_Columns`, `_Rows` | `32`, `25` | same | `func_0204bc74` clips to `x < 0x20`, `y < 0x19`; `(map, 0, 0, 0, 32, 25, 0)` fills the whole map with tile 0, as 8 other callers do |
| `REG_BLDCNT_SUB` | `0x04001050` | same (file-local, as in `HandleClose`) | The sub engine's BLDCNT, passed to `ColorEffect_ConfigureBrightnessAdjust` |
| `BLEND_TARGET_BG0` (existing, `NitroSDK/Graphics.h`) | `1` | `HandleConfirm` | The darkened layer: sub BG0, the page (`layers[3]`). `Brightness_Black / 2` (-8) on Show, `Brightness_Normal` (0) on Accept/Decline |
| `FinishStep_Start` … `_Leave`, `_Done` | 0–11, `0xff` | `CharacterCreationUI_HandleNewGameFinish` (file-local) | Start (turn to `CreationAngle_Finish`, ease camera, `CreationFlag_DimBackground`), WaitTurn (until `TurnToTarget` clears and the camera stops; sets `DimWithQuad`; at 0.8 of the body's animation loads sound bank `0x6f`), QueueLoads, WaitLoads, ApplyLoads (loads, poses, sets `ShowFinishModels`), ModelsLoaded (5: written by ApplyLoads, which writes 6 in the same frame; no case), PlaySound, FadeToWhite, WaitWhite (then every layer blend-darkened to -16), FadeToBlack, WaitBlack (then master brightness -16 set directly, blend back to 0, bank released), Leave (`SwitchTab(CreationTab_Close)`), Done. Code; live: step 1 flags `0x810800`, step 7 flags `0x810a00` (`ShowFinishModels` added between), screen goes white then the scene ends |
| `FinishFile_BodyPackage`, `_Wings`, `_Effect`, `_Count` | `0`, `1`, `2`, `3` | same | Task slots of `CharacterCreationUI_finishModelFiles` (`taskSlot` 0, 1, 2) and the index of `modelTasks_`. Slot 0 goes into the hero's body (`CharacterModel_GetBody`) with `packageID` 1, slot 1 into `wings_`, slot 2 (the only one queued with `QueueLoadFile`, the rest from `CharacterCreationUI_characterArchive`) into `finishEffect_` |
| `FinishText_Wings`, `_BodyPackage`, `_Effect`, `_Animation` | `2001`, `2002`, `0x898` (2200), `2500` | same | Text-table keys (`KeyTable_Get(texts)`) of slot 1's, slot 0's and slot 2's file names and of the animation the body and the wings play. 2001 and 2002 add `sex × CreationText_FemaleOffset` (100). The old locals called 2001 `bodyID` and 2002 `headID`, but 2001's file goes to `wings_` and 2002's into the body |
| `FinishTicks_Dim` | `90` | same | `dimTimer_` start; `func_ov023_021dac40` divides by the same 90 (`kFadeDurationTicks`) |
| `FinishTicks_ShowModels`, `_BeforeWhite`, `_HoldWhite` | `30`, `150`, `120` | same | `waitTimer_` set after ApplyLoads, PlaySound and WaitWhite; `CharacterCreationUI_UpdateWaitTimer` holds the next step back until they run out. Live: `waitTimer` read 43 and 47 during the finish (inside the 150) |
| `FinishTicks_FadeToWhite`, `_FadeToBlack` | `40`, `120` | same | `SetBrightness` durations (frames) to `Brightness_White` and `Brightness_Black` |
| `FinishBodyPackageId` | `1` | same | `ObjectArchiveLoadInfo::packageID` for slot 0; `Object3D::InternalLoadFromCHRArchive` gives the animation package it creates this id |
| `FinishStartAnimationTime` | `0xccc` | same | 0.8 in fx32 of the body's `normalizedAnimationTime_` (0–1), the point WaitTurn waits for |
| `BLEND_TARGET_BG_AND_OBJ` | `0x1f` | same (file-local macro) | `BLEND_TARGET_BG0`…`BG3 \| OBJ`: every layer but the backdrop |
| `Brightness_Black`, `_Normal`, `_White` (existing) | `-16`, `0`, `16` | both files | Master brightness for `SetBrightness` and `func_020c39a0`; also the blend brightness adjust passed to `ColorEffect_ConfigureBrightnessAdjust`, whose comment gives the same scale (-16 fully black) |
| `CreationAngle_Finish`, `CreationCamera_EaseSteps`, `CreationText_FemaleOffset`, `CreationTab_*`, `CreationFlag_*`, `KEY_A`/`KEY_X`/`KEY_B`, `SoundEffect_Select`, `KeyboardPage_Lowercase` (existing) | `0x7a`, `0x1e000`, `100`, 8/10/11, …, 1/0x400/2, 1, 1 | both files | Replace the bare numbers; each from its header |
| `REG_MASTER_BRIGHT`, `_SUB` (existing, `Resource/Brightness.h`) | file-local pointer macros of the same name | `HandleNewGameFinish` | The file redefined Brightness.h's macros as `(short*)`; it now passes `&REG_MASTER_BRIGHT` and declares `func_020c39a0` with `volatile unsigned short*` |

### Macros

| Name | Original | In | What it does |
|---|---|---|---|
| `MOVE_CURSOR_TO_TAB_ICON` | `TAB_CURSOR` | `CharacterCreationUI_HandleInput` (both halves) | Puts the 16×16 highlight on tab icon N in the top row (`x = 0x78 + N × 16`, `y = 8`) |
| `RESET_KEYBOARD_NAVIGATION` | (none; the block was written out twice) | `CharacterCreationUI_HandleNameEntry` | Puts `self`'s `GridCursor` back on the first cell of the 11 × 6 keyboard grid. It keeps its own `navigation` local: passing `&self->navigation_` straight to the calls compiles differently |
| `DISPCNT_MASK_DISPLAY`, `DISPCNT_DISPLAY_BG0`, `_BG1`, `_BG2`, `_OBJ` | `0x1f00`, `0x100`, `0x200`, `0x400`, `0x1000` | `CharacterCreationUI_ApplyTabGraphics` (file-local; belongs in `NitroSDK/Graphics.h` beside `DISPCNT_MASK_*`) | DISPCNT bits 8–12 select which of BG0–BG3 and the sprites are displayed (GBATEK; NitroSDK's `GX_PLANEMASK_*` << 8). This function sets the sub engine to `0x1500` = BG0 + BG2 + OBJ while a tab loads, so sub BG1 (the selection layer, `tabBgNumbers[1]` = 1) is hidden. It sets `0x1700` = BG0 + BG1 + BG2 + OBJ once the tab is built |
| `RESET_NAVIGATION(columns, rows, count, index)` | (same name; parameters `total`, `selected`) | `CharacterCreationUI_HandleInput` (both halves) | Rebuilds `self->navigation` as a one-page, row-major `columns × rows` grid of `count` cells on cell `index`, with no row wrap. Used for the tab icon row (Up from row 0) and, on name entry, for the keyboard (Down from the icons) |
| `MOVE_CURSOR_TO_TAB_ICON(icon)` | parameter `selected` | same | Now written with `CreationTabIcon_*` |

### Data

| Name | Original | Overlay | USA/EUR | JPN | What it is |
|---|---|---|---|---|---|
| `CharacterCreationUI_slotLayouts` | `data_ov009_0218ac04` (jpn `data_ov009_0218bb6c`) | 9 | `0x0218ac04` | `0x0218bb6c` | One `{tab, x, y, w, h, stepX, stepY, cols, rows}` entry per tab, ending in -1. Defined in C for usa; jpn and eur still take it from the ROM |
| `g_sePlayer` | `data_02108760` | Main | `0x02108760` | `0x02108760` (same name) | The menu sound effect player passed to `SePlayer_Play` (279 files) |
| `g_stringFormat` | `data_020ef078` | Main | `0x020ef078` | same name | The string `"%s"` |
| `CharacterCreationUI_firstKeyText` | `data_ov009_0218ad26` | 9 | `0x0218ad26` | (usa/eur only) | `"1"`: the label of the key name entry starts on |
| `CharacterCreationUI_widestCharacter` | `data_ov009_0218ad2a` | 9 | `0x0218ad2a` | (usa/eur only) | `"W"`: its width × 8 + 7 gaps is the name's pixel limit (47) |
| `CharacterCreationUI_nameFill` | `data_ov009_0218bc59` | 9 | (jpn only) | `0x0218bc59` | The 2-byte character jpn copies into a name's empty slots |
| `CharacterCreationUI_tabHandlers` | `data_ov009_0218ab9c` | 9 | `0x0218ab9c` | `0x0218bb04` | The handler for each tab, indexed by `state` (12 member-function pointers and a null one); `CharacterCreationUI_Update` copies it and calls entry `state`. Seen in-game: on tab 6 the `0x02186aec` entry runs. Defined in C (`CharacterCreationUI_tabHandlers_0218ab9c.c`), ported from ZevyaDev/dqix-decomp#318. |
| `CharacterCreationUI_bodyDimensions` | `data_ov009_0218aa70` | 9 | `0x0218aa70` | not identified | `{width, height}` (fx32 shorts) per sex and body type, read by `CharacterCreationUI_GetBodyDimensions`; jpn has the values in a switch. Defined in C (`CharacterCreationUI_bodyDimensions_0218aa70.c`), ported from ZevyaDev/dqix-decomp#319. |
| `CharacterCreationUI_styleOrder` | `data_ov009_0218a9bc` | 9 | `0x0218a9bc` | `0x0218b998` | Slot to style index, 0..9; `CharacterCreationUI_SlotToStyleIndex` overwrites the front of a copy per sex (female face 1, 0; male face 4, 0, 1, 2, 3; female hair 6, 0, ...). Seen live: female face slot 0 = 9021, hair 9006; male face 9024. Defined in C (`CharacterCreationUI_styleOrder_0218a9bc.c`), ported from ZevyaDev/dqix-decomp#319. |
| `CharacterCreationUI_defaultAppearance` | `data_ov009_0218aa40` | 9 | `0x0218aa40` | `0x0218ba1c` | The `PartyMemberAppearance::models_` `CharacterCreationUI_HandleSetup` starts from: {-1, -1, 0, 0, -1 ×6}; it fills in the face [2] and hair style [3]. Defined in C (`CharacterCreationUI_defaultAppearance_0218aa40.c`), ported from ZevyaDev/dqix-decomp#319. |
| `NameFilter_syntaxCharacters` | `data_ov009_0218aafc` | 9 | `0x0218aafc` | not identified | 15 five-byte strings `:` `[` `]` `{` `}` `^` `-` `.` `$` `/` `@` `&` `,` `<c/>` `'`; `NameFilter_Reset` looks each up in font 1 for the pattern matcher (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#322. |
| `NameFilter_cSlashText` | `data_ov009_0218aca0` | 9 | `0x0218aca0` | not identified | `"C"`: what `CharacterCreationUI_CheckName` turns the `<c/>` character into before matching (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#322. |
| `CharacterCreationUI_randomNameCounts` | `data_ov009_0218a9ac` | 9 | `0x0218a9ac` | not identified | {101, 101}: random names per sex; `CharacterCreationUI_PickRandomName` picks text 20000 + sex × 1000 + rand() % count. jpn hard-codes 101. Defined in C (`CharacterCreationUI_randomNameCounts_0218a9ac.c`), ported from ZevyaDev/dqix-decomp#319. |
| `CharacterCreationUI_bareBodyColors` | `data_ov009_0218a9b4` | 9 | `0x0218a9b4` | `0x0218b988` | {12, 13, 4, 1, 6, 7, 9, 14}: the new hero's `bareBodyColor` for each eye colour. Seen in-game: a hero made with eye colour 0 got `+0x56a` = 12. Defined in C (`CharacterCreationUI_bareBodyColors_0218a9b4.c`), ported from ZevyaDev/dqix-decomp#319 |
| `CharacterCreationUI_nameFillText` | `data_ov009_0218aca4` | 9 | `0x0218aca4` | not identified | `"*"`: the constructor stores its font-0 index in `nameFill_`, which pads the shown name (ROM) |
| `CharacterCreationUI_faceTabCameraPosition` | `data_ov009_0218a9c8` | 9 | `0x0218a9c8` | `0x0218b9a4` | (9.0, 18.5, 47.0): the camera position `CharacterCreationUI_HandleFace` eases to on entering the tab. Seen in-game: on the face tab the camera reached exactly these values and the head fills the screen; leaving it, the camera was back at (13.0, 15.5, 66.8) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_faceTabCameraTarget` | `data_ov009_0218a9d4` | 9 | `0x0218a9d4` | `0x0218b9b0` | (9.0, 18.5, 0): the matching camera target (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_faceTabExitCameraPosition` | `data_ov009_0218a9e0` | 9 | `0x0218a9e0` | `0x0218b9bc` | (13.0, 15.5, 66.8): the default view `CharacterCreationUI_HandleFace` eases back to when leaving; the same as `HandleSetup`'s initial camera (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_faceTabExitCameraTarget` | `data_ov009_0218a9ec` | 9 | `0x0218a9ec` | `0x0218b9c8` | (13.0, 15.5, 0): the default target (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_eyeTabCameraPosition` | `data_ov009_0218a9f8` | 9 | `0x0218a9f8` | `0x0218b9d4` | The same close-up for `CharacterCreationUI_HandleEyeColor`. Seen in-game: the eye colour tab shows the head close up (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_eyeTabCameraTarget` | `data_ov009_0218aa04` | 9 | `0x0218aa04` | `0x0218b9e0` | Its target (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_eyeTabExitCameraPosition` | `data_ov009_0218aa10` | 9 | `0x0218aa10` | `0x0218b9ec` | The default view the eye colour tab eases back to (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_eyeTabExitCameraTarget` | `data_ov009_0218aa1c` | 9 | `0x0218aa1c` | `0x0218b9f8` | Its target (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_finishCameraPosition` | `data_ov009_0218aa28` | 9 | `0x0218aa28` | `0x0218ba04` | (0, 15.5, 66.8): the default view moved to x = 0, eased to by `CharacterCreationUI_HandleNewGameFinish` (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_finishCameraTarget` | `data_ov009_0218aa34` | 9 | `0x0218aa34` | `0x0218ba10` | (0, 15.5, 0) (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#324. |
| `CharacterCreationUI_finishModelFiles` | `data_ov009_0218aa98` | 9 | `0x0218aa98` | `0x0218ba4c` | The files `CharacterCreationUI_HandleNewGameFinish` loads for `model` and `secondModel`: task index and allocator per file, ending with a NULL allocator (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#320. |
| `CharacterCreationUI_characterArchive` | `data_ov009_0218acd9` | 9 | `0x0218acd9` | `0x0218bc3e` | `"data/pack_lv5/chara_pd.gp2"` (ROM) |
| `CharacterCreationUI_finishEffectAnimation` | `data_ov009_0218ad41`, then `CharacterCreationUI_secondModelAnimation` | 9 | `0x0218ad41` | `0x0218bc71` | `"0"`: the animation name `CharacterCreationUI_HandleNewGameFinish` gives `finishEffect`, the glowing rings (ROM) |
| `CharacterCreationUI_levelFileFormat` | `data_ov009_0218ad2c` | 9 | `0x0218ad2c` | `0x0218bc5c` | `"data/prm/level%d.bin"`: `CharacterCreationUI_HandleConfirm` loads the new member's level stats for its vocation (ROM) |
| `CharacterCreationUI_equipmentFromAppearance` | `data_ov009_0218aac8` | 9 | `0x0218aac8` | `0x0218ba7c` | 7 × `{appearanceSlot, equipmentSlot}`: 0→0, 1→1, 4→5, 5→6, 6→7, 7→8, 8→9; `CharacterCreationUI_HandleConfirm` copies the item record of each appearance model into that equipment slot (the same shift as `CopyAndClampShorts_021e5fdc`). Defined in C (`CharacterCreationUI_equipmentFromAppearance_0218aac8.c`), ported from ZevyaDev/dqix-decomp#319. |
| `CharacterCreationUI_textArchive` | `data_ov009_0218acb0` | 9 | `0x0218acb0` | `0x0218bc25` | `"data/bin/menu/str_cm.gp2"`, the archive of character creation's text table (ROM) |
| `CharacterCreationUI_textFile` | `data_ov009_0218acc9` | 9 | `0x0218acc9` | not identified | `"str_cm_<LG>.nat"`, the text table inside it (ROM) |
| `CharacterCreationUI_itemIds` | `data_ov009_0218ab48` | 9 | `0x0218ab48` | `0x0218bab0` | 41 item ids (hair styles 9000–9009, faces 9020–9029, both outfits, each vocation's weapon, 994, 1000, 8001, 8010): `CharacterCreationUI_HandleSetup` loads just these from `itemdt` (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_setupBgSubScreen` | `data_ov009_0218a96c` | 9 | `0x0218a96c` | `0x0218b978` | {0, 0, 0, 1}: which screen backgrounds 0, 1, 2 and 5 are on, set by `CharacterCreationUI_HandleSetup` (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_setupBgNumbers` | `data_ov009_0218a994` | 9 | `0x0218a994` | `0x0218b95c` | {1, 2, 3, 2}: their BG numbers (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_setupBgPriorities` | `data_ov009_0218a998` | 9 | `0x0218a998` | `0x0218b968` | {3, 1, 0, 0}: their priorities (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_setupBgScreenCounts` | `data_ov009_0218a99c` | 9 | `0x0218a99c` | `0x0218b952` | {2, 1, 0, 0}: how many screens each holds (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_window1PaneSizes` | `data_ov009_0218a9a4` | 9 | `0x0218a9a4` | `0x0218b990` | {0x200, 0x80, 0x80, 0x80}: the text buffer size of each of `windows[1]`'s 4 panes (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#323. |
| `CharacterCreationUI_newGameKeyboardFile` | `data_ov009_0218acf4` | 9 | `0x0218acf4` | not identified | `"data/bin/keyboard_cm.bin"`, the keyboard layout script for mode 0 (ROM) |
| `CharacterCreationUI_partyKeyboardFile` | `data_ov009_0218ad0d` | 9 | `0x0218ad0d` | not identified | `"data/bin/keyboard_cs.bin"`, for mode 1 (ROM) |
| `CharacterCreationUI_spaceKeyText` | `data_ov009_0218ad28` | 9 | `0x0218ad28` | not identified | `" "`: `CharacterCreationUI_HandleSetup` finds the space key by it and sets its `disabled_` (ROM) |
| `CharacterCreationUI_paletteSkipModes` | `data_ov009_0218a95d` | 9 | `0x0218a95d` | not identified | {0, 1}: PALT number k of a tab archive is skipped when `mode` == entry k, so new game uses the hero palette and party creation the npc one (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_tabBgNumbers` | `data_ov009_0218a95f` | 9 | `0x0218a95f` | `0x0218b93b` | {0, 1}: BG numbers of backgrounds 3 and 4, set by `CharacterCreationUI_ApplyTabGraphics` (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_tabBgPriorities` | `data_ov009_0218a961` | 9 | `0x0218a961` | `0x0218b939` | {2, 1}: their priorities (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_finishBgNumbers` | `data_ov009_0218a963` | 9 | `0x0218a963` | `0x0218b93d` | {1, 2, 3}: BG numbers of backgrounds 0–2 rebuilt on tab 10 (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_finishBgScreenCounts` | `data_ov009_0218a966` | 9 | `0x0218a966` | `0x0218b943` | {2, 1, 0}: their screen counts (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_finishBgPriorities` | `data_ov009_0218a969` | 9 | `0x0218a969` | `0x0218b946` | {3, 1, 0}: their priorities (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_tabScreenCounts` | `data_ov009_0218aa54` | 9 | `0x0218aa54` | `0x0218ba30` | `{tab, background 3 count, background 4 count}`, ending in -1: (1,2,2) (2,5,5) (3,5,1) (4,5,0) (5,5,1) (6,5,0) (7,5,0) (8,5,4), matching each tab archive's screen files (ROM) Defined in C, ported from ZevyaDev/dqix-decomp#321. |
| `CharacterCreationUI_paletteTag` | `data_ov009_0218aca6` | 9 | `0x0218aca6` | not identified | `"PALT"`, the chunk tag `CharacterCreationUI_ApplyTabGraphics` compares (ROM) |
| `CharacterCreationUI_screenTag` | `data_ov009_0218acab` | 9 | `0x0218acab` | `0x0218bc20` | `"SCRN"` (ROM) |
| `__ptmf_null` | `data_020e6d5c` | Main | `0x020e6d5c` (EUR `0x020e6d6c`) | `0x020e7604` | The CodeWarrior runtime's null member-function pointer. The compiler copies it into the last entry of a local member-function-pointer array that ends in `0`, which is the slot every handler-table copy fills from it |
| `NameFilter_patternsFilePath` | `data_020f285c` | Main | `0x020f285c` | not identified | Points to `"data/bin/tv.nat"` (ROM), the forbidden-word patterns `CharacterCreationUI_CheckName` loads; overlay 12's message checker too |
| `NameFilter_reservedNamesFilePath` | `data_020f2858` | Main | `0x020f2858` | not identified | Points to `"data/bin/res.nat"` (ROM), the reserved names |
| `g_itemDataArchive` | `data_020f2a38` | Main | `0x020f2a38` | `0x020f2c98` | Points to `"data/prm/itemdt.gp2"` (ROM) |
| `g_itemDataFile` | `data_020f2a30` | Main | `0x020f2a30` | `0x020f2a30` | Points to `"itemdt_<LG>.nat"` (ROM), the item data inside it |

### Fields

| Name | Original | In | What it is |
|---|---|---|---|
| `GameState::characterCreated_` | raw `+0x63d4` (jpn `+0x6174`) | `include/GameState/GameState.h` | Set when character creation finishes (tab 9), cleared on backing out of it (gender tab, mode 0) and at game state setup; the scene loop goes on to the main game (overlay 17) only when it's set. Still read through raw offsets in `02000c9c.cpp` (`MOVIE_RETURN_FLAG_OFFSET`), `func_0200f3a4` and `func_ov009_0218742c` |
| `Keyboard::widthLimit_`, `textSize_`, `maxLength_` | `unk_c`, `size_`, `unk_14` | `CharacterCreationUI_HandleNameEntry` | The text's pixel limit, its buffer size and character limit (47, 0x48, 8 on name entry); `Keyboard_TypeCharacter` checks the first and last |
| `Keyboard::repeatTimer_`, `repeatDir_` | `unk_18`, `unk_1c` | same | D-pad auto-repeat timer and direction (names from `Keyboard_Update`) |
| `Keyboard::page_`, `font_`, `shift_` | `unk_1e`, `unk_1f`, `unk_20` | same | The page shown (seen changing 1, 2, 4, 8 with the page keys), the font, and the one-shot shift (seen 1 after ⇧) |
| `PartyMemberAppearance::face_`, `hairStyle_` | `models_[2]`, `models_[3]` | `CharacterCreationUI_ApplyChoice` | The face and hair style model ids, written by the face and hair style tabs. `CopyAndClampShorts_021e5fdc` copies them to parts `CharacterModelPart_Face` and `_Hair` (the hair style also to `_HairTexture`). Read live: 9024 and 9000 (male) |
| `CharacterCreationUI::savedKey`, `keyboard`, `keyboardLayout` (usa) | header pad `unknownBeforeTexts` | `include/Resource/CharacterCreationUI.h` | `+0xbc`, `+0xc0`, `+0xc4`: the names `CharacterCreationUI_HandleNameEntry` and the constructor use; the layout is the key list `keyboard_cm.bin` / `keyboard_cs.bin` builds (`CharacterCreationUI_HandleSetup`) |
| `CharacterCreationUI::itemTable` | `unknownBeforeTexts`; the constructor's `partNames_`, `HandleConfirm`'s `equipmentContainer` | same | `+0xc8` (jpn `+0xa8`): the item records of `CharacterCreationUI_itemIds` that `HandleSetup` loads from `data/prm/itemdt.gp2`, handed to both preview models |
| `CharacterCreationUI::nameFilter` | `unknownBeforeTileMaps`; `checker_`, `syntax_`, `PatternSyntax0218a518`, `Obj021847ec` | same | `+0xfc`, 0x3c bytes (jpn `+0xdc`, a different 0x20-byte checker): the forbidden-word files and pattern character ids every `NameFilter_` function takes |
| `CharacterCreationUI::layers[6]` | `tileMaps[4]` at `+0x158` (one entry off) plus two pads | same | `+0x138`: the six background layers `HandleSetup` creates, main BG1 backdrop, BG2 tab highlight, BG3 summary text, sub BG0 page, BG1 selection, BG2 text. The old `tileMaps[n]` is `layers[n + 1]` |
| `CharacterCreationUI::window0Panes`, `window1Panes`, `windowBuffers` | `unknownBeforeSprites`; `canvases_`, `canvasA_`, `pixels_` | same | `+0x370`, `+0x450`, `+0x7d0`: the panes `HandleSetup` attaches to `windows[0]` (1) and `windows[1]` (4), and their text buffers |
| `CharacterCreationUI::characterModels[2]` | `unknownBeforeCharacter`; `characters_`, `models_` | same | `+0x7f0`: the two `CharacterModel`s `character` and `nextCharacter` point into (swapped by `_SwapCharacters`) |
| `CharacterCreationUI::wings`, `finishEffect` | `model`, `secondModel`; `object_`, `object2_` | same and every overlay 9 struct | `+0x878`, `+0xcd8`: the new-game finish's models. Seen in-game: when `CreationFlag_ShowFinishModels` is set the hero gets white wings and a halo (`d_hane`, hane = wings) and two glowing rings (`ev999993000.chr`) appear |
| `CharacterCreationUI::wingsVramState`, `finishEffectVramState`, `modelTasks` | `unknownBeforeModel`, `unknownBeforeSecondModel`; `pairs_`, `unk_808`, `unk_c68` | same | The texture/palette VRAM reserved for each (`func_0207de48`), and the loader tasks of `CharacterCreationUI_finishModelFiles` |
| `CharacterCreationUI::windowInput` | `unknownAfterSelection`; `unk_d85` | same | `+0xd85`: what `windows[1]`'s update returned. Logged in-game on the Yes/No prompt: Down and Up each wrote 1; 2 (the stylus slid onto another item) is read from `func_0205c5b0` |
| `CharacterCreationUI::waitTimer`, `dimTimer` | `unknownBeforeFlags`; `timer_`, `unk_d98`, `fadeTicksRemaining` | same | `+0xd96`: counted down by `CharacterCreationUI_UpdateWaitTimer` (logged 43 and 47 during the finish); `+0xd98`: `CreationFlag_DimBackground`'s 90 ticks |
| `CharacterCreationUI::names`, `nameFill`, `keyboardResult`, `nameTabFlushPass` (usa) | not in the header; `names_`, `nameFill_`, `keyboardResult_`, `unk_db6` | same | `+0xdb0` to `+0xdb6`. `nameTabFlushPass`: logged in-game entering name entry, `CharacterCreationUI_ApplyTabGraphics` wrote 1 then 0: one pass flushes the files' cache, the next uploads them |
| `CharacterCreationUI::resourceStep` values | 0, 1, 2 | same | Logged in-game on a tab change: `CharacterCreationUI_LoadTabGraphics` wrote 1 (queued) then 2 (loaded), `CharacterCreationUI_ApplyTabGraphics` wrote 0 |
| `CharacterCreationUI::mainSpriteContext`, `mainSprites`, `mainSpriteEntries`, `subSpriteContext`, `subSprites`, `subSpriteEntries` | `firstSpriteContext`, `firstSprites`, `firstSpriteEntries`, `spriteContext`, `sprites`, `spriteEntries` | `include/Resource/CharacterCreationUI.h` | The two sprite sets `HandleSetup` creates: the first with `subScreen` 0 and 6 sprites (`cell_cm` mainscr files), the second with `subScreen` 1 and 25 (the touchscreen's buttons, tab icons and cursors, `cell_cm` subscr files) |
| `CreationNavigation::pageCount`, `order`, `step`, `heldKey`, `rowRepeat`, `columnRepeat`, `countdown`, `initialDelay`, `repeatDelay`, `wrapColumns`, `wrapRows` | `field4`, `mode`, `input`, `counter`, `unknown36`, `flags3c`, `flags3d` | `include/Resource/CharacterCreationUI.h` | The grid cursor's fields as `func_0205bf58` (its per-frame D-pad update) names and uses them: it pages only while `pages > 1`, wraps by `wrapColumns`/`wrapRows`, repeats a held key after `initialDelay` (20) then every `repeatDelay` (10) |
| `NameFilter::reservedNames`, `patterns`, `reservedNamesData`, `reservedNamesSize`, `syntaxIds` | `pad`, `unk18`, `field24`, `field28`, `field2a` | `NameFilter_Reset` | The res.nat text table, the tv.nat `ForbiddenWordFile`, the res.nat data and size `CharacterCreationUI_CheckName` loads, and the 15 font-1 ids `NameFilter_Reset` fills (usa; jpn's checker is a different struct) |
| `GridCursor::pageCount` | `unk_4` | `CharacterCreationUI_HandleNameEntry` | The same `+0x4`: name entry sets 1 page |
| `PartyMemberAppearance::skinColor_`, `eyeColor_` | `eyeColor_`, `skinColor_` (swapped) | `CharacterCreationUI_ApplyChoice`, `CharacterModel_ApplyColors`, and the same struct in `func_ov023_021e5020`, `func_ov023_021e5974`, `func_ov012_021863fc`, `func_ov012_02188640`, `02184654.cpp` | Bits 1–3 and 4–7 of byte `0x14`. Logged in-game: picking skin colour Type 1 changed bits 1–3 (3 → 0) and the skin; eye colour Type 5 set bits 4–7 to 4 and the eyes went green. `CharacterModel_ApplyColors` loads the skin palette onto every part and the eye palette only onto the face |
| `PartyMemberData::bareBodyColor` | `unk_56a` (and `appearance`, `m56a`, `b56a` in other files) | `CharacterCreationUI_HandleConfirm`, `CharacterModel_Load` | `+0x56a`: the colour of the clothes shown with no body armour. `CharacterModel_Load` adds it to the file number of a part showing `BareBodyItem`; overlay 26 reads palette colour 15 of palette `+0x56a`. The new hero gets `CharacterCreationUI_bareBodyColors[eyeColor]`, later party members `rand() % 16`. Seen in-game: with the preview's body item removed, the female body loaded `d_b629` at 0, `d_b634` at 5, `d_b641` at 12 (male `d_b042`, `d_b054`), and the top showed orange at 0, dark grey at 12; no other part's file changed |
| `StructDE234_020de234::itemId_` | `level_` | `CharacterModel_Load` | `+0x18` of an item entry: the key `FindElementByKey020dedd0` matches (`GetField0x18Short_020de56c`), i.e. the item id; `level_ == 1000` was `itemId_ == BareBodyItem` |
| `CharacterCreationUI::eyeColor`, `skinColor` | `skinColor`, `eyeColor` (swapped) | `include/Resource/CharacterCreationUI.h`, `CharacterCreationUI_HandleInput`, `_SetupSlotNavigation`, `BuildElemPaletteTags_021d9a6c` | The per-sex eye and skin choices at `+0xda8` and `+0xdaa`. Read live: after picking skin Type 1 and eye Type 5 for the male, `+0xda8` = 4 and `+0xdaa` = 0. `BuildElemPaletteTags` puts `+0xdaa` on the 6th line (Skin Colour) |
| `PaletteTable021e540c::skin2`, `skin4`, `skin8`, `eyes` | `eyes2`, `eyes4`, `eyes8`, `skin` (swapped) | `CharacterModel_ApplyColors` | Palettes indexed by the skin colour (8 entries, 2/4/8 colours, loaded onto every part) and the eye colour (16 entries, 2 colours, loaded onto the face) |
| `func_ov009_0218454c`'s `face_`, `hairStyle_` | `hairStyle_`, `face_` (swapped) | `func_ov009_0218454c` | `+0xda6` and `+0xdac`, as the header has them. Read live: changing the face moved `+0xda6`, changing the hairstyle moved `+0xdac` |
| `Keyboard::wrap_` | `unk_21` | same | The cursor wraps between the top and bottom rows; read by `func_ov003_0215e9ec` on every D-pad move (seen in-game), 0 on name entry |
| `Keyboard::allowAlt_`, `allowCancel_`, `autoRepeat_` | `unk_22`, `unk_23`, `unk_24` | same | L also presses a key; B deletes; holding a direction repeats (in `Keyboard_Update`) |
| `Keyboard::autoRepeat` | `wrap` | `Keyboard_Update` | It gates holding a direction to repeat, not wrapping |
| `KeyboardKey::pages_`, `action_`, `sizeClass_`, `disabled_`, `id_` | `flags_`, `unk_d`, `size_`, `unk_f`, `unk_10` | `CharacterCreationUI_HandleNameEntry` | From the live key list: the page mask, the `KeyboardAction`, the size class, set on the space bar (typing it gives `KeyboardResult_KeyDisabled`), and the grid id |
| `Keyboard_TypeCharacter`'s `page`, `shift`, `disabled`, `text`, `shiftedText` | `state`, `shiftMode`, `isCommand`, `code`, `shiftedCode` | `Keyboard_TypeCharacter` | The same fields, named the same way |
| `CharacterCreation::navigation_`, `lastCursorX_`, `lastCursorY_`, `characterData_`, `furthestState_` | `cursor_`, `lastX_`, `lastY_`, `member_`, `lastStates_` | `CharacterCreationUI_HandleNameEntry` | The header's names for the same offsets |
| `CharacterCreation::nameFill_` | `unk_db4` | same | The character `CharacterCreationUI_RefreshNameText` pads the shown name with |
| `FontCharacter::width_`, `GridCursor::count_` | `unk_4`, `unk_0` | same | The glyph width (×8 + 7 is the name limit); the cell count `GridCursor_SetCount` writes |
| `CharacterCreation::previewAllocators_`, `savedKey_`, `keyboard_`, `keyboardLayout_` | `unk_b8` pad, `unk_c0`, `unk_c4` (jpn `unk_a4`) | `CharacterCreationUI_HandleSetup` | Header `previewAllocators`, `savedKey`, `keyboard`, `keyboardLayout`. Step LoadKeyboard runs the keyboard file into `keyboardLayout_` and stores it in `keyboard_->layout_` |
| `CharacterCreation::itemTable_`, `texts_`, `textBuffer_`, `nameFilter_` | `unk_c8`, `strings_`, `unk_f8`, `unk_fc` (jpn `unk_dc`) | same | Header `itemTable`, `texts`, `textBuffer`, `nameFilter`. jpn calls `NameFilter_Reset` on `nameFilter_` |
| `CharacterCreation::nameFilterTasks_`, `nameFilterAllocator_` (jpn) | `unk_f0`, `unk_f8_` | same | jpn `NameFilter` `+0x14 tasks[2]` (set to -1 by `NameFilter_Reset`) and `+0x1c` (`field1c` there), which gets `&allocators_[CreationAllocator_NameFilter]` here |
| `CharacterCreation::unk_ee` (jpn) | (kept) | same | **Placeholder.** jpn `NameFilter` `+0x12` (`field12` in `NameFilter_Reset`), set to 1 here; meaning unknown |
| `CharacterCreation::layers_`, `windows_`, `window0Panes_`, `window1Panes_`, `windowBuffer0_`, `windowBuffer1_` | `backgrounds_`, `canvasListA_`/`canvasListB_`, `canvasA_`, `canvasB_`, `canvasBufA_`, `canvasBufB_` | same | Header and constructor names (`layers[6]`, `windows[2]`, `window0Panes`, `window1Panes`, `windowBuffers`) |
| `CharacterCreation::mainSpriteContext_`, `mainSprites_`, `mainSpriteEntries_`, `subSpriteContext_`, `subSprites_`, `subSpriteEntries_` | `tableA_`, `entriesA_`, `tailA_`, `tableB_`, `entriesB_`, `tailB_` | same | Header names. The main set gets `subScreen_` 0 and the mainscr `cell_cm` files; the sub set gets 1 and the subscr files (ROM listing) |
| `CharacterCreation::characterModels_`, `character_`, `nextCharacter_` | `models_`, `current_`, `next_` | same | Header `characterModels`, `character`, `nextCharacter` |
| `CharacterCreation::wingsVramState_`, `finishEffectVramState_`, `finishEffect_`, `modelTasks_`, `targetAngle_`, `selection_`, `windowInput_`, `touchedChoice_`, `waitTimer_`, `dimTimer_`, `furthestState_` | `pairs_`, `unk_c68` (split), pads `unk_800`/`unk_c5a`/`unk_d8c`/`unk_d96`/`unk_da0` | same | Header names at the same offsets. Only `wingsVramState_` and `finishEffectVramState_` are used here |
| `CharacterCreation::characterData_` (type `PartyMemberData*`), `resourceTask_`, `resourceStep_` | `hero_` (`Hero*`), `task_`, `loadStep_` | same | Header `characterData`, `resourceTask`, `resourceStep` |
| `CharacterCreation::vocation_`, `bodyType_`, `faceStyle_`, `eyeColor_`, `skinColor_`, `hairStyle_`, `hairColor_` | `unk_da2`, `unk_da4`, `unk_da6`, `unk_da8`, `unk_daa`, `unk_dac`, `unk_dae` | same | Header names. Consistent with this code: `faceStyle_` goes through `SlotToStyleIndex(…, CreationTab_Face, …)` + `AppearanceModel_FirstFace`, `hairStyle_` through `CreationTab_HairStyle` + `_FirstHairStyle`, and `skinColor_`/`eyeColor_`/`hairColor_` into the appearance's `skinColor_`/`eyeColor_`/`hairColor_` |
| `CharacterCreation::names_`, `nameFlags_` (jpn) | `nameA_`/`nameB_`, `nameEndA_`/`nameEndB_` | same | Header `names[2][11]`, `nameFlags[2]` (the bytes right after the names, which the jpn `HandleNameEntry` reads per sex); here each is set to text `SetupText_BlankName` and 0 |
| `PartyMemberAppearance::body_`, `legs_`, `feet_`, `weapon_` | `unk_0`, `unk_2`, `unk_a`, `unk_e` | same | `models_[0]`, `[1]`, `[5]`, `[7]`. `CopyAndClampShorts_021e5fdc` sends them to parts 0, 1, 6 and 8, and the logged load order put `d_b`, `d_p` and `d_r` files on parts 0, 1 and 6. `CharacterModel_Load` uses part 8's item as the weapon in the animation file name. The ids written are body clothes, slacks/stockings, footwear and one weapon per vocation (ROM descriptions above) |
| `PartyMemberAppearance::defaultArms_` | `unk_16` | same | `CopyAndClampShorts_021e5fdc`: part 5 = `models_[4]`, else this, else 8010. Part 5 loads `d_a###` files (logged: `d_a008` after `d_b008`), and `CharacterModel_Load` takes part 5's number from the body when `models_[4]` is empty or 8010. "Arms" is read from the `a` file letter and that tie to the body; not seen on screen |
| `PartyMemberAppearance::face_`, `hairStyle_`, `female_`, `skinColor_`, `eyeColor_`, `hairColor_`, `width_`, `height_` | `unk_4`, `unk_6`, `sex_`, `unk_14_1_`, `unk_14_4_`, `unk_15_0_`, `unk_18`, `unk_1a` | same | As in `CharacterCreationUI_ApplyChoice` (decided) |
| `PartyMemberData::appearance_`, `vocation_` | `look_`, `unk_568` | same | As in `CharacterModel_Load`, which falls back to `vocation_` when its argument is negative |
| `BackgroundGraphics::subScreen_`, `bgNumber_`, `screenCount_` | `unk_1c_0_`, `unk_1c_4_`, `unk_1d` | same | Written from `CharacterCreationUI_setupBgSubScreen`/`_setupBgNumbers`. `Background_TransferMap` and `func_0204b5b4` index their per-engine × BG tables with the two nibbles (the priority table holds `SetBg0..3Priority` and `SetSubBg0..3Priority`). `DispatchEntry0204b8d0` returns when `+0x1d <= screen` (CODE). `Background_TransferMap`'s `source`/`destination` names for the nibbles are wrong |
| `Window::layers_`, `panes_`, `layerCount_`, `paneCount_` | `background_`, (pad), `unk_b2`, (pad) | same | `+0x98`, `+0x9c`, `+0xb2`, `+0xb3`, as `Window_ClearLayers` and `Window_DrawPanes` (decided) use them and `LinkArrayPrevPointers0205cf78` sets them. Header calls them `tileMaps`/`elements`/`tileMapCount`/`capacity` |
| `WindowPane::previous_`, `layer_`, `windowBuffer_`, `buffer_` | (pad), `background_`, (pad), (pad) | same | `+0`: `LinkArrayPrevPointers0205cf78` links each pane to the one before. `+4`: set here to the window's layer. `+8`/`+0xd4`: `AllocateBuffer0204c7a8` stores the window's shared buffer and allocates the pane's own buffer |
| `SpriteContext::spriteEntries_`, `sprites_`, `spriteCount_`, `subScreen_` | `tail_`, `entries_`, `entryCount_`, `unk_50` | same | `+0x3c`, `+0x40`, `+0x4c`, `+0x50`. `subScreen` is the name in `SpriteAffineTransform.h`, and `InitStruct0205a444` defaults it to 1 |
| `Keyboard::layout_`, `KeyboardKey::disabled_` | `Ov3Obj::unk_4`, `node[0xf]` | same | As in `CharacterCreationUI_HandleNameEntry` (decided `KeyboardKey::disabled_`, set on the space bar). `func_ov003_0215f4fc` searches `keyboard+4`'s key list by label |
| `MessageSystem::textBuffer_` | raw `+0x5c` (jpn `+0x28`) | same | The overlay 17 copies call the same offset `TextBufferPointer` / `kTextBufferOffset` / `TextBufferOffset` (usa 0x5c, jpn 0x28). Character creation borrows it as `textBuffer` (cleared 0x960 / 0x800 bytes by `SetupTag021d9c7c`). In `include/Resource/MessageSystem.h` it is inside `pad54` (jpn `pad28`); that header's own `textBuffer` is a different field (`+0x48`) |
| `Scene::unk_124` | `unk_0` | same | **Placeholder (matching trick).** Pad so that `(Scene*)((char*)self + 0x124)` reaches `camera_` at `+0x924`; jpn uses `self` directly |
| `CharacterCreation::layers_`, `resourceTask_`, `resourceStep_` | `backgrounds_`, `task_`, `loadStep_` | `CharacterCreationUI_ApplyTabGraphics` (both region structs) | The header's names for `+0x138`/`+0xd90`/`+0xd94` (jpn `+0xfc`/`+0xd54`/`+0xd58`) |
| `CharacterCreation::nameTabFlushPass_` | `unk_db6` (usa), `unk_d8f` (jpn) | same | The header's name for usa `+0xdb6`. jpn `+0xd8f` is the same flag: the jpn code toggles it on `CreationTab_NameEntry`, flushes (`DispatchByTag0204b2e0`) while it is 1 and returns, and uploads when it is 0. The header has no jpn field at `+0xd8f` yet (its jpn layout ends at `previousKeyboardPage`, `+0xd8e`) |
| `BackgroundGraphics::screens_` | inside `unk_0[0x1c]` | same | `+0x10`: `AllocateArray0204af38` allocates `count × 0x10` there. `GetEntryByIndexStride0x10` returns `+0x10 + index × 0x10`, and `func_0204b174` stores each SCRN at `f10 + index × 0x10`. The header calls it `entries` |
| `BackgroundGraphics::map_` | inside `unk_0[0x1c]` | same | `+0x14`: allocated and cleared by `AllocateAndClearBuffer0204b12c`, filled by `func_0204bc74` (32 shorts a row), the destination of `DispatchEntry0204b8d0`'s copy, flushed and transferred by `FlushAndDispatchList0204b0e8`. NAMING.md's `Background_ClearMap` calls it the map buffer. The header calls it `buffer` |
| `BackgroundGraphics::mapSize_`, `mapType_` | inside `unk_0[0x1c]`, `unk_1e[2]` | same | `+0x18` and `+0x1f`: `AllocateAndClearBuffer0204b12c` sizes the map as `data_020e7b98[+0x1f][+0x18]`. Row 0 holds text sizes (0x800–0x2000) and row 1 affine sizes (0x200–0x8000, 8 bpp 128–1024 px) (ROM). `SetWord0x18ClearByte0x1f_0204b11c` sets the size and clears the type. The header calls them `sizeIndex` / `sizeTable` |
| `BackgroundGraphics::subScreen_`, `bgNumber_` | `unk_1c_0_`, `unk_1c_4_` | same | The `+0x1c` nibbles index the BG function tables `[subScreen][bg]` (ROM: `data_020f01d8[0][0]` = `SetBg0Priority`, `[1][3]` = `SetSubBg3Priority`; `data_020f01b8[0][0]` = `SetMainBG0Scroll`). The finish layers (main screen) get 0 and the tab layers (sub screen) 1, with BG numbers from `finishBgNumbers`/`tabBgNumbers`. The names match `CharacterCreationUI_setupBgSubScreen` / `_setupBgNumbers` |
| `BackgroundGraphics::screenCount_` | `unk_1d` | same | `+0x1d`, screens loaded: `func_0204b174` increments it per SCRN, and `GetEntryByIndexStride0x10` and `DispatchEntry0204b8d0` bound the screen index by it. Here: redraw the panel only if the selection layer has screens, and draw a language text only if the page has 5. The header calls it `entryCount` |
| `BackgroundGraphics::screenCapacity_` | `unk_1e[2]` (first byte) | same | `+0x1e`: `AllocateArray0204af38` stores the count it allocated for, and `func_0204b174` stops storing screens at it (`limit`) |
| `BackgroundScreen::width_`, `height_`, `tiles_` | `unk_0[0xc]`, `unk_c` | same | As `func_0204b620` reads its `TileSource0204b620` source (width, height, tiles at `+0xc`). Here `tiles_` is the copy's destination (a keyboard page) |
| `CharacterCreationUI::navigation`, `grid`, `cursorX`…`cursorHeight`, `lastCursorX`, `lastCursorY`, `state`, `characterData`, `touchedChoice`, `flags`, `furthestState`, `sex`, `bodyType`, `faceStyle`, `eyeColor`, `skinColor`, `hairStyle`, `hairColor`, `savedKey`, `keyboard`, `keyboardResult` (usa) | usa half's `controls.navigation`, `grid`, `lastX`, `lastY`, `member`, `maxSteps`, `gender`, `body`, `face`, `eyes`, `skin`, `hair`, `savedEntries`, `list`, `blocked` | `CharacterCreationUI_HandleInput` | The header's names at the same offsets. `blocked` (`+0xdb5`) is `keyboardResult`: Up leaves the keyboard for the tab icons only when `Keyboard_Update` did nothing this frame (`KeyboardResult_None`). `savedEntries`/`list->entries` are `savedKey`/`keyboard->key_`: the key is hidden while the cursor is on the tab icons and restored on Down |
| `CreationNavigation::pageCount`, `wrapRows`, `wrapColumns`, `row` (uses) | `field4`, `field3d`/`flags3d`, `field3c`/`flags3c`, usa `selection` | same, both halves | Header names (the jpn half no longer compiled after the header rename; fixed here) |
| `CharacterCreation::navigation`, `cursorX`, `cursorY`, `cursorWidth`, `cursorHeight`, `lastCursorX`, `lastCursorY` | `cursor[12]` + `cursorMode`, `selectionX`, `selectionY`, `selectionWidth`, `selectionHeight`, `unknownc54[4]` | `CharacterCreationUI_GetTouchedInput` | The header's names at the same offsets; `cursorMode` (`+0xbf8`) is `navigation.rows` |
| `PartyMemberAppearance::face`, `hairStyle`, `unknown0`, `unknown8`, `unknown15`, `unknown16` | `models[2]`, `models[3]`, `models[0..1]`, `models[4..9]`, `unused`, `field16` | `CharacterCreationUI_HandleInput` (both halves) | `face`/`hairStyle` as decided (`PartyMemberAppearance::face_`, `hairStyle_` in `ApplyChoice`; this file uses no `_` suffix). The others are unknown: not touched here (`unused` claimed a meaning there was no evidence for) |
| `NameFilter::reservedNames`, `patterns`, `reservedNamesData`, `reservedNamesSize` | `container_`, `file_`, `secondFile_`, `secondFileSize_` (CheckName); `field_0[0x2a]` (MatchPattern) | `CharacterCreationUI_CheckName`, `NameFilter_MatchPattern` | The names `NameFilter_Reset` already uses: res.nat's key table (reset by `ResetStruct020dfc40`, loaded by `ApplyNodeUpdater020e038c`), tv.nat's `ForbiddenWordFile`, and res.nat's data pointer and size (set from `fileSizes[NameFilterFile_ReservedNames]`) |
| `NameFilter::letterClassId`, `groupStartId`, `groupEndId`, `repeatStartId`, `repeatEndId`, `negateId`, `rangeId`, `wildcardId` | CheckName `pad2a[4]`, `closeBraceId_`, `caretId_`, `hyphenId_`, `dotId_`; MatchPattern `digit`, `groupStart`, `groupEnd`, `repeatStart`, `repeatEnd`, `negate`, `range`, `wildcard` | same | `syntaxIds[0..7]` (`+0x2a`..`+0x31`): font-1 indexes of `:` `[` `]` `{` `}` `^` `-` `.` (`NameFilter_syntaxCharacters` order, filled by `NameFilter_Reset`), named by what `NameFilter_MatchPattern` does with each. `digit` was wrong: `:` accepts tokens 18–43 = `A`–`Z` (ROM) |
| `NameFilter::dollarId`, `slashId`, `atId`, `ampersandId`, `commaId`, `cSlashId`, `apostropheId` | `dollarId_`, `slashId_`, `atId_`, `ampersandId_`, `commaId_`, `controlCId_`, `apostropheId_` | `CharacterCreationUI_CheckName` | `syntaxIds[8..14]`: font-1 indexes of `$` `/` `@` `&` `,` `<c/>` `'` (`NameFilter_syntaxCharacters`). `cSlashId`: its character's text is `<c/>`, not a control code (ROM); CheckName writes `NameFilter_cSlashText` (`"C"`) for it |
| `NameFilter::pad39` | `pad35` | `CharacterCreationUI_CheckName` | Tail padding at `+0x39` (the struct is 0x3c) |
| `CharacterCreation::nameFilter_`, `furthestState_`, `vocation_`, `bodyType_` … `hairColor_`, `nameFill_`, `keyboardResult_`, `nameTabFlushPass_` | `syntax_`, `pada0[3]`, `pada4[0xc]`, `padb4[4]` | `CharacterCreationUI_CheckName` | The header's names for `+0xfc`, `+0xda0`..`+0xda2`, `+0xda4`..`+0xdaf`, `+0xdb4`..`+0xdb6` (`include/Resource/CharacterCreationUI.h`) |
| `ForbiddenWordPattern::matchTypes_` | `types_` | `CharacterCreationUI_CheckName` | One `ForbiddenWordMatch` per word (the switch) |
| `ForbiddenWordPattern::pad1f` | `unk_1f` | same | Never read; 0 in all 1302 tv.nat patterns (ROM) |
| `ForbiddenWordHeader::textSize_` | `unused_` | same | Bits 12–30: the bytes of text after the records. tv.nat 10815 = file size − texts offset; res.nat 170 (ROM) |
| `Header020e0424::textSize_`, `relocated_` | `rest_ : 20` | same | The same header on a key table: res.nat's bits 12–30 are 170 (ROM); bit 31 is what `func_020e0280` (`InitContainerFromSource_020e0280.cpp`) tests to skip relocating and then sets in both the table and the file |
| `FontCharacter::byteLength_` | `length_` | same | Bits 0–5 of `+5`: the bytes of the character's text (`Font_FindCharacter` compares that many; `` <`A> `` is 4). The header `MessageGlyphSlot.h` calls it `byteLength` |
| `FontCharacter::lowercase_` | `uppercase_` | same | Bit 7 of `+5`: set on exactly `a`–`z` (44–69), `<oe>` (83) and the lowercase accented letters 146–169 of font 1 (ROM); CheckName uppercases those characters' texts. `include/Resource/MessageGlyphSlot.h`, `CopyTextAndUppercaseIfFlagged0206819c`, `func_02045d14` and overlay 12 call the same bit `uppercase` (= "uppercase this one"), which reads as the opposite |
| `FontCharacter::width_` | `unk_4` | same | The decided name (`FontCharacter` in `CharacterCreationUI_HandleNameEntry`) |
| `NameSpan::joinedToNext_` | `adjacent_` | same | 1 unless a comma token lies between this span and the next: set by the token loop (space = 1, comma = 0), then recomputed for every pair by the gap loop. A multi-word pattern needs it on every word's span but the last (code) |
| `NameSpan::open_` | `active_` | same | The token loop has started this span and not yet ended it (code) |
| `KeyTableEntry::key_`, `text_` | (`DictionaryPair` fields, same names) | same | See the type |
| `Struct020dfc40::loaderTask_` | `currentText_` | same | `+0x10`: `ResetStruct020dfc40` sets it to -1; `ResetHandleState020dfe88` removes it from the `BackgroundLoader` when ≥ 0 (`handle`). Not read in CheckName |
| Current name | In | What it is | Suggested |
| `CharacterCreation::keyboard`, `itemTable`, `layers`, `windows`, `characterData`, `furthestState`, `sex`, `eyeColor`, `windowInput` | `script`, `equipmentContainer`, `display` (= `layers[4]` + `[5]` + `windows[0]`), `entryList` (= `windows[1]`), `character`, `field_da0`, `selectedIndex`, `selections` | `CharacterCreationUI_HandleConfirm` | The header's names at the same offsets (usa `+0xc0`, `+0xc8`, `+0x138`, `+0x1f8`, `+0xd88`, `+0xda0`, `+0xda3`, `+0xda8`, `+0xd85`; jpn has no keyboard and is −0x20 / −0x3c). `selections[selectedIndex]` is `eyeColor[sex]`, as `data_ov009_0218a9b4`'s row says |
| `layers[4]` (use) | `display` | same | The panel layer `CharacterCreationUI_DrawTabLayers` redraws on `CreationFlag_RedrawPanel`: on tab 9 the message box (entry 0/1 at (0, 14, 32, 10)) and the Yes/No frame (entry 2 at (24, 9, 8, 7)). Accept and Decline clear it. (The `CreationFlag_RedrawPanel` row says "tile map 3": that is the old `tileMaps[3]` = `layers[4]`) |
| `PartyMemberData::appearance`, `equipment[11]`, `levels[13]`, `unk_56a` | `equipmentKeys`, `equipment[7]`, `levels[20]`, `appearance` | same | `+0x488` (models looked up per `equipmentFromAppearance`), `+0x194` (11 item records: `func_02083e28` walks `records[11]` there; slots up to 9 are written here), `+0x16c` (13 shorts; `func_020830cc` copies 13, then 13 bytes from `+0x186`), `+0x56a` (unknown: was `appearance`, which clashes with `+0x488`; `CharacterModel_Load` already calls it `unk_56a`) |
| `PartyMemberData::unk_6c`, `unk_6e`, `unk_70`, `unk_72` | `health`, `mana`, `field_70`, `field_72` | same | Back to placeholders: no evidence for the old names (see Placeholders) |
| `CharacterCreation::wingsVramState_`, `finishEffectVramState_`, `waitTimer_`, `dimTimer_`, `characterData_`, `furthestState_`, `windowInput_` | `unk_808`, `unk_c68`, `timer_`, `unk_d98`, `member_`, `lastStates_`, `unk_d85` | `CharacterCreationUI_HandleNewGameFinish` | The header's names at the same offsets (`+0x808`, `+0xc68`, `+0xd96`, `+0xd98`, `+0xd88`, `+0xda0`, `+0xd85`) |
| `FinishModelFile::taskSlot_` | `model_` | same | Which `modelTasks_` entry the file's task goes in (0, 1, 2 in the ROM data) |

### Locals

| Name | Original | In |
|---|---|---|
| `currentLayout` | `out` | `CharacterCreationUI_LoadSlotLayout` |
| `nameChecked` | `checked` | `CharacterCreationUI_HandleNameEntry` |
| `widest` | `info` | `CharacterCreationUI_HandleNameEntry` |
| `okKey` | `key` | `CharacterCreationUI_HandleNameEntry` |
| `navigation` | `cursor` | `CharacterCreationUI_HandleNameEntry` (inside `RESET_KEYBOARD_NAVIGATION`) |
| `sex`, `choice`, `tab`, `furthestState` | `idx`/`idx2`, `val`, `v`, `arr` | the choice tab handlers (body type, hair style, hair colour, skin colour, face) |
| `leavingTab`, `furthestTab`, `currentTab` | `flag`/`changed`, `arrv`, `cur` | `CharacterCreationUI_HandleFace`, `_HandleEyeColor`: set exactly when `SwitchTab` is called, which eases the camera back |
| `tab`, `newTab` | `state`, `selectedState` | `CharacterCreationUI_SwitchTab`, `_LoadTabGraphics` |
| `tab`, `slot`, `sex`, `layout` | `id`/`type`, `choice`/`index`, `sel`, `s` | `CharacterCreationUI_SetupSlotNavigation`, `_MoveCursorToSlot`, `_SlotToStyleIndex`, `_ResetTargetLayout` |
| `names`, `name`, `pick`, `firstText`, `textId`, `text`, `count` | `arr`, `entry`, `rem`, `t`, `val`, `result`, `range` | `CharacterCreationUI_PickRandomName` |
| `layers`, `layer`, `allocators`, `messageSystem` | `arr`, `p`, `arr2`, `g` | `CharacterCreationUI_Destroy` (now reads the header's fields instead of raw offsets) |
| `self`, `word`, `text`, `length`; `members`, `memberCount`, `token` | `unused`, `val`, `key`, `field5`; `buf`, `count`, `target` | `NameFilter_FindWord`; `NameFilter_GroupContains` (types kept as declared, so the symbols don't change) |
| `tab`, `reached` | `state` | `CharacterCreationUI_HandleGenderSelection`, step 3's tab icon block |
| `tab` | `characterCreationStep` (before that `state`) | `CharacterCreationUI_ApplyChoice` (both halves): `self->state`, compared with `CreationTab` values |
| `headerLength`, `gameState` | `offset`, `gs` | `CharacterCreationUI_HandleSetup` |
| `textFile`, `textFileSize` | `data`, `size` (step Init) | same |
| `itemData`, `itemDataSize` | `list`, `listSize` | same |
| `characterModel0`, `characterModel1` (macros `CHARACTER_MODEL0`/`1`) | `model0`, `model1` (`MODEL0`/`1`) | same |
| `mainSpriteContext`, `subSpriteContext` (macros `MAIN_SPRITE_CONTEXT`/`SUB_SPRITE_CONTEXT`) | `table`, `tableB` (`TABLE_A`/`TABLE_B`) | same |
| `textureBytes`, `paletteBytes` | `pairSize`, `pairAlign` | same |
| `characterArchive`, `characterArchiveRef`, `decompressedLength`, `buffer`, `capacity` | `pair`, `rp`, `length`, `buf`, `room` | same (`capacity` now starts at `sizeof(data_0211e33c)`; same constant) |
| `appearanceModels`, `setupLayers`, `appearance`, `layer`, `subScreen` | `defaults`, `backgrounds`, `look`, `background`, `lo` | same |
| `eyeColor`, `hairColor`, `face`, `hairStyle` | `hair`, `eyes`, `top`, `bottom` | same: they hold `eyeColor_[sex]`, `hairColor_[sex]` and the face and hair style model ids (the old names were wrong) |
| `order`, `remaining`, `src`, `dst`, `style` | `ids`, `n`, `s`, `d`, `v` | same: the two dead copies of `CharacterCreationUI_styleOrder`, kept for matching |
| `tab`, `innerFile` | `state`, `inner` | same |
| `record`, `fileSize`, `fileCount` | `name`, `size`, `count` (steps LoadBackgrounds, LoadSprites) | same: `FindRecordByIndex` stores the record's header (its file name) and returns the data and its size |
| `backdropScreen`, `pane`, `window0PaneSize` | `visible`, `canvas`, `bufferSize` | same |
| `keyboardFile`, `keyboardFileSize`, `spaceKey` | `data`, `size`, `node` | same |
| `tab` (usa) | `state` | `CharacterCreationUI_ApplyTabGraphics` |
| `layers`, `layer` | `backgrounds`, `background` | same |
| `record`, `fileCount`, `file`, `fileSize` | `name`, `count`, `file`, `size` | same (`record` receives `FindRecordByIndex`'s record header pointer, whose first `0x40` bytes are the file name; `fileSize` is the record's data size, `+0x44`) |
| `screenCount`, `row` | `screen`, `j` | same (the layer's count from `CharacterCreationUI_tabScreenCounts`, and the row offset in it) |
| `pageScreenCount`, `pageFileCount` | `first`, `firstEnd` | same (the page layer's screen count, and its files: its CHAR then its screens) |
| `pageFileCountBothModes` (jpn) | `pairEnd` | same (jpn's name tab takes `pageScreenCount × 2 + 1` files for the page: the CHAR, then a set party creation keeps (`i < pageFileCount`), then a set new game keeps (`i >= pageFileCount`, plus file 0). Which set is the npc one is not checked: no jpn ROM) |
| `lastFile` (usa) | `last` | same (the archive's last file. On the name tab that is `cm_name_que.bnsc`, which is stored as page screen 4 but never flushed or uploaded) |
| `paletteIndex` (usa) | `palette` | same (counts PALT files, indexes `CharacterCreationUI_paletteSkipModes`) |
| `tag` | `type` (`char[5]`) | same |
| `pageScreen` | `unk` | same |
| `queScreen`, `keyboardPage`, `unusedLayer` (usa) | `palettes`, `part`, `graphics` | same (`unusedLayer` is passed as `func_0204b620`'s first parameter, which that function never reads) |
| `language`, `languageScreen` (usa) | `type` (int), `unk2` | same |
| `input` | `result` | `CharacterCreationUI_HandleInput` (both halves): the `CreationInput` it returns |
| `touchX`, `touchY` | `x`, `y` | same: the touch point, as `GetTouchedInput`'s parameters name it |
| `previousRow` | `previous` | same: `navigation.row` before `func_0205bf58` moves it; Up from row 0 goes to the tab icons |
| `cellCount` | `count` | same: `GetField0_0205bafc(&navigation)`, the navigation's cell count |
| `sexChoice`, `choices`, `sex`, `previousChoice` | `genderValue`, `values`, `gender`, `prior` | same (usa half's choice store) |
| `navigation` | `controls` (usa) | same, inside `RESET_NAVIGATION` (usa now matches jpn's) |
| `self`, `slot`, `icon`, `layout`, `navigationRows`, `navigationCount`, `selectedSlot` | `menu`, `selected`, `i`, `grid`, `cursorMode`, `count`, `index` | `CharacterCreationUI_GetTouchedInput` |
| `spans`, `normalizedName`, `nameTokens`, `wordTokens`, `upperName`, `upperCharacter`, `normalizedCharacter`, `fileSizes` | `work_spans_`, `work_normalized_`, `work_tokens_`, `work_patterns_`, `work_exactName_`, `work_exactCharacter_`, `work_character_`, `work_fileSize_` | `CharacterCreationUI_CheckName` |
| `reservedNamesOffset`, `patternsFile`, `patternsOffset`, `patternsSize`, `patterns` | `aligned`, `buffer`, `firstOffset`, `bytes`, `file_v` | same (loading) |
| `relocating`, `relocateCount`, `relocate` | `headerPattern`, `headerCount`, `callback` | same (`relocate` only exists to match: the loop calls the function directly) |
| `rejected`, `isReservedName`, `nameLength`, `reservedIndex`, `reservedCount`, `reservedName`, `reservedLength` | `forbidden`, `exact`, `length`, `exactIndex`, `count`, `forbidden` (`char*`), `forbiddenLength` | same (reserved names) |
| `character`, `byteLength`, `typedLength`, `letter`, `cSlashId` | `entry`, `length`, `advance` / `length`, `c`, `controlCId` | same (normalising) |
| `token`, `cursor`, `gapToken`, `firstSpan`, `firstSpanCount`, `wordSpan`, `tokens`, `wordCount`, `lastWord`, `match`, `wordLength`, `offsetCount`, `word` | `c`, `token`, `p`, `first`, `positions`, `matchSpan`, `input`, `count`, `last`, `type`, `length`, `positions`, `text` | same (spans and matching) |
| `sharedIndex` | `matchIndex` | same: one variable for three things (the position within a 19-token chunk, the next span's start in the gap loop, the word index while matching). Splitting it into three locals, in any declaration order or as references, changes the code, so it stays one, with a comment |
| labels `reservedChecked`, `patternChecked`, `other_character` | `exact_done`, `match_done`, `fallback_character` | same |
| `self`, `length`, `letterClassId`, `groupStartId`, `groupEndId`, `repeatStartId`, `repeatEndId`, `wildcardId` | `syntax`, `unused`, `digit`, `groupStart`, `groupEnd`, `repeatStart`, `repeatEnd`, `wildcard` | `NameFilter_MatchPattern` (`length`: CheckName passes the word length; unused here) |
| `patternToken`, `textToken`, `minRepeat`, `maxRepeat`, `memberCount`, `groupKind`, `member`, `endId`, `negateId`, `rangeId`, `repeat` | `code`, `current`, `minimum`, `maximum`, `length`, `hasRange`, `value`, `end`, `negate`, `range`, `matched` | same. `memberCount` first holds `GroupKind_Negated` (0 or 2) until the members are counted: one variable in the original, and a separate `negated` local changes the code |
| `self`, `gameState` | `menu`, `game` | `CharacterCreationUI_HandleConfirm` |
| `declined`, `touched`, `pressedA`, `pressedX` | `cancel`, `active`, `confirm`, `alternate` | same (`touched`: `IsActiveElementFlag2Set0205da38` → `CheckActive0205bd20` needs `g_touchInput.pressed_`) |
| `member` | `character` | same (`characterData`) |
| `memberVocation` | `characterVocation` | same (the `%d` of `CharacterCreationUI_levelFileFormat`) |
| `levelStats` | `record` | same (`func_02082490` runs `level<vocation>.bin` with the member's level as the selection) |
| `models` | `keys` | same (`appearance.models`) |
| `loadContext`, `spellTable`, `spells` | `scriptContext`, `script`, `abilities` | same (`SetupAndRunBufferedScript0209a810`'s context, the spell table, the vocation's row) |
| `firstKey` | `script` | same, usa (the key labelled `CharacterCreationUI_firstKeyText`, "1") |
| `body`, `globalFlags` | `preview`, `unknown` | `CharacterCreationUI_HandleNewGameFinish` (`CharacterModel_GetBody(character_)`; the global word `data_02114e04` that `OrBitsIntoField0`/`ClearFlags` set and clear bit `0x100` of) |
| `wingsKey`, `bodyPackageKey` | `bodyID`, `headID` | same (see `FinishText`) |
| `allLoaded` | `done` | same |
| `wings`, `finishEffect` | `object`, `object2` | same, usa body |

## Placeholders

### Role known

| Current name | Overlay | USA | What it does | Suggested |
|---|---|---|---|---|
| `func_ov023_021e447c` | 23 | `0x021e447c` | Swaps another screen's pair of preview models; the screen is unknown | |
| sound effect 5 | Main | (`SePlayer_Play`'s effect) | Logged in-game: `CharacterCreationUI_HandleConfirm` plays it once as the "Begin your adventure with this character?" Yes/No prompt opens; overlays 4, 6, 12 and 13 play it too. What it sounds like isn't confirmed | |
| creation flag `0x4000` | 9 | (a bit of `CharacterCreationUI::flags`) | Set when a choice changes (`CharacterCreationUI_HandleInput`) and when a tab's graphics are applied; `RefreshFieldIfFlag4000_021d9d34` then writes text `0x4274` (just `<W=10>` in usa) into `windows[1]` pane 2 and clears it. What pane 2 shows is unknown | |

### Data

| Current name | Overlay | USA | What it is | Suggested |
|---|---|---|---|---|

### Fields

| Current name | In | What it is | Suggested |
|---|---|---|---|
| `Object3D::unknown_2_` | `include/World/Object3D.h` | ID of the model loaded in this part; -1 means none | `loadedModelId_` |
| `CharacterCreationUI::grid` | `include/Resource/CharacterCreationUI.h` | The current tab's `CreationSlotLayout` | `slotLayout` |
| `CharacterCreationUI::character` / `nextCharacter` | `include/Resource/CharacterCreationUI.h` | The visible and hidden preview models; typed `void*` until a shared `CharacterModel` type exists | |

### Overlay 9: still open after the per-file passes

#### CharacterCreationUI_ApplyTabGraphics

*Placeholders left*


| Current name | In | What is known / missing |
|---|---|---|
| creation flag `0x4000` | `CharacterCreationUI::flags` | This function sets it around `RefreshFieldIfFlag4000_021d9d34`, which writes text `0x4274` (`<W=10>` in usa `str_cm_en`) into `windows[1]` pane 2 and clears it. What pane 2 is needs an in-game look. It already has a "Role known" row |
| `BackgroundGraphics::unk_0[0x10]` | file-local | `ResetList0204af64` clears `+0`–`+0xb` (`ClearStruct0204a82c`), sets `+0xc` = 0 and `+0xe` = `0xffff`. PALT files go to `+0xc` (`func_0204aa64`). The layout is not worked out |
| `BackgroundScreen::unk_4[8]` | file-local | Not read by any callee seen |
| `resourceTask_ = -1` | | "no task". `BackgroundLoader.h` has no constant for a task id of -1 (`TaskStatus_Invalid` is a status, not an id) |

#### CharacterCreationUI_HandleInput and _GetTouchedInput

*Placeholders (unchanged, with what is known)*


| Current name | What it does | Suggested |
|---|---|---|
| `GetField0_0205bafc` | Returns `+0x0` of the cursor, `CreationNavigation::count` (`GetField0_0205bafc.cpp`) | `GridCursor_GetCount` |
| `func_0205bf58` | The GridCursor's per-frame D-pad step: a new Up/Down/Left/Right press moves row/column (wrapping per `wrapRows`/`wrapColumns`, paging), a held one repeats after `initialDelay` then every `repeatDelay`; returns 1 while a direction is pressed or repeating, and only then does `HandleInput` read the selected index | `GridCursor_Update` |
| `func_02001aec` | MSL `memcmp` (`src/MSL/Main/CompareByteBuffers.cpp`: byte compare returning -1/1/0) | `memcmp` |
| `func_ov009_0218aab0` (jpn) | Presses the jpn keyboard key at a cell: reads the 2-byte character at `choice` from text `0x4268 + keyboardPage`; OK sets `CreationFlag_KeyboardOk`, delete calls `0218b200`, two page keys, two others call `0218b2e8`/`0218b680`, random name (mode 1); otherwise appends it. Returns 1 when a character was typed (`ApplyNameKeyboardChoice_0218aab0.cpp`) | `CharacterCreationUI_PressNameKey` |
| `func_ov009_0218b200` (jpn) | Called with 0 on B when the name isn't empty, and by the delete key in `0218aab0` (which then refreshes from index `nameFlags[sex]`). Body is asm; the `0` argument is unknown | `CharacterCreationUI_DeleteNameCharacter` (LIVE check on jpn: B removes the last kana) |
| `func_ov009_0218b850` (jpn) | jpn body of the random name: empty-name text, then text `0x4e20 + sex × 1000 + rand() % 101`, `nameFlags = length / 2` (`SelectRandomName_0218b850.cpp`); `HandleInput` calls it on SELECT, as usa's `HandleNameEntry` calls `CharacterCreationUI_PickRandomName` | `CharacterCreationUI_PickRandomName` (jpn) |
| `func_ov009_0218ad0c` (jpn) | Called on START and when A pressed the OK key, where usa calls `CharacterCreationUI_CheckName`; a different 0x444-byte asm body | probably jpn's `CharacterCreationUI_CheckName`; needs a jpn run |
| `CharacterCreationUI::nameFlags` (jpn, header) | The name's length in 2-byte characters: `0218b850` sets it to `length / 2`, `0218aab0` writes the next character at it and caps it at 5 | `nameLength` |
| creation flag `0x4000` | Unchanged: still a bare number (purpose unknown) | |
| `Struct_0205bef8`, `Struct_0205ba68`, `Struct_0205bb84`, `Node0205bacc` | The GridCursor as the mangled signatures of `GridCursor_Init`, `_SetDimensions`, `_GetSelectedIndex`, `_SetCount` spell it; renaming changes the symbols | `GridCursor` (with the symbol renames) |
| `0` argument of `func_ov009_0218b200` | Unknown | |

#### CharacterCreationUI_CheckName and NameFilter_MatchPattern

*Placeholders*


*Role known (callees and data outside these files; not renamed here)*


| Current name | Overlay | USA | What it does | Suggested |
|---|---|---|---|---|
| `func_020426bc` | Main | `0x020426bc` | `TokenizeAndEncode_020426bc.cpp`: writes one byte per character of a string (stepping by `byteLength`): its font-N index, 0xff for `' '`, 0 if not found or index 0; then a 0; returns the character count. CheckName encodes the normalised name and each tv.nat word with it | `Font_EncodeText` |
| `GetBoundedEntry020425b4` | Main | `0x020425b4` | Entry `index` of font N's character table (`data_0210782c[N]`, count at `+4`, entries at `+0x10`, 8 bytes each), NULL when out of range; the same table `Font_FindCharacter` searches | `Font_GetCharacter` |
| `ResetStruct020dfc40` | Main | `0x020dfc40` | Clears a key table's header, entries and texts, sets `+0xc` and the loader task (`+0x10`) to -1 and removes a pending task (`ResetHandleState020dfe88`) | `KeyTable_Reset` (owner type still `Struct020dfc40`) |
| `ApplyNodeUpdater020e038c` | Main | `0x020e038c` | Loads a key table in place from file data (`func_020e0280`): header copied, entries at data + 4, texts after them; unless the relocated bit is set, turns each entry's text offset into a pointer and sets the bit in the table and the data. CheckName loads res.nat with it | `KeyTable_Load` |
| `GetLow12Bits020e0424` | Main | `0x020e0424` | A key table's entry count (header bits 0–11); 24 for res.nat (ROM) | `KeyTable_GetCount` |
| `Container020e0310` / `Header020e0424` / `Struct020dfc40` (types) | Main | | The key table (`KeyTable_Get` takes it), its `count:12 | textSize:19 | relocated:1` header, and the table plus its load state. Kept because the callees' C++ symbols are mangled with these names | `KeyTable`, `KeyTableHeader`, (unknown) |
| `func_02001aec` | Main | `0x02001aec` | `src/MSL/Main/CompareByteBuffers.cpp`: the MSL `memcmp` (used by `NameFilter_FindWord` and `Font_FindCharacter`, not here) | `memcmp` |

*Data*


| Current name | Overlay | USA | What it is | Suggested |
|---|---|---|---|---|
| `data_020f285c` | Main | `0x020f285c` | Pointer to `"data/bin/tv.nat"` (`0x020f2860`) (ROM); used by `CharacterCreationUI_CheckName` and overlay 12's checker `func_ov012_02184d80` | `NameFilter_patternsFilePath` |
| `data_020f2858` | Main | `0x020f2858` | Pointer to `"data/bin/res.nat"` (`0x020f2870`) (ROM); only `CharacterCreationUI_CheckName` | `NameFilter_reservedNamesFilePath` |
| `data_0211e33c` | Main | `0x0211e33c` (bss, 0x30000 bytes) | The shared file load buffer (117 source files; `LoadFileIntoMemory` frees the background loader's allocations before loading into it). CheckName loads tv.nat at its start and res.nat after it, and leaves the filter's pointers into it | `g_fileLoadBuffer` (needs its own pass) |


*Fields (placeholders)*

| Current name | In | What it is | Suggested |
|---|---|---|---|
| `FontCharacter::unknownBit6_` (was `unused_`) | `CharacterCreationUI_CheckName` | Bit 6 of `+5`. Set in font 1 on `A E I O U a e i o u`, the accented vowels, `<AE>`/`<ae>` and `<~n>` (160), but not `<~N>` (134), `<,C>`, `<x>`, `<ss>`, `<,c>`, `Y` (ROM). Never read here; the header calls it `reserved` | a vowel flag (e.g. for "a"/"an") would fit, but `<~n>` doesn't and no reader was found |
| `Struct020dfc40::unknownC_`, `unknownE_`, `unknown14_` (were `currentIndex_`, `mode_`, `allocator_`, guesses with no evidence) | same | `+0xc` short set to -1 by `ResetStruct020dfc40`; `+0xe` short and `+0x14` set to 0 by `ResetHandleState020dfe88`. Not read in CheckName | needs the key table's own pass |
| `NameSpanChunk_Length` (19) | same | See Constants. What the 19-token cut is for is unknown | check in overlay 12's message checker, where long text can reach it |

#### CharacterCreationUI_HandleConfirm and _HandleNewGameFinish

*Placeholders (role known)*


| Current name | Overlay | USA | What it does | Suggested |
|---|---|---|---|---|
| `func_ov003_0215f4fc` | 3 | `0x0215f4fc` | Returns the first key of `keyboard->layout` whose text starts with the given text (`func_02001aec` over `len` chars), or NULL; no reset | `Keyboard_FindKeyByText` |
| `func_ov023_021d9f88` | 23 | `0x021d9f88` | Sets `selection` 0 and `windows[1]` up as a 1 × 2 menu at the prompt's layout, writes its text (`func_ov023_021da100`). Confirm step 0 | `CharacterCreationUI_OpenYesNoWindow` |
| `func_ov023_021da100` | 23 | `0x021da100` | Writes the Yes/No menu's text: texts `0x465a + i` for i = 0, 1, with the cursor tag at `selection` | `CharacterCreationUI_WriteYesNoText` |
| `GetActiveScaledSum0205d794` | Main | `0x0205d794` | A window's selected item (`GridCursor_GetSelectedIndex` of `+0x54`, or the touched one), -1 when none; Confirm stores it in `selection` | `Window_GetSelectedIndex` |
| `IsActiveElementFlag2Set0205da38` | Main | `0x0205da38` | 1 while the stylus is down on the window's active item and that item's `+0xc5` has bit 2; its second argument (Confirm passes `0x14`) is not used | `Window_IsSelectionTouched` |
| `SetElementFieldC2_0205deb4` | Main | `0x0205deb4` | Sets the low nibble of `+0xc2` on a window's pane N. Confirm sets pane 3 to 2 on open and accept, to 0 when leaving; pane 2 to 0 on decline. What `+0xc2` controls is unknown (LIVE: watch `windows[1]` pane 3 `+0xc2`) | |
| `ResetEntryList0205d6a0` | Main | `0x0205d6a0` | Resets a window's pane list (1 pane, or all with a non-zero flag); Confirm calls it with 0 on Yes and No | `Window_Reset` (unconfirmed) |
| `func_0204bc74` | Main | `0x0204bc74` | Fills a rectangle of a 32 × 25 tile map with one tile and palette (`0xffff` = none) | `Background_FillRect` |
| `GetPtrField0x2a04_02010828` | Main | `0x02010828` | `gameState + 0x2a04` (jpn `0x27a4`): the list `func_02086778` appends the new member's entry to (first free id 0–15, 0x23c-byte entries at `+0xf80`) | `GameState::GetPartyList` (LIVE: what the list is in-game) |
| `func_02086404`, `func_020830cc`, `func_02086778`, `Snapshot0218742c` | Main | `0x02086404`, `0x020830cc`, `0x02086778` | Initialise a 0x23c-byte list entry, copy the member into it (vocation, levels, experience, `+0x56a`, name, ...), append it to the list | (LIVE) |
| `SetBit0x954StoreIndex0x950_02083ca0` | Main | `0x02083ca0` | Sets bit `vocation` of the member's `+0x954` (jpn `0x8bc`) and stores `vocation` at `+0x950` | `PartyMember_SetVocation` |
| `SetBitInArray0x910_02083b60` | Main | `0x02083b60` | Sets bit N of the member's `+0x910` (jpn `0x878`); Confirm passes spell ids from `spelltable.bin` | `PartyMember_LearnSpell` |
| `func_02083cbc` | Main | `0x02083cbc` | Copies a level entry's three packed triples (`initial.value8/C/10`) to the member's `+0x91c` and its 0x16 `variants` after them (default 100 each) | `PartyMember_ApplyLevelStats` |
| `func_02083e28(member, 0)`, `ResetAndCopyShorts0x1c_020863c4` | Main | `0x02083e28`, `0x020863c4` | Recomputes the member's stats from its items and level rows; then copies `+0x6c`/`+0x6e` into `+0x1c`/`+0x1e` and zeroes `+0x18` | (LIVE: read `+0x1c`, `+0x6c` on a new member) |
| `SetupAndRunBufferedScript0209a810`, `ClearField00209a804` | Main | `0x0209a810`, `0x0209a804` | Load `data/prm/spelltable.bin` and run it into a 0x550-byte table through a context (`data_02109ba8`); clear the context | `SpellTable_Load` |
| `func_ov023_021dac40` | 23 | `0x021dac40` (jpn `0x021db4b4`) | While `CreationFlag_DimBackground`: counts `dimTimer` down by the ticks; with `_DimWithQuad` fades a black full-screen 3D quad in (alpha 31 × elapsed / 90), else darkens main BLDCNT layers `0x16` to -16 over 90 | `CharacterCreationUI_UpdateDim` |
| `AnySubObjectField0NonZero_0202eeb4` | Main | `0x0202eeb4` | 1 while any of the camera's three eases (`+0x16c` position, `+0x194` target, `+0x1bc`) is running | `Camera_IsEasing` |
| `func_020c39a0` | Main | `0x020c39a0` (jpn `0x020c546c`) | Writes a master brightness register: 0, `level \| 0x4000` (towards white) or `-level \| 0x8000` (towards black); NitroSDK's `GXx_SetMasterBrightness_` | `GXx_SetMasterBrightness_` |
| `SetForwardAndStore0205ebc0`, `DispatchIfField0xc4NonNeg_0205ebfc`, `ForwardField0xc0_0205ebec` | Main | `0x0205ebc0`, `0x0205ebfc`, `0x0205ebec` | On `g_sePlayer`: release `+0xc0`, load bank N and keep its id in `+0xc4`; play effect N of that bank (as `SePlayer_Play` does with `+0xb4`); release it. The finish loads bank `0x6f`, plays its effects 0 and 1, releases it at the end (LIVE: log `func_0203ac40` in steps 1, 6, 7) | `SePlayer_LoadExtraBank`, `SePlayer_PlayExtra`, `SePlayer_UnloadExtraBank` |
| `DispatchContextByState0209c678(data_02109bf4, 120)` | Main | `0x0209c678` | On the player at `data_02109bf4` (ov006 starts track `0x3e` on it with `SetValueAndActivate0209c830`, so probably the music player): dispatches by its state with 120. Other callers pass 0, 10, 15 | (LIVE: does the music fade out over 120 frames at the start of the finish?) |
| `CopyInternalFields0207df50`, `RestorePairTables0207df90`, `BackupPairTables0207dfac` | Main | | Around `finishEffect_`'s load: put `finishEffectVramState_` into the texture/palette VRAM manager, load, save it back | |
| `GetDataPtr02114e04_020d6c00` | Main | `0x020d6c00` | Returns `&data_02114e04`, a game-wide flag word (set/cleared from overlays 6 and 17 too). The finish sets bit `0x100` from FadeToWhite to WaitBlack; Confirm calls it and drops the result. What `0x100` does is unknown (LIVE: `touches --reads` on `0x02114e04` during the white) | |
| sound bank `0x6f`, its effects 0 and 1 | | | Loaded at WaitTurn, effect 0 at PlaySound, effect 1 with the fade to white. What they sound like isn't confirmed | |

*Placeholders (data)*


| Current name | Overlay | USA | What it is | Suggested |
|---|---|---|---|---|
| `data_0211e33c` | Main | `0x0211e33c` | The 0x30000-byte load buffer (`include/Filesystem/FileIO.h`); Confirm loads `level<vocation>.bin` into it | `g_fileLoadBuffer` |
| `data_02109bf4` | Main | `0x02109bf4` | See `DispatchContextByState0209c678` above | (LIVE) |
| `CharacterCreationUI_secondModelAnimation` | 9 | `0x0218ad41` | `"0"`: the animation `finishEffect_` plays; the name predates `secondModel` → `finishEffect` | `CharacterCreationUI_finishEffectAnimation` |

*Placeholders (fields)*


| Current name | In | What it is | Suggested |
|---|---|---|---|
| `PartyMemberData::unk_6c`, `unk_6e`, `unk_70`, `unk_72` | `CharacterCreationUI_HandleConfirm` | After the level stats are applied `ResetAndCopyShorts0x1c` copies `+0x6c`/`+0x6e` into `+0x1c`/`+0x1e`; `func_02083e28`'s struct calls them `maxHp`, `maxMp`, `attack`, `defence` (unverified). Confirm copies them into the list entry's packed stats | `maxHp`, `maxMp` (LIVE: read them on a new member) |
| `PartyMemberData::stats[4]`, `Snapshot0218742c::stats[5]`, `PackedStats0218742c {first, second, third}` | same | 10-bit triples at `+0` and the entry's `+0x14c`; Confirm copies the member's into the entry's (with `+0x6c`… mixed in) | (LIVE) |
| `PartyMemberData::experience` | same | `+0x138`, 13 ints indexed by vocation; set to 0 with that vocation's level set to 1. Name kept: code-read only | (LIVE: read on a member with experience) |
| `PartyMemberData::unk_56a` | same | See `data_ov009_0218a9b4`; new game: `data_ov009_0218a9b4[eyeColor[sex]]`, party member: `rand(16)` | |
| `Object3D` at `body + 0x408` | `CharacterCreationUI_HandleNewGameFinish` | Part 6 of the character model (6 × 0xac); `finishEffect_` is placed at its position. Which part it is is unknown. (`body[6]` compiles differently, so the raw offset stays) | a `CharacterModelPart` value |
| `ObjectArchiveLoadInfo::unk_0` … `unk_18` | `include/World/Object3D.h` | Zeroed before each load | |
| `GetTaskStatus` results `0`, `1` | `include/Filesystem/BackgroundLoader.h` | 0 still loading, 1 loaded, -1 failed (its body) | an enum in the header |
| the `2` in Start's `previewAllocators_` reset loop | `CharacterCreationUI_HandleNewGameFinish` | Both preview allocators, which slots 0 and 1 then load into | |
| `layers[4]` | `CharacterCreationUI_HandleConfirm` (and the header) | The panel layer (sub BG1); a header enum would let the index read as a name | `CreationLayer_Panel = 4` in `CreationEnums.h` |
| `IsActiveElementFlag2Set0205da38`'s `0x14` | same | Ignored by the callee | |
| sound effect 5 (existing row) | same | Unchanged: still a bare 5 | |

### Role unknown

| Current name | Overlay | USA | Notes |
|---|---|---|---|
| `func_ov009_02185c58` | 9 | (jpn only, `0x02185c58`) | jpn name entry waits for it to return non-zero before reading input; jpn-only asm, not seen running |
| `func_ov009_0218ad0c` | 9 | (jpn only, `0x0218ad0c`) | jpn name entry calls it on Confirm, where usa calls `CharacterCreationUI_CheckName`, but it is a different 0x444-byte function; jpn-only asm |
