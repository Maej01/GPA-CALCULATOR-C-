#include<iostream>
#include<cstdlib>

using namespace std;

main()
{
    //variables declaration
    string studentName, studentID, module_code[10], module_name[10], module_grade[10];
    int number_of_modules, i,j,semester,sum_of_credit_hrs[10];
    double gpa[10],points[10],sum_of_points[10];
    double value[10], module_credit_hrs[10];

    cout<<"\t\t------------------------------------------"<<endl;
    cout<<"\t\t|| MADUS GRADE POINT AVERAGE CALCULATOR ||"<<endl;
    cout<<"\t\t------------------------------------------"<<endl;

    cout<<"Enter Student's Name: ";
    getline(cin,studentName);
    cout<<"Enter Student's ID Number: ";
    getline(cin,studentID);
    cout<<"How many semesters do you want to calculate for? : ";
    cin>>semester;

    //this variables will hoold the total points
    sum_of_points[0]=0;
    sum_of_credit_hrs[0]=0;

    for (j=0; j<semester; j++)
    {
        cout<<"Enter total module taken for semester: "<<j+1<<": ";
        cin>>number_of_modules;

        for(i=0; i<number_of_modules; i++)
        {
            cin.ignore();
            cout<<"Enter Module Code: ";
            getline(cin,module_code[i]);
            cout<<"Enter Module Name: ";
            getline(cin,module_name[i]);
            cout<<"Enter Module's Credit Hours: ";
            cin>>module_credit_hrs[i];
            cin.ignore();

            cout<<"Enter Module Grade eg(A+, A, A-, B+, B, B-, C+, C, C-): ";
            getline(cin,module_grade[i]);

            if(module_grade[i]=="A+" || module_grade[i]=="A" || module_grade[i]=="A-")
                value[i]=4; //(90-100 -> A+ | 85-89 -> A | 80-84 -> A- )
            else if(module_grade[i]=="B+")
                value[i]=3.67;  //(75-79 -> B+)
            else if(module_grade[i]=="B")
                value[i]=2.33; //(74-70 -> B)
            else if(module_grade[i]=="B-")
                value[i]=2.00;  //(65-69 -> B-)
            else if(module_grade[i]=="C+")
                value[i]=2.67;  //(60-64 -> C+)
            else if(module_grade[i]=="C")
                value[i]=2.33;  //(55-59 -> C)
            else if(module_grade[i]=="C-")
                value[i]=2.00; //(50-54 -> C-)
            else
                value[i]=0; //(0-49 -> F)

            //multiplying and assigning each module credit hours by the grade per module eg (A = 4.00 etc)
            points[i]=value[i]*module_credit_hrs[i];
            //adding the points
            sum_of_points[j]+=points[i];
            //adding the credit hours
            sum_of_credit_hrs[j]+=module_credit_hrs[i];
        }
            //dividing the sum of all the points by the sum of all the credit hours
            gpa[j]=sum_of_points[j]/sum_of_credit_hrs[j];
    }
        std::system("clear"); //clearing the screen
        //printing the output
        cout<<"-----------------------TRANSCRIPT------------------------------"<<endl;
        cout<<"Student Name: "<<studentName<<endl;
        cout<<"Student ID: "<<studentID<<endl;

        for(j=0; j<semester; j++)
        {
            for(i=0; i<number_of_modules; i++)
            {
                    cout<<"\t-----------------MODULE DETAILS-----------------"<<endl;
                    cout<<"\tMODULE CODE\t| MODULE NAME\t| GRADE OBTAINED"<<endl;
                    cout<<"\t"<<module_code[i]<<"\t\t| "<<module_name[i]<<"\t\t| "<<module_grade[i]<<endl;
                    cout<<"\t-------------------------------------------------"<<endl;
            }
                    cout<<"GPA for semester: "<<gpa[j]<<endl;
                    cout<<"Total points for this semester: "<<sum_of_points[j]<<endl;
                    cout<<"Total credit hours for this semester: "<<sum_of_credit_hrs[j]<<endl;
        }
        cout<<"---------------------------------------------------------------"<<endl;
}
