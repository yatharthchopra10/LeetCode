# Introduction to the World of Hashing
The initial problem that we get is to find the frequency of an element in the array. In the Brute Force Approach we loop every element and count the number of times it occurs in the array. On the basis of the specified input, we print the actual number of occurrences in the array.

```C++
int countFre(int num, vector<int> &a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == num){  
            count++;
        }
    }
    return count;
}
```

In this piece of code, the Time Complexity runs down to O(QxN) where Q = number of elements searched by the user and the Space Complexity of this code is O(1).

# The Importance of Hashing and It's Need
Hashing is basically pre-storing and fetching in lame language. Mostly Hashing is used in forming a Better Solution in Arrays. Hashing simplifies and cuts down the Time Complexity to ~ O(2*N) but its drawback is that it increases the Space Complexity of the program to ~ O(N).
## Example 1: Using a hash array.

```C++
int countFre(int num, vector<int> &a){
    int n = a.size();
    int hash[n+1] = {0};
    for(int i = 0; i < n; i++){
        hash[a[i]]++;
    }
    return hash[num];
```

In this piece of code, a hash array is used to store the frequency of every element in the array (pre-storing) and then the frequency of the specific element is returned (fetching). While this method has its own limitations, but it reduces the Time Complexity than a Brute Force Solution. The Time Complexity of this piece of code is O(2*N), 1 O(N) to store the frequency of every element and another O(N) to fetch the frequency of the desired element.
**Note: The fetching part of the program will take place in the *main()* function anbd is therefore not shown here.**
A few of its limitations includes that the array can only store upto a particular size of the data type **int**, extreme alues such as 10^8 or 10^9 can not be stored in the array due to it's limit. The following table shows the limit of an array of the *int* dat-type and *bool* data-type.

| Data Type | Inside Main | Globally |
| :---: | :---: | :---: |
| int | 10^6 | 10^7 |
| bool | 10^7 | 10^8 |

This example is for accessing the elements of the data-type **int** but we can also use it for elements of the data-type **char** by using the ASCII code.

## Example 2: Using a hash map (map and unordered map)

```C++
int countFre(int num, vector<int> &a){
    map<int> mpp; // Can also use unordered map, details will be explained later.
    for(int i = 0; i < a.size(); i++){
        mpp[a[i]]++;
    }
    return mpp[num];
}
```

This method uses comparatively less space than a hash array because it stores only that element which occurs in the array and not from 0 to the size of array. The Time Complexity of this piece code is O(logN).

| Data Structure | Time Complexity(Storing and Fetching) |
| :---: | --- |
| Map | O(logN) in all three cases. |
| Unordered Map | O(1) in the best and average case, but O(N) in the worst case due to collisions. |

# HASHING: COLLISIONS, DIVISION RULE & MAP INTERNALS
The first preference should be unordered map but if we get **"Time Limit Exceeded (TLE)"** it would mean that there are collisions in the array and in that case we will have to use the map data structure (although very rare).
1. WHY INTERNAL HASHING IS NEEDED
- Array hashing cannot handle very large numbers (e.g., 10^9, 10^12, or 10^18) because array sizes are constrained by memory limits.
- Map data structures (such as C++ STL map and unordered_map, or Java HashMap) solve this by storing only the required key-value pairs dynamically instead of allocating huge contiguous arrays.
- Internally, hash maps rely on hashing functions to map large keys into bounded memory buckets. Common hashing techniques include:
  * Division Method
  * Folding Method
  * Mid-Square Method


2. THE DIVISION METHOD (CONCEPTUAL EXAMPLE)
Suppose you are restricted to a hash array of maximum size 10 (indices 0 through 9) and need to store and retrieve frequencies for the numbers: 2, 5, 16, 28, 139.

Mapping Keys (Modulo 10):
Each key is reduced to a valid index using (key % 10):
  * 2 % 10   = 2  -> stored at index 2
  * 5 % 10   = 5  -> stored at index 5
  * 16 % 10  = 6  -> stored at index 6
  * 28 % 10  = 8  -> stored at index 8
  * 139 % 10 = 9  -> stored at index 9

Fetching Values:
To query how many times 139 appears:
  1. Compute 139 % 10 = 9.
  2. Look up index 9 in the hash table to retrieve its stored frequency (1).


3. LINEAR CHAINING & COLLISIONS
What happens if multiple keys map to the exact same index?
Example: Hashing 18, 28, 38, and 48 using (key % 10) all yield index 8.

- Linear Chaining:
  Instead of overwriting values at index 8, elements hashing to the same index are linked together in a chain (typically implemented using linked lists or balanced structures). Keeping chains sorted allows fast lookups (such as binary search) within a bucket.

- Collisions:
  A collision occurs whenever multiple distinct keys hash to the exact same index/bucket.

- Worst-Case Scenario:
  If the internal hash function maps every single input key to the same index (e.g., all elements end up chained at index 8 while indices 0-7 and 9 remain empty), searching for an element requires traversing the entire chain of size N.


4. TIME COMPLEXITY OF UNORDERED_MAP
- Best Case:    O(1)
- Average Case: O(1)
- Worst Case:   O(N)  (where N is the number of elements in the map; occurs rarely due to severe internal collisions)

Practical Rule:
- Always prefer unordered_map first for O(1) average lookup and insertion.
- If a specific input triggers worst-case collisions causing a Time Limit Exceeded (TLE) error, switch to an ordered map (which guarantees O(log N) in all cases).
- Note: You do not need to manually implement chaining or collision handling from scratch—standard libraries handle this internally.


5. ALLOWED KEY TYPES: MAP VS. UNORDERED_MAP
- map (Ordered):
  Can use **ANY** data type or data structure as a key, including primitive types (int, double, char, string) as well as composite containers (e.g., pair<int, int>, vector<int>).

- unordered_map:
  Restricted strictly to individual/primitive data types (e.g., int, double, char, string). Composite data structures like pair<int, int> or vector<int> cannot be used as keys directly without a custom hash function.