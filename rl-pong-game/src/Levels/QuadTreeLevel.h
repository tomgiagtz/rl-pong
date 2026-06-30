#pragma once

#include "Core/EntityManager.h"
#include "DataStructures/QuadTree/QuadTree.h"
#include "Gameplay/Ball.h"

class QuadTreeLevel {

private:
    static constexpr int NUM_BALLS = 512;
    Ball* balls[NUM_BALLS];
    QuadTree quadTree;

    bool bDrawQuadTree = true;

public:
    QuadTreeLevel():
        quadTree({0, 0, 1280, 800}) {
        for (int i = 0; i < NUM_BALLS; ++i) {
            balls[i] = new Ball({0, 0});
            EntityManager::Instance().RegisterEntity(balls[i]);
        }
    }

    void UnloadLevel() {
        for (Ball* ball : balls) {
            ball->Destroy();
        }
    }

    void Start() {
        //create numballs number of balls
        for (Ball* ball : balls) {
            ball->Reset();
        }
    }

    void Render() {
        if (bDrawQuadTree) {
            quadTree.Render();
        }
    }

    void Update() {
        quadTree.Clear();
        for (Ball* ball : balls) {
            quadTree.Insert(ball);
        }

        if (IsKeyPressed(KEY_Q)) {
            bDrawQuadTree = !bDrawQuadTree;
        }
    }
};
