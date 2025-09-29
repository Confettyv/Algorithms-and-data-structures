def count_smaller(nums):
    if not nums:
        return []
    
    n = len(nums)
    counts = [0] * n
    sorted_nums = []
    
    # с конца массива
    for i in range(n-1, -1, -1):
        # Бинарный поиск для вставки nums[i] в другую часть
        left, right = 0, len(sorted_nums)
        
        while left < right:
            mid = (left + right) // 2
            if sorted_nums[mid] < nums[i]:
                left = mid + 1
            else:
                right = mid
        
        counts[i] = left
        sorted_nums.insert(left, nums[i])
    
    return counts

# Тесты
print(count_smaller([5, 2, 6, 1]))  
print(count_smaller([-1]))          
print(count_smaller([-1, -1]))      
print(count_smaller([3, 2, 1]))     
print(count_smaller([1, 2, 3]))  