# DSA Assignment-3

## Question- 1 () 

- **Submission Link:** [LeetCode Submission](https://leetcode.com/problems/)
- **Status:** Passed all test cases
- **Time Complexity:** O(nlogk)
- **Space Complexity:** O(k)
- **Explanation:** A priority-queue (heap) of k elements is maintained and then interates across elements of n sized array ensuring that only largest k elements encounterred till now remain in the heap. So after iterating through whole array the top element of the priority queue will be the smallest element among largest k elements of the array which is the required answers.
  ![Submission Photo](<./Ques-5/image.png>)