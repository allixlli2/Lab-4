#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int calculateSum(const int arr[], int size);
double getAverage(int sum, int size);
void addBonus(int arr[], int size, int bonus = 5);
int findHighest(const int* arr, int size);
int countPassed(const int arr[], int size);

int main() {
    const int SIZE = 5;
    int scores[SIZE] = {65, 82, 90, 45, 78};

    // 1. Show original scores
    cout << "Original Scores: ";
    for (int i = 0; i < SIZE; i++) cout << scores[i] << " ";
    cout << endl;

    // 2. Show sum & average
    int sum = calculateSum(scores, SIZE);
    double average = getAverage(sum, SIZE);
    cout << "Sum: " << sum << " | Average: " << fixed << setprecision(2) << average << endl;

    // 3. Add bonus -> show new scores
    addBonus(scores, SIZE); // Uses default bonus of 5
    cout << "Scores after Bonus (+5): ";
    for (int i = 0; i < SIZE; i++) cout << scores[i] << " ";
    cout << endl;

    // 4. Show highest & number passed
    int highest = findHighest(scores, SIZE);
    int passed = countPassed(scores, SIZE);
    cout << "Highest Score: " << highest << endl;
    cout << "Students Passed (>=70): " << passed << endl;

    return 0;
}


int calculateSum(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) total += arr[i];
    return total;
}


double getAverage(int sum, int size) {
    return static_cast<double>(sum) / size;
}


void addBonus(int arr[], int size, int bonus) {
    for (int i = 0; i < size; i++) {
        arr[i] += bonus;
    }
}


int findHighest(const int* arr, int size) {
    int high = *arr; // Start with first element
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > high) high = *(arr + i);
    }
    return high;
}


int countPassed(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 70) count++;
    }
    return count;
}