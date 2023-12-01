#include <iostream>
using namespace std;

void waitingTime(int at[], int bt[], int n) {

    int wt[n];

    wt[0] = 0;`

    for (int i = 1; i < n; i++) {

        wt[i] = wt[i-1] + at[i-1] + bt[i-1] - at[i];

    }

    cout << "Waiting time" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << " : " << wt[i] << endl;

    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += wt[i];
    }

    float avg = float (sum) / n;

    cout << "average waiting time is " << avg << endl;

}

int main() {


    int n = 5;

    int at[] = {0, 1, 2, 3, 4};

    int bt[] = {4, 3, 1, 2, 5};

    waitingTime(at, bt, n);

}
