//
//  InputManager.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#include "InputManager.h"

namespace Arc {
    InputManager* InputManager::s_Instance = nullptr;

    InputManager::InputManager()
    {
        
    }

    InputManager* InputManager::GetInstance()
    {
        if (!s_Instance)
        {
            s_Instance = new InputManager();
            return s_Instance;
        }
        return s_Instance;
    }
    
    // Getters
    // Get Key Pressed
    bool InputManager::GetKeyPressed(int key)
    {
        return GetInstance()->GetKeyPressedImpl(key);
    }

    bool InputManager::GetKeyPressedImpl(int key)
    {
        if (state[key] == KEY_PRESSED)
        {
            return true;
        }
        return false;
    }

    std::pair<float, float> InputManager::GetMouseCoords()
    {
        return GetInstance()->GetMouseCoordsImpl();
    }

    bool InputManager::GetMouseKeyPressed(int mouseKey)
    {
        return GetInstance()->GetMouseKeyPressedImpl(mouseKey);
    }

    bool InputManager::GetMouseKeyReleased(int mouseKey)
    {
        return GetInstance()->GetMouseKeyReleasedImpl(mouseKey);
    }

    std::pair<float, float> InputManager::GetMouseCoordsImpl()
    {
        return std::pair<float, float>(m_MouseCoords.x, m_MouseCoords.y);
    }

    bool InputManager::GetMouseKeyPressedImpl(int mouseKey)
    {
        if (mouseState[mouseKey] == MOUSE_KEY_PRESSED)
        {
            return true;
        }
        return false;
    }

    bool InputManager::GetMouseKeyReleasedImpl(int mouseKey)
    {
        if (mouseState[mouseKey] == MOUSE_KEY_RELEASED)
        {
            mouseState[mouseKey] = MOUSE_KEY_INITIAL;
            return true;
        }
        return false;
    }

    // Get Key Released
    bool InputManager::GetKeyReleased(int key)
    {
        return GetInstance()->GetKeyReleasedImpl(key);
    }
    
    bool InputManager::GetKeyReleasedImpl(int key)
    {
        if (state[key] == KEY_RELEASED)
        {
            state[key] = KEY_INITIAL;
            return true;
        }
        return false;
    }

 
    // Setters
    // Key Pressed
    void InputManager::SetKeyPressed(int key)
    {
        GetInstance()->SetKeyPressedImpl(key);
    }

    void InputManager::SetKeyPressedImpl(int key)
    {
        state[key] = KEY_PRESSED;
    }

    // Key Released
    void InputManager::SetKeyReleased(int key)
    {
        GetInstance()->SetKeyReleasedImpl(key);
    }

    void InputManager::SetKeyReleasedImpl(int key)
    {
        state[key] = KEY_RELEASED;
    }

    void InputManager::SetMouseCoords(float _x, float _y)
    {
        GetInstance()->SetMouseCoordsImpl(_x, _y);
    }

    void InputManager::SetMouseKeyPressed(int key)
    {
        GetInstance()->SetMouseKeyPressedImpl(key);
    }

    void InputManager::SetMouseKeyReleased(int key)
    {
        GetInstance()->SetMouseKeyReleasedImpl(key);
    }

    void InputManager::SetMouseCoordsImpl(float _x, float _y)
    {
        m_MouseCoords = {_x, _y};
    }
    
    void InputManager::SetMouseKeyPressedImpl(int key)
    {
        mouseState[key] = MOUSE_KEY_PRESSED;
    }

    void InputManager::SetMouseKeyReleasedImpl(int key)
    {
        mouseState[key] = MOUSE_KEY_RELEASED;
    }
}
