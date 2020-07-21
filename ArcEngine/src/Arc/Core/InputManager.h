//
//  InputManager.h
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#ifndef InputManager_h
#define InputManager_h

namespace Arc {
    
    enum InputState
    {
        KEY_INITIAL,
        KEY_PRESSED,
        KEY_RELEASED
    };
    
    class InputManager
    {
    public:
        static InputManager* GetInstance();
        
        // Getters
        // -- Keys
        static bool GetKeyPressed(int key);
        static bool GetKeyReleased(int key);
        
        // Setters
        static void SetKeyPressed(int key);
        static void SetKeyReleased(int key);
        
    private:
        // Non-Static Implementations
        // Getters
        
        // -- Keys
        bool GetKeyPressedImpl(int key);
        bool GetKeyReleasedImpl(int key);
        
        // -- Mouse
        
        // Setters
        void SetKeyPressedImpl(int key);
        void SetKeyReleasedImpl(int key);
    private:
        InputManager();
        static InputManager* s_Instance;
        InputState state[255];
    };
}


#endif /* InputManager_h */
