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

## 0032. Longest Valid Parentheses

[Problem description](https://leetcode.com/problems/longest-valid-parentheses/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0032_Longest_Valid_Parentheses/solution.cpp)

### 解题思路

求最长有效括号序列。

使用 stack 进行模拟。进栈后能出栈的字符是有效的。对这些有效位置进行[打表](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0032_Longest_Valid_Parentheses/solution.cpp#L27)，之后使用[动态规划](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0032_Longest_Valid_Parentheses/solution.cpp#L46)求出最长连续有效字符。

## 0033. Search in Rotated Sorted Array

[Problem description](https://leetcode.com/problems/search-in-rotated-sorted-array/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0033_Search_in_Rotated_Sorted_Array/solution.cpp)

### 解题思路

二分查找。思路：[Java AC Solution using once binary search - LeetCode Discuss](https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14472/Java-AC-Solution-using-once-binary-search)

## 0034. Find First and Last Position of Element in Sorted Array

[Problem description](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array/solution.cpp)

### 解题思路

二分查找，找到下界和上界（lower_bound、upper_bound）。

## 0035. Search Insert Position

[Problem description](https://leetcode.com/problems/search-insert-position/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0035_Search_Insert_Position/solution.cpp)

### 解题思路

二分查找，查找失败后 low 指针即为插入位置。

## 0036. Valid Sudoku

[Problem description](https://leetcode.com/problems/valid-sudoku/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0036_Valid_Sudoku/solution.cpp)

### 解题思路

遍历，打表检查。

## 0037. Sudoku Solver

[Problem description](https://leetcode.com/problems/sudoku-solver/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0037_Sudoku_Solver/solution.cpp)

### 解题思路

DFS。检查是否可行时，无需全局检查，只需检查改变了的列和 9 个方格。

## 0038. Count and Say

[Problem description](https://leetcode.com/problems/count-and-say/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0038_Count_and_Say/solution.cpp)

### 解题思路

无论如何确信，使用 stringstream 前先清空！

```cpp
stringstream ss
ss.str("");
ss.clear();
```

## 0039. Combination Sum

[Problem description](https://leetcode.com/problems/combination-sum/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0039_Combination_Sum/solution.cpp)

### 解题思路

DFS。注意使用有序数列进行[非降 DFS](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0039_Combination_Sum/solution.cpp#L19)保证所求结果没用重复，注意参数中的 i 所发挥的作用。

## 0040. Combination Sum II

[Problem description](https://leetcode.com/problems/combination-sum-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0040_Combination_Sum_II/solution.cpp)

### 解题思路

DFS 剪枝的重要思路：**排序、非降、同一层中不重复搜索相同值的元素**。

## 0042. Trapping Rain Water

[Problem description](https://leetcode.com/problems/trapping-rain-water/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0042_Trapping_Rain_Water/solution.cpp)

### 解题思路

使用两个指针，i 指针固定，j 指针从 i + 1 开始移动，找到第一个比 i 大的高度。计算 i、j 之间的体积，之后令 i = j，如此迭代。当 j == height.size() 时，说明 i 之后没有比 i 更高的了，这时应找到 i 和 j 之间比 i 小的最高的那个，记为 max_idx ，计算 i 和 max_idx 的体积，之后令 i = max_idx，继续迭代。

做题时请不要强迫症，该特判时果断特判！

## 0043. Multiply Strings

[Problem description](https://leetcode.com/problems/multiply-strings/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0043_Multiply_Strings/solution.cpp)

### 解题思路

大数乘法。

## 0045. Jump Game II

[Problem description](https://leetcode.com/problems/jump-game-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0045_Jump_Game_II/solution.cpp)

### 解题思路

farthest 保存当前可以到达的最大索引。3

ptr 是当前考虑的那个 num 下标，显然，farthest = max(farthest, ptr + num = ptr + nums[ptr])。

cur 是前一时刻可以到达的最大下标，当 ptr 超过 cur 时，cur 更新为前一次所能达到的最大距离，并跳数++。

## 0046. Permutations

[Problem description](https://leetcode.com/problems/permutations/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0046_Permutations/solution.cpp)

### 解题思路

求全排列。

## 0047. Permutations II

[Problem description](https://leetcode.com/problems/permutations-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0047_Permutations_II/solution.cpp)

### 解题思路

求**多重集**的全排列。

## 0048. Rotate Image

[Problem description](https://leetcode.com/problems/rotate-image/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0048_Rotate_Image/solution.cpp)

### 解题思路

矩阵旋转等价于：先将矩阵转置，再对矩阵进行左右翻转（镜像）。

## 0049. Group Anagrams

[Problem description](https://leetcode.com/problems/group-anagrams/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0049_Group_Anagrams/solution.cpp)

### 解题思路

STL 的 map 的使用。

## 0050. Pow(x, n)

[Problem description](https://leetcode.com/problems/powx-n/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0050_Pow(x%2C%20n)/solution.cpp)

### 解题思路

快速幂。注意在 int 范围内，-INT_MIN 会溢出。

## 0051. N-Queens

[Problem description](https://leetcode.com/problems/n-queens/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0051_N-Queens/solution.cpp)

### 解题思路

N 皇后问题。

## 0052. N-Queens II

[Problem description](https://leetcode.com/problems/n-queens-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0052_N-Queens_II/solution.cpp)

### 解题思路

N 皇后问题。

## 0053. Maximum Subarray

[Problem description](https://leetcode.com/problems/maximum-subarray/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0053_Maximum_Subarray/solution.cpp)

### 解题思路

动态规划求最长连续子串和。

## 0054. Spiral Matrix

[Problem description](https://leetcode.com/problems/spiral-matrix/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0054_Spiral_Matrix/solution.cpp)

### 解题思路

简单模拟。

## 0055. Jump Game

[Problem description](https://leetcode.com/problems/jump-game/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0055_Jump_Game/solution.cpp)

### 解题思路

参照 [0045. Jump Game II](https://github.com/Heliovic/LeetCode_Solutions#0045-jump-game-ii)。

## 0056. Merge Intervals

[Problem description](https://leetcode.com/problems/merge-intervals/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0056_Merge_Intervals/solution.cpp)

### 解题思路

合并区间。先将所有区间按照左数从小到大排序，再用 last 记录当前正在合并的区间。若对于考虑的某个区间，若其左数小于 last 的右数而其右数大于 last 的右数，则拓展 last 的右数到当前区间的右数。而若其右数小于 last 的右数，则说明该区间包含在 last 之内，可不必考虑。若其左数大于 last 的右数，则保存 last 到 ans，更新 last 为该区间。

## 0057. Insert Interval

[Problem description](https://leetcode.com/problems/insert-interval/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0057_Insert_Interval/solution.cpp)

### 解题思路

同上。

## 0058. Length of Last Word

[Problem description](https://leetcode.com/problems/length-of-last-word/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0058_Length_of_Last_Word/solution.cpp)

### 解题思路

字符串处理。

## 0059. Spiral Matrix II

[Problem description](https://leetcode.com/problems/spiral-matrix-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0059_Spiral_Matrix_II/solution.cpp)

### 解题思路

模拟。

## 0060. Permutation Sequence

[Problem description](https://leetcode.com/problems/permutation-sequence/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0060_Permutation_Sequence/solution.cpp)

### 解题思路

找规律。对于某个长度为 n 的子序列的第 k 个元素，其首位为 numbers[k / (n - 1)!]。其中 numbers 保存当前可选的数字序列。

## 0061. Rotate List

[Problem description](https://leetcode.com/problems/rotate-list/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0061_Rotate_List/solution.cpp)

### 解题思路

模拟，链表操作。

## 0062. Unique Paths

[Problem description](https://leetcode.com/problems/unique-paths/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0062_Unique_Paths/solution.cpp)

### 解题思路

递推。matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1]。初始时，matrix[m - 1][n - 1] = 1。

## 0063. Unique Paths II

[Problem description](https://leetcode.com/problems/unique-paths-ii/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0063_Unique_Paths_II/solution.cpp)

### 解题思路

递推。

## 0064. Minimum Path Sum

[Problem description](https://leetcode.com/problems/minimum-path-sum/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0064_Minimum_Path_Sum/solution.cpp)

### 解题思路

动态规划。

## 0066. Plus One

[Problem description](https://leetcode.com/problems/plus-one/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0066_Plus_One/solution.cpp)

### 解题思路

模拟加法。

## 0067. Add Binary

[Problem description](https://leetcode.com/problems/add-binary/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0067_Add_Binary/solution.cpp)

### 解题思路

二进制加法。

## 0068. Text Justification

[Problem description](https://leetcode.com/problems/text-justification/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0068_Text_Justification/solution.cpp)

### 解题思路

字符串处理。

## 0069. Sqrt(x)

[Problem description](https://leetcode.com/problems/sqrtx/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0069_Sqrt(x)/solution.cpp)

### 解题思路

二分。

## 0070. Climbing Stairs

[Problem description](https://leetcode.com/problems/climbing-stairs/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0070_Climbing_Stairs/solution.cpp)

### 解题思路

记忆化递推。

## 0071. Simplify Path

[Problem description](https://leetcode.com/problems/simplify-path/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0071_Simplify_Path/solution.cpp)

### 解题思路

字符串处理。先用 "/" 替换 "//"，再根据 "/" 进行分割。使用栈模拟路径转移。

## 0073. Set Matrix Zeroes

[Problem description](https://leetcode.com/problems/set-matrix-zeroes/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0073_Set_Matrix_Zeroes/solution.cpp)

## 0074. Search a 2D Matrix

[Problem description](https://leetcode.com/problems/search-a-2d-matrix/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0074_Search_a_2D_Matrix/solution.cpp)

### 解题思路

二分查找。
