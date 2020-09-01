#include<bits/stdc++.h>

using namespace std;

struct Workshops {
    Workshops(int s,int d) : start_time(s), duration(d), end_time(s+d) {}
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    Workshops* arr;
};

Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops* result = (Available_Workshops*)malloc(sizeof(Available_Workshops));
    result->n = n;
    result->arr = (Workshops*)malloc(sizeof(Workshops)*n);
    for (int i = 0; i < n; ++i) {
        result->arr[i] = Workshops(start_time[i], duration[i]);
    }
    return result;
}

void sortByEndTime(Workshops* x, unsigned int n) {
    sort(x, x + n,
        [](Workshops a, Workshops b) {
            return (a.end_time < b.end_time);
        } 
    );
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int time = 0;
    sortByEndTime(ptr->arr, ptr->n);
    int total_end_time = 0;
    int total = 0;
    for (int i = 0; i < ptr->n; ++i) {
        if (ptr->arr[i].start_time >= total_end_time) {
            total++;
            total_end_time=ptr->arr[i].end_time;
        }
    }
    return total;
}
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
