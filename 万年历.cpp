#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cassert>
#include <conio.h>
#include <stdio.h> 
#include <windows.h>

using namespace std;

#pragma warning(disable:4996)



//闰年判断
int ifRun(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return 1;//是闰年
    }
    else {
        return 0;//不是闰年
    }
}
void showTime(int y, int m, int d, int w) {
    string c;
    switch (w)
    {
    case 1:c = "一"; break;
    case 2:c = "二"; break;
    case 3:c = "三"; break;
    case 4:c = "四"; break;
    case 5:c = "五"; break;
    case 6:c = "六"; break;
    case 7:c = "日"; break;
    default:c = "未知错误"; break;
    }


    cout << "日期：" << y << "年" << m << "月" << d << "日" << ",星期" << c << ",";
    if (ifRun(y)) {
        cout << "是闰年" << endl;
    }
    else {
        cout << "不是闰年" << endl;
    }
}
//绘制日历
void draw(int y, int m, int d, int w) {
    int dayOfWeek = 1;//一周
    int dayOfMonth = 1;//一个月
    printf("\n\n");
    showTime(y, m, d, w);
    printf("\n");
    printf("        %d年", y);
    if (ifRun(y)) {
        printf("（闰）\n");
    }
    else {
        printf("（非闰）\n");
    }
    printf("        %d       月\n", m);
    printf("一  二  三  四  五  六  日\n");
    int fw = w;//fw是月份的第一天对应周位置
    fw = fw - ((d - 1) % 7);
    while (fw <= 0) {
        fw = fw + 7;
    }
    while (fw > 7) {
        fw = fw - 7;
    }
    int n;    //开头空格计数
    n = 2 * (fw - 1);

    while (n > 0) {
        printf("  ");

        n--;
    }
    dayOfWeek = fw;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        while (dayOfMonth <= 31) {
            while (dayOfWeek <= 7) {
                if (dayOfMonth < 10) {

                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);//变色突出
                        printf(" %d", dayOfMonth);

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//变回默认
                        printf("  ");
                    }
                    else {

                        printf(" %d  ", dayOfMonth);
                    }
                }
                if (dayOfMonth >= 10) {
                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf("%d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf("%d  ", dayOfMonth);
                    }
                }
                dayOfWeek++;
                dayOfMonth++;
                if (dayOfMonth > 31) {
                    break;
                }
            }
            printf("\n");
            dayOfWeek = 1;
        }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        while (dayOfMonth <= 30) {
            while (dayOfWeek <= 7) {
                if (dayOfMonth < 10) {

                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf(" %d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf(" %d  ", dayOfMonth);
                    }
                }
                if (dayOfMonth >= 10) {
                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf("%d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf("%d  ", dayOfMonth);
                    }
                }
                dayOfWeek++;
                dayOfMonth++;
                if (dayOfMonth > 30) {
                    break;
                }
            }
            printf("\n");
            dayOfWeek = 1;
        }
    }
    if (m == 2 && ifRun(y)) {
        while (dayOfMonth <= 29) {
            while (dayOfWeek <= 7) {
                if (dayOfMonth < 10) {

                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf(" %d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf(" %d  ", dayOfMonth);
                    }
                }
                if (dayOfMonth >= 10) {
                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf("%d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf("%d  ", dayOfMonth);
                    }
                }
                dayOfWeek++;
                dayOfMonth++;
                if (dayOfMonth > 29) {
                    break;
                }
            }
            printf("\n");
            dayOfWeek = 1;
        }
    }

    if (m == 2 && ifRun(y) == 0) {
        while (dayOfMonth <= 28) {
            while (dayOfWeek <= 7) {
                if (dayOfMonth < 10) {

                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf(" %d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf(" %d  ", dayOfMonth);
                    }
                }
                if (dayOfMonth >= 10) {
                    if (dayOfMonth == d) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
                        printf("%d", dayOfMonth);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("  ");
                    }
                    else {
                        printf("%d  ", dayOfMonth);
                    }
                }
                dayOfWeek++;
                dayOfMonth++;
                if (dayOfMonth > 28) {
                    break;
                }
            }
            printf("\n");
            dayOfWeek = 1;
        }
    }
}

class Init {
private:
    time_t nowtime;//时间变量
    struct tm* p;//时间结构体

public:
    Init() {
        time(&nowtime);//获取时间函数,等同于nowtime = time(NULL);
        p = localtime(&nowtime);//本地时间函数
    }
    void creat() {
        draw(p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_wday + 1);
    }
    Init(const Init& init) {
        nowtime = init.nowtime;
        p = init.p;
    }

    int getYear() {
        return p->tm_year + 1900;
    }
    int getMonth() {
        return p->tm_mon + 1;
    }
    int getDay() {
        return p->tm_mday;
    }

};
//日期类
class wdata
{
public:
    wdata();//默认构造函数
    int ifRun(int y); //判断是否是闰年
    void showTime(int y, int m, int d, int w);
    void draw(int y, int m, int d, int w);
    void select_1();
    void select_2();
private:
    string year;
    string month;
    string week;
    string day;
};

//备忘录类
class Note
{
public:
    Note();//默认构造函数
    void new_note();//新建备忘
    void alter_note();//修改备忘
    void delet_note();//删除备忘
    void scan_note();//浏览备忘
    char choose_time();//选择备忘的时间
    char choose_thing();//选择备忘的种类
protected:
    string validPath;//存储地址
private:
    string signs;//标题
    string data;//日期
    string des;//事件描述
};

class Calender {
private:
    int y, m, d;//年月日
    int w;//周位置

    //以2020年1月1日作为基准，定义两个正向计算和负向计算
    int plusCalc(int y, int m, int d) {
        int tempY = 2020;
        int n = 0;
        int w = 3;//2020/1/1为星期三
        while (tempY < y) {
            if (((tempY % 4 == 0 && tempY % 100 != 0) || tempY % 400 == 0)) {
                n = n + 366;//闰年
            }
            else {
                n = n + 365;
            }
            tempY++;
        }
        w = w + n % 7;
        while (w > 7) {
            w = w - 7;
        }
        //此时w为输入年份1月1日的周位置
        return thisYearCalc(w, m, d, y);
    }
    int minusCalc(int y, int m, int d) {
        int tempY = y;
        int n = 0;
        int w = 3;//2020/1/1为星期三
        while (tempY < 2020) {
            if (((tempY % 4 == 0 && tempY % 100 != 0) || tempY % 400 == 0)) {
                n = n + 366;
            }
            else {
                n = n + 365;
            }
            tempY++;
        }
        w = w - n % 7;
        while (w <= 0) {
            w = w + 7;
        }
        //此时w为输入年份1月1日的周位置
        return thisYearCalc(w, m, d, y);

    }
    //在当前年份中计算
    //w是当前年一月一日的周位置
    int thisYearCalc(int y, int m, int d, int w) {
        int tempM = 1;//月计数
        int tempD = 1;//周计数
        int n = 0;
        while (tempM < m) {
            if (tempM == 2 && ifRun(y)) {
                n += 29;

            }
            else {
                switch (tempM) {
                case 1:n += 31; break;
                case 3:n += 31; break;
                case 5:n += 31; break;
                case 7:n += 31; break;
                case 8:n += 31; break;
                case 10:n += 31; break;
                case 12:n += 31; break;
                case 4:n += 30; break;
                case 6:n += 30; break;
                case 9:n += 30; break;
                case 11:n += 30; break;
                case 2:n += 28; break;
                }
            }
            tempM++;
        }//到达所求月份
        while (tempD < d) {
            n++;
            tempD++;
        }
        w = w + n % 7;
        while (w > 7) {
            w = w - 7;
        }
        //w是当前的真实周位置
        return w;
    }
public:
    void calender(int year, int month, int day) {
        this->y = year;
        this->m = month;
        this->d = day;

        if (y >= 2020) {
            w = plusCalc(y, m, d);
        }
        else {
            w = minusCalc(y, m, d);
        }
        draw(y, m, d, w);
    }

    void printMenuInstruction() {
        /*********************************
        printf("需要查询请按'1'\n");
        printf("后一页请按'd'\n");
        printf("前一页请按'a'\n");
        printf("结束程序请按'q'\n");
        **************************************/
        system("cls");
        cout << "_____________________________ " << endl;
        cout << "      1.  查 询               " << endl;
        cout << "                              " << endl;
        cout << "      2.  上 一 页            " << endl;
        cout << "                              " << endl;
        cout << "      3.  下 一 页            " << endl;
        cout << "                              " << endl;
        cout << "      4.  返 回        " << endl;
        cout << "_____________________________ " << endl;
    }

    //判断输入的日期是否合法
    int judge(int y, int m, int d) {
        if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d >= 31) {
            return 0;//范围错误
        }
        if (m == 2 && d > 29) {
            return 0;//2月错误
        }
        if (ifRun(y) == 0 && d > 28) {
            return 0;//闰年错误
        }
        if ((m == 4 || m == 6) && d >= 31) {
            return 0;//小月错误
        }
        if (m >= 9 && m % 2 == 1 && d >= 31) {
            return 0;//小月错误
        }
        return 1;//正常  
    }
    //返回1 再次查询
    //返回0 结束查询
    void checkDate(char motion) {
        while (1)
        {
            system("cls");
            printf("输入年月日，以空格隔开\n");

            cin >> y;
            cin >> m;
            cin >> d;
            cout << endl;
            if (judge(y, m, d)) {
                system("cls");
                cout << "_____________________________ " << endl;
                cout << "      1.  上 一 页            " << endl;
                cout << "                              " << endl;
                cout << "      2.  下 一 页            " << endl;
                cout << "                              " << endl;
                cout << "      3.  返回         " << endl;
                cout << "_____________________________ " << endl;
                calender(y, m, d);
            }
            else {
                printf("输入无效,将返回主界面\n");
                system("pause");
                system("cls");
                break;
            }
            printf("\n");
            motion = _getch();

            if (motion == '3') {
                system("cls");
                break;
            }

            if (motion == '1' || motion == '2') {
                while (1) {
                    if (motion == '1') {

                        system("cls");
                        cout << "_____________________________ " << endl;
                        cout << "      1.  上 一 页            " << endl;
                        cout << "                              " << endl;
                        cout << "      2.  下 一 页            " << endl;
                        cout << "                              " << endl;
                        cout << "      3.  返回         " << endl;
                        cout << "_____________________________ " << endl;
                        if (m == 1) {
                            y--;
                            m = 12;
                        }
                        else {
                            m--;
                        }
                        calender(y, m, d);

                    }
                    if (motion == '2') {
                        system("cls");
                        cout << "_____________________________ " << endl;
                        cout << "      1.  上 一 页            " << endl;
                        cout << "                              " << endl;
                        cout << "      2.  下 一 页            " << endl;
                        cout << "                              " << endl;
                        cout << "      3.  返回         " << endl;
                        cout << "_____________________________ " << endl;
                        if (m == 12) {
                            y++;
                            m = 1;
                        }
                        else {
                            m++;
                        }
                        calender(y, m, d);
                    }
                    if (motion == '3') {
                        system("cls");
                        break;
                    }
                    motion = _getch();
                }
            }
            else {
                continue;
            }
            break;
        }
    }
    //d
    void nextPage(int& year, int& month, int& day) {
        if (month == 12) {
            year++;
            month = 1;
        }
        else {
            month++;
        }
        calender(year, month, day);
    }
    //a
    void previousPage(int& year, int& month, int& day) {
        if (month == 1) {
            year--;
            month = 12;
        }
        else {
            month--;
        }
        calender(year, month, day);
    }

};

class calendar_notebook :public Note, public wdata
{
public:
    char first_paper();//首页
    void notes_manage();//备忘录管理
    void search_data();//日历查询
    void take_path(string path);//获得存储地址
    
};

void calendar_notebook::take_path(string path) {
    validPath = path;
}

void calendar_notebook::search_data()
{
    while (1)
    {
        system("cls");
        cout << "                              万 年 历                          " << endl;
        cout << "_______________________________________________________________" << endl;
        cout << "                                                               " << endl;
        cout << "               1.  查询入口                                    " << endl;
        cout << "                                                               " << endl;
        cout << "                                                               " << endl;
        cout << "               2.  返   回                                     " << endl;
        cout << "_______________________________________________________________" << endl;
        char select = getch();
        switch (select)
        {
        case'1':
            select_1();
            break;
        case'2':
            return;
            break;
        default:
            break;
        }
    }
}

void wdata::select_1()
{
    int y, m, d;//输入的年月日

    int& year = y;
    int& month = m;
    int& day = d;

    char motion; //motion接收用户操作
    motion = ' ';

    Init init;
    y = init.getYear();
    m = init.getMonth();
    d = init.getDay();
    Calender calender;
    calender.printMenuInstruction();
    init.creat();

    while (1) {
        //日历查询功能循环
        while (1) {
            motion = _getch();
            if (motion == '1') {
                //查询
                calender.checkDate(motion);
                calender.printMenuInstruction();
                y = init.getYear();
                m = init.getMonth();
                d = init.getDay();
                init.creat();
            }
            if (motion == '2') {
                system("cls");
                calender.printMenuInstruction();
                calender.previousPage(year, month, day);//上一页
            }
            if (motion == '3') {

                system("cls");
                calender.printMenuInstruction();
                calender.nextPage(year, month, day);//下一页
            }
            if (motion == '4') {
                return;//回到登录界面
            }
        }
    }
}

//默认构造函数
Note::Note()
{
    des = "xxx";//事件描述
    signs = "xxx";//标题
    data = "xxx";//日期
}

//默认构造函数
wdata::wdata()
{
    week = "xxx";
    month = "xxx";
    day = "xxx";
    year = "xxx";
}

//首页
char calendar_notebook::first_paper()
{
    system("cls");
    char choose;

    cout << endl;
    cout << "                    万  年  历                              " << endl;
    cout << "_____________________________________________________________" << endl;
    cout << "                                                            " << endl;
    cout << "              1.  备忘录管理                            " << endl;
    cout << "                                                        " << endl;
    cout << "              2.  日历查询                              " << endl;
    cout << "                                                        " << endl;
    cout << "              3.  账号管理                              " << endl;
    cout << "                                                        " << endl;
    cout << "              4.  关闭万年历                            " << endl;
    cout << "_________________________________________________________" << endl;
    cout << "你要选择执行的功能是：" << endl;
    cin >> choose;
    return choose;
}




//备忘录管理
void calendar_notebook::notes_manage()
{
    char choose;
    while (1)
    {
        system("cls");
        cout << "                 备 忘 录 管 理                              " << endl;
        cout << "_________________________________________________________" << endl;
        cout << "                                                         " << endl;
        cout << "                 1.  新建备忘                            " << endl;
        cout << "                                                         " << endl;
        cout << "                 2.  备忘录浏览                          " << endl;
        cout << "                                                         " << endl;
        cout << "                 3.  修改备忘                            " << endl;
        cout << "                                                         " << endl;
        cout << "                 4.  删除备忘                            " << endl;
        cout << "                                                         " << endl;
        cout << "                 5.  返回                                " << endl;
        cout << "__________________________________________________________" << endl;
        cout << "你要选择执行的功能是：" << endl;
        cin >> choose;
        switch (choose)
        {
        case '1':
            calendar_notebook::new_note();//新建备忘
            break;
        case '2':
            calendar_notebook::scan_note();//浏览备忘
            break;
        case '3':
            calendar_notebook::alter_note();//修改备忘
            break;
        case '4':
            calendar_notebook::delet_note();//删除备忘
            break;
        case '5':
            return;
        default:
            break;
        }
    }
}

char  Note::choose_time()//辅助新建备忘的完成，选择备忘的种类
{
    char choose;
    cout << "              选择备忘记录时间                           " << endl;
    cout << "________________________________________________________" << endl;
    cout << "                                                        " << endl;
    cout << "              1.  当前时间                              " << endl;
    cout << "                                                        " << endl;
    cout << "              2.  未来时间                            " << endl;
    cout << "                                                        " << endl;
    cout << "              3.  过去时间（记录）                            " << endl;
    cout << "                                                        " << endl;
    cout << "              4.  取消                            " << endl;
    cout << "________________________________________________________" << endl;
    cout << "你要选择执行的功能是:";
    cin >> choose;
    return(choose);
}

char Note::choose_thing()
{
    char choose;
    cout << "              选择备忘的种类                           " << endl;
    cout << "________________________________________________________" << endl;
    cout << "                                                        " << endl;
    cout << "              1.  过去时间的（包括当前）备忘                            " << endl;
    cout << "                                                        " << endl;
    cout << "              2.  以后时间的备忘                            " << endl;
    cout << "                                                        " << endl;
    cout << "              3.  取消                            " << endl;
    cout << "________________________________________________________" << endl;
    cout << "你要选择执行的功能是:";
    cin >> choose;
    return(choose);
}
//新建备忘过程：首先选择备忘类型，然后输入内容，将其存储在一个空文件中，
//然后将备忘的标题和时间输出到专门记录时间和标题的title.txt文件中，然后新建一个以标题为名txt文件，里面记录了这条备忘录的全部详细信息。
void Note::new_note()
{  
    string address;
    address = validPath + "\\temp.txt";
    ofstream tempFile(address.c_str(), ios_base::out);//打开临时输出文件，用于输出。
    time_t timer;
    struct tm tm1;
    char a;
    while (1) {
        system("cls");
        a = choose_time();
        if (a == '1')
        {
            time(&timer);
            cout << endl << "时间 : " << asctime(localtime(&timer)) << endl;//tm时间结构体
            break;
        }
        if (a == '2' || a == '3')
        {
            int  year, month;
            cout << "请输入备忘将要发生的时间(年份应该大于1970年)：" << endl;
            cout << "年 " << "月 " << "日 " << "小时 " << "例如： 2020 1 1 1" << endl;
            cin >> year >> month >> tm1.tm_mday >> tm1.tm_hour;
            tm1.tm_year = year - 1900;
            tm1.tm_mon = month - 1;
            tm1.tm_min = 0;
            tm1.tm_sec = 0;
            tm1.tm_isdst = 0;
            time(&timer);
            timer = mktime(&tm1);
            cout << "时间 : " << asctime(localtime(&timer)) << endl;
            break;
        }
        if (a == '4') {
            return;
        }
    }
    

    int control = 0;
    while (control == 0) {
        cout << "标题 : ";
        cin >> signs;
        if (a == '1' || a == '3') {
            ifstream testFile;
            address = validPath + "\\past_things_title.txt";
            testFile.open(address.c_str());
            string x_signs;
            if (testFile.eof() == 1) control = 1;
            while (testFile.eof() != 1)
            {
                getline(testFile, x_signs);
                if (signs == x_signs) {
                    cout << "重名标题，请重新输入" << endl;
                    testFile.close();
                    control = 0;
                    break;
                }
                else  control = 1;
                getline(testFile, x_signs);
            }
            testFile.close();
        }
        if (a == '2') {
            ifstream testFile;
            address = validPath + "\\memory_things_title.txt";
            testFile.open(address.c_str());
            string x_signs;
            if (testFile.eof() == 1) control = 1;
            while (testFile.eof() != 1)
            {
                testFile.get();
                getline(testFile, x_signs);
                if (signs == x_signs) {
                    cout << "重名标题，请重新输入" << endl;
                    testFile.close();
                    control = 0;
                    break;
                }
                else  control = 1;
                getline(testFile, x_signs);
            }
            testFile.close();
        }
    }


    tempFile << "标题 : " << signs << endl << "时间:" << asctime(localtime(&timer)) << endl << "内容 : ";
    cout << endl << "内容(以#号键结束) : " << endl;
    tempFile << endl;
    string str;
    while (1)
    {
        cin >> str;
        if (str[str.length() - 1] == '#')//判断输入的末尾是否为#
        {
            str[str.length() - 1] = ' ';
            tempFile << str << endl << endl;
            break;
        }
        tempFile << str << endl << endl;
    }
    tempFile.close();
    if (a == '1' || a == '3')
    {
        address = validPath + "\\past_things_title.txt";
        ofstream reFile0(address.c_str(), ios::app);//打开输出文件reFile0，并且在文件尾添加数据,reFile0存放的是所有备忘的标题和时间
        reFile0 << signs << endl << asctime(localtime(&timer)) << endl;
        reFile0.close();
    }
    if (a == '2')
    {
        address = validPath + "\\memory_things_title.txt";
        ofstream reFile0(address.c_str(), ios::app);
        reFile0 << signs << endl << asctime(localtime(&timer)) << endl;
        reFile0.close();
    }
    string fname = validPath + "\\" + signs + ".txt";//新建一个以标题为名称的txt文件，将该备忘的所有信息记录在该文件里面
    ofstream reFile(fname.c_str());
    address = validPath + "\\temp.txt";
    ifstream tempFile0(address.c_str());
    assert(tempFile0);
    reFile << tempFile0.rdbuf();//rdbuf重定向缓冲区，把tempFile0流重新定向到reFile，也就是输出到tempFile的内容，变成输出到reFile里 
    tempFile0.close();
    reFile.close();
    cout << endl << endl << "记录已经保存!!!" << endl << endl;
    system("pause");
}
/*修改过程：首先将所有备忘的标题和时间按顺序显示出来，操作者选择要修改的备忘种类和备忘标题，然后找到所选备忘的文件并打开，将该备忘详细情况显示出来，
让操作者再确认一下是否要修改*/
void Note::alter_note()
{
    while (1)
    {
        system("cls");
        cout << endl << "请选择你想修改的种类" << endl;
        char a;
       
        ifstream reFile;
        while (1) {
            a = choose_thing();
            if (a == '1')
            {
                reFile.open(validPath + "\\past_things_title.txt", ios_base::in);
                break;
            }
            if (a == '2')
            {
                reFile.open(validPath + "\\memory_things_title.txt", ios_base::in);
                break;
            }
            if (a == '3') {
                return;
            }

        }
        
        int i = 1;
        while (reFile >> signs)//将title.txt文件里面的内容都读到标准输出界面上来
        {
            reFile.get();
            getline(reFile, data);
            cout << i << ".\t" << setiosflags(ios::left) << setw(30) << signs << " " << data << endl << endl;
            i++;
        }
        reFile.close();
        cout << endl << i << ".\t返回" << endl << endl;
        int select;//选择备忘类型
        while (1) {
            cout << endl << "请选择你想修改的备忘(或者执行的功能）: " << endl << endl;
            cin >> select;
            if (select == i)
                break;
        }
        ifstream reFile1;
        if (a == '1')
        {
            reFile1.open(validPath + "\\past_things_title.txt", ios_base::in);
        }
        if (a == '2')
        {
            reFile1.open(validPath + "\\memory_things_title.txt", ios_base::in);
        }
        assert(reFile1);
        i = 1;
        //修改
        while (reFile1 >> signs)
        {
            reFile1.get();
            getline(reFile1, data);
            if (i == select)
            {
                string fname = validPath + "\\" + signs + ".txt";
                system("cls");
                ifstream reFile2(fname.c_str());
                assert(reFile2);
                cout << endl << "你想修改的内容如下 : " << endl << endl;

                cout << reFile2.rdbuf();
                reFile2.close();
                cout << "确定要修改吗？确定请输入1，取消请输入2。" << endl;
                int i = 0;
                cin >> i;
                if (i == 1)
                {
                    cout << endl << endl << "请在下面输入新的内容 (以'#'结束): " << endl << endl;
                    cout << "内容 : ";

                    ofstream reFile3(fname.c_str());
                    reFile3 << "标题:" << signs << endl << "时间:" << data << endl << "内容:" << endl;
                    string str;
                    while (1)
                    {
                        cin >> str;
                        if (str[str.length() - 1] == '#')
                        {
                            str[str.length() - 1] = ' ';
                            reFile3 << str << endl;
                            break;
                        }
                        reFile3 << str << endl;
                    }
                    reFile3.close();
                    cout << endl << endl << "内容更新完成!!!!" << endl << endl;
                }
                if (i == 2)
                {
                    cout << "未修改" << endl;
                }
                if (i != 2 && i != 1)
                {
                    cout << "输入了错误指令" << endl;
                }
                system("pause");
                return;
            }
            i++;
        }
        reFile1.close();
    }
}
/*删除过程： 操作者先选择要删除备忘的种类，再将该种类的所有备忘显示给操作者看，然后让操作者选择，然后将该条记录删除*/
void Note::delet_note()
{
    while (1)
    {
        system("cls");
        char a;
        string address;
        ifstream reFile;
        while (1) {
            a = choose_thing();

            if (a == '1')
            {
                reFile.open(validPath + "\\past_things_title.txt", ios_base::in);
                break;
            }
            if (a == '2')
            {
                reFile.open(validPath + "\\memory_things_title.txt", ios_base::in);
                break;
            }if (a == '3') {
                return;
            }
        }
       
        int i = 1;
        //将所有时间即(title.txt文件的内容)读入到内存并且显示在标准输出界面上
        if (reFile)
        {
            while (reFile >> signs)
            {
                reFile.get();
                getline(reFile, data);
                cout << i << ".\t" << setiosflags(ios::left) << setw(30) << signs << " " << data << endl << endl;
                i++;
            }
        }
        else
        {
            cout << "无内容" << endl;
        }
        reFile.close();
        cout << endl << i << ".\t返回" << endl << endl;
        int select;//选择要删除的备忘
        while (1) {
            cout << "选择 : ";
            cin >> select;
            if (select == i)
                break;
        }
        ifstream reFile2;
        if (a == '1')
        {
            reFile2.open(validPath + "\\past_things_title.txt", ios_base::in);
        }
        if (a == '2')
        {
            reFile2.open(validPath + "\\memory_things_title.txt", ios_base::in);
        }
        assert(reFile2);
        ofstream tempFile(validPath + "\\temp.txt");
        i = 1;
        /*删除的过程：将未选中的时间都输出在文件temp.txt中，最后又将temp.txt中的内容输出到文件title.txt中*/
        int b;
        while (reFile2 >> signs)
        {
            reFile2.get();
            getline(reFile2, data);
            if (i != select)
                tempFile << signs << endl << data << endl << endl;
            else
            {
                system("cls");
                cout << endl << endl << "你想删除的备忘内容如下 : " << endl << endl;
                string fname = validPath + "\\" + signs + ".txt";
                ifstream reFilex(fname);
                assert(reFilex);
                cout << reFilex.rdbuf();
                reFilex.close();
                cout << "确定要删除吗？确定请输入1，取消请输入2。" << endl;
                cin >> b;
                if (b == 1) {
                    string command = "del " + fname;//目标路径
                    system(command.c_str());//删除文件
                }
                if (b == 2)
                {
                    tempFile << signs << endl << data << endl << endl;
                    system("pause");
                }
                if (b != 2 && b != 1)
                {
                    cout << "输入了错误指令" << endl;
                    tempFile << signs << endl << data << endl << endl;
                }
            }i++;
        }
        reFile2.close();
        tempFile.close();
        ifstream tempFile0(validPath + "\\temp.txt");
        assert(tempFile0);
        ofstream reFile3;
        if (a == '1')
        {
            reFile3.open(validPath + "\\past_things_title.txt");
        }
        if (a == '2')
        {
            reFile3.open(validPath + "\\memory_things_title.txt");
        }
        reFile3 << tempFile0.rdbuf();
        tempFile0.close();
        reFile3.close();
        if (b == 1)
        {
            cout << endl << endl << "该条备忘记录已经删除!!!" << endl << endl;
        }
        else
        {
            cout << endl << endl << "该条备忘记录未删除!!!" << endl << endl;
        }

        system("pause");
    }
}
/*浏览备忘过程：操作者先选择浏备忘的种类，然后将相对应事件种类的title.txt文件打开，让操作者浏览所有备忘的标题和时间，
最后再选择要浏览的备忘,系统将事件的整个详细情况显示出来 */
void Note::scan_note()
{
    string address;
    while (1)
    {

        cout << endl << "请选择你想浏览备忘的种类" << endl;
        char a;
        ifstream reFile;
        while (1) {
            system("cls");
            a = choose_thing();
            if (a == '3')
            {
                return;
            }
            if (a == '1')
            {
                address = validPath + "\\past_things_title.txt";
                reFile.open(address.c_str(), ios_base::in);
                break;
            }
            if (a == '2')
            {
                address = validPath + "\\memory_things_title.txt";
                reFile.open(address.c_str(), ios_base::in);
                break;
            }
        }


        cout << endl << "备忘录查询" << endl << endl;

        
        int i = 1;
        cout << "序号\t" << setiosflags(ios::left) << setw(30) << "标题 " << "\t日期" << endl << endl;
        //将title.txt文件的内容全部读入到内存，并且显示在标准输出界面上
        if (reFile)
        {
            while (reFile >> signs)
            {
                reFile.get();
                getline(reFile, data);
                cout << i << ".\t" << setiosflags(ios::left) << setw(30) << signs << " "
                    << data << endl << endl;
                i++;
            }
        }
        else
        {
            cout << "无内容" << endl;
        }
        reFile.close();
        cout << i << ".\t返回" << endl;
        int select;//选择
        while (1) {
            cout << endl << "选择 : ";
            cin >> select;
            if (select == i)
                break;
        }
        i = 1;        
        ifstream reFile1;
        if (a == '1')
        {
            address = validPath + "\\past_things_title.txt";
            reFile1.open(address.c_str(), ios_base::in);
        }
        if (a == '2')
        {
            address = validPath + "\\memory_things_title.txt";
            reFile1.open(address.c_str(), ios_base::in);
        }
        assert(reFile1);
        //将选择的备忘的整个详细内容显示出来
        while (reFile1 >> signs)
        {
            reFile1.get();
            getline(reFile1, data);
            if (i == select)
            {
                system("cls");
                string fname = validPath + "\\" + signs + ".txt";
                ifstream reFile2(fname.c_str());
                assert(reFile2);
                cout << reFile2.rdbuf();
                reFile2.close();
                cout << endl << endl;
                system("pause");
                break;
            }
            i++;
        }
        reFile1.close();
    }
}
class Account {
private:
    string account;//仅用于记录用户输入
    string password;//仅用于记录用户输入
    string check;//用来做判断的string，仅作为中间变量使用
    string validAccountPath;//用来向外部输出有效账号路径
    string nowAccount;//用户登陆成功后记录用户当前账号

    const string superAccount;//管理员账号,由英文字符组成，普通用户只能注册由数字组成的账号，账号为DING_DIAN
    const string superPassWord;//管理员账号密码，代码中的是加密后的密码，密码是2019302110448

    //对密码进行简单加密
    string lock(string password) {
        int i = 0;
        while (i < password.size()) {
            if (password[i] >= 48) {
                password[i] = password[i] - 15;
            }
            else {
                if (password[i] < 48) {
                    password[i] = password[i] + 94 - 15;
                }
            }

            i++;
        }
        return password;
    }

    //对密码进行解密
    string unlock(string password) {

        int i = 0;
        while (i < password.size()) {
            if (password[i] >= 33 && password[i] <= 111) {
                password[i] = password[i] + 15;
            }
            else {
                password[i] = password[i] - 94 + 15;
            }
            i++;
        }
        return password;
    }


public:
    Account() :superAccount("DING_DIAN"), superPassWord("#!\"*$!#\"\"!%%)") {

        //判断文件是否存在
        ifstream accountIndex_read;//账号目录
        accountIndex_read.open("data\\accountIndex.txt");
        int i = 0;
        while (!accountIndex_read) {
            if (i == 1) {
                system("md data");
            }
            if (i > 1) {
                cout << "未知错误，程序将停止运行" << endl;
                cout << "文件错误001" << endl;
                system("pause");
                exit(1);
            }
            else {
                accountIndex_read.close();
                ofstream creatFile("data\\accountIndex.txt");
                creatFile.close();
                accountIndex_read.open("data\\accountIndex.txt");
                i++;
            }
        }
        accountIndex_read.close();
        validAccountPath = " ";
        nowAccount = " ";
    }
    void creatAccount() {
        ifstream accountIndex_read;//账号目录
        accountIndex_read.open("data\\accountIndex.txt");//判断是否是新账号
        int flag;//用于判断账号是否重复
        while (1) {
            cout << endl << "====================================账号创建===============================" << endl;
            flag = 0;
            cout << "输入账号：";
            cin >> account;
            while (accountIndex_read.eof() != 1) {
                getline(accountIndex_read, check);
                if (check == account) {
                    cout << "账号重复，请重新输入" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                if (account.size() < 3 || account.size() > 20) {
                    cout << "请把账号控制在4到20位数字之间" << endl;
                    flag = 1;
                }
                int i = 0;//循环计数
                while (i < account.size() && flag != 1) {
                    if (account[i] > 57 || account[i] < 48) {
                        cout << "输入有误！账号请输入纯数字，按任意键重新输入" << endl;
                        flag = 1;
                        break;
                    }
                    i++;
                }
            }
            if (flag == 1) {
                system("pause");
                system("cls");
                continue;
            }
            accountIndex_read.close();
            cout << "输入密码：";
            cin >> password;
            while (password.size() < 6 && flag != 1) {
                cout << "密码太短，请至少输入六位密码" << endl;
                cout << "重新输入密码：";
                cin >> password;
            }
            cout << "账号:\t" << setiosflags(ios::left) << setw(10) << account << endl << endl;
            cout << "密码:\t" << setiosflags(ios::left) << setw(10) << password << endl << endl;
            cout << "该账号有效，请确认账号和密码是否正确" << endl;
            cout << "倒计时：  ";
            cout << "\b";
            int time = 3;
            while (1) {
                cout << time;
                time--;
                Sleep(1000);
                cout << "\b";
                if (time <= -1) {
                    cout << endl;
                    break;
                }
            }

            cout << endl;
            cout << "------（1）放弃并重新创建账号------" << endl;
            cout << "------（2）放弃创建账号并返回------" << endl;
            cout << "------（3）确认创建账号并返回------" << endl;
            cout << "选择是：";
            string choose = "0";
            int i = 0;//1 continue; 2 return
            while (1) {
                cin >> choose;
                if (choose == "1") {
                    i = 1;
                    break;
                }
                if (choose == "2") {
                    system("cls");
                    cout << endl << "====================================放弃账号创建===============================" << endl;
                    system("pause");
                    return;
                }
                if (choose == "3") {
                    i = 2;
                    break;
                }
            }
            if (i == 1) continue;
            if (i == 2) break;

        }



        //新建账号，并添加至账号目录
        ofstream accountIndex_write;
        accountIndex_write.open("data\\accountIndex.txt", ios_base::app);
        accountIndex_write << account << endl;
        accountIndex_write.close();

        //新建账号文件夹，并保存密码
        string addr;
        addr = "md data\\" + account + "\\password";
        system(addr.c_str());
        addr = "data\\" + account + "\\password" + "\\password.txt";
        ofstream passwordData(addr.c_str());
        passwordData.close();
        passwordData.open(addr.c_str(), ios_base::app);
        passwordData << lock(password);
        passwordData.close();
        ofstream notebookFile;
        string address;
        addr = "data\\" + account + "\\past_things_title.txt";
        notebookFile.open(addr.c_str(),ios_base::app);
        notebookFile.close();
        addr = "data\\" + account + "\\memory_things_title.txt";
        notebookFile.open(addr.c_str(),ios_base::app);
        notebookFile.close();
        cout << endl << "====================================账号创建成功===============================" << endl;
        cout << endl << "====================================请牢记密码！===============================" << endl;
        system("pause");
    }

    void login() {
        char flag;//用于判断是否继续登录
                  //用于判断账号密码是否有误,1有误，0正确
        if (getValidPath() != " ") {
            cout << "账号已登录！" << endl;
            system("pause");
            return;
        }
        ifstream accountIndex;
        ifstream customerAccount;

        while (1) {
            accountIndex.open("data\\accountIndex.txt", ios_base::in);
            cout << endl << "====================================账号登录===============================" << endl;
            flag = '0';
            cout << "输入账号：";
            cin >> account;
            cout << "输入密码：";
            cin >> password;
            if (account == superAccount && password == unlock(superPassWord)) {
                accountIndex.close();
                superAccountPage();
                return;
            }
            while (accountIndex.eof() != 1) {
                getline(accountIndex, check);
                if (check == account) {
                    break;
                }
                if (accountIndex.eof() == 1) {
                    flag = '1';
                }
            }
            accountIndex.close();
            if (flag != '1') {
                string s;
                s = "data\\" + account + "\\password\\password.txt";
                customerAccount.open(s.c_str());
                if (!customerAccount) {
                    cout << "严重错误，数据丢失，程序将结束" << endl;
                    cout << "文件错误002" << endl;
                    system("pause");
                    exit(1);
                }
                getline(customerAccount, check);//此时是密码

                if (password != unlock(check)) {
                    flag = '1';
                }
                customerAccount.close();
            }

            if (flag == '1') {
                cout << endl << "==================================账号或密码错误====================================" << endl;
                cout << "重新输入请按1，否则按任意键取消登录" << endl;
                char choose;
                choose = _getch();
                if (choose == '1') {
                    system("cls");
                    continue;
                }
                else {
                    system("cls");
                    cout << endl << "==================================取消登录====================================" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
            }
            break;

        }


        cout << endl << "==================================登录成功====================================" << endl;
        system("pause");
        validAccountPath = "data\\" + account;
        nowAccount = account;
    }

    void superAccountPage() {
        account = " ";
        password = " ";
        system("cls");
        char choose;
        while (1) {
            cout << endl;
            cout << "==================================管理员账号====================================" << endl;
            cout << "                        这个账号没有使用日历的功能" << endl;
            cout << "                        仅仅用来管理其他账号" << endl;
            cout << "________________________________________________________________________________" << endl;
            cout << "                                                                                " << endl;
            cout << "                                1.  浏览全部账号                                " << endl;
            cout << "                                                                                " << endl;
            cout << "                                2.  销毁账号                                    " << endl;
            cout << "                                                                                " << endl;
            cout << "                                3.  退出管理                                    " << endl;
            cout << "________________________________________________________________________________" << endl;
            cout << "你要选择执行的功能是:";
            choose = _getch();
            switch (choose) {
            case '1':system("cls"); superPeek();
                cout << endl << "按任意键返回";
                _getch(); break;
            case '2':system("cls"); superDeleteAccount(); break;
            case '3':system("cls"); break;
            default: continue;
            }
            if (choose == '3') {
                system("cls");
                return;
            }
            system("cls");
        }
    }

    void superPeek() {
        ifstream accountFile;//打开账号目录
        ifstream passwordFile;//打开密码文件
        string passwordAddress;//密码地址
        string password;
        string account;
        accountFile.open("data\\accountIndex.txt", ios::in);
        cout << " " << "\t" << setiosflags(ios::left) << setw(30) << "账号" << " " << "密码" << endl;
        int i = 1;
        while (accountFile.eof() != 1)
        {
            getline(accountFile, account);
            if (account.size() < 3) break;
            passwordAddress = "data\\" + account + "\\password\\password.txt";
            passwordFile.open(passwordAddress.c_str());
            getline(passwordFile, password);
            passwordFile.close();
            cout << i << ".\t" << setiosflags(ios::left) << setw(30) << account << " " << unlock(password) << endl;
            i++;
        }
        accountFile.close();

    }

    void superDeleteAccount() {
        int flag = 0;//判断账号是否正确
        char choose;
        int if_again;//判断函数是否再执行,1再执行，0不执行
        int num;//账号序号
        while (1) {
            account = " ";
            system("cls");
            if_again = 0;
            superPeek();
            cout << endl << "==================================账号删除====================================" << endl;
            cout << "输入要删除的账号序号：";
            cin >> num;
            int i = 1;
            ifstream accountIndex_read;//账号目录
            accountIndex_read.open("data\\accountIndex.txt");
            while (accountIndex_read.eof() != 1) {
                getline(accountIndex_read, account);
                if (i == num && account.size() > 3) {
                    break;
                }
                if (accountIndex_read.eof() == 1 || account.size() < 3) {
                    cout << endl << "==================================输入有误====================================" << endl;
                    cout << "------（1）继续删除------" << endl;
                    cout << "------（2）取消删除------" << endl;
                    cout << "选择是：";
                    while (1) {
                        choose = _getch();
                        if (choose == '1') {
                            system("pause");
                            system("cls");
                            if_again = 1;
                            break;
                        }
                        if (choose == '2') {
                            system("cls");
                            cout << endl << "==================================取消删除====================================" << endl;
                            system("pause");
                            system("cls");
                            accountIndex_read.close();
                            return;
                        }
                        if (choose != '1' && choose != '2') continue;
                    }
                }

                i++;
            }
            if (if_again == 1) continue;
            deleteAccount(account);
            cout << "------（1）继续删除------" << endl;
            cout << "------（2）结束删除------" << endl;
            cout << "选择是：";
            while (1) {
                choose = _getch();
                if (choose == '1') {
                    system("cls");
                    if_again = 1;
                    break;
                }
                if (choose == '2') {
                    system("cls");
                    cout << endl << "==================================取消删除====================================" << endl;
                    system("pause");
                    system("cls");
                    accountIndex_read.close();
                    return;
                }
                if (choose != '1' && choose != '2') continue;
            }
            if (if_again == 1) continue;

            else {
                accountIndex_read.close();
                break;
            }

        }

    }

    void changPassword() {
        if (validAccountPath == " ") {
            cout << "请先登录账号！" << endl;
            system("pause");
            return;
        }
        char flag;//用于判断是否要继续修改密码
        ifstream customerAccount_read;
        string addr;
        addr = validAccountPath + "\\password\\password.txt";
        customerAccount_read.open(addr.c_str());
        while (1) {
            cout << endl << "====================================密码修改==============================" << endl;
            flag = '0';
            cout << "请输入当前账号的密码：";
            cin >> password;

            getline(customerAccount_read, check);
            if (password == unlock(check)) break;
            else {
                cout << endl << "==================================密码错误====================================" << endl;
                cout << "重新输入请按1，否则按任意键取消修改密码" << endl;
                flag = _getch();
                if (flag == '1') {
                    system("pause");
                    system("cls");
                    continue;
                }
                else {
                    system("cls");
                    cout << endl << "==================================取消修改====================================" << endl;
                    system("pause");
                    system("cls");
                    return;
                }

            }
        }
        customerAccount_read.close();
        ofstream customerAccount_write;
        customerAccount_write.open(addr.c_str(), ios::out);

        while (1) {
            cout << "请输入想要修改的密码：";
            cin >> password;
            if (account.size() < 3 || account.size() > 20) {
                cout << "请把账号控制在4到20位数字之间" << endl;
                continue;
            }
            break;
        }

        customerAccount_write << lock(password);
        customerAccount_write.close();
        cout << endl << "==================================修改完成====================================" << endl;
        system("pause");

    }

    void logout() {
        validAccountPath = " ";
        nowAccount = " ";
        cout << endl << "==================================账号已退出====================================" << endl;
        int time = 4;
        cout << "即将返回登录界面：" << time;
        while (time > -1) {
            cout << "\b" << time;
            time--;
            Sleep(1000);
        }
    }

    void deleteAccount() {
        cout << endl << "==================================账号删除====================================" << endl;
        char flag = '0';
        ifstream accountIndex_read;//账号目录
        accountIndex_read.open("data\\accountIndex.txt");
        while (1) {
            cout << "输入想要删除的账号:";
            cin >> account;
            while (accountIndex_read.eof() != 1) {
                getline(accountIndex_read, check);
                if (check == account) {
                    break;
                }
                if (accountIndex_read.eof() == 1) {
                    flag = '1';
                }
            }

            accountIndex_read.close();
            string addr = "data\\" + account + "\\password\\password.txt";
            cout << "输入密码：";
            cin >> password;
            if (flag != '1') {
                ifstream customerAccount;
                customerAccount.open(addr.c_str());
                getline(customerAccount, check);
                if (password != unlock(check)) {
                    flag = '1';
                    customerAccount.close();
                }
                customerAccount.close();
            }


            if (flag == '1') {
                cout << endl << "==================================账号或密码错误====================================" << endl;
                cout << "重新输入请按1，否则按任意键取消删除" << endl;
                char choose;
                choose = _getch();
                if (choose == '1') {
                    system("pause");
                    system("cls");
                    continue;
                }
                else {
                    system("cls");
                    cout << endl << "==================================取消删除====================================" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
            }
            break;
        }
        deleteAccount(account);
        system("pause");
    }

    void deleteAccount(string targetAccount) {
        string command;
        cout << "你想要删除的账号是：" << targetAccount << endl;
        cout << "你确定要删除吗？" << endl;
        cout << "------（1）继续删除------" << endl;
        cout << "------（2）放弃删除------" << endl;
        cout << "选择是：";
        string choose = "0";
        int i = 0;//1 break; 2 return
        while (1) {
            cin >> choose;
            if (choose == "1") {
                i = 1;
                break;
            }
            if (choose == "2") {
                system("cls");
                cout << endl << "====================================放弃账号创建===============================" << endl;
                system("pause");
                return;
            }
        }

        command = "rmdir /s/q data\\" + targetAccount;//目标路径
        system(command.c_str());//删除文件夹

        fstream accountIndex;
        ofstream creatTemp("data\\accountTemp.txt");//防止没有temp文件
        creatTemp.close();
        fstream accountTemp;
        accountIndex.open("data\\accountIndex.txt");
        accountTemp.open("data\\accountTemp.txt", ios::out);

        while (accountIndex.eof() != 1) {
            getline(accountIndex, check);
            if (targetAccount != check) {
                accountTemp << check << endl;//逐条导入temp，跳过目标账号
            }
        }
        accountIndex.close();
        accountTemp.close();
        accountTemp.open("data\\accountTemp.txt");
        accountIndex.open("data\\accountIndex.txt", ios::out);

        accountTemp.seekg(0, ios::beg);
        while (accountTemp.eof() != 1) {
            getline(accountTemp, check);
            if (check.size() < 3) break;
            accountIndex << check << endl;//逐条导回index
        }

        accountIndex.close();
        accountTemp.close();



        cout << endl << "==================================删除完成====================================" << endl;
    }


    void accountHomePage() {
        char choose;
        if (validAccountPath == " ") {
            cout << "              欢迎进入万年历系统            " << endl;
            cout << "____________________________________________" << endl;
            cout << "                                            " << endl;
            cout << "              1.  登录                      " << endl;
            cout << "                                            " << endl;
            cout << "              2.  注册                      " << endl;
            cout << "                                            " << endl;
            cout << "              3.  销毁账号                  " << endl;
            cout << "                                            " << endl;
            cout << "              4.  退出程序                  " << endl;
            cout << "                                            " << endl;
            cout << "____________________________________________" << endl;
            cout << "你要选择执行的功能是:";
            while (1) {
                choose = _getch();
                switch (choose) {
                case '1':system("cls"); login(); break;
                case'2':system("cls"); creatAccount(); break;
                case '3':system("cls"); deleteAccount(); break;
                case '4':system("cls");
                    cout << endl << "==================================已退出，感谢使用====================================" << endl;
                    system("pause");
                    exit(0);
                    break;
                default: break;
                }
                if (choose == '1' || choose == '2' || choose == '3') {
                    break;
                }
            }


        }
        else {
            cout << "              用户：" << nowAccount << endl;
            cout << "____________________________________________" << endl;
            cout << "                                            " << endl;
            cout << "              1.  进入首页                  " << endl;
            cout << "                                            " << endl;
            cout << "              2.  修改密码                  " << endl;
            cout << "                                            " << endl;
            cout << "              3.  登出账号                  " << endl;
            cout << "                                            " << endl;
            cout << "              4.  退出程序                  " << endl;
            cout << "                                            " << endl;
            cout << "____________________________________________" << endl;
            cout << "你要选择执行的功能是:";

            while (1) {
                choose = _getch();
                switch (choose) {
                case '1':system("cls");  return;
                case '2':system("cls"); changPassword(); break;
                case '3':  logout(); break;
                case '4':system("cls");
                    cout << endl << "==================================已退出，感谢使用====================================" << endl;
                    system("pause");
                    exit(0);
                    break;
                default: break;
                }
                if (choose == '1' || choose == '2' || choose == '3') {
                    break;
                }
            }
        }
    }

    string getValidPath() {
        return validAccountPath;
    }

    string getNowAccount() {
        return nowAccount;
    }
};




int main()
{
    Note abook;//建立一个备忘录对象
    calendar_notebook calendar_notebook1;//建立一个日历备忘录对象
    char select;
    Account account;
    int control;//循环内控制



    //广告功能

    {
        system("AD.exe");
        string a;//防止广告期间误触
        cout << "输入任意字符并按回车继续：";
        cin >> a;
    }




    while (1) {
        control = 0;
        //账号功能循环
        system("cls");
        while (control == 0) {
            account.accountHomePage();
            system("cls");
            if (account.getNowAccount() != " ") {
                control = 1;
            }
        }
        control = 0;
        calendar_notebook1.take_path(account.getValidPath());
        //主体循环
        while (select = calendar_notebook1.first_paper())
        {
            switch (select)
            {
            case '1':
                calendar_notebook1.notes_manage();//备忘录
                break;
            case '2':
                calendar_notebook1.search_data();//日历
                break;
            case '3':
                control = 1;
                break;
            case '4':
                cout << endl << "结束使用，谢谢！！" << endl;
                exit(0);
                break;
            }
            if (control == 1) {
                break;
            }
        }


    }
    return 0;
}
