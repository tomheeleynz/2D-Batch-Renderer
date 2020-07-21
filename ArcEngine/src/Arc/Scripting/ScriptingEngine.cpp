//
//  ScriptingEngine.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 7/07/20.
//

#include "Arc/Scripting/ScriptingEngine.h"
#include <stdio.h>
#include <iostream>

namespace Arc {
    ScriptingEngine* ScriptingEngine::s_Instance = nullptr;
    
    ScriptingEngine::ScriptingEngine()
    {
        
    }
    
    ScriptingEngine* ScriptingEngine::GetInstance()
    {
        if (!s_Instance)
        {
            s_Instance = new ScriptingEngine();
            return s_Instance;
        }
        return s_Instance;
    }

    void ScriptingEngine::Init(std::string _strRuntimeLocation)
    {
        GetInstance()->InitImpl(_strRuntimeLocation);
    }
    
    void ScriptingEngine::InitImpl(std::string _strRuntimeLocation)
    {
        m_Domain = mono_jit_init("Scripting_Engine");
        m_Assembly = mono_domain_assembly_open(m_Domain, _strRuntimeLocation.c_str());
        m_Image = mono_assembly_get_image(m_Assembly);
        
        if (!m_Image) {
            std::cout << "Image Not Created" << std::endl;
        }
        else {
            std::cout << "Image Created" << std::endl;
        }
    }

    MonoClass* ScriptingEngine::CreateClass(std::string _className)
    {
        return GetInstance()->CreateClassImpl(_className);
    }

    MonoClass* ScriptingEngine::CreateClassImpl(std::string _className)
    {
        MonoClass* scriptClass = mono_class_from_name(m_Image, "ExampleApp", "PlayerMovement");
        return scriptClass;
    }
    
    MonoObject* ScriptingEngine::CreateObject(MonoClass* _className)
    {
       return GetInstance()->CreateObjectImpl(_className);
    }

    MonoObject* ScriptingEngine::CreateObjectImpl(MonoClass* _class)
    {
        MonoObject* newObject = mono_object_new(m_Domain, _class);
        
        if (!newObject) {
            std::cout << "Object Not Created" << std::endl;
        }
        else {
            std::cout << "Object Created" << std::endl;
        }
        
        return newObject;
    }

    void ScriptingEngine::RunScript(std::string _methodName, MonoClass* scriptClass, MonoObject* scriptObject)
    {
        GetInstance()->RunMethodImpl(_methodName, scriptClass, scriptObject);
    }

    void ScriptingEngine::RunMethodImpl(std::string _methodName, MonoClass* scriptClass, MonoObject* scriptObject)
    {
        void *iter = nullptr;
        MonoMethod* m;
        
        while((m = mono_class_get_methods(scriptClass, &iter)))
        {
            mono_runtime_invoke(m, scriptObject, nullptr, nullptr);
        }
    }
}
