// 设有 n 个正整数,将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。
//  3
//  13 312 343        34331213
// g++ -g joint.cpp -o joint.exe
// objcopy --only-keep-debug joint.exe joint.debug
// strip --strip-debug joint.exe
// objcopy --add-gnu-debuglink=joint.pdb joint.exe

#include <stdio.h>

#define DEBUG 1
struct num_info
{
    int bit;
    int first_num;
};

void qucik_sort(int a[], int *b[], int l, int r)
{
    int count =0;
#if DEBUG==1
    count = 5;
#endif
    int x = a[l];
    int *x_b = b[l];
    int i = l;
    int j = r;
    if (i >= j)
        return;

    while (i < j)
    {
        while (i < j && a[j] > x)
        {
            j--;
        }
        if (i < j)
        {
            a[i++] = a[j];
            b[i++] = b[j];
        }

        while (i < j && a[i] < x)
        {
            i--;
        }

        if (i < j)
        {
            a[j--] = a[i];
            b[j--] = b[i];
        }
    }
    a[i] = x;
    b[i] = x_b;
#if DEBUG == 1
    for (int i = 0; i < count; i++)
    {

        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < count; i++)
    {

        printf("%d ", *b[i]);
    }
    printf("\n\n\n");
#endif

    qucik_sort(a, b, l, i - 1);
    qucik_sort(a, b, i + 1, r);
}

int ten_power(int power)
{
    int ten = 1;
    for (int i = 0; i < power; i++)
    {
        ten *= 10;
    }
    return ten;
}

num_info num_bit(int number)
{
    num_info info;
    int bit = 0;

    while (number >= 10)
    {
        number /= 10;
        bit++;
    }
    info.bit = bit + 1;
    info.first_num = number;
    return info;
}

int joint(int a[], int count)
{
    int *b = new int[count];
    int **c = new int *[count];

    int max = a[0];
    for (int i = 0; i < count; i++)
    {
        b[i] = a[i];
        c[i] = &a[i];
        if (max < a[i])
            max = a[i];
    }
    int maxbit = num_bit(max).bit;
    num_info info;
    for (int i = 0; i < count; i++) // 扩展b
    {
        info = num_bit(b[i]);

        for (int j = 0; j < maxbit - info.bit; j++)
        {
            b[i] = b[i] * 10 + info.first_num;
        }
    }
    qucik_sort(b, c, 0, count - 1);
#if DEBUG==1
    for (int i = 0; i < count; i++)
    {

        printf("%d ", b[i]);
    }
    printf("\n");

    for (int i = 0; i < count; i++)
    {

        printf("%d ", *c[i]);
    }
    printf("\n");
#endif
    int sum = *(c[0]);
    int count_j = num_bit(*(c[0])).bit;
    for (int i = 1; i < count; i++)
    {

        sum += (*c[i]) * ten_power(count_j);
        count_j += num_bit(*(c[i])).bit;
    }

    return sum;
}

void demo_1()
{
    int b[] = {156, 157, 23333, 123456, 987654};
    int count = sizeof(b) / sizeof(int);
    printf("%d", joint(b, count));
}

int main()
{
    // int count;
    // scanf("%d", &count);
    // int *a = new int[count];
    // for (int i = 0; i < count;i++)
    // {
    //     scanf("%d", (a + i));
    // }
    demo_1();
    // printf("%d", num_bit(10).bit);
}