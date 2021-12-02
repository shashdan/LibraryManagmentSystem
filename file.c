#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//declaring the struct for linkedlist
struct book
{
    /* data */
    int price;
    char name[50];
    char author[50];
    int ID_number;

    struct book *next;
};

void menu(){
    // 1.Add a new book
    // 2.Print a complete list of all the books
    // 3.Delete a book
    // 4.See the number of books
    // 5.Update a book
    // 6.See the most expensive book.
    // 7.Check if the library is empty
    // 8.Enter a book at a particular index
    // 9.List Union
    // 10.List Intersection
    // 11.Exit

    printf("\nEnter a number according to the menu given below: \n\n1.Add a new book \n2.Print a complete list of all the books\n3.Delete a book\n4.See the number of books\n5.Update a book\n6.See the most expensive book.\n7.Check if the library is empty\n8.Enter a book at a particular index\n9.List Union\n10.List Intersection\n11.Exit");
}

int GetNumBooks(struct book *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

struct book *InsertAtIndex(struct book *ptr, int index)
{
    printf("\n****NEW BOOK INSERTION****\n");
    int val = GetNumBooks(ptr);
    if (index > val || index < 0)
    {
        printf("Sorry, the book cannot be inserted. Please enter a valid index and try again.\n");
        return ptr;
    }
    int price, ID_number;
    char name[30], author[30];
    if (index == 0)
    {
        struct book *item = (struct book *)malloc(sizeof(struct book));
        printf("Enter ISBN of the book: ");
        scanf("%d", &ID_number);
        printf("Enter the name of the book: ");
        scanf("%s", name);
        strcpy(item->name, name);
        printf("Enter the price: ");
        scanf("%d", &price);
        item->price = price;
        printf("Enter author of the book: ");
        scanf("%s", author);
        strcpy(item->author, author);
        item->ID_number = ID_number;
        item->next = ptr;
        printf("\nYour book was succesfully added!");
        return item;
    }
    else
    {
        struct book *h = ptr;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }
        struct book *item = (struct book *)malloc(sizeof(struct book));
        printf("Enter ISBN of the book: ");
        scanf("%d", &ID_number);
        printf("Enter the name of the book: ");
        scanf("%s", name);
        strcpy(item->name, name);
        printf("Enter the price: ");
        scanf("%d", &price);
        item->price = price;
        printf("Enter author of the book: ");
        scanf("%s", author);
        strcpy(item->author, author);
        item->ID_number = ID_number;
        item->next = ptr->next;
        printf("\nYour book was succesfully added!");
        ptr->next = item;
        return h;
    }
}

struct book *Insertbook(struct book *ptr)
{   
    printf("\n****NEW BOOK INSERTION****\n");
    int price, ID_number;
    char name[30], author[30];
                      
    if (ptr == NULL)
    {
        struct book *p = (struct book *)malloc(sizeof(struct book));
        printf("Enter ISBN of the book: ");
        scanf("%d", &ID_number);
        printf("Enter the name of the book: ");
        scanf("%s", name);
        strcpy(p->name, name);
        printf("Enter the price: ");
        scanf("%d", &price);
        p->price = price;
        printf("Enter author of the book: ");
        scanf("%s", author);
        strcpy(p->author, author);
        p->ID_number = ID_number;
        p->next = NULL;
        ptr = p;
        printf("\nYour book was succesfully added!");
        return ptr;
    }
    else
    {
        struct book *p = ptr;
        struct book *item = (struct book *)malloc(sizeof(struct book));

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("Enter ISBN of the book: ");
        scanf("%d", &ID_number);
        printf("Enter the name of the book: ");
        scanf("%s", name);
        strcpy(item->name, name);
        printf("Enter the price: ");
        scanf("%d", &price);
        item->price = price;
        printf("Enter author of the book: ");
        scanf("%s", author);
        strcpy(item->author, author);
        item->ID_number = ID_number;
        item->next = NULL;
        ptr->next = item;
        printf("\nYour book was succesfully added!");
        return p;
    }
}
void PrintList(struct book *ptr)
{
    printf("\n\t\t\t\t*******LIBRARY CATALOGUE*******");
    // printf("Function Started \n");
    if (ptr == NULL)
    {
        printf("\n\nSorry, the library is empty :(");
    }
    else
    {

        int book_number = 1;
        while (ptr != NULL)
        {
            printf("\n*******Book Number %d*******\n", book_number);
            printf("Title: %s\nAuthor: %s\nISBN: %d\nPrice: %d\n", ptr->name, ptr->author, ptr->ID_number, ptr->price);
            ptr = ptr->next;
            printf("\n");
            book_number++;
        }
    }
}

void IsEmpty(struct book *ptr)
{
    if (ptr == NULL)
        printf("The list is empty");
    else
        printf("The list is not empty");
    
}

struct book *Deletebook(struct book *ptr)
{
    int ID_number;
    int val = GetNumBooks(ptr);
    if (val == 0)
        printf("The list currently have 0 items \n");
    else
    {
        printf("Enter the ISBN of the book you want to delete : ");
        scanf("%d", &ID_number);
        struct book *ite = ptr;
        struct book *back = NULL;
        //this index here is working as 0-based index
        int index = 0;
        while (ite != NULL)
        {
            if (ite->ID_number == ID_number)
            {
                break;
            }
            back = ite;
            ite = ite->next;
            index++;
        }
        if (ite == NULL)
        {
            printf("Sorry no such book exists here! \n");
            return NULL;
        }
        if (index == 0)
        {
            ptr = ptr->next;
            printf("Book was succesfully deleted");
            return ptr;
        }
        else
        {
            back->next = ite->next;
            free(ite);
            printf("Book was succesfully deleted");
            return ptr;
        }
    }
}

int UpdateBook(struct book *ptr)
{
    int ID_number;
    int price;
    char author[50];
    char name[50];
    printf("\n****UPDATE BOOK****\n");
    printf("Enter the ISBN of the book you want to update : ");
    scanf("%d", &ID_number);
    int index = 0;
    struct book *ite = ptr;
    while (ite != NULL)
    {
        if (ite->ID_number == ID_number)
        {
            break;
        }
        ite = ite->next;
        index++;
    }
    if (ite == NULL)
    {
        printf("Sorry no such book exists here! \n");
        return -1;
    }
    
    printf("Enter the price: ");
    scanf("%d", &price);
    ite->price = price;
    printf("Enter the name of the book: ");
    scanf("%s", name);
    strcpy(ite->name, name);
    printf("Enter author of the book: ");
    scanf("%s", author);
    strcpy(ite->author, author);
    return 1;
}

void GetExpensive(struct book *ptr)
{
    int max_amount = -1;
    struct book *ite;
    while (ptr != NULL)
    {
        if (ptr->price > max_amount)
        {
            max_amount = ptr->price, ite = ptr;
        }
        ptr = ptr->next;
    }
    printf("The most expensive book in this list is:\n");
    printf("Title: %s\nAuthor: %s\nISBN: %d\nPrice: %d\n", ite->name, ite->author, ite->ID_number, ite->price);
    printf("\n");
}


int isPresent(struct book* head, int data)
{
    struct book* t = head;
    while (t != NULL) {
        if (t->ID_number == data)
            return 1;
        t = t->next;
    }
    return 0;
}

struct book * push(struct book** head_ref, struct book * item)
{
   
    /* allocate node */
    struct book* new_node
        = (struct book*)malloc(
            sizeof(struct book));
 
    /* put in the data */
    new_node->ID_number = item->ID_number;
    new_node->price = item->price;
    strcpy(new_node->author,item->author);
    strcpy(new_node->name,item->name);
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
    return (*head_ref);
}

void ListUnion(struct book* head1,struct book* head2)
{
    struct book* result = NULL;
    struct book *t1 = head1, *t2 = head2;
 
    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        result = push(&result, t1);
        t1 = t1->next;
    }
 
    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!isPresent(result, t2->ID_number))
            result = push(&result, t2);
        t2 = t2->next;
    }
    PrintList(result);
}

void ListIntersection(struct book* head1,struct book* head2)
{
    struct book* result = NULL;
    struct book* t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->ID_number))
            result = push(&result, t1);
        t1 = t1->next;
    }

    PrintList(result);
}

int main()
{
    int option=0;
    struct book *head1;
    struct book *head2;
    head1 = NULL;
    head2 = NULL;
    printf("\n\t\t\t\tWELCOME TO THE SVNIT LIBRARY MANAGEMENT SYSTEM!!\n");
    menu();
    while (option != 11)
    {
        
        printf("\n\nYour choice: ");
        scanf("%d", &option);
        if (option == 1){ //function to insert a new book
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
            head1 = Insertbook(head1);
            else if (list == 2)
            head2 = Insertbook(head2);
            else
            printf("Enter a valid list and try again");
        }
            
        else if (option == 2){ //function to print the complete list of books
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
            PrintList(head1);
            else if (list == 2)
            PrintList(head2);
            else
            printf("Enter a valid list and try again");
        }
            
        else if (option == 3){ // //function to delete a book at the head
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
            head1 = Deletebook(head1);
            else if (list == 2)
            head2 = Deletebook(head2);
            else
            printf("Enter a valid list and try again");
        }
            
            
        else if (option == 4) //Get number of books in library (items in list) (returns an integer value)
        {
            int ans1 = GetNumBooks(head1);
            int ans2 = GetNumBooks(head2);
            printf("\nThe number of books currently in the first list is: %d", ans1);
            printf("\nThe number of books currently in the second list is: %d", ans2);
            printf("\nThe total number of books in the library is: %d", ans1+ans2);
        }

        else if (option == 5){  //Updates a book if it exists (returns an integer value 1 for succesfull update , -1 if the book does not exists)
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
             printf("\n%d\n", UpdateBook(head1));
            else if (list == 2)
             printf("\n%d\n", UpdateBook(head2));
            else
            printf("Enter a valid list and try again");
        }
            
        else if (option == 6){ //Displays the details of the most expensive book
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
            GetExpensive(head1);
            else if (list == 2)
            GetExpensive(head2);
            else
            printf("Enter a valid list and try again");
        }            
            
        else if (option == 7)   //function to check whether the list is empty or not
        {
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1)
            IsEmpty(head1);
            else if (list == 2)
            IsEmpty(head2);
            else
            printf("Enter a valid list and try again");
            
            
        }

        else if (option == 8) //function to insert an element at any chosen index
        {
            int list;
            printf("Enter the list: ");
            scanf("%d", &list);
            if (list == 1){
                int index;
                printf("\nEnter the index :");
                scanf("%d", &index);
                head1 = InsertAtIndex(head1, index);
            }
            else if (list == 2){
                int index;
                printf("\nEnter the index :");
                scanf("%d", &index);
                head2 = InsertAtIndex(head2, index);
            }
            else
            printf("Enter a valid list and try again"); 
        }

        else if (option == 9){ //function to find the union of 2 lists
            ListUnion(head1, head2);
        }

        else if (option == 10){ // function to find the intersection of 2 lists
            ListIntersection(head1, head2);
        }

        else if (option == 11)
        break;
    }
    return 0;
}
