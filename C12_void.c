#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node struct
typedef struct s_list t_list;
struct s_list
{
    t_list  *next;
    void    *data;
};

// C_00 - create new node
t_list *ft_create_element(void *data)
{
    t_list *temp = (t_list*)malloc(sizeof(t_list));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

int main()
{
    int myInt = 100;
    printf("myInt = %d \n", myInt);
    t_list *head = ft_create_element(&myInt);
    // char *p = (char *)(head->data);
    printf("myInt = %c \n", *(char *)(head->data));
    return 0;
}