#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;



// 获取指定日期是星期几

class Date
{
public:
    int y1, y2;
    unsigned int m1, d1, m2, d2,n;
    Date(int y1, unsigned int m1, unsigned int d1, int y2, unsigned int m2, unsigned int d2,unsigned int days) :
        y1(y1),
        y2(y2),
        m1(m1),
        d1(d1),
        m2(m2),
        d2(d2),
        n(days){};
    string getWeekName(int weekday) 
    {
        static const string weekName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        return weekName[weekday];
    }
    string getWeekday(int y, unsigned int m, unsigned int d) 
    {
        year_month_day date = year{ y } / month{m} / day{d};
        weekday wd = weekday(sys_days(date));
        return getWeekName(wd.c_encoding());
    }
    void addDaysAndPrint(int y, unsigned int m, unsigned int d, int n) {
        year_month_day date = year{ y } / month{m} / day{d};
        sys_days base = sys_days(date);
        sys_days newDay = base + days(n);
        year_month_day result = year_month_day(newDay);
        weekday wd = weekday(newDay);

        cout <<"After " << n << " days: "
            << int(result.year()) << "-"
            << unsigned(result.month()) << "-"
            << unsigned(result.day()) << " ("
            << getWeekName(wd.c_encoding()) << ")" << endl;
    }
    void display()
    {
        cout << "\nBeginning Date: " << y1 << "-" << m1 << "-" << d1
            << " (" << getWeekday(y1, m1, d1) << ")" << endl;
        addDaysAndPrint(y1, m1, d1, n);
        cout << "Comparison Date: " << y2 << "-" << m2 << "-" << d2
            << " (" << getWeekday(y2, m2, d2) << ")" << endl;
    }
};
class WDate
{
public:
    int y1, y2;
    unsigned int m1, d1, m2, d2;
    WDate(int y1, unsigned int m1, unsigned int d1, int y2, unsigned int m2, unsigned int d2) :
        y1(y1),
        y2(y2),
        m1(m1),
        d1(d1),
        m2(m2),
        d2(d2) {};

    int getDaysDiff(int y1, unsigned int m1, unsigned int d1,
        int y2, unsigned int m2, unsigned int d2) {
        year_month_day date1 = year{ y1 } / month{m1} / day{d1};
        year_month_day date2 = year{ y2 } / month{m2} / day{d2};
        sys_days day1 = sys_days(date1);
        sys_days day2 = sys_days(date2);
        return abs((day2 - day1).count());
    }

    void display()
    {
        int diff = getDaysDiff(y1, m1, d1, y2, m2, d2);
        double ans = diff / 7.0;
        int x = 0;
        if (ans * 10 - ans < 0.5)
        {
            x = diff / 7;
        }
        else x = diff / 7 + 1;
        cout << "Result: " << diff << " days and  " << x << " weeks." << endl;
    }
};


int main() {
    int y1, y2;
    unsigned int m1, d1, m2, d2;
    unsigned int day;
    char c;

    cin >> y1 >> c >> m1 >> c >> d1;
    cin >> day;
    cin >> y2 >> c >> m2 >> c >> d2;

    Date x1(y1, m1, d1, y2, m2, d2,day);
    WDate x2(y1, m1, d1, y2, m2, d2);
    x1.display();
    x2.display();

    return 0;
}
