project(Auralite)

set(AURALITE_SOURCES
# Core
    # headers
    Source/Auralite/include/Auralite/Core.h
    Source/Auralite/include/Auralite/EntryPoint.h

    # src
    Source/Auralite/src/Log.cpp
    Source/Auralite/src/Application.cpp

    # Event system
    Source/Auralite/include/Auralite/Events/Event.h
    Source/Auralite/include/Auralite/Events/ApplicationEvent.h
    Source/Auralite/include/Auralite/Events/KeyEvent.h
    Source/Auralite/include/Auralite/Events/MouseEvent.h

# Platform
    # src
    Source/Platform/Windows/WindowsWindow.cpp
)

add_library(Auralite STATIC ${AURALITE_SOURCES})

target_precompile_headers(Auralite PUBLIC Source/arpch.h)

# Include directories
target_include_directories(Auralite PUBLIC
    # Engine includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Auralite/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Auralite/include/Core

    # Vendor includes
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    # ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
    # ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui
    # ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm
)

# Vendor subprojects
# add_subdirectory(vendor/GLFW)
# add_subdirectory(vendor/Glad)
# add_subdirectory(vendor/imgui)

# Link libraries
# target_link_libraries(Auralite PUBLIC
#     glfw
#     glad
#     imgui
# )

if (WIN32)
    target_link_libraries(Auralite PUBLIC opengl32)

    target_compile_definitions(Auralite PRIVATE
        AR_PLATFORM_WINDOWS
        AR_BUILD_DLL
        _WINDLL
        # GLFW_INCLUDE_NONE
        # _CRT_SECURE_NO_WARNINGS
    )
endif()

# Config-specific definitions
target_compile_definitions(Auralite PRIVATE
    $<$<CONFIG:Debug>:AR_DEBUG>
    $<$<CONFIG:Release>:AR_RELEASE>
    $<$<CONFIG:RelWithDebInfo>:AR_RELEASE>
)

# MSVC UTF-8
if (MSVC)
    target_compile_options(Auralite PRIVATE /utf-8)
endif()