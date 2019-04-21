#!/usr/bin/python3
import pandas as pd

try:
    data = pd.read_csv("data.csv", dtype = "float")
except Exception as e:
    exit(e)
t0 = 0
t1 = 0

try:
    f = open('teta.txt')
    t0 = float(f.readline())
    t1 = float(f.readline())
except Exception as e:
    t0 = 0

mileage = input("Please enter a mileage :\n")
try:
    mileage = float(mileage)
    mileage = (mileage - min(data.km)) / (max(data.km) - min(data.km))
except Exception as e:
    exit(e)

print("Estimate price :")
price = t1 * mileage + t0
if price > 0:
    price = price * (max(data.price) - min(data.price)) + min(data.price)
print(price)