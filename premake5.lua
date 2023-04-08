workspace "Cage"
	architecture "x64"
	startproject "Sandbox"
	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Cage/vendor/GLFW/include"

-- includes GLFW premake file 
include "Cage/vendor/GLFW"

project "Cage"
	location "Cage"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%{prj.name}")

	pchheader "cgpch.h"
	pchsource "Cage/src/cgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW", -- linking to included project
		"opengl32.lib"
	}

	filter "system:windows"
		-- cppdialect "C++17"
		staticruntime "On" -- static linking of the runtime libraries
		systemversion "latest"

		defines
		{
			"CG_PLATFORM_WINDOWS",
			"CG_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines 
		{
			"CG_DEBUG",
			"CG_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		defines "CG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cage/vendor/spdlog/include",
		"Cage/src"
	}

	links
	{
		"Cage"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CG_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} ../bin/" .. outputdir .. "Cage/*.dll ../bin/" .. outputdir .. "Sandbox")
		}

	filter "configurations:Debug"
		defines 
		{
			"CG_DEBUG",
			"CG_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		defines "CG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CG_DIST"
		optimize "On"