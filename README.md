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
