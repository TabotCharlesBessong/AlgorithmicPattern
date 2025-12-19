from supplier import Supplier
from contact import Contact

c = Contact("John Doe", "john@doe.com")
s = Supplier("Jane Doe", "jane@doe.com")

print(c.name, c.email)
print(s.name, s.email)

print(c.all_contacts)
# print(s.all_contacts)