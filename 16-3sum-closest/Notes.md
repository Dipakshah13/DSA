<h2>Time Taken : 19:59 mins</h2>

# 3Sum Closest — Study Notes

## 1. Problem Statement

Given an integer array `nums` and an integer `target`, find three numbers from different indices whose sum is as close as possible to `target`.

Return the sum of those three numbers.

Example:

```text
nums = [-1, 2, 1, -4]
target = 1

Closest triplet: -1 + 2 + 1 = 2
Answer: 2
```

Here, `2` is only `1` away from `1`, which is the minimum possible distance.

---

## 2. Core Idea

The brute force method checks all triplets, but it is too slow for larger arrays.

A better approach is:

- Sort the array first
- Fix one element (`i`)
- Use two pointers (`left` and `right`) on the remaining elements
- Keep track of the closest sum found so far

This reduces the search from `O(n³)` to `O(n²)`.

---

## 3. Why Sorting Helps

After sorting, the array becomes ordered.

- If `current_sum < target`, then the sum is too small, so we move `left` to the right to increase the value.
- If `current_sum > target`, then the sum is too large, so we move `right` to the left to decrease the value.
- If `current_sum == target`, we can return immediately because it is an exact match.

Because the array is sorted, pointer movement becomes predictable and efficient.

---

## 4. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Sort the array]
    B --> C[Initialize closest_sum with first valid triplet]
    C --> D[i = 0]
    D --> E{i < n - 2?}
    E -- No --> Z[Return closest_sum]
    E -- Yes --> F[left = i + 1, right = n - 1]
    F --> G{left < right?}
    G -- No --> H[i = i + 1]
    H --> E
    G -- Yes --> I[current_sum = nums[i] + nums[left] + nums[right]]
    I --> J{Is current_sum closer to target?}
    J -- Yes --> K[Update closest_sum]
    J -- No --> L{current_sum == target?}
    K --> L
    L -- Yes --> M[Return current_sum]
    L -- No --> N{current_sum < target?}
    N -- Yes --> O[left = left + 1]
    N -- No --> P[right = right - 1]
    O --> G
    P --> G
```

This flowchart shows the complete decision process: fix an element, scan with two pointers, update the best answer, and move the pointer in the correct direction.

---

## 5. Algorithm

1. Sort the array.
2. Initialize `closest_sum` with the sum of the first valid triplet.
3. For each index `i` from `0` to `n - 3`:
   - Set `left = i + 1`
   - Set `right = n - 1`
   - While `left < right`:
     - Compute `current_sum = nums[i] + nums[left] + nums[right]`
     - Update `closest_sum` if this sum is closer to the target
     - If `current_sum < target`, increment `left`
     - If `current_sum > target`, decrement `right`
     - If `current_sum == target`, return `current_sum` immediately
4. Return `closest_sum`

---

## 6. Pseudocode

```text
function threeSumClosest(nums, target):
    sort(nums)
    closest = nums[0] + nums[1] + nums[2]

    for i from 0 to n - 3:
        left = i + 1
        right = n - 1

        while left < right:
            current = nums[i] + nums[left] + nums[right]

            if abs(current - target) < abs(closest - target):
                closest = current

            if current == target:
                return current

            if current < target:
                left += 1
            else:
                right -= 1

    return closest
```

---

## 7. Step-by-Step Example

Input:

```text
nums = [-1, 2, 1, -4]
target = 1
```

Sorted array:

```text
[-4, -1, 1, 2]
```

Initialize:

```text
closest_sum = -4 + (-1) + 1 = -4
```

Now evaluate:

| i | left | right | current_sum | difference | action |
|---|---:|---:|---:|---:|---|
| 0 | 1 | 3 | -3 | 4 | update answer |
| 0 | 2 | 3 | -1 | 2 | update answer |
| 1 | 2 | 3 | 2 | 1 | update answer |

Final result:

```text
2
```

---

## 8. Why This Works

The key idea is that after sorting, moving the pointers changes the sum in a controlled way:

- `left` moves right → values increase → sum increases
- `right` moves left → values decrease → sum decreases

So for each fixed `i`, we are efficiently searching the best pair on the remaining range.

We keep updating the answer whenever a triplet comes closer to the target than the current best one.

If an exact match is found, we can stop immediately because no value can be closer than the target itself.

---

## 9. Time and Space Complexity

| Metric | Complexity |
|---|---|
| Sorting | `O(n log n)` |
| Outer loop + two-pointer search | `O(n²)` |
| Total time | `O(n²)` |
| Extra space | `O(1)` |

The dominant cost is the nested pointer scan, so overall complexity is `O(n²)`.

---

## 10. Important Notes / Pitfalls

- Always initialize `closest_sum` with a valid triplet sum, not with `0`.
- Do not return early for a non-exact match; only return immediately when `current_sum == target`.
- The answer must be a single integer sum, not a triplet or list.
- Sorting is essential for the two-pointer strategy.
- Use `abs(current_sum - target)` carefully, especially for large integers.

---

## 11. Comparison: 3Sum vs 3Sum Closest

| Feature | 3Sum | 3Sum Closest |
|---|---|---|
| Goal | Find triplet summing to target | Find triplet closest to target |
| Return type | List of triplets | Single integer sum |
| Exact match | Usually required | Can stop early when exact |
| Duplicate handling | Often important | Less critical |

---

## 12. Interview-Friendly Explanation

> I sort the array first so that I can use two pointers efficiently. Then I fix one element and search the remaining part of the array for the pair whose sum is closest to the target. At each step, I compare the current triplet sum with the best answer so far. If the sum is too small, I move the left pointer rightward; if it is too large, I move the right pointer leftward. This gives an overall time complexity of `O(n²)`.

---

## 13. Memory Trick

> Fix → Point → Sum → Update → Move

1. Fix one element with `i`
2. Point using `left` and `right`
3. Sum the triplet
4. Update the closest result
5. Move the pointer according to the comparison with the target

---

## 14. Final Summary

3Sum Closest is a classic optimized variation of the 3Sum problem. The combination of sorting and two pointers makes it efficient and elegant.

The algorithm is:

- Sort
- Fix one element
- Use two pointers
- Track the closest sum
- Return the best result

This gives a clean solution with `O(n²)` time complexity and `O(1)` extra space.

---

## 15. Quick Example Output

```text
Input:  nums = [-1, 2, 1, -4], target = 1
Output: 2
```

This is the sum of the triplet `(-1, 2, 1)`, which is closest to the target.
