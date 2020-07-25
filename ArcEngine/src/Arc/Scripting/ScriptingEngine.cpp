//
//  ScriptingEngine.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 7/07/20.
//

#include "Arc/Scripting/ScriptingEngine.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <vector>

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
        //mono_set_dirs("../ArcEngine/vendor/mono/lib", "../ArcEngine/vendor/mono/etc");

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

    MonoMethod* ScriptingEngine::CreateMethod(std::string methodName, MonoClass* scriptClass)
    {
        return GetInstance()->CreateMethodImpl(methodName, scriptClass);
    }

    MonoClass* ScriptingEngine::CreateClassImpl(std::string _className)
    {
        // Gotta Split Up Class Name
        std::stringstream ss[2];

        enum class ScriptParts
        {
            NAMESPACE,
            NAME
        };

        ScriptParts currentPart = ScriptParts::NAMESPACE;

        for (int i = 0; i < _className.size(); i++)
        {
            if (_className[i] == '.') {
                currentPart = ScriptParts::NAME;
            }
            else {
                ss[(int)currentPart] << _className[i];
            }
        }

        MonoClass* scriptClass = mono_class_from_name(m_Image, ss[0].str().c_str(), ss[1].str().c_str());
        
        if (!scriptClass) {
            std::cout << ss[0].str() << std::endl;
            std::cout << ss[1].str() << std::endl;
            std::cout << "Script Class Not Created" << std::endl;
        }
        else {
            std::cout << ss[0].str() << std::endl;
            std::cout << ss[1].str() << std::endl;
            std::cout << "Script Class Created" << std::endl;
        }

        return scriptClass;
    }
    
    MonoObject* ScriptingEngine::CreateObject(MonoClass* _className)
    {
       return GetInstance()->CreateObjectImpl(_className);
    }

    MonoObject* ScriptingEngine::CreateObjectImpl(MonoClass* _class)
    {
        MonoObject* newObject = mono_object_new(m_Domain, _class);
        mono_runtime_object_init(newObject);
        
        if (!newObject) {
            std::cout << "Object Not Created" << std::endl;
        }
        else {
            std::cout << "Object Created" << std::endl;
        }
        
        return newObject;
    }

    void ScriptingEngine::RunScript(MonoMethod* method, MonoObject* object)
    {
        GetInstance()->RunMethodImpl(method, object);
    }

    MonoMethod* ScriptingEngine::CreateMethodImpl(std::string methodName, MonoClass* scriptClass)
    {
        void* iter = nullptr;
        MonoMethod* m;

        while ((m = mono_class_get_methods(scriptClass, &iter)))
        {
            if (mono_method_get_name(m) == methodName)
            {
                return m;
            }
        }
        return nullptr;
    }

    void ScriptingEngine::RunMethodImpl(MonoMethod* method, MonoObject* object)
    {
        mono_runtime_invoke(method, object, nullptr, nullptr);
    }
}
