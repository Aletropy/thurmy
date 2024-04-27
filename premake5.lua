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
IncludeDirs["imgui"] = "%{wks.location}/vendor/imgui/"

include "vendor/glad"
include "vendor/glfw"
include "vendor/imgui"

include "ThurmyEngine"
include "Sandbox"