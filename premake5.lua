workspace "Auralite"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories Relatives To Root Folder
--[[IncludeDir = {}
IncludeDir["spdlog"] = "Auralite/vendor/spdlog/include"
IncludeDir["GLFW"] = "Mofai/vendor/GLFW/include"
IncludeDir["Glad"] = "Mofai/vendor/Glad/include"
IncludeDir["ImGui"] = "Mofai/vendor/imgui"

include "Mofai/vendor/GLFW"
include "Mofai/vendor/Glad"
include "Mofai/vendor/imgui"
]]

project "Auralite"
    location "Auralite"
    kind "SharedLib"
    language "C++"
	staticruntime "off"

    filter "action:vs*"
        buildoptions { "/utf-8" }
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "arpch.h"
	pchsource "Auralite/src/arpch.cpp"


    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
        "%{prj.name}/src/Auralite/src",
		"%{prj.name}/src/Auralite/include",
		--"{IncludeDir}.spdlog"
		"%{prj.name}/vendor/spdlog/include"
		--[[
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"]]
	}

    --[[
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
    ]]

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines 
		{
			"AR_PLATFORM_WINDOWS",
			"AR_BUILD_DLL",
			"_WINDLL"
			--"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "AR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AR_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Auralite"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

        filter "action:vs*"
            buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Auralite/src",
		"Auralite/vendor/spdlog/include"
	}

	links
	{
		"Auralite"
	}


	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines 
		{
			"AR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AR_DIST"
		runtime "Release"
		optimize "On"