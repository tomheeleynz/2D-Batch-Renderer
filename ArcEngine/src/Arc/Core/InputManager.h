//
//  InputManager.h
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#ifndef InputManager_h
#define InputManager_h

#include <glm/glm.hpp>
#include <map>

namespace Arc {
    
    enum InputState
    {
        KEY_INITIAL,
        KEY_PRESSED,
        KEY_RELEASED
    };

    enum MouseKeyState
    {
        MOUSE_KEY_INITIAL,
        MOUSE_KEY_PRESSED,
        MOUSE_KEY_RELEASED
    };

    class InputManager
    {
    public:
        static InputManager* GetInstance();
        
        // Getters
        // -- Keys
        static bool GetKeyPressed(int key);
        static bool GetKeyReleased(int key);
        
        //-- Mouse
        static std::pair<float, float> GetMouseCoords();
        static bool GetMouseKeyPressed(int mouseKey);
        static bool GetMouseKeyReleased(int mouseKey);

        // Setters
        // -- Keys
        static void SetKeyPressed(int key);
        static void SetKeyReleased(int key);
        
        // -- Mouse
        static void SetMouseCoords(float _x, float _y);
        static void SetMouseKeyPressed(int key);
        static void SetMouseKeyReleased(int key);

    private:
        // Non-Static Implementations
        // Getters
        
        // -- Keys
        bool GetKeyPressedImpl(int key);
        bool GetKeyReleasedImpl(int key);

        
        //-- Mouse
        std::pair<float, float> GetMouseCoordsImpl();
        bool GetMouseKeyPressedImpl(int mouseKey);
        bool GetMouseKeyReleasedImpl(int mouseKey);

        // Setters
        // -- Keys
        void SetKeyPressedImpl(int key);
        void SetKeyReleasedImpl(int key);

        // -- Mouse
        void SetMouseCoordsImpl(float _x, float _y);
        void SetMouseKeyPressedImpl(int key);
        void SetMouseKeyReleasedImpl(int key);

    private:
        InputManager();
        static InputManager* s_Instance;
        InputState state[255];
        MouseKeyState mouseState[3];
        glm::vec2 m_MouseCoords;
    };
}


#endif /* InputManager_h */
