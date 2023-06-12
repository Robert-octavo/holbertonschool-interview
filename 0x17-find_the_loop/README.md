# 0x17. Find the Loop

Write a function that finds the loop in a linked list.

- Prototype: listint_t *find_listint_loop(listint_t *head);
- Returns: The address of the node where the loop starts, or NULL if there is no loop
- You are not allowed to use malloc, free or arrays
- You can only declare a maximum of two variables in your function

Note: In order to compile the main file, you are provided [with this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a). This library won’t be used during the correction; Its only purpose is for testing.

If you want to use source file instead of the libloop.a library, please use this file [lib.c](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/text/2021/1/79eebf4f9215073644b8cd766a88c8a3f3a0fd88.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230612%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230612T150210Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=51ecdceb9b9fbddf59f1cdd1741689a8da15ee4df6861725276201e4e0ff3bd9)

And compile it with this command: $ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
