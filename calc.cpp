#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
using namespace sf;

int main()
{

	//Create Window for calculator display
	RenderWindow window(VideoMode(200,300), "Calculator-SFML", Style::Titlebar|Style::Close);
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);
	
	/*------------------------------------------------------------Calculator Design------------------------------------------------------------------*/
	
	//sequence of horizontal lines
	RectangleShape line1(Vector2f(200.f,1.f));
	line1.setPosition(Vector2f(0,50));
	line1.setFillColor(Color::White);
	
	RectangleShape line2(Vector2f(200.f,1.f));
	line2.setPosition(Vector2f(0,100));
	line2.setFillColor(Color::White);
	
	RectangleShape line3(Vector2f(150.f,1.f));
	line3.setPosition(Vector2f(0,150));
	line3.setFillColor(Color::White);
	
	RectangleShape line4(Vector2f(200.f,1.f));
	line4.setPosition(Vector2f(0,200));
	line4.setFillColor(Color::White);
	
	RectangleShape line5(Vector2f(150.f,1.f));
	line5.setPosition(Vector2f(0,250));
	line5.setFillColor(Color::White);
	
	//sequence of vertical lines
	RectangleShape line6(Vector2f(1.f,200.f));
	line6.setPosition(Vector2f(50,50));
	line6.setFillColor(Color::White);
	
	RectangleShape line7(Vector2f(1.f,250.f));
	line7.setPosition(Vector2f(100,50));
	line7.setFillColor(Color::White);
	
	RectangleShape line8(Vector2f(1.f,250.f));
	line8.setPosition(Vector2f(150,50));
	line8.setFillColor(Color::White);
	
	//font for calculator buttons and display
	Font font;
	font.loadFromFile("BodoniXT.ttf");
	
	//initializing calculator buttons
	Text text1;
	text1.setFont(font);
	text1.setString("1");
	text1.setCharacterSize(30);
	text1.setPosition(Vector2f(15,205));
	text1.setColor(Color::White);
	
	Text text2;
	text2.setFont(font);
	text2.setString("2");
	text2.setCharacterSize(30);
	text2.setPosition(Vector2f(65,205));
	text2.setColor(Color::White);
	
	Text text3;
	text3.setFont(font);
	text3.setString("3");
	text3.setCharacterSize(30);
	text3.setPosition(Vector2f(115,205));
	text3.setColor(Color::White);
	
	Text text4;
	text4.setFont(font);
	text4.setString("4");
	text4.setCharacterSize(30);
	text4.setPosition(Vector2f(15,155));
	text4.setColor(Color::White);
	
	Text text5;
	text5.setFont(font);
	text5.setString("5");
	text5.setCharacterSize(30);
	text5.setPosition(Vector2f(65,155));
	text5.setColor(Color::White);
	
	Text text6;
	text6.setFont(font);
	text6.setString("6");
	text6.setCharacterSize(30);
	text6.setPosition(Vector2f(115,155));
	text6.setColor(Color::White);
	
	Text text7;
	text7.setFont(font);
	text7.setString("7");
	text7.setCharacterSize(30);
	text7.setPosition(Vector2f(15,105));
	text7.setColor(Color::White);
	
	Text text8;
	text8.setFont(font);
	text8.setString("8");
	text8.setCharacterSize(30);
	text8.setPosition(Vector2f(65,105));
	text8.setColor(Color::White);
	
	Text text9;
	text9.setFont(font);
	text9.setString("9");
	text9.setCharacterSize(30);
	text9.setPosition(Vector2f(115,105));
	text9.setColor(Color::White);
	
	Text text0;
	text0.setFont(font);
	text0.setString("0");
	text0.setCharacterSize(30);
	text0.setPosition(Vector2f(43,255));
	text0.setColor(Color::White);
	
	Text plus;
	plus.setFont(font);
	plus.setString("+");
	plus.setCharacterSize(30);
	plus.setPosition(Vector2f(165,130));
	plus.setColor(Color::White);
	
	Text minus;
	minus.setFont(font);
	minus.setString("-");
	minus.setCharacterSize(30);
	minus.setPosition(Vector2f(168,55));
	minus.setColor(Color::White);
	
	Text times;
	times.setFont(font);
	times.setString("*");
	times.setCharacterSize(30);
	times.setPosition(Vector2f(118,58));
	times.setColor(Color::White);
	
	Text divide;
	divide.setFont(font);
	divide.setString("/");
	divide.setCharacterSize(30);
	divide.setPosition(Vector2f(73,55));
	divide.setColor(Color::White);
	
	Text clear;
	clear.setFont(font);
	clear.setString("C");
	clear.setCharacterSize(30);
	clear.setPosition(Vector2f(15,55));
	clear.setColor(Color::White);
	
	Text equal;
	equal.setFont(font);
	equal.setString("=");
	equal.setCharacterSize(30);
	equal.setPosition(Vector2f(165,230));
	equal.setColor(Color::White);
	
	Text dot;
	dot.setFont(font);
	dot.setString(".");
	dot.setCharacterSize(30);
	dot.setPosition(Vector2f(123,250));
	dot.setColor(Color::White);
	
	//initializing variables for calculations
	string disp = "";
	double repo1;
	string check;
	
	//initializing calculator display
	Text disl;
	disl.setFont(font);
	disl.setCharacterSize(30);
	disl.setPosition(Vector2f(15,5));
	disl.setColor(Color::White);
	
	while(window.isOpen())
	{
		disl.setString(disp);
		
		//event handler [actual calculator workings]
		Event event;
		while(window.pollEvent(event))
		{
			if((event.type==Event::Closed)||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Escape)))
				window.close();
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=50&&Mouse::getPosition(window).x>=0&&Mouse::getPosition(window).y<=250&&Mouse::getPosition(window).y>=200))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num1))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad1)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="1";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=100&&Mouse::getPosition(window).x>=50&&Mouse::getPosition(window).y<=250&&Mouse::getPosition(window).y>=200))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num2))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad2)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="2";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=150&&Mouse::getPosition(window).x>=100&&Mouse::getPosition(window).y<=250&&Mouse::getPosition(window).y>=200))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num3))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad3)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="3";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=50&&Mouse::getPosition(window).x>=0&&Mouse::getPosition(window).y<=200&&Mouse::getPosition(window).y>=150))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num4))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad4)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="4";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=100&&Mouse::getPosition(window).x>=50&&Mouse::getPosition(window).y<=200&&Mouse::getPosition(window).y>=150))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num5))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad5)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="5";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=150&&Mouse::getPosition(window).x>=100&&Mouse::getPosition(window).y<=200&&Mouse::getPosition(window).y>=150))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num6))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad6)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="6";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=50&&Mouse::getPosition(window).x>=0&&Mouse::getPosition(window).y<=150&&Mouse::getPosition(window).y>=100))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num7))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad7)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="7";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=100&&Mouse::getPosition(window).x>=50&&Mouse::getPosition(window).y<=150&&Mouse::getPosition(window).y>=100))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num8))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad8)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="8";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=150&&Mouse::getPosition(window).x>=100&&Mouse::getPosition(window).y<=150&&Mouse::getPosition(window).y>=100))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num9))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad9)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="9";
			}
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=50&&Mouse::getPosition(window).x>=0&&Mouse::getPosition(window).y<=100&&Mouse::getPosition(window).y>=50))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::C)))
			{
				disl.setCharacterSize(30);
				disl.setPosition(15,5);
				check="";
				disp="";
			}	
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=100&&Mouse::getPosition(window).x>=50&&Mouse::getPosition(window).y<=100&&Mouse::getPosition(window).y>=50))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Slash))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Divide)))
			{
				if(disp==""){check="/";}
				else
				{
					disl.setCharacterSize(30);
					disl.setPosition(15,5);
					if(check=="+"){repo1=repo1+stod(disp);}
					else if(check=="-"){repo1=repo1-stod(disp);}
					else if(check=="/"){ if(stod(disp)==0){} else{repo1=repo1/stod(disp);}}
					else if(check=="*"){repo1=repo1*stod(disp);}
					if(check=="="){}
					else{repo1=stod(disp);}
					//repo=to_string(repo1);
					disp="";
					check="/";
				}
			}
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=150&&Mouse::getPosition(window).x>=100&&Mouse::getPosition(window).y<=100&&Mouse::getPosition(window).y>=50))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Multiply)))
			{
				if(disp==""){check="*";}
				else
				{
					disl.setCharacterSize(30);
					disl.setPosition(15,5);
					if(check=="+"){repo1=repo1+stod(disp);disp=to_string(repo1);}
					else if(check=="-"){repo1=repo1-stod(disp);disp=to_string(repo1);}
					else if(check=="/"){ if(stod(disp)==0){} else{repo1=repo1/stod(disp);disp=to_string(repo1);}}
					else if(check=="*"){repo1=repo1*stod(disp);disp=to_string(repo1);}
					if(check=="="){}
					else{repo1=stod(disp);}
					disp="";
					check="*";
				}
			}
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=200&&Mouse::getPosition(window).x>=150&&Mouse::getPosition(window).y<=100&&Mouse::getPosition(window).y>=50))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Dash))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Subtract)))
			{
				if(disp==""){check="-";}
				else
				{
					disl.setCharacterSize(30);
					disl.setPosition(15,5);
					if(check=="+"){repo1=repo1+stod(disp);disp=to_string(repo1);}
					else if(check=="-"){repo1=repo1-stod(disp);disp=to_string(repo1);}
					else if(check=="/"){ if(stod(disp)==0){} else{repo1=repo1/stod(disp);disp=to_string(repo1);}}
					else if(check=="*"){repo1=repo1*stod(disp);disp=to_string(repo1);}
					if(check=="="){}
					else{repo1=stod(disp);}
					disp="";
					check="-";
				}
			}
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=200&&Mouse::getPosition(window).x>=150&&Mouse::getPosition(window).y<=200&&Mouse::getPosition(window).y>=100))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Add)))
			{
				if(disp==""){check="+";}
				else
				{
					disl.setCharacterSize(30);
					disl.setPosition(15,5);
					if(check=="+"){repo1=repo1+stod(disp);disp=to_string(repo1);}
					else if(check=="-"){repo1=repo1-stod(disp);disp=to_string(repo1);}
					else if(check=="/"){ if(stod(disp)==0){} else{repo1=repo1/stod(disp);disp=to_string(repo1);}}
					else if(check=="*"){repo1=repo1*stod(disp);disp=to_string(repo1);}
					if(check=="="){}
					else{repo1=stod(disp);}
					disp="";
					check="+";
				}
			}
			if(((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=200&&Mouse::getPosition(window).x>=150&&Mouse::getPosition(window).y<=300&&Mouse::getPosition(window).y>=200))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Equal))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Return)))
			{
				if(disp==""){check="=";}
				else
				{
					if(check=="+"){repo1=repo1+stod(disp);}
					else if(check=="-"){repo1=repo1-stod(disp);}
					else if(check=="/"){ if(stod(disp)==0){} else{repo1=repo1/stod(disp);}}
					else if(check=="*"){repo1=repo1*stod(disp);}
					repo1=ceil(repo1*pow(10,4))/pow(10,4);
					disp=to_string(repo1);
					disp=disp.erase(disp.find(".")+5,disp.size()-1);
					if(disp.size()>11){disl.setCharacterSize(20);disl.setPosition(10,15);}
					check="=";
				}
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=100&&Mouse::getPosition(window).x>=0&&Mouse::getPosition(window).y<=300&&Mouse::getPosition(window).y>=250))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Num0))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Numpad0)))&&(disp.size()<11))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				disp+="0";
			}
			if((((event.type==Event::MouseButtonPressed)&&(event.mouseButton.button==Mouse::Left)&&(Mouse::getPosition(window).x<=150&&Mouse::getPosition(window).x>=100&&Mouse::getPosition(window).y<=300&&Mouse::getPosition(window).y>=250))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Period))||((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::Pause)))&&(disp.size()<10))
			{
				if(check=="="){disp="";check="";disl.setCharacterSize(30);disl.setPosition(15,5);}
				int t=0,s=0;
				while(t<disp.size()){if(disp[t]=='.'){s=1;}t++; if(s==1){break;}}
				if(s==0)
					disp+=".";
			}
			if(((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::BackSpace)))
				disp.erase(disp.size()-1,1);
		}
		
		//Program output
		window.clear();
		window.draw(line1);
		window.draw(line2);
		window.draw(line3);
		window.draw(line4);
		window.draw(line5);
		window.draw(line6);
		window.draw(line7);
		window.draw(line8);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);
		window.draw(text0);
		window.draw(plus);
		window.draw(minus);
		window.draw(times);
		window.draw(divide);
		window.draw(clear);
		window.draw(equal);
		window.draw(dot);
		window.draw(disl);
		window.display();
	}
	return 0;
}