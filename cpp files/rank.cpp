#include"rank.h"
void getleaderboard()
{
	int h;
	int m;
	int s;
	string filename;
	int i = 0;
	ifstream in;
	in.open("input.txt");
	struct info if1;
	while (!in.eof())
	{
		in >> if1.mode;
		in >> if1.size;
		in >> if1.time;
	}
	in.close();
	if (if1.mode == "B")
	{
		if (if1.size == 4)
		{
			ofstream out;
			filename = "Basic4x4.txt";
			out.open("Basic4x4.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;
			out.close();
		}
		else if (if1.size == 6)
		{
			ofstream out;
			filename = "Basic6x6.txt";
			out.open("Basic6x6.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;
			out.close();
		}
		else if (if1.size == 8)
		{
			ofstream out;
			filename = "Basic8x8.txt";
			out.open("Basic8x8.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;
			out.close();
		}
	}
	else if (if1.mode == "A")
	{
		if (if1.size == 4)
		{
			ofstream out;
			filename = "Advanced4x4.txt";
			out.open("Advanced4x4.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;
			out.close();
		}
		else if (if1.size == 6)
		{
			ofstream out;
			filename = "Advanced6x6.txt";
			out.open("Advanced6x6.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;
			out.close();
		}
		else if (if1.size == 8)
		{
			ofstream out;
			filename = "Advanced8x8.txt";
			out.open("Advanced8x8.txt", ios::app);
			h = if1.time / 3600;
			m = (if1.time % 3600) / 60;
			s = (if1.time % 3600) % 60;
			out << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " " << if1.time;

			out.close();
		}
	}
	rankleaderboard(filename);
}
void rankleaderboard(string filename)
{
	int n = 0;
	ifstream in;
	struct time temp;
	in.open(filename);
	struct time t1[55];
	while (!in.eof())
	{
		in >> t1[n].fulltime;
		in >> t1[n].seconds;
		n++;
	}
	in.close();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t1[i].seconds > t1[j].seconds)
			{
				temp = t1[i];
				t1[i] = t1[j];
				t1[j] = temp;
			}

		}
	}
	ofstream out;
	out.open(filename);
	for (int i = 0; i < n; i++)
	{
		out << t1[i].fulltime << " " << t1[i].seconds << "\n";
	}
	out.close();
}
void read(string filename)
{
	system("cls");
	draw2();
	int i = 1;
	string time;
	int seconds;
	ifstream in;
	in.open(filename);
	gotoxy(0, 11);
	setcolor(11);
	while (!in.eof())
	{
		cout << "   ------------------------------------------------------\n";
		in >> time;
		in >> seconds;
		if (seconds < 0)
		{
			break;
		}
		cout << "         " << i << "\t   " << time << "\t   " << seconds<<" sec";
		cout << "\n";
		i++;
		if (i == 11)
		{
			cout << "   ------------------------------------------------------\n";
			break;
		}
	}
	setcolor(78);
	gotoxy(30, 33);
	cout << "Press Enter to go back";
	setcolor(7);
	in.close();
}
void draw2()
{
	setcolor(222);
	gotoxy(26, 5);
	cout << " __    _____ _____ ____  _____ _____ _____ _____ _____ _____ ____  ";
	gotoxy(26, 6);
	cout << "|  |  |   __|  _  |     \|   __| __  | __  |     |  _  | __  |    \\ ";
	gotoxy(26, 7);
	cout << "|  |__|   __|     |  |  |   __|    -| __ -|  |  |     |    -|  |  |";
	gotoxy(26, 8);
	cout << "|_____|_____|__|__|____/|_____|__|__|_____|_____|__|__|__|__|____/ \n";
	gotoxy(26, 9);
	cout << "                                                                   \n";
	/*gotoxy(20, 11);
	cout << "\_____\____\_| |_|___/ \____/\_| \_\____/ \___/\_| |_\_| \_|___/  \n";*/

}