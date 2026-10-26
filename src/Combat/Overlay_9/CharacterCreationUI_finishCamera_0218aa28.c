// The default view moved to x = 0, for CharacterCreationUI_HandleNewGameFinish. Originally CharacterCreationUI_finishCameraPosition and CharacterCreationUI_finishCameraTarget (ZevyaDev/dqix-decomp#324;
// jpn 0x0218ba04, values assumed equal to usa).
typedef struct Vector3fix {
    int x;
    int y;
    int z;
} Vector3fix;

const Vector3fix CharacterCreationUI_finishCameraPosition = {0, 0xF800, 0x42CCC};
const Vector3fix CharacterCreationUI_finishCameraTarget = {0, 0xF800, 0};
