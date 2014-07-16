#ifndef OL_FILE_PATH_H
#define OL_FILE_PATH_H

#include <string>


namespace OnLooker
{
    class FilePath
    {
    public:
        /*
        *   Function: getInstance
        *   Return Type: FilePath
        *   Description: Singleton design accessor
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        static FilePath * getInstance();

        /*
        *   Function: destroy
        *   Return Type: void
        *   Description: Calls the destructor if allocated
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        static void destroy();
        /*
        *   Function: convertPathForIni
        *   Return Type: string
        *   Description: returns the path to the ini folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForIni(std::string aFilename);
        /*
        *   Function: convertPathForLevelData
        *   Return Type: string
        *   Description: returns the path to the Level Data folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForLevelData(std::string aFilename);
        /*
        *   Function: convertPathForMaterials
        *   Return Type: string
        *   Description: returns the path to the materials folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForMaterials(std::string aFilename);
        /*
        *   Function: convertPathForModels
        *   Return Type: string
        *   Description: returns the path to the models folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForModels(std::string aFilename);
        /*
        *   Function: convertPathForMods
        *   Return Type: string
        *   Description: returns the path to the mods folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForMods(std::string aFilename);
        /*
        *   Function: convertPathForScripts
        *   Return Type: string
        *   Description: returns the path to the scripts folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForScripts(std::string aFilename);
        /*
        *   Function: convertPathForShaders
        *   Return Type: string
        *   Description: returns the path to the shaders folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForShaders(std::string aFilename);
        /*
        *   Function: convertPathForSounds
        *   Return Type: string
        *   Description: returns the path to the sounds folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForSounds(std::string aFilename);
        /*
        *   Function: convertPathForTextures
        *   Return Type: string
        *   Description: returns the path to the textures folder inside resource
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string convertPathForTextures(std::string aFilename);
        /*
        *   Function: getPathForResources
        *   Return Type: string
        *   Description: returns the path to the resources folder
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        std::string getPathForResources();
    private:
        /*
        *   Function: FilePath
        *   Return Type: constructor
        *   Description: Instantiates the object
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        FilePath();
        /*
        *   Function: FilePath
        *   Return Type: destructor
        *   Description: Instantiates the object
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */  
        ~FilePath();
        //The instance of the class - singleton design
        static FilePath * s_Instance;
    };
}

#endif