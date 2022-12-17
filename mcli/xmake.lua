includes("../commander")
includes("../controller")
includes("../commands")

target("mcli")
    set_kind("static")
    add_cflags("-pedantic", "-Wall",  "-pedantic-errors", {force=true})

    add_files("*.c")

    add_includedirs("./",  {public = true})

    add_headerfiles("*.h")
    add_headerfiles("../base/*.h")
    add_headerfiles("../base/(cdef/*.h)")

    add_deps("commander", "controller", "commands")
    set_policy("build.merge_archive", true)
