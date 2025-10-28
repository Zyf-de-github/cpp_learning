#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class teacher
{
public:
    vector<vector<int>> teacher_points;
    vector<int> teacher_average;
    vector<vector<int>> teacher_achievement;
    vector<int> teacher_achievement_avg;
    vector<vector<int>> teacher_grade;
    vector<int> teacher_grade_avg;
    teacher()
    {
        teacher_points.clear();
        teacher_average.clear();
        teacher_achievement.clear();
        teacher_achievement_avg.clear();
        teacher_grade.clear();
        teacher_grade_avg.clear();
    }
    void add_average(double x)
    {
        teacher_average.push_back(x);
    }
    void add_point(vector<int> y)
    {
        teacher_points.push_back(y);
    }
    void add_achievement(vector<int> y)
    {
        teacher_achievement.push_back(y);
    }
    void add_achievement_avg(int x)
    {
        teacher_achievement_avg.push_back(x);
    }
    void add_grade(vector<int> y)
    {
        teacher_grade.push_back(y);
    }
    void add_grade_avg(int x)
    {
        teacher_grade_avg.push_back(x);
    }
    void show_record()
    {
        int m = teacher_points.size();
        int n = teacher_points[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Teacher " << i + 1 << " -> Student " << j + 1 << ": " << teacher_points[i][j] << endl;
            }
            cout << "The average record (Teacher " << i + 1 << "): " << teacher_average[i] << endl;
        }
    }
    void show_achievement()
    {
        int m = teacher_achievement.size();
        int n = teacher_achievement[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Teacher " << i + 1 << " -> Graduate Student " << j + 1 << ": " << teacher_achievement[i][j] << endl;
            }
            cout << "The average achievement (Teacher " << i + 1 << "): " << teacher_achievement_avg[i] << endl;
        }
    }
    void show_grade()
    {
        int m = teacher_grade.size();
        int n = teacher_grade[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Student " << j + 1 << " -> Teacher " << i + 1 << ": " << teacher_grade[i][j] << endl;
            }
            cout << "The average grade of Teacher " << i + 1 << ": " << teacher_grade_avg[i] << endl;
        }
    }
};

class student
{
public:
    vector<vector<int>> students_points;
    vector<int> students_average;
    student()
    {
        students_points.clear();
        students_average.clear();
    }
    void add_average(int x)
    {
        students_average.push_back(x);
    }
    void add_point(vector<int> y)
    {
        students_points.push_back(y);
    }
};

class grdstudent : public student
{
public:
    vector<vector<int>> achievements;
    vector<int> achievements_avg;
    grdstudent()
    {
        achievements.clear();
        achievements_avg.clear();
    }
    void add_achievement(vector<int> y)
    {
        achievements.push_back(y);
    }
    void add_achievement_avg(int x)
    {
        achievements_avg.push_back(x);
    }
};

class supervisor
{
public:
    vector<vector<int>> supervisor_points;
    vector<int> supervisor_avg;
    supervisor()
    {
        supervisor_points.clear();
        supervisor_avg.clear();
    }
    void add_point(vector<int> y)
    {
        supervisor_points.push_back(y);
    }
    void add_avg(int x)
    {
        supervisor_avg.push_back(x);
    }
    void show()
    {
        int m = supervisor_points.size();
        int n = supervisor_points[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Supervisor " << i + 1 << " -> Teacher " << j + 1 << ": " << supervisor_points[i][j] << endl;
            }
        }
    }
};

int main()
{
    int ns, nt, ng, nu;
    cin >> ns >> nt >> ng >> nu;
    teacher T;
    grdstudent G;
    student U;
    supervisor S;
    for (int i = 0; i < nt; i++)
    {
        vector<int> y;
        int total = 0;
        for (int j = 0; j < nu; j++)
        {
            int x;
            cin >> x;
            total += x;
            y.push_back(x);
        }
        T.add_point(y);
        T.add_average(round(double(total) / nu));
    }
    for (int i = 0; i < nt; i++)
    {
        vector<int> y;
        int total = 0;
        for (int j = 0; j < ng; j++)
        {
            int x;
            cin >> x;
            total += x;
            y.push_back(x);
        }
        T.add_achievement(y);
        T.add_achievement_avg(round(double(total) / ng));
    }
    for (int i = 0; i < nt; i++)
    {
        vector<int> y;
        int total = 0;
        for (int j = 0; j < ng; j++)
        {
            int x;
            cin >> x;
            total += x;
            y.push_back(x);
        }
        G.add_achievement(y);
        G.add_achievement_avg(round(double(total) / ng));
    }
    for (int i = 0; i < nt; i++)
    {
        vector<int> y;
        int total = 0;
        for (int j = 0; j < nu; j++)
        {
            int x;
            cin >> x;
            total += x;
            y.push_back(x);
        }
        T.add_grade(y);
        T.add_grade_avg(round(double(total) / nu));
    }
    for (int i = 0; i < ns; i++)
    {
        vector<int> y;
        int total = 0;
        for (int j = 0; j < nt; j++)
        {
            int x;
            cin >> x;
            total += x;
            y.push_back(x);
        }
        S.add_point(y);
        S.add_avg(round(double(total) / nt));
    }
    T.show_record();
    T.show_achievement();
    S.show();
    T.show_grade();
    return 0;
}


#endif