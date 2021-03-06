cmake_minimum_required( VERSION 3.0 )

project(keypet)

SET(SDL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/SDL/include)
SET(SDL_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/SDL)
SET(SDL_IMG_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/SDL_image)

file( GLOB SRCS 
    src/*.c 
    src/*.cpp 
    src/*.h 
    src/*.hpp 
)

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_dependencies(SDL2_image SDL2)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_executable( ${PROJECT_NAME} ${SRCS} )
    else()
        add_executable( ${PROJECT_NAME} WIN32 ${SRCS} )
    endif()
else()
    add_executable( ${PROJECT_NAME} ${SRCS} )
endif()

target_link_libraries( ${PROJECT_NAME} PUBLIC 
    SDL2
    SDL2main
    SDL2_image
)

target_include_directories( ${PROJECT_NAME} PUBLIC
    ${SDL_INCLUDE_DIR},
    external/SDL_image,
    external/include
)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Copying debug DLL.")
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_LIB_DIR}/SDL2d.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_IMG_LIB_DIR}/external/libpng-1.6.37/libpng16d.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_IMG_LIB_DIR}/external/zlib-1.2.11/zlibd1.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    else()
        message("Copying release DLL.")
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_LIB_DIR}/SDL2.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_IMG_LIB_DIR}/external/libpng-1.6.37/libpng16.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
        add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL_IMG_LIB_DIR}/external/zlib-1.2.11/zlib1.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endif()

    add_custom_command ( TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SDL_IMG_LIB_DIR}/SDL2_image.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)