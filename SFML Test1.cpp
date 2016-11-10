// SFML Test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <regex>
#include <time.h>
#include <random>


using namespace std;

// Global Variables
sf::Font Font1;
sf::RenderWindow Surface(sf::VideoMode(800,600),"Battleground");
sf::Color Brown = sf::Color(126,79,52);
sf::Color Maroon = sf::Color(69,44,29);
sf::Color BFill = sf::Color(102,65,43);
sf::Color Grey = sf::Color(195,195,195);

int SIDE_DISTANCE = 24;
int LINE_WIDTH = 4;
int SQUARE_SIZE = 55;
int SCALE = 3;

//Predefinitions of Functions
void DrawText(string Msg,float TSize,sf::Color TColor,float PosX,float PosY,bool isBold, bool isUnderlined);
void MakeSprite(string Image1,float PosX,float PosY,int SFX,int SFY);
void CreateRect(float Len,float Width,sf::Color Fill,sf::Color Out,float Edge,float PosX,float PosY);
void CreateCircle(sf::Color Fill,sf::Color Out,float Edge,float PosX,float PosY,float Rad);
int RandomInt(int Min, int Max);
string KeyboardLoop(string Title, int Mode);
void ErrorMsg();
bool Confirm(string NoOfSquares,string Units,string NoOfPlayers,string isBot,string Difficulty);
int BattleMain(string Mode, int NoOfPlayers, int UnitsPerSide, int NoOfSquares, int Difficulty, int isBot);
// Class Definitions

class Character
{
public:
	vector<int> Pos;
	string Class;
	string Direction;
	int MovementStage;
	bool isMoved;
	void MoveImage(int PosX,int PosY);
};

void Character::MoveImage(int AddX, int AddY)
{
	// PosX and PosY are the distances relative to the unit which a unit needs to move
	sf::RenderWindow SurfaceDef(sf::VideoMode(800,600),"Battleground");
	SurfaceDef = Surface;
	// Alter Surface2 in a loop, and as Surface2 is a local variable
	// Distance Crossed = Number of Squares*59
	for(int Count = 0; Count<
};


class Unit // Define Superclass Unit
{
public:  // Public Variable Definitions
	string Name,Class,Team;
	int Experience,Level;
	vector<int> Pos;
	Character MyImage;
	//Equip Equipment;
	//Attrs Stats;
	vector<vector<int>> Show(int BaseX, int BaseY);
	void Info();
	void Predict(Unit Enemy);
	void Attack(Unit Enemy);
};

vector<vector<int>> Unit::Show(int BaseX, int BaseY) // Show method definition
{
    vector<vector<int>> ValidMoves;
    bool Condition = false;
    for(int X = 0;X<=3;X++)
    {
        for(int Y = 0;Y<=3;Y++)
        {
            vector<int> Positions;
            if(Class == "Alumni") Condition = (X == Y);
			else if(Class == "Barbarian") Condition = ((X<2 && Y<2));
			else if(Class == "Cleric") Condition = ((X>0 && Y == 0) || (Y>0 && X == 0));
			else if(Class == "Crusader") Condition = ((X==1 && (Y==1||Y==2)) || (Y==1 && (X==1||X==2)));
			else if(Class =="Gladiator") Condition = ((X==2 && Y<2)||(Y==2 && X<2));
			else if(Class == "Knight") Condition = ((X==2 && Y==1)||(Y==2 && X ==1));
			else if(Class == "Mage") Condition = (X==2 && Y==2);
			else if(Class == "Minstrel") Condition = ((X>0 && Y == 0)||(Y>0 && X == 0)||(Y==X));
			else if(Class == "Paladin") Condition = ((X == 2 && Y == 0)||(X == 0 && Y == 2));
			else if(Class == "Warmonger") Condition = (X>=1 && X<=2 && Y>=1 && Y<=2);
			else if(Class == "Warrior") Condition =	((X==2 && Y==2)||(X==1 &&(Y==1||Y==3))||(Y==1 &&(X==1||X==3)));
            if(Condition == true && (X+Y !=0)) // X,Y increase is valid
            {
				int Quarters[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
				for(int Count = 0; Count<4;Count++)
				{
					vector<int> Positions;
					Positions.push_back(BaseX+(X*Quarters[Count][0]));
					Positions.push_back(BaseY+(Y*Quarters[Count][1]));
					ValidMoves.push_back(Positions);
				}
				cout<<X<<" "<<Y<<endl;
            }
        }
	}
	cout<<ValidMoves[0][0]<<endl;
	return ValidMoves;
};

void Unit::Info() // Info method definiton
{
};

void Unit::Predict(Unit Enemy) // Predict method definition
{
};

void Unit::Attack(Unit Enemy) // Attack method definition
{
};



class Random: public Unit // Define Subclass Random
{
public:
	void Define(int MaxLevel, string team, int MaxEquipLevel, int TotalStats,int X, int Y);
};

void Random::Define(int MaxLevel, string team, int MaxEquipLevel, int TotalStats,int X, int Y) // Define method definition
{
	// Need to define Name, Class, Team, Experience and Level

	Name = "jimbob";
	string Classes[11] = {"Alumni","Barbarian","Cleric","Crusader","Gladiator","Knight","Mage","Minstrel","Paladin","Warmonger","Warrior"};
	Class = Classes[RandomInt(0,10)];
	Team = team;
	Experience = 0;
	Level = RandomInt(1,MaxLevel);
	Pos.push_back(X);
	Pos.push_back(Y);
	MyImage.isMoved = false;
	
};

class Story: public Unit // Define Subclass Story
{
public:
	void Define(int StoryID, string team);
};

void Story::Define(int StoryID, string team) // Define method definition
{
};

// CreateText
void DrawText(string Msg,int TSize,sf::Color TColor,float PosX,float PosY,bool isBold, bool isUnderlined)
{
	Font1.loadFromFile("Dalila.ttf");
	sf::Text Msg1;
	Msg1.setFont(Font1);
	Msg1.setColor(TColor);
	Msg1.setCharacterSize(TSize);
	Msg1.setString(Msg);
	Msg1.setPosition(PosX,PosY);
	if(isBold == true) Msg1.setStyle(sf::Text::Bold);
	if(isUnderlined == true) Msg1.setStyle(sf::Text::Underlined);
	Surface.draw(Msg1);
}

// MakeSprite
void MakeSprite(string Image1,float PosX,float PosY,int SFX,int SFY)
{
	sf::Image Img1;
	Img1.loadFromFile(Image1);
	Img1.createMaskFromColor(sf::Color::White);
	sf::Texture Txtr1;
	Txtr1.loadFromImage(Img1);
	sf::Sprite Spr1;
	Spr1.setTexture(Txtr1);
	Spr1.setScale(sf::Vector2f(SFX,SFX));
	Spr1.setPosition(PosX,PosY);
	Surface.draw(Spr1);
}

// CreateRect
void CreateRect(float Len,float Width,sf::Color Fill,sf::Color Out,float Edge,float PosX,float PosY)
{
	sf::RectangleShape Rect1;
	Rect1.setFillColor(Fill);
	Rect1.setOutlineColor(Out);
	Rect1.setPosition(PosX,PosY);
	Rect1.setSize(sf::Vector2f(Len,Width));
	Rect1.setOutlineThickness(Edge);
	Surface.draw(Rect1);
}

// CreateCircle
void CreateCircle(sf::Color Fill,sf::Color Out,float Edge,float PosX,float PosY,float Rad)
{
	sf::CircleShape Circ1;
	Circ1.setFillColor(Fill);
	Circ1.setOutlineColor(Out);
	Circ1.setOutlineThickness(Edge);
	Circ1.setPosition(PosX,PosY);
	Circ1.setRadius(Rad);
	Surface.draw(Circ1);
}

// Menu125 loop function
int Menu125(string BackG,string Title,string Button1, string Button2, string Button3)
{
	bool isButton = false;
	sf::Vector2i Pos =  sf::Mouse::getPosition(Surface);
	int Option = 0;
	sf::Event Eve;
	cout<<sizeof(Button1)<<endl;
	cout<<Button3.length()<<endl;
	while(isButton == false)
	{
		Surface.clear();
		MakeSprite(BackG,0,0,4,4);
		Pos =  sf::Mouse::getPosition(Surface);
		if((Pos.x <500 && Pos.x > 300 && Pos.y < 280 && Pos.y > 230)&&(Button1.length()>0))
		{
			CreateRect(270,50,BFill,Maroon,5,265,230);
			DrawText(Button1,40,sf::Color::Yellow,400-(Button1.length()*10),225,false,false);
		}
		else
		{

			if(Button1.length() >0)CreateRect(270,50,BFill,Maroon,5,265,230); 
			DrawText(Button1,40,sf::Color::Black,400-(Button1.length()*10),225,false,false);
		}
		if((Pos.x <500 && Pos.x > 300 && Pos.y <360 && Pos.y >310)&&(Button2.length()>0))
		{
			CreateRect(270,50,BFill,Maroon,5,265,310);
	        DrawText(Button2,40,sf::Color::Yellow,400-(Button2.length()*10),305,false,false);
		}
		else
		{
			if(Button2.length()>0) CreateRect(270,50,BFill,Maroon,5,265,310);
			DrawText(Button2,40,sf::Color::Black,400-(Button2.length()*10),305,false,false);
		}
		if(Pos.x<500 && Pos.x >300 && Pos.y <440 && Pos.y >390)
		{
			CreateRect(270,50,BFill,Maroon,5,265,390);
			DrawText(Button3,40,sf::Color::Yellow,400-(Button3.length()*10),385,false,false);
		}
		else
		{
			if(Button3.length()>0) CreateRect(270,50,BFill,Maroon,5,265,390);
			DrawText(Button3,40,sf::Color::Black,400-(Button3.length()*10),385,false,false);
		}
		DrawText(Title,40,sf::Color::Black,275,150,true,true);
		Surface.display();
		sf::Event Eve;
		while (Surface.pollEvent(Eve))
			{
			switch(Eve.type)
				{
				case(sf::Event::Closed):
					Surface.close();
					break;
				case(sf::Event::MouseButtonPressed):
					if((Pos.x <535 && Pos.x > 265 && Pos.y < 280 && Pos.y > 230)&&(Button1.length()>0))
					{
						Option = 0;
						isButton = true;
						break;
					}
					if((Pos.x <535 && Pos.x > 265 && Pos.y <360 && Pos.y >310)&&(Button2.length()>0))
					{
						Option = 1;
						isButton = true;
						break;
					}
			
					if((Pos.x<530 && Pos.x >265 && Pos.y <440 && Pos.y >390)&&(Button3.length()>0))
					{
						Option = 2;
						isButton = true;
						break;
					}
					
				}
			}
	}
	return Option;
}


// Menu34 loop function
int Menu34(string Mode,int* Difficult, int* NoOfPlayer, int*NoSquare, int* Unit,int* Bot)
{
	// NoOfSquares = 0;
	// UnitsPerSide = 0;
	// Number of Players = 0;
	// While All Inputs are Invalid
	string Diff = "0";
	int Difficulty = *Difficult;

	string NoPlayers = "2";
	int NoOfPlayers = *NoOfPlayer;

	string NoOfSquares = "0";
	int NoSquares = *NoSquare;

	string UnitsPerSide = "0";
	int Units = *Unit;

	string IsBot = "0";
	int isBot = *Bot;

	bool isValid = false;
	while(isValid == false)
	{
		try
		{
			// NoOfSquares
			NoOfSquares = KeyboardLoop("Number of \nboard Squares \n(8-25)",0);
			NoSquares = stoi(NoOfSquares,nullptr,10);
			if(NoSquares<8 || NoSquares>25)
			{
				ErrorMsg();
				continue;
			}
			// UnitsPerSide
			UnitsPerSide = KeyboardLoop("Units Per Side \n(Max 50)",0);
			Units = stoi(UnitsPerSide,nullptr,10);
			if(Units<1 || Units>50)
			{
				ErrorMsg();
				continue;
			}
			if(Mode == "Annihilation")
			{
				NoPlayers = KeyboardLoop("Number of\nPlayers (2-6)",0);
				NoOfPlayers = stoi(NoPlayers,nullptr,10);
				cout<<NoOfPlayers<<" Number of Players 1"<<endl;
				if(NoOfPlayers<2 || NoOfPlayers>6)
				{
					ErrorMsg();
					continue;
				}
			}
			IsBot = KeyboardLoop("Play with Bot?\n(0 or 1)",0);
			isBot = stoi(IsBot,nullptr,10);
			if(!(isBot == 1||isBot == 0))
			{
				ErrorMsg();
				continue;
			}
			if(isBot==1)
			{
				Diff = KeyboardLoop("Enter bot\nDifficulty\n(1,2,3,4)",0);
				Difficulty = stoi(Diff,nullptr,10);
				cout<<Diff<<endl;
				if(Difficulty<1 || Difficulty>4)
				{
					ErrorMsg();
					continue;
				}
			}
			cout<<Diff<<endl;
			bool Choice = Confirm(NoOfSquares,UnitsPerSide,NoPlayers,IsBot,Diff);
			if(Choice == true)
			{
				cout<<NoOfPlayers<<" Number of Players F"<<endl;
				*Difficult = Difficulty;
				*NoOfPlayer = NoOfPlayers;
				*NoSquare = NoSquares;
				*Unit = Units;
				*Bot = isBot;
				return 1;
			}
			else if(Choice == false)
			{
				cout<<"PreRejected"<<endl;
				return 0;
			}
		}
		catch(...)
		{
			ErrorMsg();
		}
	}
	// Loop for each textbox
	// Check if Output is valid
	// depending on output, do bot
	// --------------------------------Confirm Output---------------------------------
}

bool Confirm(string NoOfSquares,string Units,string NoOfPlayers,string isBot,string Difficulty)
{
	bool isEntered = false;
	sf::Vector2i Pos =  sf::Mouse::getPosition(Surface);
	while(isEntered == false)
	{
		Surface.clear();
		MakeSprite("Menu125.png",0,0,4,4);
		DrawText("Number of Squares:",25,sf::Color::Black,260,150,false,false);
		DrawText(NoOfSquares,25,sf::Color::Black,500,150,true,false);
		DrawText("Units Per Side:",25,sf::Color::Black,260,200,false,false);
		DrawText(Units,25,sf::Color::Black,500,200,true,false);
		DrawText("Number of Players:",25,sf::Color::Black,260,250,false,false);
		DrawText(NoOfPlayers,25,sf::Color::Black,500,250,true,false);
		DrawText("Bot Enabled:",25,sf::Color::Black,260,300,false,false);
		DrawText(isBot,25,sf::Color::Black,500,300,true,false);
		if(Difficulty != "0")
		{
			DrawText("Difficulty Level:",25,sf::Color::Black,260,350,false,false);
			DrawText(Difficulty,25,sf::Color::Black,500,350,true,false);
		}
		Pos =  sf::Mouse::getPosition(Surface);
		// Y = 450, X = 260 and 400
		CreateRect(125,50,BFill,Maroon,5,260,400);
		CreateRect(125,50,BFill,Maroon,5,400,400);
		if((Pos.x<385 && Pos.x>260 && Pos.y>400 && Pos.y<450)) DrawText("Confirm",30,sf::Color::Yellow,270,410,true,false);
		else DrawText("Confirm",30,sf::Color::Black,270,410,true,false);
		if((Pos.x<525 && Pos.x>400 && Pos.y>400 && Pos.y<450)) DrawText("Reject",30,sf::Color::Yellow,410,410,true,false);
		else DrawText("Reject",30,sf::Color::Black,410,410,true,false);
		sf::Event Eve;
		while(Surface.pollEvent(Eve))
		{
			switch(Eve.type)
			{
			case(sf::Event::Closed):
				Surface.close();
				break;
			case(sf::Event::MouseButtonPressed):
				if((Pos.x<385 && Pos.x>260 && Pos.y>400 && Pos.y<450))
				{
					return true;
				}
				else if((Pos.x<525 && Pos.x>400 && Pos.y>400 && Pos.y<450))
				{
					return false;
				}
			}
		}
		Surface.display();
	}
	//return ;
}

void ErrorMsg()
{
	Surface.clear();
	CreateRect(400,150,Maroon,Brown,5,200,250);
	DrawText("Error: Invalid Input\nPress Any Key To Continue",30,sf::Color::Black,210,260,true,false);
	Surface.display();
	sf::Event Eve2;
	bool isEnter2 = false;
	while(isEnter2 == false)
	{
		while(Surface.pollEvent(Eve2))
		{
			if(Eve2.type == sf::Event::KeyPressed) isEnter2 = true;
		}
	}
}

string KeyboardLoop(string Title,int Mode)
{
	string Nums[10] = {"0","1","2","3","4","5","6","7","8","9"};
    string Alpha[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	bool isEntered = false;
	string Word = "";
	while(isEntered == false)
	{
		try
		{
			sf::Event event1;
			while (Surface.pollEvent(event1))
			{
				Surface.clear();
				MakeSprite("Menu125.png",0,0,4,4);
				DrawText(Title,40,sf::Color::Black,260,150,true,true);
				CreateRect(280,50,BFill,Maroon,5,260,300);
				DrawText(Word,35,sf::Color::Black,270,300,false,false);
				DrawText("Press Enter to Continue \n(No Capitals Please)",25,sf::Color::Black,260,380,false,false);
				Surface.display();
				if(event1.type == sf::Event::KeyPressed)
				{
					//cout<<event1.key.code<<endl;
					if(event1.key.code == 59 && Word.length()>0)
					{
						// Backspace has been pressed
						string NewWord;
						for(int Count = 0; Count<Word.length()-1; Count++) 
						{
							NewWord += Word[Count];
						}
						Word = NewWord;
					}
					else if(event1.key.code == 58 && Word.length()>0)
					{
						isEntered = true;
						break;
					}
					else if (Word.length()<10)
					{
						int Num = event1.key.code;
						if(Mode==0)
						{
							Num -= 26;
							string Char = Nums[Num];
							//cout<<Word<<" Original"<<endl;
							//cout<<Char<<" Char"<<endl;
							Word = Word + Char;
							//cout<<Word<<" New"<<endl;
						}
						else
						{
							string Char = Alpha[Num];
							Word = Word+Char;
						}
					}
				}
			}
		}	
		catch(...)
		{
			ErrorMsg();
		}
	}
	return Word;
}

string ReadfromFile(void)
{
	ifstream input;
	input.open("Names.txt",ios::in);
	if(input.fail())
	{
		cerr << "Error opening File" <<endl;
		exit(1);
	}
	string line;
	string File = "";
	while (!input.eof())
	{
		getline(input,line);
		File += line;
		File += "\n";
	}
	input.close();
	return File;
}

void Opening()
{
    // Wait Statement
	for(int Count = 0; Count<255;Count++)
	{
		Surface.clear();
		sf::Color Fluid = sf::Color(0,0,0,255-Count);
		MakeSprite("Battleground Loading Page.png",0,0,1,1);
		CreateRect(800,600,Fluid,Fluid,0,0,0);
		Surface.display();
	}
	// Wait Statement
	string Instructions = ReadfromFile();
	Surface.clear();
	MakeSprite("AWESOMEBACK.PNG",0,0,5,5);
	DrawText("Instructions:",40,Brown,50,50,true,true);
	DrawText(Instructions,20,Maroon,50,100,true,false);
	Surface.display();
}


// MenuHub function
int MenuMain()
{
	// Load Game Campaign Data
	//Opening();
	int OptionC = 4;
	int OptionS = 4;
	int Difficulty = 0;
	int NoOfSquares = 0;
	int NoOfPlayers = 2;
	int UnitsPerSide = 0;
	int isBot = 0;
	// Opening Screen
	// Opening();
	// Menu System
	bool isChosen = false;
	while(isChosen==false)
	{
		int OptionMain = Menu125("Menu125.png","Battleground","Campaign"," Skirmish","Exit");
		if(OptionMain == 0)
		{
			// Load Game Campaign Data
			// If Data Retrieval is successful... else ...
			OptionC = Menu125("Menu125.png","Campaign","New Game","Load Game","Back To Main");
			if(OptionC ==0)
			{
				// New Game
			}
		}
		else if (OptionMain == 1)
		{
			int Choice = 0;
			string Mode = "";
			OptionS = Menu125("Menu125.png","Skirmish","Classic","Annihilation","Back To Main");
			if(OptionS == 0)
			{
				// Classic Mode
				Choice = Menu34("Classic",&Difficulty,&NoOfPlayers,&NoOfSquares,&UnitsPerSide,&isBot);
				Mode = "Classic";
			}
			else if(OptionS == 1)
			{
				// Annihilation Mode
				Choice = Menu34("Annihilation",&Difficulty,&NoOfPlayers,&NoOfSquares,&UnitsPerSide,&isBot);
				Mode = "Annihilation";
			}
			if(Choice == 1)
			{
				int X = BattleMain(Mode,NoOfPlayers,UnitsPerSide,NoOfSquares,Difficulty,isBot);
				isChosen = true;
			}
		}
	}
	return 0;
}

// DrawGrid function
void DrawGrid(float NoOfSquares,int X,int Y,string TerrainFile)
{
	int Square = LINE_WIDTH + SQUARE_SIZE;
	int Grid = Square*NoOfSquares+LINE_WIDTH;
	int TotLen = (SIDE_DISTANCE*2)+Grid;
	sf::Color Grass = sf::Color(40,213,92);
	if(TotLen>500) CreateRect(TotLen,TotLen,Grass,Grass,0,350-X,-Y);
	MakeSprite(TerrainFile,350-X,-Y,TotLen/40,TotLen/40);

	for(int Count = 0;Count<NoOfSquares+1;Count++)
	{
		CreateRect(Grid,LINE_WIDTH,sf::Color::Black,sf::Color::Black,0,350+SIDE_DISTANCE-X,SIDE_DISTANCE-Y+Square*Count);
		CreateRect(LINE_WIDTH,Grid,sf::Color::Black,sf::Color::Black,0,350+SIDE_DISTANCE-X+Square*Count,SIDE_DISTANCE-Y);
	}
}

// DrawSprite function
void DrawSprite(string SpriteClass,string team, int PosX, int PosY, int X, int Y, bool isMoved)
{
	sf::Color SquareColor = sf::Color::Transparent;
	sf::Color colors[6] = {sf::Color::Red,sf::Color::Blue,sf::Color::Green,sf::Color::Magenta,sf::Color::White,sf::Color::Yellow};
	string teams[6] = {"Red","Blue","Green","Magenta","White","Yellow"};
	for(int count=0;count<6;count++) if(teams[count] == team) SquareColor = colors[count];
	string NClass = "ImageClasses\\";
	NClass += SpriteClass;
	NClass += "\\";
	NClass += SpriteClass;
	NClass += "2F.png";
	//replace(NClass.begin(),NClass.end(),'x',SpriteClass);
	int WindowX = int(SIDE_DISTANCE-X+350+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosX+(SQUARE_SIZE-(14*SCALE))/2);
	int WindowY = int(SIDE_DISTANCE-Y+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosY+(SQUARE_SIZE-(18*SCALE))/2);
	if(WindowX>300 && WindowX<850 && WindowY>-50 && WindowY<600)
	{
		if(isMoved == true) CreateRect(SQUARE_SIZE,SQUARE_SIZE,sf::Color::Transparent,sf::Color::Black,0,(SIDE_DISTANCE-X+350+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosX),(SIDE_DISTANCE-Y+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosY));
		else CreateRect(SQUARE_SIZE-8,SQUARE_SIZE-8,sf::Color::Transparent,SquareColor,4,(SIDE_DISTANCE-X+350+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosX)+4,(SIDE_DISTANCE-Y+LINE_WIDTH+(LINE_WIDTH+SQUARE_SIZE)*PosY)+4);
		MakeSprite(NClass,WindowX,WindowY,SCALE,SCALE);
	}
}

// Create random integer
int RandomInt(int Min, int Max)
{
	random_device generator;
	uniform_int_distribution<int> distribution(Min,Max);
	int Random = distribution(generator);
	return Random;
}

void GetArmy(string Team, vector<Random>* BUnits, int UnitsPerSide, int NoOfSquares, vector<vector<int>>* Use)
{
	vector<vector<int>> Used = *Use;
	vector<Random> BoardUnits = *BUnits;
	for(int Count = 0;Count<UnitsPerSide;Count++)
	{
		bool isValid = false;
		int PX,PY;
		while(isValid == false)
		{
			PX = RandomInt(0,NoOfSquares-1);
			PY = RandomInt(0,NoOfSquares-1);
			vector<int> Suggested;
			Suggested.push_back(PX);
			Suggested.push_back(PY);
			isValid = true;
			for(int Count2 = 0;Count2<Used.size();Count2++) if(Used[Count2] == Suggested) isValid = false;
		}
		Random Soldier1;
		Soldier1.Define(2,Team,2,2,PX,PY);
		BoardUnits.push_back(Soldier1);
		vector<int> New;
		New.push_back(PX);
		New.push_back(PY);
		Used.push_back(New);
	}
	*BUnits = BoardUnits;
	*Use = Used;
}

// Battle Logic Function
int BattleMain(string Mode, int NoOfPlayers, int UnitsPerSide, int NoOfSquares, int Difficulty, int isBot)
{
	//
	string Terrains[6] = {"1","2","3","4","5","6"};
	int NumI = RandomInt(0,5);
	string Num = Terrains[NumI];
	string TerrainFile = "Terrain";
	TerrainFile += Num;
	TerrainFile += ".png";
	//

	int BaseX = 0;
	int BaseY = 0;
	vector<Random> BoardUnits;
	vector<vector<int>> Used;
	string Teams[6] = {"Red","Blue","White","Green","Magenta","Yellow"};
	for(int Count = 0;Count<NoOfPlayers;Count++) GetArmy(Teams[Count],&BoardUnits,UnitsPerSide,NoOfSquares,&Used);
	int X = 0;
	int Y = 0;
	Surface.clear();
	DrawGrid(NoOfSquares,X,Y,TerrainFile);
	string BaseTeam;
	for(int Count=0; Count<BoardUnits.size();Count++)
	{
		vector<int> Pos = BoardUnits[Count].Pos;
		DrawSprite(BoardUnits[Count].Class,BoardUnits[Count].Team,Pos[0],Pos[1],X,Y,false);
	}
	CreateRect(330,580,Maroon,Brown,10,10,10);
	CreateRect(780,130,Maroon,Brown,10,10,460);
	Surface.display();
	int TotLen = SIDE_DISTANCE*2+(LINE_WIDTH+SQUARE_SIZE)*NoOfSquares+LINE_WIDTH;
	bool isEntered = false;
	sf::Vector2i Pos =  sf::Mouse::getPosition(Surface);
	sf::Event Eve;
	vector<vector<int>> Positions;
	int BaseNum;
	while(isEntered == false)
	{
		bool Update = false;
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (X<TotLen-450))
		{
			X += 6; // Move Right
			Update = true;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (X>0))
		{
			X -= 6; // Move Left
			Update = true;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (Y<TotLen-450))
		{
			Y += 6; // Move Down
			Update = true;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (Y>0))
		{
			Y -= 6; // Move Up
			Update = true;
		}
		while(Surface.pollEvent(Eve))
		{
			if(Eve.type == 8)
			{
				Pos = sf::Mouse::getPosition(Surface);
				Update = true;
				if(Pos.x>350 && Pos.y<450) // Mouse is within window
				{
					bool New = true;
					for(int Count = 0;Count<BoardUnits.size();Count++)
					{
						int FormX = 350-X+SIDE_DISTANCE+(LINE_WIDTH*BoardUnits[Count].Pos[0]+1)+(SQUARE_SIZE*BoardUnits[Count].Pos[0]);
						int FormY = SIDE_DISTANCE-Y+(LINE_WIDTH*BoardUnits[Count].Pos[1]+1)+(SQUARE_SIZE*BoardUnits[Count].Pos[1]);
						// Mouse Position X must be greater than formulated value, but no greater than SQUARE_SIZE more:
						if((Pos.x>FormX) && (Pos.x<FormX+SQUARE_SIZE))
						{
							if((Pos.y>FormY) && (Pos.y<FormY+SQUARE_SIZE))
							{
								// Click is within this square
								//cout<<"Doing this"<<endl;
								//cout<<"Positions1 "<<Positions[0][0]<<endl;
								if(New == true)
								{
									vector<vector<int>> Noo;
									Positions = Noo;
								}
								if(BoardUnits[Count].MyImage.isMoved == false)
								{
									BaseX = BoardUnits[Count].Pos[0];
									BaseY = BoardUnits[Count].Pos[1];
									Positions = BoardUnits[Count].Show(BaseX,BaseY);
									BaseTeam = BoardUnits[Count].Team;
									BaseNum = Count;
									New = false;
								}
							}
						}

					}
					// Do something with the vector
				}
				cout<<"Beginning Check"<<endl;
				for(int Count = 0;Count<Positions.size();Count++)
				{
					int FormX = 350-X+SIDE_DISTANCE+(LINE_WIDTH*(Positions[Count][0]))+(SQUARE_SIZE*(Positions[Count][0]));
					int FormY = SIDE_DISTANCE-Y+(LINE_WIDTH*(Positions[Count][1]))+(SQUARE_SIZE*(Positions[Count][1]));
					cout<<Pos.x<<" "<<FormX<<endl;
					cout<<Pos.y<<" "<<FormY<<endl;
					if(Pos.x>FormX && Pos.x<FormX+SQUARE_SIZE && Pos.y>FormY && Pos.y<FormY+SQUARE_SIZE)
					{
						// This is the correct square
						cout<<"Unit has been moved"<<endl;
						// Moving Commencing
						BoardUnits[BaseNum].Pos[0] = Positions[Count][0];
						BoardUnits[BaseNum].Pos[1] = Positions[Count][1];
						vector<vector<int>> Noo;
						Positions = Noo;
						// Unit Has Been Moved
						BoardUnits[BaseNum].MyImage.isMoved = true;
					}
				}

			}
		}
		if(Update == true)
		{
			Surface.clear();
			DrawGrid(NoOfSquares,X,Y,TerrainFile);
			for(int Count=0; Count<BoardUnits.size();Count++)
			{
				vector<int> Pos = BoardUnits[Count].Pos;
				DrawSprite(BoardUnits[Count].Class,BoardUnits[Count].Team,Pos[0],Pos[1],X,Y,BoardUnits[Count].MyImage.isMoved);
			}
			for(int count = 0;count<Positions.size();count++)
			{
				int PX = (Positions[count][0]);
				int PY = (Positions[count][1]);
				bool Taken = false;
				for(int count4 = 0;count4<BoardUnits.size();count4++) if(BoardUnits[count4].Pos[0] == PX && BoardUnits[count4].Pos[1] == PY) Taken = true;
				if(Taken == false)
				{
					sf::Color BaseColor;
					sf::Color ColorList[6] = {sf::Color::Red,sf::Color::Blue,sf::Color::White,sf::Color::Green,sf::Color::Magenta,sf::Color::Yellow};
					for(int count3 = 0;count3<6;count3++) if(Teams[count3] == BaseTeam) BaseColor = ColorList[count3];
					if(PX>-1 && PX<NoOfSquares && PY>-1 && PY<NoOfSquares) CreateRect(SQUARE_SIZE,SQUARE_SIZE,BaseColor,sf::Color::Blue,0,350+SIDE_DISTANCE+(LINE_WIDTH*(PX+1))+(SQUARE_SIZE*PX)-X,SIDE_DISTANCE+(LINE_WIDTH*(PY+1))+(SQUARE_SIZE*PY)-Y);
				}
			}
			CreateRect(330,580,Maroon,Brown,10,10,10);
			CreateRect(780,130,Maroon,Brown,10,10,460);
			Surface.display();
		}
	}
	return 0;
}

// Main
int _tmain(int argc, _TCHAR* argv[])
{
	sf::Music MenuMusic;
	MenuMusic.openFromFile("Song2.OGG");
	MenuMusic.play();
	int X = MenuMain();
	MenuMusic.stop();
}
