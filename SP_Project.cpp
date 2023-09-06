#include <iostream>
using namespace std;
#include <string>
void removeing();
void exp_in();
void inc_in();
void rc_in();
void edit_exp();
void edit_inc();
void edit_rc();
void main_menu();
void inc_add();
void exp_add();
void rc_add();
void dit_disinc();
void dit_disrc();
void dit_disexp();
void qk_disin();
void qk_disrc();
void qk_disexp();
void nested_menu();
//
int DeleteV(float& I)
{
	return I = 0.0;
}
string Deletes(string& m)
{
	return m = " ";
}

struct income_src
{
	string name;
	float value;
};
struct income
{
    //array with 100 length for the user if he wants to add more income sources
	income_src j[100];
	float salary;
	float bouns;
	float net_salary;
};
//struct for recurring costs
struct recurring_src
{
	string name;
	float value;
};
struct recurring
{
    //array with 100 length for the user if he wants to add more recurring costs
    recurring_src r[100];
	float carfuel_fees, house_rent, water_fees, elect_fees, food_fees, gas_fees;
};
//struct for expenses costs
struct expenses_src
{
	string name;
	float value;
};
struct expenses
{
    //array with 100 length for the user if he wants to add more expenses costs
    expenses_src e[100];
	float traveling, clothes, entertainment;
};

income a;
recurring b;
expenses c;
int main()
{
	main_menu();
/*	cout << "the test \n" << a.salary;
	cout << "the test2\n" << a.j[0].value;*/
	return 0;
}
void main_menu()
{

    //checking if the user want to go back to main menu
	char check;


    //checking if the user want to fill items again or no
	char check2;
	cout << "\t\t\t\t\twelcome to income tracker program\n \n";
	cout << "\t_____________________________________________________________________________________________________\n\n\n" << endl;
	do
	{
		cout << "\t\t_____________________________________main menu_____________________________________\n" << endl;
		cout << "\t\t\t\tpress y if you want to fill the items or n if you do not \n ";
		cout << "\t\t\t\t";
		cin >> check2;
		cout << "\n";
		if (check2 == 'y')
		{
			inc_in();
			exp_in();
			rc_in();
			nested_menu();
		}

		else if (check2 == 'n')
		{
			nested_menu();
		}
		else
			cout << "\t\t\t\terror please write y or n only\n";
		cout << "\t\t\t\tif you want to back to main menu press y :";
		cin >> check;
	} while (check == 'y');
}
//inc_in for getting salary and bonus from the user
void inc_in()
{
	cout << "\t\t\t\tenter your  salary:  " << endl << "\t\t\t\t";
	cin >> a.salary;
	cout << "\t\t\t\tenter the bouns:   " << endl << "\t\t\t\t";
	cin >> a.bouns;
	a.net_salary = a.salary + a.bouns;
}
//exp_in for getting expenses fees from the user
void exp_in()
{
	cout << "\t\t\t\tenter traveling cost : " << endl << "\t\t\t\t"; cin >> c.traveling; ;
	cout << "\t\t\t\tenter clothes cost: " << endl << "\t\t\t\t"; cin >> c.clothes;
	cout << "\t\t\t\tenter entertainment cost: " << endl << "\t\t\t\t"; cin >> c.entertainment;
}
//rc_in for getting recurring fees from the user
void rc_in()
{
	cout << "\t\t\t\tenter carfuel cost: " << endl << "\t\t\t\t"; cin >> b.carfuel_fees;
	cout << "\t\t\t\tenter houserent cost: " << endl << "\t\t\t\t"; cin >> b.house_rent;
	cout << "\t\t\t\tenter water cost: " << endl << "\t\t\t\t"; cin >> b.water_fees;
	cout << "\t\t\t\tenter food cost: " << endl << "\t\t\t\t"; cin >> b.food_fees;
	cout << "\t\t\t\tenter gas cost : " << endl << "\t\t\t\t"; cin >> b.gas_fees;
}

//fn for deleting the values
void removing()
{
//ck for checking if user want to delete again or not
	char ck;
	do
	{
		string name_value;
        //chk for checking if the name of the value found or not
		bool chk=false;
        //index for saving the index name of the value we want to delete
		int index;
		cout << "\t\t\t\tenter name of value which you want to delete: \n";
		cout << "\t\t\t\t";
		cin >> name_value;
		for (int i = 0;i < 100;i++)
		{
            //checking if the value exist in any array of the three arrays
			if (name_value == a.j[i].name || name_value == c.e[i].name || name_value == b.r[i].name)
			{
				chk = true;
				index= i;
				break;
			}
		}
		if (name_value == "salary")
		{
			DeleteV(a.salary);
		}
		else if (name_value == "bouns")
		{
			DeleteV(a.bouns);
		}
		else if (name_value == "net_salary")
		{
			DeleteV(a.net_salary);
		}
		else if (name_value == "carfull") {
			DeleteV(b.carfuel_fees);
		}
		else if (name_value == "hrent") {
			DeleteV(b.house_rent);
		}
		else if (name_value == "water") {
			DeleteV(b.water_fees);
		}
		else if (name_value == "elect") {
			DeleteV(b.elect_fees);
		}
		else if (name_value == "food") {
			DeleteV(b.food_fees);
		}
		else if (name_value == "gas") {
			DeleteV(b.gas_fees);
		}
		else if (name_value == "clothes") {
			DeleteV(c.clothes);
		}
		else if (name_value == "entertianment") {
			DeleteV(c.entertainment);
		}
		else if (name_value == "traveling") {
			DeleteV(c.traveling);
		}
		else 
		{
			if (chk == true)
			{
				
					if (name_value == a.j[index].name)
					{
						
						DeleteV(a.j[index].value);
					}
					else if (name_value == c.e[index].name)
					{
						
						DeleteV(c.e[index].value);
					}
					else if (name_value == b.r[index].name)
					{
					
						DeleteV(b.r[index].value);
					}
				
			}
			else
				cout << "\t\t\t\terror not found \n";
		}
		cout << "\t\t\t\tif you want to try again press y if not press n\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');
	
}
//edit_exp is fn for editing expenses fees
void edit_exp()
{
    //word for the name of the item the user want to edit
	string word;
    // ck for checking it the user want to edit again
	char ck;
    //to save the index of the item we want to delete
	int index;
	bool check = true;
	do
	{
		cout << "\t\t\t\tenter the item which you want to edit  " << "\n";
		cout << "\t\t\t\t\t\t (clothes , traveling ,entertainment,......)  : \n";
		cout << "\t\t\t\t";
		cin >> word;
		for (int i = 0;i < 100;i++)
		{
			if (word == c.e[i].name)
			{
				check = false;
				index= i;
				break;
			}
		}
		if (word == "clothes")
		{
			cout << "\t\t\t\t";
			cin >> c.clothes;
		}
		else if (word == "traveling")
		{
			cout << "\t\t\t\t";
			cin >> c.traveling;
		}
		else if (word == "entertainment")
		{
			cout << "\t\t\t\t";
			cin >> c.entertainment;
		}
		else
		{
			if (check == false)
			{
				cout << "\t\t\t\tenter the new value \n";
				cout << "\t\t\t\t";
				cin >> c.e[index].value;
			}
			else
				cout << "\t\t\t\t error not found\n";
		}
		cout << "\t\t\t\tif you want to try again press y if not press n\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');
}
//edit_inc is a fn for editing the income
void edit_inc()
{

    //word for the name of the item the user want to edit
    string word;
    // ck for checking it the user want to edit again
    char ck;
    //to save the index of the item we want to edit
    int index;
    bool check = true;
	do
	{
		
		cout << "\t\t\t\tenter the item whitch you want to edit" << "\n";
		cout << "\t\t\t\t\t\t (salary,bouns,.....) : \n";
		cout << "\t\t\t\t";
		cin >> word;
		for (int i = 0;i < 100;i++)
		{
     		if (word == a.j[i].name)
			{
				check = false;
                 index= i;
				break;
			}
		}
		if (word == "salary")
		{
			cout << "\t\t\t\t";

			cin >> a.salary;
		}
		else if (word == "bouns")
		{
			cout << "\t\t\t\t";
			cin >> a.bouns;
		}
		else
		{
			if (check == false)
			{
				cout << "\t\t\t\tenter the new value \n";
				cout << "\t\t\t\t";
				cin >> a.j[index].value;
			}
			else
				cout << "\t\t\t\t error not found\n";
		}
		cout << "\t\t\t\tif you want to edit again press y->\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');
}
//edit_rc is a function for editing the recurring fees
void edit_rc()
{
    //word for the name of the item the user want to edit
    string word;
    // ck for checking it the user want to edit again
    char ck;
    //to save the index of the item we want to edit
    int index;
    bool check = true;
	do
	{
	
		cout << "\t\t\t\tenter the item whitch you want to edit " << "\n";
		cout << "\t\t\t\t\t\t(carful,houserentوwaterوelectricity,food,gas) : \n";
		cout << "\t\t\t\t";
		cin >> word;
		for (int i = 0;i < 100;i++)
		{
			if (word == b.r[i].name)
			{
				check= false;
				index = i;
				break;
			}
		}
		if (word == "carful")
		{
			cout << "\t\t\t\t";
			cin >> b.carfuel_fees;
		}
		else if (word == "houserent")
		{
			cout << "\t\t\t\t";
			cin >> b.house_rent;
		}
		else if (word == " water")
		{
			cout << "\t\t\t\t";
			cin >> b.water_fees;
		}
		else if (word == "electricity")
		{
			cout << "\t\t\t\t";
			cin >> b.elect_fees;
		}
		else if (word == "food")
		{
			cout << "\t\t\t\t";
			cin >> b.food_fees;
		}
		else if (word == "gas")
		{
			cout << "\t\t\t\t";
			cin >> b.gas_fees;
		}
		else
		{
			if (check == false)
			{
				cout << "\t\t\t\tenter the new value \n";
				cout << "\t\t\t\t";
				cin >> b.r[index].value;
			}
			else
				cout << "\t\t\t\t error not found\n";
		}
		cout << "\t\t\t\tif you want to edit agian press y->\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');

}
//inc_add is a fn to add new income sources
void inc_add()
{
	int cnt = 0, num;
	char ck;
	do

	{
		cout << "\t\t\t\thow many items you will add \n";
		cout << "\t\t\t\t";
		cin >> num;
		int i = cnt;
		for (;i < cnt + num;i++)
		{
			cout << "\t\t\t\tenter the name of the itme---> ";
			cin >> a.j[i].name;
			cout << "\t\t\t\tenter the value of the item---> ";
			cin >> a.j[i].value;
		}
		cnt = i; 
		cout << "\t\t\t\t if you want to add new items again press y ->\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');

}
//rc_add is a fn for add new recurring fees
void rc_add()
{
	int cnt = 0, num;
	char ck;
	do

	{
		cout << "\t\t\t\thow many items you will add \n";
		cout << "\t\t\t\t";
		cin >> num;
		int i = cnt;


		for (;i < cnt + num;i++)
		{
			cout << "\t\t\t\tenter the name of the item---> ";
			cin >> b.r[i].name;
			cout << "\t\t\t\tenter the value of the item---> ";
			cin >> b.r[i].value;
		}
		cnt = i;
		cout << "\t\t\t\t if you want to add new items again  press y ->\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');
}
//exp_add is a fn for add new expenses fees
void exp_add()
{
	int cnt = 0, num;
	char ck;
	do

	{
		cout << "\t\t\t\thow many items you will add \n";
		cout << "\t\t\t\t";
		cin >> num;
		int i = cnt;


		for (;i < cnt + num;i++)
		{
			cout << "\t\t\t\tenter the name of the itme---> ";
			cin >> c.e[i].name;
			cout << "\t\t\t\tenter the value of the item---> ";
			cin >> c.e[i].value;
		}
		cnt = i;
		cout << "\t\t\t\tif you want to add new items agian press y ->\n";
		cout << "\t\t\t\t";
		cin >> ck;
	} while (ck == 'y');
}

void nested_menu()
{
    //check for checking if the user need to do a process or not
	char check;
    //choice1 for choosing the process
	int choice1;
    //choice2 for choosing which category the user want to edit
	char choice2;
    //choice3 for choosing which category the user want to add in
    char choice3;
    //ck for choosing which type displaying the user want
	int ck;
    //ck for choosing which category the user want to display
	int ck2;
	cout << "\t\t\t\t if you want to edit/delete/add press y and n if you not  : ";
	cin >> check;
	if (check == 'y')
	{
		cout << "\t\t\t\tpress 1 to delete any item  \n";
		cout << "\t\t\t\tpress 2 to edit any item \n";
		cout << "\t\t\t\tpress 3 to add items \n ";
		cout << "\t\t\t\t";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
		{
			removeing();
			break;
		}

		case 2:
		{
			cout << "\t\t\t\tto edit expenses items press a \n";
			cout << "\t\t\t\tto edit income items press b \n";
			cout << "\t\t\t\tto edit recurring costs c \n";
			cout << "\t\t\t\t";
			cin >> choice2;
			if (choice2 == 'a')
				edit_exp();
			else if (choice2== 'b')
				edit_inc();
			else if (choice2 == 'c')
				edit_rc();
			else

				cout << "\t\t\t\terror not found \n";
			break;
		}
		case 3:
		{
			cout << "\t\t\t\tif you want to add new expenses press a \n";
			cout << "\t\t\t\tif you want to add new income press b \n";
			cout << "\t\t\t\tif you want to add new recurring costs press c \n";
			cout << "\t\t\t\t";
			cin >> choice3;
			if (choice3 == 'a')
			{
				exp_add();
			}
			else if (choice3 == 'b')
			{
				inc_add();
			}
			else if (choice3 == 'c')
			{
				rc_add();
			}
			break;
		}
		default:
		{
			cout << "\t\t\t\terror please enter the numbers from 1 to 3\n";
			break;
		}
		}

	}
	cout << "\t\t\t\tif you want detailed display press 0: or if you want to quick display press 9:";
	cin >> ck;
	if (ck == 0)
	{
		cout << "\t\t\t\tfor income display press 1\n";
		cout << "\t\t\t\tfor recurring costs display press 2\n";
		cout << "\t\t\t\tfor expenses  display press 3\n";
		cout << "\t\t\t\tfor display all items press 0\n";
		cout << "\t\t\t\t";
		cin >> ck2;
		if (ck2 == 1)
		{
			dit_disinc();
		}
		else if (ck2 == 2)
		{
			dit_disrc();
		}
		else if (ck2 == 3)
		{
			dit_disexp();
		}
		else if (ck2 == 0)
		{
			dit_disinc();
			dit_disrc();
			dit_disexp();
		}
		else cout << "\t\t\t\tplease next time try to put the right choice";
	}
	else if (ck == 9)
	{
		cout << "\t\t\t\tfor income display press 1\n";
		cout << "\t\t\t\tfor recurring costs display press 2\n";
		cout << "\t\t\t\tfor expenses  display press 3\n";
		cout << "\t\t\t\tfor display all items press 0\n";
		cout << "\t\t\t\t";
		cin >> ck2 ;
		if (ck2 == 1)
		{
			qk_disin(); 
		}
		else if (ck2 == 2)
		{
			qk_disrc();
		}
		else if (ck2 == 3)
		{
			qk_disexp();
		}
		else if (ck2 == 0)
		{
			qk_disin();
			qk_disrc();
			qk_disexp();
		}
	}
}
void dit_disinc()
{
	int sum = a.salary + a.bouns;
	int index = 0;
	cout << "\t\t\t\tyou get from salary :" << a.salary <<"pound" << "\n";
	cout << "\t\t\t\tyou get from bonus:" << a.bouns << "pound" << "\n";
	cout << "\t\t\t\tyour net salary:" << a.net_salary << "pound" << "\n";

	for (int i = 0;i < 100;i++)
	{
		if (a.j[i].name == "\0")
		{
			index = i;
			break;
		}
	}
	for (int j = 0;j < index;j++)
	{
		cout << "\t\t\t\tyou get from " << a.j[j].name << ":" << a.j[j].value << " pound \n";
		sum = sum + a.j[j].value;
	}
	cout << "\t\t\t\tthe total income you get is " << sum << " pound \n" ;
}
void dit_disrc()
{
	int sum = b.carfuel_fees+b.elect_fees+b.food_fees+b.gas_fees+b.house_rent;
	int x = 0;
	cout << "\t\t\t\tyou pay for  carfuel :" << b.carfuel_fees << "pound" << "\n";
	cout << "\t\t\t\tyou pay for  electricity :" << b.elect_fees << "pound" << "\n";
	cout << "\t\t\t\tyou pay for food :" << b.food_fees << "pound" << "\n";
	cout << "\t\t\t\tyou pay for gas :" << b.gas_fees << "pound" << "\n";
	cout << "\t\t\t\tyou pay for house rent :" << b.house_rent << "pound" << "\n";

	for (int i = 0;i < 100;i++)
	{
		if (b.r[i].name == "\0")
		{
			x = i;
			break;
		}
	}
	for (int k = 0;k < x;k++)
	{
		cout << "\t\t\t\tyou get from " << b.r[k].name << ":" << b.r[k].value<< " pound \n";
		sum = sum + b.r[k].value;
	}
	cout << "\t\t\t\tthe total recurring costs you get is " << sum << " pound \n";
}
void dit_disexp()
{
	int sum = c.clothes+c.entertainment+c.traveling;
	int x = 0;
	cout << "\t\t\t\tyou pay for  clothes :" << c.clothes<<"pound"<<"\n";
	cout << "\t\t\t\tyou pay for  entertainment :" << c.entertainment << "pound" << "\n";
	cout << "\t\t\t\tyou pay for travelling :" << c.traveling << "pound" << "\n";
	for (int i = 0;i < 100;i++)
	{
		if (c.e[i].name== "\0")
		{
			x = i;
			break;
		}
	}
	for (int k = 0;k < x;k++)
	{
		cout << "\t\t\t\tyou get from " << c.e[k].name << ":" << c.e[k].value << " pound \n";
		sum = sum + c.e[k].value;
	}
	cout << "\t\t\t\tthe total expenses you get is " << sum << " pound \n";

}
void qk_disin()
{
	int sum = a.salary + a.bouns;
	int x = 0;
	for (int i = 0;i < 100;i++)
	{
		if (a.j[i].name == "\0")
		{
			x = i;
			break;
		}
	}
	for (int k = 0;k < x;k++)
	{
		sum = sum + a.j[k].value;
	}
	cout << "\t\t\t\tthe total income you get is " << sum << " pound \n";
}
void qk_disrc()
{
	int sum = b.carfuel_fees+b.elect_fees+b.food_fees+b.gas_fees+b.house_rent+b.water_fees;
	int x = 0;
	for (int i = 0;i < 100;i++)
	{
		if (b.r[i].name== "\0")
		{
			x = i;
			break;
		}
	}
	for (int k = 0;k < x;k++)
	{
		sum = sum + b.r[k].value;
	}
	cout << "\t\t\t\tthe total recurring costs you pay is " << sum << " pound \n";
}
void qk_disexp()
{
	int sum = c.clothes+c.entertainment+c.traveling;
	int x = 0;
	for (int i = 0;i < 100;i++)
	{
		if (c.e[i].name == "\0")
		{
			x = i;
			break;
		}
	}
	for (int k = 0;k < x;k++)
	{
		sum = sum + c.e[k].value;
	}
	cout << "\t\t\t\tthe total expenses costs you pay is " << sum << " pound \n";
}