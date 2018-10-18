#CMAKE TO MAKE A STATIC LIBRARY
#HEADER
cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)
set(TARGET_NAME sdlwrapper)
project(${TARGET_NAME})
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 17)

#Installation directory 
get_filename_component(GTECH_DIR $ENV{GTECH_ROOT} ABSOLUTE)
set(GTECH_DIR_LIB ${GTECH_DIR}/3rd/lib/)
set(GTECH_DIR_INC_SDLWRAPPER ${GTECH_DIR}/3rd/include/SDLWrapper)
set(GTECH_DIR_INC_SDL2 ${GTECH_DIR}/3rd/include/SDL2)
#DIRECTORIES
get_filename_component(ROOT_DIR "." ABSOLUTE)
message(STATUS "-----------------------------")
message(STATUS "SYSTEM NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "ROOT_DIR: ${ROOT_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "-----------------------------")

#GLM
set(GLM_DIR "${GTECH_DIR}/GLM")

#SDL
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/3rd/include)

add_library(${TARGET_NAME} STATIC
    ${CMAKE_SOURCE_DIR}/sdlwrapper.cpp 
)
set(INC_DIR_SET 
	${GLM_DIR}
	${SDL2_DIR}
)

target_include_directories(${TARGET_NAME} PUBLIC 
	${INC_DIR_SET}    
)
message(STATUS "-----------------------------")
message(STATUS "INCLUDE_DIRECTORIES: ${INC_DIR_SET}")
message(STATUS "-----------------------------")



file(MAKE_DIRECTORY ${GTECH_DIR_LIB})
file(MAKE_DIRECTORY ${GTECH_DIR_INC_SDLWRAPPER})
file(MAKE_DIRECTORY ${GTECH_DIR_INC_SDL2})


#POST BUILD COMMANDS 
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_AR} qc lib${TARGET_NAME}.a ${CMAKE_BINARY_DIR}/CMakeFiles/sdlwrapper.dir/sdlwrapper.cpp.o ${CMAKE_SOURCE_DIR}/3rd/lib/libSDL2.a ${CMAKE_SOURCE_DIR}/3rd/lib/libSDL_image.a    
	COMMAND ${CMAKE_RANLIB} lib${TARGET_NAME}.a  
	COMMAND ${CMAKE_COMMAND} -E copy lib${TARGET_NAME}.a ${GTECH_DIR_LIB}
	COMMAND ${CMAKE_COMMAND} -E copy ${ROOT_DIR}/*.h ${GTECH_DIR_INC_SDLWRAPPER}
	COMMAND ${CMAKE_COMMAND} -E copy ${ROOT_DIR}/3rd/include/SDL2/* ${GTECH_DIR_INC_SDL2}	
    ) 

