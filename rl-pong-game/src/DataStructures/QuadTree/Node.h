#pragma once


#include "uuid_v4.h"
#include "QuadTreeStructs.h"
#include "Core/Entity.h"
#include "Core/RectEntity.h"

class Node {
public:
    static constexpr size_t CAPACITY = 1;

    UUIDv4::UUID GetId() const {
        return id;
    }

    Boundary GetBounds() const {
        return bounds;
    }

    bool IsDivided() const {
        return isDivided;
    }

    void SetDivided() {
        isDivided = true;
    }

    Node(const UUIDv4::UUID& _uuid = UUIDv4::UUID(), const Boundary _bounds = {0, 0, 0, 0}) :
        id(_uuid), bounds(_bounds) {
    }


    bool Insert(RectEntity* _rect) {
        if (!bounds.ContainsPoint(_rect->GetIntPosition()))
            return false;

        if (!entity) {
            entity = _rect;
            return true;
        }
        return false;
    }

    RectEntity* GetEntity() {
        return entity;
    }

    void ClearEntity() {
        entity = nullptr;
    }

    UUIDv4::UUID* GetChildren() {
        return children;
    }

private:
    const UUIDv4::UUID id;
    int depth = 0;
    Boundary bounds;
    bool isDivided = false;
    UUIDv4::UUID children[4];

    RectEntity* entity = nullptr;

};
