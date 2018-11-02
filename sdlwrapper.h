#ifndef __SDLWRAPPER_H__
#define __SDLWRAPPER_H__

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <SDL2/SDL.h>
#include <utility>
#include <tuple>


namespace GTech  {

    void SDLInitialization(unsigned int GLMAJOR = 2, unsigned int GLMINOR = 1);
    void SDLQuit();
    void SDLDestroyWindow();



    SDL_Texture* SDLCreateTexture(SDL_Rect& rSize);
    SDL_Texture* SDLCreateTextureFromFile(const char* path);

    /*!
     * @brief Query a SDL_Texture, for format, access type and texture size.
     *
     * Format is one of the formats explained at https://wiki.libsdl.org/SDL_PixelFormatEnum. Access is one of https://wiki.libsdl.org/SDL_TextureAccess.
     * Texture size is a glm::ivec2 where x is width and y is height.
     *
     * @return Function returns a tuple of format, access and texture size.
     */
    std::tuple<uint32_t, int , glm::ivec2> SDLQueryTexture(SDL_Texture*);


    
    void SDLDetachRenderTexture();
    void SDLRenderClear();
    void SDLRenderCopy(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    void SDLRenderCopyEx(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, glm::vec3* anchorPoint);
    void SDLSetRenderTarget(SDL_Texture* pSDLTexture);
    void SDLUpdateScreen();
    std::pair<int, int> SDLWindowSize();

    /**
     * @brief      Get the count per second of the high resolution counter.
     *
     * @return     The number of ticks counted with the high resolution counter.
     */
    Uint64 SDLGetPerformanceFrequency();
    /**
     * @brief      Get the current value of the high resolution counter.
     *
     * @return     An unsigned int with the current value of the counter.
     */
    Uint64 SDLGetPerformanceCounter();
    /**
     * @brief      Get the number of milliseconds since the SDL library initialization.
     *
     * @return     An unsigned 32 bit number, with the number of ticks since the library was initialized.
     */
    Uint32 SDLGetTicks();

    /* --- Open Gl ---- */
    void SDLGlSwapWindow();


}



#endif //__SDLWRAPPER_H__