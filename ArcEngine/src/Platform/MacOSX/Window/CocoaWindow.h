//
//  CocoaWindow.h
//  ArcEngine
//
//  Created by Thomas Heeley on 1/05/20.
//  Copyright © 2020 Thomas Heeley. All rights reserved.
//

#ifndef CocoaWindow_h
#define CocoaWindow_h

#include <iostream>
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>
#include "Arc/Core/Window.h"

namespace Arc {
	class CocoaWindow : public Window
	{
	public:
		CocoaWindow(WindowsProps props);
		
		void OnUpdate() override;
        GraphicsContext* GetContext() override;
        void UpdateTitle(std::string _strTitle) override;
        void TestCallbackFunction();
        
	private:
		void Init(WindowsProps props);
		
	private:
		struct WindowData
		{
			std::string m_strTitle;
			int m_iWidth;
			int m_iHeight;
		};
	
		WindowData m_Data;
        AppDelegate* appDelegate;
		NSApplication* app;
        GraphicsContext* m_Context;
	};
}

#endif /* CocoaWindow_h */
