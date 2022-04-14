베르나르 베르베르 소설에 나온 개미 수열에 대한 C++ 풀이. 

 

Look and Say Sequence라는 이름은 이전 행을 읽고 이전 행의 데이터를 다음 행에서 말하기 때문인 것 같다.

 

위키백과에서는 소설 "개미"에서 소개되면서 유명해졌기 때문에, 개미 수열이라는 이름이 붙었다고 소개되어있다.


 
![image](https://user-images.githubusercontent.com/60171875/161701127-942892c6-3b76-4172-acba-727c1e6114f6.png)



## **<Look and Say Sequence C++ Code>**
 
```c++
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
```
 
## **<Look and Say Sequence C++ 풀이>**
  
### **1. 헤더파일 선언**
```c++
#include <iostream>
#include <vector>
``` 

입력과 출력을 위한 <iostream> 헤더파일.

배열을 변수로 하면 결과값 범위에 제한이 되기 때문에, STL의 <vector> 컨테이너를 활용했다.

### **2. Main 함수**
 
```c++
int main()
{
    int x = 1;
    int l = 10;

    solution(x,l);
}
```

x는 초기값을 의미하며 1로 시작하고, l은 총 10개의 행까지 개미수열을 구현하는 것을 의미한다.

solution은 개미수열을 수행하는 함수를 나타낸다.

 

### **3. Solution 함수**
 
Solution 함수의 선언 (int형 인자로 초기값 init_num, 행의 길이 length 선언)

```c++
void solution(int init_num, int length)
{
}​
```
 
length의 갯수의 행을 가지는 이중벡터 컨테이너를 선언한다. 열은 빈 공간으로 선언한다.

```c++
vector<vector<int>> seq (length, vector<int> {});
``` 

for 문을 선언하여 length - 1 까지 반복한다. length - 1인 이유는

이전의 행을 읽어 다음 행으로 값과 갯수를 push_back 할 때 마지막 반복 때 seq[5]에 대한 선언은 하지 않았으므로,

Segmentaion Fault 문제가 생기기 때문이다. (아래에서 다시 설명)

```c++
for (int i = 0; i < length-1; i++){
}
```

이전 행 데이터의 갯수를 세는 count 변수 선언

```c++
int count = 1;​
```

vector 컨테이너는 현재 전부 비어있는 상태이므로, 비어있다면 초기값을 push_back.

```c++
        if(seq[i].empty())
        {
            seq[i].push_back(init_num);
        }​
```

선언한 이중벡터 변수 seq의 i행의 vector size 만큼 반복

```c++
for (int j = 0; j < seq[i].size(); j++){
}​
```

i행의 j번째 변수와 j+1번째 변수가 같다면 count를 1만큼 증가.

```c++
            if(seq[i][j] == seq[i][j+1]){
                count++;
                
            }
```

i행의 j번째 변수와 j+1번째 변수가 같지 않다면, 다음 i+1에 i행의 j번째 변수와 count 변수 push_back.

```c++
            else if (seq[i][j] != seq[i][j+1]){
                seq[i+1].push_back(seq[i][j]);
                seq[i+1].push_back(count);
                count = 1;
            }
```

### **4. 결과**
 
이를 실행하면 아래와 같이 결과가 나타난다. 

![image](https://user-images.githubusercontent.com/60171875/161701503-585164b5-e07e-437c-8b36-2b6b711f2917.png)


https://milkuey.tistory.com/2
 
