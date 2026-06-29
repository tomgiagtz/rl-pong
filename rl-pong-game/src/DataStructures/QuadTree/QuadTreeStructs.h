#pragma once
#include "raylib.h"

struct Position {
    int x;
    int y;
};

//clockwise starting at NW
enum class Quadrant {
    NW = 0,
    NE = 1,
    SE = 2,
    SW = 3
};

struct Boundary {
    int x;
    int y;
    int width;
    int height;

    explicit operator Rectangle() const {
        return {float(x), float(y), float(width), float(height)};
    }

    int GetRightEdge() const {
        return x + width;
    }

    int GetBottomEdge() const {
        return y + height;
    }

    int GetLeftEdge() const {
        return x;
    }

    int GetTopEdge() const {
        return y;
    }

    //bottom and right edge are inclusive
    bool ContainsPoint(const Position _pos) const {
        return _pos.x <= GetRightEdge() && _pos.x > GetLeftEdge() && _pos.y <= GetBottomEdge() && _pos.y > GetTopEdge();
    }

    Boundary GetNWQuadrant() const {
        return {x, y, width / 2, height / 2};
    };

    Boundary GetNEQuadrant() const {
        return {x + width / 2, y, width / 2, height / 2};
    };

    Boundary GetSWQuadrant() const {
        return {x, y + height / 2, width / 2, height / 2};
    };

    Boundary GetSEQuadrant() const {
        return {x + width / 2, y + height / 2, width / 2, height / 2};
    };

    Boundary GetQuadrant(const Quadrant _quad) const {
        switch (_quad) {
        case Quadrant::NW:
            return GetNWQuadrant();
        case Quadrant::NE:
            return GetNEQuadrant();
        case Quadrant::SE:
            return GetSEQuadrant();
        case Quadrant::SW:
            return GetSWQuadrant();
        }

        return Boundary();
    }

};

