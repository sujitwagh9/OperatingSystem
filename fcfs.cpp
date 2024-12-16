#include<bits/stdc++.h>
using namespace std;

void fcfs(vector<int> input, int& totalSeekTime, int start) {
    if (input.empty()) {
        cout << "No requests to process.\n";
        totalSeekTime = 0;
        return;
    }

    int currentHeadPosition = start;
    cout << "Starting Head Position: " << currentHeadPosition << endl;

    for (int request : input) {
        int seekDistance = abs(request - currentHeadPosition);
        totalSeekTime += seekDistance;
        cout << "Move from " << currentHeadPosition << " to " << request
             << " (Seek Distance: " << seekDistance << ")" << endl;
        currentHeadPosition = request;
    }
}

int main() {
    vector<int> input;
    int totalSeekTime = 0, start;

    cout << "Enter the starting position of the disk head: ";
    cin >> start;

    cout << "Enter the number of requests: ";
    int n;
    cin >> n;

    cout << "Enter the requests: ";
    for (int i = 0; i < n; ++i) {
        int request;
        cin >> request;
        input.push_back(request);
    }

    fcfs(input, totalSeekTime, start);

    cout << "Total Seek Time: " << totalSeekTime << endl;

    return 0;
}
