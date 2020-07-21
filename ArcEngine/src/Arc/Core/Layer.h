//
//  Layer.h
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#ifndef Layer_h
#define Layer_h

#include <string>

namespace Arc {
    class Layer
    {
    public:
        Layer(std::string _strLayerName)
        {
            m_strName = _strLayerName;
        }
        
        std::string GetName()
        {
            return m_strName;
        }
        
        virtual void OnStart() {};
        virtual void OnUpdate() {};
    private:
        std::string m_strName;
        
    };
}

#endif /* Layer_h */
