#include <unordered_map>
#include <set>

class NumberContainers {
private:
    std::unordered_map<int, int> indexToNumber;
    std::unordered_map<int, std::set<int>> numberToIndices;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNum = indexToNumber[index];
            if (oldNum == number) {
                return;
            }
            auto it = numberToIndices.find(oldNum);
            if (it != numberToIndices.end()) {
                it->second.erase(index);
                if (it->second.empty()) {
                    numberToIndices.erase(it);
                }
            }
        }
        numberToIndices[number].insert(index);
        indexToNumber[index] = number;
    }
    
    int find(int number) {
        auto it = numberToIndices.find(number);
        if (it != numberToIndices.end()) {
            return *it->second.begin();
        }
        return -1;
    }
};