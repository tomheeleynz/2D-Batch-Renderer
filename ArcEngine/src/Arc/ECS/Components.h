//
//  Components.h
//  ArcEngine
//
//  Created by Thomas Heeley on 11/07/20.
//

#ifndef Components_h
#define Components_h

#include <string>
#include <glm/glm.hpp>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

namespace Arc {
    struct Transform
    {
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;
        float rotationAngle;
    };

    struct SpriteRenderer
    {
        glm::vec3 color;
        std::string textureFile;
    };

    struct Script
    {
        // Script Name
        std::string _scriptName;

        // To Get Methods and Invoke Methods
        MonoClass* scriptClass;
        MonoObject* scriptObject;

        // Start And Update Methods
        MonoMethod* startMethod;
        MonoMethod* updateMethod;
    };
}

#endif /* Components_h */
