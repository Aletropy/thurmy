project "ThurmyEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glfw}"
    }

    links
    {
        "glad",
        "glfw"
    }

    filter "configurations:Debug"
        defines { "THURMY_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "THURMY_RELEASE" }
        runtime "Release"
        optimize "On"
