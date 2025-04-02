# Exercise 1 - Basic List Operations
cities = ["Los Angeles", "New York", "Seattle", "Chicago", "Houston"]
cities.append("Miami")
cities.remove("Los Angeles")
print(cities)


# Exercise 2 - Tuples vs. Lists
items = ("apple", "banana", "grape")
# items.append("orange")  # This will raise an AttributeError because tuples are immutable
# items[1] = "orange"  # This will raise a TypeError because tuples are immutable
print("full", items)
print("1", items[0])
print("2", items[1])
print("3", items[2])


# Exercise 3 - Unique Elements with Sets
not_unique_list = [1, 2, 3, 4, 5, 1, 2, 3]
unique_set = set(not_unique_list)
print(f"Original list: {not_unique_list} -> Unique values: {list(unique_set)}")


# Exercise 4 - Dictionary Lookup
people = {
    "Alice": 25,
    "Bob": 30,
    "Charlie": 35
}
def get_age(name):
    return people.get(name.capitalize(), "Name not found")

print("Alice:", get_age("Alice"))
print("Bobby:", get_age("Bobby"))


# Exercise 5 - Merging Dictionaries
dict1 = {"a": 1, "b": 2}
dict2 = {"b": 3, "c": 4}

def merge_dicts(d1, d2):
    merged_dict = {**d1, **d2}
    for key, value in d1.items():
        if key in d2 and d2[key] > value:
            merged_dict[key] = d2[key]
    return merged_dict

def suggested_merge_dicts(d1, d2):
    return {
        k: max(d1.get(k, 0), d2.get(k, 0)) for k in set(d1) | set(d2)
    }

print(merge_dicts(dict1, dict2))
