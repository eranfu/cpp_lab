#include <iostream>
#include <vector>

int main() {
    std::vector<int32_t> vec{10, 9, 8};
    auto &first = vec[0];

    for (auto i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    std::cout << first << std::endl;
    return 0;
}
