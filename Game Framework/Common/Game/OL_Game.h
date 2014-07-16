#ifndef OL_GAME_H
#define OL_GAME_H

#include "../Core/Base Objects/OL_Object.h"

namespace OnLooker
{
	class Shader;
	class Color;
	class TextureReference;

    class Game : public Object
    {
    public:
        Game();
        ~Game();
		void load();
        void earlyUpdate();
        void update();
        void lateUpdate();
    
        void fixedUpdate();
        void collisionDetection();

        void render();
        void gui();

        
    private:

		unsigned int m_VBO;
		unsigned int m_IBO;
		Shader * m_Shader;
		Shader * m_TextureShader;
		Shader * m_MaskShader;

		Color * m_Color;

		TextureReference * m_Texture[3];
		unsigned int m_TextureHandles[2];

		float m_Transparency;

		long double m_Counter;

    };


}

#endif