project "glad"
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files
	{
		"src/glad.c",
		"include/glad/glad.h",
		"include/khr/khrplatform.h"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		links
		{
			"opengl32"
		}

	filter "system:linux"
		links
		{
			"GL"
		}

	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "NDEBUG" }
		runtime "Release"
		optimize "on"