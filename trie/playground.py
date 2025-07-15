from datastruct import Trie

t = Trie()
t.insert("car")
t.insert("cart")
t.insert("cat")
t.insert("dog")

print(f'word "cat" is in the Trie: {t.search("cat")}')

print(t.starts_with("ca"))  # ['car', 'cart', 'cat']
print(t.starts_with("dog"))  # ['dog']
print(t.starts_with("z"))    # []