


# javascript_times = [
#     20.843994140625, 22.69798046875, 20.5, 14.073974609375, 19.75857421875, 
#     20.62109375, 21.56396484375, 20.5, 25.5390625, 20.73291015625, 
#     30.420166015625, 20.73291015625, 21.56396484375, 15.126953125, 
#     14.826904296875, 18.18408203125, 8.467041015625, 20.47412109375, 
#     14.489013671875, 24.595947265625
# ]

# webassembly_times = [
#     5.223876953125, 4.89501953125, 5.591064453125, 4.697021484375, 
#     4.98291015625, 6.93017578125, 6.72509765625, 7.986083984375, 
#     4.824951171875, 4.702880859375, 7.986083984375, 6.66015625, 
#     7.31298828125, 11.39501953125, 7.31298828125, 11.39501953125, 
#     5.031005859375, 4.824951171875, 5.031005859375, 4.779052734375
# ]

# percentage_improvement = [
#     ((js - wasm) / js) * 100 for js, wasm in zip(javascript_times, webassembly_times)
# ]

# average_improvement = sum(percentage_improvement) / len(percentage_improvement)
# print(average_improvement)


def is_subset_or_superset(set1, set2):
    """
    Returns True if set1 contains set2 or vice versa.
    """
    return set1.issuperset(set2) or set2.issuperset(set1)

# print(is_subset_or_superset(set1, set2))

def replace_odds():
    pass

set1 = {1,3,2,5}
set2 = {1,2,3}

numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

odd_number = { n for n in numbers if n % 2 != 0}
numbers -= odd_number
print(odd_number)

for odd in odd_number:
    numbers.add(odd + 1 + 100)
    
print(numbers)


