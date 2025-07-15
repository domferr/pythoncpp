# Our first library!

Let's create a library which name is `hello`, it provides a `Counter` class and a dummy method `bad_fun` that just raises an exception:
```python
from hello import Counter, bad_fun

count = Counter()
print(count.get())   # 0
count.incr()
count.incr()
print(count.get())   # 2

c2 = Counter(42)
print(c2.get())  # 42

bad_fun() # will throw an exception
```

Remember: Python's garbage collector uses **Reference Counting**!
- Each object has a reference count
- The garbage collector deletes from memory the objects with reference count of 0
- We need to increase or decrease the reference count accordingly!