
from note import Note
from notebook import Notebook

n1 = Note("Hello, world!")
n2 = Note("Hello, world! again")
print(n1.id, n2.id)
print(n1.memo, n2.memo)
print(n1.tags, n2.tags)
print(n1.creation_date, n2.creation_date)
print(n1.match("Hello"))
print(n2.match("Hello"))
print(n1.match("world"))
print(n2.match("world"))
print(n1.match("Hello, world!"))
print(n2.match("Hello, world!"))

n = Notebook()
n.new_note("Hello, world!")
n.new_note("Hello, world! again")
print(n.notes)
print(n.search("Hello"))
print(n.search("world"))
print(n.search("Hello, world!"))
print(n.search("Hello, world! again"))
print(n.search("Hello, world! again"))