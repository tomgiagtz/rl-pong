#include "RectEntity.h"

#include "raymath.h"

void RectEntity::Render() {
    Entity::Render();

    DrawRectangleRec(GetRect(), color);
}

void RectEntity::OnCollisionBegin(RectEntity* _otherRect) {
    collidingEntities.insert(_otherRect);

    SetColor(Color{255, 0, 0, 255});
}

void RectEntity::OnCollisionEnd(RectEntity* _otherRect) {
    collidingEntities.erase(_otherRect);

    if (collidingEntities.empty()) {
        SetColor(Color{255, 255, 255, 255});
    }
}

void RectEntity::SetColor(const Color& _color) {
    color = _color;
}

Color RectEntity::GetColor() const {
    return color;
}

Rectangle RectEntity::GetRect() {
    return {position.x, position.y, (float)width, (float)height};
}


Vector2 RectEntity::GetCenter() {
    // return position + {width, height} / 2; but ugly
    return Vector2Add(position, Vector2Scale({(float)width, (float)height}, 2));
}

bool RectEntity::CheckRectOverlap(RectEntity* rect1, RectEntity* rect2) {
    // positions are top left corner
    //   left edge = position.x
    //  right edge = position.x + width
    //    top edge = position.y
    // bottom edge = position.y + height

    if (rect1->position.x + rect1->width >= rect2->position.x &&  //rect1 right side past rect2 left side
        rect1->position.x <= rect2->position.x + rect2->width &&  //rect1 left past rect 2 right
        rect1->position.y + rect1->height >= rect2->position.y && //rect1 bottom past rect2 top
        rect1->position.y <= rect2->position.y + rect2->height) { //rect1 top past rect2 bottom
        return true;
    }

    return false;
}
