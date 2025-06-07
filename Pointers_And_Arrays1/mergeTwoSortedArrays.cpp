#include <iostream>
#include <vector>
using namespace std;

vector<int> mergedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else if(nums2[j] < nums1[i]){
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i < n1){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j < n2){
        ans.push_back(nums2[j]);
        j++;
    }

    return ans;
}

int main(){
    system("cls");

    vector<int> vec1;
    vector<int> vec2;

    int input;
    cin >> input;
    while(input != -1){
        vec1.push_back(input);
        cin >> input;
    }

    cin >> input;
    while(input != -1){
        vec2.push_back(input);
        cin >> input;
    }

    vector<int> ans = mergedArrays(vec1, vec2);

    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}