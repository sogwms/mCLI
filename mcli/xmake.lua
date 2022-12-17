includes("../commander")
includes("../controller")
includes("../commands")

target("mcli")
    set_kind("static")
    set_languages("c11")
    set_warnings("everything", "error")

    add_files("*.c")

    add_includedirs("./",  {public = true})

    add_headerfiles("*.h")
    add_headerfiles("../base/*.h")
    add_headerfiles("../base/(cdef/*.h)")

    add_deps("commander", "controller", "commands")
    set_policy("build.merge_archive", true)
