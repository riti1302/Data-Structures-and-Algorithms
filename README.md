# Data Structures
Data Structures are structures programmed to store ordered data, so that various operations can be performed on it easily. 
It represents the knowledge of data to be organized in memory. 
It should be designed and implemented in such a way that it reduces the complexity and increases the efficiency.

## Basic Types of Data Structure
Data Structures are classified into two categories:
1. Primitive Data Structures(Build-in data structures)
2. Abstract Data Structures(User defined data structures)
### Primitive Data Structures
Integer, Float, Char, Boolean etc are all examples of this.



### Abstract Data Structures
Stacks, Queues, Linkedlists, Trees, Graphs etc are all examples of this.

<p align="center"> <img src="data_structures.gif"/> </p>

### Stacks
Stack is an abstract data type with a bounded(predefined) capacity. It is a simple data structure that allows adding and 
removing elements in a particular order. Every time an element is added, it goes on the top of the stack and the only element
that can be removed is the element that is at the top of the stack, just like a pile of objects.
<p align="center"> <img src="stacks.jpeg"/> </p>

### Queues
Queue is also an abstract data type or a linear data structure, just like stack data structure, in which the first element is 
inserted from one end called the REAR(also called tail), and the removal of existing element takes place from the other end 
called as FRONT(also called head).

The process to add an element into queue is called Enqueue and the process of removal of an element from queue is called Dequeue.
This makes queue as FIFO(First in First Out) data structure, which means that element inserted first will be removed first.

<p align="center"> <img src="queues.png"/> </p>

### Linked lists
Linked List is a very commonly used linear data structure which consists of group of nodes in a sequence.
Each node holds its own data and the address of the next node hence forming a chain like structure.
Linked Lists are used to create trees and graphs.

<p align="center"> <img src="linked lists.jpeg"/> </p>

#### Singly linked lists
ingly linked lists contain nodes which have a data part as well as an address part i.e. next, which points to the next node in the
sequence of nodes.
The operations we can perform on singly linked lists are insertion, deletion and traversal.

#### Doubly linked lists
In a doubly linked list, each node contains a data part and two addresses, one for the previous node and one for the next 
node.

#### Circular linked lists
In circular linked list the last node of the list holds the address of the first node hence forming a circular chain.
