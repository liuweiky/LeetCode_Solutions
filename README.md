# LeetCode_Solutions
🎉My LeetCode solutions

## 0001. Two Sum

[Problem description](https://leetcode.com/problems/two-sum/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0001_Two_Sum/solution.cpp)

## 0002. Add Two Numbers

[Problem description](https://leetcode.com/problems/add-two-numbers/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0002_Add_Two_Numbers/solution.cpp)

## 0003. Longest Substring Without Repeating Characters

[Problem description](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0003_Longest_Substring_Without_Repeating_Characters/solution.cpp)

### 解题思路

使用 ```st[i]``` 保存**以```i```结尾的最大非重复子串**，外层循环遍历以 i 结尾的子串，内层循环根据```st[i]```检查是否有重复。这种方法可以将时间复杂度从 O(n^3) 降低到 O(n^2)。

## 0004. Median of Two Sorted Arrays

[Problem description](https://leetcode.com/problems/median-of-two-sorted-arrays/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0004_Median_of_Two_Sorted_Arrays/solution.cpp)

### 解题思路

二分查找，并且使用了Median的性质。对于A的划分i，表示以第i - 1个元素结尾的子序列，则对B的划分j应受到Median性质的限制。即，i和j应有如下关系成立：```i + j = m + n - i - j（m + n 为偶数）```，```i + j = m + n - i - j + 1（m + n 为奇数）```。

初始时i的范围为[0, m]，其中m为较大长度序列的长度。对于一个正确的Median划分，left_part的所有元素都应小于等于right_part的元素，若有不满足，则应相应调整i的取值及其取值范围。

详见LeetCode上的[Discuss](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O\(log\(min\(mn\)\)-solution-with-explanation)

此题还应注意对引用的交换。交换引用时不要直接覆盖：

```cpp
vector<int>& t = num1;
num1 = num2;    // WRONG!这样的交换会直接用num2覆盖原来num1处的数据，导致t也变成了num2的数据！
num2 = t;
```
## 0005. Longest Palindromic Substring

[Problem description](https://leetcode.com/problems/longest-palindromic-substring/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0005_Longest_Palindromic_Substring/solution.cpp)

### 解题思路

求最长回文子串，使用**动态规划**。

```is_palindromic[i][j]``` 表示从 i 到 j 的子串是否是回文的。

递推关系式：```is_palindromic[i][j] = is_palindromic[i + 1][i + k - 1] && s[i] == s[i + k]  ? 1 : 0;```

初始时：

```cpp
is_palindromic[i][i] = 1;
is_palindromic[i][i + 1] = s[i] == s[i + 1] ? 1 : 0;
```

循环中按照子串长度更新：```is_palindromic[i][i + k]``` k 从 1 到整个字符串长度减 1。

该方法时间复杂度 O(n^2)。

## 0006. ZigZag Conversion

[Problem description](https://leetcode.com/problems/zigzag-conversion/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0006_ZigZag_Conversion/solution.cpp)

### 解题思路

注意多维数组动态申请和释放。

越界写将产生 **Runtime Error:** ***Error in `sandbox run': free(): invalid next size (fast): \<ADDRESS>***

## 0007. Reverse Integer

[Problem description](https://leetcode.com/problems/reverse-integer/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0007_Reverse_Integer/solution.cpp)

### 解题思路

题目中要求溢出处理，这时可以用一个**取值范围更大的数**来判断是否溢出：

```cpp
long long xt = x;
// ...
long long rev = 0;
// ...
if (rev > INT_MAX)    // Overflow
    return 0;
```

## 0008. String to Integer (atoi)

[Problem description](https://leetcode.com/problems/string-to-integer-atoi/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0008_String_to_Integer_(atoi)/solution.cpp)

### 解题思路

溢出处理有更好的方法：从高位向低位十进制移位累加。累加低位前保存原数（old_num），累加后检查是否有 ```new_num / 10 == old_num``` 成立。若不成立，说明已经溢出。

## 0009. Palindrome Number

[Problem description](https://leetcode.com/problems/palindrome-number/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0009_Palindrome_Number/solution.cpp)

## 0011. Container With Most Water

[Problem description](https://leetcode.com/problems/container-with-most-water/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0011_Container_With_Most_Water/solution.cpp)

### 解题思路

Two Pointers 方法。i 和 j 指向当前考虑的索引和高度。初始时 i 指向头，j 指向尾。i 随着迭代进行而增大，j 随着迭代进行而减小。对于其中某次迭代，记录当前有效高度 min_height。在决定下次迭代的 i 和 j 时，注意到 j - i 必定减小，要找到更大的面积，**下一次的有效高度应大于本次的有效高度 min_height**。

## 0012. Integer to Roman

[Problem description](https://leetcode.com/problems/integer-to-roman/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0012_Integer_to_Roman/solution.cpp)

### 解题思路

字符串处理。

## 0013. Roman to Integer

[Problem description](https://leetcode.com/problems/roman-to-integer/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0013_Roman_to_Integer/solution.cpp)

### 解题思路

字符串处理。

## 0014. Longest Common Prefix

[Problem description](https://leetcode.com/problems/longest-common-prefix/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0014_Longest_Common_Prefix/solution.cpp)

### 解题思路

字符串处理。

## 0015. 3Sum

[Problem description](https://leetcode.com/problems/3sum/)

[C++ (Accepted) - 二分查找 364 ms](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0015_3Sum/solution-binary-search.cpp)

[C++ (Accepted) - Two Pointers 144 ms](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0015_3Sum/solution-two-pointers.cpp)

### 解题思路

先对整个数组进行非降序排序。

#### 二分查找

先固定第一、二个数（p、q 指针），这样也就是要找到 nums[r] = - (nums[p] + nums[q])。使用 low、high 指针二分查找确定 nums[r] 。

#### Two Pointers

先固定第一个数（p 指针），再使用 Two Pointers（q、r 指针）确定剩余两数。

## 0016. 3Sum Closest

[Problem description](https://leetcode.com/problems/3sum-closest/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0016_3Sum_Closest/solution.cpp)

### 解题思路

Two Pointers 或 二分查找。

## 0017. Letter Combinations of a Phone Number

[Problem description](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0017_Letter_Combinations_of_a_Phone_Number/solution.cpp)

### 解题思路

DFS。

## 0018. 4Sum

[Problem description](https://leetcode.com/problems/4sum/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0018_4Sum/solution.cpp)

### 解题思路

对于 N-Sum 问题，只需遍历前 N-2 个数，对剩余两个数使用 two pointers。若前后两个相邻的数相同，则进行优化，跳过这个与前面一个相同的数。

## 0019. Remove Nth Node From End of List

[Problem description](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0019_Remove_Nth_Node_From_End_of_List/solution.cpp)

### 解题思路

链表操作。

## 0020. Valid Parentheses

[Problem description](https://leetcode.com/problems/valid-parentheses/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0020_Valid_Parentheses/solution.cpp)

### 解题思路

表达式栈。

## 0021. Merge Two Sorted Lists

[Problem description](https://leetcode.com/problems/merge-two-sorted-lists/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0021_Merge_Two_Sorted_Lists/solution.cpp)

### 解题思路

链表操作。

## 0022. Generate Parentheses

[Problem description](https://leetcode.com/problems/generate-parentheses/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0022_Generate_Parentheses/solution.cpp)

### 解题思路

回溯。还有很大优化空间。

## 0023. Merge k Sorted Lists

[Problem description](https://leetcode.com/problems/merge-k-sorted-lists/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0023_Merge_k_Sorted_Lists/solution.cpp)

### 解题思路

priority_queue 应用于队列实时调整，又需要取当前队列里最大/最小值的情况。

## 0024. Swap Nodes in Pairs

[Problem description](https://leetcode.com/problems/swap-nodes-in-pairs/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0024_Swap_Nodes_in_Pairs/solution.cpp)

### 解题思路

链表操作。

## 0025. Reverse Nodes in k-Group

[Problem description](https://leetcode.com/problems/reverse-nodes-in-k-group/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0025_Reverse_Nodes_in_k-Group/solution.cpp)

### 解题思路

对于链表元素进行每 k 个元素反转。先利用 vector<ListNode*> 暂存，直到累积到 k 个元素后，进行反转。

## 0026. Remove Duplicates from Sorted Array

[Problem description](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0026_Remove_Duplicates_from_Sorted_Array/solution.cpp)

### 解题思路

使用两个指针，一个 (ptr) 指向保留的最后一个元素，另一个 (i) 指向遍历元素，i 不断遍历，若两者不等，nums[++ptr] = nums[i]。

## 0027. Remove Element

[Problem description](https://leetcode.com/problems/remove-element/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0027_Remove_Element/solution.cpp)

### 解题思路

类似 0026 题。

## 0028. Implement strStr()

[Problem description](https://leetcode.com/problems/implement-strstr/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0028_Implement_strStr()/solution.cpp)

### 解题思路

当然没那么简单啦。实现 KMP 算法，有空再看。

## 0031. Next Permutation

[Problem description](https://leetcode.com/problems/next-permutation/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0031_Next_Permutation/solution.cpp)

### 解题思路

生成下一个排列。

从后往前找第一个满足 nums[i - 1] < nums[i] 的，即，从后往前第一个下降的。则 nums[i], nums[i + 1], nums[i + 2], . . . 序列必然是非增的。从 nums[i], nums[i + 1], nums[i + 2], . . . 序列中选择最小的，但是比 nums[i - 1] 大的数 nums[k]。将 nums[i - 1] 与 nums[k] 交换，对交换后的 nums[i], nums[i + 1], nums[i + 2], . . . 进行倒序，即为下一个排列。

> 1 2 4 [6 5 3]
> 
> 1 2 **5** [6 **4** 3]
> 
> 1 2 5 [3 4 6] (Next Permutation)

## 0035. Search Insert Position

[Problem description](https://leetcode.com/problems/search-insert-position/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0035_Search_Insert_Position/solution.cpp)

### 解题思路

二分查找，查找失败后 low 指针即为插入位置。
