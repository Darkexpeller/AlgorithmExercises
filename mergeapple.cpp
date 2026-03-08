#include <stdio.h>


struct data_node
{
    int val;
    data_node *next = NULL;
};

class data_node_header
{
public:
    int length;
    data_node *first = NULL;
    data_node *last = NULL;
    void insert_sort(data_node *new_data)
    {
        new_data->next = NULL;
        data_node *now = first;
        if (first == NULL) //空链表
        {
            first = new_data;
            last = first;
            length++;
            return;
        }
        if (first->val >= new_data->val)  //插首
        {
            new_data->next = first;
            first = new_data;
            length++;
            return;
        }

        while (now->next != NULL)  //插中间
        {
            if (now->val <= new_data->val && now->next->val >= new_data->val)
            {
                new_data->next = now->next;
                now->next = new_data;
                length++;
                return;
            }
            now = now->next;
        }
        now->next = new_data; //插尾
        last = new_data;
        length++;
    }
    void delete_first()
    {
        if (NULL == first)
        {
            return;
        }
        data_node *next = first->next;
        delete first;
        first = next;
        --length;
        if (length == 0)
            last = NULL;
    }
    ~data_node_header()
    {
        if (first != NULL)
        {
            data_node *now = first;
            data_node *pre;
            while (now != NULL)
            {
                pre = now;
                now = now->next;
                delete pre;
            }
        }
    }
};


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
int mergeapple(int data[], int count)
{
    data_node_header header;
    header.length = count;
    data_node *first = new data_node;
    first->val = data[0];
    header.first = first;
    header.last = first;
    data_node *new_data = NULL;
    for (int i = 1; i < count; i++)
    {
        new_data = new data_node;
        new_data->val = data[i];
        header.last->next = new_data;
        header.last = new_data;
    }
    int sum = 0;
    while (header.length>1)
    {
        new_data = new data_node;
        new_data->val =header.first->val + header.first->next->val;
        sum +=new_data->val;
        header.delete_first();
        header.delete_first();
        header.insert_sort(new_data);
        //printf("%d\n", new_data->val);
    }
    return sum;
}
void demo()
{
    int count;
    scanf("%d", &count);
    int *data = new int[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", (data + i));
    }
    qucik_sort(data, 0, count - 1);
    data_node_header header;
    printf("%d", mergeapple(data, count));
}
void demo_2()
{
    int count=3;
    int data[] = {1, 2, 9};
    printf("%d", mergeapple(data, count));

}

int main()
{
    demo();
}