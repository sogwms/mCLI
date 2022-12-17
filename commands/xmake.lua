includes("../base")

target("commands")
    set_kind("static")
    set_warnings("everything", "error")
    
    add_files("**/*.c")
    add_files("*.c")

    add_includedirs("./",  {public = true})

    add_deps("base")
    set_policy("build.merge_archive", true)



