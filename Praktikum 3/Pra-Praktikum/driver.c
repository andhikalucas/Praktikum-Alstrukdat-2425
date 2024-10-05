#include <stdio.h>
#include "listdin.h"
#include "listdin.c"

int main() {
    ListDin l1, l2;
    int capacity = 10;  // Example capacity for testing
    ElType val, max, min;
    
    // 1. Create a ListDin
    printf("Creating list with capacity %d...\n", capacity);
    CreateListDin(&l1, capacity);
    
    // 2. Read a list
    printf("Enter the number of elements and the elements themselves:\n");
    readList(&l1);
    
    // 3. Print the list
    printf("List after reading input: ");
    printList(l1);
    printf("\n");

    // 4. Test isEmpty and isFull
    if (isEmpty(l1)) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }

    if (isFull(l1)) {
        printf("The list is full.\n");
    } else {
        printf("The list is not full.\n");
    }

    // 5. Get first and last index
    printf("First index: %d\n", getFirstIdx(l1));
    printf("Last index: %d\n", getLastIdx(l1));

    // 6. Find the sum of the list
    printf("Sum of list: %d\n", sumList(l1));

    // 7. Find the extreme values
    extremeValues(l1, &max, &min);
    printf("Max value: %d, Min value: %d\n", max, min);

    // 8. Insert an element at the end
    printf("Inserting element 99 at the end...\n");
    insertLast(&l1, 99);
    printf("List after inserting 99: ");
    printList(l1);
    printf("\n");

    // 9. Delete the last element
    printf("Deleting the last element...\n");
    deleteLast(&l1, &val);
    printf("Deleted element: %d\n", val);
    printf("List after deleting: ");
    printList(l1);
    printf("\n");

    // 10. Copy list to another list
    printf("Copying list to a new list...\n");
    copyList(l1, &l2);
    printf("Copied list: ");
    printList(l2);
    printf("\n");

    // 11. Check if two lists are equal
    if (isListEqual(l1, l2)) {
        printf("The lists are equal.\n");
    } else {
        printf("The lists are not equal.\n");
    }

    // 12. Expand the list
    printf("Expanding the list by 5...\n");
    expandList(&l1, 5);
    printf("New capacity: %d\n", CAPACITY(l1));

    // 13. Shrink the list
    printf("Shrinking the list by 3...\n");
    shrinkList(&l1, 3);
    printf("New capacity: %d\n", CAPACITY(l1));

    // 14. Compress the list
    printf("Compressing the list...\n");
    compressList(&l1);
    printf("New capacity after compression: %d\n", CAPACITY(l1));

    // 15. Sort the list in ascending order
    printf("Sorting list in ascending order...\n");
    sort(&l1, true);
    printf("List after sorting: ");
    printList(l1);
    printf("\n");

    // 16. Find an element in the list
    printf("Searching for element 5...\n");
    int idx = indexOf(l1, 5);
    if (idx != IDX_UNDEF) {
        printf("Element found at index: %d\n", idx);
    } else {
        printf("Element not found.\n");
    }

    // 17. Deallocate the list
    printf("Deallocating the list...\n");
    dealocateList(&l1);
    
    return 0;
}