// 快速排序流程：
// (1) 从数列中挑出一个基准值。
// (2) 将所有比基准值小的摆放在基准前面，所有比基准值大的摆在基准的后面(相同的数可以到任一边)；在这个分区退出之后，该基准就处于数列的中间位置。
// (3) 递归地把"基准值前面的子数列"和"基准值后面的子数列"进行排序。

#include <stdio.h>

void qucik_sort(int a[], int l, int r)
{
    int x = a[l];
    int i = l;
    int j = r;
    if (i >= j)
        return;

    while (i < j)
    {
        while (i < j && a[j] > x)
        {
            --j;
        }

        if (i < j)
        {
            a[i++] = a[j];
        }

        while (i < j && a[i] < x)
        {
            ++i;
        }

        if (i < j)
        {
            a[j--] = a[i];
        }
    }
    a[i] = x;
    qucik_sort(a, l, i - 1);
    qucik_sort(a, i + 1, r);
}
//输出第k小的数

void demo()
{
     int b[] = {156111, 157111, 233331, 123456, 987654};
     int count = sizeof(b) / 4;
     qucik_sort(b, 0, count - 1);
     for (int i = 0; i < count;i++)
     {
         printf("%d ", b[i]);
     }
}
void demo_2()
{
    int count, k = 0;
    scanf("%d %d", &count, &k);
    int *b=new int[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", (b + i));
    }
    qucik_sort(b, 0, count - 1);
    
    printf("%d", b[k]);
}
int main()
{
    // int a[] = {5, 2, 7, 1, 2, 4, 0, 9,5,6,2,7,2,4,5,5,5,6,1,2,3,5,4,6,8,7,9,11,12,13,14,15,16,17,18,19};
    // qucik_sort(a, 0, sizeof(a) / sizeof(int)-1);

    demo();
}