## 3912. Valid Elements in an Array

### Problem

Given an integer array `nums`, an element is valid if:
- It is strictly greater than every element to its left, OR
- It is strictly greater than every element to its right.

First and last elements are always valid. Return all valid elements in original order.

### Key Insight

"Strictly greater than every element to its left" means greater than the prefix max, not just the previous element. `[4, 1, 7]` — 7 is left-valid (7 > max(4,1)) even though 1 is not > 4. So left-valid elements do NOT form a strictly increasing prefix.

### Approach

1. Precompute suffix max array (max of all elements from index i to end).
2. Scan left-to-right tracking a running prefix max.
3. An element is valid if: it is first/last, greater than prefix max (left-valid), or greater than suffix max of the rest (right-valid).

### Complexity

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) - suffix max array |
