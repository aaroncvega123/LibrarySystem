Answers based on question numbers:

1. As far as I can tell, everything seems to work. However, I'm still not sure how memory management really works, so there are, regretfully, memory leaks.

2. There is one hashtable in ResourceList. It contains a 2 dimensional array. 1 dimension is for genres. The other is for each item within that genre. When there is a collision, items are placed in a linked list.

3. ResourceList::populateList() read data4books.txt

4. LibrarySystem::setCommandsFromFile() read data4commands.txt

5. I didn't pay much attention to memory deallocation.  I also feel some parts would need changing if a new Resource or Interact object type were added. No switches used.

6. I'm just glad I made it to the finish line.