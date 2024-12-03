#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>


using namespace std;


int partition(vector<int>* A, int lo, int hi){

    int pivot = (*A).at(hi);

    int i = lo;

    for (int j=lo; j <= hi-1; j++){


        if ((*A).at(j) <= pivot){
            int x =   (*A).at(j);
            (*A)[j] = (*A).at(i);
            (*A)[i] = x;
            i++;
        }

    }

    int x = (*A)[i];
    (*A)[i] = (*A)[hi];
    (*A)[hi] = x;

    return i;

}

// quicksort
int quicksort(vector<int>* A, int lo, int hi){

    if (lo >= hi || lo < 0) return -1;

    // x.size() = len of vector

    int p = partition(A, lo, hi);

    quicksort(A, lo, p-1);
    quicksort(A, p+1, hi);
}




int main(){

    ifstream file("input.txt");

    char line[128];
    vector<int> r1;
    vector<int> r2;
    /*const char delim[2] = '\t';*/

    if (file.is_open()){
        while (file.getline(line, sizeof(line))){

            char* x = strtok(line, " ");

            char* y = strtok(nullptr, " ");

            r1.insert(end(r1), stoi(x)); 
            r2.insert(end(r2), stoi(y)); 
            

        }

        file.close();
    } else {
        cerr << "unable to open file" << endl;

    }



    // sort vectors
    quicksort(&r1, 0, r1.size()-1);
    quicksort(&r2, 0, r2.size()-1);

    /*for (int i = 0; i < r1.size(); i++)*/
    /*    cout << r1[i] << " " ;*/
    /*cout << endl;*/
    /*cout << r1.size() << endl;*/
    /**/
    /*for (int i = 0; i < r2.size(); i++)*/
    /*    cout << r2[i] << " " ;*/
    /*cout << endl;*/
    /*cout << r2.size() << endl;*/

    int sum = 0;

    for (int i = 0; i < r1.size(); i++)
        sum += abs(r1[i] - r2[i]);

    cout << sum << endl;

    return 0;
    


}
