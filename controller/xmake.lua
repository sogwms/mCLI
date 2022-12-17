includes("../base")

target("controller")
    set_kind("static")
    set_warnings("everything", "error")

    add_files("*.c")

    add_includedirs("./",  {public = true})
    add_headerfiles("*.h")

    add_deps("base")
    set_policy("build.merge_archive", true)




