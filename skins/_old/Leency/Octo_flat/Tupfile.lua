if tup.getconfig("NO_FASM") ~= "" then return end
tup.rule("default.asm", 'fasm "%f" "%o" ' .. tup.getconfig("KPACK_CMD"), "Octo_flat.skn")
