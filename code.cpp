#include<iostream>
#include<fstream>
using namespace std;
class student
{
    char name[20];
    int age;
    public:
        void getdata()
        {
            cout<<"enter age\n";
            cin>>age;
            cout<<"enter name\n";
            cin>>name;
        }
        void showdata()
            {
                cout<<"\n age"<<age;
                cout<<"\n name"<<name;
            }
};
int main()
{
    student s;
    fstream file;
    char c;

    file.open("always make new file for new data or it will enter data withour wwith exsisting data .DATA",ios::in|ios::out|ios::app);

    do
    {
        cout<<"enter student record\n";
        s.getdata();
        file.write((char*)&s,sizeof(s));
        cout<<"want to add more\n";
        cin>>c;
    }
    while(c=='Y'||c=='y');
    file.clear();
    file.seekg(0);
    //file.read((char*)&s,sizeof(s));//
    while (file.read((char*)&s, sizeof(s)))
    {
    s.showdata();
    }

    file.close();
    cout << "\n done" << endl;
    return 0;
}