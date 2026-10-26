#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/Bounds3D.h"

// The struct tag stays: func_0204c608's C++ symbol is mangled with it.
struct Vec3Target0204c608 {
    int x;
    int y;
    int z;
};
extern "C" void func_0204c608(Vec3Target0204c608* obj, int x, int y, int z);

struct TerrainMeshHeader {
    int type;
    int shift;
    short originX;
    short originY;
    short unknown_c_;
    char unknown_e_[0x18 - 0x0e];
    short unknown_18_;
    unsigned int cols;
    unsigned int rows;
};

struct TerrainMeshPolygon {
    union {
        Vector3s unknown_0_[4];
        short unknown1_0_[12];
    };
    unsigned char minX : 4;
    unsigned char unknown_18_4_ : 4;
    unsigned char minZ : 4;
    unsigned char maxX : 4;
    unsigned char unknown_1a_0_ : 4;
    unsigned char maxZ : 4;
    unsigned char visited : 1;
    unsigned char unknown_1b_1_ : 7;

    short MinX() const { return unknown1_0_[minX]; }
    short MinY() const { return unknown1_0_[unknown_18_4_]; }
    short MinZ() const { return unknown1_0_[minZ]; }
    short MaxX() const { return unknown1_0_[maxX]; }
    short MaxY() const { return unknown1_0_[unknown_1a_0_]; }
    short MaxZ() const { return unknown1_0_[maxZ]; }
    void GetMin(Vector3fix* v) const { func_0204c608((Vec3Target0204c608*)v, MinX(), MinY(), MinZ()); }
    void GetMax(Vector3fix* v) const { func_0204c608((Vec3Target0204c608*)v, MaxX(), MaxY(), MaxZ()); }
    Bounds3D GetBox() const {
        Bounds3D box;
        GetMin(&box.minimum);
        GetMax(&box.maximum);
        return box;
    }
};

struct TerrainMesh {
    TerrainMeshHeader* header;
    TerrainMeshPolygon* polygons;
    unsigned char* unknown_8_;
    unsigned short* unknown_c_;
    unsigned short* polygonIndices;
    int field14;
    Bounds3D bounds;
    Vector3i origin;
    Vector3i field3c;
    unsigned int cellCount;
};

// The header's ZoneTerrainGrid (World/ZoneTerrain.h) as this function fills it.
struct ZoneTerrainGrid {
    Vector3s polygons[96][4];
    int count;
    int scale;
    Vector3i position;
    Vector3i unknown_914_;
    unsigned char attributes[96];
};

extern "C" bool Bounds3D_Overlap(const Bounds3D* a, const Bounds3D* b);

// Main, originally func_0204c030 (USA 0x0204c030, EUR 0x0204c040, JPN 0x0204ce50)
extern "C" ARM int TerrainMesh_CollectPolygons(TerrainMesh* mesh, ZoneTerrainGrid* grid, Bounds3D probe) {
    static int sLastTotal;
    TerrainMeshPolygon* visitedPolygons[192];
    Vector3fix_Subtract(&probe.minimum, &mesh->origin, &probe.minimum);
    Vector3fix_Subtract(&probe.maximum, &mesh->origin, &probe.maximum);
    if (!Bounds3D_Overlap(&probe, &mesh->bounds)) return 0;
    probe.minimum.x >>= mesh->header->shift;
    probe.minimum.y >>= mesh->header->shift;
    probe.minimum.z >>= mesh->header->shift;
    probe.maximum.x >>= mesh->header->shift;
    probe.maximum.y >>= mesh->header->shift;
    probe.maximum.z >>= mesh->header->shift;
    int searchCells[7] = {0, 1, 2, 3, 4, 5, 6};
    int searchCount = 0;
    int centerX = (probe.maximum.x + probe.minimum.x) / 2;
    int centerZ = (probe.maximum.z + probe.minimum.z) / 2;
    if (mesh->cellCount <= 7) {
        searchCount = mesh->cellCount;
    } else {
        int row = (int)((float)fix32_Divide(centerZ - mesh->header->unknown_c_, mesh->header->unknown_18_) / 4096.0f);
        if (row >= 0 && row < mesh->header->rows) {
            bool found = false;
            if (row % 2 == 0) {
                int col = (int)((float)fix32_Divide(centerX - mesh->header->originX, mesh->header->unknown_18_) / 4096.0f);
                if (col >= 0 && col < mesh->header->cols) found = true;
                if (found) {
                    int index = row * mesh->header->cols + col + row / 2;
                    unsigned int cols = mesh->header->cols;
                    searchCells[searchCount++] = index;
                    if (row > 0) {
                        searchCells[searchCount++] = index - mesh->header->cols;
                        searchCells[searchCount++] = index - mesh->header->cols - 1;
                    }
                    if (row < mesh->header->rows - 1) {
                        searchCells[searchCount++] = index + mesh->header->cols;
                        searchCells[searchCount++] = index + mesh->header->cols + 1;
                    }
                    if (col > 0) searchCells[searchCount++] = index - 1;
                    if (col < cols - 1) searchCells[searchCount++] = index + 1;
                }
            } else {
                int col = (int)((float)fix32_Divide(centerX - mesh->header->originX + mesh->header->unknown_18_ / 2, mesh->header->unknown_18_) / 4096.0f);
                if (col >= 0 && col < mesh->header->cols + 1) found = true;
                if (found) {
                    int index = row * mesh->header->cols + col + row / 2;
                    unsigned int cols = mesh->header->cols;
                    searchCells[searchCount++] = index;
                    if (row > 0) {
                        if (col > 0) searchCells[searchCount++] = index - cols - 1;
                        if (col < cols) searchCells[searchCount++] = index - cols;
                    }
                    if (row < mesh->header->rows - 1) {
                        if (col > 0) searchCells[searchCount++] = index + cols;
                        if (col < cols) searchCells[searchCount++] = index + cols + 1;
                    }
                    if (col > 0) searchCells[searchCount++] = index - 1;
                    if (col < cols) searchCells[searchCount++] = index + 1;
                }
            }
        }
    }
    int visitedCount = 0;
    int total = 0;
    for (int i = 0; i < searchCount; i++) {
        int cell = searchCells[i];
        int count = mesh->unknown_8_[cell];
        int start = mesh->unknown_c_[cell];
        for (int j = 0; j < count; j++) {
            TerrainMeshPolygon* polygon = &mesh->polygons[mesh->polygonIndices[start + j]];
            if (!polygon->visited) {
                polygon->visited = 1;
                visitedPolygons[visitedCount++] = polygon;
                if (visitedCount == 192) break;
                Bounds3D box = polygon->GetBox();
                if (Bounds3D_Overlap(&box, &probe)) {
                    Vector3fix16Copy(&grid->polygons[total][0], &polygon->unknown_0_[0]);
                    Vector3fix16Copy(&grid->polygons[total][1], &polygon->unknown_0_[1]);
                    Vector3fix16Copy(&grid->polygons[total][2], &polygon->unknown_0_[2]);
                    Vector3fix16Copy(&grid->polygons[total][3], &polygon->unknown_0_[3]);
                    if (mesh->header->type == 3) grid->attributes[total] = polygon->unknown_1b_1_;
                    total++;
                    grid->count = total;
                    if (total == 96) break;
                }
            }
        }
        if (total == 96) break;
    }
    for (int k = 0; k < visitedCount; k++) visitedPolygons[k]->visited = 0;
    if (sLastTotal != total) sLastTotal = total;
    grid->scale = 1 << mesh->header->shift;
    grid->position = mesh->origin;
    grid->unknown_914_ = mesh->field3c;
    return total;
}
