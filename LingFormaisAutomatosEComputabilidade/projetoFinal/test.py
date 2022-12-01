import string
lista = {"a","b","c","d","e"}

conjunto = {"c","l","f", "d", "g", "h", "1", "4"}

LUC = lista.union(conjunto)

dif = LUC.difference(lista)

print(set(sorted(conjunto)))