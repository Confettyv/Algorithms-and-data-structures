def count_positive_negative_simple(arr):
    left, right = 0, len(arr) - 1
    
    # Ищем индекс первого неотрицательного числа
    first_non_negative = len(arr)
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] >= 0:
            first_non_negative = mid
            right = mid - 1
        else:
            left = mid + 1
    
    neg_count = first_non_negative
    non_neg_count = len(arr) - first_non_negative
    
    if non_neg_count > neg_count:
        return f"Больше неотрицательных: {non_neg_count}"
    elif neg_count > non_neg_count:
        return f"Больше отрицательных: {neg_count}"
    else:
        return f"Одинаково: {neg_count}"

# Тесты
print(count_positive_negative_simple([-5, -3, -1, 2, 4, 6]))
print(count_positive_negative_simple([-5, -3, -1, 0, 0, 2]))  
print(count_positive_negative_simple([-2, -1, 1, 2]))         # Одинаково: 2