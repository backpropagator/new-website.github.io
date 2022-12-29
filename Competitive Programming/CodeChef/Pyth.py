mod = 1000000000+7
ti = input()
t = int(ti)
for _ in range(t):
	ni = input()
	ki = input()
	n = int(ni)
	k = int(ki)
	a = k-1
	d = n-1
	st = a%d
	p = ((a-st)/d + 1)
	t1 = st+a
	t2=0
	t3=0
	if t1%2 == 0:
		t2 = t1/2
		t3 = p
	else:
		t2 = p/2
		t3 = t1
	ans = (t2%mod * t3%mod)%mod
	print(int(ans))
