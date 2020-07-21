//
//  CocoaWindow.swift
//  ArcEngine
//
//  Created by Thomas Heeley on 29/05/20.
//

import Foundation
import Cocoa
import MetalKit

class Window : NSWindow
{
    var m_viewController : ViewController!
    var keyCallback : ((NSInteger, NSInteger)->Void)!
    
    override func keyDown(with event: NSEvent)
    {
        keyCallback(NSInteger(event.keyCode), 0)
    }
    
    override func keyUp(with event: NSEvent)
    {
        keyCallback(NSInteger(event.keyCode), 1)
        
        if (event.keyCode == 13)
        {
            let openPanel : NSOpenPanel = NSOpenPanel()
            openPanel.canChooseFiles = true
            openPanel.canChooseDirectories = true
            openPanel.begin { (result) -> Void in
                if (result.rawValue == NSApplication.ModalResponse.OK.rawValue) {
                    
                }
            }
        }
    }
    
    override func mouseDown(with event: NSEvent) {
        
    }
    
    override func mouseDragged(with event: NSEvent) {
        
    }
    
    override func mouseMoved(with event: NSEvent) {
        
    }
    
    @objc func MakeContextCurrent(_ viewController : ViewController)->Void {
        let view = self.contentView!
        let trackingArea = NSTrackingArea(rect: view.bounds, options:[.activeInActiveApp, .mouseMoved, .mouseEnteredAndExited], owner: self)
        m_viewController = viewController
        viewController.view.frame = view.bounds
        viewController.view.addTrackingArea(trackingArea)
        view.addSubview(viewController.view)
    }
}

extension Window : NSWindowDelegate {
    func windowWillClose(_ notification: Notification) {
        NSApp.terminate(self)
    }
    
    func windowWillResize(_ sender: NSWindow, to frameSize: NSSize) -> NSSize {
        m_viewController.GetView().frame = NSMakeRect(0, 0, frameSize.width, frameSize.height)
        return frameSize
    }
}

class ViewController : NSViewController
{    
    @objc func GetView() -> NSView
    {
        return self.view
    }
    
    override func loadView() {
        let metalView = MTKView(frame: .zero)
        metalView.isPaused = true
        metalView.enableSetNeedsDisplay = false
        self.view = metalView
    }
}

class AppDelegate : NSObject, NSApplicationDelegate {
    // Creating A Window for App
    let window = Window()
    
    // Creating a view to render inside the window
    var rootViewController: NSViewController?
    
    var screenWidth: Int!
    var screenHeight: Int!
    var screenTitle: String!
    
    override init() {
        print("Starting App Delegate")
    }
    
    @objc func GetWindowHandle() -> NSWindow
    {
        return window
    }
    
    @objc init(width: Int, height : Int, title : String) {
        screenWidth = width
        screenHeight = height
        screenTitle = title
        
        window.setContentSize(NSSize(width: screenWidth , height: screenHeight))
        window.styleMask = [ .titled, .closable, .miniaturizable, .resizable ]
        window.title = screenTitle
        window.level = .normal
        window.center()
        window.makeKeyAndOrderFront(window)
    }
    
    @objc func SetKeyCallback(_ keyDownCallBack : @escaping (NSInteger, NSInteger)->()) {
        window.keyCallback = keyDownCallBack
    }
    
    @objc func SetDimension(_ width: Int, _ height: Int, _ title: String){
        screenWidth = width
        screenHeight = height
        screenTitle = title
    }
    
    @objc func UpdateWindowTitle(_ title : String) {
        window.title = title
    }
    
    // Init Window and View after app has Finished Launching
    func applicationDidFinishLaunching(_ notification: Notification) {
        NSApp.activate(ignoringOtherApps: true)
    }
}



