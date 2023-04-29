
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;




class Solution
{
public:
    int sid;
    string s;


    Solution(int i, string s1)
    {
        sid = i;
        s = s1;
    }

    void display()
    {
        cout<<s<<endl;
    }

    string getsol()
    {
        return s;
    }
};





class Course
{
    public:
    int sem;
    string name;
    string code;

    Course()
    {
        sem = 0;
        name = "";
        code = "";
    }

    Course(int s, string n, string c): sem(s),name(n),code(c)
    {

    }
};


class Branch
{
    public:
    string bcode;
    string name;
    Course *c;
    int numberCourses;


    Branch(Course *co, string code , string n, int num)
    {
        bcode = code;
        name = n;
        c = co;
        numberCourses = num;
    }


};


class Question
{

public:
    int id;
    string que;
    Solution *sol;
    int numberSolutions;
    Branch *b;
    Question(int i, string q, Solution *s,Branch *b1,int n)
    {
        id = i;
        que = q;
        sol = s;
        numberSolutions = n;
        b = b1;
    }


    void addSolution(string s1)
    {
        numberSolutions++;
        sol[numberSolutions-1].sid = numberSolutions;
        sol[numberSolutions-1].s = s1;
    }


    void removeSolution(int s1)
    {
        for(int i=0;i<numberSolutions;i++)
        {
            if(sol[i].sid == s1)
            {
                cout<<"Solution Deleted"<<endl;

                for(int j=i;j<numberSolutions-1;j++)
                {
                    sol[j] = sol[j+1];
                }

                numberSolutions--;
            }
        }
    }



    string getQuestion()
    {
        return que;
    }


    void display()
    {
        cout<<"---"<<endl;
        cout<<"Question: "<<que<<endl;
        cout<<"Branch: "<<b->name<<endl;
        cout<<"Solution: "<<endl;

        for(int i=0;i<numberSolutions;i++)
        {
            cout<<i+1<<": ";sol[i].display();
        }
        cout<<"---"<<endl;
    }
protected:
    Question()
    {

    }
    template <typename temp>

friend void sortAndDisplay(temp ar[],int n);
};






class QuestionForum
{
public:
    Question *Qrr;

    static int Id;
    int numberQuestions;


    QuestionForum(Question *q, int n)
    {
        Id++;
        numberQuestions=n;
        Qrr = q;
    }


    void displayBranch(string code, string name)
    {
        cout<<"Branch: "<<name<<endl;
        for(int i=0;i<numberQuestions;i++)
        {
            if(Qrr[i].b->bcode == code)
                Qrr[i].display();
        }
    }

    void displayCourse(string code, string name)
    {
        cout<<"Course: "<<name<<endl;
        for(int i=0;i<numberQuestions;i++)
        {
            for(int j=0;j<Qrr[i].b->numberCourses;j++)
            {
                if(Qrr[i].b->c[j].code == code)
                {
                    if(Qrr[i].que != "xx")
                      Qrr[i].display();
                }

            }


        }
    }


    void display()
    {
        cout<<"All the questions posted:"<<endl;
        for(int i=0;i<numberQuestions;i++)
        {
                    Qrr[i].display();


        }
    }

    void removesol(int qid,int number)
    {
        int fact = 1;
        for(int i=0;i<numberQuestions;i++)
        {
            if(Qrr[i].id == qid)
            {
                fact = 0;
                Qrr[i].removeSolution(number);
            }
        }
        if(fact)
            cout<<"Question Not Found"<<endl;
    }



};


int QuestionForum::Id = 0;

class Error
{
public:
    int id;
    Error(int i):id(i)
    {

    }
    void show()
    {
        if(id == 0)
          cout<<"Username cannot be empty"<<endl;
        else if(id == 1)
          cout<<"Password cannot be empty"<<endl;
    }
};
class User
{
public:
    int id;
    string name;
    string username;
    string password;
    string type;
    long long mobileNo;
    User(int id,string name,string username,string password,string type,long long mobileNo):id(id),name(name),username(username),password(password),type(type),mobileNo(mobileNo)
    {

    }


    void display()
    {
        cout<<"User details:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"UserName: "<<username<<endl;
        cout<<"Account Type: "<<type<<endl;

    }


   void changePassword(string oldpassword,string newpassword)
   {
       try
       {
           if(newpassword == "") throw Error(1);

            if(oldpassword==password)
           {
             password=newpassword;
             cout<<"PASSWORD CHANGED"<<endl;
           }
           else
             cout<<"INCORRECT PASSWORD"<<endl;
       }
       catch(Error e)
       {
           e.show();
       }

   }



      void changeUsername(string oldusername,string newusername,string password1)
   {

      try
    {
        if(newusername == "") throw Error(0);
        if(password1==password)
       {
           username=newusername;
           cout<<"USERNAME CHANGED"<<endl;
       }
       else
        cout<<"INCORRECT PASSWORD"<<endl;
    }
    catch(Error e)
    {
           e.show();
    }

   }

   virtual void postQuestion(QuestionForum &qp, Question &q)
   {

   }
   virtual void postAnswer(string answer, QuestionForum &q, int qid)
   {
     cout<<"noo"<<endl;
   }

};


class University_Account
{
public:
    int id;
    string name;
    string address;
    int year_established;

    int noOfUsers;
    User *UserArray;
    University_Account(int id,string name,string address,int year_established,User *u,int num):id(id),name(name),address(address),year_established(year_established)
    {
        noOfUsers=num;
        UserArray = u;
    }
    void displayUniversity()
    {
        cout<<"Name : " <<name<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"YEAR Established"<<year_established<<endl;

        cout<<"Users List: "<<endl;
        for(int i=0;i<noOfUsers;i++)
        {
            cout<<i+1<<"--"<<endl;
            UserArray[i].display();
            cout<<endl;
        }
    }
    void addUser(User temp)
    {
        noOfUsers = noOfUsers+1;
        UserArray[noOfUsers-1] = temp;
    }



     void removeUser(string Username,string Password)
    {
        int fact = 1;
        for(int i=0;i<noOfUsers;i++)
        {
            if(Username==UserArray[i].username)
            {
                if(Password==UserArray[i].password)
                {
                    fact = 0;
                    cout<<"ACCOUNT REMOVED"<<endl;
                    for(int j=i;j<noOfUsers-1;j++)
                    {
                        UserArray[j]=UserArray[j+1];
                    }
                    noOfUsers=noOfUsers-1;

                }
            }
        }

        if(fact)
            cout<<"INCORRECT PASSWORD/ USER NOT FOUND"<<endl;
    }
    void displayUsers()
    {
        for(int i=0;i<noOfUsers;i++)
        {
            cout<<i+1<<"--"<<endl;
            UserArray[i].display();
            cout<<endl;
        }
    }
    void displayStudents()
    {
        for(int i=0;i<noOfUsers;i++)
        {
         if(UserArray[i].type=="Student")
            UserArray[i].display();
        }
    }
        void displayFaculty()
    {
        for(int i=0;i<noOfUsers;i++)
        {
         if(UserArray[i].type=="Faculty")
            UserArray[i].display();
        }
    }




};







class FacultyAccount:public User
{
public:
        string role;
        FacultyAccount(int id,string name,string username,string password,long long mobileNo, string r):User(id,name,username,password,"FACULTY",mobileNo)
        {
          role = r;
        }


        void display()
    {
        cout<<"User details:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"UserName: "<<username<<endl;
        cout<<"Account Type: "<<type<<endl;
        cout<<"Role: "<<role<<endl;

    }


        void postAnswer(string answer, QuestionForum &q, int qid)
        {
            for(int i=0;i<q.numberQuestions;i++)
            {
                if(q.Qrr[i].id == qid )
                {
                   q.Qrr[i].addSolution(answer);
                }
            }
        }
};


class StudentAccount:public User
{
public:
    string SRN;
    int sem;
    Branch *b;
    StudentAccount(int id,string name,string username,string password,long long mobileNo, string srn, int s, Branch *br):User(id,name,username,password,"STUDENT",mobileNo)
    {
       SRN =srn;
       sem = s;
       b = br;
    }

    void postQuestion(QuestionForum &qp, Question &q)
    {
            qp.numberQuestions++;
            qp.Qrr[qp.numberQuestions-1] = q;
    }

};






class Post
{
public:
    int id;
    string title;

    int imgId;
    int numberImages;
    string description;
    int like;

    Post(string t,int post,int imgId,int numberImg, string d)
    {
        title = t;
        numberImages = numberImg;
        id=post;
        imgId=imgId;
        description = d;
        like=0;
    }



void display()
{
    cout<<"Title :"<<title<<endl<<"Description :"<<description<<endl;
    cout<<"Number of Likes : "<<like<<endl;
}

    static int addPost(Post *ar,int size1,Post p)
    {
       ar[size1]=p;
       cout<<"Post Created"<<endl;
       return (size1+1);
    }

static void likepost(Post *p)
{
    p->like=p->like+1;
}

    static int removePost(Post *arrP,int size,int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (arrP[i].id == id)
            {
                cout << "Post Deleted" << endl;

                for (int j = i; j < size - 1; j++)
                {
                    arrP[j] = arrP[j + 1];
                }
return (size-1);
 }
        }
        cout<<"Unsuccessful Deletion"<<endl;
        return size;
    }


    static void displayPost(Post *p,int size)
{
    for(int i=0;i<size;i++)
    {
        p[i].display();
    }
}


private:
    Post()
    {

    }
    template <typename temp>

friend void sortAndDisplay(temp ar[],int n);
};


template <class temp>
void sortAndDisplay(temp ar[],int n)
{
    temp v;
    int i,j;
    for(i=n-2;i>=0;i--)
    {
        v = ar[i];
        j = i+1;
        while(j<n && ar[j].id<v.id)
        {
            ar[j-1] = ar[j];
            j++;
        }
        ar[j-1] = v;
    }
    for(i=0;i<n;i++)
    {   cout<<ar[i].id   <<"     " <<endl;
        ar[i].display();
        cout<<"........."<<endl;
    }
}




int main()
{

   int sizeofpost=1;
   Post p1("POST 1",22,1,1,"Details 1");
   Post p2("POST 2",13,2,2,"Details 2");
   Post parr[5]={p1,p1,p1,p1,p1};
    Course c1(1,"SVC","1msvc"),
           c2(1,"EngineeringPhysics","1sep"),
           c3(1,"EngineeringMechanics","1mem"),
           c4(2,"MechanicalEngineering","2mme"),
           c5(2,"Chemistry","2cch"),
           c6(4,"OOPS","4eops"),
           c7(4,"OS","4ios"),
           c8(4,"MCP","4rmc"),
           c9(4,"EDA","4red");


    Course cArr1[3] = {c1,c2,c3}, cArr2[3] = {c4,c5,c6}, cArr3[3] = {c7,c8,c9};

    Branch b1(cArr1,"csc","ComputerScience",3),
           b2(cArr2,"enc","ElectronicsCommunication",3),
           b3(cArr3,"mech","MechanicalEngineering",3);



    Solution s1(1,"The answer will be 6"),
             s2(2,"OOPs stands for Object-Oriented programming system"),
             s3(3,"Atom is the smallest particle of a chemical element that can exist."),
             s4(4,"The kernel is a core component of an operating system"),
             s5(5,"Multiplication will result into 6"),
             dys(0,"");

    Solution forQ1[5] = {s1,s5,s5,s5,s5}, forQ2[5] = {s2,dys,dys,dys,dys}, forQ3[5] = {s3,dys,dys,dys,dys}, forQ4[5] = {s4,dys,dys,dys,dys}, fordum[5] = {dys,dys,dys,dys,dys};


   Question q1(10,"What is 3*2?",forQ1,&b1,2),
            q2(11,"What does OOPs stand for?",forQ2,&b1,1),
            q3(12,"What is an atom?",forQ3,&b2,1),
            q4(13,"What is the Kernel?",forQ4,&b3,1),
            dummy(0,"xx",fordum,&b1,0);

    Question Qarr[10] = {q1,q2,q3,q4,dummy,dummy,dummy,dummy,dummy,dummy};


    QuestionForum questions(Qarr,4);



    StudentAccount st1(100,"Sneha","Sneehha","abc@12",9856783456L,"01fe20bcs584",4,&b1),
                   st2(101,"Nakul","Nakull","xyz-11",9967583456L,"01fe21bec123",2,&b2),
                   st3(102,"Kriti","Kri","kri@789",8934283336L,"01fe20bme111",1,&b3);



    FacultyAccount f1(200,"Sapna","sapna","saap",8934823413L,"Professor"),
                   f2(201,"Preetam","pree","pre@123",9324528295L,"Office"),
                   f3(202,"Kushal","kushaal","kushal-00",9943823482L,"Professor");


    User accounts[10] = {st1,f1,st2,st3,f2,f3,f1,f1,f1,f1};


    University_Account uni(2000,"KLETECH","Vidyanagar, Hubballi",1947,accounts,6);


    uni.displayUniversity();


    cout<<"------------------------------------------------------------"<<endl;

    cout<<"ADD NEW USER"<<endl<<endl;
    FacultyAccount f4(203,"Khushi","kuu","hjk&67",9976823413L,"Professor");

    uni.addUser(f4);
    uni.displayUniversity();

    cout<<"------------------------------------------------------------"<<endl;


    cout<<"REMOVE/DELETE USER"<<endl<<endl;
    uni.removeUser("kuu","hjk&67");
    cout<<endl;
    uni.displayUniversity();

    cout<<"------------------------------------------------------------"<<endl;

    cout<<"DISPLAY USERS DETAILS"<<endl;
    uni.displayUsers();


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"CHANGE PASSWORD"<<endl<<endl;

    f3.changePassword("kushal-00","kus00");


    cout<<"EXCEPTION HANDLING EXAMPLE"<<endl;
    cout<<"1--"<<endl;

    f3.changePassword("kushal-00","");

    cout<<endl<<"2--"<<endl;

    f3.changeUsername("kushaal","","kus00");

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"CHANGE USERNAME"<<endl<<endl;
    f3.changeUsername("kushaal","ku12","kus00");
    f3.display();


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"POST QUESTION"<<endl<<endl;

    Question q(14,"What is a Monitor",fordum,&b2,0);
    st1.postQuestion(questions,q);
    questions.display();



    cout<<"------------------------------------------------------------"<<endl;
    cout<<"POST ANSWER"<<endl<<endl;

    f1.postAnswer("It's one of the device",questions,14);
    questions.display();


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"POST ANOTHER ANSWER TO THE SAME QUESTION"<<endl<<endl;

    f1.postAnswer("It is used for the display",questions,14);
    questions.display();


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"REMOVE SOLUTION"<<endl<<endl;
    questions.removesol(14,1);
    questions.display();

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"DISPLAY THE QUESTIONS OF A PARTICULAR BRANCH"<<endl<<endl;
    questions.displayBranch("csc","ComputerScience");


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"DISPLAY THE QUESTIONS OF A PARTICULAR COURSE"<<endl<<endl;
    questions.displayCourse("1msvc","SVC");

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"DISPLAY THE POSTS OF FACULTY"<<endl;
    Post::displayPost(parr,sizeofpost);

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"ADD A NEW POST"<<endl;
    sizeofpost=Post::addPost(parr,sizeofpost,p2);
    Post::displayPost(parr,sizeofpost);


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"REMOVE A POST"<<endl;
    sizeofpost=Post::removePost(parr,sizeofpost,1);
    Post::displayPost(parr,sizeofpost);

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"ADD A NEW POST"<<endl;
    sizeofpost=Post::addPost(parr,sizeofpost,p2);
    Post::displayPost(parr,sizeofpost);

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SORT QUESTIONS USING A TEMPLATE"<<endl;

    sortAndDisplay(Qarr,4);

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SORT POSTS USING A TEMPLATE"<<endl;
    sortAndDisplay(parr,2);


    cout<<endl<<endl<<"                 *****"<<endl;

    return 0;

}
