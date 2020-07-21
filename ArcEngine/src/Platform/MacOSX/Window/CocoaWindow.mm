//
//  CocoaWindow.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 1/05/20.
//  Copyright © 2020 Thomas Heeley. All rights reserved.
//

#include "CocoaWindow.h"
#include "Arc/Core/InputManager.h"
#include <functional>

namespace Arc {
    Window* Window::Create(WindowsProps props)
    {
        return new CocoaWindow(props);
    }

    CocoaWindow::CocoaWindow(WindowsProps props)
    {
        Init(props);
    }
    
    void CocoaWindow::Init(WindowsProps props)
    {
        m_Data.m_strTitle = props._strTitle;
        m_Data.m_iHeight = props._iHeight;
        m_Data.m_iWidth = props._iWidth;
        
        // Setting Up App, and Passing In variables to create window
        appDelegate = [[AppDelegate alloc] initWithWidth:m_Data.m_iWidth height:m_Data.m_iHeight title:[NSString stringWithCString:m_Data.m_strTitle.c_str() encoding:[NSString defaultCStringEncoding]]];
        
        m_Context = GraphicsContext::Create([appDelegate GetWindowHandle]);
        m_Context->Init();
            
        // Window Callbacks
        [appDelegate SetKeyCallback:^(NSInteger key, NSInteger keyState) {
            switch (keyState) {
                case 0: {
                    InputManager::SetKeyPressed(key);
                    break;
                }
                case 1: {
                    InputManager::SetKeyReleased(key);
                    break;
                }
                default:
                    break;
            }
        }];
        
        app = [NSApplication sharedApplication];
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        [app setDelegate:appDelegate];
    }

    void CocoaWindow::OnUpdate()
    {
        [app run];
    }
    
    GraphicsContext* CocoaWindow::GetContext()
    {
        return m_Context;
    }
    
    void CocoaWindow::UpdateTitle(std::string _strTitle)
    {
        [appDelegate UpdateWindowTitle:[NSString stringWithCString:_strTitle.c_str() encoding:[NSString defaultCStringEncoding]]];
    }
}
