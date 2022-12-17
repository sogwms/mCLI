includes("../base")

target("commander")
    set_kind("static")
    set_warnings("everything", "error")

    add_files("*.c")
    add_files("container/*.c")

    add_includedirs("./",  {public = true})
    add_includedirs("container",  {public = false})

    add_deps("base")
    set_policy("build.merge_archive", true)



