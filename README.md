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

使用 ```st[i]``` 保存**以```i```结尾的最大非重复子串**，外层循环遍历以 i 结尾的子串，内层循环根据```st[i]```检查是否有重复。这种方法可以将时间复杂度从 O(N^3) 降低到 O(N^2)。

## 0004. Median of Two Sorted Arrays

[Problem description](https://leetcode.com/problems/median-of-two-sorted-arrays/)

[C++ (Accepted)](https://github.com/Heliovic/LeetCode_Solutions/blob/master/0004_Median_of_Two_Sorted_Arrays/solution.cpp)

### 解题思路

二分查找，并且使用了Median的性质。对于A的划分i，表示以第i - 1个元素结尾的子序列，则对B的划分j应受到Median性质的限制。即，i和j应有如下关系成立：```i + j = m + n - i - j（m + n 为偶数）```，```i + j = m + n - i - j（m + n 为奇数）```。

初始时i的范围为[0, m]，其中m为较大长度序列的长度。对于一个正确的Median划分，left_part的所有元素都应小于等于right_part的元素，若有不满足，则应相应调整i的取值及其取值范围。

详见LeetCode上的[Discuss](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O\(log\(min\(mn\)\)-solution-with-explanation)

此题还应注意对引用的交换。交换引用时不要直接覆盖：

```cpp
vector<int>& t = num1;
num1 = num2;    // WRONG!这样的交换会直接用num2覆盖原来num1处的数据，导致t也变成了num2的数据！
num2 = t;
```
