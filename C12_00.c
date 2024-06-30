
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node struct
typedef struct s_list t_list;
struct s_list
{
    t_list  *next;
    int     data;
};


// helper function - print linked list
void *ft_print_list(t_list *begin_list)
{
    while(begin_list != NULL){
        printf("%d-->", begin_list->data);
        begin_list = begin_list->next;
    }
    printf("\n");
}



// C_00 - create new node
t_list *ft_create_element(int data)
{
    t_list *temp = (t_list*)malloc(sizeof(t_list));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

// C_01 add new node to linked list
void ft_list_push_front(t_list **begin_list, int data)
{
    t_list *newNode = ft_create_element(data);
    newNode->next = *begin_list;
    *begin_list = newNode;
}

// C_02 => return list length
int ft_list_size(t_list *begin_list)
{
    int count = 0;
    while(begin_list != NULL){
        count++;
        begin_list = begin_list->next;
    }
    return count;
}

// c_03 => return last element value
t_list *ft_list_last(t_list *begin_list)
{
    while(begin_list->next != NULL){
        begin_list = begin_list->next;
    }
    return begin_list;
}

// c_04 => add element at list end
void ft_list_push_back(t_list **begin_list, int data)
{
    t_list *cursor = *begin_list;
    if (cursor == NULL){
        *begin_list = ft_create_element(data);
    }
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = ft_create_element(data);
}

// c_14 => sort linked list
// using Selection sort
t_list  *ft_find_min(t_list *head)
{
    t_list *min = head;
    while (head != NULL)
    {
        if(head->data < min->data)
            min = head;
        head = head->next;
    }
    return min;
}

void    ft_list_sort(t_list *head)
{
    if (head == NULL || head->next == NULL)
        return;
    t_list *cur = head;
    t_list *min;
    int temp;
    while (cur->next != NULL)
    {
        min = ft_find_min(cur->next);
        if (cur->data > min->data)
            {
                temp = cur->data;
                cur->data = min->data;
                min->data = temp;
            }
        cur = cur->next;
    }
}


int main()
{
    t_list *head = ft_create_element(10);
    ft_list_push_front(&head, 8);
    ft_list_push_front(&head, 9);
    ft_list_push_front(&head, 4);
    ft_list_push_front(&head, 200);
    ft_list_push_front(&head, 32);
    ft_list_push_front(&head, 125);
    ft_list_push_front(&head, 34);
    ft_list_push_front(&head, 50);
    ft_list_push_front(&head, 400);
    ft_print_list(head);
    ft_list_sort(head);
    ft_print_list(head);
    // t_list *min = ft_find_min(head);
    // printf("min value %d \n", min->data);
    return 0;
}