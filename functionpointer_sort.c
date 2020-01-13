#include <stdio.h>
#include <stdlib.h> //for qsort()

int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}
main()
{
    int (*cmp) (const void* , const void*);
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8,9};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
}
