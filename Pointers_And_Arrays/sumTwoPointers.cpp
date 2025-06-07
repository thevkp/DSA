#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;


pair<int, int> findSum(vector<int>& vec, int sum){
    int i = 0;
    int j = vec.size() - 1;

    while(i < j){
        if(vec[i] + vec[j] == sum){
            return make_pair(i, j);
        }
        else if(vec[i] + vec[j] > sum){
            j--;
        }
        else{
            i++;
        }
    }

    return make_pair(-1, -1);
}


vector<pair<int, int>> findAllPairs(vector<int>& vec, int sum){
    int n = vec.size();
    int i = 0;
    int j = n - 1;

    vector<pair<int, int>> pairs;
    while(i < n && j >= 0){
        if(vec[i] + vec[j] == sum){
            pairs.push_back(make_pair(i, j));
            i++;
            j--;
        }
        else if(vec[i] + vec[j] > sum){
            j--;
        }
        else {
            i++;
        }
    }

    return pairs;
}

vector<pair<int, int>> findAllPairs1(vector<int> &vec, int target){
    vector<pair<int, int>> pairs;
    unordered_map<int, int> valIndMap;

    for(int i = 0; i < vec.size(); i++){
        int complement = abs(abs(vec[i]) - target);
        valIndMap[vec[i]] = i;
        if(valIndMap.find(complement) != valIndMap.end()){
            if(valIndMap[complement] > 0){
                pairs.push_back(make_pair(valIndMap[complement], i));
            } 
        }
    }

    for(const auto& it : valIndMap){
        cout << it.first << " " << it.second << endl;
    }
    cout << "Returing pairs" << endl;

    return pairs;
}

void findAllPairsFinal(vector<int>& vec, int target){
    unordered_map<int, int> numCount;
    vector<pair<int, int>> pairs;
    
    for(int num : vec){
        int complement = target - num;

        if(numCount[complement] > 0){
            pairs.push_back({complement, num});
            numCount[complement]--;
        }
        else{
            numCount[num]++;
        }
    }

    if (pairs.empty()) {
        cout << "No pairs found with the target sum." << endl;
    } 
    else {
        cout << "Pairs with target sum " << target << ":" << endl;
        for (const auto& p : pairs) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
}

int main(){
    system("cls");

    vector<int> vec;

    int input, targetSum;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    cin >> targetSum;
    // pair<int, int> elements = findSum(vec, targetSum);

    // cout << "Single Pair: " << elements.first << " " << elements.second << endl;

    // vector<pair<int, int>> pairSum = findAllPairs1(vec, targetSum);

    // cout << "All pairs" << endl;
    // for(const auto& it : pairSum){
    //     cout << it.first << " " << it.second << endl;
    // }


    cout << endl << "Final Pairs" << endl;
    findAllPairsFinal(vec, targetSum);

    return 0;
}



// 1 2 3 7 5 -14 2 3 8 4 6 6 9 -1  