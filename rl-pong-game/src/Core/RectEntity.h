#pragma once
#include <set>

#include "Entity.h"
#include "raylib.h"


enum Edge {
    NONE,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

class RectEntity : public Entity {
public:
    void Render() override;

    virtual void OnCollision(RectEntity* _otherRect) {};

    virtual void OnCollisionBegin(RectEntity* _otherRect);;

    virtual void OnCollisionEnd(RectEntity* _otherRect);;

protected:
    Vector2 position = {0, 0};
    Vector2 velocity = {0, 0};
    int width = 30;
    int height = 30;

    Color color = WHITE;

    bool shouldCollide = false;
    bool isColliding = false;
    std::set<RectEntity*> collidingEntities;

public:
    void SetColor(const Color& _color);

    bool HasCollision() override {
        return shouldCollide;
    }

    void SetPosition(const Vector2 _position) {
        position = _position;
    }

    Color GetColor() const;
    Rectangle GetRect();
    Vector2 GetCenter();
    void RandomizePosition();

    float GetEdgeTop() { return position.y; }
    float GetEdgeBottom() { return position.y + height; }
    float GetEdgeLeft() { return position.x; }
    float GetEdgeRight() { return position.x + width; }

    int GetWidth() const {
        return width;
    }

    int GetHeight() const {
        return height;
    }

    RectEntity(const Vector2 _position, const int _width = 30, const int _height = 30):
        position(_position), width(_width), height(_height) {};

    static bool CheckRectOverlap(RectEntity* rect1, RectEntity* rect2);
    static Edge GetClosestEdge(RectEntity* rect1, RectEntity* rect2);
    static Edge BoundsCollision(RectEntity* rect);


};
