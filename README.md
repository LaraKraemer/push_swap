# Pushswap Project

![Pushswap Header](media/push_swap.png)


## Description
Pushswap is an algorithmic project at 42 School. It's main objectives is to sort a list of integers using two stacks and a limited set of operations. 

## Objectives
- Implement an efficient sorting algorithm using two stacks (`a` and `b`).
- Minimize the number of operations required to sort 100 and 500 numbers.
- Utilize a **radix sort** approach to achieve a good performance.

## Time Complexity
My implementation has a time complexity of:

```sh
O(n * k)
```
Where:
- n = number of elements (e.g., 100 or 500 numbers in your case).
- k = number of digits in the largest number (depends on the number range and base used).

In General:
Radix Sort works by sorting numbers digit by digit, typically using a stable sorting algorithm like Counting Sort (O(n)). Since it processes each digit separately, the total complexity is O(n * k). However, my implementation sorts indices instead of raw numbers, k is smaller (≈ log(n)), making my approach nearly O(n log n) in practice.

## Performance
My implementation achieves the following results:

- **100 Numbers:** **1,084 moves** → **3 points**
- **500 Numbers:** **6,784 moves** → **4 points**

### **Scoring Breakdown**
#### **100 Numbers:**
- ≤ 700 moves → **5 points**
- ≤ 900 moves → **4 points**
- ≤ 1100 moves → **3 points ✅**
- ≤ 1300 moves → **2 points**
- > 1300 moves → **1 point**

#### **500 Numbers:**
- ≤ 5500 moves → **5 points**
- ≤ 7000 moves → **4 points ✅**
- ≤ 8500 moves → **3 points**
- ≤ 10000 moves → **2 points**
- > 10000 moves → **1 point**

### **Final Score:** **84%** 

## How to Run
Compile the program and execute it with a list of numbers as arguments.

```sh
make
./push_swap <list of numbers>
```

### **Example Usage:**
```sh
./push_swap 5 2 8 3 1
```
This will output the necessary operations to sort the numbers using stack manipulations.

---

### Notes:
- The program only accepts **unique integers** as input.
- The output can be put into a checker to validate correctness:
  ```sh
  ARG="5 2 8 3 1"; ./push_swap $ARG | ./checker $ARG 
  ```

---

