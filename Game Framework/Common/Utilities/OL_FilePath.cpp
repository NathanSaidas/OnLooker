#include "OL_FilePath.h"
#include <string>
namespace OnLooker
{
    FilePath * FilePath::s_Instance = 0;
    FilePath * FilePath::getInstance()
    {
        if(s_Instance == 0)
        {
            s_Instance = new FilePath();
        }
        return s_Instance;
    }
    void FilePath::destroy()
    {
        if(s_Instance != 0)
        {
            delete s_Instance;
            s_Instance = 0;
        }
    }
    FilePath::FilePath()
    {
    }
    FilePath::~FilePath()
    {
    }
    std::string FilePath::convertPathForIni(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Ini/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForLevelData(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Level Data/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForMaterials(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Materials/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForModels(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Models/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForMods(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Mods/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForScripts(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Scripts/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForShaders(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Shaders/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForSounds(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Sounds/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::convertPathForTextures(std::string aFilename)
    {
        std::string path = getPathForResources();
        path.append("Textures/");
        path.append(aFilename);
        return path;
    }
    std::string FilePath::getPathForResources()
    {
        return "../../../Resources/";
    }
    
}