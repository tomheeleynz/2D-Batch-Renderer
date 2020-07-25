//
//  ScriptingEngine.h
//  ArcEngine
//
//  Created by Thomas Heeley on 7/07/20.
//

#ifndef ScriptingEngine_h
#define ScriptingEngine_h

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <string>

namespace Arc {
    class ScriptingEngine
    {
    public:
        static void Init(std::string _strRuntimeLocation);
        static ScriptingEngine* GetInstance();
        static MonoClass* CreateClass(std::string _className);
        static MonoObject* CreateObject(MonoClass* _class);
        static void RunScript(MonoMethod* method, MonoObject* object);
        static MonoMethod* CreateMethod(std::string methodName, MonoClass* scriptClass);
        
    private:
        ScriptingEngine();
        static ScriptingEngine* s_Instance;
        
        // Implementation
        void InitImpl(std::string _strRuntimeLocation);
        MonoObject* CreateObjectImpl(MonoClass* _class);
        MonoClass* CreateClassImpl(std::string _className);
        void RunMethodImpl(MonoMethod* method, MonoObject* object);
        MonoMethod* CreateMethodImpl(std::string methodName, MonoClass* scriptClass);
    private:
        MonoDomain* m_Domain;
        MonoAssembly* m_Assembly;
        MonoImage* m_Image;
    };
}


#endif /* ScriptingEngine_h */
