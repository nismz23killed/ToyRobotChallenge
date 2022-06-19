#ifndef __FACING_H__
#define __FACING_H__


enum class Facing {
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

  

const char * FacingToStr(Facing facing);
Facing FacingFromStr(const char * facingStr);

#endif // __FACING_H__