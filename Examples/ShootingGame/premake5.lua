project "ShootingGame"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"

    files {
        "src/**.cpp",
        "src/**.hpp",
        "lib/**.h",
        "lib/**.hpp"
    }

    includedirs {
        "lib",
        "src",

        _MAIN_SCRIPT_DIR .. "/Framework/lib",
        _MAIN_SCRIPT_DIR .. "/SharedVendor/glm"
    }
    links {
        "Framework",
        "glfw3"
    }

    libdirs {
        _MAIN_SCRIPT_DIR .. "/SharedVendor/glfw/lib",
        _MAIN_SCRIPT_DIR .. "/Build/glfw/src"
    }

    filter { "system:windows" }
		links { "opengl32" }

	filter { "system:linux" }
		links { "GL", "pthread", "dl" }
    
    filter {}