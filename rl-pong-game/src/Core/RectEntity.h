#pragma once
#include "Entity.h"
#include "raylib.h"

class RectEntity : public Entity {
protected:
    Vector2 position = {0, 0};
    Vector2 velocity = {0, 0};
    int width = 30;
    int height = 30;



    bool shouldCollide = false;

public:
    bool HasCollision() override {
        return shouldCollide;
    }

    void SetPosition(const Vector2 _position) {
        position = _position;
    }

    Rectangle GetRect();
    Vector2 GetCenter();

    int GetWidth() const {
        return width;
    }

    int GetHeight() const {
        return height;
    }

    RectEntity(const Vector2 _position, const int _width = 30, const int _height = 30):
        position(_position), width(_width), height(_height) {};

    static bool CheckRectOverlap(RectEntity* rect1, RectEntity* rect2);
};
