-- project
set_project("mcli")

set_version("0.1.1")
-- language standard
set_languages("c11")

-- compiler settings: strongest
set_warnings("everything", "error")

includes("../commander")
includes("../controller")
includes("../editor")
includes("../commands")


target("mcli")
    set_kind("static")

    add_files("*.c")

    add_includedirs("./",  {public = true})

    add_headerfiles("*.h")
    add_headerfiles("../base/*.h")
    add_headerfiles("../base/(cdef/*.h)")

    add_deps("commander", "controller", "commands", "editor", {private = true})
    set_policy("build.merge_archive", true)
