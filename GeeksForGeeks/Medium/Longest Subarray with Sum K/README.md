# Longest Subarray with Sum K

## Difficulty: Medium

## Platform: GeeksForGeeks

## Problem Link
[View Problem](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)

## Solved On
12 Sept 2026 at 04:12 pm

<h2><a href="https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1">Longest Subarray with Sum K</a></h2><h3>Difficulty Level: Medium</h3><hr><p><span style="font-size: 14pt;">Given an array <strong>arr[]</strong> containing integers and an integer <strong>k</strong>, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value&nbsp;<span style="font-size: 18.6667px;">k</span>. If there is no subarray with sum equal to&nbsp;<span style="font-size: 18.6667px;">k</span>, return <span style="font-size: 18.6667px;">0</span>.</span></p><p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p><pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [10, 5, 2, 7, 1, -10], k = 15
<strong>Output:</strong> 6
<strong>Explanation: </strong></span><span style="font-size: 18.6667px;">Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.</span></pre><pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [-5, 8, -14, 2, 4, 12], k = -5
<strong>Output:</strong> 5
<strong>Explanation: </strong>S</span><span style="font-size: 18.6667px;">ubarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.</span></pre><pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [10, -10, 20, 30], k = 5
<strong>Output:</strong> 0
<strong>Explanation: </strong></span><span style="font-size: 18.6667px;">No subarray with sum = 5 is present in arr[].</span></pre>