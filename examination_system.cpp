#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h> //for sleep func //for beep 
#include <conio.h> //for kbhit() and getch()
using namespace std;

class login
{
    protected:
    string name; 
    string email; 
    string password;
    public:
    void teacher_login(); 
    void student_login();
};
class question_bank { 
    string file_name; 
    string q; 
    string optiona; 
    string optionb;
    string optionc;
    string optiond;
public:
    int question_no=1;
    void create(string a); 
    void add(); 
    void show(string a,int total_questions);
    void add_questions_to_new_file(string srcfile, string destfile, int question_number);
};
class quiz_analysis
{
    public:
    int marks_obtained;
    string key;
    void analysis_key(){
        cout<<"enter the key of the q"<<endl;
        cout<<"write the options without spaces"<<endl;
        cin>>key;
    }
};
class time_class{
    public:
    int quiz_after_itne_hours; 
    int quiz_after_itne_minutes; 
    int quiz_after_itne_seconds;
    int quiz_hours; 
    int quiz_minutes; 
    int quiz_seconds;
    void quiz_time(int h, int m, int s,int total_q);
    void start_timer(int h, int m, int s);
    void set_quiz_time();
    quiz_analysis analysis; //***************composition********************
};
class quiz:public question_bank,public time_class{
    public:
    string file_name;
    int no_of_q=0; 
    int marks_of_every_q=0;
    int total_marks;
    void this_is_quiz(){
    cout<<"no of questions are: "<<no_of_q<<endl;
    cout<<"marks of every question is: "<<marks_of_every_q<<endl;
    cout<<"total marks are: "<<total_marks<<endl;
    show(file_name,no_of_q);
    }
};
class course_registration
{
    public:
    string course1,course2,course3,course4,course5,course6,course7,course8,course9,course10;
    string course1_name="Programming Fundamentals"; string course2_name="Object Oriented Programming";
    string course3_name="Linear Algebra"; string course4_name="discrete maths";
    string course5_name="Differential Equations"; string course6_name="Communication and Composition";
    string course7_name="OOP Lab"; string course8_name="Islamic Studies";
    string course9_name="Communication and Presentation Skills"; string course10_name="Introduction to Information and Communication Technology";
    void set_course1(string s){course1=s;} void set_course2(string s){course2=s;}
    void set_course3(string s){course3=s;} void set_course4(string s){course4=s;}
    void set_course5(string s){course5=s;} void set_course6(string s){course6=s;}
    void set_course7(string s){course7=s;} void set_course8(string s){course8=s;}
    void set_course9(string s){course9=s;} void set_course10(string s){course10=s;}
    void display();
    void registration();

};
class teacher:public login /********inheritance************/
{
    public:
    string course_name;
    string course_title;
    void set_email(string s){email=s; email+="@nu.edu.pk";} 
    void set_password(string s){password=s;}
    string get_name(){return name;} 
    string get_password(){return password;} 
    string get_course_name(){return course_name;}
    void display_teacher();
    void choose_task(time_class& t,quiz& quiz_to_attempt);
    void set_q_paper(quiz& quiz_to_attempt);
    bool password_validity(string p);
    //teacher has a quiz and question bank
    question_bank bank;    /********composition*********/
}teach[10];
class student: public login
{
    public:
    string roll_no;
    string serial_no;
    course_registration courses; //registring for sourses using combination
    void set_email(string s){email=s; email+="@nu.edu.pk";} 
    string get_name(){return name;} 
    string get_password(){return password;} 
    void display();
    bool valid_student(string n,string p){
            if(this->roll_no==p)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    bool can_attempt_quiz(string s){
        if(courses.course1_name!=s)
        {
            if(courses.course2_name!=s)
            {
               if(courses.course3_name!=s)
               {
                 if(courses.course4_name!=s)
                 {
                    if(courses.course5_name!=s)
                    {
                        if(courses.course6_name!=s)
                        {
                           if(courses.course7_name!=s)
                           {
                              if(courses.course8_name!=s)
                              {
                                if(courses.course9_name!=s)
                                {
                                   if(courses.course10_name!=s)
                                   {
                                      cout<<"you are not registered for the course!"<<endl;
                                      return false;
                                   }else{return 1;}
                                }else{return 1;}
                              }else{return 1;}
                           }else{return 1;}
                        }else{return 1;}
                      }else{return 1;}
                   }else{return 1;}
                }else{return 1;}
            }else{return 1;}
        }else{return 1;}
    }

}s[217];
int main(){
    static time_class t;//all time related stuff will be stored in here the time when the quiz should happen and all
    static quiz quiz_to_attempt; //all quiz info here
    //creating logins of the teacher
    for(int i=0; i<10; i++){
        teach[i].teacher_login();
    }
    //creating the logins for student
      login in; in.student_login(); 
      student g; g.courses.registration();
    bool start_end=true; int teacher_index=-1;
    string name; string password;
    while(start_end){
    cout<<"enter your name"<<endl; getline(cin,name);
    cout<<"enter your password"<<endl;  getline(cin,password);
    for(int i=0; i<10; i++){
        if(teach[i].get_name()==name && teach[i].get_password()==password){
           cout<<"teacher id found!"<<endl; teacher_index=i;
           teach[teacher_index].display_teacher();
           cout<<"if you want to change password press 1: "; int c; cin>>c;
           if(c==1){
            string your_password;
            cout<<"enter your password"<<endl;
            cin.ignore();getline(cin,your_password);
            bool result=0;
            result=teach[teacher_index].password_validity(your_password);
            if(result==1){ cout<<"password changed!"<<endl; teach[teacher_index].set_password(your_password);}
            else{cout<<"password is not valid"<<endl;}
           }
           else{break;}
        }
    }
      if(teacher_index==-1){
        cout<<"teacher id not found!"<<endl; cout<<"enter the credentials again"<<endl; continue;
      }
      teach[teacher_index].choose_task(t,quiz_to_attempt);
      t.analysis.analysis_key();
      t.start_timer(t.quiz_after_itne_hours,t.quiz_after_itne_minutes,t.quiz_after_itne_seconds);
      //now moving on to the portal of the student
      string pass; string nam;
      start_end=true; cout<<"welcome to student portal! "<<endl;
      int student_index=-1; bool result;
    while(start_end)
    {
        cin.ignore();
        cout<<"enter your name: "; getline(cin,nam); 
        cout<<"enter your password: "; getline(cin,pass);
        for(int i=0; i<216; i++){
            result=s[i].valid_student(nam,pass);
            if(result==true){
               student_index=i;
            }
        }
        if(student_index!=-1){cout<<"student id found!"<<endl;}
        else{
            cout<<"student id not found!"<<endl;
            cout<<"enter credentials again"<<endl; 
            cout<<"do you want to enter again"<<endl; char c; cin>>c;
            if((c=='y')||(c=='Y')){continue;}
            else{break;}
        }
        cout<<"****************************"<<endl;
        s[student_index].display();
        cout<<"****************************"<<endl;
        if(s[student_index].can_attempt_quiz(teach[teacher_index].course_name)){
            cout<<"you are registered for the course: "<<teach[teacher_index].course_name<<endl;
            cout<<"so you can give "<<name<<"'s"<<" quiz"<<endl;
        quiz_to_attempt.this_is_quiz();
        t.quiz_time(t.quiz_hours,t.quiz_minutes,t.quiz_seconds,quiz_to_attempt.no_of_q);
        }
        cout<<"next student: "; char c; cin>>c;
        if((c=='y')||(c=='Y')){start_end=true;}
        else{start_end=false;}
    }
}
}
void login::teacher_login(){
   ifstream inputFile("instructor.csv");
    if (!inputFile.is_open()) { cout << "Failed to open file!" << endl; return;}
    string line; int size=10; const int MAX_ROWS =size; // Maximum number of rows 
    int row = 0; int r=1;
    //teacher t[MAX_ROWS-r];
    size=MAX_ROWS;
    while (getline(inputFile, line)) 
    {
        if (r> MAX_ROWS) { cout << "Maximum number of rows exceeded!" << endl; break;}
        stringstream lineStream(line); string cell;
        int col = 1;
        while (getline(lineStream, cell, ',')){
            if(col==2){ teach[row].course_title=cell;} else if(col==3){teach[row].name=cell; teach[row].email=cell;} else if(col==1){ teach[row].course_name=cell;} else if(col==4){ teach[row].password=cell;}
            col++;
        }
        cout << endl;row++;r++;
    }
}
void teacher::display_teacher(){
    cout<<"*****************************"<<endl;
    cout<<"name: "<<name<<endl; 
    cout<<"course name: "<<course_name<<endl; 
    cout<<"course title: "<<course_title<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"*****************************"<<endl;
}
void teacher::choose_task(time_class& t,quiz& quiz_to_attempt){
    cout<<"1.set question paper"<<endl;
    cout<<"2.set time for test"<<endl; int choice=0; cin>>choice;
    switch(choice){
        case 1: {
            set_q_paper(quiz_to_attempt);t.set_quiz_time();
            //t.start_timer(t.quiz_after_itne_hours,t.quiz_after_itne_minutes,t.quiz_after_itne_seconds);
            //t.quiz_time(t.quiz_hours,t.quiz_minutes,t.quiz_seconds);
            break;
        }
        case 2:{
            t.set_quiz_time(); set_q_paper(quiz_to_attempt);
            //t.start_timer(t.quiz_after_itne_hours,t.quiz_after_itne_minutes,t.quiz_after_itne_seconds);
            //t.quiz_time(t.quiz_hours,t.quiz_minutes,t.quiz_seconds);
            break;
        }
    }
}
void teacher::set_q_paper(quiz& quiz_to_attempt){ string temp; string new_temp;
    if (this->course_name=="Programming Fundamentals"){temp="pf.bin"; new_temp="new_pf.bin";}
    if (this->course_name=="Object Oriented Programming"){temp="oop.bin"; new_temp="new_oop.bin";}
    if (this->course_name=="Linear Algebra"){temp="la.bin"; new_temp="new_la.bin";}
    if (this->course_name=="discrete maths"){temp="dis.bin"; new_temp="new_dis.bin";}
    if (this->course_name=="Differential Equations"){temp="de.bin"; new_temp="new_de.bin";}
    if (this->course_name=="Communication and Composition"){temp="com.bin"; new_temp="new_com.bin";}
    if (this->course_name=="OOP Lab"){temp="ooplb.bin"; new_temp="new_ooplb.bin";}
    if (this->course_name=="Islamic Studies"){temp="isl.bin"; new_temp="new_isl.bin";}
    if (this->course_name=="Communication and Presentation Skills"){temp="cps.bin"; new_temp="new_cps.bin";}
    if (this->course_name=="Introduction to Information and Communication Technology"){temp="iict.bin"; new_temp="new_iict.bin";}
    int choice=0;
    cout<<"1.generate quiz by question bank"<<endl;
    cout<<"2.genrate quiz by yourself"<<endl;
    cout<<"3.add some from questions question bank and also add yourself"<<endl; cin>>choice;
    switch(choice){
        case 1:{
            cout<<"enter the no of questions in the quiz"<<endl; cin>>quiz_to_attempt.no_of_q;
            cout<<"enter the marks of every question"<<endl;     cin>>quiz_to_attempt.marks_of_every_q;
            quiz_to_attempt.total_marks=(quiz_to_attempt.no_of_q)*(quiz_to_attempt.marks_of_every_q); 
            quiz_to_attempt.file_name=temp;
            break; 
        }
        case 2:{
            temp="new_quiz.bin"; quiz_to_attempt.file_name=temp;
            cout<<"enter the no of questions in the quiz"<<endl; cin>>quiz_to_attempt.no_of_q; int num=quiz_to_attempt.no_of_q;
            cout<<"enter the marks of every question"<<endl;     cin>>quiz_to_attempt.marks_of_every_q;
            quiz_to_attempt.total_marks=(quiz_to_attempt.no_of_q)*(quiz_to_attempt.marks_of_every_q); 
            while(num){
            bank.create(temp);num--;} 
            break;
        }
        case 3:{
            cout<<"enter the no of questions in the quiz"<<endl; cin>>quiz_to_attempt.no_of_q; int num=quiz_to_attempt.no_of_q;
            cout<<"enter the marks of every question"<<endl;     cin>>quiz_to_attempt.marks_of_every_q;
            quiz_to_attempt.total_marks=(quiz_to_attempt.no_of_q)*(quiz_to_attempt.marks_of_every_q);
            //*********//
            cout<<"how many questions you want to add from question bank"<<endl;
            int count; cin>>count; int q_n;
            cout<<"here is the question bank you have to input the question no you want to add"<<endl;
            bank.show(temp,9);
            for(int i=0; i<count; i++){
                cin>>q_n;
                bank.add_questions_to_new_file(temp,new_temp,q_n);
            }
            quiz_to_attempt.file_name=new_temp;
            cout<<"do you want to add more questions to file"<<endl;
            cout<<"enter y/n"<<endl;
            char c; cin>>c;
            if (c=='y'||c=='Y'){
                cout<<"how many q you want to add"<<endl; cin>>num;
                while(num){
                bank.create(new_temp);num--;} 
            }
            break;
        }

    }
}
void question_bank::show(string a, int total_questions) {
    ifstream f_read(a, ios::in | ios::binary);
    if (!f_read.good()) {
        cout << "No quizzes found." << endl;
        return;
    } question_no=1; int count=0;
    while (getline(f_read, q)) { 
        getline(f_read, optiona);
        getline(f_read, optionb);
        getline(f_read, optionc);
        getline(f_read, optiond);
        cout<<"quesion no: "<<question_no<<endl;
        cout << "Q: " << q << endl;
        cout << "Option A: " << optiona << endl;
        cout << "Option B: " << optionb << endl;
        cout << "Option C: " << optionc << endl;
        cout << "Option D: " << optiond << endl << endl; question_no++; count++;
        if(count==total_questions){break;}
    }
    f_read.close();
}
void question_bank::create(string a) {
    ofstream f_write;
    f_write.open(a ,ios::out | ios::app | ios::binary);
    add();
    f_write << q << endl;
    f_write << optiona << endl;
    f_write << optionb << endl;
    f_write << optionc << endl;
    f_write << optiond << endl;
    f_write.close();
}
void question_bank::add() { cin.ignore();
    cout << "Enter Q: "; getline(cin, q);
    cout << "Option A: "; getline(cin, optiona);
    cout << "Option B: "; getline(cin, optionb);
    cout << "Option C: "; getline(cin, optionc);
    cout << "Option D: "; getline(cin, optiond); cout<<endl; cout<<endl;
}
void time_class::quiz_time(int hour, int min, int sec, int total_q){
        char ans[total_q]={}; int i=0; int max=total_q;
        cout<<"quiz started..."<<endl; for(int x=0; x<3; x++) {Beep(700,200);} //Beep(750,800);
        //quiz_to_attempt.this_is_quiz();
        system("pause");
    for(;;){
        if(hour==0&&min==0&&sec==0){break; }
        if(sec==0&&min==0){ min=60; hour--;}
        if(sec==0){ sec=60; min--;}
        system("cls");     //this command clears the secreeen creates the effect of stop watch
        cout<<hour<<":"<<min<<":"<<sec--;
        Sleep(1000);
        if (kbhit()) { // check if a key is pressed the key on keyboard that is pressed will
        //be taken by the getch() fun and stored in the choice and then the choice
        //will be stored a your ans so this fun is enableing two func to be called ad used simultaneously
            char choice = getch();
            if(i<max){// get the key pressed
            ans[i]=choice; i++;}
        }
    }
    cout<<endl; Beep(700,200);
    cout<<"quiz ended!"<<endl;
    cout<<"your ans are: "<<endl;
    for(int i=0; i<total_q; i++){
        cout<<"ans"<<i+1<<":"<<ans[i]<<" ";
    } cout<<endl;
    cout<<"the right key is: "<<endl;
    for(int i=0; analysis.key[i]!='\0'; i++){
        cout<<"ans"<<i+1<<":"<<analysis.key[i]<<" ";
    }cout<<endl;
    analysis.marks_obtained=0;
    for(int i=0; analysis.key[i]!='\0'; i++){
        if(ans[i]==analysis.key[i]){
           analysis.marks_obtained++;
        }
    }
    cout<<"marks obtained are: "<<analysis.marks_obtained<<endl;
    cout<<endl;
}
void time_class::start_timer(int hour, int min, int sec){
        while(1){
            if(hour==0&&min==0&&sec==0){cout<<endl; cout<<"its time for the quiz"<<endl;break;}
            if(sec==0&&min==0){ min=60; hour--;}
            if(sec==0){ sec=60; min--;}
            system("cls");             //this command clears the secreeen creates the effect of stop watch
            cout<<hour<<":"<<min<<":"<<sec--;
            Sleep(1000);
        }
    }
void time_class::set_quiz_time(){
        cout<<"enter the no of hours and minutes after which quiz should take place"<<endl;
        cout<<"enter the hours: "; cin>>quiz_after_itne_hours;
        cout<<"enter the minutes: "; cin>>quiz_after_itne_minutes;
        cout<<"enter the seconds: "; cin>>quiz_after_itne_seconds;
        cout<<"set the duration of quiz"<<endl;
        cout<<"hours: "; cin>>quiz_hours; cout<<"minutes: "; cin>>quiz_minutes; cout<<"seconds: "; cin>>quiz_seconds;
}
void question_bank::add_questions_to_new_file(string main_file, string dest_file, int questionno) {
    ifstream f_read(main_file, ios::in | ios::binary); ofstream f_write(dest_file, ios::out | ios::app | ios::binary);
    if (!f_read.good() || !f_write.good()) { cout << "Failed to open files!" << endl; return;}
    this->question_no = 1; bool Found = false;
    while (getline(f_read, q)) {
        getline(f_read, optiona);getline(f_read, optionb);getline(f_read, optionc);getline(f_read, optiond);
        if (question_no == questionno) {
            f_write << q << endl;
            f_write << optiona << endl;
            f_write << optionb << endl;
            f_write << optionc << endl;
            f_write << optiond << endl;
            Found = true; break;
        }
        this->question_no++;
    }
    f_read.close();f_write.close();
    if (!Found) {cout << "Question not found in the source file." << endl;} 
    else {cout << "Question added to the destination file." << endl;}
}
bool teacher::password_validity(string p)
{
    int length=0;
    int capitals=0;
    int lowers=0;
    int digits=0;
   for(int i=0; (p[i])!='\0'; i++){
    length++;
    if((p[i]>='A')&&(p[i]<='Z')){capitals++;}
    if((p[i]>='a')&&(p[i]<='z')){lowers++;}
    if((p[i]>='0')&&(p[i]<='9')){ digits++;}
   }
   //now linking all conditions
   if(length>=6)
   {
    if(capitals>=1){
        if(lowers>=1){
            if(digits>=1){return 1;}
            else{cout<<"password has no digits"<<endl;return 0;}
        }
        else{ cout<<"password has no lower characters"<<endl;return 0;}
      }
    else{
        cout<<"password has no capital characters"<<endl;
        return 0;
    }
   }
   else{
      cout<<"the entered password has less characters"<<endl;
      return 0;
   }
}
void student::display(){
    cout<<"*********************************************************"<<endl; cout<<"serial no: "<<serial_no<<endl;cout<<"name: "<<name<<endl;cout<<"roll no: "<<roll_no<<endl;cout<<"email: "<<email<<endl;cout<<"password: "<<password<<endl;//cout<<"***********************************"<<endl;
    courses.display();
}
void login::student_login(){
    ifstream inputFile("student.csv");
    if (!inputFile.is_open()) {cout << "Failed to open file!" << endl; return;}
    string line; int size=217;
    const int MAX_ROWS =size; // Maximum number of rows 
    int row = 0; int r=1;  /*student s[MAX_ROWS-r];*/ size=MAX_ROWS-r;
    while (getline(inputFile, line)){
        if (r>= MAX_ROWS) { cout << "Maximum number of rows exceeded!" << endl; break;}
        stringstream lineStream(line); string cell; int col = 0;
        while (getline(lineStream, cell, ',')) 
        {
            if(col==0){ s[row].serial_no=cell;}
            else if(col==1){s[row].roll_no=cell; s[row].set_email(cell); s[row].password=cell;}
            else if(col==2){s[row].name=cell;}
            col++;
        }
        cout << endl; row++; r++;
    }
    inputFile.close();
}
void course_registration:: registration(){
    ifstream inputFile("student.csv");
    if (!inputFile.is_open()) {cout << "Failed to open file!" << endl; return;}
    string line; int size=217;
    const int MAX_ROWS =size; // Maximum number of rows 
    int row = 0; int r=1;  /*student s[MAX_ROWS-r];*/ size=MAX_ROWS-r;
    while (getline(inputFile, line)){
        if (r>= MAX_ROWS) { cout << "Maximum number of rows exceeded!" << endl; break;}
        stringstream lineStream(line); string cell; int col = 0;
        while (getline(lineStream, cell, ',')) 
        {
            if(col==3){s[row].courses.set_course1(cell);}
            else if(col==4){s[row].courses.set_course2(cell);}
            else if(col==5){s[row].courses.set_course3(cell);}
            else if(col==6){s[row].courses.set_course4(cell);}
            else if(col==7){s[row].courses.set_course5(cell);}
            else if(col==8){s[row].courses.set_course6(cell);}
            else if(col==9){s[row].courses.set_course7(cell);}
            else if(col==10){s[row].courses.set_course8(cell);}
            else if(col==11){s[row].courses.set_course9(cell);}
            else if(col==12){s[row].courses.set_course10(cell);}
            col++;
        }
        cout << endl; row++; r++;
    }
    inputFile.close();
}
void course_registration::display(){
        if(course1=="0"&&course2=="0"&&course3=="0"&&course4=="0"&&course5=="0"&&course6=="0"&&course7=="0"&&course8=="0"&&course9=="0"&&course10=="0"){
            cout<<"you have not registered for any courses"<<endl;
        }else{
        cout<<"you have registered for these courses"<<endl;} string s="1";
        if(course1==s){cout<<course1_name<<endl;} if(course2==s){cout<<course2_name<<endl;}
        if(course3==s){cout<<course3_name<<endl;} if(course4==s){cout<<course4_name<<endl;}
        if(course5==s){cout<<course5_name<<endl;} if(course6==s){cout<<course6_name<<endl;}
        if(course7==s){cout<<course7_name<<endl;} if(course8==s){cout<<course8_name<<endl;}
        if(course9==s){cout<<course9_name<<endl;} if(course10==s){cout<<course10_name<<endl;}
        cout<<"*********************************************************"<<endl;
}