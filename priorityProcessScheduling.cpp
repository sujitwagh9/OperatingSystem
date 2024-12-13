#include <bits/stdc++.h>
using namespace std;

struct process {
    int processId;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime = 0;
    int turnaroundTime = 0;
    int completionTime = 0;
};

struct CompareProcess {
    bool operator()(const process& p1, const process& p2) {
        if (p1.priority == p2.priority) {
            return p1.arrivalTime > p2.arrivalTime; 
        }
        return p1.priority > p2.priority;
    }
};

void processScheduler(vector<process>& processes) {
    priority_queue<process, vector<process>, CompareProcess> pq;

    for (const auto& p : processes) {
        pq.push(p);
    }

    int currentTime = 0;

    cout << left << setw(12) << "Process ID"
         << setw(15) << "Arrival Time"
         << setw(12) << "Burst Time"
         << setw(10) << "Priority"
         << setw(15) << "Waiting Time"
         << setw(20) << "Turnaround Time"
         << setw(15) << "Completion Time" << endl;

    cout << string(90, '-') << endl;

    while (!pq.empty()) {
        process p = pq.top();
        pq.pop();

        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }

        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;

        cout << setw(12) << p.processId
             << setw(15) << p.arrivalTime
             << setw(12) << p.burstTime
             << setw(10) << p.priority
             << setw(15) << p.waitingTime
             << setw(20) << p.turnaroundTime
             << setw(15) << p.completionTime << endl;
    }
}

int main() {
    int processId, arrivalTime, burstTime, priority;
    int numOfProcess;

    cout << "Enter number of processes: ";
    cin >> numOfProcess;

    vector<process> processes;

    while (numOfProcess--) {
        cout << "\nEnter details for process " << numOfProcess + 1 << ":\n";
        cout << "Process ID: ";
        cin >> processId;
        cout << "Arrival Time: ";
        cin >> arrivalTime;
        cout << "Burst Time: ";
        cin >> burstTime;
        cout << "Priority: ";
        cin >> priority;

        processes.push_back({processId, arrivalTime, burstTime, priority});
    }

    processScheduler(processes);

    return 0;
}
