from hello import bad_fun, Counter

count = Counter()
print(count.get())  # 0
count.incr()
count.incr()
print(count.get())  # 2

c2 = Counter(42)
print(c2.get())     # 42

c3 = Counter(17, factor=3)
c3.incr()
print(c3.get())     # 20

bad_fun()           # will throw an exception
