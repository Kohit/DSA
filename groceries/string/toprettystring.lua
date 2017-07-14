-- -*- coding: utf-8 -*-
--[[
    A hight efficiency replacement of prettytostring in base.lua in stdlib-27

    version: 2017/7/14
    Author: kohit (https://github.com/Kohit)
]]

---
-- @param value object to convert to string
-- @param indent indent char for spacing, e.g. '\t', nil means no spacing
-- @param pspacing parent spacing in recursion call, just leave it empty
--[[ e.g.
	require("toprettystring") -- please makesure toprettystring.lua is in the same dirctory
    local table_ = { ["foo"] = {1, 2, 3}, "foo" }
    print( toprettystring(table_, '\t') )
    you will get the output:
    {
        [1] = "foo",
        ["foo"] =
        {
            [1] = 1,
            [2] = 2,
            [3] = 3,
        },
    }
    or
    print( toprettystring(table_) ) -- no pretty printing
    output:
    {[1]="foo",["foo"]={[1]=1,[2]=2,[3]=3,},}
]]
function toprettystring(value, indent, pspacing) 
	if value == nil then 
		return "nil"
	elseif type(value) == "string" then
		return string.format("%q", value)
	elseif type(value) ~= "table" then
		return value
	end
	local result = { }
	result[#result + 1] = "{"
	local dospacing = (indent ~= nil) and true or false
	local pspacing = pspacing or ""
	local indent = indent or "\t"
	local spacing = pspacing .. indent
	if dospacing then result[#result + 1] = "\n" end
	for key_, val_ in pairs(value) do
		if dospacing then result[#result + 1] = spacing end
		if type(key_) == "string" then -- assume key_ is string or number
			if dospacing then
				result[#result + 1] = string.format("[%q] =", key_)
			else
				result[#result + 1] = string.format("[%q]=", key_)
			end
		else -- number
			if dospacing then
				result[#result + 1] = "[" .. key_ .. "] ="
			else
				result[#result + 1] = "[" .. key_ .. "]="
			end
		end
		if (type(val_) == "table") then
			if dospacing then 
				result[#result + 1] = "\n" .. spacing
				result[#result + 1] = toprettystring(val_, indent, spacing)
			else
				result[#result + 1] = toprettystring(val_)
			end
		elseif (type(val_) == "string") then
			if dospacing then
				result[#result + 1] = string.format(" %q", val_)
			else
				result[#result + 1] = string.format("%q", val_)
			end
		else
			if dospacing then
				result[#result + 1] = " " .. val_
			else
				result[#result + 1] = val_
			end
		end
		result[#result + 1] = ","
		if dospacing then result[#result + 1] = "\n" end
	end
	if dospacing then result[#result + 1] = pspacing end
	result[#result + 1] = "}"
	return table.concat(result)
end
