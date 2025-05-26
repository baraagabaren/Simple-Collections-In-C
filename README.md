# Simple-Collections-In-C

# Collections Library in C (No malloc)

This is a simple collections library written in C that implements:

- Singly Linked List
- Stack (LIFO)
- Queue (FIFO)

All operations are implemented **without using `malloc()` or `free()`**, making the library ideal for embedded or low-level systems where dynamic memory is restricted.

---

## Features

### ✅ Linked List
- `AddAt(index, list, newChain)` – Insert a chain of nodes at a given index
- `ListIndex(index, list)` – Get the node at a given index
- `SizeOfList(list)` – Get total number of nodes
- `PrintList(list)` – Print contents of the list

### ✅ Stack
- `StackPush(stack, node)` – Push node onto stack
- `StackPop(stack)` – Pop node from stack
- `StackTop(stack)` – Peek at top node
- `StackEmpty(stack)` – Check if stack is empty

### ✅ Queue
- `Enqueue(queue, node)` – Add node to the end
- `Dequeue(queue)` – Remove node from front
- `Front(queue)` – Peek at front node
- `QueueEmpty(queue)` – Check if queue is empty
