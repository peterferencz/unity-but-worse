function includeGLFW()
    local glfw_src = path.getabsolute("vendor/glfw-3.4")
    local glfw_build = path.getabsolute("vendor/glfw-3.4/build")

    prebuildcommands {
        "mkdir -p " .. glfw_build,
        "cd " .. glfw_build .. " && cmake .. -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF",
        "cd " .. glfw_build .. " && cmake --build . --config Release"
    }

    libdirs { glfw_build .. "/src" }
    links { "glfw3" }
    
    includedirs {
        "vendor/glfw-3.4/include"
    }
end

function includeGlad()
    includedirs "vendor/glad/include"

    files "vendor/glad/src/gl.c"
end

function includeGLM()
    includedirs "vendor/glm"
end

function includeStb()
    includedirs "vendor/stb"
end

workspace "Project"
    configurations { "Debug", "Release" }
    architecture "x64"
    
    targetdir ("build/bin/%{prj.name}/%{cfg.longname}")
	objdir ("build/obj/%{prj.name}/%{cfg.longname}")

project "App"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    includedirs {
        "lib",
        "src"
    }


    files {
        "src/**.cpp",
        "src/**.hpp",
        "lib/**.h",
        "lib/**.hpp"
    }
    
    includeGLFW()
    includeGlad()
    includeGLM()
    includeStb()

    filter "system:windows"
        links { "opengl32" }
    
    filter "system:linux"
        links { "GL", "pthread", "dl" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"