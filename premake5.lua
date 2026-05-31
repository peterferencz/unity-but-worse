--
-- Configuration
--

local BUILD_DIR = path.getabsolute("Build")
local FRAMEWORK_DIR = path.getabsolute("Framework")

--
-- Helper functions
--

function prebuildGLFW()
    local glfw_src = path.getabsolute(_MAIN_SCRIPT_DIR .. "/SharedVendor/glfw")
    local glfw_build = path.getabsolute(BUILD_DIR .. "/glfw")

    prebuildcommands {
        "mkdir -p " .. glfw_build,
        "cmake -S ".. glfw_src .. " -B " .. glfw_build .. " -D GLFW_LIBRARY_TYPE=STATIC -D GLFW_BUILD_DOCS=OFF -D GLFW_BUILD_EXAMPLES=OFF -D GLFW_BUILD_TESTS=OFF",
        "cmake --build " .. glfw_build .. " --config Release"
    }
end

-- 
-- Workspace / Projects
-- 

workspace "OpenGLFramework"
    configurations { "Debug", "Release" }
    architecture "x64"
    location (BUILD_DIR)

    prebuildGLFW()
    
    targetdir (BUILD_DIR .. "/%{prj.name}/%{cfg.longname}/bin")
	objdir (BUILD_DIR .. "/%{prj.name}/%{cfg.longname}/obj")

include "Framework"
include "Examples/ShootingGame"
