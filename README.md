# Info

This is my own implementation of stack/queue using linked list, this was created during an exam at my university.

# Usage

## Changing data type

Default datatype used for this linked list is Char, defined in typedef at the top of the code, you can change this by setting different data type at typedef.

```c
typedef char itemType; //Change 'char' to 'int' if integers are desired (example)
```
Do not forget to change the return values from character types to normal integer values.

```c
return '\0'; // Change to 'return 0' if data type is integer
```


## Using the linked list

### Initialzing list

Linked list can be used by defining a data type p_list and initialzing it (as it is a structure) via function "init();"

```c
p_list list=init();
```


### Putting items inside the list

Putting items into the list is quite simple, use functions "insertFirst" and "insertLast", while the first parameter of the function is always the list you want to put in into and the second is data you want to put into the list.

```c
insertFirst(list, 'A');
insertLast(list, 'B');
```

### Removing items from the list

You can "pop" or remove the items from the list by using functions "removeFirst" or "removeLast", while the parameter of the function is always the list you want to remove item from. Return value is data type with the value of the item stored inside.

```c
removeFirst(list);
removeLast(list);
```


### Checking if the list is empty

You can use function "isEmpty" with parameter being the list you want to check whether it is empty or not, returns 1 if empty or 0 if it is not.

```c
isEmpty(list);
```

### Clearing the list

You can use function "clear" with parameter being list you want to clear, this functions as its name suggests clears the entire list without deleting it.

```c
clear(list);
```

### Deleting (destroying) the list

You can also choose the delete the entire list using function "destroy".

```c
destroy(list);
```

### Counting items inside the list

Last available function is function "count" with parameter being list you want to count items in. Return value is integer value with number of entries in the list.

```c
count(list);
```


