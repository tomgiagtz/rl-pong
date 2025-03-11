#pragma once

#include <random>
#include <unordered_map>
#include <uuid_v4.h>
#include "Node.h"
#include "QuadTreeStructs.h"
#include "raylib.h"
#include "Core/RectEntity.h"


class QuadTree {


public:
    QuadTree(Boundary _bounds) :
        bounds(_bounds) {
        rootId = UUIDGenerator.getUUID();
        nodes.emplace(rootId, Node(rootId, bounds));
    }

    void SetBounds(Boundary _bounds) {
        bounds = _bounds;
    }

    bool Insert(RectEntity* _entity) {

        Node& root = nodes[rootId];

        return Insert(root, _entity);
    }

    bool Insert(Node& _node, RectEntity* _entity) {
        if (!_node.GetBounds().ContainsPoint(_entity->GetIntPosition())) {
            return false;
        }
        //node has capacity
        if (!_node.GetEntity() && _node.Insert(_entity)) {
            return true;
        }
        //node at capacity

        Subdivide(_node);

        if (_node.IsDivided()) {
            for (size_t i = 0; i < 4; i++) {
                UUIDv4::UUID& childID = _node.GetChildren()[i];
                if (Insert(nodes[childID], _entity)) {
                    return true;
                }
            }
        }
        return false;
    }

    void Subdivide(Node& _node) {
        if (_node.IsDivided()) {
            return;
        }
        _node.SetDivided();
        UUIDv4::UUID* children = _node.GetChildren();

        for (size_t i = 0; i < 4; i++) {
            const Quadrant quad = (Quadrant) i;
            UUIDv4::UUID quadId = UUIDGenerator.getUUID();
            Boundary quadBounds = _node.GetBounds().GetQuadrant(quad);
            nodes.emplace(quadId, Node(quadId, quadBounds));
            children[i] = quadId;

            nodes[quadId].Insert(_node.GetEntity());
        }
        _node.ClearEntity();

    }

    void Subdivide() {
        Subdivide(nodes[rootId]);
    }

    void Clear() {
        nodes.clear();
        nodes.emplace(rootId, Node(rootId, bounds));
    }

    void Render() {
        for (auto const& curr : nodes) {
            const Node& currNode = curr.second;;
            DrawRectangleLinesEx((Rectangle) currNode.GetBounds(), 2.f, {255, 255, 255, 255});

        }
    }

private:
    Boundary bounds;
    std::unordered_map<UUIDv4::UUID, Node> nodes;
    UUIDv4::UUIDGenerator<std::mt19937_64> UUIDGenerator;
    UUIDv4::UUID rootId;

};


