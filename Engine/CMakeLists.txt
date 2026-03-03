project(Auralite)

set(AURALITE_SOURCES

# Core
    # headers
    Source/Auralite/include/Core/Core.h
    Source/Auralite/include/Core/EntryPoint.h
    Source/Auralite/include/Core/Layer.h
    Source/Auralite/include/Core/LayerStack.h

    # src
    Source/Auralite/src/Core/Log.cpp
    Source/Auralite/src/Core/Application.cpp
    Source/Auralite/src/Core/Layer.cpp
    Source/Auralite/src/Core/LayerStack.cpp

    # Event system
    Source/Auralite/include/Events/Event.h
    Source/Auralite/include/Events/ApplicationEvent.h
    Source/Auralite/include/Events/KeyEvent.h
    Source/Auralite/include/Events/MouseEvent.h

# ImGui
    Source/Auralite/src/ImGui/ImGuiLayer.cpp

# Platform
    Source/Platform/Windows/WindowsWindow.cpp
    Source/Platform/OpenGL/ImGuiOpenGLRenderer.cpp

# Vendors
    #Glad
    vendor/Glad/src/glad.c

    #ImGui
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/backends/imgui_impl_glfw.cpp
    vendor/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(Auralite STATIC ${AURALITE_SOURCES})

target_precompile_headers(Auralite PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/Source/arpch.h>"
)

# Include directories
target_include_directories(Auralite PUBLIC
    # Engine includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Auralite/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Auralite/include/ImGui
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Auralite/include/Core

# Vendor includes
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui
    # ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm
)

# Vendor subprojects
# add_subdirectory(vendor/GLFW)
# add_subdirectory(vendor/Glad)
# add_subdirectory(vendor/imgui)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Link libraries
target_link_libraries(Auralite PUBLIC
    glfw
    OpenGL::GL
)

if (WIN32)

    target_link_libraries(Auralite PUBLIC opengl32)

    target_compile_definitions(Auralite PRIVATE
        AR_PLATFORM_WINDOWS
        AR_BUILD_DLL
        _WINDLL
        _CRT_SECURE_NO_WARNINGS
    )

elseif(UNIX)

    target_compile_definitions(Auralite PRIVATE
        AR_PLATFORM_LINUX
    )

endif()

target_compile_definitions(Auralite PRIVATE
    GLFW_INCLUDE_NONE
)

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
