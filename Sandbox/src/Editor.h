//
//  Editor.h
//  Sandbox
//
//  Created by Thomas Heeley on 18/07/20.
//

#ifndef Editor_h
#define Editor_h

#include <Arc.h>
#include <string>

class EditorLayer : public Arc::Layer
{
public:
    EditorLayer();
    
    void OnStart() override;
    void OnUpdate() override;

    void CreateScene(std::string _strName);
private:
    Arc::Scene* currentScene;
    Arc::Panel* entityPanel;
};

#endif /* Editor_h */

