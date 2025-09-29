def binary_search(lst, key):
    low, high = 0, len(lst) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if lst[mid] == key:
            return mid
        if lst[mid] > key:
            high = mid - 1
        else:
            low = mid + 1
    
    lst.insert(low, key)
    return low

a = [1, 2, 3, 4, 5, 6, 7]

# поиск существующего элемента
result = binary_search(a, 4)
print(f"Найден на позиции: {result}") if result < len(a) and a[result] == 4 else print(f"Вставлен на позицию: {result}")
print("Массив:", a)

# поиск несуществующего элемента
result = binary_search(a, 8)
print(f"Найден на позиции: {result}") if result < len(a) and a[result] == 8 else print(f"Вставлен на позицию: {result}")
print("Массив:", a)