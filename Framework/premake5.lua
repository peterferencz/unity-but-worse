project "Framework"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    
    includedirs {
        "lib",
        "src",
        "vendor/glad/include",
        "vendor/stb",
        _MAIN_SCRIPT_DIR .. "/SharedVendor/glm",
        _MAIN_SCRIPT_DIR .. "/SharedVendor/glfw/include"
    }

    libdirs {
        _MAIN_SCRIPT_DIR .. "/SharedVendor/glfw/lib",
        _MAIN_SCRIPT_DIR .. "/Build/glfw/src"
    }

    files {
        "src/**.cpp",
        "src/**.hpp",
        "lib/**.h",
        "lib/**.hpp",

        "vendor/glad/src/gl.c"
    }

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
    filter {}