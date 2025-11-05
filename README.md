# Data Structures Lab - Semester 3

A comprehensive collection of Data Structures and Algorithms implementations in C, covering fundamental concepts including searching, sorting, stacks, queues, linked lists, trees, heaps, and graphs.

## Overview

This repository contains 37 programs implementing various data structures and algorithms as part of the Data Structures Laboratory course. Each program is self-contained and demonstrates specific concepts with clear implementations.

## Table of Contents

- [Searching Algorithms](#searching-algorithms)
- [Sorting Algorithms](#sorting-algorithms)
- [Stack Implementations](#stack-implementations)
- [Queue Implementations](#queue-implementations)
- [Linked List Operations](#linked-list-operations)
- [Tree Data Structures](#tree-data-structures)
- [Heap Data Structures](#heap-data-structures)
- [Graph Algorithms](#graph-algorithms)
- [Matrix Operations](#matrix-operations)
- [Compilation and Execution](#compilation-and-execution)

---

## Searching Algorithms

### 01. Binary Search
**File:** `01_Binary_Search.c`  
**Description:** Implements recursive binary search on a sorted array.  
**Key Concepts:** Divide and conquer, logarithmic time complexity  
**Time Complexity:** O(log n)

### 02. Count Rotations
**File:** `02_Count_Rotations.c`  
**Description:** Counts the number of times a sorted array has been rotated using modified binary search.  
**Key Concepts:** Rotated sorted arrays, finding pivot element  
**Time Complexity:** O(log n)

### 03. Binary Search in Rotated Array
**File:** `03_Binary_Search_Rotated_Array.c`  
**Description:** Searches for an element in a rotated sorted array.  
**Key Concepts:** Modified binary search for rotated arrays  
**Time Complexity:** O(log n)

### 04. First Occurrence
**File:** `04_First_Occurrence.c`  
**Description:** Finds the first occurrence of an element in a sorted array with duplicates.  
**Key Concepts:** Binary search variant for duplicate handling  
**Time Complexity:** O(log n)

---

## Sorting Algorithms

### 05. Insertion Sort
**File:** `05_Insertion_Sort.c`  
**Description:** Implements insertion sort algorithm.  
**Time Complexity:** O(n²) average/worst case, O(n) best case  
**Space Complexity:** O(1)

### 06. Selection Sort
**File:** `06_Selection_Sort.c`  
**Description:** Implements selection sort algorithm.  
**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

### 07. Merge Sort
**File:** `07_Merge_Sort.c`  
**Description:** Implements merge sort using divide and conquer approach.  
**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

### 08. Quick Sort
**File:** `08_Quick_Sort.c`  
**Description:** Implements quick sort with partitioning strategy.  
**Time Complexity:** O(n log n) average, O(n²) worst case  
**Space Complexity:** O(log n)

### 17. Counting Sort
**File:** `17_Counting_Sort.c`  
**Description:** Non-comparison based sorting for integer arrays.  
**Time Complexity:** O(n + k) where k is the range of input  
**Space Complexity:** O(k)

### 19. Radix Sort
**File:** `19_Radix_Sort.c`  
**Description:** Implements radix sort for sorting integers digit by digit.  
**Time Complexity:** O(d × n) where d is the number of digits  
**Space Complexity:** O(n + k)

---

## Stack Implementations

### 09. Stack using Structure
**File:** `09_Stack_Struct.c`  
**Description:** Basic stack implementation using structure with push, pop, and peek operations.  
**Operations:** Push, Pop, Peek, isEmpty, isFull  
**Implementation:** Array-based with fixed size

### 10. Two Stacks in One Array
**File:** `10_Two_Stacks_Array.c`  
**Description:** Efficient implementation of two stacks in a single array.  
**Key Concepts:** Space optimization, dual stack management

### 11. Balanced Parentheses
**File:** `11_Balanced_Parentheses.c`  
**Description:** Checks if parentheses in an expression are balanced using stack.  
**Applications:** Expression validation, compiler design  
**Time Complexity:** O(n)

### 12. Postfix Expression Evaluation
**File:** `12_Postfix_Expression_Evaluation.c`  
**Description:** Evaluates postfix (Reverse Polish Notation) expressions.  
**Key Concepts:** Stack-based expression evaluation  
**Time Complexity:** O(n)

### 13. Sort Stack
**File:** `13_Sort_Stack.c`  
**Description:** Sorts a stack using only stack operations.  
**Key Concepts:** Recursive stack sorting  
**Space Complexity:** O(n) for recursion stack

### 14. Stack with GetMin Operation
**File:** `14_Stack_GetMin.c`  
**Description:** Stack implementation with O(1) getMin() operation.  
**Key Concepts:** Auxiliary stack for tracking minimum element

### 15. Infix to Postfix Conversion
**File:** `15_Infix_To_Postfix.c`  
**Description:** Converts infix expressions to postfix notation.  
**Key Concepts:** Operator precedence, stack-based conversion  
**Time Complexity:** O(n)

### 23. Stack using Linked List
**File:** `23_Stack_LinkedList.c`  
**Description:** Dynamic stack implementation using linked list.  
**Advantages:** No size limitation, dynamic memory allocation

---

## Queue Implementations

### 20. Circular Queue
**File:** `20_Circular_Queue.c`  
**Description:** Circular queue implementation with efficient space utilization.  
**Operations:** Enqueue, Dequeue, Display  
**Key Concepts:** Circular array, modulo arithmetic

### 21. Double Ended Queue (Deque)
**File:** `21_Double_Ended_Queue.c`  
**Description:** Queue allowing insertion and deletion at both ends.  
**Operations:** Insert/Delete at front and rear  
**Applications:** Sliding window problems, palindrome checking

### 22. Queue using Stack
**File:** `22_Queue_Using_Stack.c`  
**Description:** Queue implementation using two stacks.  
**Key Concepts:** Stack to queue conversion, amortized analysis  
**Time Complexity:** O(1) amortized for enqueue and dequeue

### 24. Queue using Linked List
**File:** `24_Queue_LinkedList.c`  
**Description:** Dynamic queue implementation using linked list.  
**Advantages:** No overflow condition, efficient memory usage

---

## Linked List Operations

### 25. Middle of Linked List
**File:** `25_Middle_Linked_List.c`  
**Description:** Finds the middle element of a linked list in one pass.  
**Algorithm:** Two-pointer (slow and fast pointer) technique  
**Time Complexity:** O(n)

### 26. Reverse Linked List
**File:** `26_Reverse_Linked_List.c`  
**Description:** Reverses a singly linked list.  
**Approaches:** Iterative and recursive methods  
**Time Complexity:** O(n)

### 27. Rotate Linked List
**File:** `27_Rotate_LinkedList.c`  
**Description:** Rotates a linked list by k positions.  
**Key Concepts:** Circular linked list conversion, pointer manipulation

### 28. Loop Detection in Linked List
**File:** `28_Loop_in_LinkedList.c`  
**Description:** Detects cycle in a linked list using Floyd's cycle detection algorithm.  
**Algorithm:** Tortoise and hare (slow and fast pointer)  
**Time Complexity:** O(n)

### 29. Intersection of Two Linked Lists
**File:** `29_Intersection_Of_Two_LinkedList.c`  
**Description:** Finds the intersection point of two linked lists.  
**Algorithm:** Two-pointer approach with length adjustment  
**Time Complexity:** O(m + n)

---

## Tree Data Structures

### 30. Binary Tree Traversals
**File:** `30_Binary_Tree_Traversals.c`  
**Description:** Implements all tree traversal methods (both recursive and iterative).  
**Traversals Implemented:**
- Inorder (Recursive & Iterative)
- Preorder (Recursive & Iterative)
- Postorder (Recursive & Iterative)

**Key Concepts:** Stack-based iterative traversals, recursive tree navigation

### 31. Binary Search Tree Operations
**File:** `31_Binary_Search_Tree_Operations.c`  
**Description:** Complete BST implementation with insertion, deletion, and search.  
**Operations:** Insert, Delete, Search, Traversals  
**Properties:** Left subtree < Root < Right subtree

### 32. Dictionary using BST
**File:** `32_Dictionary_Using_BST.c`  
**Description:** Dictionary implementation using Binary Search Tree.  
**Operations:** Insert word, Search word, Delete word  
**Applications:** Symbol tables, autocomplete systems

---

## Heap Data Structures

### 33. Priority Queue using Min Heap
**File:** `33_Priority_Queue_MinHeap.c`  
**Description:** Priority queue implementation using min heap for customer service simulation.  
**Features:** Priority-based customer service (differently abled, senior citizens, defence personnel, ordinary)  
**Operations:** Enqueue with priority, Dequeue (serve highest priority), Display  
**Time Complexity:** O(log n) for insertion and deletion

### 34. Merge K Sorted Lists
**File:** `34_Merge_K_Sorted_Lists.c`  
**Description:** Merges K sorted linked lists using min heap.  
**Algorithm:** Heap-based merging  
**Time Complexity:** O(N log k) where N is total elements

### 35. Min Heap Implementation
**File:** `35_Min_Heap_Implementation.c`  
**Description:** Complete min heap implementation with heapify operations.  
**Operations:** Insert, Extract-Min, Heapify, Build-Heap  
**Applications:** Priority queues, heap sort

---

## Graph Algorithms

### 36. Graph DFS and BFS
**File:** `36_Graph_DFS_BFS.c`  
**Description:** Implements graph traversal using Depth-First Search and Breadth-First Search.  
**Representation:** Adjacency list  
**Applications:** Pathfinding, connectivity checking, cycle detection  
**Time Complexity:** O(V + E)

### 37. Water Jug Problem using BFS
**File:** `37_Water_Jug_Problem_BFS.c`  
**Description:** Solves the classic water jug problem using BFS.  
**Key Concepts:** State space search, BFS for shortest path  
**Applications:** AI problem solving, state exploration

---

## Matrix Operations

### 16. Polynomial Addition
**File:** `16_Polynomial_Addition.c`  
**Description:** Adds two polynomials represented using arrays/linked lists.  
**Key Concepts:** Sparse data structure representation  
**Time Complexity:** O(m + n)

### 18. Fast Transpose of Sparse Matrix
**File:** `18_Fast_Transpose_Sparse_Matrix.c`  
**Description:** Efficient transpose of sparse matrix in O(n) time.  
**Representation:** Three-column representation (row, column, value)  
**Time Complexity:** O(n) where n is number of non-zero elements

---

## Compilation and Execution

### Prerequisites
- GCC Compiler (MinGW for Windows, GCC for Linux/Mac)
- Basic knowledge of C programming

### Compilation
To compile any program, use the following command:

```bash
gcc filename.c -o output
```

**Example:**
```bash
gcc 01_Binary_Search.c -o binary_search
```

### Execution

**Windows:**
```bash
output.exe
```

**Linux/Mac:**
```bash
./output
```

### Complete Example
```bash
# Compile
gcc 30_Binary_Tree_Traversals.c -o tree_traversal

# Run
./tree_traversal    # Linux/Mac
tree_traversal.exe  # Windows
```

---

## Key Concepts Covered

### Data Structures
- Arrays and Strings
- Stacks (Array and Linked List based)
- Queues (Circular, Deque, Priority Queue)
- Linked Lists (Singly, operations)
- Trees (Binary Tree, Binary Search Tree)
- Heaps (Min Heap)
- Graphs (Adjacency List)
- Sparse Matrices

### Algorithms
- **Searching:** Binary Search and variants
- **Sorting:** Insertion, Selection, Merge, Quick, Counting, Radix
- **Tree Traversals:** Inorder, Preorder, Postorder (Recursive & Iterative)
- **Graph Traversals:** DFS, BFS
- **Optimization:** Two-pointer technique, Fast-slow pointer
- **Problem Solving:** Stack-based problems, Heap-based merging

### Time Complexities Summary

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Binary Search | O(1) | O(log n) | O(log n) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) |
| Radix Sort | O(d × n) | O(d × n) | O(d × n) |
| DFS/BFS | O(V + E) | O(V + E) | O(V + E) |
| Heap Operations | O(log n) | O(log n) | O(log n) |

---

## Repository Structure

```
Data-Structures-Lab/
│
├── 01_Binary_Search.c
├── 02_Count_Rotations.c
├── 03_Binary_Search_Rotated_Array.c
├── 04_First_Occurrence.c
├── 05_Insertion_Sort.c
├── 06_Selection_Sort.c
├── 07_Merge_Sort.c
├── 08_Quick_Sort.c
├── 09_Stack_Struct.c
├── 10_Two_Stacks_Array.c
├── 11_Balanced_Parentheses.c
├── 12_Postfix_Expression_Evaluation.c
├── 13_Sort_Stack.c
├── 14_Stack_GetMin.c
├── 15_Infix_To_Postfix.c
├── 16_Polynomial_Addition.c
├── 17_Counting_Sort.c
├── 18_Fast_Transpose_Sparse_Matrix.c
├── 19_Radix_Sort.c
├── 20_Circular_Queue.c
├── 21_Double_Ended_Queue.c
├── 22_Queue_Using_Stack.c
├── 23_Stack_LinkedList.c
├── 24_Queue_LinkedList.c
├── 25_Middle_Linked_List.c
├── 26_Reverse_Linked_List.c
├── 27_Rotate_LinkedList.c
├── 28_Loop_in_LinkedList.c
├── 29_Intersection_Of_Two_LinkedList.c
├── 30_Binary_Tree_Traversals.c
├── 31_Binary_Search_Tree_Operations.c
├── 32_Dictionary_Using_BST.c
├── 33_Priority_Queue_MinHeap.c
├── 34_Merge_K_Sorted_Lists.c
├── 35_Min_Heap_Implementation.c
├── 36_Graph_DFS_BFS.c
├── 37_Water_Jug_Problem_BFS.c
└── README.md
```

---

## Learning Outcomes

Through these implementations, the following competencies are developed:

1. **Understanding fundamental data structures** and their practical applications
2. **Algorithm design and analysis** including time and space complexity
3. **Problem-solving skills** using appropriate data structures
4. **Memory management** in C including dynamic allocation
5. **Recursive and iterative thinking** for various algorithms
6. **Optimization techniques** for efficient code implementation

---

## Notes

- All programs are written in C and follow standard C conventions
- Programs include error handling for edge cases
- Each implementation is self-contained and can be compiled independently
- Interactive input/output for better understanding and testing

---

## Author

**Gabriel James**  
Data Structures Laboratory - Semester 3

---

## License

This repository is for educational purposes as part of academic coursework.

---

## Acknowledgments

Implementations are based on standard algorithms and data structures concepts from computer science fundamentals.
