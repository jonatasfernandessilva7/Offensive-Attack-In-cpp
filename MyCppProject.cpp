#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory>
#include "math_utils.h"
#include <thread>
#include <variant>
#include <map>
#include <regex>
#include <windows.h>

using namespace std;

class FileLogger {
private:
    ofstream file;

public:
    FileLogger(const string& filename) {
        file.open(filename);
        if (!file) {
            throw runtime_error("Unable to open file");
        }
    }

    void log(const string& message) {
        file << message << endl;
    }

    ~FileLogger() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }
    ~Resource() {
        cout << "Resource destroyed" << endl;
    }

    void greet() {
        cout << "Hello from resource!" << endl;
    }
};

class InvalidOperation : public runtime_error {
    public:
        explicit InvalidOperation(const string& message) : runtime_error(message) {}
};

class Vector2D {
    public:
        float x, y;

        Vector2D(float x, float y) : x(x), y(y) {}

        Vector2D operator+(const Vector2D& other) const {
            return Vector2D(x + other.x, y + other.y);
        }

        void print() {
            cout << "x: " << x << ", y: " << y << endl;
        }
};

template <typename T>
T maxValue(T a, T b){
    return (a > b) ? a : b;
}


int add(int x, int y);
void double_value(int *ponteiro);
int add_one(int a, int b);
int multiply(int a, int b);
void task(int id);
int divide(int a, int b);

struct Person {
    string name;
    int age;
};

struct IsEven {
    bool operator()(int x) const {
        return x % 2 ==0;
    }
};

using Data = variant<int, float, string>;

void printData(const Data& d);

int main(){

    //Hello World and Basic I/O

    /*
    cout << "Hello, world!" << endl;

    string name;

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Welcome, " << name << "!" << endl;
    */

    //Variables, Arithmetic, and Constants

    /*
    int a = 5;
    int b = 3;

    int sum = a + b;
    int diff = a - b;
    int product = a * b;
    int quotient = a / b;

    const float pi = 3.14159f;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Constant pi: " << pi << endl;
    */

    //Conditionals and User Input

    /*
    int age;

    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are an adult." << endl;
    } else if (age >= 13) {
        cout << "You are a teenager." << endl;
    } else {
        cout << "You are a child." << endl;
    }
    */

    //Loops and Accumulation

    /*
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    cout << "The sum of number from 1 to " << n << " is " << sum << endl;
    */

    //Functions and Pointers

    /*
    int result = add(10, 5);

    cout << "Sum from function: " << result << endl;

    int num = 7;

    cout << "Before doubling: " << num << endl;

    double_value(&num);

    cout << "After doubling: " << num << endl;
    */

    //Using Vector and Iteration
    /*
    vector<int>numbers;

    int input;
    cout << "Enter 5 numbers: " << endl;

    for(int i = 0; i < 5; i++) {
        cin >> input;
        numbers.push_back(input); //append to vector
    }

    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }

    float average = static_cast<float>(sum) / numbers.size(); //transform int to float

    cout << "Average: " << average << endl;
    */

    //Structs and Data Aggregation
    /*
    Person student;

    cout << "Enter your name: " << endl;
    getline(cin, student.name); //Read full line including spaces

    cout << "Enter your age: " << endl;
    cin >> student.age;

    cout << "Student Info - Name: " << student.name << " Age: " << student.age << endl;
    */

    //File I/O (reading an writing text files)
    /*
    string filename = "example.txt";

    //write to a file
    ofstream outfile(filename); //open for output

    if (outfile.is_open()){
        outfile << "This is a test.\n";
        outfile << "Written by C++. \n";
        outfile.close();
    } else {
        cerr << "Failed to open file for writing." << endl;
    }

    //read from the file
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    } else {
        cerr << "Failed to open file for reading." << endl;
    }
    */

    //Dynamic Memory and Array Allocation
    /*
    int size;

    cout << "Enter a size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = (i+1) * 10;
    }

    cout << "Array contents: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

    cout << endl;

    delete[] arr;
    */

    //Funtions Decomposition and Header Inclusion
    /*
    int x = 4, y = 5;

    cout << "Add: " << add_one(x, y) << endl;
    cout << "Multiply: " << multiply(x, y) << endl;
    */

    //Generic Functions with Templates
    /*
    cout << "Max (int): " << maxValue(10, 20) << endl;
    cout << "Max (double): " << maxValue(5.5, 2.3) << endl;
    cout << "Max (char): " << maxValue('a', 'z') << endl;
    */

    //Automatic Resource Management - RAII
    /*
    try {
        FileLogger logger("log.txt");
        logger.log("This is a log message");
        logger.log("Resource management done right");
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    */

    //Lambdas and Functors
    /*
    vector<int> numbers = {1,2,3,4,5,6};

    cout << "All numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;

    int evens = count_if(numbers.begin(), numbers.end(), IsEven());

    cout << "Even numbers count: " << evens << endl;
    */

    //Smart Poniters and shared Ownership
    /*
    shared_ptr<Resource> ptr1 = make_shared<Resource>();
    {
        shared_ptr<Resource> ptr2 = ptr1; //shared ownership
        ptr2 -> greet();
        cout << "Reference count: " << ptr1.use_count() << endl;
    }

    cout << "Back to main to scope. reference count: " << ptr1.use_count() << endl;
    */

    //Multithreading with std::thread
    /*
    thread t1(task,1);
    thread t2(task,2);

    t1.join();
    t2.join();

    cout << "Main thread finished" << endl;
    */

    //std::variant and std::visit fot type-safe unios
    //pode assumir vários tipos
    /*
    Data d1 = 42;
    Data d2 = string("C++ Advanced");
    Data d3 = 3.14f;

    printData(d1);
    printData(d2);
    printData(d3);
    */

    //Custom Eception Class
    /*
    try {
        cout << divide(10, 2) << endl;
        cout << divide(5, 0) << endl;
    }catch (const InvalidOperation& e) {
        cerr << e.what() << endl;
    }
    */

    //Operator Overloading
    /*
    Vector2D a(2.0f, 3.0f);
    Vector2D b(1.5f, 4.5f);

    Vector2D result = a + b;

    result.print();
    */

    //Associative Containers std::map
    /*
    map<string, int> scoreBoard;

    scoreBoard["Alice"] = 100;
    scoreBoard["Bob"] = 200;
    scoreBoard["Charlie"] = 300;

    for (const auto& entry : scoreBoard) {
        cout << entry.first << " " << entry.second << endl;
    }

    string name = "Alice";

    if (scoreBoard.find(name) != scoreBoard.end()) {
        cout << name << scoreBoard[name] << endl;
    }
    */

    //Pattern Matching with std::regex
    /*
    string input;
    regex pattern(R"(\w+@\w+\.\w+)");

    cout << "Enter an email address: ";
    getline(cin, input);

    if (regex_match(input, pattern)) {
        cout << "Valid address!" << endl;
    }else {
        cout << "Invalid address!" << endl;
    }
    */

    //Windows API Programming with C++ Introduction

    //Basic Examples

    //MessageBox whit MessageBoxA
    /*
    MessageBoxA(
        NULL, //no parent window
        "Hello from WinAPI", //message
        "MessageBox Example", //title
        MB_OK | MB_ICONINFORMATION //button and icon type
    );
    */

    //Example 2: Creating and Writing to a File
    /*
    HANDLE hFile = CreateFileA(
        "example1.txt", //file name
        GENERIC_WRITE, //desire access
        0, //share mode
        NULL, //security atributes
        CREATE_ALWAYS, //creation disposition
        FILE_ATTRIBUTE_NORMAL, //flags and atributes
        NULL //template file
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cerr << "CreateFileA failed with error: " << GetLastError() << endl;
        return 1;
    }

    const char* data = "Hello, WinAPI file I/O";
    DWORD bytesWritten;

    BOOL success = WriteFile(hFile, data, strlen(data), &bytesWritten, NULL);

    if (!success) {
        cerr << "WriteFile failed with error: " << GetLastError() << endl;
    } else {
        cout << "Write successful" << "Bytes" << bytesWritten << endl;
    }

    CloseHandle(hFile);
    */

    //Example 3: Allocating Memory with VirtualAlloc
    /*
    LPVOID mem = VirtualAlloc(
        NULL, //let OS choose the address
        1024, //size in bytes
        MEM_COMMIT | MEM_RESERVE, //alocation type
        PAGE_READWRITE //protection
    );

    if (mem == NULL) {
        cerr << "VirtualAlloc failed" << GetLastError() << endl;
        return -1;
    }

    strcpy_s((char*) mem, 1024, "This is dynamic memory via WinAPI");

    cout << "Memory content: " << (char*)mem << endl;

    VirtualFree(mem, 0, MEM_RELEASE);
    */

    //Example 4: Getting System Information with GetSystemInfo
    /*
    SYSTEM_INFO sysInfo;

    GetSystemInfo(&sysInfo);

    cout << "Processor architecture: " << sysInfo.wProcessorArchitecture << endl;
    cout << "Page size: " << sysInfo.dwPageSize << endl;
    cout << "Number of processors: " << sysInfo.dwNumberOfProcessors << endl;
    */

    //Example 5: Sleep and Beep (Timing and Sound)
    /*
    Sleep(2000);

    Beep(750, 300); // Play a beep sound (frequency 750 Hz, duration 300 ms)
    */

    //Intermediate Examples
    //Example 6: Creating a New Process with CreateProcessA
    /*
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi; //receive process info

    LPCSTR appName = "C:\\Windows\\System32\\notepad.exe";
    BOOL success = CreateProcessA(
        appName,
        NULL, //command line
        NULL, //process security attributes
        NULL, //Thread security attributes
        FALSE, //inherit handles
        0, //creation flags
        NULL, //environment
        NULL, //current directory
        &si,
        &pi
    );

    if (!success) {
        cerr << "CreateProcess failed" << GetLastError() << endl;
        return 1;
    }

    cout << "Process created - PID: " << pi.dwProcessId << endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    */

    //Example 7: Getting the Current Process and Thread IDs
    /*
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    cout << "Process ID: " << pid << endl;
    cout << "Thread ID: " << tid << endl;
    */

    //Example 8: Reading a File with WinAPI
    /*
    HANDLE hFile = CreateFileA(
        "example1.txt", //file name
        GENERIC_READ, //desire access
        FILE_SHARE_READ, //share mode
        NULL, //security atributes
        OPEN_EXISTING, //open only if exists
        FILE_ATTRIBUTE_NORMAL, //flags and atributes
        NULL //template file
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cerr << "Unable to open file" << GetLastError() << endl;
        return 1;
    }

    char buffer[128] = {0};
    DWORD bytesRead;

    BOOL success = ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL);

    if (!success) {
        cerr << "Unable to read file" << GetLastError() << endl;
    } else {
        cout << "Read: " << bytesRead << " Bytes: " << buffer << endl;
    }

    CloseHandle(hFile);
    */

    //Example 9: Using OpenProcess to Access Another Process
    /*
    DWORD pid;

    cout << "Enter the PID of the process to open: " << endl;
    cin >> pid;

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);

    if (hProcess == NULL) {
        cerr << "Unable to open process" << GetLastError() << endl;
        return 1;
    }

    cout << "Process opened successfuly (handle: " << hProcess << ")" << endl;

    CloseHandle(hProcess);
    */

    return 0;
}

int add(int x, int y){
    return x + y;
}

void double_value(int *ponteiro){
    *ponteiro = *ponteiro * 2;
}

int add_one(int a, int b){
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}

void task(int id) {
    cout << "Thread" << id << "Is running" << endl;
}

void printData(const Data& d) {
    visit([](auto&& value) {
        cout << "Value: " << value << endl;
    }, d);
}

int divide(int a, int b) {
    if (b == 0) {
        throw InvalidOperation("Divide by zero is not allowed");
    }
    return a / b;
}

