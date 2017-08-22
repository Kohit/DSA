require('socket')
host = 'www.w3.org'
file = '/TR/REC-html32.html'
c = assert(socket.connect(host, 80))
c:send("GET "..file.." HTTP/1.0\r\n\r\n")
c:settimeout(0)	-- set to receive data from buffer
print(c:receive(2^10))	-- time out, not block, still receiving data to buffer
a = "a"
for i = 1,100000 do a = a.."a".."a" end -- do other things e.g. busy wait
print(c:receive(2^20))	-- receive data from buffer with size up to 1M, not blcok
count = 0
while true do
	--c:settimeout(0)
	local s, stat, partial = c:receive(2^10)
	--io.write(s or partial)
	count = count + #(s or partial)
	if stat == 'closed' then break end
end
print(count)