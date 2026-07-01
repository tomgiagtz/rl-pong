#include "Button.h"

#include "raylib.h"

void Button::SetStyle(const ButtonStyle& _style) {
    style = _style;
    boundingRect = {_style.position.x, _style.position.y, _style.size.x, _style.size.y};
}
void Button::SetPosition(const Vector2 _position) {
    style.position = _position;
    SetStyle(style);
}
void Button::ClickActionHandled() {
    bAwaitingClickHandler = false;
}
void Button::ClickPerformed() {
    bAwaitingClickHandler = true;
}

bool Button::IsClickActionPending() const {
    return bAwaitingClickHandler;
}

Button::Button(const ButtonStyle& _style) {
    SetState(IDLE);
    SetStyle(_style);
}
void Button::Start() {
    Entity::Start();
}
void Button::Update(const float _deltaTime) {
    if (state == ButtonState::DISABLED) {
        return;
    }

    Vector2 mousePos = GetMousePosition();
    bool bMouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    bool mouseReleased = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);

    bool bMouseIsHovering = CheckCollisionPointRec(mousePos, boundingRect);

    if (!bMouseIsHovering) {
        SetState(IDLE);
    }

    if (bMouseIsHovering) {

        if (state == IDLE) {
            SetState(HOVER);
            return;
        }

        // prevent setting state if the button is held
        if (state == PRESSED) {
            if (!bMouseDown) {

                SetState(HOVER);
                ClickPerformed();
            }
        }

        if (bMouseDown) {
            SetState(PRESSED);
        }


    }

}
void Button::Render() {
    DrawRectangleRounded(boundingRect, 0.1f, 16, style.GetStateColor(state));
}
void Button::SetActive(const bool _active) {
    SetState(_active ? IDLE : DISABLED);
    Entity::SetActive(_active);
}
void Button::SetState(ButtonState newState) {
    state = newState;
}