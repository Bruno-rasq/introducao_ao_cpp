#include <iostream>
#include <vector>

using namespace std;

void imprimir(vector<string> &array) {
    for(int i=0; i<array.size(); i++){
        cout << "index[" << i << "] = " << array[i] << endl;
    }
}


int main() {

    string substring = "rob";
    vector<string> arr = { "pato", "rato", "robo" };
    
    imprimir(arr);

    cout << "==================" << endl;
    
    int i = arr.size() - 1;
    while(i >= 0){
        string curr = arr[i];
        size_t pos = curr.find(substring);
        if(pos != string::npos){
            arr.erase(arr.begin() + i);
        }
        
        i--;
    }
    
    imprimir(arr);
    
    
    return 0;
}