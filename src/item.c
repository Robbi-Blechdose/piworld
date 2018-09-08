#include "item.h"
#include "util.h"

const int items[] =
{
    // items the user can build
    GRASS,
    SAND,
    STONE,
    BRICK,
    WOOD,
    CEMENT,
    DIRT,
    PLANK,
    SNOW,
    GLASS,
    COBBLE,
    LIGHT_STONE,
    DARK_STONE,
    CHEST,
    LEAVES,
    TALL_GRASS,
    YELLOW_FLOWER,
    RED_FLOWER,
    PURPLE_FLOWER,
    SUN_FLOWER,
    WHITE_FLOWER,
    BLUE_FLOWER,
    TORCH,
    WATER,
    SLAB_WOOD,
    COLOR_00,
    COLOR_01,
    COLOR_02,
    COLOR_03,
    COLOR_04,
    COLOR_05,
    COLOR_06,
    COLOR_07,
    COLOR_08,
    COLOR_09,
    COLOR_10,
    COLOR_11,
    COLOR_12,
    COLOR_13,
    COLOR_14,
    COLOR_15,
    COLOR_16,
    COLOR_17,
    COLOR_18,
    COLOR_19,
    COLOR_20,
    COLOR_21,
    COLOR_22,
    COLOR_23,
    COLOR_24,
    COLOR_25,
    COLOR_26,
    COLOR_27,
    COLOR_28,
    COLOR_29,
    COLOR_30,
    COLOR_31
};

const int item_count = sizeof(items) / sizeof(int);

const int blocks[256][7] =
{
    //block type, textures (left, right, top, bottom, front, back)
    //            textures (plant, unused ...)
    {T_BLOCK, 0, 0, 0, 0, 0, 0}, // 0 - empty
    {T_BLOCK, 16, 16, 32, 0, 16, 16}, // 1 - grass
    {T_BLOCK, 1, 1, 1, 1, 1, 1}, // 2 - sand
    {T_BLOCK, 2, 2, 2, 2, 2, 2}, // 3 - stone
    {T_BLOCK, 3, 3, 3, 3, 3, 3}, // 4 - brick
    {T_BLOCK, 20, 20, 36, 4, 20, 20}, // 5 - wood
    {T_BLOCK, 5, 5, 5, 5, 5, 5}, // 6 - cement
    {T_BLOCK, 6, 6, 6, 6, 6, 6}, // 7 - dirt
    {T_BLOCK, 7, 7, 7, 7, 7, 7}, // 8 - plank
    {T_BLOCK, 24, 24, 40, 8, 24, 24}, // 9 - snow
    {T_BLOCK_TRANSPARENT, 9, 9, 9, 9, 9, 9}, // 10 - glass
    {T_BLOCK, 10, 10, 10, 10, 10, 10}, // 11 - cobble
    {T_BLOCK, 11, 11, 11, 11, 11, 11}, // 12 - light stone
    {T_BLOCK, 12, 12, 12, 12, 12, 12}, // 13 - dark stone
    {T_BLOCK, 13, 13, 13, 13, 13, 13}, // 14 - chest
    {T_BLOCK_TRANSPARENT, 14, 14, 14, 14, 14, 14}, // 15 - leaves
    {T_BLOCK, 15, 15, 15, 15, 15, 15}, // 16 - cloud
    {T_QUADS_TRANSPARENT, 48, 0, 0, 0, 0, 0}, // 17 - tall grass
    {T_QUADS_TRANSPARENT, 49, 0, 0, 0, 0, 0}, // 18 - yellow flower
    {T_QUADS_TRANSPARENT, 50, 0, 0, 0, 0, 0}, // 19 - red flower
    {T_QUADS_TRANSPARENT, 51, 0, 0, 0, 0, 0}, // 20 - purple flower
    {T_QUADS_TRANSPARENT, 52, 0, 0, 0, 0, 0}, // 21 - sun flower
    {T_QUADS_TRANSPARENT, 53, 0, 0, 0, 0, 0}, // 22 - white flower
    {T_QUADS_TRANSPARENT, 54, 0, 0, 0, 0, 0}, // 23 - blue flower
    {T_QUADS_TRANSPARENT, 55, 0, 0, 0, 0, 0}, // 24 - torch
    {T_FLUID, 17, 17, 17, 17, 17, 17}, // 25 - water
    {T_SLAB, 7, 7, 7, 7, 7, 7} // 26 - wood slab
};

int is_plant(int w)
{
    switch (w)
    {
        case TALL_GRASS:
        case YELLOW_FLOWER:
        case RED_FLOWER:
        case PURPLE_FLOWER:
        case SUN_FLOWER:
        case WHITE_FLOWER:
        case BLUE_FLOWER:
        case TORCH:
            return 1;
        default:
            return 0;
    }
}

int is_obstacle(int w)
{
    w = ABS(w);
    if(is_plant(w))
    {
        return 0;
    }
    switch(w)
    {
        case EMPTY:
        case CLOUD:
        case WATER:
            return 0;
        default:
            return 1;
    }
}

int is_transparent(int w)
{
    if(w == EMPTY)
    {
        return 1;
    }
    w = ABS(w);
    if(getType(w) == T_QUADS_TRANSPARENT || getType(w) == T_BLOCK_TRANSPARENT || getType(w) == T_FLUID)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_destructable(int w)
{
    switch (w)
    {
        case EMPTY:
        case CLOUD:
            return 0;
        default:
            return 1;
    }
}

int getType(int w)
{
    return blocks[w][0];
}