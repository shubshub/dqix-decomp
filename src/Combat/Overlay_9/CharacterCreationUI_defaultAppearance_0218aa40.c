// The PartyMemberAppearance::models_ CharacterCreationUI_HandleSetup starts from; it fills in the face [2]
// and hair style [3]. Originally CharacterCreationUI_defaultAppearance (USA/EUR 0x0218aa40, JPN 0x0218ba1c).
typedef struct AppearanceModels {
    short models[10];
} AppearanceModels;

const AppearanceModels CharacterCreationUI_defaultAppearance = {{-1, -1, 0, 0, -1, -1, -1, -1, -1, -1}};
