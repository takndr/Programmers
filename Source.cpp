#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> queueMax;
    priority_queue<int, vector<int>, greater<int>> queueMin;

    int insertOperate = 0;
    int deleteOperate = 0;

    for (auto operation : operations)
    {
        char command = operation.front();
        operation.erase(0, 2);
        int index = stoi(operation);

        if (command == 'I')
        {
            insertOperate++;
            queueMax.push(index);
            queueMin.push(index);
        }
        else
        {
            deleteOperate++;
            if (index == 1)
            {
                if (!queueMax.empty())
                {
                    queueMax.pop();
                }
            } 
            else
            {
                if (!queueMin.empty())
                {
                    queueMin.pop();
                }
            }
        }
    }
    
    if (deleteOperate >= insertOperate)
    {
        answer.push_back(0);
        answer.push_back(0);
    } 
    else
    {
        answer.push_back(queueMax.top());
        answer.push_back(queueMin.top());
    }

    return answer;
}

/*
    int stoi(const string& _Str, size_t* _Idx = nullptr, int _Base = 10)
*/

/*
    ["I 1", "I 3", "D 1", "I 5", "D -1"]
    Max     Min
    5       -1
    1       -3
            -5
*/

int main()
{
    vector<string> test = { "I 1", "I 3", "D 1", "I 5", "D -1" };
    vector<int> answers;
    answers = solution(test);
    for (auto answer : answers)
    {
        cout << answer << endl;
    }
}