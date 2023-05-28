#include "ordering.h"
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

void testShiftMiddle() {
    int input[] = {2, 4, 6, 8, 5};
    int expected[] = {2, 4, 5, 6, 8};

    cout << "Running testShiftMiddle..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == 2);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftMiddle completed." << endl;
}

void testShiftBegin() {
    int input[] = {2, 4, 6, 8, 1};
    int expected[] = {1, 2, 4, 6, 8};

    cout << "Running testShiftBegin..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == -1);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftBegin completed." << endl;
}

void testShiftEnd() {
    int input[] = {2, 4, 6, 8, 10};
    int expected[] = {2, 4, 6, 8, 10};

    cout << "Running testShiftEnd..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == 4);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftEnd completed." << endl;
}

void testShiftEmpty() {
    int input[] = {10};
    int expected[] = {10};

    cout << "Running testShiftEmpty..." << endl;

    int pos = shiftIntoPosition(input, 1);

    cout << "Position: " << pos << endl;

    assert(pos == 0);

    for (int i = 0; i < 1; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftEmpty completed." << endl;
}

// Template tests

void testShiftMiddleD() {
    double input[] = {2, 4, 6, 8, 5};
    double expected[] = {2, 4, 5, 6, 8};

    cout << "Running testShiftMiddleD..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == 2);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftMiddleD completed." << endl;
}

void testShiftBeginS() {
    string input[] = {"2", "4", "6", "8", "1"};
    string expected[] = {"1", "2", "4", "6", "8"};

    cout << "Running testShiftBeginS..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == 0);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftBeginS completed." << endl;
}

void testShiftEndS() {
    string input[] = {"2", "4", "6", "8", "A"};
    string expected[] = {"2", "4", "6", "8", "A"};

    cout << "Running testShiftEndS..." << endl;

    int pos = shiftIntoPosition(input, 5);

    cout << "Position: " << pos << endl;

    assert(pos == 4);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftEndS completed." << endl;
}

// Iterator tests

void testShiftMiddleV() {
    vector<int> input {2, 4, 6, 8, 5};
    vector<int> expected {2, 4, 5, 6, 8};

    cout << "Running testShiftMiddleV..." << endl;

    auto pos = shiftIntoPosition(input.begin(), input.end());

    cout << "Position: " << distance(input.begin(), pos) << endl;

    assert(pos == input.begin() + 2);

    assert(input == expected);

    cout << "Test testShiftMiddleV completed." << endl;
}

void testShiftBeginA() {
    int input[] = {2, 4, 6, 8, 1};
    int expected[] = {1, 2, 4, 6, 8};

    cout << "Running testShiftBeginA..." << endl;

    auto pos = shiftIntoPosition(input, input + 5);

    cout << "Position: " << distance(input, pos) << endl;

    assert(pos - input == 0);

    for (int i = 0; i < 5; i++) {
        assert(input[i] == expected[i]);
    }

    cout << "Test testShiftBeginA completed." << endl;
}

void testShiftEndL() {
    list<string> input {"2", "4", "6", "8", "A"};
    list<string> expected {"2", "4", "6", "8", "A"};

    cout << "Running testShiftEndL..." << endl;

    auto pos = shiftIntoPosition(input.begin(), input.end());

    auto it = pos;
    ++it;

    cout << "Position: " << distance(input.begin(), pos) << endl;

    assert(it == input.end());

    assert(list<string>(input.begin(), input.end()) == expected);

    cout << "Test testShiftEndL completed." << endl;
}

void testShiftEmptyVL() {
    vector<int> input;
    input.push_back(10);

    list<int> expected {10};

    cout << "Running testShiftEmptyVL..." << endl;

    auto pos = shiftIntoPosition(input.begin(), input.end());

    cout << "Position: " << distance(input.begin(), pos) << endl;

    assert(pos == input.begin());

    assert(vector<int>(input.begin(), input.end()) == vector<int>(expected.begin(), expected.end()));

    cout << "Test testShiftEmptyVL completed." << endl;
}

int main() {
    // Run the tests
    testShiftMiddle();
    testShiftBegin();
    testShiftEnd();
    testShiftEmpty();

    testShiftMiddleD();
    testShiftBeginS();
    testShiftEndS();

    testShiftMiddleV();
    testShiftBeginA();
    testShiftEndL();
    testShiftEmptyVL();

    return 0;
}
