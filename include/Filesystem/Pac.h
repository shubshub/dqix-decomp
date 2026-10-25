#pragma once

// One file record of a .pac archive: the file's name, the size of this header (the file's data follows it), the
// data's size and the stride to the next record. A record with an empty name ends the archive (Pac_CountFiles,
// Pac_GetFile).
struct PacRecord {
    char name[0x40];
    int headerSize;
    int dataSize;
    int stride;
};
