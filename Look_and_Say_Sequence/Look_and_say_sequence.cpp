#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int init_mem, int length)
{
    vector<vector<int>> seq (length, vector<int> {});

    for (int i = 0; i < length-1; i++){
        int count = 1;

        if(seq[i].empty())
        {
            seq[i].push_back(init_mem);
        }

        for (int j = 0; j < seq[i].size(); j++){
            if(seq[i][j] == seq[i][j+1]){
                count++;
                
            }
            else if (seq[i][j] != seq[i][j+1]){
                seq[i+1].push_back(seq[i][j]);
                seq[i+1].push_back(count);
                count = 1;
            }
        }
    }

    for(int k = 0; k < seq.size(); k++){

        for (int m = 0; m < seq[k].size(); m++){
            cout << seq[k][m] << " ";
        }
        cout << endl;
    }

}


int main()
{
    int x = 1;
    int l = 10;

    solution(x,l);
}