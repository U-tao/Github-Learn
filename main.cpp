# include <iostream>

void Bubblesort(int arr[], int size)
{
    int tmp = 0;
    bool issort = false;
    for(int i = 0; i < size - 1; i++)
    {
	for(int j = 0; j < size - 1 - i; j++)
	{
	    if(arr[j] > arr[j+1])
	    {
		tmp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = tmp;
	    }
	}
	if(!issort)
	    break;
    }

}

void Fastsort(int arr[], int begin, int end)
{

    int val = arr[begin];
    int l = begin;
    int r = end;
    while(l < r)
    {
        while(l < r && arr[r] >= val) r--;
        if(l < r) arr[l++] = arr[r];
        while(l < r && arr[l] <= val) l++;
        if(l < r) arr[r--] = arr[l];

    }
    arr[l] = val;

    if(begin < l-1) Fastsort(arr, begin, l-1);
    if(end > l+1) Fastsort(arr, l+1, end);
}

void sort(int arr[], int size)
{
    // Fastsort(arr, 0, size-1);
    Bubblesort(arr, size);
}

int main()
{
    // 小张添加的注释
    int arr[] = {12, 3, 89, 43, 21, 78};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, size);

    std::cout << "排序结果：" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
