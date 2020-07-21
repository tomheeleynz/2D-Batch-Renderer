//
//  MetalShader.h
//  ArcEngine
//
//  Created by Thomas Heeley on 25/05/20.
//

#include <string>
#include "Arc/Renderer/Shader.h"

namespace Arc {
    class MetalShader : public Shader
    {
    public:
        MetalShader(std::string _strFileName);
        
        void Bind() override;
        void Unbind() override;
        void* GetNative() override;
        
        void SetInt(std::string uniformName, int value) override;
        void SetMat4(std::string uniformName, glm::mat4 value) override;
    private:
        struct Impl;
        Impl* impl;
        
    };
}
