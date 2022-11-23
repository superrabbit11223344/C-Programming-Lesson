#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    freopen("../data/ex854.in", "r", stdin);

    int setNum;  // 多少个集合
    scanf("%d", &setNum);

    int num;    // 每个集合里有多少个元素
    int element;    // 集合中的每个元素
    int result = 0;     // 计算集合里所有只出现过一次的数的和
    unordered_map<int, int> umap;   // key表示集合中的元素，value表示元素出现的次数
    for (int i = 0; i < setNum; i++) {
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &element);
            // 当前element出现过，且第一次发现重复
            if (umap.find(element) != umap.end() && umap[element] == 1) {
                result -= element;
                umap[element]++;
            // 当前element出现过，且多次出现重复
            } else if (umap.find(element) != umap.end()) {
                continue;
            // 当前element第一次出现
            } else {
                umap[element] = 1;
                result += element;
            }
        }
    }

    // 打印结果
    printf("%d", result);
    return 0;
}