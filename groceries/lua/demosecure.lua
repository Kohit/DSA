module('demosecure', package.seeall)

function errfoo()
	error('errfoo',1)
end
print(pcall(errfoo))

a = 1 / 0  -- ok, a = 1.#INF

------loadstring etc.------
text = "]] .. os.execute('rm *') .. [["
str = '[[' .. text .. ']]'
print(str)
-----DANGER------
--loadstring(str)()
-----------------
str = string.format('%q', text) -- '%q' is very important
print(str)
print(loadstring(str))

text = "os.execute('rm *')"
str = string.format('%q', text)
print(str)
print(loadstring(str))

