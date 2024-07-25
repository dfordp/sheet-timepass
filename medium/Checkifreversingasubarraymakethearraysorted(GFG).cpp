class Solution {
public:
    bool checkReverse(int arr[], int n) {
        std::vector<int> temp(arr, arr + n);
        std::sort(temp.begin(), temp.end());
        int front = 0, back = n - 1;
        while (front < n && temp[front] == arr[front]) front++;
        while (back >= 0 && temp[back] == arr[back]) back--;
        if (front >= back) return true;
        for (int i = front; i < back; i++)
            if (arr[i] < arr[i + 1]) return false;
        return true;
    }
};