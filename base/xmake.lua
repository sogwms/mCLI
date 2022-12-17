target("base")
    set_kind("static")
    set_warnings("everything", "error")

    add_files("*.c")
    add_includedirs("./",  {public = true})
    add_headerfiles("*.h")


