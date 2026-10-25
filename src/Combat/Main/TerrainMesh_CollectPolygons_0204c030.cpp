#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/Bounds3D.h"

// The struct tag stays: SetVec3At0x0's C++ symbol is mangled with it.
struct Vec3Target0204c608 {
    int x;
    int y;
    int z;
};
extern "C" void func_0204c608(Struct_0204c030_6* arg0, int arg1, int arg2, int arg3);

struct TerrainMeshHeader {
    int type;
    int shift;
    short originX;
    short originY;
    short originZ;
    char pad0e[0x18 - 0x0e];
    short cellSize;
    unsigned int cols;
    unsigned int rows;
};

struct TerrainMeshPolygon {
    union {
        Vector3s unknown_0_[4];
        short unknown1_0_[12];
    };
    unsigned char unknown_18_0_ : 4;
    unsigned char unknown_18_4_ : 4;
    unsigned char unknown_19_0_ : 4;
    unsigned char unknown_19_4_ : 4;
    unsigned char unknown_1a_0_ : 4;
    unsigned char unknown_1a_4_ : 4;
    unsigned char unknown_1b_0_ : 1;
    unsigned char unknown_1b_1_ : 7;

    short MinX() const { return coords[minX]; }
    short MinY() const { return coords[minY]; }
    short MinZ() const { return coords[minZ]; }
    short MaxX() const { return coords[maxX]; }
    short MaxY() const { return coords[maxY]; }
    short MaxZ() const { return coords[maxZ]; }
    void GetMin(Vector3fix* v) const { SetVec3At0x0((Vec3Target0204c608*)v, MinX(), MinY(), MinZ()); }
    void GetMax(Vector3fix* v) const { SetVec3At0x0((Vec3Target0204c608*)v, MaxX(), MaxY(), MaxZ()); }
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
    unsigned char* cellCounts;
    unsigned short* cellStarts;
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
    Vector3i field914;
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
        int row = (int)((float)fix32_Divide(centerZ - mesh->header->originZ, mesh->header->cellSize) / 4096.0f);
        if (row >= 0 && row < mesh->header->rows) {
            bool found = false;
            if (row % 2 == 0) {
                int col = (int)((float)fix32_Divide(centerX - mesh->header->originX, mesh->header->cellSize) / 4096.0f);
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
                int col = (int)((float)fix32_Divide(centerX - mesh->header->originX + mesh->header->cellSize / 2, mesh->header->cellSize) / 4096.0f);
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
        int count = mesh->cellCounts[cell];
        int start = mesh->cellStarts[cell];
        for (int j = 0; j < count; j++) {
            TerrainMeshPolygon* polygon = &mesh->polygons[mesh->polygonIndices[start + j]];
            if (!polygon->visited) {
                polygon->visited = 1;
                visitedPolygons[visitedCount++] = polygon;
                if (visitedCount == 192) break;
                Bounds3D box = polygon->GetBox();
                if (Bounds3D_Overlap(&box, &probe)) {
                    Vector3fix16Copy(&grid->polygons[total][0], &polygon->verts[0]);
                    Vector3fix16Copy(&grid->polygons[total][1], &polygon->verts[1]);
                    Vector3fix16Copy(&grid->polygons[total][2], &polygon->verts[2]);
                    Vector3fix16Copy(&grid->polygons[total][3], &polygon->verts[3]);
                    if (mesh->header->type == 3) grid->attributes[total] = polygon->attribute;
                    total++;
                    grid->count = total;
                    if (total == 96) break;
                }
            }
        }
        if (var14 == 96) break;
    }
    for (int k = 0; k < visitedCount; k++) visitedPolygons[k]->visited = 0;
    if (sLastTotal != total) sLastTotal = total;
    grid->scale = 1 << mesh->header->shift;
    grid->position = mesh->origin;
    grid->field914 = mesh->field3c;
    return total;
}
