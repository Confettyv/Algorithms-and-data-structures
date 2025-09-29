def peak_index_in_mountain_array(arr):
    if len(arr) < 3:
        return -1
    
    left, right = 0, len(arr) - 1
    
    while left < right:
        mid = (left + right) // 2
        
        if arr[mid] > arr[mid + 1]:
            right = mid
        else:
            left = mid + 1
    
    # Проверяем, что найденный пик действительно пик
    if left > 0 and left < len(arr) - 1 and arr[left - 1] < arr[left] > arr[left + 1]:
        return left
    else:
        return -1

# Тесты
print(peak_index_in_mountain_array([1, 3, 5, 4, 2]))  
print(peak_index_in_mountain_array([1, 2, 3, 2, 1]))  
print(peak_index_in_mountain_array([1, 2, 1]))        
print(peak_index_in_mountain_array([1, 2, 3]))       
print(peak_index_in_mountain_array([3, 2, 1]))      
print(peak_index_in_mountain_array([1, 2]))          