function derivative(f, delta)
	delta = delta or 1e-8	-- accuracy (lim delta -> 0)
	return function (x)
				return (f(x + delta) - f(x)) / delta 
				-- closure(cos = return function(x) ...  end, cos contains function and the non-local variable 'delta')
			end
end
cos = derivative(math.sin)
print(math.cos(10), cos(10))


function getrand()
    local seed = tonumber(tostring(os.time()):reverse():sub(1,6))
    -- http://lua-users.org/wiki/MathLibraryTutorial
    math.randomseed(seed) -- init
    return function(...) 
        return math.random(...)
    end
end

rand = getrand()
print(rand(6, 15), rand(6, 15), rand(6, 15), rand(), rand(), rand(6), rand(6))

----compare-----
for i = 1,10 do 
    print(math.random(10))
end

print(1 / 0)  -- ok 1.#INF
print(0 / 0)  -- ok -1.#IND (NaN)
a = 1 / 0
print(a <= 1, a >= 1, a and 1) -- false	true	1

a = 0 / 0
print(a <= 1, a >= 1, a and 1 or 0) -- false	false	1


 



    