#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

#define maxclients 100
#define maxtrainers 100


//structures (all the team participate )//

struct clients
{
	int client_id;
	string username;
	string password;
	string workout_plans[100];
	string progress_logs[100];
	int measurments[100];

} client[maxclients];


struct trainers
{
	int trainer_id;
	string username;
	string password;
	string clients[maxclients];

} trainer[maxtrainers];


struct workouts
{
	int workout_id;
	string workout_name;
	string exercises[100];
	int duration;

};









//all the declaraintions//


void register_trainer(int&);
int login_trainer(int);

void register_client(int&);
int login_client(int);













//program run//

int main()
{
	//intializations//
	int TorC ,RorL;
	int Trainer_index = 0 , Client_index=0;
	int index_of_C=0, index_of_T=0;
	bool run = true;
	int choice;


	////////////////////////////////////////////////////////////////////////////////

	while (true)
	{

		//to know (clint or trainer) //
		cout << "--------------------------------------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t -- hello to our fitness center --\n";
		cout << "1) Trainer\n2) Client\n";
		cout << "can you please choose a option: ";
		cin >> TorC;
		cout << "--------------------------------------------------------------------------\n\n";


		// registration and login process//

		switch (TorC)
		{
		case 1:
			while(true)
			{ 
			cout << "--------------------------------------------------------------------------\n\n";
			cout << "--Hello Trainer--\n\n";
			cout << "1) Register\n2) Login\n3) Exit\n";
			cout << "can you please choose a option: ";
			cin >> RorL;

			switch (RorL)
			{
			case 1:
				register_trainer(Trainer_index);
				Trainer_index++;
				break;


			case 2:
				index_of_T = login_trainer(Trainer_index);
				if (index_of_T != -1)
				{
					cout << "you are looged in succefully\n";
					cout << "--------------------------------------------------------------------------\n\n";
					cout << "--Trainer control center--\n\n";
					cout << "1) View clients\n2) Create workouts\n3) Assign workouts\n4) View client progress\n5) Logout\n";
					cout << "Can you please chouse an option : ";
					cin >> choice;
					switch (choice)
					{
					case 1:

						break;
					case 2:

						break;
					case 3:

						break;
					case 4:

						break;
					case 5:

						break;
					default:
						cout << "Imvalid choice\n\n";
						cout << "--------------------------------------------------------------------------\n\n";

					}
				}

				else
				{
					cout << "incorrect username or password\n\n";
					cout << "--------------------------------------------------------------------------\n\n";
				}

				break;

			case 3 :
				goto back_to_mainmenu_T;
				break;

			default: 
				cout << "Invalid choice\n\n";
				cout << "--------------------------------------------------------------------------\n\n";


			}
			
			} //close loop//
			break;

		back_to_mainmenu_T:
			break;
			

		case 2:
			while(true)
			{ 
		    cout << "--------------------------------------------------------------------------\n\n";
			cout << "--Hello Client--\n\n";
			cout << "1) Rigester\n2) Login\n3) Exit\n";
			cout << "can you please choose a option: ";
			cin >> RorL;
			switch (RorL)
			{
			case 1:
				register_client(Client_index);
				Client_index++;
				break;


			case 2:
				index_of_C = login_client(Client_index);
				if (index_of_C != -1)
				{
					cout << "you are looged in succefully\n";
					cout << "--------------------------------------------------------------------------\n\n";
					cout << "--Client control center--\n\n ";
					cout << "1) View workouts\n2) Log workouts\n3) Log measurments\n4) Logout\n";
					cout << "Can you please chouse an option";
					cin >> choice;
					switch (choice)
					{
					case 1:

						break;
					case 2:

						break;
					case 3:

						break;
					case 4:

						break;

					default:
						cout << "Imvalid choice\n\n";
						cout << "--------------------------------------------------------------------------\n\n";



					}
				}

				else
				{
					cout << "incorrect username or password\n\n";
					cout << "--------------------------------------------------------------------------\n\n";
				}

				break;
			case 3:
				goto back_to_mainmenu_C;

				break;

			default:
				cout << "Imvalid choice\n\n";
				cout << "--------------------------------------------------------------------------\n\n";

			}

			} //close loop//

			break;

		back_to_mainmenu_C:
			break;


		default:
			cout << "invalid choice\n\n";
			cout << "--------------------------------------------------------------------------\n\n";


		}

	}

}




//functions//

void register_trainer( int&Trainer_index)
{
	cout << "--------------------------------------------------------------------------\n\n";
	cout << "--Registration Page (Trainer)--\n\n";


	cout << "Enter your username : ";
	cin >> trainer[Trainer_index].username;
	cout << "Enter your Password : ";
	cin >> trainer[Trainer_index].password;
	


	
}

int login_trainer(int total_trainers)
{
	string username, password;
	cout << "--------------------------------------------------------------------------\n\n";
	cout << "--Login Page--\n\n";


	cout << "Enter your username : ";
	cin >> username;
	cout << "Enter your Password : ";
	cin >> password;


	for (int i = 0; i < total_trainers; i++)
	{
		if (username == trainer[i].username && password == trainer[i].password)
			return i;
		
			
	}

	return -1;


}


void register_client(int& Client_index)
{
	cout << "--------------------------------------------------------------------------\n\n";
	cout << "--Registration Page (Client)--\n\n";


	cout << "Enter your username : ";
	cin >> client[Client_index].username;
	cout << "Enter your Password : ";
	cin >> client[Client_index].password;

}


int login_client(int total_clients)
{
	string username, password;
	cout << "--------------------------------------------------------------------------\n\n";
	cout << "--Login Page (Client)--\n\n";


	cout << "Enter your username : ";
	cin >> username;
	cout << "Enter your Password : ";
	cin >> password;

	for (int i = 0; i < total_clients; i++)
	{

		if (username == client[i].username && password == client[i].password)
			return i;
		
	}

	return -1;

}