target("mcli")
    -- set_kind("object")
    -- set_warnings("everything", "error")

    add_files("src/*.c")
    add_includedirs("./",  {public = true})
    add_headerfiles("*.h")
    add_headerfiles("(cdef/*.h)")



