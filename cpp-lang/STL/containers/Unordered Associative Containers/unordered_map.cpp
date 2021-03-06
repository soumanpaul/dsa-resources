
// C++ program to demonstrate functionality of unordered_map
/*

begin(): Returns an iterator pointing to the first element in the container in the unordered_map container.
end(): Returns an iterator pointing to the position past the last element in the container in the unordered_map container.
count(): Counts the number of elements present in an unordered_map with a given key. Since keys are unique in an unordered_map, so it is basically used as a replacement of find() sometimes to check if a key-value pair with a given key exists in the unoredered_map or not.
size(): The size function is used to find the total size of the unorered_map. That is, the total number of elements present in the unordered_map.
erase(): The erase function is used to erase a particular element from the unordered_map. It can also be used to erase a range of elements from the map.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> umap;

    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    for (auto x : umap)
        cout << x.first << " " << x.second << endl;

    if (umap.find("Practice") != umap.end())
        cout << "The key Practice Found!\n";
    else
        cout << "The key Practice Not Found!\n";

    auto it = umap.find("Practice");
    if (it != umap.end())
        cout << "Key is: " << it->first << ", "
             << "Value is: " << it->second;

    umap.erase("Practice");

    cout << "Size after erasing: " << umap.size() << "\n";

    // Erasing a range
    umap.erase(umap.begin(), umap.end());

    // Size after erasing all elements
    cout << "Size after erasing all elements: "
         << umap.size();
}
