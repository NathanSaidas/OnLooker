#ifndef OL_COMPONENT_H
#define OL_COMPONENT_H

#include <string>

namespace OnLooker
{
    class GameObject;
    class Component
    {
    public:

        virtual void awake() = 0;
        virtual void onEnable() = 0;
        virtual void onDisable() = 0;
        virtual void update() = 0;
        virtual void render() = 0;

    private:
        std::string m_Name;
        bool m_Enabled;
        GameObject * m_GameObject; //The game object the component belongs to

    };
}

#endif