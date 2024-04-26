project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDirs.ThurmyEngine}"
    }

    links
    {
        "ThurmyEngine"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        defines { "THURMY_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "THURMY_RELEASE" }
        runtime "Release"
        optimize "On"
