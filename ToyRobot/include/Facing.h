#ifndef __FACING_H__
#define __FACING_H__

class Facing
{
public:
    enum class Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST,
    };

    static const Direction NORTH = Direction::NORTH;
    static const Direction SOUTH = Direction::SOUTH;
    static const Direction EAST = Direction::EAST;
    static const Direction WEST = Direction::WEST;

private:
    Direction _direction;

public:
    Facing(Direction direction);
    Facing() = default;
    virtual ~Facing() = default;
    
    Facing & operator=(Direction direction);
    bool operator==(const Direction other) const; 
    operator Direction() const { return _direction; }

    const char * toString() const;

    Facing left() const;
    Facing right() const;
};

#endif // __FACING_H__