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

void RectEntity::RandomizePosition() {
    int xpos = GetRandomValue(0, GetScreenWidth() - width);
    int ypos = GetRandomValue(0, GetScreenHeight() - height);
    position = {(float)xpos, (float)ypos};
}

//> collision functions

bool RectEntity::CheckRectOverlap(RectEntity* rect1, RectEntity* rect2) {
    if (rect1->GetEdgeRight() >= rect2->GetEdgeLeft() &&  //rect1 right side past rect2 left side
        rect1->GetEdgeLeft() <= rect2->GetEdgeRight() &&  //rect1 left past rect 2 right
        rect1->GetEdgeBottom() >= rect2->GetEdgeTop() && //rect1 bottom past rect2 top
        rect1->GetEdgeTop() <= rect2->GetEdgeBottom()) { //rect1 top past rect2 bottom
        return true;
    }

    return false;
}

float MinOverlap(float a, float b, float c, float d) {
    float min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

Edge RectEntity::GetClosestEdge(RectEntity* rect1, RectEntity* rect2) {
    float overlapLeft = rect1->GetEdgeRight() - rect2->GetEdgeLeft();
    float overlapRight = rect2->GetEdgeRight() - rect1->GetEdgeLeft();
    float overlapTop = rect1->GetEdgeBottom() - rect2->GetEdgeTop();
    float overlapBottom = rect2->GetEdgeBottom() - rect1->GetEdgeTop();

    float minOverlap = MinOverlap(overlapLeft, overlapRight, overlapTop, overlapBottom);

    // eww...
    if (minOverlap == overlapLeft) { return Edge::LEFT; }
    if (minOverlap == overlapTop) { return Edge::TOP; }
    if (minOverlap == overlapRight) { return Edge::RIGHT; }
    return Edge::BOTTOM;
}

Edge RectEntity::BoundsCollision(RectEntity* rect) {
    if (rect->position.y <= 0) return TOP;
    if (rect->position.y >= GetScreenHeight() - rect->height) return BOTTOM;
    if (rect->position.x <= 0) return LEFT;
    if (rect->position.x >= GetScreenWidth() - rect->width) return RIGHT;
    return NONE;
}
