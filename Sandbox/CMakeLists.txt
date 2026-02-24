project(Sandbox)

set(SANDBOX_SOURCES
    src/Main.cpp
    src/SandboxApp.cpp
)

add_executable(Sandbox ${SANDBOX_SOURCES})

target_include_directories(Sandbox PRIVATE
    ${CMAKE_SOURCE_DIR}/Auralite/src
    ${CMAKE_SOURCE_DIR}/Auralite/vendor/spdlog/include
    # ${CMAKE_SOURCE_DIR}/Auralite/vendor
    # ${CMAKE_SOURCE_DIR}/Auralite/vendor/glm
)

target_link_libraries(Sandbox PRIVATE Auralite)

if (WIN32)
    target_compile_definitions(Sandbox PRIVATE AR_PLATFORM_WINDOWS)
endif()

target_compile_definitions(Sandbox PRIVATE
    $<$<CONFIG:Debug>:AR_DEBUG>
    $<$<CONFIG:Release>:AR_RELEASE>
    $<$<CONFIG:RelWithDebInfo>:AR_RELEASE>
)

if (MSVC)
    target_compile_options(Sandbox PRIVATE /utf-8)
endif()