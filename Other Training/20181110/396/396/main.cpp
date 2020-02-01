#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
int main() {
    int partituras, instrumentos;
    vector<int> arr(200000);
    vector<double> arr2(200000);
    vector<double> arr3(200000);
    string s;
    
    
    while(cin >> partituras) {
        cin >> instrumentos;
        for(int i=0; i<instrumentos; i++) {
            cin >> arr[i];
            arr2[i] = 1;
        }
    
        sort(arr.begin(), arr.end(), greater<int>());
        partituras -= instrumentos;
        while(partituras) {
            for(int i=0; i<instrumentos; i++) {
                arr2[i]++;
                partituras--;
                if(!partituras) break;
            }
            for(int i=0; i<instrumentos; i++) {
                arr3[i] = arr[i] / arr2[i];
            }
        }
   
        sort(arr3.begin(), arr3.end(), greater<int>());
        cout << arr3[0] << endl;
    }
    
    
    
    
    
    
    return 0;
}
