
/*****************************************************************
Student Name:           Abhi Patel
Student No:				040-978-822
Assignment name:		Simon
Assignment Number:      1
Course Name and Number:	CST8219 c++ Programming
Lab Section:			301
Professor Name:         Abdullah Kadri
Due Date:				11 December 2020
Submission Date:		11 December 2020
Files:                  Project
******************************************************************/


#include "project.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <chrono>	
#include <nana/gui/timer.hpp>
#include <cstdlib>
#include <iostream>

/**************************************************************************
					constants
**************************************************************************/
const int lastMenu = 600,lastMenuLength = 600,colorMenu = 550,colorMenuLength = 450,startMenu = 250,startMenuLength = 250;

/**************************************************************************
					Variables 
**************************************************************************/

int a = 0, randomNumber, number_of_count = 0; bool no_error = true, yes_error = false;

/**************************************************************************
					 Using std, nama
**************************************************************************/
using namespace std;
using namespace nana;

/**************************************************************************
					Declaring
**************************************************************************/
color random_C[],userSelected[];
string soundTrack[];
enum class Button { Red, Green, Blue, Yellow };
button* fourButton[4];
vector<int> nextNumber;

/**************************************************************************
					Colors And Timers 
**************************************************************************/
color userSelected[]{
	color(255, 102, 102),
	color(102, 255, 102),
	color(51, 153, 255),
	color(255, 255, 153)
};
struct userTime {
	timer marker,user_t,restart_t;

	userTime()
		: user_t(chrono::seconds(5)),
		marker(chrono::seconds(5/10)),
		restart_t(chrono::seconds(1 / 10))
	{
	}
};

color random_C[]  {
	color(255, 0, 0),
	color(0, 204, 0),
	color(0, 0, 255),
	color(255, 255, 0)
};

string soundTrack[]{
	"Fa_Piano.wav",
	"La_Piano.wav",
	"Mi_Piano.wav",
	"Re_Piano.wav"
};
userTime* stoWatch;

/**************************************************************************
					Function Prototypes
**************************************************************************/
void mainGame(form& );
void ran_Color(form& );
void user_But(int );
void End_user(form&, int );
void user_sel(form& , int );
void pro_method();

/***************************************************************
Function name:		main
Purpose:			Displaying the Starting of the menu (Start New Game and ex)
					and Playing Audio
Return Value:		exce()
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/

int main()
{
	
	string na = "Start New Game",ex = "X";
	form buttonOnScreen;
	stoWatch = new userTime();

	buttonOnScreen.size(nana::size(startMenu, startMenuLength));
	buttonOnScreen.div("vert <<><><<><><ex>>><<><start><>><<><><>>");
	audio::player Do("Do_Octave_Piano.wav");
	button ope{ buttonOnScreen, na };
	ope.events().click([&] {
		Do.play();
		mainGame(buttonOnScreen);
		});
	audio::player sol("Sol_Piano.wav");
	button buy{ buttonOnScreen, ex };
	buy.events().click([&] {
		sol.play();
		buttonOnScreen.close();
		});
	
	

	buttonOnScreen["start"] << ope;
	buttonOnScreen["ex"] << buy;
	
	buttonOnScreen.collocate();
	buttonOnScreen.show();
	
	exec();
	return 0;
}

/***************************************************************
Function name:		End_user
Purpose:			Diaplaying Main menu (option 1: Start New Gme and option 2: Exit) And Playing Background Music 
Return Value:		exec
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/

void End_user(form& game_form, int signal)
{
	if (!yes_error) return;

	yes_error = false;

	cout << "\n\t\tSorry, wrong colour / TimeUP  " << endl;
	audio::player ror("Do_Piano.wav");
	ror.play();

	game_form.close();

	form buttonOnScreen; string re = "Restart ", ex = "Exit";
	buttonOnScreen.size(nana::size(colorMenu, colorMenuLength));

	int amount = nextNumber.size();

	string c_text = "<size = 18 center>Sorry, wrong colour. \nYou made it to round " + to_string(amount) + " of the game" + "</>";
	nana::audio::player sol("Sol_Piano.wav");
	nana::audio::player si("Si_Piano.wav");

	label txt_menu{ buttonOnScreen, c_text };
	button to_start{ buttonOnScreen,re };
	to_start.events().click([&] {
		si.play();
		mainGame(buttonOnScreen);
		});
	button to_stop{ buttonOnScreen, ex };
	to_stop.events().click([&] {
		sol.play();
		buttonOnScreen.close();
		//exit (0);
		//system.exit();
		//abort();
		//to_stop.close();
		//exec();
		//API::exit;
		});

	txt_menu.format(true);
	txt_menu.text_align(align::center, align_v::center);



	buttonOnScreen.div("vert <OverText><Restart><ex>");
	
	buttonOnScreen["ex"] << to_stop;
	buttonOnScreen["OverText"] << txt_menu;
	buttonOnScreen["Restart"] << to_start;

	buttonOnScreen.collocate();
	buttonOnScreen.show();

	stoWatch->restart_t.reset();
	stoWatch->marker.reset();
	stoWatch->user_t.reset();

	if (stoWatch->restart_t.started())
	{
		stoWatch->restart_t.stop();

	}
	
	if (stoWatch->marker.started())
	{
		stoWatch->marker.stop();
		
	}

	if (stoWatch->user_t.started())
	{
		stoWatch->user_t.stop();
	}
	
	
	exec();
}

/***************************************************************
Function name:		user_sel
Purpose:			Checking if the user select the correct color then play Music
Return Value:		void
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/
void user_sel(form& form, int signal)
{
	if (no_error) {
		return ;
	}

	stoWatch->user_t.stop();
	string u_color;
	Button chosen = (Button)signal;
	if ((int)nextNumber[number_of_count] == 1) {
		u_color = "Green";
	}
	else if ((int)nextNumber[number_of_count] == 0) {
		u_color = "Red";
	}
	else if ((int)nextNumber[number_of_count] == 2) {
		u_color = "Blue";
	}
	else if ((int)nextNumber[number_of_count] == 3) {
		u_color = "Yellow";
	}
	string s_color;
	if (signal == 1) {
		s_color = "Green";
	}
	else if (signal == 0) {
		s_color = "Red";
	}
	else if (signal == 2) {
		s_color = "Blue";
	}
	else if (signal == 3) {
		s_color = "Yellow";
	}
	
	if (a == 0) {
		cout << "User Selcted: " << s_color << endl;
		
	}
	
	if (u_color != s_color) {
		cout << "!!!!	USER SELCTED WROUNG COLOR	!!!!" << endl;
	}
	if (nextNumber[number_of_count] != signal)
	{
		End_user(form, signal);
	}
	else 
		{
			number_of_count = number_of_count + 1;

	
			audio::player ic(soundTrack[signal]);
			ic.play();



			if (number_of_count != nextNumber.size())
			{
				stoWatch->user_t.start();
			}
			else {
				ran_Color(form);
			}
		}
	
}

/***************************************************************
Function name:		user_But
Purpose:			Just Playing the Audio
Return Value:		void
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/
void user_But(int signal)
{
	audio::player msic(soundTrack[signal]);
	fourButton[signal]->bgcolor(userSelected[signal]);
	msic.play();

}

/***************************************************************
Function name:		ran_Color
Purpose:			Selectiong Randon number and Color And playing Music according to color
Return Value:		void
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/
void ran_Color(form& form)
{
	
	if (stoWatch->marker.started()) { stoWatch->marker.stop(); }
	int n_selection = rand() % 4;
	nextNumber.push_back(n_selection);
	number_of_count = 0;
	no_error = true;
	int i = 1;
	cout << "\nRandon selected color is: ";
	//for (int btn = 0; btn <nextNumber; btn++) {
	for (int btn : nextNumber) {
		string ran_color;
		if (btn == 1) {
			ran_color = "Green";
		}
		if (btn == 0) {
			ran_color = "Red";
		}
		if (btn == 2) {
			ran_color = "Blue";
		}
		if (btn == 3) {
			ran_color = "Yellow";
		}
		if (i == 1) {
			cout << ran_color << " \t ";
			i++;
		}
		else if (i != 1) {
			cout << "\tNext: " << ran_color << " ";
		}
	}
	cout << endl;

	randomNumber = 0;

	stoWatch->marker.elapse(pro_method);
	user_But(nextNumber[0]);

	stoWatch->marker.start();
}

/***************************************************************
Function name:		mainGame
Purpose:			Formatting the Button (like Background Color)
Return Value:		exec
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/
void mainGame(form& old)
{
	srand(time(0));
	old.close();

	threads::pool pool(1);


	form buttonOnScreen;
	buttonOnScreen.size(nana::size(lastMenu, lastMenuLength));


	button btnRed{ buttonOnScreen }, btnGreen{ buttonOnScreen }, btnBlue{ buttonOnScreen }, btnYellow{ buttonOnScreen };
	no_error = true;
	yes_error = true;
	nextNumber.clear();
	randomNumber = 0;
	number_of_count = 0;
	fourButton[0] = &btnRed;
	fourButton[1] = &btnGreen;
	fourButton[2] = &btnBlue;
	fourButton[3] = &btnYellow;

	int loop = 0;
	while (loop < 4)

	{
		button& bt = *fourButton[loop];
		bt.bgcolor(random_C[loop]);
		bt.enable_focus_color(false);
		bt.events().click([&buttonOnScreen, loop] { user_sel(buttonOnScreen, loop); });
		loop++;
	}

	buttonOnScreen.div("vert <<Green><Red>><<Yellow><Blue>>");

	buttonOnScreen["Red"] << btnRed;
	buttonOnScreen["Blue"] << btnBlue;
	buttonOnScreen["Yellow"] << btnYellow;
	buttonOnScreen["Green"] << btnGreen;


	buttonOnScreen.collocate();
	buttonOnScreen.show();

	ran_Color(buttonOnScreen);

	stoWatch->user_t.elapse([&] { End_user(buttonOnScreen, -1); });

	exec();
}

/***************************************************************
Function name:		pro_method
Purpose:			If the user select correct the going on the next step
Return Value:		void
Version :           3.8
Student Name:		Abhi Patel (Pate0789)
***************************************************************/
void pro_method()
{
	int last_selc;

	if (!yes_error)
	{
		stoWatch->marker.stop();
		return;
	}

	last_selc = nextNumber[randomNumber];

	fourButton[last_selc]->bgcolor(random_C[last_selc]);

	if (++randomNumber >= nextNumber.size())
	{
		
		no_error = false;
		stoWatch->marker.stop();
		stoWatch->user_t.start();
	}
	else
	{
		user_But(nextNumber[randomNumber]);
	}
}



