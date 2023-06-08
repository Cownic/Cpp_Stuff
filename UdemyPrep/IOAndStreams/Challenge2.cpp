/*
Section 19
Challenge 2
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;

int compare(const string &a,const string &b)
{
    size_t size = a.length();
    int score{0};
    for (int i = 0 ; i < size ; i++)
    {
        if (a[i] == b[i])
        {
            ++score;
        }
    }
    return score;
}

int main()
{
    ifstream in_file{"responses.txt" , ios::in};
    string answerkey{};
    string temp_name{};
    string temp_ans{};
    int temp_score;
    int total{0};
    int num_student{0};
    unordered_map<string, int> result_list;


    if (!in_file)
    {
        cerr << "Error Opening File" << endl;
    }

    getline(in_file, answerkey);

    while (in_file >> temp_name >> temp_ans)
    {
        temp_score = compare(temp_ans, answerkey);
        total += temp_score;
        result_list.insert({temp_name, temp_score});
        num_student++;
    }

    for (const auto &s: result_list)
    {
        cout << left << setw(10) << s.first << setw(10) << s.second << endl;
    }
    cout << "_________________________________________________________" << endl;
    cout << "Average: " << static_cast<double>(total)/num_student << endl;
    in_file.close();

    return 0;
}