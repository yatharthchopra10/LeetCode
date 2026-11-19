## 📂 PHASE 1: THE INITIAL THREAT (BRUTE FORCE)

**The Objective:** Determine how many times a specific target (`num`) appears inside an array of size $N$.

**The Amateur Approach:** You send an operative to interrogate every single person in the crowd from start to finish, counting matches one by one. For $Q$ different targets, you repeat this entire sweep from scratch.

```C++
int countFre(int num, vector<int> &a) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == num) {  
            count++;
        }
    }
    return count;
}
```

### Threat Assessment

* **Time Complexity:** $O(Q \times N)$. If $Q = 10^5$ and $N = 10^5$, your system executes $10^{10}$ operations. **Mission Failure (TLE).**

* **Space Complexity:** $O(1)$. Uses virtually no extra memory, but speed is compromised.

## 📂 PHASE 2: THE COUNTERMEASURE (HASHING)

**The Strategy:** **Pre-storing and Fetching.** Instead of searching blindly on demand, you run *one* reconnaissance sweep beforehand, log every target's frequency into an instant access ledger, and retrieve answers in real time.

* **The Trade-off:** Time complexity plummets to $\approx O(2 \times N)$ ($O(N)$ to pre-store, $O(1)$ per fetch), at the cost of $O(N)$ extra memory.

### Tactic A: The Hash Array (Direct Indexing)

You create a dedicated ledger (`hash[]`) where the index itself represents the target ID, and the value stored at that index is its frequency.

```C++
int countFre(int num, vector<int> &a) {
    int n = a.size();
    // Note: Array size must be at least (max_element + 1)
    int hash[n + 1] = {0}; 
    
    // Step 1: Pre-storing (Reconnaissance)
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
    
    // Step 2: Fetching (Typically executed inside main() for each query)
    return hash[num];
}
```

> **Note:** While this snippet tracks `int` targets, you can track `char` targets just as easily by mapping their **ASCII values** into a hash array of size `256`.

#### Critical Hardware Constraints

Arrays demand contiguous memory blocks. Extreme values like $10^8$ or $10^9$ will trigger a segmentation fault (memory crash). Know your exact clearance limits:

| Data Type | Inside `main()` | Globally Declared | 
| ----- | ----- | ----- | 
| **`int`** | $10^6$ | $10^7$ | 
| **`bool`** | $10^7$ | $10^8$ | 

### Tactic B: Dynamic Hash Maps (`map` & `unordered_map`)

When target IDs exceed array limits (e.g., $10^9$ or $10^{12}$), static arrays fail. You deploy C++ STL Maps, which are dynamic structures that allocate memory **only** for targets that actually appear in the field.

```C++
int countFre(int num, vector<int> &a) {
    map<int, int> mpp; // Can also deploy unordered_map<int, int>
    for (int i = 0; i < a.size(); i++) {
        mpp[a[i]]++;
    }
    return mpp[num];
}
```

#### Performance Comparison

| Data Structure | Time Complexity (Storing & Fetching) | 
| ----- | ----- | 
| **`map`** | $O(\log N)$ across best, average, and worst cases. | 
| **`unordered_map`** | $O(1)$ in best/average cases, but $O(N)$ **in the worst case** due to collisions. | 

> **Field Rule:** Always deploy `unordered_map` first for $O(1)$ speed. If a hostile test case triggers a **Time Limit Exceeded (TLE)** error, immediately fall back to `map`.

## 📂 PHASE 3: CLASSIFIED INTERNALS (COLLISIONS & DIVISION RULE)

### 1. Why Internal Hashing Exists

Because memory cannot allocate an array of size $10^{18}$, hash maps compress massive keys into bounded memory buckets using mathematical hashing functions:

* **Division Method**

* **Folding Method**

* **Mid-Square Method**

### 2. The Division Method (`key % M`)

Imagine your safe house only has **10 lockers** (indices `0` through `9`), and you must store intel for keys: `2, 5, 16, 28, 139`.

* **Storing (Modulo 10):**

  * `2 % 10 = 2` $\rightarrow$ Locker `2`

  * `5 % 10 = 5` $\rightarrow$ Locker `5`

  * `16 % 10 = 6` $\rightarrow$ Locker `6`

  * `28 % 10 = 8` $\rightarrow$ Locker `8`

  * `139 % 10 = 9` $\rightarrow$ Locker `9`

* **Fetching `139`:** Compute `139 % 10 = 9` $\rightarrow$ Open Locker `9` $\rightarrow$ Retrieve frequency (`1`).

### 3. Collisions & Linear Chaining

What happens if incoming targets are `18, 28, 38, 48`? Every single one hashes to **Locker `8`**.

* **Collision:** When multiple distinct keys resolve to the exact same memory bucket.

* **Linear Chaining:** Instead of overwriting data in Locker `8`, the system attaches a sorted chain (like a linked list or balanced tree) to that locker so all colliding keys coexist safely. *(Handled automatically by C++ STL; no manual coding required.)*

* **The Worst-Case Trap:** If an adversary crafts an input where *every* element collides into Locker `8`, your $O(1)$ lookup degrades into a linear search through a chain of length $N$, resulting in $O(N)$ time complexity and a **TLE**.

### 4. Key Clearance Rules (`map` vs. `unordered_map`)

* **`map` (Ordered):** Accepts **any** data type or container as a key, including primitives (`int`, `double`, `char`, `string`) as well as composite structures (`pair<int, int>`, `vector<int>`).

* **`unordered_map`:** Strictly restricted to primitive/individual data types (`int`, `double`, `char`, `string`). Composite structures like `pair<int, int>` cannot be used as keys without writing a custom hash function.

## 🎯 60-SECOND REVISION CHECKLIST

1. **Brute Force:** $O(Q \times N)$ time, $O(1)$ space.

2. **Hash Array:** $O(N)$ time, $O(N)$ space. Max size: $10^6$ (`int` in `main`), $10^7$ (`int` global).

3. **`unordered_map`:** $O(1)$ avg, $O(N)$ worst case (collisions). Only primitive keys.

4. **`map`:** $O(\log N)$ always. Supports any key type (including `pair`). Use when `unordered_map` gives TLE.