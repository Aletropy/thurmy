workspace "Thurmy"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release"
    }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["ThurmyEngine"] = "%{wks.location}/ThurmyEngine/src"
IncludeDirs["glfw"] = "%{wks.location}/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/vendor/glad/include"

include "vendor/glad"
include "vendor/glfw"

include "ThurmyEngine"
include "Sandbox"