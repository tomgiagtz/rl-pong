#pragma once
#include "Core/Entity.h"
#include "raylib.h"

enum ButtonState {
    IDLE,
    HOVER,
    PRESSED,
    DISABLED
};

struct ButtonStyle {
public:

    ButtonStyle() {
        this->position = {GetScreenHeight()/2.f, GetScreenWidth()/2.f};
    }

    ButtonStyle(Vector2 size, Vector2 position) {
        ButtonStyle();
        this->size = size;
    };

    /**
     * Size of the button in pixels
     */
    Vector2 size = {100, 30};
    /**
     * Position of the button, top left
     */
    Vector2 position;

    Color GetStateColor(const ButtonState state) const {
        switch (state) {
            case IDLE:
                return idleColor;
            case HOVER:
                return hoverColor;
            case PRESSED:
                return pressedColor;
            case DISABLED:
                return disabledColor;
            }
        return GetColor(0xFF00FFff);
    }

    Color idleColor = GetColor(0xff0000ff);
    Color hoverColor = GetColor(0x303030ff);
    Color pressedColor = GetColor(0x282828ff);
    Color disabledColor = GetColor(0x101010ff);
};

class Button : public Entity {
public:
    Button(const ButtonStyle& _style);
    void Start() override;

    void Update(const float _deltaTime) override;
    void Render() override;
    void SetActive(const bool _active) override;
    void SetStyle(const ButtonStyle& _style);
    void SetPosition(const Vector2 _position);

    /**
     * Function called after the awaited click has been handled
     */
    void ClickActionHandled();
    bool IsClickActionPending() const;

private:
    ButtonStyle style;
    ButtonState state;
    Rectangle boundingRect;
    bool bAwaitingClickHandler;
    void SetState(ButtonState state);

    void ClickPerformed();
};
