import random

def generate_test_data(num_tips, num_fruits):
    fruits = [f"{i:03d}" for i in range(1, num_fruits + 1)]
    tips = []
    prices = []

    # Generate tips (pairs of fruits that cannot be eaten together)
    while len(tips) < num_tips:
        f1, f2 = random.sample(fruits, 2)
        pair = f"{f1} {f2}"
        reverse_pair = f"{f2} {f1}"
        if pair not in tips and reverse_pair not in tips:
            tips.append(pair)
    
    # Generate prices for each fruit
    for fruit in fruits:
        price = random.randint(1, 100)  # Prices from 1 to 100
        prices.append(f"{fruit} {price}")

    return num_tips, num_fruits, tips, prices

# Example usage
num_tips = input("输入不能同时吃的水果数量： ")

num_fruits = input("输入所有的水果数量： ")
num_tips, num_fruits, tips, prices = generate_test_data(num_tips, num_fruits)

print(f"{num_tips} {num_fruits}")
for tip in tips:
    print(tip)
for price in prices:
    print(price)
