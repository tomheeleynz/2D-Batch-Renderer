//
//  Editor.h
//  Sandbox
//
//  Created by Thomas Heeley on 18/07/20.
//

#ifndef Editor_h
#define Editor_h

#include <Arc.h>

class EditorLayer : public Arc::Layer
{
public:
    EditorLayer();
    
    void OnStart() override;
    void OnUpdate() override;
    
    void UpdateTitle();
private:
    Arc::Scene* currentScene;
};

#endif /* Editor_h */

