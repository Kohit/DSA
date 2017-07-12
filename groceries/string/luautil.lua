module ("luautil", package.seeall)

timer = 0

function tic()
    timer = os.clock()
end

function toc()
    print("time elapse:" .. (os.clock() - timer) .. "ms")
end


function writetable(table_, file_, indent, pspacing) 
	file_:write("{")
	local dospacing = (indent ~= nil) and true or false
	local pspacing = pspacing or ""
	local indent = indent or "\t"
	local spacing = pspacing .. indent
	if dospacing then file_:write("\n") end
	for key_, val in pairs(table_) do
		if dospacing then file_:write(spacing) end
		if (type(key_) == "string") then -- assume key_ is string or number
			file_:write("[\"")
			file_:write(key_)
			file_:write("\"]=") 
		else
			file_:write("[")
			file_:write(key_)
			file_:write("] =")
		end
		if (type(val) == "table") then
			if dospacing then 
				file_:write("\n")
				file_:write(spacing)
				writetable(val, file_, indent, spacing)
			else
				writetable(val, file_)
			end
		elseif (type(val) == "string") then
			file_:write("\"")
			file_:write(val)
			file_:write("\"")
		else
			file_:write(val)
			file_:write("")
		end
		file_:write(",")
		if dospacing then file_:write("\n") end
	end
	if dospacing then file_:write(pspacing) end
	file_:write("}")
end


